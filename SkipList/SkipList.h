#pragma once
#include <vector>
#include "Node.h"

class SkipList : std::vector<Node *>
{
private:
	int maxLevel = 16;

	int randomLevel();
public:
	SkipList();
	~SkipList();

	Node * search(int value);
	bool insert(Domain * key);
	bool remove(Domain * key);
};

