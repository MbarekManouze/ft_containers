/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reverse_iterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:39:56 by mmanouze          #+#    #+#             */
/*   Updated: 2023/03/05 15:02:10 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_REVERSE_ITEARTOR_HPP
#define MAP_REVERSE_ITEARTOR_HPP


#include "map_iterator.hpp"

namespace ft
{

	template <typename map_iterator>
	class reverse_iterator{
		private :
			map_iterator rev_it;
		public :


			//-----------------mamber types----------------//


			typedef				map_iterator 														underlying_iterator;
			typedef typename 	ft::iterator_traits_map<underlying_iterator>::iterator_category		iterator_category;
			typedef typename	ft::iterator_traits_map<underlying_iterator>::value_type 			value_type;
			typedef typename 	ft::iterator_traits_map<underlying_iterator>::difference_type 		diffrence_type;
			typedef typename 	ft::iterator_traits_map<underlying_iterator>::pointer 				pointer;
			typedef typename 	ft::iterator_traits_map<underlying_iterator>::reference 			reference;

			//------------------base----------------------//

			underlying_iterator base() const { return (rev_it);}

			//----------------constructors----------------//


			reverse_iterator():rev_it() {}
			~reverse_iterator() {}
			explicit reverse_iterator(underlying_iterator object) :rev_it(object){}
			template <class it>
				reverse_iterator(const reverse_iterator& rit): rev_it(rit.base()){}


			//----------------operators--------------------//

				
			bool 						operator!=(const reverse_iterator& object) const { return (rev_it != object.rev_it); }
			bool 						operator==(const reverse_iterator& object) const { return (rev_it == object.rev_it); }
			pointer 					operator->() const { return (rev_it.operator->()); }
			reference 					operator*() const { return (*rev_it); }
			reverse_iterator 			operator++(int) {reverse_iterator tmp = *this; --rev_it; return (tmp); }
			reverse_iterator 			operator--(int) {reverse_iterator tmp = *this; ++rev_it; return (tmp); }
			reverse_iterator& 			operator++() {  --rev_it; return (*this); }
			reverse_iterator& 			operator--() { ++rev_it; return (*this); }
	};

}



#endif