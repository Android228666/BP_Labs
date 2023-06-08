#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MatrixTrace; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MatrixTrace *ui;
private slots:
    void onClick();
    void documentationClick();
    void spinBox1ValueChanged(int value);
    void spinBox2ValueChanged(int value);


};
#endif // MAINWINDOW_H
