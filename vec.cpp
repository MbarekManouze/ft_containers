#include "Vector/vector.hpp"


int main()
{
	ft::vector<int> vec;

	vec.push_back(5);
	vec.push_back(66);
	vec.push_back(33);
	vec.push_back(7);
	vec.push_back(99);
	vec.push_back(4);

	ft::vector<int>::reverse_iterator rit = vec.rbegin();
	(void)rit;
}