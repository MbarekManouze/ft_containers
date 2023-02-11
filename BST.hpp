/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:30:53 by mmanouze          #+#    #+#             */
/*   Updated: 2023/02/10 18:10:27 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
# define BST_HPP


#include <iostream>
#include <new>
#include "tree.hpp"


template <class T>
class BST{
	public :
		BST():left(NULL), right(NULL){}
		BST(T arg):data(arg), left(NULL), right(NULL){}
		~BST(){}

		//bool isempty(){
		//	if (root == NULL)
		//		return (true);
		//	else
		//		return (false);
		//}
		
		int height(BST *node)
		{
			if (node == NULL)
				return (-1);
			int lheight = height(node->left);
			int rheight = height(node->right);
			if (lheight > rheight)
				return (lheight + 1);
			else
				return (rheight + 1);
		}

		int Balancefactor(BST *node)
		{
			if (node == NULL)
				return (-1);
			return (height(node->left) - height(node->right));
		}

		BST *Rightrotation(BST *y)
		{
			BST *x = y->left;
			BST *z = x->right;

			x->right = y;
			y->left = z;

			return(x);
		}

		BST *Leftrotation(BST *x)
		{
			BST *y = x->right;
			BST *z = y->left;

			y->left = x;
			x->right = z;

			return (y);
		}

		BST* insertnode(BST *root, T data)
		{
			if (root == NULL)
			{
				root = new BST<T>(data);
				return (root);
			}
			if (data < root->data)
				root->left = insertnode(root->left, data);
			if (data > root->data)
				root->right = insertnode(root->right, data);
			else if (data == root->data)
			{
				std::cout << "NO DUPLICATE VALUES" << std::endl;
				return (root);
			}
			int balance_f = Balancefactor(root);
			if (balance_f > 1 && (data < root->left->data))
				return Rightrotation(root);
			if (balance_f < -1 && (data > root->right->data))
				return Leftrotation(root);
			if (balance_f > 1 && (data < root->left->data))
			{
				root->left = Leftrotation(root->left);
				return Rightrotation(root);
			}
			if (balance_f < -1 && (data < root->right->data))
			{
				root->right = Rightrotation(root->right);
				return Leftrotation(root);
			}
			return (root);
		}

		struct Trunk
		{
			Trunk *prev;
			std::string str;
		
			Trunk(Trunk *prev, std::string str)
			{
				this->prev = prev;
				this->str = str;
			}
		};
		
		// Helper function to print branches of the binary BST
		void showTrunks(Trunk *p)
		{
			if (p == nullptr) {
				return;
			}
		
			showTrunks(p->prev);
			std::cout << p->str;
		}

		void printTree(BST* root, Trunk *prev, bool isLeft)
		{
			if (root == nullptr) {
				return;
			}
		
			std::string prev_str = "    ";
			Trunk *trunk = new Trunk(prev, prev_str);
		
			printTree(root->right, trunk, true);
		
			if (!prev) {
				trunk->str = "———";
			}
			else if (isLeft)
			{
				trunk->str = ".———";
				prev_str = "   |";
			}
			else {
				trunk->str = "`———";
				prev->str = prev_str;
			}
		
			showTrunks(trunk);
			std::cout << " " << root->data << std::endl;
		
			if (prev) {
				prev->str = prev_str;
			}
			trunk->str = "   |";
		
			printTree(root->left, trunk, false);
		}

	private :
		BST *left;
		BST *right;
		T 	data;
};


#endif