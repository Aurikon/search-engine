#include <string>
#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <mysql_error.h>
#include <mysql/mysql.h>
#include <mysql/jdbc.h>
#include <gumbo.h>
#include <curl/curl.h>

bool isLinkAbsolute(const std::string& url)
{
    if(url.size() < 2)
    {
        return false;
    }

    if(url[0] == '/' && url[1] == '/' || std::string(url, 0, 7) == "http://" || std::string(url, 0, 8) == "https://") 
    {
        return true;
    }

    return false;
}
std::size_t write_data(void* ptr, std::size_t size, std::size_t nmemb, std::string* data)
{
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}

std::string getBody(const std::string& url)
{
    CURL* curl = curl_easy_init();

    std::string bodyResult{};
    char *tmp = NULL;
    
    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &bodyResult);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        
        CURLcode curlcode = curl_easy_perform(curl);

        curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &tmp);
        curl_easy_cleanup(curl);
    }
    std::string effectiveUrl(tmp);
    if(tmp)
    {
        printf("%s\n", tmp);
        std::cout << effectiveUrl << std::endl;
    }
    return bodyResult;
}

void extractLinks(GumboNode* node, std::string rootURL)
{
    if(node->type != GUMBO_NODE_ELEMENT)
    {
        return;
    }

    if(node->v.element.tag == GUMBO_TAG_A)
    {
        GumboAttribute* href = gumbo_get_attribute(&node->v.element.attributes, "href");
        if(href)
        {   
            std::string tmp(href->value);
            if(isLinkAbsolute(tmp))
            {
                std::cout << "absolute " << href->value << std::endl;
            }
            else
            {
                if(tmp[0] == '/')
                {
                    std::cout << "not absolute: " << rootURL << href->value << std::endl;
                }
                std::cout << "not url" << tmp << std::endl;
            }
        }
        return;
    }
    GumboVector* children = &node->v.element.children;
    for(std::size_t i = 0; i < children->length; ++i)
    {
        extractLinks(static_cast<GumboNode*>(children->data[i]), rootURL);
    }
}
void parse(const std::string& body, std::string rootURL)
{
    
    GumboOutput* output = gumbo_parse(body.c_str());
    if(!output)
    {
        return;
    }

    extractLinks(output->root, rootURL);   
    
    gumbo_destroy_output(&kGumboDefaultOptions, output);
}


int main()
{
    std::string url = "https://rau.am";
    parse(getBody(url), url);
    return 0;
}