#include <iostream>
#include "../include/functions.cpp"
#include <cstring>

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

            if(strcmp(argv[1], "--generate") == 0) 
            {
                int *n;
                int *nodes;
                string insert;

                cout<<endl;

                cout<<"node>";
                cin>>numberOfNodes;

                cout<<endl;

                cout<<"saturation>";
                cin>>saturation;

                graph = generateGraph(numberOfNodes, saturation);

                type = "matrix";

            }
            else if(strcmp(argv[1], "--user-provided") == 0)
            {
                int *n;
                int *nodes;
                string insert;
                string *inputMatrix;

                cout<<"type>";
                cin>>type;

                cout<<"node>";
                cin>>numberOfNodes;

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
                {
                   cout<<"test"<<endl; 
                   graph = generateGraphMatrix(inputMatrix, numberOfNodes);

                }
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
                if(command == "Remove")
                {

                }
                if(command == "Delete")
                {

                }
                if(command == "FindMinMax")
                {
                    
                }
                if(command == "Export")
                {

                }                
                if(command == "Rebalance")
                {
                    
                }
                if(command == "Exit")
                    return 0;

            }
            
    return 0;
}