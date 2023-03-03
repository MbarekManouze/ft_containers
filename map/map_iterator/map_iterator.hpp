/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:53:31 by mmanouze          #+#    #+#             */
/*   Updated: 2023/03/02 11:13:27 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP


#include <iostream>
#include <vector>
#include "../pair/pair.hpp"
#include "../avl_tree/avl_tree.hpp"
#include "iterator_traits_map.hpp"


template <class Node>
class Map_Iterator {
	public :
		//typedef ft::pair< const typename Node::key_type,  typename Node::mapped_type>			value_type;
		//typedef std::bidirectional_iterator_tag 												iterator_category;
		//typedef std::ptrdiff_t 																	diffrence_type;
		//typedef value_type* 																	pointer;
		//typedef value_type&																		reference;
        typedef typename  iterator_traits_map<ft::pair< const typename Node::key_type,  typename Node::mapped_type>*>::value_type         							value_type;
        typedef typename  iterator_traits_map<ft::pair< const typename Node::key_type,  typename Node::mapped_type>*>::difference_type    							difference_type;
        typedef typename  iterator_traits_map<ft::pair< const typename Node::key_type,  typename Node::mapped_type>*>::pointer            							pointer;
        typedef typename  iterator_traits_map<ft::pair< const typename Node::key_type,  typename Node::mapped_type>*>::reference          							reference;
        typedef typename  iterator_traits_map<ft::pair< const typename Node::key_type,  typename Node::mapped_type>*>::iterator_category  							iterator_category;
		typedef Node* 																			node;

		Map_Iterator(){}
		Map_Iterator(node node): tree_branche(node){}
		Map_Iterator(node nd, node rt) :tree_branche(nd), root(rt){}
		Map_Iterator(const Map_Iterator& obj):tree_branche(obj.tree_branche), root(obj.root) {}
		Map_Iterator(const ft::pair<Node*, Node*>& pr)
		{
			root = pr.first;
			tree_branche = pr.second;
		}
		Map_Iterator& operator=(const Map_Iterator& obj)
		{
			tree_branche = obj.tree_branche;
			root = obj.root;
			return (*this);
		}
		//operator Map_Iterator<const Node>() const {return Map_Iterator<const Node>(tree_branche);}
        //operator Map_Iterator<const Node>() {return Map_Iterator<const Node>(tree_branche);}
		pointer operator->()  { return(tree_branche->data); }
		reference operator*() const { return(*tree_branche->data); }
		bool operator!=(const Map_Iterator& other) const
		{ 
			//if (tree_branche == NULL && other.tree_branche == NULL)
			//	return (false);
			//std::cerr << tree_branche << " ******* " << other.tree_branche << std::endl;
			return (tree_branche != other.tree_branche);
		}
		bool operator==(const Map_Iterator& other) const 
		{
			return (tree_branche == other.tree_branche);
		}

		//Map_Iterator& operator++()
		//{
		//	if (tree_branche->right) {
		//		tree_branche = tree_branche->right;
		//		while (tree_branche->left) {
		//			tree_branche = tree_branche->left;
		//		}
		//	}
		//	else {
		//		node parent = Tree<typename Node::key_type, typename Node::mapped_type>::I_wanna_know_my_parent(root, tree_branche->data->first);
		//		while (parent && tree_branche == parent->right) {
		//			tree_branche = parent;
		//			parent = Tree<typename Node::key_type, typename Node::mapped_type>::I_wanna_know_my_parent(root, parent->data->first);;
		//		}
		//		tree_branche = parent;
		//	}
		//	return *this;
		//}

		Map_Iterator& operator++()
		{
			if(tree_branche->right != nullptr){
				tree_branche = tree_branche->right;
				while(tree_branche->left){
					tree_branche = tree_branche->left;
			}
			}else{
				Node *parent = Tree<typename Node::key_type, typename Node::mapped_type, typename Node::cmp>::I_wanna_know_my_parent(root, tree_branche->data->first);
								//std::cerr << "hehehe\n";
				if (parent == nullptr)
				{
					tree_branche = root; 
				}
				while (parent && tree_branche == parent->right)
				{
					tree_branche = parent;
					parent = Tree<typename Node::key_type, typename Node::mapped_type, typename Node::cmp>::I_wanna_know_my_parent(root, parent->data->first);
				}
				tree_branche =parent;
			}
			return *this;
		}

		Map_Iterator operator++(int)
		{
			Map_Iterator tmp = *this;
			++(*this);
			return (tmp);
		}

		Map_Iterator& operator--()
		{
			if (tree_branche == nullptr)
			{
				tree_branche = Tree<typename Node::key_type, typename Node::mapped_type, typename Node::cmp>::large_root_pair(root).second;
				return (*this);
			}
			if (tree_branche->left) {
				tree_branche = tree_branche->left;
				while (tree_branche->right) {
					tree_branche = tree_branche->right;
				}
			}
			else {
				node parent = Tree<typename Node::key_type, typename Node::mapped_type, typename Node::cmp>::I_wanna_know_my_parent(root, tree_branche->data->first);
				while (parent && tree_branche == parent->left) {
					tree_branche = parent;
					parent = Tree<typename Node::key_type, typename Node::mapped_type, typename Node::cmp>::I_wanna_know_my_parent(root, parent->data->first);;
				}
				tree_branche = parent;
			}
			return *this;
		}
		
		Map_Iterator operator--(int)
		{
			Map_Iterator tmp = *this;
			--(*this);
			return (tmp);
		}

		node get_tree_branche() const
		{
			return (tree_branche);
		}
	private :
		//Tree<typename Node::key_type, typename Node::mapped_type> suiii;
		node	tree_branche;
		node 	root;
};




#endif