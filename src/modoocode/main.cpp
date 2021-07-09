#include "pch.h"
#include <iostream>
#include <list>

template <typename T>
void print_list(const std::list<T>& lst)
{
	std::cout << "[ ";
	for (const std::list<T>::value_type& elem : lst)
		std::cout << elem << " ";
	std::cout << "]" << std::endl;
}

int main()
{
	std::list<int32_t> lst;

	lst.emplace_back(10);
	lst.emplace_back(20);
	lst.emplace_back(30);
	lst.emplace_back(40);

	std::cout << "처음 리스트의 상태 " << std::endl;
	print_list(lst);

	using itr_t = std::list<int32_t>::iterator;
	for (itr_t itr = lst.begin(); itr != lst.end(); ++itr)
	{
		if (*itr == 20)
			lst.insert(itr, 50);
	}
	
	std::cout << "값이 20 인 원소 앞에 50 을 추가 " << std::endl;
	print_list(lst);

	for (itr_t itr = lst.begin(); itr != lst.end(); ++itr)
	{
		if (*itr == 30)
		{
			lst.erase(itr);
			break;
		}
	}

	std::cout << "값이 30 인 원소 를 제거한다 " << std::endl;
	print_list(lst);

	return 0;
}