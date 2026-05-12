
# Getting Started
Clone the repo recursively:

git clone --recursive https://github.com/ericnantel/cmake_examples cmake_examples

# Install prerequisites
* git
* cmake
* ninja (recommended)
* a C++ compiler (gcc, clang or msvc)
* bear (optional)

# Additionnal installs
Some examples might require installing addtionnal packages on your system.

In [Episode 03](https://youtu.be/xLxtga-11iU) you will need to install:
* doxygen

In [Episode 04](https://youtu.be/Ycl1ocm8xog) you will need to install:
* googletest

# List presets

* cmake --list-presets

# List workflow presets

* cmake --workflow --list-presets

# Configure preset

* cmake --preset default
* cmake --fresh --preset default

# Build preset

* cmake --build --preset default

# Run preset tests (CTest and/or GoogleTest)

* ctest --preset default

# Execute workflow preset

* cmake --workflow --preset default
* cmake --workflow --fresh --preset default

# Run executable
Ex toml_parser (Episode 01):

* ./build/toml_parser

Ex test_simple (Episode 04):

* ./build/GoogleTests

# Watch YouTube Tutorials
* [Episode 01 - C++ TOML Integration](https://youtu.be/iGJrAzn7Qic)
* [Episode 02 - C++ Unity Plugin For Games !](https://youtu.be/lzul2prPbZE)
* [Episode 03 - C++ Doxygen Docs](https://youtu.be/xLxtga-11iU)
* [Episode 04 - C++ Unit Testing (CTest + GoogleTest)](https://youtu.be/Ycl1ocm8xog)

# Bear + CMake
Usually Makefile and Ninja generators can export compile commands
for Clangd (lsp), but if using Visual Studio or perhaps GCC then you
may need to use Bear to intercept build commands and produce those
compile commands. Also it produces a cleaner file imo. To use Bear,
first you must install it (ideally with a package manager) and then
you can do the following to configure and build a CMake project:

* bear -- cmake --list-presets
* bear -- cmake --fresh --preset default
* bear -- cmake --build --preset default

You can also use a workflow preset with bear:

* bear -- cmake --workflow --fresh --preset default

It should generate a compile_commands.json in the CMake root path.

# Roadmap
Is subject to change at anytime.
See [Roadmap here](./ROADMAP.md)

# Extras
I am using Emacs to write ROADMAP.org.
However GitHub doesn't render org files properly (especially tasks).
So I am using pandoc to convert org to md files, such as ROADMAP.org.

Here is the command I use to convert .org to .md:
* pandoc --from=org --to=gfm ROADMAP.org -o ROADMAP.md

# About the author
Eric Nantel (Canada) Senior Level

Make sure to follow me :smile_cat:
:star: Help this repository by giving it a star . It really helps me .
