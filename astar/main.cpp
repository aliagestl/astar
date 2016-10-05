#include "THeap.h"
#include "TNode.h"
#include "Search.h"
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;



TEST_CASE("Makes map correctly")
{
	TNode map[4][4];
	int endPos[2] = { 2,2 };
	int startPos[2] = { 3,0 };

	TNode *end = &TNode(endPos, 1);
	TNode *begin = &TNode(startPos, 1);
	Search astar = Search();
	REQUIRE(astar.mp.map[0][0].cost == 2);
	REQUIRE(astar.mp.map[0][1].cost == 2);
	REQUIRE(astar.mp.map[0][2].cost == 2);
	REQUIRE(astar.mp.map[0][3].cost == 2);

	REQUIRE(astar.mp.map[1][0].cost == 2);
	REQUIRE(astar.mp.map[1][1].cost == 2);
	REQUIRE(astar.mp.map[1][2].cost == 2);
	REQUIRE(astar.mp.map[1][3].cost == 2);

	REQUIRE(astar.mp.map[2][0].cost == 2);
	REQUIRE(astar.mp.map[2][1].cost == 2);
	REQUIRE(astar.mp.map[2][2].cost == 1);
	REQUIRE(astar.mp.map[2][3].cost == 2);

	REQUIRE(astar.mp.map[3][0].cost == 1);
	REQUIRE(astar.mp.map[3][1].cost == 1);
	REQUIRE(astar.mp.map[3][2].cost == 1);
	REQUIRE(astar.mp.map[3][3].cost == 2);
}

TEST_CASE("Searches map correctly")
{
	SECTION("Visits proper nodes") {
		TNode map[4][4];
		int endPos[2] = { 2,2 };
		int startPos[2] = { 3,0 };

		TNode *end = &TNode(endPos, 1);
		TNode *begin = &TNode(startPos, 1);
		Search astar = Search();

		//run astar
		//make sure proper ones are visited
		astar.astar(begin, end);

		REQUIRE(astar.mp.map[0][0].visited == false);
		REQUIRE(astar.mp.map[0][1].visited == false);
		REQUIRE(astar.mp.map[0][2].visited == false);
		REQUIRE(astar.mp.map[0][3].visited == false);

		REQUIRE(astar.mp.map[1][0].visited == false);
		REQUIRE(astar.mp.map[1][1].visited == false);
		REQUIRE(astar.mp.map[1][2].visited == false);
		REQUIRE(astar.mp.map[1][3].visited == false);

		REQUIRE(astar.mp.map[2][0].visited == true);
		REQUIRE(astar.mp.map[2][1].visited == true);
		REQUIRE(astar.mp.map[2][2].visited == true);
		REQUIRE(astar.mp.map[2][3].visited == false);

		REQUIRE(astar.mp.map[3][0].visited == true);
		REQUIRE(astar.mp.map[3][1].visited == true);
		REQUIRE(astar.mp.map[3][2].visited == true);
		REQUIRE(astar.mp.map[3][3].visited == true);
	}
	SECTION("Takes correct path")
	{
		TNode map[4][4];
		int endPos[2] = { 2,2 };
		int startPos[2] = { 3,0 };

		TNode *end = &TNode(endPos, 1);
		TNode *begin = &TNode(startPos, 1);
		Search astar = Search();

		//run astar
		//make sure proper ones are visited
		astar.astar(begin, end);

		//I check this by checking the previous node of the end until the beginning is reached
		REQUIRE(astar.mp.map[2][2].previous->xPos == astar.mp.map[3][2].xPos);
		REQUIRE(astar.mp.map[2][2].previous->yPos == astar.mp.map[3][2].yPos);

		REQUIRE(astar.mp.map[3][2].previous->xPos == astar.mp.map[3][1].xPos);
		REQUIRE(astar.mp.map[3][2].previous->yPos == astar.mp.map[3][1].yPos);

		REQUIRE(astar.mp.map[3][1].previous->xPos == astar.mp.map[3][0].xPos);
		REQUIRE(astar.mp.map[3][1].previous->yPos == astar.mp.map[3][0].yPos);
	}
	SECTION("Adds costs correctly")
	{
		TNode map[4][4];
		int endPos[2] = { 2,2 };
		int startPos[2] = { 3,0 };

		TNode *end = &TNode(endPos, 1);
		TNode *begin = &TNode(startPos, 1);
		Search astar = Search();

		//run astar
		//make sure proper ones are visited
		astar.astar(begin, end);

		REQUIRE(astar.summation() == 3);
	}
}

/*
int main() {
	int endPos[2] = { 2,2 };
	int startPos[2] = { 3,0 };

	TNode *end = &TNode(endPos, 1);
	TNode *begin = &TNode(startPos, 1);

	//call astar
	Search astar = Search();
	astar.astar(begin, end);
	return 0;
}
*/