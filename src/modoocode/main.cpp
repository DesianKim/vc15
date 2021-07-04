#include "pch.h"
#include <string>
#include <iostream>
#include "TMP.h"
#include "Ratio.h"

int main()
{
	using r1 = Ratio<2, 3>;
	using r2 = Ratio<3, 2>;
	using r3 = Ratio_add<r1, r2>;
	std::cout << "2/3 + 3/2 = " << r3::num << " / " << r3::den << std::endl;

	using r4 = Ratio_multiply<r1, r3>;
	std::cout << "13 / 6 * 2 / 3 = " << r4::num << " / " << r4::den << std::endl;

	return 0;
}