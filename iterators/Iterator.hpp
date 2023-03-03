/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 09:23:41 by mmanouze          #+#    #+#             */
/*   Updated: 2023/03/02 11:29:52 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOE_HPP
# define ITERATOE_HPP

#include <iostream>
#include <cstddef>
#include "Iterator_traits.hpp"

template <class T> class Iterator
{
	public :
         typedef typename  iterator_traits<T*>::value_type         value_type;
        //typedef T value_type;
        //typedef T& reference;
        //typedef T* pointer;
        //typedef std::ptrdiff_t difference_type;
        //typedef std::random_access_iterator_tag iterator_category;
        typedef typename iterator_traits<T*>::reference reference;
        typedef typename iterator_traits<T*>::pointer pointer;
        typedef typename iterator_traits<T*>::difference_type difference_type;
        typedef typename iterator_traits<T*>::iterator_category iterator_category;

		Iterator():_iterator_data(NULL) {}
		Iterator(pointer data):_iterator_data(data) {}
        Iterator(const Iterator &object):_iterator_data(object._iterator_data) {}
        operator Iterator<const value_type>() const {return Iterator<const value_type>(_iterator_data);}
        operator Iterator<const value_type>() {return Iterator<const value_type>(_iterator_data);}
        Iterator& operator=(Iterator const &object) { this->_iterator_data = object._iterator_data; return (*this); }		
        reference operator*() const { return *_iterator_data; }
        pointer operator->() const { return _iterator_data; }
        Iterator& operator++() { ++_iterator_data; return *this; }
        Iterator operator++(int) { Iterator tmp(*this); operator++(); return tmp; }
        Iterator& operator--() { --_iterator_data; return *this; }
        Iterator operator--(int) { Iterator tmp(*this); operator--(); return tmp; }
        Iterator operator+(difference_type n) const { return Iterator(_iterator_data + n); }
        Iterator operator-(difference_type n) const { return Iterator(_iterator_data - n); }
        Iterator operator+=(difference_type n) { _iterator_data += n; return (*this); }
        Iterator operator-=(difference_type n) { _iterator_data -= n; return (*this); }
        pointer base() const {return _iterator_data;}
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
        friend std::ostream &operator<<(std::ostream &os, Iterator const &object){
            os << object.operator*() << std::endl;
            return os;
        }
        friend Iterator<T> operator+ (typename Iterator<T>::difference_type n, const Iterator<T>& it)
        {
            return it + n;
        }
        template <class _T>
            std::ptrdiff_t operator- (const Iterator<_T>& object) const { return this->_iterator_data -  object.base(); }
        template <class P, class P2>
            friend bool operator< (const Iterator<P>& lhs, const Iterator<P2>& rhs);
        template <class P, class P2>
            friend bool operator<= (const Iterator<P>& lhs, const Iterator<P2>& rhs);
        template <class P, class P2>
            friend bool operator> (const Iterator<P>& lhs, const Iterator<P2>& rhs);
        template <class P, class P2>
            friend bool operator>= (const Iterator<P>& lhs, const Iterator<P2>& rhs);
        template <class P, class P2>
            friend bool operator!= (const Iterator<P>& lhs, const Iterator<P2>& rhs);
        template <class P, class P2>
            friend bool operator== (const Iterator<P>& lhs, const Iterator<P2>& rhs);

        //friend Iterator<T> operator- (typename Iterator<T>::difference_type n, const Iterator<T>& it)
        //{
        //    return it - n;
        //}        
        //friend Iterator<T> operator* (typename Iterator<T>::difference_type n, const Iterator<T>& it)
        //{
        //    return it * n;
        //}        
        //friend Iterator<T> operator/ (typename Iterator<T>::difference_type n, const Iterator<T>& it)
        //{
        //    return it / n;
        //}
	protected :
		T *_iterator_data;
};

template <class P, class P2> 
    bool operator== (const Iterator<P>& lhs, const Iterator<P2>& rhs)
    {
        return(lhs._iterator_data == rhs._iterator_data);
    }
template <class P, class P2>
    bool operator!= (const Iterator<P>& lhs, const Iterator<P2>& rhs)
    {
        return(lhs._iterator_data != rhs._iterator_data);
    }
template <class P, class P2>
    bool operator< (const Iterator<P>& lhs, const Iterator<P2>& rhs)
    {
        return(lhs._iterator_data < rhs._iterator_data);
    }
template <class P, class P2>
    bool operator<= (const Iterator<P>& lhs, const Iterator<P2>& rhs)
    {
        return(lhs._iterator_data <= rhs._iterator_data);
    }
template <class P, class P2>
    bool operator>  (const Iterator<P>& lhs, const Iterator<P2>& rhs)
    {
        return(lhs._iterator_data > rhs._iterator_data);
    }
template <class P, class P2>
    bool operator>= (const Iterator<P>& lhs, const Iterator<P2>& rhs)
    {
        return(lhs._iterator_data >= rhs._iterator_data);
    }

#endif