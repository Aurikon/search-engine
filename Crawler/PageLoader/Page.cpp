#include "Page.hpp"

Page::Page(std::string& body, std::string& effectiveUrl, int status):
        body(body), 
        effectiveUrl(effectiveUrl),
        status(status)
        {
        }

Page::~Page() = default;

const std::string& Page::getBody() const
{
    return body;
}

int Page::getStatus() const
{
    return status;
}

const std::string Page::getEffectiveUrl() const
{
    return this->effectiveUrl;
}