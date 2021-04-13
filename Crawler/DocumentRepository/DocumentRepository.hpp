#ifndef DOCUMENTREPOSITORY_HPP
#define DOCUMENTREPOSITORY_HPP

#include "Document.hpp"

#include <vector>

class DocumentRepository
{
private:
    std::vector<Document> documents;

public:
    const std::vector<Document>& getAll() const;
    void add(const Document& document);
};


#endif
