// C++ program to print DFS traversal from
// a given vertex in a given graph
#include <bits/stdc++.h>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
public:
	map<int, bool> visited;
	map<int, list<int>> adj;
	
	// function to add an edge to graph
	void addEdge(int v, int w);

	// DFS traversal of the vertices
	// reachable from v
	void DFS_Recursive(int v);
	void DFS_Iterative(int v);
	void do_reset();
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFS_Recursive(int v)
{
	// Mark the current node as visited and
	// print it
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent
	// to this vertex
	
	for(auto neighbour:adj[v])
		if(!visited[neighbour])
			DFS_Recursive(neighbour);
}
void Graph::DFS_Iterative(int v){
	do_reset();
	stack<int> processing;
	processing.push(v);
	while(!processing.empty()){
		int next = processing.top();		
		processing.pop();
		if(!visited[next]){
			visited[next] = true;
			cout << next << " ";
		}
		for(auto neighbour:adj[next])	
			if(!visited[neighbour])	
				processing.push(neighbour);
		
		
	}
}
void Graph::do_reset(){
	for(auto i = visited.begin(); i != visited.end(); ++i){
		i->second = false;		
	}
}
// Driver code
int main()
{
	// Create a graph given in the above diagram
	Graph g;
	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

	cout << "Following is Depth First Traversal"
			" Using Recursive Method"
			" (starting from vertex 2) \n";
	g.DFS_Recursive(2);	
	
	cout << "\nFollowing is Depth First Traversal"
			" Using Iterative Method"
			" (starting from vertex 2) \n";	
	g.DFS_Iterative(2);	

	return 0;
}


