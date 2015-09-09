#include "stdafx.h"
#include "Graph.h"

Graph::Graph(){
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			adjMatrix[i][j] = 0;
		}
	}
}

Graph::~Graph(){
	for (int i = 0; i < vertList.size(); i++){
		delete vertList[i];
		vertList[i] = NULL;
	}
}

void Graph::addVertex(int data){
	Vertex* v = new Vertex();
	v->data = data;
	v->num = vertList.size();

	vertList.push_back(v);
}

void Graph::addEdge(Vertex& node1, Vertex& node2){
	adjMatrix[node1.num][node2.num] = 1;
}