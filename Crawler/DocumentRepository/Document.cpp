#include "Document.hpp"

Document::Document(std::string url, std::string title, std::string description, std::string content, time_t time) :
    url(std::move(url)),
    title(std::move(title)),
    description(std::move(description)),
    content(std::move(content)),
    lastUpdatedTime(time)
{
}

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