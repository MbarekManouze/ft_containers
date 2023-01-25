/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_Iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:23:29 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/25 16:23:27 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOE_HPP
# define REVERSE_ITERATOE_HPP

#include <iostream>
#include <cstddef>
#include "Iterator.hpp"
template<class Iterator>
class iterator_traits{
  public:
        typedef typename Iterator::difference_type    difference_type;
        typedef typename Iterator::value_type         value_type;
        typedef typename Iterator::pointer            pointer;
        typedef typename Iterator::reference          reference;
        typedef typename Iterator::iterator_category  iterator_category;
};

template <class T>
class iterator_traits<T*>
{
  public:
        typedef std::ptrdiff_t                  difference_type;
        typedef T                               value_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef std::random_access_iterator_tag iterator_category;
};

template <class T>
class iterator_traits<const T*>
{
  public:
        typedef std::ptrdiff_t                  difference_type;
        typedef T                               value_type;
        typedef const T*                        pointer;
        typedef const T&                        reference;
        typedef std::random_access_iterator_tag iterator_category;
};

template <class T> class Reverse_Iterator
{
	public :
        typedef  T value_type;
        typedef typename iterator_traits<T>::reference reference;
        typedef typename iterator_traits<T>::pointer pointer;
        typedef typename iterator_traits<T>::difference_type difference_type;
        typedef typename iterator_traits<T>::iterator_category iterator_category;

	Reverse_Iterator():reverse_iterator_data(NULL){}
        Reverse_Iterator(const Reverse_Iterator &_rit){ this->operator=(_rit); }
        Reverse_Iterator(const value_type &object):reverse_iterator_data(object) {}
        Reverse_Iterator& operator=(Reverse_Iterator const &object) { this->reverse_iterator_data = object.reverse_iterator_data; return (*this); }
	reference operator*() { return *(reverse_iterator_data - 1); }
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

	protected :
	value_type reverse_iterator_data;
};


#endif