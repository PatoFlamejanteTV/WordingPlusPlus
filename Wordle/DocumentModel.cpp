// DocumentModel.cpp

#include "stdafx.h"
#include "DocumentModel.h"

DocumentModel::DocumentModel()
{
}

DocumentModel::~DocumentModel()
{
}

void DocumentModel::SetContent(const std::wstring& content)
{
    m_content = content;
}

const std::wstring& DocumentModel::GetContent() const
{
    return m_content;
}
