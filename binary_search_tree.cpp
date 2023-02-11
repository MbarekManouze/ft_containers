/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:30:23 by mmanouze          #+#    #+#             */
/*   Updated: 2023/02/10 18:10:32 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.hpp"

 
 
int main(){
	BST<int> chajara ,*root;

	root = NULL;
	root = chajara.insertnode(root, 20);

	chajara.insertnode(root, 3);
	chajara.insertnode(root, 30);
	chajara.insertnode(root, 11);
	chajara.insertnode(root, 25);
	chajara.insertnode(root, 15);
	chajara.insertnode(root, 55);
	chajara.insertnode(root, 0);
	chajara.insertnode(root, 1);
	chajara.insertnode(root, 9);
	chajara.insertnode(root, 19);
	chajara.insertnode(root, 18);
	chajara.insertnode(root, 17);
	chajara.insertnode(root, 16);
	chajara.insertnode(root, 13);
	chajara.insertnode(root, 12);
	chajara.insertnode(root, 10);
	chajara.insertnode(root, 10);



	chajara.printTree(root, nullptr, false);

	return (0);
}