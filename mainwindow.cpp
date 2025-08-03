#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QVBoxLayout>
#include <QTextBrowser>  // ✅ needed

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}


MainWindow::~MainWindow() {
    delete ui;
}
// ======= File Operations =======

void MainWindow::on_actionnew_triggered() {
    mFilename = "";
    ui->textEdit->setPlainText("");
}

void MainWindow::on_actionSave_triggered() {
    if (mFilename.isEmpty()) {
        on_actionSave_As_triggered();
        return;
    }

    QFile sFile(mFilename);
    if (sFile.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream out(&sFile);
        out << ui->textEdit->toPlainText();
        sFile.flush();
        sFile.close();
    }
}

void MainWindow::on_actionOpen_triggered() {
    QString file = QFileDialog::getOpenFileName(this, "Open a file");

    if (!file.isEmpty()) {
        QFile sFile(file);
        if (sFile.open(QFile::ReadOnly | QFile::Text)) {
            QTextStream in(&sFile);
            QString text = in.readAll();
            sFile.close();
            ui->textEdit->setPlainText(text);
        }
    }
}

void MainWindow::on_actionSave_As_triggered() {
    QString file = QFileDialog::getSaveFileName(this, "Save As");

    if (!file.isEmpty()) {
        mFilename = file;
        QFile sFile(file);
        if (sFile.open(QFile::WriteOnly | QFile::Text)) {
            QTextStream out(&sFile);
            out << ui->textEdit->toPlainText();
            sFile.flush();
            sFile.close();
        }
    }
}

// ======= Copy/Paste/Cut =======

void MainWindow::on_actioncopy_2_triggered() {
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered() {
    ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered() {
    ui->textEdit->paste();
}

// ======= About Me Dialog =======
void MainWindow::on_actionAbout_Me_triggered()
{
    QDialog* aboutDialog = new QDialog(this);
    aboutDialog->setWindowTitle("About Me");

    QVBoxLayout* layout = new QVBoxLayout();

    QTextBrowser* resumeText = new QTextBrowser();
    resumeText->setHtml(
        "<h2 style='color:#2e86de;'>Prathmesh Giram</h2>"
        "<p><b>CDAC Kharghar</b> - PG-DBDA Student</p>"
        "<p><b>Skills:</b> Python, C++, Qt, Machine Learning, Git, Cloud</p>"
        "<p><b>Projects:</b> Virtual Try-On, Road Sign Classifier</p>"
        "<p><b>LinkedIn:</b> <a href='https://www.linkedin.com/in/prathmeshgiram'>prathmeshgiram</a></p>"
    );
    resumeText->setOpenExternalLinks(true);
    resumeText->setFont(QFont("Arial", 10));

    layout->addWidget(resumeText);
    aboutDialog->setLayout(layout);
    aboutDialog->resize(400, 300);
    aboutDialog->exec();
}

void MainWindow::on_actionSuperscript_triggered()
{
    QTextCharFormat format;
        format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
        ui->textEdit->mergeCurrentCharFormat(format);
}

void MainWindow::on_actionSubscript_triggered()
{
    QTextCharFormat format;
        format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
        ui->textEdit->mergeCurrentCharFormat(format);
}
