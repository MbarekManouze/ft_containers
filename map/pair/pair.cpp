/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:07:51 by mmanouze          #+#    #+#             */
/*   Updated: 2023/02/15 18:11:15 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair.hpp"

int main() {
	pair<int, double> p1(1, 3.14);
	pair<int, double> p2(2, 6.28);

	std::cout << "p1: " << p1.first << ", " << p1.second << std::endl;
	std::cout << "p2: " << p2.first << ", " << p2.second << std::endl;

	pair<int, double> p3 = make_pair(3, 9.42);
	std::cout << "p3: " << p3.first << ", " << p3.second << std::endl;

	return 0;
}
