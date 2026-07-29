cmake_minimum_required(VERSION 3.14)
project(LinearAlgebra_Ryzen7520U CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Flagi dedykowane dla AMD Ryzen 5 7520U (Zen 2)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -mavx2 -mfma -ffast-math")
endif()

# Wyszukiwanie zainstalowanej biblioteki Eigen3
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(MatrixPerf main.cpp)
target_link_libraries(MatrixPerf PRIVATE Eigen3::Eigen)

