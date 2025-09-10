cmake_minimum_required(VERSION 3.18)
project(cuda_scalar_product LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CUDA_STANDARD 17)

# исходники
set(SOURCES
    src/main.cu
    src/utils.cpp
)

add_executable(scalar_product ${SOURCES})

target_include_directories(scalar_product PRIVATE include)

# включаем все оптимизации
target_compile_options(scalar_product PRIVATE $<$<COMPILE_LANGUAGE:CUDA>:
    --use_fast_math -O3
>)