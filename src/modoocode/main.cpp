#include "pch.h"
#include <string>
#include <iostream>
#include "9_1_Vector.h"
#include "FuncTemplate.h"
#include <array>

int main()
{
	int32_t a = 3, b = 4;
	std::cout << "Min " << a << " , " << b << " :: " << Min(a, b) << std::endl;

	std::string s1 = "abc", s2 = "def";
	std::cout << "Min " << s1 << " , " << s2 << " :: " << Min(s1, s2) << std::endl;

	return 0;
}