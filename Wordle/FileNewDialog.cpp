#include "FileNewDialog.h"

#include <QListWidget>
#include <QVBoxLayout>
#include <QDialogButtonBox>

FileNewDialog::FileNewDialog(QWidget *parent)
    : QDialog(parent)
{
    m_listWidget = new QListWidget(this);
    m_listWidget->addItem(tr("Word 6 Document"));
    m_listWidget->addItem(tr("Rich Text Document"));
    m_listWidget->addItem(tr("Text Document"));
    m_listWidget->setCurrentRow(0);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_listWidget);
    layout->addWidget(buttonBox);
}

FileNewDialog::~FileNewDialog()
{
}

int FileNewDialog::selectedType() const
{
    return m_listWidget->currentRow();
}
