#pragma once
#include "node.h"
#include <vector>

class nodeGraph
{
protected:

	std::vector<std::vector<node*>> nodes;
public:
	nodeGraph(int w, int h);
	nodeGraph(std::vector <node*> dfg);
	~nodeGraph();

	node* getNode(int x, int y);

};