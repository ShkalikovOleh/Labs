#include "Tasks.h"

void Load(std::istream& stream, Text& text)
{
    char current;
    auto word = Array<char>(1);

    while (true)
    {       
        stream.get(current);

        if(stream.eof())
        {
            if(word.size() != 0)
                text.push_back(word);
            break;
        }
            

        if(current != ' ')
            word.push_back(current);

        if(current == ' ' || current == ',' || current == '.' || current == ';')
        {
            bool isEndLineOnly = (word.size() == 1) && (*word.cbegin() == '\n');
            if(word.size() != 0 && !isEndLineOnly)
            {
                word.shrinkToFit();
                text.push_back(word);
                word.clear();
            }            
        }        
    }    
}

std::ostream& Write(std::ostream& stream, const Text& text)
{
    for(auto&& word : text)
    {
        for(auto&& letter : word)            
            stream << letter;                            
                    
        stream << ' ';
    }
}

std::ostream& Task1(std::ostream& stream, const Text& text)
{
    for(auto&& word : text)
    {
        size_t size = word.size();
        if(size % 2 != 0 && size > 2)
        {
            for(auto it = word.cbegin() + 1; it != word.cend() - 1; it++)
            {
                stream << *it;
            }
            stream << std::endl;
        }
    }
    return stream;
}

std::ostream& Task2(std::ostream& stream, const Text& text)
{
    for(auto&& word : text)
    {
        if(word.empty())
            continue;
        if(*word.cbegin() != 'a')
            continue;

        bool flag = true;
        for(auto it = word.cbegin(), jt = word.cbegin() + 1; jt != word.cend(); it++, jt++)
        {
            if((*jt - *it) != 1)
            {
                flag = false;
                break;
            }            
        }

        if(flag)
        {
            for(auto it = word.cbegin() + 1; it != word.cend(); it++)
            {
                stream << *it;
            }
            stream << "." << std::endl;
        }        
    }
    return stream;
}

std::ostream& Task3(std::ostream& stream, const Text& text)
{
    char pivot;
    if(!text.empty())
        pivot = *(text.cbegin()->cbegin());

    for(auto&& word : text)
    {
        if(word.empty())
            continue;

        if(pivot != *word.cbegin())
        {
            for(auto&& letter : word)
            {
                if(letter != 'a' && letter != 'o')
                    stream << letter;
            }
            stream << std::endl;
        }
    }
    return stream;
}

template<typename T, typename Allocator>
bool isEqual(const Array<T, Allocator>& first, const Array<T, Allocator>& second)
{
    if(first.size() != second.size())
        return false;

    for(auto it = first.cbegin(), jt = second.cbegin(); it != first.cend(); it++, jt++)
    {
        if(*it != *jt)
            return false;
    }
    return true;
}

std::ostream& Task4(std::ostream& stream, const Text& text)
{
    if(text.size() < 2)
    {
        stream << "Words less than 2" << std::endl;
    }
    else
    {
        auto first = *(text.cbegin());
        for(auto&& word : text)
        {
            if(!isEqual(word, first))
            {
                int isEven = word.size() % 2;
                if(isEven)
                {
                    for(auto it = word.cbegin(); it != word.cend() - 1; it++)
                    {
                        stream << *it;
                    }
                    stream << std::endl;
                }
                else
                {
                    stream << *word.cbegin();
                    for(auto it = word.cbegin(); it != word.cend(); it++)
                    {
                        stream << *it;
                    }
                    stream << std::endl;
                }
                
            }
        }
    }
    
    return stream;
}