#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;

namespace Functions
{
    int tableSize = 0;

    int** generateGraph(int n, double saturation) {
        int** macierz = new int*[n];
        
        int edges = (n * (n - 1) / 2) * (saturation / 100);
        int howMany = 0;
        for (int i = 0; i < n; ++i) {
            macierz[i] = new int[n]; 
            for (int j = i + 1; j < n; ++j) {
                if(howMany < edges)
                {
                    macierz[i][j] = 1;
                    howMany++;

                }
            }
        }
        
        return macierz;
    }
    int** generateGraphMatrix(string *inputMatrix, int size)
    {
        int **matrix = new int*[size];
        string value = "";

        for(int i = 0; i < size; i++)
        {
            matrix[i] = new int[size];

        }

        for(int i = 0; i < size; i++)
        {
            value = "";

            for(int x = 0; x < inputMatrix[i].length(); x++)
            {
                if(inputMatrix[i][x] != ' ')
                {
                    value += inputMatrix[i][x];

                    if(x == inputMatrix[i].length() - 1)
                    {
                        matrix[i][stoi(value)] = 1;

                        value = "";

                    }
                }
                else
                {
                    matrix[i][stoi(value)] = 1;

                    cout<<value<<endl;

                    value = "";

                }

            }

        }

        return matrix;
    }
    int** generateGraphTable(string *inputTable, int size)
    {
        tableSize = 0;

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < inputTable[i].length(); j++)
            {
                if(inputTable[i][j] == ' ' || j == inputTable[i].length() - 1)
                    tableSize++;

            }
        }

        int **table = new int*[tableSize];
        string inputValue = "";
        string value = "";
        int it = 0;

        for(int i = 0; i < tableSize; i++)
        {
            table[i] = new int[2];

        }

        cout<<"tableSize: "<<tableSize<<endl;

        for(int i = 0; i < size; i++)
        {
            value = "";

            for(int x = 0; x < inputTable[i].length(); x++)
            {
                if(inputTable[i][x] != ' ')
                {
                    value += inputTable[i][x];

                    if(x == inputTable[i].length() - 1)
                    {
                        table[it][0] = i;
                        table[it][1] = stoi(value);

                        it++;

                        cout<<"it: "<<it<<endl;

                        value = "";

                    }

                }
                else
                {
                    table[it][0] = i;
                    table[it][1] = stoi(value);

                    value = "";
                    it++;

                    cout<<"it: "<<it<<endl;
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

                    if(x == inputList[i].length() - 1)
                    {
                        list[i][it] = stoi(value);

                        value = "";

                    }

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
    int** convertMatrixToTable(int **graph, int size)
    {
        int edgesNum = 0;

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(graph[i][j] == 1)
                    edgesNum++;

            }

        }

        int **table = new int*[edgesNum];
        int it = 0;

        for(int j = 0; j < edgesNum; j++)
        {
            table[j] = new int[2];

        }

        tableSize = edgesNum;

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(graph[i][j] == 1)
                {
                    cout<<it<<endl;

                    table[it][0] = i;
                    table[it][1] = j;

                    cout<<i<<i<<endl;

                    it++;
                }


            }

        }

        return table;
    }
    int** convertMatrixToList(int **graph, int size)
    {
        int **list = new int*[size];

        for(int i = 0; i < size; i++)
        {
            list[i] = new int[size];

            fill_n(list[i], size, -1);

        }

        for(int i = 0; i < size; i++)
        {
            int it = 0;

            for(int j = 0; j < size; j++)
            {
                if(graph[i][j] == 1)
                {
                    list[i][it] = j;
                    it++;
                }

            }

        }

        return list;
    }
    void printMatrix(int **matrix, int size)
    {
        cout<<" "<<" |";

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

        for(int i = 0; i < tableSize; i++)
        {
            cout<<"[ ";

            for(int j = 0; j < 2; j++)
            {
                cout<<table[i][j];

                if(j < 1)
                    cout<<" ,";

            }

            cout<<" ]";

            if(i < size - 1)
                cout<<" ,";

        }

        cout<<endl;

    }
    void printList(int **list, int size)
    {

        for(int i = 0; i < size; i++)
        {
            cout<<i<<" | ";

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
        bool isInSet = from >= 0 && from <= size && to >= 0 && to <= size;

        if(isInSet)
        {
            if(matrix[from][to] == 1)
                return true;

        }

        return false;
    }
    bool findEdgeInTable(int **table, int size, int from, int to)
    {
        bool isInSet = from >= 0 && from <= size && to >= 0 && to <= size;

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
        bool isInSet = from >= 0 && from <= size && to >= 0 && to <= size;

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
    void bfsMatrix(int** matrix, int size, int start) 
    {
        bool *visited = new bool[size]; 
        for (int i = 0; i < size; i++)
        {
            visited[i] = false;
        }

        queue<int> q;

        visited[start] = true;
        q.push(start);

        int vertex = 0;

        while (!q.empty()) {
            vertex = q.front();
            q.pop();
            cout << vertex << " ";

            for (int neighbor = 0; neighbor < size; ++neighbor) 
            {
                if (matrix[vertex][neighbor] == 1 && !visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        delete[] visited;

    }
    void bfsTable(int **table, int size, int start)
    {
        bool *visited = new bool[size];

        for(int i = 0; i < size; i++)
        {
            visited[i] = false;

        }

        queue<int> q;

        visited[start] = true;
        q.push(start);

        int vertex = 0;

        while(!q.empty())
        {
            vertex = q.front();

            q.pop();

            cout<<vertex<<" ";

            for (int i = 0; i < 2; ++i) {
                int neighbor = table[vertex][i];
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }

        }

        delete[] visited;

    }
    void bfsList(int **list, int size, int start)
    {
        bool *visited = new bool[size];

        for(int i = 0; i < size; i++)
        {
            visited[i] = false;

        }

        queue<int> q;

        visited[start] = true;
        q.push(start);

        int vertex = 0;

        while(!q.empty())
        {
            vertex = q.front();

            q.pop();

            cout<<vertex<<" ";

            for (int i = 0; i < size; ++i) {
                int successor = list[vertex][i];
                if (!visited[successor] && list[vertex][i] != -1) 
                {
                    visited[successor] = true;
                    q.push(successor);
                }

            }

        }

        delete[] visited;

    }
    void dfsMatrix(int **matrix, int vertex, vector<bool>& visited, int size) 
    {
        visited[vertex] = true;
        cout << vertex << " "; 

        for (int neighbor = 0; neighbor < size; neighbor++) 
        {
            if (matrix[vertex][neighbor] == 1 && !visited[neighbor])
                dfsMatrix(matrix, neighbor, visited, size);
            
        }

    }
    void dfsTraversalMatrix(int **matrix, int size) 
    {
        int numVertices = size;

        vector<bool> visited(numVertices, false);

        cout << "DFS traversal: ";
        for (int i = 0; i < numVertices; ++i) 
        {
            if (!visited[i])
                dfsMatrix(matrix, i, visited, size);
            
        }
    }
    void dfsTable(int **table, int vertex, vector<bool>& visited, int size) 
    {
        visited[vertex] = true;
        cout << vertex << " "; 

        for (int i = 0; i < 2; i++) 
        {
            int neighbor = table[vertex][i];

            if(!visited[neighbor])
                dfsTable(table, neighbor, visited, size);

        }
            
    }
    void dfsTraversalTable(int **table, int size) 
    {
        int numVertices = size;

        vector<bool> visited(numVertices, false);

        cout << "DFS traversal: ";
        for (int i = 0; i < numVertices; ++i) {
            if (!visited[i])
                dfsTable(table, i, visited, size);
            
        }
    }
    void dfsList(int **list, int vertex, vector<bool>& visited, int size) 
    {
        visited[vertex] = true;
        cout << vertex << " "; 

        for (int i = 0; i < size; i++) 
        {
            int s = list[vertex][i];

            if(!visited[s] && list[vertex][i] != -1)
                dfsList(list, s, visited, size);

        }
    }
    void dfsTraversalList(int **list, int size) 
    {
        int numVertices = size;

        vector<bool> visited(numVertices, false);

        for (int i = 0; i < numVertices; ++i) 
        {
            if (!visited[i]) 
                dfsList(list, i, visited, size);
            
        }

    }
    vector<int> topologicalSortKhanMatrix(int **matrix, int size) 
    {
        int numVertices = size;
        vector<int> sortedOrder; 

        vector<int> inDegree(numVertices, 0);

        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (matrix[i][j] == 1)
                    inDegree[j]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numVertices; ++i) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            sortedOrder.push_back(vertex);

            for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
                if (matrix[vertex][neighbor] == 1) {
                    inDegree[neighbor]--;
                    if (inDegree[neighbor] == 0)
                        q.push(neighbor);
                }
            }
        }

        if (sortedOrder.size() != numVertices) {
            sortedOrder.clear();
        }

        return sortedOrder;
    }
    vector<int> topologicalSortKhanTable(int **table, int numVertices) 
    {
        vector<int> sortedOrder;

        vector<int> inDegree(numVertices, 0);

        for (int i = 0; i < numVertices; ++i) 
        {
            for(int j = 0; j < 2; j++)
            {
                inDegree[table[i][j]]++;

            }

        }

        queue<int> q;
        for (int i = 0; i < numVertices; ++i) 
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            sortedOrder.push_back(vertex);

            for(int i = 0; i < 2; i++)
            {
                inDegree[table[vertex][i]]--;
                if(inDegree[table[vertex][i]] == 0)
                    q.push(table[vertex][i]);
            }

        }

        if (sortedOrder.size() != numVertices) 
            sortedOrder.clear();

        return sortedOrder; 
    }
    vector<int> topologicalSortKhanList(int **list, int numVertices) 
    {
        vector<int> sortedOrder;

        vector<int> inDegree(numVertices, 0); 

        for (int i = 0; i < numVertices; ++i) {
            for(int j = 0; j < numVertices; j++)
            {
                if(list[i][j] != -1)
                    inDegree[list[i][j]]++;

            }
            
        }

        queue<int> q;
        for (int i = 0; i < numVertices; ++i) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            sortedOrder.push_back(vertex);

            for(int i = 0; i < numVertices; i++)
            {
                if(list[vertex][i] != -1)
                {
                    inDegree[list[vertex][i]]--;

                    if(inDegree[list[vertex][i]] == 0)
                        q.push(list[vertex][i]);

                }

            }
        }

        if (sortedOrder.size() != numVertices) 
            sortedOrder.clear();

        return sortedOrder;
    }
    void tarjansSCCMatrix(int u, int** graph, vector<int>& low, vector<int>& disc, stack<int>& st, vector<bool>& stackMember, vector<vector<int>>& SCCs, int& time, int size) 
    {
        disc[u] = low[u] = ++time;
        st.push(u);
        stackMember[u] = true;

        for (int v = 0; v < size; ++v) {
            if (graph[u][v] == 1) {
                if (disc[v] == -1) {
                    tarjansSCCMatrix(v, graph, low, disc, st, stackMember, SCCs, time, size);
                    low[u] = min(low[u], low[v]);
                } else if (stackMember[v]) {
                    low[u] = min(low[u], disc[v]);
                }
            }
        }

        if (low[u] == disc[u]) {
            vector<int> SCC;
            int v;
            do {
                v = st.top();
                st.pop();
                stackMember[v] = false;
                SCC.push_back(v);
            } while (v != u);
            SCCs.push_back(SCC);
        }
    }
    vector<vector<int>> tarjansAlgorithmMatrix(int** graph, int size) 
    {
        int numVertices = size;
        vector<int> low(numVertices, -1);
        vector<int> disc(numVertices, -1);
        vector<bool> stackMember(numVertices, false);
        stack<int> st;
        vector<vector<int>> SCCs;
        int time = 0;

        for (int u = 0; u < numVertices; ++u) {
            if (disc[u] == -1) {
                tarjansSCCMatrix(u, graph, low, disc, st, stackMember, SCCs, time, size);
            }
        }

        return SCCs;
    }
    void tarjansSCCTable(int u, int** table, vector<int>& low, vector<int>& disc, stack<int>& st, vector<bool>& stackMember, vector<vector<int>>& SCCs, int& time) 
    {
        disc[u] = low[u] = ++time;
        st.push(u);
        stackMember[u] = true;

        for(int i = 0; i < 2; i++)
        {
            if(disc[table[u][i]] == -1)
            {
                tarjansSCCTable(table[u][i], table, low, disc, st, stackMember, SCCs, time);
                low[u] = min(low[u], low[table[u][i]]);
            }
            else if(stackMember[table[u][i]])
                low[u] = min(low[u], disc[table[u][i]]);

        }

        if (low[u] == disc[u]) {
            vector<int> SCC;
            int v;
            do {
                v = st.top();
                st.pop();
                stackMember[v] = false;
                SCC.push_back(v);
            } while (v != u);
            SCCs.push_back(SCC);
        }
    }
    vector<vector<int>> tarjansAlgorithmTable(int** table, int numVertices) 
    {
        vector<int> low(numVertices, -1);
        vector<int> disc(numVertices, -1);
        vector<bool> stackMember(numVertices, false);
        stack<int> st;
        vector<vector<int>> SCCs;
        int time = 0;

        for (int u = 0; u < numVertices; ++u) {
            if (disc[u] == -1) {
                tarjansSCCTable(u, table, low, disc, st, stackMember, SCCs, time);
            }
        }

        return SCCs;
    }
    vector<int> reverseVector(vector<vector<int>>& result)
    {
        stack<int> helper;
        vector<int>::iterator it;
        vector<int> reversedVector;
        int top = 0;

        for(int i = 0; i < result.size(); i++)
        {
            for(int j = 0; j < result[i].size(); j++)
            {
                helper.push(result[i][j]);

            }

        }

        for(int i = 0; i < result.size(); i++)
        {
            for(int j = 0; j < result[i].size(); j++)
            {
                top = helper.top();

                reversedVector.push_back(top);

                helper.pop();
            }

        }

        return reversedVector;
    }
    void tarjansSCCList(int u, int **list, vector<int>& low, vector<int>& disc, stack<int>& st, vector<bool>& stackMember, vector<vector<int>>& SCCs, int& time, int size) 
    {
        disc[u] = low[u] = ++time;
        st.push(u);
        stackMember[u] = true;

        for(int i = 0; i < size; i++)
        {
            if(list[u][i] != -1)
            {

                if(disc[list[u][i]])
                {
                    tarjansSCCList(list[u][i], list, low, disc, st, stackMember, SCCs, time, size);
                    low[u] = min(low[u], low[list[u][i]]);
                }
                else if(stackMember[list[u][i]])
                    low[u] = min(low[u], disc[list[i][u]]);

            }

        }

        if (low[u] == disc[u]) {
            vector<int> SCC;
            int v;
            do {
                v = st.top();
                st.pop();
                stackMember[v] = false;
                SCC.push_back(v);
            } while (v != u);
            SCCs.push_back(SCC);
        }
    }
    vector<vector<int>> tarjansAlgorithmList(int **list, int numVertices) 
    {
        vector<int> low(numVertices, -1);
        vector<int> disc(numVertices, -1);
        vector<bool> stackMember(numVertices, false);
        stack<int> st;
        vector<vector<int>> SCCs;
        int time = 0;

        for (int u = 0; u < numVertices; ++u) {
            if (disc[u] == -1) {
                tarjansSCCList(u, list, low, disc, st, stackMember, SCCs, time, numVertices);
            }
        }

        return SCCs;
    }

};