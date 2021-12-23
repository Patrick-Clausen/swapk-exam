cmake_minimum_required(VERSION 3.0)
project(swapk_exam CXX)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
set(CMAKE_CXX_STANDARD 17)

file(GLOB dispatch dispatch/*.cpp)
file(GLOB controller-examples controller-examples/*.cpp)
file(GLOB exception exception/*.cpp)
file(GLOB exception-defaults exception/defaults/*.cpp)
file(GLOB http http/*.cpp)
file(GLOB http-details http/details/*.cpp)
file(GLOB socket socket/*.cpp)

add_executable(swapk_exam main.cpp ${dispatch} ${controller-examples} ${exception} ${exception-defaults} ${http} ${http-details} ${socket} dispatch/Dispatcher.cpp RESTBuilder.cpp RESTBuilder.h)
set_target_properties(swapk_exam PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(swapk_exam PRIVATE Threads::Threads)
target_link_libraries(swapk_exam PRIVATE boost_system)