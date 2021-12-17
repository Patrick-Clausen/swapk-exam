cmake_minimum_required(VERSION 3.0)
project(swapk_exam CXX)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
set(CMAKE_CXX_STANDARD 17)

add_executable(swapk_exam main.cpp SocketListener.cpp SocketListener.h ExceptionHandler.h HTTPParser.h Dispatcher.h HTTPCall.h)
target_link_libraries(swapk_exam PRIVATE Threads::Threads)
set_target_properties(swapk_exam PROPERTIES LINKER_LANGUAGE CXX)
