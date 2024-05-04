#include <iostream>
#include <vector>
#include <random>

using namespace std;

namespace Functions
{
    int** generateGraph(int nodes, double saturation)
    {
        int **graph = new int*[nodes];
        int numEdges = (nodes - 1) + (nodes * (nodes - 1) / 2) * saturation;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(0, nodes - 1);
        int x = 0;
        int y = 0;
        int u = -1;
        int w = -1;
        int numEdgesE = 0;

        for(int i = 0; i < nodes; i++)
        {
            graph[i] = new int[nodes];

        }

        std::vector<int> parent(nodes, -1);
        std::vector<bool> inMST(nodes, false);
        std::vector<double> weight(nodes, std::numeric_limits<double>::max());
        weight[0] = 0;

        for(int i = 0; i < nodes - 1; i++) 
        {
            u = -1;

            for(int v = 0; v < nodes; v++) 
            {
                if(!inMST[v] && (u == -1 || weight[v] < weight[u])) 
                    u = v;
                
            }
            inMST[u] = true;
            for(int v = 0; v < nodes; v++) 
            {
                if(!inMST[v] && dist(gen) < saturation)
                {
                    w = dist(gen) * 10;

                    if(w < weight[v]) 
                    {
                        parent[v] = u;
                        weight[v] = w;
                    }
                }
            }
 
            for(int i = 1; i < nodes; ++i) 
            {
                graph[parent[i]][i] = 1;
                graph[i][parent[i]] = 1;
            }

        }

        numEdgesE = numEdges - (nodes  - 1);

        for(int j = 0; j < numEdgesE; j++)
        {
            x = dist(gen);
            y = dist(gen);

            if(x != y && graph[x][y] != 0)
            {
                graph[x][y] = 1;

            }

        }

        return graph;

    }
    int** generateGraph(string *inputMatrix, int size, int key)
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