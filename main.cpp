/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:17:54 by mmanouze          #+#    #+#             */
/*   Updated: 2023/02/02 11:36:03 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Vector/vector.hpp"
#include"./iterators/reverse_Iterator.hpp"
#include"./iterators/Iterator.hpp"
int main ()
{
//   ft_();
  vector<int> vec;
  vec.push_back(22);
  vec.push_back(66);
  vec.push_back(11);
  vec.push_back(33);
  
  vector<int>::iterator itbegin = vec.begin();
  vector<int>::iterator itend = vec.end();  
  Reverse_Iterator<vector<int>::iterator> revitb(itend);
  Reverse_Iterator<vector<int>::iterator> revite(itbegin);
  while (revitb != revite)
  {
    std::cout << *revitb++ << std::endl;
    // revitb++;
  }
  // system("leaks a.out");
  return 0;
}