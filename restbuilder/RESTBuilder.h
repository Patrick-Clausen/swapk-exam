//
// Created by Patrick Clausen on 23/12/2021.
//

#ifndef SWAPK_EXAM_RESTBUILDER_H
#define SWAPK_EXAM_RESTBUILDER_H

#include <boost/asio.hpp>

#include "../http/HTTPCallHandler.h"
#include "../exception/ExceptionHandler.h"
#include "../dispatch/Dispatcher.h"
#include "../socket/SocketManager.h"
#include "../http/interceptor/HTTPInterceptor.h"
#include "REST.h"

#include <typeindex>
#include <string>
#include <utility>

namespace restbuilder {
    class RESTBuilder {
    public:
        static RESTBuilder builder();

        template<typename T>
        RESTBuilder& addController(T controller) {
            _dispatcher->registerController(controller);
            return *this;
        }

        template<typename T>
        RESTBuilder& addInterceptor(T interceptor) {
            _interceptor->addInterceptor(interceptor);
            return *this;
        }

        RESTBuilder&
        addException(const std::type_index& type, std::string_view statusCode, std::string_view statusMessage);

        RESTBuilder& setEndpoint(boost::asio::ip::tcp::endpoint endpoint);

        REST build();

    private:
        RESTBuilder() {
            _exceptionHandler = std::make_shared<exception::ExceptionHandler>();
            _dispatcher = std::make_shared<dispatch::Dispatcher>();
            _interceptor = std::make_shared<http::interceptor::HTTPInterceptorChain>(*_dispatcher);
        }

        boost::asio::ip::tcp::endpoint _endpoint = boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 80);
        std::shared_ptr<exception::ExceptionHandler> _exceptionHandler;
        std::shared_ptr<dispatch::Dispatcher> _dispatcher;
        std::shared_ptr<http::interceptor::HTTPInterceptorChain> _interceptor;
    };
}

#endif //SWAPK_EXAM_RESTBUILDER_H
