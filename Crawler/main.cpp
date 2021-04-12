#include "WebsiteRepository.hpp"
#include "LinkInfoRepository.hpp"
#include "PageLoader.hpp"
#include "Parser.hpp"

int main()
{
    WebsiteRepository wr;
    auto& websites = wr.getAll();


    LinkInfoRepository linkRepo;  
    PageLoader pageloader;

    for(auto& website : websites)
    {
        /*  
            check, is website processed
            add or update in lr website homepage
        */
        while(true)
        {
            auto& links = linkRepo.getBy(website.getDomain(), WAITING, 10);
            if(links.size() == 0)
            {
                break;
            }
            for(auto& link : links)
            {
                Page page = pageloader.load(link.getUrl());
                if(page.getStatus() < 200 || page.getStatus() >= 300)
                {
                    linkRepo.save(LinkInfo(link.getUrl(), link.getDomain(), ERROR, time(nullptr)));
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
                    linkRepo.save(LinkInfo(url, website.getDomain(), WAITING, time(nullptr)));
                }

                linkRepo.save(LinkInfo(link.getUrl(), link.getDomain(), LOADED, time(nullptr)));
                // mark current link as loaded
                // update time


            }

        }

        // update website lastCrawlinkTime
    }

    
    return 0;
}