#ifndef LINKINFO_HPP
#define LINKINFO_HPP

#include "LinkStatus.hpp"

#include <string>
#include <ctime>

class LinkInfo
{
private:
    std::string url;
    std::string domain;
    LinkStatus status;
    time_t loadedTime;

public:
    LinkInfo(std::string url, std::string domain, LinkStatus status, time_t loadedTime);

    const std::string& getUrl() const;
    const std::string& getDomain() const;
    LinkStatus getStatus() const;
    time_t getLoadedTime() const;
};

#endif
