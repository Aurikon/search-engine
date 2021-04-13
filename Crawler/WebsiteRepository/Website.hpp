#ifndef WEBSITE_HPP
#define WEBSITE_HPP

#include "WebsiteStatus.hpp"

#include <string>

class Website
{
private:
    std::string domain;
    std::string homepage;
    time_t lastCrawlingTime;  
    WebsiteStatus status;

public:
    const std::string& getDomain() const;
    const std::string& getHomepage() const;
    time_t getLastCrawlingTime() const;
    WebsiteStatus getStatus() const;
};

#endif
