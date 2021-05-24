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

public:
    Document(std::string url, std::string title, std::string description, std::string content);
    [[nodiscard]] const std::string& getTitle() const;
    [[nodiscard]] const std::string& getDescription() const;
    [[nodiscard]] const std::string& getContent() const;
    [[nodiscard]] const std::string& getUrl() const;
};

#endif
