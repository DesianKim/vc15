#include "pch.h"
#include <string>
#include <iostream>

template <typename _Ty>
class Vector
{
public:
	Vector(size_t size)
		: size_(size)
	{
		data_ = new _Ty[size_];
		for (int32_t i = 0; i < size_; ++i)
			data_[i] = 3;
	}

	virtual ~Vector()
	{
		if (data_ != nullptr)
		{
			delete[] data_;
			data_ = nullptr;
		}
	}

	const _Ty& at(size_t index) const
	{
		if (index >= size_)
			throw std::out_of_range("vector 의 index 가 범위를 초과하였습니다.");
		return data_[index];
	}

private:
	_Ty* data_;
	size_t size_;
};// class Vector

int main()
{
	Vector<int32_t> vec(3);
	
	int32_t index, data = 0;
	std::cin >> index;

	try
	{
		data = vec.at(index);
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "예외 발생 ! " << e.what() << std::endl;
	}

	std::cout << "읽은 데이터 : " << data << std::endl;

	return 0;
}