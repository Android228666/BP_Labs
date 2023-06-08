#include "matrix.h"
#include "qdebug.h"
#include <stdexcept>
Matrix::Matrix(int size)
{
    if(size < 0 || size > 8){
        throw std::invalid_argument("Invalid matrix size! The size of the matrix can be from 0 to 8");
    }
    this->size = size;
    this->trace = 0;
    matrix = new double*[size];
    for(int i = 0; i < size; i++){
        matrix[i] = new double[size];
        for(int j = 0; j < size; j++){
            matrix[i][j] = 0;
        }
    }
}

Matrix::~Matrix(){
    for(int i = 0; i < size; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Matrix::setCell(const QString& value, int i, int j){
    bool isOk = true;
    double temp = value.toDouble(&isOk);
    if(!isOk){
        throw std::invalid_argument("Invalid cell value!");
    }
    matrix[i][j] = temp;
}

void Matrix::printMatrix(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            qDebug() << matrix[i][j] << " ";
         }
        qDebug() << "\n";
    }
}

double Matrix::calculateMatrixTrace(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(i == j){
                trace += matrix[i][j];
            }
        }
    }
    return trace;
}

bool Matrix::checkTrace(){
    return trace == 0 ? true : false;
}


