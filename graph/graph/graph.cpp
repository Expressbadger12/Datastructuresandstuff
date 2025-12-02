// graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//boone stewart

#include <iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Graph {
private:
	unordered_map<int, vector<int>> adjList; // Adjacaney list to store the graph
public:
	// add an edge to the graph (directed or undirected)
	void addEdge(int u, int v, bool isDirected = false) {
		adjList[u].push_back(v); //add edge u -> v
		if (!isDirected) {
			adjList[v].push_back(u);//if undirected, also add edge v-> u
		}
	}
	//Display the graph
	void display() {
		for (const auto& pair : adjList) {
			cout << pair.first << " -> ";
			for (int neighbour : pair.second) {
				cout << neighbour << " ";
			}
			cout << endl;
		}
	}
	//Perform the depth-first search (DFS)
	void dfsUtil(int node, unordered_map<int, bool>& visisted) {
		visisted[node] = true;
		cout << node << " ";
		for (int neighbour : adjList.at(node)) {
			if (!visisted[neighbour]) {
				dfsUtil(neighbour, visisted);
			}
		}
	}
	void dfs(int startNode) {
		unordered_map<int, bool> visited;//keep track of visited node
		cout << "DFS starting from node " << startNode << ": ";
		dfsUtil(startNode, visited);
		cout << endl;
	}
	//perform BBreadhtfirstsearch (BFS)
	void bfs(int startNode) {
		unordered_map<int, bool> visisted;
		vector<int> queue; //use a que for the breadth search first (BFS)
		queue.push_back(startNode);
		visisted[startNode] = true;
		cout << "BFS starting from node " << startNode << ": ";
		while (!queue.empty()) {
			int current = queue.front();
			queue.erase(queue.begin()); //remove the frobnt elememenetnt
			cout << current << " ";
			for (int neighbour : adjList.at(current)) {
				if (!visisted[neighbour]) {
					queue.push_back(neighbour);
					visisted[neighbour] = true;
				}
			}
		} cout << endl;
	}
};

int main()
{
	Graph graph1;
	//add edgesto the graph
	graph1.addEdge(1, 2);
	graph1.addEdge(1, 3);
	graph1.addEdge(2, 4);
	graph1.addEdge(3, 4);
	graph1.addEdge(4, 5);
	//display the graph
	cout << "Graph representation: " << endl;
	graph1.display();
	//preform graph traversal
	graph1.bfs(1);
	graph1.dfs(1);
}
