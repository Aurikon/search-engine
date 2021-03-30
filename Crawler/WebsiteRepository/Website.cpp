#include "Website.hpp"

int Website::getId() const
{
    return this->id;
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