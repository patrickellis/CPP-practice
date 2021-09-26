#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/strongly-connected-components/
class Graph
{
    private:
        int V;
        list<int> *adj;
        void fillOrder(int v, bool visited[], stack<int> &Stack);
        void DFSUtil(int v, bool visited[]);
    public:
        Graph(int V);
        void addEdge(int v, int w);
        void printSCCs();     
        Graph getTranspose();   
};
Graph::Graph(int V){
    this->V = V;
    this->adj = new list<int>[V];
}
Graph Graph::getTranspose(){
    Graph g(V);
    list<int>::iterator it;
    for(int v = 0; v < V; ++v){
        for(it = adj[v].begin(); it != adj[v].end(); ++it){
            g.addEdge(*it, v);
        }
    }
    return g;
}
void Graph::DFSUtil(int v, bool visited[]){
    // print DFS starting from v
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator it;
    for(it = adj[v].begin(); it != adj[v].end(); ++it){
        if(!visited[*it])
            DFSUtil(*it, visited);
    }
}
void Graph::fillOrder(int v, bool visited[], stack<int> &Stack){
    visited[v] = true;
    list<int>::iterator it;
    for(it = adj[v].begin(); it != adj[v].end(); ++it){
        if(!visited[*it])
            fillOrder(*it, visited, Stack);
    }
    Stack.push(v);
}
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::printSCCs(){
    stack<int> Stack;
    // mark all vertices as not visited (for first DFS)
    bool *visited = new bool[V];
    for(int i = 0; i < V; ++i){
        visited[i] = false;
    }
    
    // fill vertices in stack according to their finishing times
    for(int i = 0; i < V; ++i){
        if(visited[i] == false)
            fillOrder(i, visited, Stack);
    }
    // create reversed graph
    Graph gr = getTranspose();

    for(int i = 0; i < V; ++i){
        visited[i] = false;
    }

    while(!Stack.empty()){
        int v = Stack.top();
        Stack.pop();
        if(visited[v] == false)
        {
            gr.DFSUtil(v,visited);
            cout << "\n";
        }
    }
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
  
    cout << "Following are strongly connected components in "
            "given graph \n";
    g.printSCCs();
  
    return 0;
}