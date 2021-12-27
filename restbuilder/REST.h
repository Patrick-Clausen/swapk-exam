//
// Created by Patrick Clausen on 27/12/2021.
//

#ifndef SWAPK_EXAM_REST_H
#define SWAPK_EXAM_REST_H

#include <boost/asio.hpp>
#include <memory>
#include "../exception/ExceptionHandler.h"
#include "../http/interceptor/HTTPInterceptor.h"
#include "../http/HTTPCallHandler.h"
#include "../socket/SocketManager.h"

namespace restbuilder {
    class REST {
    public:
        REST() = delete;

        REST(std::shared_ptr <exception::ExceptionHandler> exceptionHandler,
             std::shared_ptr <dispatch::Dispatcher> dispatcher,
             std::shared_ptr <http::interceptor::HTTPInterceptorChain> interceptor,
             boost::asio::ip::tcp::endpoint endpoint);

    private:
        std::shared_ptr <http::HTTPCallHandler> _callHandler;
        std::shared_ptr <socket::SocketManager> _socketManager;
        std::shared_ptr <exception::ExceptionHandler> _exceptionHandler;
        std::shared_ptr <dispatch::Dispatcher> _dispatcher;
        std::shared_ptr <http::interceptor::HTTPInterceptorChain> _interceptor;
    };
}


#endif //SWAPK_EXAM_REST_H
