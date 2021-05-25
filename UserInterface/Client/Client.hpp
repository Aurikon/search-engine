#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <cpprest/http_client.h>
#include <cpprest/json.h>

#include "SearchResult/SearchResult.hpp"

using namespace web;
using namespace web::http;
using namespace web::http::client;

class Client
{
private:
    http_client client;
public:
    Client(std::string& uri);
    std::vector<SearchResult> makeRequest(const std::string& message);
};

#endif
