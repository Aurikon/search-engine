#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include "../Client/SearchResult/SearchResult.hpp"

class UserInterface
{
public:
    virtual void UIMain() = 0;
    virtual void UIRequest(const std::string& message) = 0;
    virtual void UIShowResults(std::vector<SearchResult> results) = 0;
};

#endif
