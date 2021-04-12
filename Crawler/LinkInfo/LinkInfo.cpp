#include "LinkInfo.hpp"

LinkInfo::LinkInfo(std::string url, std::string domain, LinkStatus status, time_t loadedTime) :
    url(std::move(url)),
    domain(std::move(domain)),
    status(status),
    loadedTime(loadedTime)
{
}

const std::string& LinkInfo::getUrl() const
{
    return this->url;
}

const std::string& LinkInfo::getDomain() const
{
    return this->domain;
}

LinkStatus LinkInfo::getStatus() const
{
    return this->status;
}

time_t LinkInfo::getLoadedTime() const
{
    return this->loadedTime;
}