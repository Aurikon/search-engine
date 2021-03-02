#include "Page.hpp"

Page::Page(std::string& body, int status):
        body(body), status(status)
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