#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QObject>
#include <QString>

class Document : public QObject
{
    Q_OBJECT

public:
    Document(QObject *parent = nullptr);
    ~Document();

    QString text() const;
    void setText(const QString &text);

private:
    QString m_text;
};

#endif // DOCUMENT_H
