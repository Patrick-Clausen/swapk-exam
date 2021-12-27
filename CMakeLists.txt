cmake_minimum_required(VERSION 3.0)
project(swapk_exam CXX)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
set(CMAKE_CXX_STANDARD 17)

file(GLOB sources
        dispatch/*.cpp
        controller-examples/*.cpp
        exception/*.cpp
        exception/defaults/*.cpp
        http/*.cpp
        socket/*.cpp
        http/interceptor/*.cpp
        restbuilder/*.cpp)


add_executable(swapk_exam main.cpp ${sources})
set_target_properties(swapk_exam PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(swapk_exam PRIVATE Threads::Threads)
target_link_libraries(swapk_exam PRIVATE boost_system)