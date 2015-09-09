#include "stdafx.h"
#include <vector>

class Graph{
	struct Vertex{
		int num;
		int data;
	};

	int adjMatrix[100][100];
	std::vector<Vertex*> vertList;

	Graph();
	~Graph();
	void addVertex(int data);
	void addEdge(Vertex& node1, Vertex& node2);
	void printShortestPath(Vertex& node1, Vertex& node2);
};