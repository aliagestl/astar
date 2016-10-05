#pragma once
#include "TNode.h"

struct Map
{
	TNode map[4][4];
	int size = 16;
};

class Search
{
public:
	Search();
	~Search();
	int manDist(TNode* startPos, TNode * endPos);
	int priority(int cost, TNode * endPos);
	int summation();
	void astar(TNode * startPos, TNode * endPos);
	Map mp;
private: 
	TNode *previous;
	TNode *current;
	int totalCost;
};


