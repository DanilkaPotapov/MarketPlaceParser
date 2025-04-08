#ifndef PARSER_H
#define PARSER_H

#include <string>

namespace Parser {
    void startBot();
    void handleProductRequest(const std::string& productName);
}

#endif // PARSER_H