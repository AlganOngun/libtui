# libtui

## Getting started

- Make sure you have zig installed if not:
```bash
sudo pacman -S zig
```

### Build the release (Recomended for everyone):
- Download the latest release's special source code (the name should be something like: "libtui-1.0.0-release-special-source.zip")
- Then unzip it in the directory you prepared to build it:
```bash
mkdir libtui-build
cd libtui-build
mv ~/Downloads/libtui-x.x.x-release-special-source.zip .
unzip libtui-x.x.x-release-special-source.zip
```
- Finally build it:
```bash
zig build
```

##### Then optionally run:
```bash
zig build run
```
to build and run the example code in **"examples/simple.c"**.

### Build the development version (Only difference is that this version has some boilerplate Doxygen stuff):
- Download and compile the development source code using:
```bash
git clone https://github.com/AlganOngun/libtui
cd libtui
zig build
```

##### Then optionally run:
```bash
zig build run
```
to build and run the example code in **"examples/simple.c"**.

#### You can use any build system and compiler you want just include libtui.h and link liblibtui.a

## Docs
libtui uses **Doxygen** to generate docs to an html and has an **github pages** up and running in: https://alganongun.github.io/libtui-github-page/
