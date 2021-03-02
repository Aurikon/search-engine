#include "PageLoader.hpp"

Page PageLoader::load(std::string& url)
{
    CURL* curl;
    curl = curl_easy_init();

    std::string result{};
    CURLcode status;

    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);

        status = curl_easy_perform(curl);

        curl_easy_cleanup(curl);
    }
    
    return Page(result, status);
}

std::size_t write_data(void* ptr, std::size_t size, std::size_t nmemb, std::string* data)
{
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}