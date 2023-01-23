/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:23:29 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/23 17:52:08 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOE_HPP
# define REVERSE_ITERATOE_HPP

#include <iostream>
#include <cstddef>

template <class T> class Reverse_Iterator
{
	public :
        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;
        typedef std::ptrdiff_t difference_type;
        typedef std::random_access_iterator_tag iterator_category;

		Reverse_Iterator():reverse_iterator_data(NULL){}
		Reverse_Iterator(T *data):reverse_iterator_data(data){}
        Reverse_Iterator(const Reverse_Iterator &object){ this->operator=(object); }
        Reverse_Iterator& operator=(Reverse_Iterator const &object) { this->reverse_iterator_data = object.reverse_iterator_data; return (*this); }
		reference operator*() const { return *reverse_iterator_data; }
        pointer operator->() const { return reverse_iterator_data; }
        Reverse_Iterator& operator++() { --reverse_iterator_data; return *this; }
        Reverse_Iterator operator++(int) { Reverse_Iterator tmp(*this); operator++(); return tmp; }
        Reverse_Iterator& operator--() { ++reverse_iterator_data; return *this; }
        Reverse_Iterator operator--(int) { Reverse_Iterator tmp(*this); operator--(); return tmp; }
        Reverse_Iterator operator+(difference_type n) const { return Reverse_Iterator(reverse_iterator_data - n); }
        Reverse_Iterator operator-(difference_type n) const { return Reverse_Iterator(reverse_iterator_data + n); }
        difference_type operator-(const Reverse_Iterator& other) const { return reverse_iterator_data - other.reverse_iterator_data; }
        bool operator==(const Reverse_Iterator& other) const { return reverse_iterator_data == other.reverse_iterator_data; }
        bool operator!=(const Reverse_Iterator& other) const { return reverse_iterator_data != other.reverse_iterator_data; }
        bool operator<(const Reverse_Iterator& other) const { return reverse_iterator_data < other.reverse_iterator_data; }
        bool operator>(const Reverse_Iterator& other) const { return reverse_iterator_data > other.reverse_iterator_data; }
        bool operator<=(const Reverse_Iterator& other) const { return reverse_iterator_data <= other.reverse_iterator_data; }
        bool operator>=(const Reverse_Iterator& other) const { return reverse_iterator_data >= other.reverse_iterator_data; }
        reference operator[](difference_type n) const { return reverse_iterator_data[n]; }
        pointer operator&() { return (reverse_iterator_data); }
        pointer &get_iterator(){ return (reverse_iterator_data); }

	private :
		T *reverse_iterator_data;
};


#endif