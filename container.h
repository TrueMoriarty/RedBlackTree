#pragma once
#include <string>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

using namespace std;

class RedBlackTree {
private:
	string name; //RBT name 
	set<int> data; //set based on RBT
	vector<set<int>::iterator> itSeq; //iterators of tree set
public:
	//Default constructor 
	RedBlackTree(string N) : name(N) {}
	//TESTING CONSTRUCTOR
	RedBlackTree(string N, char T);
	//Generator
	RedBlackTree(int power, string N);
	void OR(RedBlackTree val, RedBlackTree& res);
	void DIF(RedBlackTree val, RedBlackTree& res);
	void MERGE(RedBlackTree val, RedBlackTree& res);
	void CONCAT(RedBlackTree val, RedBlackTree& res);
	void MUL(int p, RedBlackTree& res);
	void printSet();
	void printitSeq();
	int getPower() { return data.size(); }
};