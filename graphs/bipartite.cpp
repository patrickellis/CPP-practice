#include <bits/stdc++.h>
using namespace std;

class Graph
{
    vector<int>* adj;
    int V;
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isBipartite();
};

Graph::Graph(int V){
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph::isBipartite(){
    int* colors = new int[V];
    for(int i = 0; i < V; ++i)
        colors[i] = -1;
        // -1 = uncolored
        // 0 = red
        // 1 = blue
    queue<int> processing;
    processing.push(0);
    colors[0] = 1;  
    vector<int>::iterator it;  
    while(!processing.empty()){
        int next = processing.front();
        processing.pop();
        for(it = adj[next].begin(); it != adj[next].end(); ++it){
            if(colors[*it]==-1){
                colors[*it] = 1-colors[next];
                processing.push(*it);
            }
            else if(colors[*it] == colors[next]){
                return false;                    
            }        
        }
    }
    return true;
}

int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,3);
    g.addEdge(2,3);
    
    if(g.isBipartite()){
        cout << "graph is bipartite";
    }
    else{
        cout << "graph not bipartite";
    }
    return 0;
}