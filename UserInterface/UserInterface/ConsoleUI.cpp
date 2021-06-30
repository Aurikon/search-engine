#include "ConsoleUI.hpp"

#include <string>
#include <iostream>

#include "../Client/Client.hpp"

ConsoleUI::ConsoleUI(std::string host) :
    client(host)
{
}

void ConsoleUI::UIMain()
{
    std::cout << "\t\t\tWelcome back, searcher!" << std::endl;
    std::string message;
    do
    {
        std::cout << "What are you looking for?" << std::endl;
        std::cin >> message;

        this->UIRequest(message); 
    }
    while(message != "exit");
}

void ConsoleUI::UIRequest(const std::string& message)
{
    auto results = client.makeRequest(message);

    this->UIShowResults(results);
}

void ConsoleUI::UIShowResults(std::vector<SearchResult> results)
{
    for(auto elem : results)
    {
        std::cout << elem.getTitle() << std::endl;
        std::cout << elem.getUrl() << std::endl;

        std::cout << "\n\n";
    }
}