/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:23:41 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/22 11:46:38 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOE_HPP
# define ITERATOE_HPP

#include <iostream>
#include <cstddef>

template <class T> class Iterator
{
	public :
        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;
        typedef std::ptrdiff_t difference_type;
        typedef std::random_access_iterator_tag iterator_category;

		Iterator():_iterator_data(NULL){}
		Iterator(T *data):_iterator_data(data){}
        Iterator(const Iterator &object){ this->operator=(object); }
        Iterator& operator=(Iterator const &object) { this->_iterator_data = object._iterator_data; return (*this); }
		reference operator*() const { return *_iterator_data; }
        pointer operator->() const { return _iterator_data; }
        Iterator& operator++() { ++_iterator_data; return *this; }
        Iterator operator++(int) { Iterator tmp(*this); operator++(); return tmp; }
        Iterator& operator--() { --_iterator_data; return *this; }
        Iterator operator--(int) { Iterator tmp(*this); operator--(); return tmp; }
        Iterator operator+(difference_type n) const { return Iterator(_iterator_data + n); }
        Iterator operator-(difference_type n) const { return Iterator(_iterator_data - n); }
        difference_type operator-(const Iterator& other) const { return _iterator_data - other._iterator_data; }
        bool operator==(const Iterator& other) const { return _iterator_data == other._iterator_data; }
        bool operator!=(const Iterator& other) const { return _iterator_data != other._iterator_data; }
        bool operator<(const Iterator& other) const { return _iterator_data < other._iterator_data; }
        bool operator>(const Iterator& other) const { return _iterator_data > other._iterator_data; }
        bool operator<=(const Iterator& other) const { return _iterator_data <= other._iterator_data; }
        bool operator>=(const Iterator& other) const { return _iterator_data >= other._iterator_data; }
        reference operator[](difference_type n) const { return _iterator_data[n]; }
        pointer operator&() { return (_iterator_data); }
        pointer &get_iterator(){ return (_iterator_data); }

	private :
		T *_iterator_data;
};


#endif