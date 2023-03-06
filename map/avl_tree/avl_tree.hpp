/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:36:24 by mmanouze          #+#    #+#             */
/*   Updated: 2023/03/05 21:07:20 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_TREE_HPP
# define AVL_TREE_HPP


#include <iostream>
#include "../pair/pair.hpp"

template <class Key, class T,  class Compare, class Alloc = std::allocator<ft::pair<const Key, T> > >
class Tree {
	public:
		struct Node {
			typedef	Key			key_type;
			typedef	T			mapped_type;
			typedef	Compare		cmp;
			ft::pair<const Key, T> *data;
			Node* left;
			Node* right;
			size_t height;

			Node():data(NULL), left(NULL), right(NULL), height(0){}
			Node(ft::pair<const Key, T> *data) : data(data), left(NULL), right(NULL) ,height(0){}
		};

		typedef typename Alloc::template rebind<Node>::other rebind_alloc;
		typedef typename rebind_alloc::pointer node_pointer;

		Tree() : root(NULL), _size(0) ,alloc(){}

		~Tree()
		{
		}

		size_t get_size() const { return (_size); }

		static ft::pair<Node*, Node*> 	smaller_root_pair(node_pointer node)
		{
			node_pointer rt = node;
			if (node == NULL)
				return (ft::pair<Node*, Node*>(NULL, NULL));
			else if (node->left)
			{
				node = node->left;
				while (node->left)
					node = node->left;
			}
			return (ft::pair<Node*, Node*>(rt, node));
		}

		static ft::pair<Node*, Node*> large_root_pair(node_pointer node)
		{
			node_pointer rt = node;
			if (node == NULL)
				return (ft::pair<Node*, Node*>(NULL, NULL));
			if (node->right)
			{
				node = node->right;
				while (node->right)
					node = node->right;
			}
			return (ft::pair<Node*, Node*>(rt, node));
		}

		node_pointer find_element(Key key, node_pointer root, node_pointer &node)
		{
			Compare cmp;
			if (!root)
				return (root);
			if (cmp(key , root->data->first))
				root->left = find_element(key, root->left, node);
			else if (cmp(root->data->first, key))
				root->right = find_element(key, root->right, node);
			else
			{
				node = root;
				return (root);
			}
			return (root);
		}

		node_pointer	insert(node_pointer &root, const ft::pair<const Key, T>& value, node_pointer &nd)
		{
			Compare cmp;

			if (!root) {
				root = alloc.allocate(1);
				ft::pair<const Key, T>* pr = pair_alloc.allocate(1);
				pair_alloc.construct(pr, ft::pair<Key, T>(value.first, value.second));
				alloc.construct(root, pr);
				_size++;
				nd = root;
				return root;
			}
			if (cmp(value.first , root->data->first))
			{
				root->left = insert(root->left, value, nd);
			}
			else if (cmp(root->data->first, value.first))
			{
				root->right = insert(root->right, value, nd);
			}
			else
			{
				nd = root;
				return (root);
			}
			if (height(root->left) > height(root->right))
				root->height = height(root->left) + 1;
			else if (height(root->left) < height(root->right))
				root->height = height(root->right) + 1;
			else
				root->height = height(root->left) + 1;
			int balance_f = Balancefactor(root);
			if (balance_f > 1 && (cmp(value.first, root->left->data->first)))
			{
				root = Rightrotation(root);
				return (root);
			}
			if (balance_f < -1 && (cmp(root->right->data->first, value.first)))
			{
				root =  Leftrotation(root);
				return (root);
			}
			if (balance_f > 1 && (cmp(value.first, root->left->data->first)))
			{
				root->left = Leftrotation(root->left);
				root =  Rightrotation(root);
				return (root);
			}
			if (balance_f < -1 && (cmp(root->right->data->first, value.first)))
			{
				root->right = Rightrotation(root->right);
				root = Leftrotation(root);
				return (root);
			}
			return (root);
		}

		static node_pointer I_wanna_know_my_parent(Node *root, Key key)
		{
			Compare cmp;
			if (root == NULL)
				return (NULL);
			node_pointer tmp = NULL;
			if (root->left != NULL && root->left->data->first == key)
				return (root);
			if (root->right != NULL && root->right->data->first == key)
				return (root);
			if (cmp(root->data->first, key ))
				tmp = I_wanna_know_my_parent(root->right, key);
			if (cmp(key , root->data->first))
				tmp = I_wanna_know_my_parent(root->left, key);
			return (tmp);
		}

		node_pointer DeleteNode(Node *&root, Key data, size_t &Q)
		{
			Compare cmp;
			if (root == NULL)
				return (root);
			else if (cmp(data , root->data->first))
				root->left = DeleteNode(root->left, data, Q);
			else if (cmp(root->data->first, data))
				root->right = DeleteNode(root->right, data, Q);
			else
			{
				if (root->left == NULL)
				{
					node_pointer temp = root->right;
					if (root)
					{
						pair_alloc.destroy(root->data);
						pair_alloc.deallocate(root->data, 1);
						alloc.destroy(root);
						alloc.deallocate(root, 1);
						_size--;
						Q = 1;
					}
					root = temp;
					return (temp);
				}
				else if (root->right == NULL)
				{
					node_pointer temp = root->left;
					if (root)
					{
						pair_alloc.destroy(root->data);
						pair_alloc.deallocate(root->data, 1);
						alloc.destroy(root);
						alloc.deallocate(root, 1);
						_size--;
						Q = 1;
					}
					root = temp;
					return (temp);
				}
				else
				{
					node_pointer temp = minValueNode(root->right);
					if (root->data)
			            pair_alloc.destroy(root->data);
					pair_alloc.construct(root->data, ft::make_pair(temp->data->first, temp->data->second));
					root->right = DeleteNode(root->right, temp->data->first, Q);
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
			while (current -> left != NULL) {
			current = current -> left;
			}
			return current;
		}

		size_t height(node_pointer node)
		{
			if (node == NULL)
				return (0);
			return (node->height);
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
			
			return(x);
		}

		node_pointer Leftrotation(node_pointer x)
		{
			node_pointer y = x->right;
			node_pointer z = y->left;

			y->left = x;
			x->right = z;

			return (y);
		}

		//--------------------PRINT TREE-------------------//

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
		
		void showTrunks(Trunk *p)
		{
			if (p == NULL) {
				return;
			}

			showTrunks(p->prev);
			std::cerr << p->str;
		}

		void printTree(node_pointer root, Trunk *prev, bool isLeft)
		{
			if (root == NULL) {
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
			std::cerr << " " << root->data->first << std::endl;
		
			if (prev) {
				prev->str = prev_str;
			}
			trunk->str = "   |";
		
			printTree(root->left, trunk, false);
		}

		node_pointer root;
	private:
		size_t 			_size;
		Alloc 			pair_alloc;
		rebind_alloc	alloc;
		node_pointer	previous_node;
};





#endif