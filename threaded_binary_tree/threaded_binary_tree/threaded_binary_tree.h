#pragma once
#include<iostream>
#include<queue>
using namespace std;

enum way{front,middle,behind};

class Node
{
public:
	Node* left;
	Node* right;
	int date;
};

class Threaded_Binary_Tree
{
public:
	Threaded_Binary_Tree() { root = this->Init(); this->travel_way = front; }
	void Change_the_way(way w) { this->travel_way = w; }
	Node* Init();

	void Init_by_Threaded(way);
	
private:
	Node* root;
	queue<Node*> q;
	way travel_way;

	void Front_Init(Node*);
	void Middle_Init(Node*);
	void Behind_Init(Node*);
};