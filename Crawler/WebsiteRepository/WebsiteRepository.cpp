#include "WebsiteRepository.hpp"

#include <algorithm>

const std::vector<Website>& WebsiteRepository::getAll() const
{
    return websites;
}

const std::pair<bool, Website> WebsiteRepository::getById(int id) const
{
    if(id < idCounter)
    {
        return std::make_pair(true, websites[id]);
    }
    else
    {
        std::make_pair(false, nullptr);
    }
}

const std::pair<bool, Website> WebsiteRepository::getByDomain(const std::string& domain) const
{
    for(auto website : websites)
    {
        if(website.getDomain() == domain)
        {
            return std::make_pair(true, website);
        }
    }

    return std::make_pair(false, nullptr); 
}

bool WebsiteRepository::add(const Website& website)
{
    websites[idCounter++] = website;
    return true;
}

void WebsiteRepository::update(int id, const Website& website)
{
    websites[id] = Website;
}