# Starter CPP

A very minimal starter project.  Feel free to help me make it better.  I am always hoping to learn something.

## What technologies are folded in?

- [CMake](https://cmake.org/cmake/help/v3.15/index.html)
- [clang C++ 17](https://clang.llvm.org/cxx_status.html#cxx17)
- [clang format](https://clang.llvm.org/docs/ClangFormat.html)
- [google test 1.8.1](https://github.com/google/googletest)

## What platforms?

(Help needed here: add you own OS)

- Mac OS


## How does it work?

The C++ source is in a folder called `src/console`.  The idea is that `console` is an example some higher level package or component.  So, for a larger project you would add more folders under `src`.

Note that Google Test is not in the source.  It will be downloaded and added to the source the first time you build.  The code will be place in `src/gtest`.  This folder is git ignored.  The code in `get-gtest.h` fetches gtest using `wget`.  Most likely the most problematic part of the build. 

This starter uses the idea that you can write your unit tests in the same file as the source.  The `TESTING` define can be used to demarcate you test code from the rest.

```cpp
#ifdef TESTING
// tests go here
#endif
```

This approach avoids some problems that occurs when you want to hide implementation details from other modules, but not from tests.

The downside is that `main()` must be excluded from the build using the same preprocessor definition.  I small price to pay, I think.

```cpp
#ifndef TESTING
// your main function goes here
#endif
```

# How to build?

The most standard way is possibly this:

```sh
mkdir build
cd build
cmake ..
make all
```

The targets `test_app` and `console_app` should be ready for use.

# Questions

1. Can `CMakeLists.txt` be simpler?
1. Is there a better way to get gtest than `get-gtest.sh`?
