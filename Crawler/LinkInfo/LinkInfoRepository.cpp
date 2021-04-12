#include "LinkInfoRepository.hpp"

const std::vector<LinkInfo>& LinkInfoRepository::getAll() const
{
    return this->links;
}

const std::optional<LinkInfo> LinkInfoRepository::getByUrl(const std::string& url) const
{
    for(auto& link : this->links)
    {
        if(link.getUrl() == url)
        {
            return link;
        }
    }

    return {};
}

const std::vector<LinkInfo> LinkInfoRepository::getBy(const std::string& domain, LinkStatus status, int count) const
{
    std::vector<LinkInfo> result;
    for(auto& link : this->links)
    {
        if(link.getDomain() != domain || link.getStatus() != status)
        {
            continue;
        }

        result.push_back(link);

        if(result.size() >= count)
        {
            break;
        }
    }
    
    return result;
}

void LinkInfoRepository::save(const LinkInfo& link)
{
    for(auto& elem : this->links)
    {
        if(elem.getUrl() != link.getUrl())
        {
            continue;
        }

        elem = link;
        return;
    }

    this->links.push_back(link);
}