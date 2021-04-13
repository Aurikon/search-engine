#include "Parser.hpp"

void Parser::parse(const std::string& body, const std::string& rootURL)
{
    
    this->domain = this->getDomain(rootURL);
    GumboOutput* output = gumbo_parse(body.c_str());
    if(!output)
    {
        return;
    }
    
    this->extractLinks(output->root, domain);
    this->extractTitle(output->root);
    this->extractDescription(output->root);

    gumbo_destroy_output(&kGumboDefaultOptions, output);
}


const std::string& Parser::getDomain(const std::string& rootURL) const
{   
    std::size_t slashPos = 0;
    for(std::size_t i = 0; i < rootURL.size(); ++i, ++slashPos)
    {
        if(rootURL[i] == '/' && rootURL[i-1] == '/')
        {
            break;
        }
    }
    while (rootURL[slashPos] != '/')
    {
        ++slashPos;
    }

    return std::string(rootURL, 0, slashPos);
}

void Parser::extractLinks(GumboNode* node, const std::string& domain)
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
            if(this->isLinkAbsolute(href->value))
            {
                this->links.push_back(href->value); 
            }
            else
            {
                this->links.push_back(domain + href->value);
            }
        }
        return;
    }
    
    GumboVector* children = &node->v.element.children;
    for(std::size_t i = 0; i < children->length; ++i)
    {
        this->extractLinks(static_cast<GumboNode*>(children->data[i]), domain);
    }
}


void Parser::extractTitle(GumboNode* node)
{
    if(node->type != GUMBO_NODE_ELEMENT)
    {
        return;
    }

    // find head
    GumboNode* head = NULL;
    GumboVector* nodeChildren = &(node->v.element.children);
    for(auto i = 0; i < nodeChildren->length; ++i)
    {
        GumboNode* child = static_cast<GumboNode*>(nodeChildren->data[i]);

        if(child->type == GUMBO_NODE_ELEMENT && child->v.element.tag == GUMBO_TAG_HEAD)
        {
            head = child;
            break;
        }
    }

    GumboVector* headChildren = &head->v.element.children;
    for(auto i = 0; i < headChildren->length; ++i)
    {
        GumboNode* child = static_cast<GumboNode*>(headChildren->data[i]);

        if(child->type == GUMBO_NODE_ELEMENT && child->v.element.tag == GUMBO_TAG_TITLE)
        {
            if(child->v.element.children.length != 1)
            {
                this->title = "<empty title>";
            }
            GumboNode* titleText = static_cast<GumboNode*>(child->v.element.children.data[0]);
            this->title = titleText->v.text.text;
        }
    }

    this->title = "<title not found>";
}

void Parser::extractDescription(GumboNode* node)
{
    if(node->type != GUMBO_NODE_ELEMENT)
    {
        return;
    }

    // find head
    GumboNode* head = NULL;
    GumboVector* nodeChildren = &(node->v.element.children);
    for(auto i = 0; i < nodeChildren->length; ++i)
    {
        GumboNode* child = static_cast<GumboNode*>(nodeChildren->data[i]);

        if(child->type == GUMBO_NODE_ELEMENT && child->v.element.tag == GUMBO_TAG_HEAD)
        {
            head = child;
            break;
        }
    }

    GumboVector* headChildren = &head->v.element.children;
    for(auto i = 0; i < headChildren->length; ++i)
    {
        GumboNode* child = static_cast<GumboNode*>(headChildren->data[i]);

        if(child->type == GUMBO_NODE_ELEMENT && child->v.element.tag == GUMBO_TAG_META)
        {
            GumboAttribute* name = gumbo_get_attribute(&node->v.element.attributes, "name");

            if(name->value == "description")
            {
                GumboAttribute* content = gumbo_get_attribute(&node->v.element.attributes, "content");
                this->description = content->value;
            }
        }
    }
}

void Parser::extractContent(GumboNode* node)
{
    if (node->type != GUMBO_NODE_ELEMENT || node->v.element.tag == GUMBO_TAG_STYLE || node->v.element.tag==GUMBO_TAG_SCRIPT) 
    {
		return;
	}

    if (node->type==GUMBO_NODE_TEXT) 
    {
		this->content += std::string(node->v.text.text);
		this->content += '\n';
		return;
	}
	
	GumboVector* children = &node->v.element.children;
	for (size_t i = 0; i < children->length; ++i) 
    {
		this->content += ' ';
		this->extractContent(static_cast<GumboNode*>(children->data[i]));	
	}
}

const std::vector<std::string>& Parser::getLinks() const
{
    return this->links;
}

const std::string& Parser::getTitle() const
{
    return this->title;
}

const std::string& Parser::getDescription() const
{
    return this->description;
}
const std::string& Parser::getContent() const
{
    return this->content;
}

bool Parser::isLinkAbsolute(const std::string& url)
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
