#ifndef MoreFunctions_h
#define MoreFunctions_h
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
bool isSolved(int **Matrix, int size)
{
    int i, j, counter;
    counter = 0;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            if(Matrix[i][j] > 0 && Matrix[i][j] != 2048)
            {
                counter++;
            }
        }
    }
    if(counter == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void bubbleSort(vector<string> &line, int size)
{
    for(int i = size - 1; i >= 1; i--)
    {
        for(int j = 1; j <= i; j++)
        {
            if(stof(line[j - 1]) > stof(line[j]))
            {
                swap(line[j], line[j - 1]);
            }
        }
    }
}

void Move(int **Matrix, int size, int num)
{
    if(num == 1)
    {
        MatrixUp(Matrix, size);
        MergeUp(Matrix, size);
    }
    else if(num == 2)
    {
        MatrixRight(Matrix, size);
        MergeRight(Matrix, size);
    }
    else if(num == 3)
    {
        MatrixDown(Matrix, size);
        MergeDown(Matrix, size);
    }
    else if(num == 4)
    {
        MatrixLeft(Matrix, size);
        MergeLeft(Matrix, size);
    }
}
#endif /* MoreFunctions_h */
