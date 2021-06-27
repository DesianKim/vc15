#include "pch.h"
#include <string>
#include <iostream>
#include "9_1_Vector.h"
#include "FuncTemplate.h"

int main()
{
	Template::Vector<int32_t> int_vec;
	int_vec.push_back(3);
	int_vec.push_back(1);
	int_vec.push_back(2);
	int_vec.push_back(8);
	int_vec.push_back(5);
	int_vec.push_back(3);

	std::cout << "정렬 이전 ---- " << std::endl;
	for (int32_t i = 0; i < int_vec.size(); ++i)
		std::cout << int_vec[i] << " ";
	std::cout << std::endl;

	Comp1 comp1;
	bubble_sort(int_vec, comp1);

	std::cout << std::endl << "내림차순 정렬 이후 ---- " << std::endl;

	for (int32_t i = 0; i < int_vec.size(); ++i)
		std::cout << int_vec[i] << " ";
	std::cout << std::endl;

	Comp2 comp2;
	bubble_sort(int_vec, comp2);

	std::cout << std::endl << "오름차순 정렬 이후 ---- " << std::endl;

	for (int32_t i = 0; i < int_vec.size(); ++i)
		std::cout << int_vec[i] << " ";
	std::cout << std::endl;

	return 0;
}