// BFS with adjacency list implementation
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    public:
        vector<vector<int>> adj;
        vector<bool> visited;
        vector<int> parent;
        vector<int> level;
        void addEdge(int v, int w);
        void BFS(int s); // conduct a BFS from starting node s
};

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);    
}

void Graph::BFS(int s){
    queue<int> frontier;
    frontier.push(s);
    parent[s] = s;
    int currLevel = 1;    
    while(!frontier.empty()){
        int n = frontier.size();
        for(int i = 0; i < n; ++i){
            int next = frontier.front();            
            frontier.pop();
            level[next] = currLevel;
            visited[next] = true;
            for(auto neighbour:adj[next]){
                if(!visited[neighbour]){
                    cout << neighbour << " ";
                    visited[neighbour] = true;
                    parent[neighbour] = next;
                    frontier.push(neighbour);                    
                }                 
            }
        }
        currLevel++;
    }
}
// driver code
int main(){
    Graph g;
    int nodes = 4;
    g.visited.resize(nodes);
    g.adj.resize(nodes);
    g.parent.resize(nodes);
    g.level.resize(nodes);
	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    cout << "\n" << 2 << " ";
    g.BFS(2);
    

    return 0;
}