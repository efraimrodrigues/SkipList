#pragma once
class Domain
{
private:
	int min, max;

public:
	Domain();
	~Domain();

	void setMin(int min);
	int getMin();

	void setMax(int max);
	int getMax();

	bool contains(int value);
};

