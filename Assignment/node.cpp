#include "node.h"

node::node()
{
	xPos = 0;
	yPos = 0;
	numConnections = 0;
}

node::node(int x, int y)
{
	xPos = x;
	yPos = y;
	numConnections = 0;
}

node::~node()
{

}

void node::build()
{

}

void node::setDistance(int d)
{
	if (d < distance)
	{
		distance = d;
	}
}

int node::getDistance()
{
	return distance;
}

void node::setVisited(bool v)
{
	visited = v;
}

bool node::getVisited()
{
	return visited;
}

void node::setX(int x)
{
	xPos = x;
}

int node::getX()
{
	return xPos;
}

void node::setY(int y)
{
	yPos = y;
}

int node::getY()
{
	return yPos;
}

void node::addConnection(node* cnntn)
{
	nodeConnections.push_back(cnntn);
	numConnections += 1;
}

void node::setConnections(std::vector<node*> connections)
{
	nodeConnections = connections;
}

std::vector<node*> node::getConnections()
{
	return nodeConnections;
}

int node::getNumConnections()
{
	return numConnections;
}