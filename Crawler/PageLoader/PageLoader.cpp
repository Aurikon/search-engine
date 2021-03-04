#include "PageLoader.hpp"

Page PageLoader::load(const std::string& url)
{
    CURL* curl = curl_easy_init();

    std::string result{};
    int status;

    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        
        CURLcode curlcode = curl_easy_perform(curl);

        curl_easy_getinfo(curl, CURLINFO_HTTP_CODE, &status);

        curl_easy_cleanup(curl);
    }
    
    return Page(result, status);
}

std::size_t PageLoader::write_data(void* ptr, std::size_t size, std::size_t nmemb, std::string* data)
{
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}