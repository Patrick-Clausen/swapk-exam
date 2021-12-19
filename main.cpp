#include "HttpCallParser.h"
#include <iostream>

int main() {
    std::string input =
            "POST / HTTP/1.1\nHost: localhost\nUser-Agent: curl/7.55.1\nAccept: /\nContent-Length: 5\nContent-Type: application/x-www-form-urlencoded\n\n{\nTemperature: 5\nCountry: Denmark\n}";
    auto parser = HttpCallParser();
    auto request = parser.ParseCallToResponse(input);

    std::cout << request << std::endl;
    return 0;
}
