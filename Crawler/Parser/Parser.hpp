#ifndef PARSER_HPP
#define PARSER_HPP

#include <gumbo.h>
#include <vector>
#include <string>
#include <iostream>

#include "Page.hpp"

class Parser
{
private: // data

    std::vector<std::string> links;
    std::string title;
    std::string description;
    std::string content;

    std::string domain;
private: // functions

    void extractLinks(GumboNode* node, const std::string& domain);
    bool isLinkAbsolute(const std::string& url);
    

public:
    const std::vector<std::string>& getLinks() const;
    const std::string& getTitle() const;
    const std::string& getDescription() const;
    const std::string& getContent() const;

    const std::string& getDomain(const std::string& rootURL) const; 
    
    void parse(const Page& page, const std::string& rootURL);
};

#endif
