#include <iostream>
#include <string>

#include "Client.hpp"

int main()
{
    std::string host = "http://localhost:23568";
    Client client(host);

    std::string message{};
    std::cout << "\t\t\t Welcome \t\t\t " << std::endl;
    std::cout << "What are we looking for? " <<  std::endl;
    std::cin >> message;

    auto results = client.makeRequest(message);

    for(auto elem : results)
    {
        std::cout << elem.getTitle() << std::endl;
        std::cout << elem.getUrl() << std::endl;

        std::cout << "\n\n\n";
    }
    
    return 0;
}