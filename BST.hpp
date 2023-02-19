/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:30:53 by mmanouze          #+#    #+#             */
/*   Updated: 2023/02/18 21:16:50 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
# define BST_HPP


#include <iostream>
#include <new>
//#include "tree.hpp"

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
			else 
			{
				int lheight = height(node->left);
				int rheight = height(node->right);
				if (lheight > rheight)
					return (lheight + 1);
				else
					return (rheight + 1);
			}
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

		BST * InsertNode(BST* &root, T data)
		{
			if (root == NULL)
			{
				root = new BST(data);
				return (root);
			}
			if (data < root->data)
				root->left = InsertNode(root->left, data);
			if (data > root->data)
				root->right = InsertNode(root->right, data);
			else if (data == root->data)
			{
				std::cout << "NO DUPLICATE VALUES" << std::endl;
				return (root);
			}
			int balance_f = Balancefactor(root);
			if (balance_f > 1 && (data < root->left->data))
			{
				std::cout << "right\n";
				root =  Rightrotation(root);
				return (root);
			}
			if (balance_f < -1 && (data > root->right->data))
			{
				std::cout << "left\n";
				root =  Leftrotation(root);
				return (root);
			}
			if (balance_f > 1 && (data > root->left->data))
			{
				std::cout << "left right\n";
				std::cout << balance_f << std::endl;
				std::cout << "root : " << root->data << std::endl; 
				root->left = Leftrotation(root->left);
				std::cout << root->data << std::endl;
				root = Rightrotation(root);
				std::cout << root->data << std::endl;
				return (root);
			}
			if (balance_f < -1 && (data < root->right->data))
			{
				std::cout << "right left\n";
				root->right = Rightrotation(root->right);
				root = Leftrotation(root);
				return (root);
			}
			return (root);
		}

		/////////////////////////////////////////////////


		BST* DeleteNode(BST *root, T data)
		{
			if (root == NULL)
				return (root);
			else if (data < root->data)
				root->left = DeleteNode(root->left, data);
			else if (data > root->data)
				root->right = DeleteNode(root->right, data);
			else
			{
				if (root->left == NULL)
				{
					BST* temp = root->right;
					delete root;
					return (temp);
				}
				else if (root->right == NULL)
				{
					BST* temp = root->left;
					delete root;
					return (temp);
				}
				else
				{
					BST* temp = minValueNode(root->right);
					root->data = temp->data;
					root->right = DeleteNode(root->right, temp->data);
				}
			}
			int balance_f = Balancefactor(root);
			if ((balance_f == 2) && Balancefactor(root->left) >= 0)
				return (Rightrotation(root));
			else if ((balance_f == 2) && Balancefactor(root->left) == -1)
			{
				root->left = Leftrotation(root->left);
				return (Rightrotation(root));
			}
			else if ((balance_f == -2) && Balancefactor(root->right) <= 0)
				return (Leftrotation(root));
			else if ((balance_f == -2) && Balancefactor(root->right) == 1)
			{
				root->right = Rightrotation(root->right);
				return (Leftrotation(root));
			} 
			return (root);
		}


		/////////////////////////////////////////////////


		BST * minValueNode(BST * node) {
			BST * current = node;
			/* loop down to find the leftmost leaf */
			while (current -> left != NULL) {
			current = current -> left;
			}
			return current;
		}


		/////////////////////////////////////////////////



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


		/////////////////////////////////////////////

	private :
		//B *root;
		BST *left;
		BST *right;
		T 	data;
};

//template <typename T>
//subtree<T>* new_node(T data)
//{
//	return (subtree())
//}


//template <class T>
//class BST{
//	public :
//		BST():left(NULL), right(NULL){}
//		BST(T arg):data(arg), left(NULL), right(NULL){}
//		~BST(){}

//		//bool isempty(){
//		//	if (root == NULL)
//		//		return (true);
//		//	else
//		//		return (false);
//		//}
		
//		int height(BST *node)
//		{
//			if (node == NULL)
//				return (-1);
//			int lheight = height(node->left);
//			int rheight = height(node->right);
//			if (lheight > rheight)
//				return (lheight + 1);
//			else
//				return (rheight + 1);
//		}

//		int Balancefactor(BST *node)
//		{
//			if (node == NULL)
//				return (-1);
//			return (height(node->left) - height(node->right));
//		}

//		BST *Rightrotation(BST *y)
//		{
//			BST *x = y->left;
//			BST *z = x->right;

//			x->right = y;
//			y->left = z;

//			return(x);
//		}

//		BST *Leftrotation(BST *x)
//		{
//			BST *y = x->right;
//			BST *z = y->left;

//			y->left = x;
//			x->right = z;

//			return (y);
//		}

//		BST* InsertNode(BST *root, T data)
//		{
//			if (root == NULL)
//			{
//				root = new BST<T>(data);
//				return (root);
//			}
//			if (data < root->data)
//				root->left = InsertNode(root->left, data);
//			if (data > root->data)
//				root->right = InsertNode(root->right, data);
//			else if (data == root->data)
//			{
//				std::cout << "NO DUPLICATE VALUES" << std::endl;
//				return (root);
//			}
//			int balance_f = Balancefactor(root);
//			if (balance_f > 1 && (data < root->left->data))
//				return Rightrotation(root);
//			if (balance_f < -1 && (data > root->right->data))
//				return Leftrotation(root);
//			if (balance_f > 1 && (data < root->left->data))
//			{
//				root->left = Leftrotation(root->left);
//				return Rightrotation(root);
//			}
//			if (balance_f < -1 && (data < root->right->data))
//			{
//				root->right = Rightrotation(root->right);
//				return Leftrotation(root);
//			}
//			return (root);
//		}


//		/////////////////////////////////////////////////


//		BST* DeleteNode(BST *root, T data)
//		{
//			if (root == NULL)
//				return (root);
//			else if (data < root->data)
//				root->left = DeleteNode(root->left, data);
//			else if (data > root->data)
//				root->right = DeleteNode(root->right, data);
//			else
//			{
//				if (root->left == NULL)
//				{
//					BST* temp = root->right;
//					delete root;
//					return (temp);
//				}
//				else if (root->right == NULL)
//				{
//					BST* temp = root->left;
//					delete root;
//					return (temp);
//				}
//				else
//				{
//					BST* temp = minValueNode(root->right);
//					root->data = temp->data;
//					root->right = DeleteNode(root->right, temp->data);
//				}
//			}
//			int balance_f = Balancefactor(root);
//			if ((balance_f == 2) && Balancefactor(root->left) >= 0)
//				return (Rightrotation(root));
//			else if ((balance_f == 2) && Balancefactor(root->left) == -1)
//			{
//				root->left = Leftrotation(root->left);
//				return (Rightrotation(root));
//			}
//			else if ((balance_f == -2) && Balancefactor(root->right) <= 0)
//				return (Leftrotation(root));
//			else if ((balance_f == -2) && Balancefactor(root->right) == 1)
//			{
//				root->right = Rightrotation(root->right);
//				return (Leftrotation(root));
//			} 
//			return (root);
//		}


//		/////////////////////////////////////////////////


//		BST * minValueNode(BST * node) {
//			BST * current = node;
//			/* loop down to find the leftmost leaf */
//			while (current -> left != NULL) {
//			current = current -> left;
//			}
//			return current;
//		}


//		/////////////////////////////////////////////////



//		struct Trunk
//		{
//			Trunk *prev;
//			std::string str;
		
//			Trunk(Trunk *prev, std::string str)
//			{
//				this->prev = prev;
//				this->str = str;
//			}
//		};
		
//		// Helper function to print branches of the binary BST
//		void showTrunks(Trunk *p)
//		{
//			if (p == nullptr) {
//				return;
//			}
		
//			showTrunks(p->prev);
//			std::cout << p->str;
//		}

//		void printTree(BST* root, Trunk *prev, bool isLeft)
//		{
//			if (root == nullptr) {
//				return;
//			}
		
//			std::string prev_str = "    ";
//			Trunk *trunk = new Trunk(prev, prev_str);
		
//			printTree(root->right, trunk, true);
		
//			if (!prev) {
//				trunk->str = "———";
//			}
//			else if (isLeft)
//			{
//				trunk->str = ".———";
//				prev_str = "   |";
//			}
//			else {
//				trunk->str = "`———";
//				prev->str = prev_str;
//			}
		
//			showTrunks(trunk);
//			std::cout << " " << root->data << std::endl;
		
//			if (prev) {
//				prev->str = prev_str;
//			}
//			trunk->str = "   |";
		
//			printTree(root->left, trunk, false);
//		}


//		/////////////////////////////////////////////

//	private :
//		BST *left;
//		BST *right;
//		T 	data;
//};


#endif