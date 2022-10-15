#ifndef Down_h
#define Down_h
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
void MatrixDown(int **Matrix, int size)
{
    int i, j, k;
    stack<int> myStack;
    for(j = 0; j < size; j++)
    {
        for(i = 0; i < size; i++)
        {
            // if(Matrix[i][j] != 0)
            if(Matrix[i][j] != 0 && Matrix[i][j] != 2048)
            {
                myStack.push(Matrix[i][j]);
            }
        }
        for(k = 0; k < size; k++)
        {
            if(Matrix[k][j] == 2048)
            {
                break;
            }
        } // Updated
        for(i = (k - 1); i >= 0; i--)
        {
            if(Matrix[i][j] == 2048)
            {
                continue;
            } // updated
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

void MergeDown(int **Matrix, int size)
{
    int i, j, k;
    for(i = (size - 1); i > 0; i--)
    {
        for(j = 0; j < size; j++)
        {
            if(Matrix[i][j] != 0 && Matrix[i - 1][j] != 0)
            {
                if(Matrix[i][j] == Matrix[i - 1][j] && Matrix[i][j] != 2048) // Updated
                {
                    Matrix[i][j] *= 2;
                    for(k = (i - 1); k > 1; k--)
                    {
                        if(Matrix[k - 1][j] == 2048)
                        {
                            Matrix[k][j] = 0;
                            break;
                        } // Updated
                        else
                        {
                            Matrix[k][j] = Matrix[k - 1][j];
                        }
                    }
                    if(k - 1 == 0)
                    {
                        Matrix[k - 1][j] = 0;
                    }
                }
            }
        }
    }
}
#endif /* Down_h */
