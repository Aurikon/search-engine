#include "DocumentRepository.hpp"
#include "LinkInfoRepository.hpp"
#include "WebsiteRepository.hpp"
#include "PageLoader.hpp"
#include "Parser.hpp"

#include <iostream>

int main()
{
    WebsiteRepository websiteRepo;
    websiteRepo.add(Website("rau.am", "https://rau.am/", time(nullptr), WebsiteStatus::WAITING));
    auto websites = websiteRepo.getAll();


    LinkInfoRepository linkRepo;  
    PageLoader pageloader;

    DocumentRepository documentRepo;
    for(auto& website : websites)
    {
        if(website.getStatus() != WebsiteStatus::WAITING)
        {
            continue;
        }
        
        linkRepo.save(LinkInfo(website.getHomepage(), website.getDomain(), LinkStatus::WAITING, time(nullptr)));
        std::cout << "save link in linkRepo homepage: " << website.getHomepage() << " domain: " << website.getDomain() << "status: WAITING \n"; 
        while(true)
        {
            auto& links = linkRepo.getBy(website.getDomain(), LinkStatus::WAITING, 10);
            if(links.size() == 0)
            {
                break;
            }
            for(auto& link : links)
            {
                Page page = pageloader.load(link.getUrl());
                if(page.getStatus() < 200 || page.getStatus() >= 300)
                {
                    linkRepo.save(LinkInfo(link.getUrl(), link.getDomain(), LinkStatus::ERROR, time(nullptr)));
                    std::cout << "save in linkRepo url: " << link.getUrl() << " domain: " << link.getDomain() << " status: ERROR \n";
                    continue;
                }
                Parser parser;
                parser.parse(page.getBody(), page.getEffectiveUrl(), link.getDomain());
                std::cout << "Parsed " << page.getEffectiveUrl() << "\n";
                documentRepo.add(Document(link.getUrl(), parser.getTitle(), parser.getDescription(), parser.getContent(), time(nullptr)));
                std::cout << "add document in documentRepo \n";
                for(auto& url : parser.getLinks())
                {
                    if(linkRepo.getByUrl(url).has_value())
                    {
                        continue;
                    }
                    linkRepo.save(LinkInfo(url, website.getDomain(), LinkStatus::WAITING, time(nullptr)));
                    std::cout << "save link in linkRepo with status WAITING, domain: " << website.getDomain() << "url: " << url << "\n";
                }

                linkRepo.save(LinkInfo(link.getUrl(), link.getDomain(), LinkStatus::LOADED, time(nullptr)));
                std::cout << "Saved \n\n\n\n\n\n";
            }

        }
        
        websiteRepo.update(website.getDomain(), Website(website.getDomain(), website.getHomepage(), time(nullptr), WebsiteStatus::PROCESSED));
        std::cout << "Update " << website.getDomain() << " " << website.getHomepage() << " status: PROCESSED \n";
    }
    
    return 0;
}