#include "Parser.hpp"

#include <cstdio>

void Parser::parse(const Page& page,const std::string& rootURL)
{
    std::string body = page.getBody();
    this->domain = this->getDomain(rootURL);
    GumboOutput* output = gumbo_parse(body.c_str());
    if(!output)
    {
        return;
    }
    this->extractLinks(output->root, domain);
    gumbo_destroy_output(&kGumboDefaultOptions, output);
}

const std::string& Parser::getDomain(const std::string& rootURL) const
{   
    std::size_t slashPos = 0;
    for(std::size_t i = 0; i < rootURL.size(); ++i, ++slashPos)
    {
        if(rootURL[i] == '/' && rootURL[i-1] == '/')
        {
            break;
        }
    }
    while (rootURL[slashPos] != '/')
    {
        ++slashPos;
    }

    return std::string(rootURL, 0, slashPos);
}


void Parser::extractLinks(GumboNode* node, const std::string& domain)
{
    if(node->type != GUMBO_NODE_ELEMENT)
    {
        return;
    }

    if(node->v.element.tag == GUMBO_TAG_A)
    {
        GumboAttribute* href = gumbo_get_attribute(&node->v.element.attributes, "href");
        if(href)
        {
            if(this->isLinkAbsolute(href->value))
            {
                this->links.push_back(href->value); // task: clear links
            }
            else
            {
                this->links.push_back(domain + href->value);
            }
        }
        return;
    }
    
    GumboVector* children = &node->v.element.children;
    for(std::size_t i = 0; i < children->length; ++i)
    {
        this->extractLinks(static_cast<GumboNode*>(children->data[i]), domain);
    }
}

const std::vector<std::string>& Parser::getLinks() const
{
    return this->links;
}

const std::string& Parser::getTitle() const
{
    return this->title;
}

const std::string& Parser::getDescription() const
{
    return this->description;
}
const std::string& Parser::getContent() const
{
    return this->content;
}

bool Parser::isLinkAbsolute(const std::string& url)
{
    if(url.size() < 2) {
        return false;
    }

    if(url[0] == '/' && url[1] == '/' || std::string(url, 0, 7) == "http://" || std::string(url, 0, 8) == "https://") {
        return true;
    }

    return false;
}