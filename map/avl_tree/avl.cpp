/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:54:13 by mmanouze          #+#    #+#             */
/*   Updated: 2023/02/21 13:24:58 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl_tree.hpp"
#include "../pair/pair.hpp"
#include <map>

void ft_test()
{
  Tree<int, int> t;

  // Test case 1: Insert elements into the tree
  t.insert(t.root, pair<int, int>(5, 99), NULL);
  t.insert(t.root, pair<int, int>(3, 20), NULL);
  t.insert(t.root, pair<int, int>(1, 30), NULL);
  t.insert(t.root, pair<int, int>(4, 30), NULL);
  //t.insert(t.root, pair<int, int>(5, 30), NULL);
  t.insert(t.root, pair<int, int>(6, 30), NULL);
  t.insert(t.root, pair<int, int>(8, 30), NULL);
  t.insert(t.root, pair<int, int>(7, 66), NULL);
  t.insert(t.root, pair<int, int>(10, 4), NULL);
  t.insert(t.root, pair<int, int>(0, 30), NULL);
  t.insert(t.root, pair<int, int>(11, 30), NULL);
  t.insert(t.root, pair<int, int>(20, 30), NULL);


  //t.DeleteNode(t.root, 5);
  //t.DeleteNode(t.root, 6);
  //t.DeleteNode(t.root, 4);
  t.printTree(t.root, nullptr, false);
  std::cout << t.I_wanna_know_my_parent(t.root, 11)->data.first << std::endl;
  std::cout << t.root->right->data.second << std::endl;
  std::cout << t.root->left->parent->data.first << std::endl;

  //std::map<int , int> mp;
  //mp.insert(std::pair<int, int>(3, 3));
  //mp.insert(std::pair<int, int>(4, 4));
  //mp.insert(std::pair<int, int>(5, 5));
  //mp.insert(std::pair<int, int>(1, 1));
  //mp.insert(std::pair<int, int>(6, 6));
  //mp.insert(std::pair<int, int>(7, 7));
  //mp.insert(std::pair<int, int>(8, 8));
  //mp.insert(std::pair<int, int>(9, 9));

  //mp.erase(1);

  //std::map<int, int>::iterator it = mp.begin();  
  //std::cout << it->first << std::endl;
}

int main() {
  ft_test();

  //system("leaks a.out");
}