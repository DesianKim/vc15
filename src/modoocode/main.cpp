#include "pch.h"
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <iostream>

template <class _RanIt>
void print(_RanIt begin, _RanIt end)
{
	for (_RanIt itr = begin; itr != end; ++itr)
		std::cout << "[" << *itr << "] ";
	std::cout << std::endl;
}

int main()
{
	std::vector<int32_t> vec;
	vec.emplace_back(5);
	vec.emplace_back(3);
	vec.emplace_back(1);
	vec.emplace_back(2);
	vec.emplace_back(3);
	vec.emplace_back(4);

	std::cout << "처음 vec 상태 ------" << std::endl;
	print(vec.begin(), vec.end());

	std::cout << "벡터에서 홀수 인 원소 제거 ---" << std::endl;
	int32_t num_erased = 0;

	std::function func = [&num_erased](const int32_t& i) -> bool {
		if (num_erased >= 2)
			return false;
		else if (i % 2 == 1)
		{
			++num_erased;
			return true;
		}
		return false;
	};

	vec.erase(std::remove_if(vec.begin(), vec.end(), func), vec.end());

	print(vec.begin(), vec.end());

	return 0;
}