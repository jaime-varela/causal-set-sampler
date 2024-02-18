cmake_minimum_required(VERSION 3.12)

# Set your project name
project(CausalSetSampler)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)

# eigen
include_directories(${CMAKE_SOURCE_DIR}/eigen_directory)
# optimlib
include_directories(${CMAKE_SOURCE_DIR}/header_only_version)

# Add the C library subdirectory
add_subdirectory(cubature)

# Add the metric form library
add_subdirectory(metric_volume_forms)


# Add the executable
add_executable(cubature_test cubature_test.cpp)

# Link the C library with your executable
target_link_libraries(cubature_test PRIVATE cubature)


# optimlib integration
add_executable(optim_lib_test optim_lib_test.cpp)


# schwarchild optimization
add_executable(optimization_of_volume_sampling optimization_of_volume_sampling.cpp)
target_link_libraries(optimization_of_volume_sampling PRIVATE metric_volume_forms)
