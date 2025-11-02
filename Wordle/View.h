#ifndef VIEW_H
#define VIEW_H

#include <QTextEdit>

class Document;

class View : public QTextEdit
{
    Q_OBJECT

public:
    View(Document *document, QWidget *parent = nullptr);
    ~View();

private:
    Document *m_document;
};

#endif // VIEW_H
