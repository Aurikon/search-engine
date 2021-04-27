#include "Website.hpp"


Website::Website(std::string domain, std::string homepage, time_t time, WebsiteStatus status) :
    domain(std::move(domain)),
    homepage(std::move(homepage)),
    lastCrawlingTime(time),
    status(status)
{
}
const std::string& Website::getDomain() const
{
    return this->domain;
}

const std::string& Website::getHomepage() const
{
    return this->homepage;
}

time_t Website::getLastCrawlingTime() const
{
    return this->lastCrawlingTime;
}

WebsiteStatus Website::getStatus() const
{
    return this->status;
}