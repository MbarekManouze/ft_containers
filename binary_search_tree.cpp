/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search_tree.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:30:23 by mmanouze          #+#    #+#             */
/*   Updated: 2023/02/18 21:20:17 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.hpp"

 
 
int main(){
	BST<int> chajara ,*root;

	root = NULL;
	root = chajara.InsertNode(root, 20);
	chajara.InsertNode(root, 3);
	chajara.InsertNode(root, 30);
	chajara.InsertNode(root, 11);
	chajara.InsertNode(root, 25);
	chajara.InsertNode(root, 15);
	chajara.InsertNode(root, 55);
	chajara.InsertNode(root, 0);
	chajara.InsertNode(root, 1);
	chajara.InsertNode(root, 9);
	chajara.InsertNode(root, 19);
	chajara.InsertNode(root, 18);
	chajara.InsertNode(root, 17);
	chajara.InsertNode(root, 16);
	chajara.InsertNode(root, 13);
	chajara.InsertNode(root, 12);
	chajara.InsertNode(root, 10);
	chajara.InsertNode(root, 2000);
	chajara.InsertNode(root, 3000);
	chajara.InsertNode(root, 4000);
	chajara.InsertNode(root, 5000);

	chajara.printTree(root, nullptr, false);

	//chajara.DeleteNode(root, 2000);
	//chajara.DeleteNode(root, 20);
	chajara.DeleteNode(root, 11);
	chajara.DeleteNode(root, 12);
	chajara.DeleteNode(root, 13);
	chajara.DeleteNode(root, 15);
	chajara.DeleteNode(root, 16);


	chajara.printTree(root, nullptr, false);

	return (0);
}