{
  description = "CMake hello world example";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    flake-parts.url = "github:hercules-ci/flake-parts";
  };

  outputs =
    inputs@{
      self,
      nixpkgs,
      flake-parts,
    }:
    flake-parts.lib.mkFlake { inherit inputs; } {
      systems = [ "x86_64-linux" ];

      perSystem =
        { pkgs, ... }:
        let
          stdenv' = pkgs.gcc14Stdenv;
        in
        {
          # packages = {
          #   hello = pkgs.callPackage ./default.nix {
          #     stdenv = stdenv';
          #   };
          #   default = self'.packages.hello;
          # };

          devShells.default =
            pkgs.mkShell.override
              {
                stdenv = stdenv';
              }
              {
                # inputsFrom = [ self'.packages.default ];
                packages = with pkgs; [
                  nixd
                  nixfmt-rfc-style
                  clang-tools

                  meson
                  ninja
                  mesonlsp

                  pkg-config
                ];
              };
        };
    };
}
