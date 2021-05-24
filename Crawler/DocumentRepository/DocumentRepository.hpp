#ifndef DOCUMENTREPOSITORY_HPP
#define DOCUMENTREPOSITORY_HPP

#include "Document.hpp"
#include "mysql.hpp"
#include <vector>

class DocumentRepository
{

public:
    [[nodiscard]] const std::vector<Document>& getAll() const;
    void add(const Document& document, sql::Connection* connection);
};


#endif
