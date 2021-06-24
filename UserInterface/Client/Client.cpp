#include "Client.hpp"

Client::Client(std::string& uri) 
: client(uri)
{
}

std::vector<SearchResult> Client::makeRequest(const std::string& message)
{
    std::vector<SearchResult> results{};
    client.request(methods::GET, "", message).then([&results](http_response responce)
    {
        if(responce.status_code() == status_codes::OK)
        {
            auto array = responce.extract_json().get().at("results").as_array();

            for(auto it = array.begin(); it != array.end(); ++it)
            {
                auto searchResult = SearchResult::fromJSON(it->as_object());
                results.push_back(searchResult);
            }
        }
    }).wait();

    return results;
}