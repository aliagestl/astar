#include "Search.h"
#include <iostream>
#include "TNode.h"
#include "THeap.h"
#include "math.h"

using namespace std;


//NOT USING DIAGONALS BECAUSE MANHATTAN DISTANCE FORMULA DOES NOT USE DIAGONALS
Search::Search()
{
	totalCost = 0;

	//set up map
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			int tempArr[2] = { x, y };
			mp.map[x][y] = TNode(tempArr, 0);
		}
	}

	//manually set costs
	mp.map[0][0].cost = 2;
	mp.map[0][1].cost = 2;
	mp.map[0][2].cost = 2; 
	mp.map[0][3].cost = 2;

	mp.map[1][0].cost = 2;
	mp.map[1][1].cost = 2;
	mp.map[1][2].cost = 2;
	mp.map[1][3].cost = 2;
	  
	mp.map[2][0].cost = 2;
	mp.map[2][1].cost = 2;
	mp.map[2][2].cost = 1;
	mp.map[2][3].cost = 2;
	  
	mp.map[3][0].cost = 1;
	mp.map[3][1].cost = 1;
	mp.map[3][2].cost = 1;
	mp.map[3][3].cost = 2;

	/*
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << mp.map[i][j].cost;

		}
		cout << endl;
	}
	*/
}


Search::~Search()
{
}

int Search::manDist(TNode * currPos, TNode * endPos)
{
	int dx = abs(endPos->xPos - currPos->xPos);
	int dy = abs(endPos->yPos - currPos->yPos);
	return dx + dy;
}

int Search::priority(int cost, TNode * endPos)
{
 	int pri = summation() + cost + manDist(current, endPos);
	return pri;
}

int Search::summation()
{
	return totalCost;
}

void Search::astar(TNode  * startPos, TNode * endPos)
{
	//found is whether the destiantion was found yet
	bool found = false;
	THeap<TNode> heap;

	//mark source as visited
	mp.map[(*startPos).xPos][(*startPos).yPos].visited = true;

	//add start to heap
	heap.push_back(mp.map[(*startPos).xPos][(*startPos).yPos]);
	

	//check if source is destination
	if ((*startPos).xPos == (*endPos).xPos && (*startPos).yPos == (*endPos).yPos)
	{
		found = true;
	}
	else found = false;

	//while destination hasn't been found and heap isn't empty
	while (!found && heap.size() != 0)
	{
		//check if end
		if (heap.front().xPos == (*endPos).xPos && heap.front().yPos == (*endPos).yPos) {
			found = true;
		}
		else
		{
			//if not end
			//pop front, save the value
			int temp[2] = { heap.front().xPos , heap.front().yPos };

			
			totalCost += heap.front().cost;
			heap.pop_back(heap.front());
			
			//check for unvisited neighbors, mark all visited, set previous node, add to min heap
			//nesting the if statements because calling the map for a node that doesn't exist may cause problems

			//check top
			if (temp[0] - 1 >= 0)
			{
				if (mp.map[temp[0] - 1][temp[1]].visited == false)
				{
					mp.map[temp[0] - 1][temp[1]].previous = &mp.map[temp[0]][temp[1]]; //set node's previous
					previous = &mp.map[temp[0]][temp[1]]; //set this class's previous node (to be used in the manhattan distance method)
					current = &mp.map[temp[0] - 1][temp[1]]; //set this class's current node (to be used in the manhattan distance method)
					mp.map[temp[0] - 1][temp[1]].setPriority(priority(mp.map[temp[0] - 1][temp[1]].cost, endPos)); //set the node's current priority
					heap.push_back(mp.map[temp[0] - 1][temp[1]]); //add to heap
					mp.map[temp[0] - 1][temp[1]].visited = true; //mark visited
				}
			}

			//check bottom
			if (temp[0] + 1 <= 3)
			{
				if (mp.map[temp[0] + 1][temp[1]].visited == false)
				{
					mp.map[temp[0] + 1][temp[1]].previous = &mp.map[temp[0]][temp[1]]; //set node's previous
					previous = &mp.map[temp[0]][temp[1]]; //set this class's previous node (to be used in the manhattan distance method)
					current = &mp.map[temp[0] + 1][temp[1]]; //set this class's current node (to be used in the manhattan distance method)
					mp.map[temp[0] + 1][temp[1]].setPriority(priority(mp.map[temp[0] + 1][temp[1]].cost, endPos)); //set the node's current priority
					heap.push_back(mp.map[temp[0] + 1][temp[1]]); //add to heap
					mp.map[temp[0] + 1][temp[1]].visited = true; //mark visited
				}
			}

			//check left
			if (temp[1] - 1 >= 0)
			{
				if (mp.map[temp[0]][temp[1] - 1].visited == false)
				{
					mp.map[temp[0]][temp[1] - 1].previous = &mp.map[temp[0]][temp[1]]; //set node's previous
					previous = &mp.map[temp[0]][temp[1]]; //set this class's previous node (to be used in the manhattan distance method)
					current = &mp.map[temp[0]][temp[1] - 1]; //set this class's current node (to be used in the manhattan distance method)
					mp.map[temp[0]][temp[1] - 1].setPriority(priority(mp.map[temp[0]][temp[1] - 1].cost, endPos)); //set the node's current priority
					heap.push_back(mp.map[temp[0]][temp[1] - 1]); // add to heap
					mp.map[temp[0]][temp[1] - 1].visited = true; //mark visited
				}
			}

			//check right
			if (temp[1] + 1 <= 3)
			{
				if (mp.map[temp[0]][temp[1] + 1].visited == false)
				{
					mp.map[temp[0]][temp[1] + 1].previous = &mp.map[temp[0]][temp[1]]; //set node's previous
					previous = &mp.map[temp[0]][temp[1]]; //set this class's previous node (to be used in the manhattan distance method)
					current = &mp.map[temp[0]][temp[1] + 1]; //set this class's current node (to be used in the manhattan distance method)
					mp.map[temp[0]][temp[1] + 1].setPriority(priority(mp.map[temp[0]][temp[1] + 1].cost, endPos)); //set the node's current priority
					heap.push_back(mp.map[temp[0]][temp[1] + 1]); //add to heap
					mp.map[temp[0]][temp[1] + 1].visited = true; //set visited
				}
			}

			found = false;
		}

	}
	/*
	bool listDone = false;
	cout << "PATH (Printing from end to beginning) : { " << (*endPos).xPos << ", " << (*endPos).yPos << " }" << endl;
	TNode* toPrint;
	while (!listDone)
	{
		toPrint = (*current).previous;
		current = (*current).previous;
		cout << "{ " << (*toPrint).xPos << ", " << (*toPrint).yPos << " }" << endl;

		if ((*current).xPos == (*startPos).xPos && (*current).yPos == (*startPos).yPos)
		{
			listDone = true;
		}
	}
	*/
}
