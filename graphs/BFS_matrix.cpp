// BFS with adjacency matrix implementation
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    public:
        int vertexCount;
        vector<vector<bool>> adj;
        vector<bool> visited;
        void BFS(int s);
        void addEdge(int v, int w);
        void setSize(size_t size);
};

void Graph::addEdge(int v, int w){
    adj[v][w] = true;
}
void Graph::setSize(size_t size){
    visited.resize(size);
    adj.resize(size, vector<bool>(size,false));
    vertexCount = size;
}

void Graph::BFS(int s){
    queue<int> frontier;
    frontier.push(s);
    cout << s << " ";
    int level = 1;
    while(!frontier.empty()){
        int n = frontier.size();
        for(int i = 0; i < n; ++i){            
            int next = frontier.front();
            visited[next] = true;            
            frontier.pop();
            for(int i = 0; i < vertexCount; ++i){
                if(adj[next][i] == true && !visited[i]){
                    visited[i] = true;
                    frontier.push(i);
                    cout << i << " ";
                }
            }
        }
    }
}



//driver code
int main(){
    int nodes = 4;
    Graph g;
    g.setSize(nodes);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.BFS(2);
    return 0;
}