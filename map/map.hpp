/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:20:56 by mmanouze          #+#    #+#             */
/*   Updated: 2023/02/21 14:52:03 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include "./pair/pair.hpp"
#include "./avl_tree/avl_tree.hpp"
#include "map_iterator/map_iterator.hpp"


template < class Key, class T, class Compare = std::less<Key>,  class Alloc = std::allocator<std::pair<const Key,T> > >
class map{
	public :
		typedef typename 	key												key_type;
		typedef typename	T												mapped_type;							
		typedef typename	pair<const key_type,mapped_type>				value_type; 
		typedef typename	Compare											key_compare;		
		typedef typename	Alloc											allocator_type;							
		typedef 			value_type&			 							reference;		
		typedef 			const value_type&								const_reference;
		typedef 			value_type*										pointer;
		typedef 			const value_type*								const_pointer;
		typedef typename	Map_Iterator<Tree<key, T>::Node> 				iterator;
		typedef typename	Map_Iterator<const Tree<key, T>::Node> 			const_iterator;
		//typedef typename	reverse_iterator<Tree<key, T>::Node> 			reverse_iterator;
		//typedef typename	reverse_iterator<const Tree<key, T>::Node> 		const_reverse_iterator;
		typedef typename 	Tree<Key, T>* 									node_pointer;


		typedef std::allocator<Tree<Key, T>> tree_allocator;
		typedef typename tree_allocator::template rebind<Tree<Key, T>>::other tree_bind;



		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):root(nullptr), _alloc(alloc), Comp(comp), _size(0){}
		template <class InputIterator>  
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{}
		map (const map& x){}

		bool empty() const {return(_size == 0 ? true : false);}
		iterator begin() { return (iterator(root->root)); }



		pair<iterator,bool> insert (const value_type& val)
		{
			root->insert(root->root, val, nullptr);	
		}



	private :
		tree_bind 		tree_alloc;
		node_pointer 	root;
		allocator_type 	_alloc;
		key_compare 	Comp;
		size_t 			_size;
};



#endif