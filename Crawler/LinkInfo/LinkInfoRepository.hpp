#ifndef LINKINFOREPOSITORY_HPP
#define LINKINFOREPOSITORY_HPP

#include "LinkInfo.hpp"
#include <vector>
#include <optional>

class LinkInfoRepository
{
private:
    std::vector<LinkInfo> links;

public:
    const std::vector<LinkInfo>& getAll() const;
    const std::optional<LinkInfo> getByUrl(const std::string& url) const;
    const std::vector<LinkInfo> getBy(const std::string& domain, LinkStatus status, int count) const;

    void save(const LinkInfo& link);
};

#endif
