#include "Parser.hpp"
#include "PageLoader.hpp"

int main()
{
    std::string url = "https:://rau.am";

    PageLoader pageLoader;
    Page result = pageLoader.load(url);

    Parser parser;
    parser.parse(result, url);

    std::vector<std::string> l = parser.getLinks();

    for(auto elem : l)
    {
        std::cout << elem << "\n";
    }

    return 0;
}

// make module that save extracted links