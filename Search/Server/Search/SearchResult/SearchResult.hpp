#ifndef SEARCHRESULT_HPP
#define SEARCHRESULT_HPP

#include <vector>
#include <string>
#include <cpprest/json.h>

class SearchResult
{
private:
    std::string url;
    std::string title;
    
public:
    SearchResult(const std::string& url, const std::string& title);
    web::json::value asJSON() const;
};

#endif
