/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:56:22 by mmanouze          #+#    #+#             */
/*   Updated: 2023/03/01 20:29:28 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <map>
#include <iterator>     // std::advance
void ft_test()
{
	ft::map<int , std::string> mp;

	mp.insert(ft::pair<int, std::string>(5, "mbarek"));
	mp.insert(ft::pair<int, std::string>(10, "basket"));
	mp.insert(ft::pair<int, std::string>(20, "ball"));
	mp.insert(ft::pair<int, std::string>(9, "school"));
	mp.insert(ft::pair<int, std::string>(8, "1337"));
	mp.insert(ft::pair<int, std::string>(7, "UM6P"));
	mp.insert(ft::pair<int, std::string>(0, "benguerir"));
	mp.insert(ft::pair<int, std::string>(-1, "agadir"));
	mp.insert(ft::pair<int, std::string>(11, "morocco"));
	mp.insert(ft::pair<int, std::string>(15, "coding"));
	mp.insert(ft::pair<int, std::string>(44, "debuging"));
	mp.insert(ft::pair<int, std::string>(-2, "solving"));
	mp.insert(ft::pair<int, std::string>(-3, "solved"));

	//mp.erase(mp.begin(), mp.end());
	//ft::map<int, std::string>::iterator it = mp.begin();
	//ft::map<int, std::string>::iterator ite = mp.end();

	//mp.erase(it);

	//mp.print_my_map();
	////it++;
	////ite--;
	////std::cout << ite->first << std::endl;
	////std::cout << ite->second << std::endl;
	//ite--;
	//while (it != ite)
	//{
	//	std::cout << it->first << " "<< std::endl;
	//	it++;
	//}

	//std::map<int , std::string> mp;

	//mp.insert(std::pair<int, std::string>(5, "mbarek"));
	//mp.insert(std::pair<int, std::string>(10, "basket"));
	//mp.insert(std::pair<int, std::string>(20, "ball"));
	//mp.insert(std::pair<int, std::string>(9, "school"));
	//mp.insert(std::pair<int, std::string>(8, "1337"));
	//mp.insert(std::pair<int, std::string>(7, "UM6P"));
	//mp.insert(std::pair<int, std::string>(0, "benguerir"));
	//mp.insert(std::pair<int, std::string>(-1, "agadir"));
	//mp.insert(std::pair<int, std::string>(11, "morocco"));
	//mp.insert(std::pair<int, std::string>(15, "coding"));
	//mp.insert(std::pair<int, std::string>(44, "debuging"));
	//mp.insert(std::pair<int, std::string>(-2, "solving"));


	//std::map<int, std::string>::reverse_iterator it = mp.rbegin();
	//std::map<int, std::string>::reverse_iterator ite = mp.rend();

	////mp.print_my_map();


	////mp.print_my_map();
	////it++;
	//ite--;
	////std::cout << ite->first;
	//while (it != ite)
	//{
	//	std::cout << ite->first << std::endl;
	//	ite--;
	//}
}

int main()
{
	ft_test();

	system("leaks a.out");

	return (0);
}