#include "pch.h"
#include <string>
#include <iostream>
#include "TMP.h"

int main()
{
	std::cout << "6! = 1*2*3*4*5*6 = " << Factorial<6>::result << std::endl;

	return 0;
}