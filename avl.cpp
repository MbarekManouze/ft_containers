/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:54:13 by mmanouze          #+#    #+#             */
/*   Updated: 2023/02/19 17:59:24 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl_tree.hpp"
#include "pair.hpp"

void ft_test()
{
  Tree<int, int> t;

  // Test case 1: Insert elements into the tree
  t.insert(t.root, pair<int, int>(5, 10), NULL);
  t.insert(t.root, pair<int, int>(3, 20), NULL);
  t.insert(t.root, pair<int, int>(1, 30), NULL);
  t.insert(t.root, pair<int, int>(4, 30), NULL);
  //t.insert(t.root, pair<int, int>(5, 30), NULL);
  t.insert(t.root, pair<int, int>(6, 30), NULL);
  t.insert(t.root, pair<int, int>(8, 30), NULL);
  t.insert(t.root, pair<int, int>(7, 30), NULL);
  //t.insert(t.root, pair<int, int>(10, 30), NULL);
  //t.insert(t.root, pair<int, int>(0, 30), NULL);
  //t.insert(t.root, pair<int, int>(11, 30), NULL);
  //t.insert(t.root, pair<int, int>(20, 30), NULL);



  t.printTree(t.root, nullptr, false);
  std::cout << t.root->right->parent->data.first << std::endl;
  std::cout << t.root->left->parent->data.first << std::endl;
}

int main() {
  ft_test();

  //system("leaks a.out");
}