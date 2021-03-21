#ifndef PAGE_HPP
#define PAGE_HPP

#include <string>
class Page
{
private:
    std::string domain;
    std::string body; // html code
    int status;
    
public:
    Page(std::string& body, int status);
    ~Page();

    const std::string& getBody() const;
    int getStatus() const;
};

#endif
