# 📝 TextEditor_QTCreator

A lightweight yet feature-rich **Text Editor** built using **C++ and Qt Framework**.  
Includes basic file operations, rich text formatting (Bold, Subscript, Superscript), clipboard controls, undo/redo, and an interactive **"About Me"** popup.

---

## 🚀 How to Run the Code

1. **Open Qt Creator**
2. Go to:  
   **File > Open File or Project** (`Ctrl+O` or `Cmd+O` on macOS)
3. Select your project file:
   - `.pro` (qmake)
   - `CMakeLists.txt` (CMake)
4. In the **Configure Project** tab, select your desired kit (e.g., Desktop Qt 5 or 6)
5. Click **Configure Project**
6. Press `Ctrl+R` or click the **Run** button to launch the application

---

## ✅ What Has Been Done

### 🔹 New File

```cpp
ui->textEdit->setPlainText("");


# Open File

QString file = QFileDialog::getOpenFileName(this, "Open a file");
mFilename = file;
QFile sFile(file);

if (sFile.open(QFile::ReadOnly | QFile::Text)) {
    QTextStream in(&sFile);
    QString text = in.readAll();
    sFile.close();
    ui->textEdit->setPlainText(text);
}

# Save File

QTextStream out(&sFile);
out << ui->textEdit->toPlainText();
sFile.flush();
sFile.close();

# Save As

QString file = QFileDialog::getSaveFileName(this, "Save As");

# Copy, Cut, Paste

ui->textEdit->copy();
ui->textEdit->cut();
ui->textEdit->paste();


# Super Script and sub Script

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

# About me

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


👤 Author

Prathmesh Giram
🎓 PG-DBDA | CDAC Kharghar
💼 https://www.linkedin.com/in/prathmeshgiram'>prathmeshgiram
