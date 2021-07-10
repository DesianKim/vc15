#include "pch.h"
#include <iostream>
#include <string>
#include <set>

template <class _Ty>
void print_set(const std::set<_Ty>& s)
{
	for (const auto& elem : s)
		std::cout << elem << std::endl;
}

class Todo
{
public:
	Todo(int32_t nPriority, std::string sJob_desc)
		: m_nPriority(nPriority),
		m_sJob_desc(sJob_desc)
	{
	}

	virtual ~Todo()
	{
	}

public:
	bool operator<(const Todo& rhs) const
	{
		if (m_nPriority == rhs.m_nPriority)
			return m_sJob_desc < rhs.m_sJob_desc;
		return m_nPriority > rhs.m_nPriority;
	}

	friend std::ostream& operator<<(std::ostream& o, const Todo& td);

private:
	int32_t m_nPriority;
	std::string m_sJob_desc;
};

std::ostream& operator<<(std::ostream& o, const Todo& td)
{
	o << "[ 중요도: " << td.m_nPriority << "] " << td.m_sJob_desc;
	return o;
}

int main()
{
	std::set<Todo> todos;

	todos.insert(Todo(1, "농구 하기"));
	todos.insert(Todo(2, "수학 숙제 하기"));
	todos.insert(Todo(1, "프로그래밍 프로젝트"));
	todos.insert(Todo(3, "친구 만나기"));
	todos.insert(Todo(2, "영화 보기"));

	print_set(todos);

	std::cout << "-------------" << std::endl;
	std::cout << "숙제를 끝냈다면!" << std::endl;
	todos.erase(todos.find(Todo(2, "수학 숙제 하기")));
	print_set(todos);

	return 0;
}