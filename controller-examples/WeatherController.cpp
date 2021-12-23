//
// Created by einar on 12/17/21.
//
#include <iostream>
#include "WeatherController.h"

std::string WeatherController::GET(const std::string &body) {
    std::cout << "Called get" << std::endl;
    return "Hello";
}

std::string WeatherController::POST(std::string body) {
    std::cout << "Called post" << std::endl;
    return body;
}

