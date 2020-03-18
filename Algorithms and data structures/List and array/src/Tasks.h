#ifndef TASKS_H
    #define TASKS_H

#include "LinkedList.h"
#include "Array.h"
#include <iostream>

using Text = LinkedList<Array<char>>;

void Load(std::istream&, Text&);

std::ostream& Write(std::ostream&, const Text&);

//Print words with odd letter lenght without first and last character
std::ostream& Task1(std::ostream&, const Text&);

//Print all words(without first) if word's letters in alphabetic order(a, ab, abc, ...)
std::ostream& Task2(std::ostream&, const Text&);

//Print words(without 'a' and 'o') which not equal the first letter of the first word
std::ostream& Task3(std::ostream&, const Text&);

/*
Print all words, that not equal to first word
If words count less than 2 -> print message, otherwise:
If odd letters count -> without last
Otherwise -> double first
*/
std::ostream& Task4(std::ostream&, const Text& text);

int countChar(const Text& text, char symbol);


#endif