#include <bits/stdc++.h>
using namespace std;

void DFS_Util(vector<bool>& visited, vector<vector<bool>>& adj,int source){
    if(!visited[source]){
        visited[source] = true;
        cout << source << " ";
    }
    for(int node = 0; node < adj.size(); ++node){
        if(adj[source][node] == true && !visited[node])
            DFS_Util(visited,adj,node);
    }
}

// implementation using adjacency matrix
class Graph
{
    public:
        vector<vector<bool>> adj;
        vector<bool> visited;
        void addEdge(int v, int w);
        void DFS(int s);     
        void DFS_Recurse(int s);   
};

void Graph::addEdge(int v, int w){
    adj[v][w] = true;    
}

void Graph::DFS(int s){
    stack<int> processing;
    processing.push(s);
    
    while(!processing.empty()){
        int next = processing.top();        
        processing.pop();
        if(!visited[next]){
            visited[next] = true;
            cout << next << " ";
        }
        for(int i = 0; i < adj.size(); ++i){
            // linear search for neighbours
            if(adj[next][i] == true && !visited[i]){
                processing.push(i);
            } 
        }
    }
    // ensure all vertices are visited by iterating over them
    for(int node = 0; node < visited.size(); ++node)
        if(!visited[node])
            DFS(node);    
}

void Graph::DFS_Recurse(int s){
    DFS_Util(visited, adj, s);
    for(int i = 0; i < visited.size(); ++i)
        if(!visited[i])
            DFS_Util(visited,adj,s);
}

// driver code
int main(){
    int nodes = 4;
    Graph g;
    g.adj.resize(nodes,vector<bool>(nodes,false));
    g.visited.resize(nodes, false);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.DFS_Recurse(2);
}