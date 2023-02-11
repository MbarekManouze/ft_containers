/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:26:33 by mmanouze          #+#    #+#             */
/*   Updated: 2023/02/10 16:17:58 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

#include <iostream>
#include <new>
#include "BST.hpp"

template <class T>
class tree{
	public :
		typedef  	T 			value_type;
		typedef 	tree<T>		TREE;
		tree():data(0), left(NULL), right(NULL){}
		tree(value_type param):data(param), left(NULL), right(NULL){}
		~tree(){}
		//tree *insert(TREE *root, T data){
		//	if (!root)
		//		return new tree(data);
		//	if (data < root->data)
		//			root->left = insert(root->left, data);
		//	else
		//			root->right = insert(root->right, data);
		//	return (root);
		//}

		//void Inorder(tree* root)
		//{
		//	if (!root) {
		//		return;
		//	}
		//	Inorder(root->left);
		//	std::cout << root->data << std::endl;
		//	Inorder(root->right);
		//}
		//struct Trunk
		//{
		//	Trunk *prev;
		//	std::string str;
		
		//	Trunk(Trunk *prev, std::string str)
		//	{
		//		this->prev = prev;
		//		this->str = str;
		//	}
		//};
		
		//// Helper function to print branches of the binary tree
		//void showTrunks(Trunk *p)
		//{
		//	if (p == nullptr) {
		//		return;
		//	}
		
		//	showTrunks(p->prev);
		//	std::cout << p->str;
		//}

		//void printTree(tree* root, Trunk *prev, bool isLeft)
		//{
		//	if (root == nullptr) {
		//		return;
		//	}
		
		//	std::string prev_str = "    ";
		//	Trunk *trunk = new Trunk(prev, prev_str);
		
		//	printTree(root->right, trunk, true);
		
		//	if (!prev) {
		//		trunk->str = "———";
		//	}
		//	else if (isLeft)
		//	{
		//		trunk->str = ".———";
		//		prev_str = "   |";
		//	}
		//	else {
		//		trunk->str = "`———";
		//		prev->str = prev_str;
		//	}
		
		//	showTrunks(trunk);
		//	std::cout << " " << root->data << std::endl;
		
		//	if (prev) {
		//		prev->str = prev_str;
		//	}
		//	trunk->str = "   |";
		
		//	printTree(root->left, trunk, false);
		//}


	private:
		TREE *left;
		TREE *right;
		value_type data;
		static int num;
};




#endif