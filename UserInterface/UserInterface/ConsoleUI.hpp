#ifndef CONSOLEUI_HPP
#define CONSOLEUI_HPP

#include "UserInterface.hpp"
#include "../Client/Client.hpp"

class ConsoleUI : virtual protected UserInterface
{   
private:
    Client client;
public:
    ConsoleUI(std::string host);

    void UIMain() override;
    void UIRequest(const std::string& message) override;
    void UIShowResults(std::vector<SearchResult> results) override;
};

#endif
