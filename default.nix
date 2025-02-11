{
  stdenv,
  lib,

  # Build tools
  meson,
  ninja,
  pkg-config,
}:
stdenv.mkDerivation {
  name = "linux-stl-containers";
  src = lib.cleanSource ./.;

  nativeBuildInputs = [
    meson
    ninja
    pkg-config
  ];
}
