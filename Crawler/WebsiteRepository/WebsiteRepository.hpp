#ifndef WEBSITEREPOSITORY_HPP
#define WEBSITEREPOSITORY_HPP

#include "Website.hpp"

#include <vector>
#include <optional>

class WebsiteRepository
{
private:
    std::vector<Website> websites;
public:
    const std::vector<Website>& getAll() const; // return websites
    const std::optional<Website> getByDomain(const std::string& domain) const;

    void add(const Website& website);

    void update(const std::string& domain, const Website& website); // update website with domain to website
};


#endif
