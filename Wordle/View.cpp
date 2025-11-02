#include "View.h"
#include "Document.h"

View::View(Document *document, QWidget *parent)
    : QTextEdit(parent), m_document(document)
{
    setPlainText(m_document->text());
}

View::~View()
{
}
