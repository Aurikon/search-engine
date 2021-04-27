#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <string>
#include <ctime>

class Document
{
private:
    std::string url;
    std::string title;
    std::string description;
    std::string content;
    time_t lastUpdatedTime;

public:
    Document(std::string url, std::string title, std::string description, std::string content, time_t time);
    const std::string& getTitle() const;
    const std::string& getDescription() const;
    const std::string& getContent() const;
    const std::string& getUrl() const;
    time_t getLastUpdatedTime() const;
};

#endif
