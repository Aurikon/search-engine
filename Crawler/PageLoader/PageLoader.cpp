#include "PageLoader.hpp"

#include <curl/curl.h>

Page PageLoader::load(const std::string& url)
{
    CURL* curl = curl_easy_init();

    std::string bodyResult{};
    std::string effectiveUrl{};
    int status;

    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &bodyResult);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        
        CURLcode curlcode = curl_easy_perform(curl);

        
        curl_easy_getinfo(curl, CURLINFO_HTTP_CODE, &status);
        curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, effectiveUrl.c_str());
        curl_easy_cleanup(curl);
    }

    return Page(bodyResult, effectiveUrl, status);
}

std::size_t PageLoader::write_data(void* ptr, std::size_t size, std::size_t nmemb, std::string* data)
{
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}
