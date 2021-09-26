#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>* adj;
    void topologicalSortUtil(int v, bool visited[], stack<int>& S);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int>& S){
    visited[v] = true;
    list<int>::iterator it;
    for(it = adj[v].begin(); it != adj[v].end(); ++it){
        if(!visited[*it])
            topologicalSortUtil(*it, visited, S);            
    }
    S.push(v);
}
void Graph::topologicalSort(){
    stack<int> S;
    bool* visited = new bool[V];
    for(int i = 0; i < V; ++i)
        visited[i] = false;
    
    for(int i = 0; i < V; ++i){
        if(!visited[i])
            topologicalSortUtil(i, visited, S);
    }
    
    cout << "\n";
    while(!S.empty()){
        cout << S.top() << " ";
        S.pop();
    }
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
  
    cout << "Following is a Topological Sort of the given graph n";
    g.topologicalSort();
  
    return 0;
}