//
// Created by Patrick Clausen on 23/12/2021.
//

#ifndef SWAPK_EXAM_RESTBUILDER_H
#define SWAPK_EXAM_RESTBUILDER_H

#include <boost/asio.hpp>

#include "http/details/HTTPCallHandler.h"
#include "exception/ExceptionHandler.h"
#include "dispatch/Dispatcher.h"
#include "socket/SocketManager.h"

#include <typeindex>
#include <string>

class RESTBuilder {
public:
    static RESTBuilder *builder();

    ~RESTBuilder();
    template <typename T>
    RESTBuilder* addController(T controller){
        _dispatcher.registerController(controller);
        return this;
    }
    RESTBuilder* addException(const std::type_index& type, std::string_view statusCode, std::string_view statusMessage);
    RESTBuilder* setEndpoint(boost::asio::ip::tcp::endpoint endpoint);

    void build();

private:
    RESTBuilder() = default;
    boost::asio::ip::tcp::endpoint _endpoint = boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 80);
    ExceptionHandler _exceptionHandler;
    Dispatcher _dispatcher;
    HTTPCallHandler* _httpCallHandler;
    SocketManager* _socketManager;
};


#endif //SWAPK_EXAM_RESTBUILDER_H
