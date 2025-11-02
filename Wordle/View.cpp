#include "View.h"
#include "Document.h"

View::View(Document *document, QWidget *parent)
    : QTextEdit(parent), m_document(document)
{
    setPlainText(m_document->text());
    connect(this, &QTextEdit::textChanged, this, &View::onDocumentUpdate);
    connect(m_document, &Document::textChanged, this, &QTextEdit::setPlainText);
}

View::~View()
{
}

void View::onDocumentUpdate()
{
    m_document->setText(toPlainText());
}
