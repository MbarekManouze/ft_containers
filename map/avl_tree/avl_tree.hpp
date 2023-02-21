/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:36:24 by mmanouze          #+#    #+#             */
/*   Updated: 2023/02/21 13:37:29 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP


#include <iostream>
#include "../pair/pair.hpp"

template <class Key, class T,  class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
class Tree {
	public:
		struct Node {
			typedef  Key key_type;
			typedef  T	type_mapped;
			pair<const Key, T> data;
			Node* parent;
			Node* left;
			Node* right;

			Node(const pair<const Key, T>& data) : data(data), left(nullptr), right(nullptr) {}
		};

		typedef std::allocator<Node>  node_allocator;
		typedef typename node_allocator::template rebind<Node>::other rebind_alloc;
		typedef typename rebind_alloc::pointer node_pointer;

		Tree() : root(nullptr), alloc() {}

		node_pointer	set_previous_parent(node_pointer leaf, node_pointer previous)
		{
			if (previous == NULL)
				return (NULL);
			else{
				leaf->parent = alloc.allocate(1);
				alloc.construct(leaf->parent, previous->data);
			}
			return (nullptr);
		}

		node_pointer	insert(node_pointer &root, const pair<const Key, T>& value, node_pointer previous)
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

		node_pointer I_wanna_know_my_parent(Node *root, Key key)
		{
			node_pointer tmp = root;
			if (root->left != NULL && root->left->data.first == key)
				return (root);
			if (root->right != NULL && root->right->data.first == key)
				return (root);
			if (key > root->data.first)
				tmp = I_wanna_know_my_parent(root->right, key);
			if (key < root->data.first)
				tmp = I_wanna_know_my_parent(root->left, key);
			return (tmp);
		}

		node_pointer DeleteNode(Node *&root, T data)
		{
			if (root == NULL)
				return (root);
			else if (data < root->data.first)
				root->left = DeleteNode(root->left, data);
			else if (data > root->data.first)
				root->right = DeleteNode(root->right, data);
			else
			{
				if (root->left == NULL)
				{
					node_pointer temp = root->right;
					alloc.deallocate(root, 1);
					//delete root;
					return (temp);
				}
				else if (root->right == NULL)
				{
					node_pointer temp = root->left;
					alloc.deallocate(root, 1);
					//delete root;
					return (temp);
				}
				else
				{
					node_pointer temp = minValueNode(root->right);
					root->data = temp->data;
					root->right = DeleteNode(root->right, temp->data.first);
				}
			}
			int balance_f = Balancefactor(root);
			if ((balance_f == 2) && Balancefactor(root->left) >= 0)
			{
				root = Rightrotation(root);
				return (root);
			}
			else if ((balance_f == 2) && Balancefactor(root->left) == -1)
			{
				root->left = Leftrotation(root->left);
				root = Rightrotation(root);
				return (root);
			}
			else if ((balance_f == -2) && Balancefactor(root->right) <= 0)
			{
				root = Leftrotation(root);
				return (root);
			}
			else if ((balance_f == -2) && Balancefactor(root->right) == 1)
			{
				root->right = Rightrotation(root->right);
				root = Leftrotation(root);
				return (root);
			} 
			return (root);
		}

		Node * minValueNode(Node * node) {
			Node * current = node;
			/* loop down to find the leftmost leaf */
			while (current -> left != NULL) {
			current = current -> left;
			}
			return current;
		}

		int height(node_pointer node)
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

		int Balancefactor(node_pointer node)
		{
			if (node == NULL)
				return (-1);
			return (height(node->left) - height(node->right));
		}


		node_pointer Rightrotation(node_pointer y)
		{
			node_pointer x = y->left;
			node_pointer z = x->right;

			x->right = y;
			y->left = z;

			// y parent is x;
			//std::cout << "right\n";
			//std::cout << y->data.first << std::endl;
			//std::cout << x->data.first << std::endl;
			//if (z)
			//	std::cout << z->data.first << std::endl;

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

		node_pointer Leftrotation(node_pointer x)
		{
			node_pointer y = x->right;
			node_pointer z = y->left;

			y->left = x;
			x->right = z;

			//x parent is  y
			//std::cout << "left\n";

			//std::cout << x->data.first << std::endl;
			//std::cout << y->data.first << std::endl;
			//if (z)
			//	std::cout << z->data.first << std::endl;

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
		
		// Helper function to print branches of the binary Node
		void showTrunks(Trunk *p)
		{
			if (p == nullptr) {
				return;
			}

			showTrunks(p->prev);
			std::cout << p->str;
		}

		void printTree(node_pointer root, Trunk *prev, bool isLeft)
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

		node_pointer root;
	private:
		rebind_alloc	alloc;
		node_pointer	previous_node;
};





#endif