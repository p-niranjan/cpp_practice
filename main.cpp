#includes "arrays.h"

void arrays()
{
	vector<int> array = {3,5,-4,8,11,1,-1,6};
	twoNumberSumUsingHashMap(array, 10);
	twoNumberSumUsingTraversers(array, 10);
}

int main()
{
	arrays();
}