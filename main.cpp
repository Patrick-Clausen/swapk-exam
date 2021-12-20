#include "HttpCallParser.h"
#include <iostream>

const std::string input =
        "POST / HTTP/1.1\nHost: localhost\nUser-Agent: curl/7.55.1\nAccept: /\nContent-Length: 5\nContent-Type: application/x-www-form-urlencoded\n\n{\nTemperature: 5\nCountry: Denmark\n}";

int main() {
    auto parser = HttpCallParser();
    auto response = parser.ParseCallToResponse(input);
    auto request = parser.ParseCallToResponse(input);

    std::cout << response << std::endl;
    std::cout << request << std::endl;
    return 0;
}
