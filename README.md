# Starter CPP

A  starter project for C++ and CMake. Works on Mac out of the box.

## What technologies are folded in?

- [CMake](https://cmake.org/cmake/help/v3.15/index.html)
- [clang C++ 20](https://clang.llvm.org/cxx_status.html#cxx20)
- [google test 1.8.1](https://github.com/google/googletest)
- [clang format](https://clang.llvm.org/docs/ClangFormat.html)
- Settings for [Visual Studio code](https://code.visualstudio.com/)

## Basic ideas

Google Test is _not_ in the source.  It will be downloaded and added to the source the first time you build.  The code will be placed in `src/gtest`.  This folder is ignored by GIT.  The code in `get-gtest.h` fetches `gtest` using `wget`.  

The folder structure:

1. `src/domain` has the code of your app. Files here are testable.
1. `src/console` has the code that runs the console app (`main()`)
1. `src/test` has the test code.

You can also use the `#ifndef NO_TESTING ... #endif` construct to create _internal tests_.  See [fun.cpp](src/domain/fun.cpp) for an example.

## Building

The most standard way to build possibly this:

```sh
mkdir build && cd build && cmake .. && make all && cd ..
```

The targets `test_app` and `console_app` should be ready for use.
