#include "SearchResult.hpp"

SearchResult::SearchResult(const std::string& url, const std::string& title) :
    url(url),
    title(title)
{
}

web::json::value SearchResult::asJSON() const
{
    web::json::value result = web::json::value::object();

    result["url"] = web::json::value::string(this->url);
    result["title"] = web::json::value::string(this->title);

    return result;
}