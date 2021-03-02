#include "PageLoader.hpp"
#include <iostream>

int main()
{
    std::string s = "https://rau.am";

    PageLoader PL;
    Page res = PL.load(s);

    std::cout << res.getBody();
    return 0;
}