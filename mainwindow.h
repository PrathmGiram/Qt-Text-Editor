#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionnew_triggered();
    void on_actionSave_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_As_triggered();
    void on_actioncopy_2_triggered();
    void on_actionCut_triggered();
    void on_actionPaste_triggered();

    void on_actionAbout_Me_triggered();

    void on_actionSuperscript_triggered();

    void on_actionSubscript_triggered();

private:
    Ui::MainWindow *ui;
    QString mFilename;
};

#endif // MAINWINDOW_H
