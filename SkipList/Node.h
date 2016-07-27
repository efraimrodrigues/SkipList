#pragma once
#include "Domain.h"

class Node
{
public:
	Domain * domain;
	std::vector<Node *> forward;

	Node();
	Node(Domain * domain, int level);
	~Node();

	int getKey();
	bool contains(int value);

	bool greater(int value);
	bool less(int value);
};

