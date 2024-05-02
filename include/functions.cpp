#include <iostream>

using namespace std;

namespace Functions
{
    void generateGraph(int **matrix, int nodes, int saturation)
    {
        

    }
    int** generateGraph(string *inputMatrix, int size, int key, int value)
    {
        int **matrix = new int*[size];
        string inputValue = "";
        string value = "";
        int it = 0;

        for(int i = 0; i < size; i++)
        {
            inputValue = inputMatrix[i];;
            int sizeVector = 0;
            it = 0;
            value = "";

            for(int j = 0; j < inputMatrix[i].length(); j++)
            {
                if(inputMatrix[i][j] == ' ')
                    sizeVector++;

            }

            matrix[i] = new int[sizeVector];

            for(int x = 0; x < inputMatrix[i].length(); x++)
            {
                if(inputMatrix[i][x] != ' ')
                {
                    value += inputMatrix[i][x];

                }
                else
                {
                    matrix[i][it] = stoi(value);

                    value = "";

                    it++;
                }

            }

        }

        return matrix;
    }

};