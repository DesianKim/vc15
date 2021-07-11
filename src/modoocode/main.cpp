#include "pch.h"
#include <iostream>
#include <string>
#include <map>

template <class _Kty, class _Ty>
void print_map(const std::map<_Kty, _Ty>& m)
{
	using citr = std::map<_Kty, _Ty>::const_iterator;
	for (citr itr = m.cbegin(); itr != m.cend(); ++itr)
		std::cout << itr->first << " " << itr->second << std::endl;
}

template <class _Kty, class _Ty>
void search_and_print(const std::map<_Kty, _Ty>& m, _Kty key)
{
	std::map<_Kty, _Ty>::const_iterator itr= m.find(key);
	if (itr != m.end())
		std::cout << key << " --> " << itr->second << std::endl;
	else
		std::cout << key << "은(는) 목록에 없습니다" << std::endl;
}

int main()
{
	std::map<std::string, double> pitcher_list;

	pitcher_list.insert(std::pair<std::string, double>("박세웅", 2.23));
	pitcher_list.insert(std::pair<std::string, double>("해커", 2.93));
	pitcher_list.insert(std::pair<std::string, double>("피어밴드", 2.95));

	pitcher_list.insert(std::make_pair("차우찬", 3.04));
	pitcher_list.insert(std::make_pair("장원준", 3.05));
	pitcher_list.insert(std::make_pair("핵터", 3.09));

	pitcher_list["니퍼트"] = 3.56;
	pitcher_list["박종훈"] = 3.76;
	pitcher_list["켈리"] = 3.90;

	print_map(pitcher_list);

	std::cout << "박세웅 방어율은? :: " << pitcher_list["박세웅"] << std::endl;

	search_and_print(pitcher_list, std::string("차우찬"));
	search_and_print(pitcher_list, std::string("류현진"));

	return 0;
}