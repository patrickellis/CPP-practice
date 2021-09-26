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
        void addEdge(int u, int v, int w);
        void getMST(int src);
        Graph(int V);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<myPair>[this->V];
}

void Graph::addEdge(int u, int v, int w){
    this->adj[u].push_back({v,w});
    this->adj[v].push_back({u,w});
}

void Graph::getMST(int src){
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
            if(w < dist[v]){
                dist[v] = w;
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
    int V = 4;
    Graph g(V);
    g.addEdge(0,1,2);
    g.addEdge(0,3,1);
    g.addEdge(1,3,2);
    g.addEdge(2,3,3);
    g.getMST(0);
    return 0;
}