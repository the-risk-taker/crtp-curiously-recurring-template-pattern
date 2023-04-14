# CRTP

The Curiously Recurring Template Pattern (CRTP) is a C++ technique where a class derives from a template class using itself as the template parameter, enabling static polymorphism without virtual functions overhead.

Here are some examples of CRTP implementations made for an in-company lightning talk.

## Building

Building examples with CMake (from repository root directory):

```shell
cmake -S . -B build
cmake --build build --parallel
```

## Run examples

After building, you can run the examples from the `build` directory. Each example demonstrates different aspects of CRTP and includes console output explaining the behavior.
