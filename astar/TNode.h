#pragma once

class TNode
{
public:
	TNode();
	~TNode();
	TNode(int* startPos, int cst);
	int xPos;
	int yPos;
	bool visited = false;
	int cost;
	bool operator<(TNode& other);
	bool operator>(TNode& other);
	bool operator==(TNode& other);
	void setPriority(int p);
	TNode* previous;
private:
	int priority;
	int* endPosition;
};