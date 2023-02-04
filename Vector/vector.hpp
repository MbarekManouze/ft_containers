/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:52:11 by mmanouze          #+#    #+#             */
/*   Updated: 2023/02/04 23:07:35 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <new>
#include <memory>
#include "../iterators/Iterator.hpp"
#include "../iterators/reverse_Iterator.hpp"

namespace ft {
template < class T, class Alloc = std::allocator<T> > class vector
{
	public :

		typedef Iterator<T> 					iterator;
		typedef Iterator<const T> 				const_iterator;
		typedef T 								value_type;
		typedef Alloc							allocator_type;
		typedef T& 								reference;
		typedef const T& 						const_reference;
		typedef T* 								pointer;
		typedef const T* 						const_pointer;
		typedef typename std::ptrdiff_t 		difference_type;
		typedef typename Alloc::size_type 		size_type; 
		typedef T* 								Iterator;
		typedef const T* 						const_Iterator;
    	typedef Reverse_Iterator<const_iterator>         const_reverse_iterator;
    	typedef Reverse_Iterator<iterator>               reverse_iterator;

		explicit vector (const allocator_type& alloc = allocator_type()): _data(0),allocater(alloc),_size(0), _capacity(0){}
		
		explicit vector (size_type n, const value_type& val = value_type(),                 const allocator_type& alloc = allocator_type())
		: allocater(alloc), _size(n),_capacity(n){
			_data = allocater.allocate(n);
			for (size_t i = 0; i < n; i++)
				allocater.construct(_data + i, val);
		}
		vector (const vector& x):_data(0),_size(0),_capacity(0){
			allocater = x.get_allocator();
			*this = x;
		}

		~vector(){ 
			
			if (_data != NULL)
			{
				for (size_t i = 0; i < _size; i++)
					allocater.destroy(_data + i);
				allocater.deallocate(_data, _capacity); 
			}
		}

		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
		:_data(0),allocater(alloc),_size(0),_capacity(0)
		{
			assign(first, last);
		}

		value_type &operator[](size_t index)const{ return (_data[index]); }
		vector  &operator=(const vector& x){
			if (this != &x)
				assign(x.begin(), x.end());
			return (*this);
		}

		iterator 				begin() { return (iterator (_data)); }
		iterator 				end() { return (iterator (_data + _size)); }
		const_Iterator 			begin() const {return (const_Iterator(_data));}
		const_Iterator 			end() const { return (const_Iterator (_data + _size)); }
		reverse_iterator 				rbegin() { /*std::cout <<"rebegiin : "<< *(_data + _size-1) <<std::endl;*/return (reverse_iterator (_data + _size)); }
		reverse_iterator 				rend() { /*std::cout <<"reend : "<< *(_data) <<std::endl;*/return (reverse_iterator (_data)); }
		const_reverse_iterator  rbegin() const {return const_reverse_iterator(_data + _size);}
		const_reverse_iterator  rend() const {return const_reverse_iterator(_data);}
		size_type 				size() const { return (_size); }
		size_type 				capacity() const { return (_capacity); }
		bool 					empty() const { return (_size == 0 ? true : false); }
		size_type max_size() const
		{
			if(INT64_MAX < allocater.max_size())
				return(INT64_MAX);
			return(allocater.max_size());
		}

		reference     			at(size_type n)
		{
			if(n >= _size)
				throw std::out_of_range("vector::at() index out of range");
			else
				return (_data[n]);
		}
		const_reference     	at(size_type n) const 
		{ 
			if (n >= _size)
				throw std::out_of_range("vector::at() index out of range");
			else
				return (_data[n]);
		}
		reference 				back() { return ((_data[_size - 1])); }
		const_reference 		back() const { return ((_data[_size - 1])); }
		reference 				front() { return (_data[0]); }
		const_reference 		front() const { return (_data[0]); }
		allocator_type 			get_allocator() const { return (allocater); }
		void 					clear()
		{
			for(size_t i =0; i<_size; i++)
			{
				allocater.destroy(_data + i);
			}
			_size=0;
		}

		// RESIZE METHOD DONE AND WELL TESTED //

		void 			resize (size_type n)
		{
			if (_size == 0){
				_data = allocater.allocate(n);
				_capacity = n;
				_size = 0;
			}
			else{
				if (n > this->size()){
					size_t new_capacity;
					if (n > _capacity)
					{
						if (n > _capacity * 2)
							new_capacity = n;
						else
							new_capacity = _capacity * 2;
					}
					else
						new_capacity = _capacity;
					pointer _new_data = allocater.allocate(new_capacity);
					for (size_t i = 0; i < this->size() ; i++)
					{
						allocater.construct(_new_data + i, _data[i]);
						allocater.destroy(_data + i);
					}
					allocater.deallocate(_data, _capacity);
					_data = _new_data;
					_capacity = new_capacity;
					_size = n;
				}
				else if (n < _size){
					pointer _new_data = allocater.allocate(_capacity);
					for (size_t i = 0; i < n; i++)
					{
						allocater.construct(_new_data + i, _data[i]);
						allocater.destroy(_data + i);
					}
					for (size_t i = n ; i < _size ; i++)
							allocater.destroy(_data + i);
					if (_data != NULL)
						allocater.deallocate(_data , _capacity);
					_data = _new_data;
					_size = n;
				}
			}
		}

		void 			resize (size_type n, const T& value){
			if (n > this->size()){
				size_t new_capacity;
				if (n > _capacity)
				{
					if (n > _capacity * 2)
						new_capacity = n;
					else
						new_capacity = _capacity * 2;
				}
				else
					new_capacity = _capacity;
				pointer new_data = allocater.allocate(new_capacity);
				for (size_t i = 0; i < this->size() ;i++)
				{
					allocater.construct(new_data + i, _data[i]);
					allocater.destroy(_data + i);
				}
				for (size_t i = this->size(); i < n; i++)
					allocater.construct(new_data + i, value);
				if (_data != NULL)
					allocater.deallocate(_data, _capacity);
				_data = new_data;
				_capacity = new_capacity;
				_size = n;
			}
			else{
				pointer new_data = allocater.allocate(_capacity);
				for (size_t i = 0; i < n ;i++)
				{
					allocater.construct(new_data + i, _data[i]);
					allocater.destroy(_data + i);
				}
				for (size_t i = n; i < this->size() ;i++)
					allocater.destroy(_data + i);
				if (_data != NULL)
					allocater.deallocate(_data, _capacity);
				_data = new_data;
				_size = n;
			}
		}

		/////////////////////////////////
		
		void push_back(const value_type& value){
			if (_size == _capacity)
			{
				size_t new_capacity = (_capacity != 0) ? _capacity * 2 : 1;
				pointer _new_data = allocater.allocate(new_capacity);
				for (size_t i = 0; i < _size; i++)
				{
					allocater.construct(_new_data + i , _data[i]);
					allocater.destroy(_data + i);					
				}
				if (_data != NULL)
					allocater.deallocate(_data ,_capacity);
				_data = _new_data;
				_capacity = new_capacity;
			}
			allocater.construct(_data + _size, value);
			_size++;
		}

		/////////////////////////////////

		void pop_back(){
			if (_size > 0){
				allocater.destroy(_data + _size - 1);
				_size--;
			}
			else {
				exit(1);
			}
		}

		/////////////////////////////////

		iterator erase(iterator position) {
			size_t distance = position - _data;
			for (size_t i = distance; i < _size - 1; i++) {
				allocater.destroy(_data + i);
				allocater.construct(_data + i, _data[i + 1]);
				if (i + 1 == _size - 1)
					allocater.destroy(_data + i + 1);
			}
			if (distance == _size - 1)
				allocater.destroy(_data + distance);
			_size--;
			return _data + distance;
		}

		iterator erase (iterator first, iterator last){
			size_t i = first - _data;
			size_t j = first - _data;
			size_t dis = last - first;
			size_t begin_construct = last - _data;
			if (last - first == 0)
				return (_data + i);
			while (first != last)
			{
				allocater.destroy(&(*first));
				first++;
			}
			for (size_t i = begin_construct; i < _size ; i++){
				allocater.construct(_data + j, _data[i]);
				allocater.destroy(_data + i);
				j++;
			}
			_size -= (dis);
			return (_data + i);
		}

		////////////////////////////////

		iterator insert (iterator position, const value_type& val){
			size_t cords = position - _data;
			if (_size == _capacity)
				reserve(_capacity == 0 ? 1 : _capacity * 2);
			for (size_t i = _size; i > cords; i--){
				allocater.construct(_data + i, _data[i - 1]);
				allocater.destroy(_data + i - 1);
			}
			allocater.construct(_data + cords, val);
			_size++;
			return (_data + cords);
		}

    	void insert (iterator position, size_type n, const value_type& val)
		{
			size_type cords = (position) - _data;
			if(_size + n > _capacity)
			{
				if (_capacity + n > max_size())
					throw std::length_error("insert: position is out of range");
				reserve(_capacity + n);
			}
			for (size_type i = _size; i > cords; i--)
			{
				allocater.destroy(_data + i - 1);
				allocater.construct(_data + i + n - 1, _data[i - 1]);
			}
			for (size_type i = 0; i < n; i++)
				allocater.construct(_data + cords + i, val);
			_size += n;
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
		{
			size_type cords = (position) - _data;
			vector vec_tmp;
			while (first != last)
			{
				vec_tmp.push_back(*first);
				first++;
			}
			if(_size + vec_tmp.size() > _capacity)
				reserve(_capacity + vec_tmp.size());
			for (size_type i = _size; i > cords; --i)
			{
				allocater.destroy(&_data[i - 1]);
				allocater.construct(&_data[i + vec_tmp.size() -1], _data[i - 1]);
			}
			for (size_type i = 0; i < vec_tmp.size(); ++i)
				allocater.construct(&_data[cords + i], vec_tmp[i]);
			_size += vec_tmp.size();
		}

		///////////////////////////////////////////

		void reserve (size_type n){
			
			if (n > _capacity){
				pointer new_data = allocater.allocate(n);
				for (size_t i = 0; i < _size; i++){
					allocater.construct(new_data + i, _data[i]);
					allocater.destroy(_data + i);
				}
				if (_data != NULL)
					allocater.deallocate(_data, _capacity);
				_data = new_data;
				_capacity = n;
			}
		}

		///////////////////////////////////////////

		void swap (vector& x){

			pointer tmp_data = x._data;
			size_t tmp_capacity = x._capacity;
			size_t tmp_size = x._size;

			x._data = this->_data;
			x._capacity = this->_capacity;
			x._size = this->_size;

			this->_data = tmp_data;
			this->_capacity = tmp_capacity;
			this->_size = tmp_size;

		}


		//////////////////////////////////////////

		void assign (size_type n, const value_type& val){
			size_t new_capacity = n;
			clear();
			pointer new_data;
			new_data = allocater.allocate(new_capacity);
			for (size_t i = 0; i < n; i++)
				allocater.construct(new_data + i, val);
			if (_data != NULL)
				allocater.deallocate(_data, _capacity);
			_data = new_data;
			_size = n;
			_capacity = new_capacity;
		}

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = nullptr){
			clear();
			vector tmp;
			while (first != last)
			{
				tmp.push_back(*first);
				first++;
			}
			size_t difference = tmp.size();
			pointer new_data = allocater.allocate(difference);
			for (size_t i = 0; i < difference ; i++)
				allocater.construct(new_data + i, tmp[i]);
			if (_data != NULL)
				allocater.deallocate(_data, _capacity);
			_data = new_data;
			_capacity = difference;
			_size = difference;
		}
		//template <class U, class P>
		//	bool operator<(const vector<U>& obj, const vector<P>& obj1) {return (obj._size < obj1._size);}
	private :
		pointer 		_data;
		allocator_type	allocater;
		size_t			_size;
		size_t			_capacity;
		template <typename U, class A>
			friend bool operator== (const vector<U,A>& lhs, const vector<U,A>& rhs);
			template <typename U, class A>
			friend bool operator!= (const vector<U,A>& lhs, const vector<U,A>& rhs);
			template <typename U, class A>
			friend bool operator<  (const vector<U,A>& lhs, const vector<U,A>& rhs);
			template <typename U, class A>
			friend bool operator<= (const vector<U,A>& lhs, const vector<U,A>& rhs);
			template <typename U, class A>
			friend bool operator>  (const vector<U,A>& lhs, const vector<U, A>& rhs);
			template <typename U, class A>
			friend bool operator>= (const vector<U,A>& lhs, const vector<U,A>& rhs);
			template <typename U, class A>
			friend void swap (vector<U>& x, vector<U,A>& y);
};
//------------lexicographical_compare------------//
template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
    {
        while (first1!=last1)
        {
          if (first2==last2 || *first2<*first1) return false;
          else if (*first1<*first2) return true;
          ++first1; ++first2;
        }
        return (first2!=last2);
    }

// template <class InputIterator1, class InputIterator2, class Compare>
//     bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
//     {
        
//     }
//------------equal------------//
template <class InputIterator1, class InputIterator2>
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1!=last1) {
        if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
          return false;
        ++first1; ++first2;
  }
        return true;
    }
template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
    {
        while (first1!=last1) {
        if (!pred(*first1,*first2))
          return false;
        ++first1; ++first2;
  }
        return true;
    }
//------------Non-member function overloads------------//
template <class T, class A>  
    bool operator== (const vector<T,A>& lhs, const vector<T,A>& rhs)
    {
    // return !(lhs < rhs) && !(rhs < lhs);
        if (lhs.capacity() != rhs.capacity())
            return(false);
        return(ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
template <class T, class A>
    bool operator!= (const vector<T,A>& lhs, const vector<T,A>& rhs)
    {
        if (lhs.size() != rhs.size())
            return(1);
        if((lhs.capacity() != rhs.capacity()))
            return(1);
        return(!(ft::equal(lhs.begin(), lhs.end(), rhs.begin())));
    }
template <class T, class A>  
    bool operator< (const vector<T,A>& lhs, const vector<T,A>& rhs)
    {
        if (lhs.capacity() < rhs.capacity())
            return(true);
        else if (lhs.capacity() > rhs.capacity())
            return(false);
        else
            return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
template <class T, class A>  
    bool operator<= (const vector<T,A>& lhs, const vector<T,A>& rhs)
    {

        if (lhs.capacity() < rhs.capacity())
            return(true);
        else if (lhs.capacity() > rhs.capacity())
            return(false);
        else
         return((ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())) || (lhs == rhs));
    }
template <class T, class A>
    bool operator>  (const vector<T,A>& lhs, const vector<T,A>& rhs)
    {
		return rhs < lhs;
    }
template <class T, class A>  
    bool operator>= (const vector<T,A>& lhs, const vector<T,A>& rhs)
    {
        return (rhs <= lhs);
    }
template <class T, class A>
    void swap (vector<T,A>& x, vector<T,A>& y)
    {
        x.swap(y);
    }
}


#endif