//#include "functions.h"
#include <QVector>
#include <QDebug>

void AddElement(int Row, int Col, int Value, QVector<int> *PD, QVector<int> *VE);
int SearchElement(int Row, int Col, QVector<int> *PD, QVector<int> *VE);
void Swap(int *Row, int *Col);
void OpenFile(/*int size, int value,*/ QVector<int> *PD, QVector<int> *VE);
bool check(int Row, int Col, QVector<int> *PD);
void DelElement(int Row, int Col, QVector<int> *PD, QVector<int> *VE);

void AddElement(int Row, int Col, int Value, QVector<int> *PD, QVector<int> *VE)
{
    Swap(&Row, &Col);
    if(Row == Col)
    {
        VE->replace(PD->at(Row) - 1, Value);
        qDebug() << *PD << "\n" << *VE;
    }
    else
    {
        bool ok = check(Row, Col, PD);
        if(ok){
            if((PD->at(Row) - PD->at(Row - 1) - 1) == 0){
                for(int i = Row; i != PD->size(); i++)
                {
                    PD->replace(i, PD->at(i) + (Row - Col)); // Увеличение на единицу значений в массиве PD
                }
                int new_pos = PD->at(Row) - (Row - Col++) - 1;
                VE->insert(new_pos, Value);

                new_pos++;
                int PD_pos = PD->at(Row) - 1;
                while(new_pos < PD_pos)
                {
                    VE->insert(new_pos++, 0);
                }
            }
            else
            {
                int empty = Row - (PD->at(Row) - PD->at(Row - 1) - 1);
                // Количество пустых ячеек в строке, при условии, что часть уже заполнена.
                qDebug() << QString("Пустых в строке %1: %2").arg(Row + 1).arg(empty);
                for(int i = 0; i < empty; i++)
                {
                    if(i == Col)
                    {
                       for(int j = Row; j < PD->size(); j++) {
                           qDebug() << Row << PD->size();
                           PD->replace(j, PD->at(j) + 1);
                       }
                       int new_pos = PD->at(Row) - (Row - i) - 1;
                       VE->insert(new_pos, Value);

                    }
                    if(i > Col)
                    {
                       for(int j = Row; j < PD->size(); j++) {
                           qDebug() << Row << PD->size();
                           PD->replace(j, PD->at(j) + 1);
                       }
                       int new_pos = PD->at(Row) - (Row - i) - 1;
                       VE->insert(new_pos, 0);
                    }

                }
            }

        }
        else
        {
            int new_pos = PD->at(Row) - (Row - Col);
            VE->replace(new_pos - 1, Value);
        }
        qDebug() << *PD;
        qDebug() << *VE;
    }
    // Увеличить значение в массиве PD на единицу в элементе равным Row и далее.
    // После этого необходимо определить значение в массиве VE и вставить в нужную позицию.
}

void Swap(int *Row, int *Col)
{
    if(*Col > *Row)
    {
        int temp = *Row;
        *Row = *Col;
        *Col = temp;
    }
}

int SearchElement(int Row, int Col, QVector<int> *PD, QVector<int> *VE)
{
    if(!PD->isEmpty() && !VE->isEmpty())
    {
        //Swap(&Row, &Col);
        int pos = PD->at(Row) - (Row - Col);
        if(PD->at(Row - 1) < pos)
        {
            return pos;
        }
    }
    return 0;
}

bool check(int Row, int Col, QVector<int> *PD)
{
    int pos = PD->at(Row) - (Row - Col);
    int pos_PD = PD->at(Row - 1);
    //qDebug() << pos << pos_PD;
    if(pos <= pos_PD) return true;
    else return  false;
}

void DelElement(int Row, int Col, QVector<int> *PD, QVector<int> *VE)
{
    Swap(&Row, &Col);
    int pos = SearchElement(Row, Col, PD, VE);
    qDebug() << pos << PD->at(Row - 1) << PD->at(Row);
    if(pos != 0 && VE->at(pos) > 0)
    {
        if(PD->at(Row - 1) == pos - 1 && PD->at(Row) == pos + 1)
        {
            pos = pos - 1;
            qDebug() << pos << "1 усл";
            // Первый и последний, не считая диагональный.
            VE->remove(pos);
            for(int j = Row; j < PD->size(); j++) {
                PD->replace(j, PD->at(j) - 1);
            }
        }

        if(PD->at(Row - 1) < pos - 1 /*&& PD->at(Row) >= pos + 1*/)
        {
            qDebug() << pos << "2 усл";
            // Не первый и не последний, не считая диагональный
            VE->replace(pos, 0);
        }

        if(PD->at(Row - 1) == pos - 1 && PD->at(Row) > pos + 1)
        {
            int i;
            qDebug() << pos << "3 усл";
            // Первый, но не последний, не считая диагональный
            for(i = pos + 1; i < PD->at(Row) ; i++)
            {
                if(VE->at(i) != 0)
                    break;
            }

            for(int j = pos; j < i; j++)
            {
                VE->remove(j);
                for(int j = Row; j < PD->size(); j++) {
                    PD->replace(j, PD->at(j) - 1);
                }
            }
        }

    }
    qDebug() << *VE;
    qDebug() << *PD;
}
/*void OpenFile(int size, int value, QVector<int> *PD, QVector<int> *VE)
{
    int count = 0;
    int value = 1;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(i > j && value != 0)
            {
                VE->append(value);
                count++;
            }
            else if(i == j)
            {
                VE->append(value);
                count++;
                PD->append(count);
            }
        }
    }
    qDebug() << VE;
    qDebug() << PD;
}*/
