#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "functions.cpp"
#include <QVector>
#include <QDebug>

void AddElement(int Row, int Col, int Value, QVector<int> *PD, QVector<int> *VE);
int SearchElement(int Row, int Col, QVector<int> *PD, QVector<int> *VE);
void Swap(int *Row, int *Col);
void OpenFile(/*int size, int value,*/ QVector<int> *PD, QVector<int> *VE);

#endif // FUNCTIONS_H
