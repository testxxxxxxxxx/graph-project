#include <iostream>
#include "../include/functions.cpp"
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;
using namespace Functions;

int main(int argc, char *argv[])
{
    if(!argv[1])
    {
        cout<<"Error"<<endl;

        return 0;
    }

    int numberOfNodes = 0;
    int saturation = 0;
    string type = "";
    int** graph;
    string path = "";
    string name = "";
    string dir = path + name;

    fstream benchmarkResult;

    benchmarkResult.open(dir, ios::out | ios::app);

            if(strcmp(argv[1], "--generate") == 0) 
            {
                int *n;
                int *nodes;
                string insert;

                cout<<"type>";
                cin>>type;

                if(type != "matrix" && type != "table" && type != "list")
                {
                    cout<<"Error"<<endl;

                    return 0;
                }

                cout<<endl;

                cout<<"node>";
                cin>>numberOfNodes;

                if(numberOfNodes <= 0)
                {
                    cout<<"Error"<<endl;

                    return 0;
                }

                cout<<endl;

                cout<<"saturation>";
                cin>>saturation;

                if(saturation <= 0)
                {
                    cout<<"Error"<<endl;

                    return 0;
                }

                graph = generateGraph(numberOfNodes, saturation);

                if(type == "table")
                    graph = convertMatrixToTable(graph, numberOfNodes);
                else if(type == "list")
                    graph = convertMatrixToList(graph, numberOfNodes);

            }
            else if(strcmp(argv[1], "--user-provided") == 0)
            {
                int *n;
                int *nodes;
                string insert;
                string *inputMatrix;

                cout<<"type>";
                cin>>type;

                if(type != "matrix" && type != "table" && type != "list")
                {
                    cout<<"Error"<<endl;

                    return 0;
                }

                cout<<"node>";
                cin>>numberOfNodes;

                if(numberOfNodes <= 0)
                {
                    cout<<"Error"<<endl;

                    return 0;
                }

                cout<<numberOfNodes<<endl;

                nodes = new int[numberOfNodes];

                n = nodes;

                inputMatrix = new string[numberOfNodes];

                string value = "";
                int it = -1;

                for(int x = 0; x < numberOfNodes; x++)
                {
                    cout<<endl;

                    cout<<x<<">";
                    getline(cin >> ws, insert);

                    inputMatrix[x] = insert;

                }

                for(int i = 0; i < numberOfNodes; i++)
                {
                    cout<<"i: "<<inputMatrix[i]<<endl;

                }

                if(type == "matrix") 
                   graph = generateGraphMatrix(inputMatrix, numberOfNodes);
                else if(type == "table")
                    graph = generateGraphTable(inputMatrix, numberOfNodes);
                else if(type == "list")
                    graph = generateGraphList(inputMatrix, numberOfNodes);

                cout<<endl;

            }
            else
            {
                cout<<"Error"<<endl;

                return 0;
            }

            string action = "action";
            string command = "";

            while(true)
            {
                cout<<action<<">";
                cin>>command;

                if(command == "Help")
                {
                    cout<<"Help"<<"                     "<<"Show this message"<<endl;
                    cout<<"FindMinMax"<<"                     "<<"Find min max"<<endl;
                    cout<<"Print"<<"                     "<<"print tree inorder, postorder, preorder"<<endl;
                    cout<<"Remove"<<"                     "<<"Remove element from tree"<<endl;
                    cout<<"Delete"<<"                     "<<"Delete whole tree"<<endl;
                    cout<<"Export"<<"                     "<<"Export tzpicture"<<endl;
                    cout<<"Rebalance"<<"                     "<<"Rebalance tree"<<endl;
                    cout<<"Exit"<<"                     "<<"Exit"<<endl;

                }
                if(command == "Print")
                {
                    if(type == "matrix")
                        printMatrix(graph, numberOfNodes);
                    else if(type == "table")
                        printTable(graph, numberOfNodes);
                    else if(type == "list")
                        printList(graph, numberOfNodes);

                }
                if(command == "BFS")
                {
                    if(type == "matrix")
                        bfsMatrix(graph, numberOfNodes, 0);
                    if(type == "table")
                        bfsTable(graph, numberOfNodes, 0);
                    if(type == "list")
                        bfsList(graph, numberOfNodes, 0);

                }
                if(command == "DFS")
                {
                    if(type == "matrix")
                        dfsTraversalMatrix(graph, numberOfNodes);
                    else if(type == "table")
                        dfsTraversalTable(graph, numberOfNodes);
                    else if(type == "list")
                        dfsTraversalList(graph, numberOfNodes);

                }
                if(command == "Find")
                {
                    int from = 0;
                    int to = 0;

                    cout<<"from>";
                    cin>>from;

                    cout<<endl;

                    cout<<"to>";
                    cin>>to;

                    cout<<endl;

                    if(type == "matrix" && findEdgeInMatrix(graph, numberOfNodes, from, to))
                        cout<<"True: edge("<<from<<","<<to<<")"<<" exists in the Graph"<<endl;
                    else if(type == "matrix")
                        cout<<"False: edge("<<from<<","<<to<<")"<<" does not exists in the Graph"<<endl;

                    
                    if(type == "table" && findEdgeInTable(graph, tableSize, from, to))
                        cout<<"True: edge("<<from<<","<<to<<")"<<" exists in the Graph"<<endl;
                    else if(type == "table")
                        cout<<"False: edge("<<from<<","<<to<<")"<<" does not exists in the Graph"<<endl;

                    auto startEdge = chrono::high_resolution_clock::now();
                    
                    if(type == "list" && findEdgeInList(graph, numberOfNodes, from, to))
                        cout<<"True: edge("<<from<<","<<to<<")"<<" exists in the Graph"<<endl;
                    else if(type == "list")
                        cout<<"False: edge("<<from<<","<<to<<")"<<" does not exists in the Graph"<<endl;

                    auto stopEdge = chrono::high_resolution_clock::now();

                    auto timeEdge = chrono::duration_cast<chrono::milliseconds>(stopEdge - startEdge);

                    benchmarkResult<<"Find,"<<to_string(numberOfNodes)+","<<to_string(timeEdge.count())<<endl;
                    
                }
                if(command == "Khan")
                {

                    if(type == "matrix")
                    {

                        vector<int> result = topologicalSortKhanMatrix(graph, numberOfNodes);   

                        for(int& i : result)
                        {
                            cout<<i<<" ";

                        }

                    }
                    if(type == "table")
                    {
                        vector<int> result = topologicalSortKhanTable(graph, tableSize);

                        for(int& i : result)
                        {
                            cout<<i<<" ";

                        }

                    }
                    if(type == "list")
                    {
                        auto startKhan = chrono::high_resolution_clock::now();

                        vector<int> result = topologicalSortKhanList(graph, numberOfNodes);

                        auto stopKhan = chrono::high_resolution_clock::now();

                        auto timeKhan = chrono::duration_cast<chrono::milliseconds>(stopKhan - startKhan);

                        benchmarkResult<<"Khan,"<<to_string(numberOfNodes)+","<<to_string(timeKhan.count())<<endl;

                        for(int& i : result)
                        {
                            cout<<i<<" ";

                        }

                    }

                    cout<<endl;
                }                
                if(command == "Tarjan")
                {
                    if(type == "matrix")
                    {

                        vector<vector<int>> result = tarjansAlgorithmMatrix(graph, numberOfNodes);

                        vector<int> reversed = reverseVector(result);

                        for(int& i : reversed)
                        {
                            cout<<i<<" ";

                        }

                    }
                    else if(type == "table")
                    {
                        vector<vector<int>> result = tarjansAlgorithmTable(graph, numberOfNodes);

                        vector<int> reversed = reverseVector(result);

                        for(int& i : reversed)
                        {
                            cout<<i<<" ";

                        }

                    }
                    else if(type == "list")
                    {
                        auto startTarjan = chrono::high_resolution_clock::now();

                        vector<vector<int>> result = tarjansAlgorithmList(graph, numberOfNodes);

                        vector<int> reversed = reverseVector(result);

                        auto stopTarjan = chrono::high_resolution_clock::now();

                        auto timeTarjan = chrono::duration_cast<chrono::milliseconds>(stopTarjan - startTarjan);

                        benchmarkResult<<"Tarjan,"<<to_string(numberOfNodes)+","<<to_string(timeTarjan.count())<<endl;

                        for(int& i : reversed)
                        {
                            cout<<i<<" ";

                        }

                        cout<<endl;

                    }
                    
                }
                if(command == "Exit")
                    return 0;

            }
            
    return 0;
}