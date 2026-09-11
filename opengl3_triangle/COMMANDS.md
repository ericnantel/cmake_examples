
# Clone submodules

git submodule init
git submodule update

# Using conan
# Expects a conanfile.txt
# Expects toolchainFile: "${sourceDir}/build/generators/Release/conan_toolchain.cmake"
# So that you can use cmake --preset default which will configure conan-release as well
# If a package binaries is not available, you might need to install source code and build locally
# Ex: conan install . --build=gtest/1.18.0
# Or: conan install . --build=missing
conan profile detect --force
conan install . --build=missing
cmake --preset conan-release
cmake --build --preset conan-release
# Or
cmake --workflow --preset default
# Or
cmake --workflow --fresh --preset default

# Using bear

bear -- cmake --list-presets
bear -- cmake --preset default
bear -- cmake --build --preset default
# Or
bear -- cmake --workflow --preset default
# Or
bear -- cmake --workflow --fresh --preset default

# Not using bear

cmake --list-presets
cmake --preset default
cmake --build --preset default
# Or
cmake --workflow --preset default
# Or
cmake --workfloat --fresh --preset default

# Run executable

./build/mailman
./build/default/mailman
./build/Release/mailman
