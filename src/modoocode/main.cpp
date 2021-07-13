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

struct User
{
public:
	User(std::string name, int32_t age)
		: m_sName(name),
		m_nAge(age)
	{
	}

	bool operator<(const User& u) const
	{
		return m_nAge < u.m_nAge;
	}

	std::string m_sName;
	int32_t m_nAge;
};

std::ostream& operator<<(std::ostream& o, const User& u)
{
	o << u.m_sName << " , " << u.m_nAge;
	return o;
}

int main()
{
	std::vector<User> vec;
	for (int32_t i = 0; i < 100; ++i)
	{
		std::string name = "";
		name.push_back('a' + i / 26);
		name.push_back('a' + i % 26);
		vec.emplace_back(name, static_cast<int32_t>(rand() % 10));
	}

	std::vector<User> vec2 = vec;

	std::cout << "정렬 전 ----" << std::endl;
	print(vec.begin(), vec.end());

	std::sort(vec.begin(), vec.end());

	std::cout << "정렬 후 ----" << std::endl;
	print(vec.begin(), vec.end());

	std::cout << "stable_sort 의 경우 ---" << std::endl;
	std::stable_sort(vec2.begin(), vec2.end());
	print(vec2.begin(), vec2.end());

	return 0;
}