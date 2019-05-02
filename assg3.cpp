#include<iostream>
using namespace std;
 
class Node
{
    private:
        int num;
        Node* next;
    public:
        Node()
        {
            next = NULL;
        }
        friend class Dijkstras;
         
};
class Dijkstras
{
private:
    int visited[20]; 
    int dist[20]; 
   
    int nodes; 
    int edges; 
    int adjacency[20][20]; 
    Node* q_front;
    Node* q_rear;
public:
    Dijkstras() 
    {
        for(int i = 0; i<20; i++)
        {
            visited[i] = 0;
            dist[i] = 1000;
        }
         
        for(int i = 0; i<20; i++)
            for(int j= 0; j<20; j++)
                adjacency[i][j] = 0; 
 
 
        q_front = NULL;
        q_rear = NULL;
    }
 
void enter(); 
void print(); 
void enq(int n); 
int deq_min(); 
bool qempty(); 
Node* create_qnode(int n);
};
 
 
 
 
void Dijkstras::print()
{
dist[0] = 0; 
int min;
    for(int k = 0; k<nodes; k++) 
    {
 
        for(int i = 0; i < nodes; i++) 
         if(dist[i] <= dist[min] && visited[i] != 1)
                min = i;  
        visited[min] = 1; 
         
 
        for(int i = 0; i<nodes; i++)
        {
            if(adjacency[min][i] != 0)  
            {
                if(visited[i] == 0 && (adjacency[min][i] + dist[min])< dist[i]) 
                {
                    dist[i] = adjacency[min][i] + dist[min]; 
 
                }
            }
        }
        for(int i = 0; i< nodes; i++)
            {
                if(visited[i] == 0) 
                            {
                    min = i;
                    break;
                }
            }
 
 
}
cout<<"\nSHORTEST DISTANCE TO EACH VERTEX IS: "<<endl;
 
for(int i = 1; i<nodes; i++)
    cout<<"FOR "<<i<<": "<<dist[i]<<endl;
}
 
void Dijkstras::enter()
{
    int choice;
    cout<<"\nPRESS 0 FOR UNDIRECTED GRAPH, 1 FOR DIRECTED GRAPH: ";
    cin>>choice;
    switch(choice)
    {
        case 0:
        {
            cout<<"\nENTER THE NUMBER OF VERTICES IN GRAPH. ";
            cin>>nodes;
            cout<<"\nENTER THE NUMBER OF EDGES. ";
            cin>>edges;
            cout<<"\nENTER THE VERTICES AND WEIGHT. (e.g. FOR EDGE BETWEEN 0 AND 1 OF WEIGHT 2, ENTER 0 1 2)"<<endl;
             
            for(int i = 0; i<edges; i++)
            {
                int v1, v2, weight;
                cin>>v1>>v2>>weight;
                adjacency[v1][v2] = weight;
                adjacency[v2][v1] = weight;
            }
        break;
        }
        case 1:
        {
            cout<<"\nENTER THE NUMBER OF VERTICES IN GRAPH: ";
            cin>>nodes;
            cout<<"\nENTER THE NUMBER OF EDGES: ";
            cin>>edges;
            cout<<"\nENTER THE EDGE AND THE WEIGHT (E.G FOR EDGE FROM 0 TO 1, OF WEIGHT 3, ENTER 0 1 3)"<<endl;
            for(int i = 0; i<edges; i++)
            {
                int v1, v2, weight;
                cin>>v1>>v2>>weight;
                adjacency[v1][v2] = weight;
                 
            }
        break;
}
 
    }
}
int main()
{
Dijkstras obj; 
obj.enter(); 
obj.print();
 
 
return 0;
}
 