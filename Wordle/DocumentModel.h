// DocumentModel.h

#pragma once

#include <string>
#include <vector>

class DocumentModel
{
public:
    DocumentModel();
    ~DocumentModel();

    void SetContent(const std::wstring& content);
    const std::wstring& GetContent() const;

    // We can add more document-related data here later,
    // such as formatting information, etc.

private:
    std::wstring m_content;
};
