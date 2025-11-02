#ifndef DATETIMEDIALOG_H
#define DATETIMEDIALOG_H

#include <QDialog>

class QListWidget;

class DateTimeDialog : public QDialog
{
    Q_OBJECT

public:
    DateTimeDialog(QWidget *parent = nullptr);
    ~DateTimeDialog();

    QString selectedFormat() const;

private:
    QListWidget *m_listWidget;
};

#endif // DATETIMEDIALOG_H
