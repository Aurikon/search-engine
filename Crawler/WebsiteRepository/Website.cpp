#include "Website.hpp"

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