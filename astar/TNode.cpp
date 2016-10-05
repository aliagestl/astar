#include "TNode.h"


TNode::TNode()
{
}

TNode::~TNode()
{
}

TNode::TNode(int* startPos, int cst)
{
	xPos = startPos[0];
	yPos = startPos[1];
	cost = cst;
	priority = 100000;
}

bool TNode::operator<(TNode & other)
{
	return priority < other.priority;
}

bool TNode::operator>(TNode & other)
{
	return priority > other.priority;
}

bool TNode::operator==(TNode & other)
{
	return priority == other.priority;
}

void TNode::setPriority(int p)
{
	priority = p;
}
