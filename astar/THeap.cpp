#include "THeap.h"
//#define CATCH_CONFIG_MAIN  
#include "catch.hpp"


/*
TEST_CASE("Initializes correctly")
{
	THeap<int> t(4); //create object, don't add anything
	REQUIRE(t.size() == 0); //size = 0
	REQUIRE(t.empty() == true);
}


TEST_CASE("Pushes numbers correctly")
{
	SECTION("Adds the first number properly")
	{
		THeap<double> t(2);
		t.push_back(10.333);
		REQUIRE(t.empty() == false);
		REQUIRE(t.size() == 1);
		REQUIRE(t.front() == 10.333);
	}

	SECTION("Adds a second, larger number properly")
	{
		THeap<double> t(2);
		t.push_back(10.333);
		t.push_back(11.666);
		REQUIRE(t.size() == 2);
		REQUIRE(t.front() == 10.333);
		REQUIRE(t.empty() == false);
	}

	SECTION("Adds a third, smaller number properly, enlarges array as well")
	{
		THeap<double> t(2);
		t.push_back(10.333);
		t.push_back(11.666);
		t.push_back(9);
		REQUIRE(t.size() == 3);
		REQUIRE(t.front() == 9);
		REQUIRE(t.empty() == false);
	}

	SECTION("Sifts added numbers up correctly")
	{
		THeap<double> t(2);
		t.push_back(10.333);
		t.push_back(11.666);
		t.push_back(9);
		t.push_back(8);
		REQUIRE(t.size() == 4);
		REQUIRE(t.front() == 8);
		REQUIRE(t.empty() == false);
	}
	
}

TEST_CASE("Pops numbers correctly")
{
	SECTION("Doesnt pop when array is empty")
	{
		int i = 0;
		int* ptr = &i;     // pointer
		int& ref = *ptr; // address
		THeap<int> t(2);
		REQUIRE(t.pop_back(ref) == false);
		REQUIRE(t.empty() == true);
	}

	SECTION("Pops when array has 1 item")
	{
		int i = 0;
		int* ptr = &i;     // pointer
		int& ref = *ptr; // address
		THeap<int> t(2);
		t.push_back(2);
		REQUIRE(t.pop_back(ref) == true);
		REQUIRE(ref == 2);
		REQUIRE(t.size() == 0);
		REQUIRE(t.empty() == true);
	}

	SECTION("Pops when array has multiple items and sifts correctly")
	{
		int i = 0;
		int* ptr = &i;     // pointer
		int& ref = *ptr; // address
		THeap<int> t(2);
		t.push_back(20);
		t.push_back(10);
		t.push_back(5);
		t.push_back(1);
		REQUIRE(t.pop_back(ref) == true);
		REQUIRE(ref == 1);
		REQUIRE(t.front() == 5);
		REQUIRE(t.size() == 3);
		REQUIRE(t.empty() == false);
	}
}
*/