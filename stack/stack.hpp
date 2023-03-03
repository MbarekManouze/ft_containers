/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 00:52:02 by mmanouze          #+#    #+#             */
/*   Updated: 2023/03/03 01:21:41 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "../Vector/vector.hpp"

namespace ft
{
template <class T, class Container = ft::vector<T> > class stack
{
	public :
		typedef 	T 								value_type;
		typedef 	T&								reference;
		typedef 	const T& 						const_reference;
		typedef 	Container 						container_type;
		typedef		typename Container::size_type	size_type;

		explicit stack (const container_type& ctnr = container_type()) :vec(ctnr){  }

		bool empty() const { return (vec.empty()); }
		size_type size() const { return (vec.size()); }
      	value_type& top() { return (vec.back()); }
		const value_type& top() const { return (vec.back()); }
		void push (const value_type& val) { return (vec.push_back(val)); }
		void pop() { return (vec.pop_back()); }
		template <class T_, class Container_>   
			friend bool operator== (const stack<T_,Container_>& lhs, const stack<T_,Container_>& rhs) { return (lhs.vec == rhs.vec); }
		template <class T_, class Container_>   
			friend bool operator!= (const stack<T_,Container_>& lhs, const stack<T_,Container_>& rhs) { return (lhs.vec != rhs.vec); }
		template <class T_, class Container_>   
			friend bool operator<  (const stack<T_,Container_>& lhs, const stack<T_,Container_>& rhs) { return (lhs.vec < rhs.vec); }
		template <class T_, class Container_>   
			friend bool operator<= (const stack<T_,Container_>& lhs, const stack<T_,Container_>& rhs) { return (lhs.vec <= rhs.vec); }
		template <class T_, class Container_>   
			friend bool operator>  (const stack<T_,Container_>& lhs, const stack<T_,Container_>& rhs) { return (lhs.vec > rhs.vec); }
		template <class T_, class Container_>   
			friend bool operator>= (const stack<T_,Container_>& lhs, const stack<T_,Container_>& rhs) { return (lhs.vec >= rhs.vec); }

	private :
		container_type 		vec;
};
}

#endif
