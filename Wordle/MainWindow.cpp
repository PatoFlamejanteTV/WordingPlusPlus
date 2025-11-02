#include "MainWindow.h"
#include "Document.h"
#include "View.h"
#include "FileNewDialog.h"
#include "DateTimeDialog.h"

#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QPrinter>
#include <QPrintDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    document = new Document(this);
    view = new View(document, this);
    setCentralWidget(view);

    createActions();
    createMenus();
    createToolBars();
    statusBar();
}

MainWindow::~MainWindow()
{
}

void MainWindow::newFile()
{
    FileNewDialog dialog(this);
    if (dialog.exec()) {
        document->setText(QString());
        qInfo() << "New file created";
    }
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
        tr("Text Files (*.txt);;All Files (*)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QString errorMsg = tr("Could not open file: %1").arg(fileName);
            QMessageBox::critical(this, tr("Error"), errorMsg);
            qWarning() << errorMsg;
            return;
        }
        QTextStream in(&file);
        document->setText(in.readAll());
        file.close();
        qInfo() << "Opened file:" << fileName;
    }
}

void MainWindow::save()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
        tr("Text Files (*.txt);;All Files (*)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QString errorMsg = tr("Could not save file: %1").arg(fileName);
            QMessageBox::critical(this, tr("Error"), errorMsg);
            qWarning() << errorMsg;
            return;
        }
        QTextStream out(&file);
        out << document->text();
        file.close();
        qInfo() << "Saved file:" << fileName;
    }
}

void MainWindow::print()
{
    QPrinter printer;
    QPrintDialog dialog(&printer, this);
    if (dialog.exec()) {
        view->print(&printer);
        qInfo() << "Printed document";
    }
}

void MainWindow::insertDateTime()
{
    DateTimeDialog dialog(this);
    if (dialog.exec()) {
        view->textCursor().insertText(dialog.selectedFormat());
    }
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About WordPad"),
        tr("This is a simple WordPad clone created with Qt."));
}

void MainWindow::createActions()
{
    newAct = new QAction(tr("&New"), this);
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);
    openAct = new QAction(tr("&Open..."), this);
    connect(openAct, &QAction::triggered, this, &MainWindow::open);
    saveAct = new QAction(tr("&Save"), this);
    connect(saveAct, &QAction::triggered, this, &MainWindow::save);
    printAct = new QAction(tr("&Print..."), this);
    connect(printAct, &QAction::triggered, this, &MainWindow::print);
    exitAct = new QAction(tr("E&xit"), this);
    connect(exitAct, &QAction::triggered, qApp, &QApplication::quit);
    undoAct = new QAction(tr("&Undo"), this);
    connect(undoAct, &QAction::triggered, view, &QTextEdit::undo);
    cutAct = new QAction(tr("Cu&t"), this);
    connect(cutAct, &QAction::triggered, view, &QTextEdit::cut);
    copyAct = new QAction(tr("&Copy"), this);
    connect(copyAct, &QAction::triggered, view, &QTextEdit::copy);
    pasteAct = new QAction(tr("&Paste"), this);
    connect(pasteAct, &QAction::triggered, view, &QTextEdit::paste);
    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

    insertDateTimeAct = new QAction(tr("Date and &Time..."), this);
    connect(insertDateTimeAct, &QAction::triggered, this, &MainWindow::insertDateTime);
}

}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(undoAct);
    editMenu->addSeparator();
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);

    viewMenu = menuBar()->addMenu(tr("&View"));
    insertMenu = menuBar()->addMenu(tr("&Insert"));
    insertMenu->addAction(insertDateTimeAct);
    formatMenu = menuBar()->addMenu(tr("&Format"));

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
}

void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);

    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(undoAct);
    editToolBar->addSeparator();
    editToolBar->addAction(cutAct);
    editToolBar->addAction(copyAct);
    editToolBar->addAction(pasteAct);
}
