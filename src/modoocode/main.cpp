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

	std::vector<int32_t> vec2(6, 0);

	std::cout << "처음 vec과 vec2 상태 ------" << std::endl;
	print(vec.begin(), vec.end());
	print(vec2.begin(), vec2.end());

	std::cout << "vec 전체에 1 을 더한 것을 vec2 에 저장 ---" << std::endl;
	std::transform(vec.begin(), vec.end(), vec2.begin(), [](int32_t i) -> int32_t {return i + 1; });
	print(vec.begin(), vec.end());
	print(vec2.begin(), vec2.end());

	return 0;
}