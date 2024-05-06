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

        for(int x = 0; x < nodes; x++)
        {
            for(int y = 0; y < nodes; y++)
            {
                graph[x][y] = 0;

            }

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
    int** generateGraphMatrix(string *inputMatrix, int size)
    {
        int **matrix = new int*[size];
        string value = "";

        for(int i = 0; i < size; i++)
        {
            value = "";

            matrix[i] = new int[size];

            for(int x = 0; x < inputMatrix[i].length(); x++)
            {
                if(inputMatrix[i][x] != ' ')
                {
                    value += inputMatrix[i][x];

                }
                else
                {
                    matrix[i][stoi(value)] = 1;

                    value = "";

                }

            }

        }

        return matrix;
    }
    int** generateGraphTable(string *inputTable, int nodes, int size)
    {
        int **table = new int*[size];
        string inputValue = "";
        string value = "";
        int it = 0;

        for(int i = 0; i < size; i++)
        {
            table[i] = new int[2];

        }

        for(int i = 0; i < nodes; i++)
        {
            value = "";

            for(int x = 0; x < inputTable[i].length(); x++)
            {
                if(inputTable[i][x] != ' ')
                {
                    value += inputTable[i][x];

                }
                else
                {
                    table[it][0] = i;
                    table[it][1] = stoi(value);

                    value = "";
                    it++;
                }

            }

        }

        return table;

    }
    int **generateGraphList(string *inputList, int size)
    {
        int **list = new int*[size];
        string inputValue = "";
        string value = "";
        int sizeVector = 0;
        int it = 0;

        for(int i = 0; i < size; i++)
        {
            list[i] = new int[size];

            fill_n(list[i], size, -1);

        }

        for(int i = 0; i < size; i++)
        {
            it = 0;
            value = "";

            for(int x = 0; x < inputList[i].length(); x++)
            {
                if(inputList[i][x] != ' ')
                {
                    value += inputList[i][x];

                }
                else
                {
                    list[i][it] = stoi(value);

                    value = "";
                    it++;

                }

            }

        }

        return list;
    }
    void printMatrix(int **matrix, int size)
    {
        cout<<" "<<"|";

        for(int i = 0; i < size; i++)
        {
            cout<<i<<" ";

        }

        cout<<endl;

        cout<<"--"<<"+";

        for(int i = 0; i < 2 * size; i++)
        {
            cout<<"-";

        }

        cout<<endl;

        for(int x = 0; x < size; x++)
        {
            cout<<x<<" "<<"|";

            for(int y = 0; y < size; y++)
            {
                cout<<matrix[x][y]<<" ";

            }

            cout<<endl;

        }

    }
    void printTable(int **table, int size)
    {
        cout<<"[ ";

        for(int i = 0; i < size; i++)
        {
            cout<<"[ ";

            for(int j = 0; j < 2; j++)
            {
                cout<<table[i][j];

                if(j < 1)
                    cout<<" ,";

            }

            cout<<" ]";

        }

        cout<<endl;

    }
    void printList(int **list, int size)
    {

        for(int i = 0; i < size; i++)
        {
            cout<<i<<" ";

            for(int j = 0; j < size; j++)
            {
                if(list[i][j] != -1)
                    cout<<list[i][j]<<" ";

            }

            cout<<endl;

        }

    }
    bool findEdgeInMatrix(int **matrix, int size, int from, int to)
    {
        bool isInSet = from > 0 && from <= size && to > 0 && to <= size;

        if(isInSet)
        {
            if(matrix[from][to] == 1)
                return true;

        }

        return false;
    }
    bool findEdgeInTable(int **table, int size, int from, int to)
    {
        bool isInSet = from > 0 && from <= size && to > 0 && to <= size;

        if(isInSet)
        {
            for(int i = 0; i < size; i++)
            {
                if(table[i][0] == from && table[i][1] == to)
                    return true;

            }

        }

        return false;
    }
    bool findEdgeInList(int **list, int size, int from, int to)
    {
        bool isInSet = from > 0 && from <= size && to > 0 && to <= size;

        if(isInSet)
        {
            for(int j = 0; j < size; j++)
            {
                    if(list[from][j] == to)
                        return true;

            }

        }

        return false;
    }

};