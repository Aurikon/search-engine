#include "Document.hpp"

const std::string& Document::getTitle() const
{
    return this->title;
}

const std::string& Document::getDescription() const
{
    return this->description;
}

const std::string& Document::getContent() const
{
    return this->content;
}
const std::string& Document::getUrl() const
{
    return this->url;
}

time_t Document::getLastUpdatedTime() const
{
    return this->lastUpdatedTime;
}