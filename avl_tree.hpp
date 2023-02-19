/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:36:24 by mmanouze          #+#    #+#             */
/*   Updated: 2023/02/19 16:12:08 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP


#include <iostream>
#include "pair.hpp"


//template <class Key, class T, class Val, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
//class Tree {
//  public:
//    struct Node {
//      Val data;
//      Node* left;
//      Node* right;

//      //Node():data.first(NULL){}
//      Node(const pair<const Key, T>& data) : data(data), left(nullptr), right(nullptr) {}
//    };
//    Alloc alloc_pair;
//    typedef typename Alloc::template rebind<Node>::other rebind_alloc;
//    rebind_alloc alloc_node;
//    Tree() : root(nullptr), alloc() {}

//    Node *insert(Node *root, const pair<const Key, T>& value) {
//      if (root == NULL) {
//        Node *new_node = alloc_node.allocate(1);
//        alloc_node.construct(new_node, Node(value));
//        //new_node->data = alloc_pair.allocate(1);
//        //alloc_pair.construct(new_node->data, value);
//        root = new_node;
//        std::cout << root->data.first << std::endl;
//        //return root;
//      }
//      //std::cout << "hahahaha\n";
//      std::cout<<value.first<<std::endl;
//      if (value.first < root->data.first) {
//        root->left = insert(root->left, value);
//      } else if (value.first > root->data.first) {
//        root->right = insert(root->right, value);
//      }
//			else if (value.first == root->data.first)
//			{
//				std::cout << "NO DUPLICATE VALUES" << std::endl;
//				return (root);
//			}
//			//int balance_f = Balancefactor(root);
//			//if (balance_f > 1 && (value.first < root->left->data.first))
//			//	return Rightrotation(root);
//			//if (balance_f < -1 && (value.first > root->right->data.first))
//			//	return Leftrotation(root);
//			//if (balance_f > 1 && (value.first < root->left->data.first))
//			//{
//			//	root->left = Leftrotation(root->left);
//			//	return Rightrotation(root);
//			//}
//			//if (balance_f < -1 && (value.first < root->right->data.first))
//			//{
//			//	root->right = Rightrotation(root->right);
//			//	return Leftrotation(root);
//			//}
//			return (root);
//    }

//		int height(Node *node)
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

//		int Balancefactor(Node *node)
//		{
//			if (node == NULL)
//				return (-1);
//			return (height(node->left) - height(node->right));
//		}


//		Node *Rightrotation(Node *y)
//		{
//			Node *x = y->left;
//			Node *z = x->right;

//			x->right = y;
//			y->left = z;

//			return(x);
//		}

//		Node *Leftrotation(Node *x)
//		{
//			Node *y = x->right;
//			Node *z = y->left;

//			y->left = x;
//			x->right = z;

//			return (y);
//		}

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

//		void printTree(Node *root, Trunk *prev, bool isLeft)
//		{
//			if (root == nullptr) {
//				return;
//			}
//		std::cout << "hahahaha\n";
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
//			std::cout << " " << root->data.first << std::endl;
		
//			if (prev) {
//				prev->str = prev_str;
//			}
//			trunk->str = "   |";
		
//			printTree(root->left, trunk, false);
//		}

//    Node *root;
//  private:
//    rebind_alloc alloc;
//};





//#endif
template <class Key, class T,  class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
class Tree {
	public:
		struct Node {
		pair<const Key, T> data;
		Node* parent;
		Node* left;
		Node* right;

		Node(const pair<const Key, T>& data) : data(data), left(nullptr), right(nullptr) {}
		};

		//using node_allocator = std::allocator<Node>;
		//using rebind_alloc = typename node_allocator::template rebind<Node>::other;
		//using node_pointer = typename rebind_alloc::pointer;

		typedef std::allocator<Node>  node_allocator;
		typedef typename node_allocator::template rebind<Node>::other rebind_alloc;
		typedef typename rebind_alloc::pointer node_pointer;

		Tree() : root(nullptr), alloc() {}

		Node*	set_previous_parent(Node* leaf, Node* previous)
		{
			if (previous == NULL)
				return (NULL);
			else{
				leaf->parent = alloc.allocate(1);
				alloc.construct(leaf->parent, previous->data);
			}
			return (nullptr);
		}

		Node*	insert(Node* &root, const pair<const Key, T>& value, Node* previous)
		{
			if (!root) {
				root = alloc.allocate(1);
				alloc.construct(root, value);
				root->parent = NULL;
				set_previous_parent(root, previous);
				return root;
			}
			if (value.first < root->data.first)
			{
				root->left = insert(root->left, value, root);
			}
			else if (value.first > root->data.first)
			{
				root->right = insert(root->right, value, root);
			}
			else
				return (root);
			int balance_f = Balancefactor(root);
			if (balance_f > 1 && (value.first < root->left->data.first))
			{
				root = Rightrotation(root);
				return (root);
			}
			if (balance_f < -1 && (value.first > root->right->data.first))
			{
				root =  Leftrotation(root);
				return (root);
			}
			if (balance_f > 1 && (value.first < root->left->data.first))
			{
				root->left = Leftrotation(root->left);
				root =  Rightrotation(root);
				return (root);
			}
			if (balance_f < -1 && (value.first < root->right->data.first))
			{
				root->right = Rightrotation(root->right);
				root = Leftrotation(root);
				return (root);
			}
			return (root);
		}

		int height(Node* node)
		{
			if (node == NULL)
				return (-1);
			else {
				int lheight = height(node->left);
				int rheight = height(node->right);
				if (lheight > rheight)
					return (lheight + 1);
				else
					return (rheight + 1);
			}
		}

		int Balancefactor(Node* node)
		{
			if (node == NULL)
				return (-1);
			return (height(node->left) - height(node->right));
		}


		Node* Rightrotation(Node* y)
		{
			Node* x = y->left;
			Node* z = x->right;

			x->right = y;
			y->left = z;

			// y parent is x;
			std::cout << "right\n";
			std::cout << y->data.first << std::endl;
			std::cout << x->data.first << std::endl;
			if (z)
				std::cout << z->data.first << std::endl;

			if (y->left)
			{
				alloc.deallocate(y->left->parent, 1);
				y->left->parent = alloc.allocate(1);
				alloc.construct(y->left->parent, y->data);
			}

			alloc.deallocate(x->parent, 1);
			x->parent = NULL;
			if (y->parent != NULL)
			{
				x->parent = alloc.allocate(1);
				alloc.construct(x->parent, y->data);
			}
			if (y->parent)
				alloc.deallocate(y->parent, 1);
			y->parent = alloc.allocate(1);
			alloc.construct(y->parent, x->data);
			
			return(x);
		}

		Node* Leftrotation(Node* x)
		{
			Node* y = x->right;
			Node* z = y->left;

			y->left = x;
			x->right = z;

			//x parent is  y
			std::cout << "left\n";

			std::cout << x->data.first << std::endl;
			std::cout << y->data.first << std::endl;
			if (z)
				std::cout << z->data.first << std::endl;

			if (x->right)
			{
				alloc.deallocate(x->right->parent, 1);
				x->right->parent = alloc.allocate(1);
				alloc.construct(x->right->parent, x->data);
			}

			alloc.deallocate(y->parent, 1);
			y->parent = NULL;
			if (x->parent != NULL)
			{
				y->parent = alloc.allocate(1);
				alloc.construct(y->parent, x->data);
			}
			if (x->parent)
				alloc.deallocate(x->parent, 1);
			x->parent = alloc.allocate(1);
			alloc.construct(x->parent, y->data);

			return (y);
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

		void printTree(Node* root, Trunk *prev, bool isLeft)
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
			std::cout << " " << root->data.first << std::endl;
		
			if (prev) {
				prev->str = prev_str;
			}
			trunk->str = "   |";
		
			printTree(root->left, trunk, false);
		}

		Node* root;
	private:
		rebind_alloc alloc;
		Node*		 previous_node;
};





#endif