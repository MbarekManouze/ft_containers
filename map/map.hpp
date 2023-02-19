/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:20:56 by mmanouze          #+#    #+#             */
/*   Updated: 2023/02/15 18:04:42 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>


template < class Key, class T, class Compare = std::less<Key>,  class Alloc = std::allocator<std::pair<const Key,T> > >
class map{
	public :
		typedef typename 	key												key_type;
		typedef typename	T												mapped_type;							
		typedef typename	std::pair<const key_type,mapped_type>			value_type; 
		typedef typename	Compare											key_compare;		
		typedef typename	Alloc											allocator_type;							
		typedef 			&value_type			 							reference;		
		typedef 			const &value_type								const_reference;
		typedef 			value_type*										pointer;
		typedef 			const value_type*								const_pointer;
		typedef typename	iterator<T> 									iterator;
		typedef typename	iterator<const T> 								const_iterator;
		typedef typename	reverse_iterator<T> 							reverse_iterator;
		typedef typename	reverse_iterator<const T> 						const_reverse_iterator;

		template <typename first, typename second>
		class pair {
			private :
				first first;
				second second;
			public :
				pair(){}
				pair(first f, second s):first(f), second(s){}
				~pair(){}
		};
		template <typename first, typename second>
		pair<first, second> make_pair(first key, second value)
		{
			return (pair(key, value));
		}


}







#endif