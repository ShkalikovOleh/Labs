#ifndef INFIX_TO_POSTFIX_H
    #define INFIX_TO_POSTFIX_H

#include <string>
#include <vector>

template<typename Container = std::vector<char>>
std::string infixToPostfix(const std::string&);

#include "InfixToPostfix.cpp"

#endif