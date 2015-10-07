#pragma once
#include <vector>

class node
{
protected:
	int xPos;
	int yPos;
	int distance;
	bool visited;
	int numConnections;
	std::vector<node*> nodeConnections;
public:
	node();
	node(int x, int y);
	~node();
	void build();
	void setDistance(int d);
	int getDistance();
	void setVisited(bool v);
	bool getVisited();
	void setX(int x);
	int getX();
	void setY(int y);
	int getY();
	void addConnection(node* cnntn);
	void setConnections(std::vector<node*> connections);
	std::vector<node*> getConnections();
	int getNumConnections();
};