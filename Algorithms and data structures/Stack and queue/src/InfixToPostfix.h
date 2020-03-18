#ifndef INFIX_TO_POSTFIX_H
    #define INFIX_TO_POSTFIX_H

#include <string>
#include <vector>
#include <map>

template<typename Container = std::vector<char>>
std::string infixToPostfix(const std::string&);

template<typename Container = std::vector<int>>
int calculate_infix(const std::string&, std::map<char, int>);

#include "InfixToPostfix.cpp"

#endif