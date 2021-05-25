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
    SearchResult();
    SearchResult(const std::string& url, const std::string& title);
    static SearchResult fromJSON(const web::json::object& object);

    [[nodiscard]] std::string getUrl() const;
    [[nodiscard]] std::string getTitle() const;
};

#endif
