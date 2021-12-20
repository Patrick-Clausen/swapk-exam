cmake_minimum_required(VERSION 3.0)
project(swapk_exam CXX)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
set(CMAKE_CXX_STANDARD 17)

add_executable(swapk_exam main.cpp HttpTypes/HttpRequest.h HttpTypes/HttpResponse.h HttpTypes/HttpCall.h HttpTypes/HttpCallParser.h socket/SocketListener.cpp socket/SocketListener.h socket/SocketConnection.cpp socket/SocketConnection.h socket/SocketManager.cpp socket/SocketManager.h)
set_target_properties(swapk_exam PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(swapk_exam PRIVATE Threads::Threads)
target_link_libraries(swapk_exam PRIVATE boost_system)