#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "matrix.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MatrixTrace)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::onClick(){
    try{
        int firstMatrixSize = ui->spinBox1->value();
        int secondMatrixSize = ui->spinBox2->value();
        qDebug() << "FisrstMatrixSize: " << firstMatrixSize;
         qDebug() << "SecondMatrixSize: " << secondMatrixSize;
        Matrix matrix1(firstMatrixSize);
        Matrix matrix2(secondMatrixSize);

        for(int i = 0; i< firstMatrixSize; i++){
            for(int j = 0; j < firstMatrixSize; j++){
                QTableWidgetItem* item = ui->tableWidget1->item(i, j);
                if(item != nullptr){
                    QString cellText = item->text();
                    if(!cellText.isEmpty()){
                        matrix1.setCell(cellText, i, j);
                    }
                }
            }
        }

        for(int i =0; i< secondMatrixSize; i++){
            for(int j = 0; j < secondMatrixSize; j++){
                QTableWidgetItem* item = ui->tableWidget2->item(i, j);
                if(item != nullptr){
                    QString cellText = item->text();
                    if(!cellText.isEmpty()){
                        matrix2.setCell(cellText, i, j);
                    }
                }
            }
        }

        double firstMatrixTrace = matrix1.calculateMatrixTrace();
        double secondMatrixTrace = matrix2.calculateMatrixTrace();
        if(matrix1.checkTrace() && matrix2.checkTrace()){
            throw std::runtime_error("Both traces of matrices are equal to 0");
        }else if(matrix1.checkTrace()){
            throw std::runtime_error("First matrix trace is 0");
        }else if(matrix2.checkTrace()){
            throw std::runtime_error("Second matrix trace is 0");
        }

        if(std::abs(firstMatrixTrace - secondMatrixTrace) < 0.000001){
            ui->lineEdit->setText("The trace of the matrices is equal!");
        }else if(firstMatrixTrace > secondMatrixTrace){
            ui->lineEdit->setText("First matrix trace is greater.");
        }else{
            ui->lineEdit->setText("Second matrix trace is greater.");
        }

    }catch(const std::exception& e){
        qDebug() << e.what();
        QMessageBox::critical(ui->centralwidget, "Error", e.what());
    }catch(...){
        QMessageBox::critical(ui->centralwidget, "Error", "Unknown error!");
    }
}

void MainWindow::spinBox1ValueChanged(int value){
    if(value < 0){
        value = 0;
    }
    ui->tableWidget1->setColumnCount(value);
    ui->tableWidget1->setRowCount(value);
}

void MainWindow::spinBox2ValueChanged(int value){
    if(value < 0){
        value = 0;
    }
    ui->tableWidget2->setColumnCount(value);
    ui->tableWidget2->setRowCount(value);
}

void MainWindow::documentationClick(){
    QMessageBox::information(
        nullptr,
        "Documentation",
        "Hello! I am very glad that you are using my software. "
        "This program is designed to determine the matrix with the larger trace (the sum of the diagonal elements) of the two given. "
        "The size of the matrix can be from 0 to 8, and the trace should not be equal to 0. Enjoy using it.");
}



