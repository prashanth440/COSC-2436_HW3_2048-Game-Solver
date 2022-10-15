#ifndef Right_h
#define Right_h
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
void MatrixRight(int **Matrix, int size)
{
    int i, j, k;
    stack<int> myStack;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            // if(Matrix[i][j] != 0)
            if(Matrix[i][j] != 0 && Matrix[i][j] != 2048)
            {
                myStack.push(Matrix[i][j]);
            }
        }
        for(k = 0; k < size; k++)
        {
            if(Matrix[i][k] == 2048)
            {
                break;
            }
        } // Updated
        for(j = (k - 1); j >= 0; j--)
        {
            if(Matrix[i][j] == 2048)
            {
                continue;
            } // Updated
            else if(!myStack.empty())
            {
                Matrix[i][j] = myStack.top();
                myStack.pop();
            }
            else
            {
                Matrix[i][j] = 0;
            }
        }
        while(!myStack.empty())
        {
            myStack.pop();
        }
    }
}

void MergeRight(int **Matrix, int size)
{
    int i, j, k;
    for(j = (size - 1); j > 0; j--)
    {
        for(i = 0; i < size; i++)
        {
            if(Matrix[i][j] != 0 && Matrix[i][j - 1] != 0)
            {
                if(Matrix[i][j] == Matrix[i][j - 1] && Matrix[i][j] != 2048) // Updated
                {
                    Matrix[i][j] *= 2;
                    for(k = (j - 1); k > 0; k--)
                    {
                        if(Matrix[i][k - 1] == 2048)
                        {
                            Matrix[i][k] = 0;
                            break;
                        } // Updated
                        else
                        {
                            Matrix[i][k] = Matrix[i][k - 1];
                        }
                    }
                    if(k == 0)
                    {
                        Matrix[i][k] = 0;
                    }
                }
            }
        }
    }
}
#endif /* Right_h */
