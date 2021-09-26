#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef pair<int,int> myPair;

class Graph
{
    private:
        int V;
        list<myPair> *adj;
    public:
        Graph(int V);
        void addEdge(int u, int v, int w);
        void shortestPath(int src);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<myPair>[this->V];
}
void Graph::addEdge(int u, int v, int w){
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}

void Graph::shortestPath(int src){
    priority_queue<myPair,vector<myPair>,greater<myPair>> pq;
    vector<int> dist(this->V, INF);
    dist[src] = 0;
    list<myPair>::iterator it;
    pq.push({0,src});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(it = adj[u].begin(); it != adj[u].end(); ++it){
            int v = it->first;
            int w = it->second;
            if(dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
                pq.push({dist[v],v});                
            }            
        }        
    }
    // print single-source shortest paths
    for(int i = 0; i < this->V; ++i){
        cout << i << " - " << dist[i] << '\n';
    }
}

int main(){
    int V = 3;
    Graph g(V);
    g.addEdge(0,1,7);
    g.addEdge(0,2,9);
    g.addEdge(1,2,10);
    g.shortestPath(0);
    return 0;
}