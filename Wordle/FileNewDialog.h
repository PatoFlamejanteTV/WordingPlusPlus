#ifndef FILENEWDIALOG_H
#define FILENEWDIALOG_H

#include <QDialog>

class QListWidget;

class FileNewDialog : public QDialog
{
    Q_OBJECT

public:
    FileNewDialog(QWidget *parent = nullptr);
    ~FileNewDialog();

    int selectedType() const;

private:
    QListWidget *m_listWidget;
};

#endif // FILENEWDIALOG_H
