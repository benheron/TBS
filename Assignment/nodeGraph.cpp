#include "nodeGraph.h"

nodeGraph::nodeGraph(int w, int h)
{
	for (int i = 0; i < w; i++)
	{
		std::vector<node*> tmp;
		nodes.push_back(tmp);
		for (int j = 0; j < h; j++)
		{
			node *tileNode = new node();
			nodes[i].push_back(tileNode);
		}
	}

	//create connections
	int c = 0;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (i < w - 1) nodes[i][j]->addConnection(nodes[i + 1][j]);
			if (i > 0) nodes[i][j]->addConnection(nodes[i - 1][j]);
			if (j < h - 1) nodes[i][j]->addConnection(nodes[i][j + 1]);
			if (j > 0) nodes[i][j]->addConnection(nodes[i][j - 1]);
		}
	}
}

nodeGraph::~nodeGraph()
{

}

node* nodeGraph::getNode(int x, int y)
{
	return nodes[x][y];
}