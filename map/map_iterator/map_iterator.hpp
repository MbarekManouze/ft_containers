/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:53:31 by mmanouze          #+#    #+#             */
/*   Updated: 2023/02/21 14:45:15 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP


#include <iostream>
#include "../pair/pair.hpp"
#include "../avl_tree/avl_tree.hpp"


template <class Node>
class Map_Iterator {
	public :
		typedef typename pair< Node::key_type,  Node::type_mapped>	value_type;
		typedef std::bidirectional_iterator_tag 					iterator_category;
		typedef std::ptrdiff_t 										diffrence_type;
		typedef value_type* 										pointer;
		typedef value_type&											reference;
		typedef Node 												node;

		Map_Iterator(pointer node): tree_branche(node){}
		pointer operator->() const { return(tree_branche->data); }
		reference operator*() const { return(tree_branche->data); }

	private :
		node	tree_branche;
};




#endif