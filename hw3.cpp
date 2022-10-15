#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Up.h"
#include "Down.h"
#include "Right.h"
#include "Left.h"
#include "MoreFunctions.h"
//#include "time.h"
#include "ArgumentManager.h"
using namespace std;
int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        return -1;
    }
      
    ArgumentManager am(argc, argv);
    string infilename = am.get("input");
    string outfilename = am.get("output");
    //clock_t start = clock();
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open(infilename);
    outputFile.open(outfilename);
    
    //inputFile.open("/Users/saiprashanthharihar/Desktop/input32.txt");
    //outputFile.open("/Users/saiprashanthharihar/Desktop/hw3Output.txt");
    
    string line;
    getline(inputFile, line);
    istringstream numbers(line);
    int i, j, k, N;
    numbers >> N;
    int **Matrix = new int*[N];
    int **OriginalMatrix = new int*[N];
    for(i = 0; i < N; i++)
    {
        Matrix[i] = new int[N];
        OriginalMatrix[i] = new int[N];
    }
    line = "";
    while(!inputFile.eof())
    {
        for(i = 0; i < N; i++)
        {
            getline(inputFile, line);
            istringstream MatrixElm(line);
            for(j = 0; j < N; j++)
            {
                MatrixElm >> Matrix[i][j];
                line = "";
            }
        }
    }
    
    // Transfer Elements
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            OriginalMatrix[i][j] = Matrix[i][j];
        }
    }
    
    
    //Test
    cout << "Original Matrix:" << endl;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            cout << OriginalMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    // Testing
    
    /* MatrixLeft(Matrix, N);
    MergeLeft(Matrix, N);
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl; */
    
    // Testing
    vector<string> outputString;
    vector<int> V;
    string output;
    
    if(isSolved(Matrix, N))
    {
        cout << "0" << endl;
        outputFile << "0";
        return 0;
    }
    else
    {
        for(i = 1; i < 5; i++)
        {
            V.push_back(i);
        }
        for(i = 1; i < 5; i++)
        {
            V.push_back(i);
        }
        while(next_permutation(V.begin(), V.end()))
        {
            i = 0;
            while(i < 8 && isSolved(Matrix, N) == 0)
            {
                Move(Matrix, N, V[i]);
                i++;
            }
            if(isSolved(Matrix, N) == 1)
            {
                for(k = 0; k < i; k++)
                {
                    //cout << V[k];
                    output.push_back(V[k] + 48);
                }
                //cout << endl;
                outputString.push_back(output);
                output = "";
                
                for(i = 0; i < N; i++)
                {
                    for(j = 0; j < N; j++)
                    {
                        Matrix[i][j] = OriginalMatrix[i][j];
                    }
                }
            }
            else
            {
                for(i = 0; i < N; i++)
                {
                    for(j = 0; j < N; j++)
                    {
                        Matrix[i][j] = OriginalMatrix[i][j];
                    }
                }
            }
        }
    }
    
    bubbleSort(outputString, (int) outputString.size());
    /* for(int l = 0; l < outputString.size(); l++)
    {
        cout << outputString[l] << endl;
    } */
    if(outputString.size() == 0)
    {
        cout << "Impossible";
        outputFile << "Impossible";
    }
    else if(outputString.size() > 0)
    {
        cout << outputString[0];
        outputFile << outputString[0];
    }
    //clock_t end = clock();
    //double cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
    //cout << endl << "Time: " << cpu_time_used << " seconds" << endl;
    for(i = 0; i < N; i++)
    {
        delete [] Matrix[i];
    }
    delete [] Matrix;
    inputFile.close();
    outputFile.close();
}
