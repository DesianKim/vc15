#include "pch.h"
#include <iostream>
#include <string>
#include <unordered_set>

template <class _Ty>
void print_undordered_set(const std::unordered_set<_Ty>& s)
{
	for (const auto& elem : s)
		std::cout << elem << std::endl;
}

template <class _Ty>
void is_exist(const std::unordered_set<_Ty>& s, _Ty key)
{
	auto itr = s.find(key);
	if (itr != s.end())
		std::cout << key << " 가 존재!" << std::endl;
	else
		std::cout << key << " 가 없다" << std::endl;
}

int main()
{
	std::unordered_set<std::string> s;

	s.insert("hi");
	s.insert("my");
	s.insert("name");
	s.insert("is");
	s.insert("psi");
	s.insert("welcome");
	s.insert("to");
	s.insert("c++");

	print_undordered_set(s);
	std::cout << "----------------------" << std::endl;
	is_exist(s, std::string("c++"));
	is_exist(s, std::string("c"));

	std::cout << "----------------------" << std::endl;
	std::cout << "'hi' 를 삭제" << std::endl;
	s.erase(s.find("hi"));
	is_exist(s, std::string("hi"));

	return 0;
}