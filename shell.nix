let
  nixpkgs = fetchTarball "https://github.com/NixOS/nixpkgs/tarball/nixos-24.05";
  pkgs = import nixpkgs { config = {}; overlays = []; };
in

pkgs.mkShellNoCC {
  packages = with pkgs; [
    gnumake
    clang
    glfw
    xorg.libX11
    xorg.libXrandr
    xorg.libXi
  ];
}
