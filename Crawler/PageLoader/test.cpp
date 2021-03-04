#include "PageLoader.hpp"
#include <iostream>

int main()
{
    std::string url = "http://rau.am";

    PageLoader pageLoader;
    Page result = pageLoader.load(url);

    std::cout << result.getStatus() << std::endl;
    std::cout << result.getBody() << std::endl;
    return 0;
}