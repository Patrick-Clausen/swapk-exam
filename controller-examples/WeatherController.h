//
// Created by einar on 12/17/21.
//
#ifndef SWAPK_EXAM_WEATHERCONTROLLER_H
#define SWAPK_EXAM_WEATHERCONTROLLER_H

#include <string>

class WeatherController {
public:
    std::string GET(const std::string &body);

    std::string POST(std::string body);
    [[nodiscard]] static constexpr std::string_view Path() { return "/weather"; }

private:

};


#endif //SWAPK_EXAM_WEATHERCONTROLLER_H
