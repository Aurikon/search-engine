#ifndef WEBSITEREPOSITORY_HPP
#define WEBSITEREPOSITORY_HPP

#include <vector>
#include "Website.hpp"

class WebsiteRepository
{
private:
    std::vector<Website> websites;
    int idCounter;
public:
    const std::vector<Website>& getAll() const; // return websites
    const std::pair<bool, Website> getById(int id) const;
    const std::pair<bool, Website> getByDomain(const std::string& domain) const;

    bool add(const Website& website);

    void update(int id, const Website& website); // update website[id] to website
};


#endif
