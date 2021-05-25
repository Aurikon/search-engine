#include "Search.hpp"

const std::vector<SearchResult>& Search::search(const std::string& text, sql::Connection* connection, unsigned int count)
{
    std::vector<SearchResult> results;
    auto prepst = connection->prepareStatement("SELECT * from Documents WHERE content LIKE '(?)'");
    std::string textSearch = "'%"+ text +"%'";
    prepst->setString(1, textSearch);
    auto result = prepst->executeQuery();
    for(int i = 0; i < count; ++i)
    {
        if(!result->next())
        {
            break;
        }
        std::cout << result->getString("title") << " " << result->getString("url") << "\n";
        results.push_back(SearchResult(result->getString("url"), result->getString("title")));
    }

    return results;
}