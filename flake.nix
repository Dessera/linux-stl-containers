{
  description = "Some data structures implemented out of kernel tree";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixpkgs-unstable";
    flake-parts.url = "github:hercules-ci/flake-parts";

    nixcode = {
      url = "github:Dessera/nixcode";
      inputs.flake-parts.follows = "flake-parts";
    };
  };

  nixConfig = {
    extra-substituters = [
      "https://nixcode.cachix.org"
    ];

    extra-trusted-public-keys = [
      "nixcode.cachix.org-1:6FvhF+vlN7gCzQ10JIKVldbG59VfYVzxhH/+KGHvMhw="
    ];
  };

  outputs =
    { flake-parts, ... }@inputs:
    flake-parts.lib.mkFlake { inherit inputs; } (
      { withSystem, ... }:
      {
        systems = [ "x86_64-linux" ];

        perSystem =
          {
            self',
            pkgs,
            system,
            ...
          }:
          let
            stdenv = pkgs.gcc14Stdenv;

            clang-tools = pkgs.callPackage ./.nix-support/clang-tools.nix {
              inherit stdenv;
            };

            code = withSystem system ({ inputs', ... }: inputs'.nixcode.packages.nixcode-cpp);
          in
          {
            packages.default = pkgs.callPackage ./default.nix { inherit stdenv; };
            devShells.default =
              pkgs.mkShell.override
                {
                  inherit stdenv;
                }
                {
                  inputsFrom = [ self'.packages.default ];

                  packages =
                    (with pkgs; [
                      nixd
                      nixfmt-rfc-style
                      mesonlsp
                    ])
                    ++ [
                      clang-tools
                      code
                    ];
                };
          };
      }
    );
}
