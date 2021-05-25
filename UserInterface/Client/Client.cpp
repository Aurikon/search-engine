#include "Client.hpp"

Client::Client(std::string& uri) 
: client(uri)
{
}

std::vector<SearchResult> Client::makeRequest(const std::string& message)
{
    std::vector<SearchResult> results;
    client.request(methods::GET, "", message).then([&results](http_response responce)
    {
        if(responce.status_code() == status_codes::OK)
        {
            json::value cs = responce.extract_json().get().as_object().at("data");

            for(auto it = cs.as_array().begin(); it != cs.as_array().end(); ++it)
            {
                auto searchResult = SearchResult::fromJSON(it->as_object());
                results.push_back(searchResult);
            }
        }
    }).wait();

    return results;
}