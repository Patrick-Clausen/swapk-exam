//
// Created by Patrick Clausen on 22/12/2021.
//

#ifndef SWAPK_EXAM_HTTPCALLHANDLERIMPL_H
#define SWAPK_EXAM_HTTPCALLHANDLERIMPL_H

#include "../../exception/ExceptionHandler.h"
#include "../HTTPRequest.h"
#include "../HTTPResponse.h"

namespace http::details::call {
    class HTTPCallHandlerImpl {
    public:
        static std::string handle(const std::string& request);

        HTTPCallHandlerImpl(HTTPCallHandlerImpl const&) = delete;
        void operator=(HTTPCallHandlerImpl const &) = delete;
    private:
        HTTPCallHandlerImpl() = default;

        std::string handleInInstance(const std::string& request);

        // Functional singleton
        static HTTPCallHandlerImpl& handler();

        ExceptionHandler _exceptionHandler;
    };
}




#endif //SWAPK_EXAM_HTTPCALLHANDLERIMPL_H
