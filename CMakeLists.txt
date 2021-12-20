cmake_minimum_required(VERSION 3.0)
project(swapk_exam CXX)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
set(CMAKE_CXX_STANDARD 17)

add_executable(swapk_exam main.cpp http/HTTPRequest.h http/HTTPResponse.h http/HTTPCall.h http/HTTPCallParser.h socket/SocketListener.cpp socket/SocketListener.h socket/SocketConnection.cpp socket/SocketConnection.h socket/SocketManager.cpp socket/SocketManager.h http/HTTPCallHandler.h dispatch/Dispatcher.h http/HTTPCallParser.cpp)
set_target_properties(swapk_exam PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(swapk_exam PRIVATE Threads::Threads)
target_link_libraries(swapk_exam PRIVATE boost_system)