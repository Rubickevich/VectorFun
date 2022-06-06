#include <algorithm>
#include <iostream>
#include <vector>
class Functor
{
public:
	bool operator()(int a, int b) { return a > b; }
};
bool predicate(int a, int b)
{
	return a > b;
}
int main()
{
	int n; int max = INT_MIN; int sum = 0;
	std::cout << "write n: ";
	std::cin >> n;
	std::vector<int> empty;
	std::vector<int> nElements(n);
	std::vector<int> birthDay(n, 2);
	std::vector<int> birthFull{ 2,11,2003 };
	std::cout << "Birth Full: " << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << birthFull.at(i) << " ";
	std::for_each(birthFull.begin(), birthFull.end(), [&max](int i)
	{
			if (i > max)
				max = i;
	});
	std::cout <<std::endl<< "max is: " <<max<<std::endl;
	auto itr = birthFull.begin();
	while (itr < birthFull.end())
	{
		sum += *itr;
		++itr;
	}
	std::cout <<"sum is : " << sum << std::endl;
	std::cout <<"Number 11 found " << std::count(birthFull.begin(), birthFull.end(), 11) <<" times in the vector" <<std::endl;
	birthFull.emplace_back(16);
	std::cout << "Birth Full: " << std::endl;
	std::copy(birthFull.begin(), birthFull.end(), std::ostream_iterator<int>(std::cout, " "));
	std::sort(birthFull.begin(), birthFull.end());
	std::cout << std::endl <<"Birth Full sorted: " << std::endl;
	std::copy(birthFull.begin(), birthFull.end(), std::ostream_iterator<int>(std::cout, " "));
	std::sort(birthFull.begin(), birthFull.end(), predicate);
	std::cout << std::endl << "Birth Full revers sorted: " << std::endl;
	std::copy(birthFull.begin(), birthFull.end(), std::ostream_iterator<int>(std::cout, " "));
	itr = birthFull.begin();
	++itr;
	birthFull.insert(itr, 6);
	Functor functor;
	std::sort(birthFull.begin(), birthFull.end(), functor);
	std::cout << std::endl << "Birth Full revers sorted: " << std::endl;
	std::copy(birthFull.begin(), birthFull.end(), std::ostream_iterator<int>(std::cout, " "));
}
