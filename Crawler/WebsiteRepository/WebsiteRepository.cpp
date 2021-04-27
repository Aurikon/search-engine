#include "WebsiteRepository.hpp"



const std::vector<Website>& WebsiteRepository::getAll() const
{
    return websites;
}

const std::optional<Website> WebsiteRepository::getByDomain(const std::string& domain) const
{
    for(auto website : websites)
    {
        if(website.getDomain() == domain)
        {
            return website;
        }
    }

    return {};
}

void WebsiteRepository::add(const Website& website)
{
    websites.push_back(website);
}

void WebsiteRepository::update(const std::string& domain, const Website& website)
{
    for(auto& elem : websites)
    {
        if(elem.getDomain() == domain)
        {
            elem = website;
        }
    }
}