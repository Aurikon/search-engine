#include "PageLoader.hpp"
#include <iostream>
#include <curl/curl.h>

Page PageLoader::load(const std::string& url, std::string& domain)
{
    CURL* curl = curl_easy_init();

    std::string bodyResult{};
    char* contentType = NULL;
    int status;
    char* EffectiveUrl = NULL;
    

    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &bodyResult);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        
        CURLcode curlcode = curl_easy_perform(curl);

        if(curlcode == CURLE_OK)
        {
            curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &contentType);
            curl_easy_getinfo(curl, CURLINFO_HTTP_CODE, &status);
            curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &EffectiveUrl);
        }
        curl_easy_cleanup(curl);
    }
    std::cout << contentType << std::endl;
    auto tmp = std::string(EffectiveUrl);
    return Page(domain, tmp, bodyResult, status);
}

std::size_t PageLoader::write_data(void* ptr, std::size_t size, std::size_t nmemb, std::string* data)
{
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}
