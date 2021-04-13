#include "WebsiteRepository.hpp"
#include "LinkInfoRepository.hpp"
#include "PageLoader.hpp"
#include "Parser.hpp"

int main()
{
    WebsiteRepository websiteRepo;
    auto& websites = websiteRepo.getAll();


    LinkInfoRepository linkRepo;  
    PageLoader pageloader;

    for(auto& website : websites)
    {
        if(website.getStatus() != WebsiteStatus::WAITING)
        {
            continue;
        }
        /*  
            check, is website processed
            add or update in lr website homepage
        */
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
                    continue;
                }
                Parser parser;
                parser.parse(page.getBody(), page.getEffectiveUrl());

                // pars page
                // add links to linksrepository
                // add document to documentRepository
                for(auto& url : parser.getLinks())
                {
                    if(linkRepo.getByUrl(url).has_value())
                    {
                        continue;
                    }
                    linkRepo.save(LinkInfo(url, website.getDomain(), LinkStatus::WAITING, time(nullptr)));
                }

                linkRepo.save(LinkInfo(link.getUrl(), link.getDomain(), LinkStatus::LOADED, time(nullptr)));
                


            }

        }

        // update website lastCrawlinkTime
    }

    
    return 0;
}