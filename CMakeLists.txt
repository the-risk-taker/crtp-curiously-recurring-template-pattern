cmake_minimum_required(VERSION 3.22)
project (crtp LANGUAGES CXX)

add_compile_options(-std=c++20)

add_executable (interface_crtp src/interface_crtp.cpp)
add_executable (interface_virtual src/interface_virtual.cpp)
add_executable (pitfalls src/pitfalls.cpp)
add_executable (extension src/extension.cpp)
add_executable (wrapper src/wrapper.cpp)
add_executable (phantom_type src/phantom_type.cpp)
add_executable (mixins src/mixins.cpp)
add_executable (crtp-variant src/crtp-variant.cpp)
