#include "SkipList.h"



int SkipList::randomLevel()
{
	int lvl = 0;

	/*Flipping coins*/
	while (rand() < 0.5 && lvl < this->maxLevel)
		lvl++;

	return lvl;
}

SkipList::SkipList()
{
}


SkipList::~SkipList()
{
}

Node * SkipList::search(int searchKey)
{
	Node * x = this->at(currentLevel);

	for (int i = currentLevel; i >= 0; i--)
		while (x->forward[i]->less(searchKey))
			x = x->forward[i];

	x = x->forward[0];

	if (x->contains(searchKey))
		return x;
	else
		return nullptr;
}

bool SkipList::insert(Domain * key)
{
	Node * x = this->at(this->size());

	int lvl = randomLevel();

	//TODO 
	/*Pass Domain and Level as Node parameters.*/
	Node * newNode = new Node();

	if (lvl >= this->size())
		this->push_back(nullptr);

	/*Place the key on each level below the chosen level.*/
	for (int i = this->size() - 1; i >= 0; i--) {
		while (x->forward[i]->less(key->getMax()))
			x = x->forward[i];

		newNode->forward[i] = x->forward[i];

		x->forward[i] = newNode;

	}

	return false;
}
