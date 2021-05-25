#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <vector>
#include <mysql.hpp>

#include "SearchResult/SearchResult.hpp"

class Search
{
private:

public:
    [[nodiscard]] const std::vector<SearchResult>& search(const std::string& text, sql::Connection* connection, unsigned int count);

};

#endif
