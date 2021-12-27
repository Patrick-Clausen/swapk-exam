//
// Created by Patrick Clausen on 27/12/2021.
//

#include "REST.h"

restbuilder::REST::REST(std::shared_ptr<exception::ExceptionHandler> exceptionHandler,
                        std::shared_ptr<dispatch::Dispatcher> dispatcher,
                        std::shared_ptr<http::interceptor::HTTPInterceptorChain> interceptor,
                        const boost::asio::ip::tcp::endpoint endpoint)
        : _dispatcher(dispatcher),
          _exceptionHandler(exceptionHandler),
          _interceptor(interceptor) {

    _callHandler = std::make_shared<http::HTTPCallHandler>(*_exceptionHandler, *_interceptor);
    std::function < std::string(std::string) > lambda = [this](
            std::string&& arg) -> std::string { return _callHandler->handle(std::move(arg)); };

    _socketManager = std::make_shared<socket::SocketManager>(endpoint, lambda);
}
