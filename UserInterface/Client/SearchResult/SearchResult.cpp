#include "SearchResult.hpp"

SearchResult::SearchResult() = default;

SearchResult::SearchResult(const std::string& url, const std::string& title) :
    url(url),
    title(title)
{
}

SearchResult SearchResult::fromJSON(const web::json::object& object)
{
    SearchResult result;
    result.url = object.at("url").as_string();
    result.title = object.at("title").as_string();

    return result;
}

std::string SearchResult::getUrl() const
{
    return this->url;
}

std::string SearchResult::getTitle() const
{
    return this->title;
}