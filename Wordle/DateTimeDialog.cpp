#include "DateTimeDialog.h"

#include <QListWidget>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QDateTime>

DateTimeDialog::DateTimeDialog(QWidget *parent)
    : QDialog(parent)
{
    m_listWidget = new QListWidget(this);
    QDateTime now = QDateTime::currentDateTime();
    m_listWidget->addItem(now.toString("d-MMM-yy"));
    m_listWidget->addItem(now.toString("dd-MMM-yy"));
    m_listWidget->addItem(now.toString("ddd d MMM yy"));
    m_listWidget->addItem(now.toString("dddd, d MMMM yyyy"));
    m_listWidget->addItem(now.toString("h:mm AP"));
    m_listWidget->addItem(now.toString("h:mm:ss AP"));
    m_listWidget->addItem(now.toString("hh:mm"));
    m_listWidget->addItem(now.toString("hh:mm:ss"));
    m_listWidget->setCurrentRow(0);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_listWidget);
    layout->addWidget(buttonBox);
}

DateTimeDialog::~DateTimeDialog()
{
}

QString DateTimeDialog::selectedFormat() const
{
    return m_listWidget->currentItem()->text();
}
