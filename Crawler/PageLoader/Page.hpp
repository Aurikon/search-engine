#ifndef PAGE_HPP
#define PAGE_HPP

#include <string>

class Page
{
private:
    std::string body;
    int status;
    
public:
    Page(std::string& body, int status);
    ~Page();

    const std::string& getBody() const;

    int getStatus() const; //0 - successful, 
};

#endif
