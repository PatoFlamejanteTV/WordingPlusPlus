#include "Document.h"

Document::Document(QObject *parent)
    : QObject(parent)
{
}

Document::~Document()
{
}

QString Document::text() const
{
    return m_text;
}

void Document::setText(const QString &text)
{
    if (m_text != text) {
        m_text = text;
    }
}
