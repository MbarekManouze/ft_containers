/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:20:56 by mmanouze          #+#    #+#             */
/*   Updated: 2023/03/01 23:50:00 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include "./pair/pair.hpp"
#include "./avl_tree/avl_tree.hpp"
#include "map_iterator/map_iterator.hpp"
#include "map_iterator/map_reverse_iterator.hpp"
#include "../Vector/vector.hpp"

namespace ft{

template < class Key, class T, class Compare = std::less<Key>,  class Alloc = std::allocator<std::pair<const Key,T> > >
class map{
	public :
		typedef  	Key																	key_type;
		typedef 	T																	mapped_type;							
		typedef 	pair<const key_type,mapped_type>									value_type; 
		typedef 	Compare																key_compare;
		typedef 	typename Alloc::size_type											size_type;	
		typedef 	Alloc																allocator_type;							
		typedef 	value_type&			 												reference;		
		typedef 	const value_type&													const_reference;
		typedef 	value_type*															pointer;
		typedef 	const value_type*													const_pointer;
		typedef 	Map_Iterator<typename Tree<key_type, mapped_type>::Node> 			iterator;
		typedef 	Map_Iterator<typename Tree<key_type, mapped_type>::Node> 			const_iterator;
		typedef 	reverse_iterator<const_iterator> 									const_reverse_iterator;
		typedef 	reverse_iterator<iterator> 											reverse_iterator;
	    typedef typename std::ptrdiff_t                                            		difference_type;
		typedef typename Tree<key_type, mapped_type>::Node nd;

		typedef std::allocator<Tree<key_type, mapped_type> > tree_allocator;
		typedef typename tree_allocator::template rebind<Tree<key_type, mapped_type> >::other tree_bind;
		typedef typename tree_bind::pointer node_pointer;
		class value_compare {
   		private:
   		  Compare comp;
   		public:
   		  typedef bool result_type;
   		  typedef value_type first_argument_type;
   		  typedef value_type second_argument_type;
   		  bool operator()(const value_type& x, const value_type& y) const {
   		    return comp(x.first, y.first);
   		  }
   		};
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):root(nullptr), _alloc(alloc), Comp(comp), _size(0)
		{
			root = tree_alloc.allocate(1);
			tree_alloc.construct(root, Tree<key_type, mapped_type>());
		}

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :root(nullptr), _alloc(alloc), Comp(comp), _size(0)
		{
			nd* node = NULL;
			root = tree_alloc.allocate(1);
			tree_alloc.construct(root, Tree<key_type, mapped_type>());
			while (first != last)
			{
				root->insert(root->root, *first , node);
				_size++;
				first++;
			}
		}
		mapped_type& at (const key_type& k){
			if (find(k).get_tree_branche() == nullptr)
				throw std::out_of_range("vector::at() index out of range");
			else
				return(find(k)->second);
		}
		const mapped_type& at (const key_type& k) const
		{
			if (find(k).get_tree_branche() == nullptr)
				throw std::out_of_range("vector::at() index out of range");
			else
				return(find(k)->second);
		}
		mapped_type& operator[] (const key_type& k){
			 iterator it = find(k);
        if(it == end())
            it = insert(ft::make_pair(k, mapped_type())).first;
        return it->second;
		}
		map (const map& x): root(nullptr), _alloc(x._alloc), Comp(x.Comp)
		{
			*this = x;
		}

		~map() 
		{
			if (root)
			{
				erase(begin(), end());
				tree_alloc.destroy(root);
				tree_alloc.deallocate(root, 1);
				//erase(begin(), end());
			}
		}

		map& operator=(const map& object)
		{
			if (root == nullptr)
			{
				//std::cerr << "okeey\n";
				root = tree_alloc.allocate(1);
				tree_alloc.construct(root, Tree<key_type, mapped_type>());
				insert(object.begin(), object.end());
			}
			else
			{
				erase(begin(), end());
				tree_alloc.deallocate(root, 1);
				root = tree_alloc.allocate(1);
				tree_alloc.construct(root, Tree<key_type, mapped_type>());
				insert(object.begin(), object.end());
			}
			return (*this);
		}

		size_t size() const { return (root->get_size()); }
		bool empty() const {return(_size == 0 ? true : false);}
		iterator begin()  { return (iterator(root->smaller_root_pair(root->root))); }
		iterator end()  { return (iterator(nullptr, root->root)); }
		const_iterator begin() const { return (const_iterator(root->smaller_root_pair(root->root))); }
		const_iterator end() const { return (const_iterator(nullptr, root->root)); }
		reverse_iterator rbegin() { iterator tmp(root->large_root_pair(root->root));return (reverse_iterator(tmp)); }
		reverse_iterator rend() { return (reverse_iterator(end())); }
		const_reverse_iterator rbegin() const {const_iterator tmp(root->large_root_pair(root->root));return (const_reverse_iterator(tmp)); }
		const_reverse_iterator rend() const { return (const_reverse_iterator(end())); }
		
		allocator_type get_allocator() const { return (_alloc); }

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			while (first != last)
			{

				insert(*first);
				first++;
			}
		}

		pair<iterator, bool> insert (const value_type& val)
		{
			nd* node = NULL;
			size_t tmp = root->get_size();
			root->insert(root->root, val, node);
			if (tmp == root->get_size())
				return (pair<iterator, bool>(iterator(node), 0));
			_size++;
			return (pair<iterator, bool>(iterator(node), 1));
		}

		iterator insert (iterator position, const value_type& val)
		{
			(void)position;
			return (insert(val).first);
		}

		void erase(iterator position)
		{
			size_t q = 0;
			root->DeleteNode(root->root, position->first, q);
			_size--;
		}

		size_type erase (const key_type& k)
		{
			size_t q = 0;
			root->DeleteNode(root->root, k, q);
			_size--;
			if (q == 0)
				return (0);
			return (1);
		}

		void erase(iterator first, iterator last)
		{
			ft::vector<key_type> vec;
			while (first != last)
			{
				vec.push_back(first->first);
				first++;
			}
			size_t i = 0;
			while (i < vec.size())
			{
				erase(vec[i]);
				i++;
			}
		}

		iterator find (const key_type& k)
		{
			nd* node = NULL;
			root->find_element(k, root->root, node);
			if (node == NULL)
				return (end());
			return (iterator(node, root->root));
		}

		const_iterator find (const key_type& k) const
		{
			nd* node = NULL;
			root->find_element(k, root->root, node);
			if (node == NULL)
				return (const_iterator(end()));
			return (const_iterator(node, root->root));
		}

		size_type count (const key_type& k) const 
		{
			nd* node = NULL;
			root->find_element(k, root->root, node);
			if (node == NULL)
				return 0;
			return (1);
		}

		void print_my_map()
		{
			root->printTree(root->root, nullptr, false);
		}

 template <class Key_, class T_, class Compare_, class Alloc_>
        friend bool operator== ( const map<Key_,T_,Compare_,Alloc_>& lhs, const map<Key_,T_,Compare_,Alloc_>& rhs ){
            if ((lhs.size() != rhs.size()))
                return(false);
            iterator first1 = lhs.begin();
            iterator first2 = rhs.begin();
            iterator last1 = lhs.end();
            
            while (first1 != last1)
            {
                if (!(first1->first == first2->first && first1->second == first2->second)) {
                    return false;
                }
                first1++;
                first2++;
            }
            
            return(true);
        }
		template<typename S>
			void swap_object(S& x, S& y)
    	{
    	    S temp;
    	    temp = x;
    	    x = y;
    	    y = temp;
    	}
    	void swap (map& x)
    	{
    	    swap_object(tree_alloc, x.tree_alloc);
    	    swap_object(_alloc, x._alloc);
    	    swap_object(Comp, x.Comp);
    	    swap_object(_size, x._size);
    	    swap_object(root, x.root);
    	}
		 iterator lower_bound(const key_type& k){
    	    nd* node = root->root;
    	    nd* res = nullptr;
    	    while (node != nullptr) {
    	        if (!Comp(node->data->first, k)) {
    	            res = node;
    	            node = node->left;
    	        } else {
    	            node = node->right;
    	        }
    	    }
    	    return iterator(res);
    	}
    	const_iterator lower_bound(const key_type& k) const {
    	    nd* node = root->root;
    	    nd* res = nullptr;
    	    while (node != nullptr) {
    	        if (!Comp(node->data->first, k)) {
    	            res = node;
    	            node = node->left;
    	        } else {
    	            node = node->right;
    	        }
    	    }
    	    return const_iterator(res);
    	}
    	   iterator upper_bound(const key_type& k){
    	    nd* node = root->root;
    	    nd* res = nullptr;
    	    while (node != nullptr) {
    	        if (Comp(k, node->data->first)) {
    	            res = node;
    	            node = node->left;
    	        } else {
    	            node = node->right;
    	        }
    	    }
    	    return iterator(res);
    	}
    	const_iterator upper_bound(const key_type& k) const {
    	    nd* node = root->root;
    	    nd* res = nullptr;
    	    while (node != nullptr) {
    	        if (Comp(k, node->data->first)) {
    	            res = node;
    	            node = node->left;
    	        } else {
    	            node = node->right;
    	        }
    	    }
    	    return const_iterator(res);
    	}
			void clear()
			{
				erase(begin(), end());
			}
			value_compare value_comp() const
			{
				value_compare cmp;
				return(cmp);
		}

		ft::pair<const_iterator,const_iterator>
	        equal_range (const key_type& k) const{
	            return(ft::make_pair(lower_bound(k), upper_bound(k)));
	        }
	    ft::pair<iterator,iterator>
	        equal_range (const key_type& k){
	            return(ft::make_pair(lower_bound(k), upper_bound(k)));
	        }
	key_compare key_comp() const
	{
		return(Comp);
	}
 template <class Key_, class T_, class Compare_, class Alloc_>
        friend bool operator!= ( const map<Key_,T_,Compare_,Alloc_>& lhs, const map<Key_,T_,Compare_,Alloc_>& rhs ){
           return(!(lhs == rhs));
        }
    template <class Key_, class T_, class Compare_, class Alloc_>
        friend bool operator<  ( const map<Key_,T_,Compare_,Alloc_>& lhs, const map<Key_,T_,Compare_,Alloc_>& rhs ){
            return(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
        }
    template <class Key_, class T_, class Compare_, class Alloc_>
        friend bool operator<=  ( const map<Key_,T_,Compare_,Alloc_>& lhs, const map<Key_,T_,Compare_,Alloc_>& rhs ){
            return((ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())) || (lhs == rhs));
        }
    template <class Key_, class T_, class Compare_, class Alloc_>
        friend bool operator>  ( const map<Key_,T_,Compare_,Alloc_>& lhs, const map<Key_,T_,Compare_,Alloc_>& rhs ){
            return(rhs < lhs);
        }
    template <class Key_, class T_, class Compare_, class Alloc_>
        friend bool operator>=  ( const map<Key_,T_,Compare_,Alloc_>& lhs, const map<Key_,T_,Compare_,Alloc_>& rhs ){
            return(rhs <= lhs);
        }
        template <class Key_, class T_, class Compare_, class Alloc_>
        friend void swap (map<Key_,T_,Compare_,Alloc_>& x, map<Key_,T_,Compare_,Alloc_>& y);
		node_pointer 	root;
	private :
		tree_bind 		tree_alloc;
		allocator_type 	_alloc;
		key_compare 	Comp;
		size_t 			_size;
};
    template <class Key_, class T_, class Compare_, class Alloc_>
        void swap (map<Key_,T_,Compare_,Alloc_>& x, map<Key_,T_,Compare_,Alloc_>& y){
            x.swap(y);
        }
} 


#endif