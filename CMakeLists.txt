cmake_minimum_required(VERSION 3.15)
project(neural-network-c LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include the headers directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Gather library files (excluding main.cpp so there is only one main() function)
add_library(nn_core STATIC src/activations.cpp src/neuron.cpp src/layer.cpp)

# Build the test executable
add_executable(nn_test tests/nn_learning.cpp)

# Link activations into the test binary
target_link_libraries(nn_test PRIVATE nn_core)

# Build the XOR gate test executable
add_executable(xor_test tests/XOR_GATE.cpp)
target_link_libraries(xor_test PRIVATE nn_core)