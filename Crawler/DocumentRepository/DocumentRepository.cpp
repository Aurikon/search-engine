#include "DocumentRepository.hpp"

const std::vector<Document>& DocumentRepository::getAll() const
{
    return this->documents;
}

void DocumentRepository::add(const Document& document)
{
    this->documents.push_back(document);
}
