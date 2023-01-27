/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:52:11 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/27 18:42:53 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <new>
#include <memory>
#include "Iterator.hpp"
#include "reverse_Iterator.hpp"

namespace ft {
template < class T, class Alloc = std::allocator<T> > class vector
{
	public :

		typedef Iterator<T> 					iterator;
		typedef T 								value_type;
		typedef Alloc							allocator_type;
		typedef T& 								reference;
		typedef const T 						const_reference;
		typedef T* 								pointer;
		typedef const T* 						const_pointer;
		typedef typename std::ptrdiff_t 	difference_type;
		typedef typename Alloc::size_type 		size_type; 
		typedef T* 								Iterator;
		typedef const T* 						const_Iterator;
		
		explicit vector (const allocator_type& alloc = allocator_type()): _data(0),allocater(alloc),_size(0), _capacity(0){}
		explicit vector (size_type n, const value_type& val = value_type(),                 const allocator_type& alloc = allocator_type())
		: allocater(alloc), _size(n),_capacity(n){
			_data = allocater.allocate(n);
			for (size_t i = 0; i < n; i++)
				allocater.construct(_data + i, val);
		}
		vector (const vector& x){
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
		{
			allocater = alloc;
			_size = (last) - (first);
			_capacity = _size;
			_data = allocater.allocate(_size);
			for (size_type i = 0; i < _size ; i++)
			{
				allocater.construct(&_data[i], *first);
				first++;
			}
		}

		value_type &operator[](size_t index)const{ return (_data[index]); }
		vector  &operator=(const vector& x){
			this->allocater = x.allocater;
			this->_capacity = x._capacity;
			this->_size = x._size;
			this->_data = allocater.allocate(_capacity);
			for (size_t i = 0; i < _size; i++)
			{
				allocater.construct(_data + i, x._data[i]);
				//this->_data[i] = x._data[i];
			}
			return (*this);
		}

		iterator 				begin() { return (iterator (_data)); }
		iterator 				end() { return (iterator (_data + _size)); }
		iterator 				rbegin() { return (iterator (_data + _size)); }
		iterator 				rend() { return (iterator (_data)); }
		size_type 				size() const { return (_size); }
		size_t 					max_size() const { return std::numeric_limits<std::size_t>::max() / sizeof(T); }
		size_type 				capacity() const { return (_capacity); }
		bool 					empty() const { return (_size == 0 ? true : false); }
		reference     			at(size_type n) { if (n > 0 && n < _capacity) { return (_data[n]); } else {exit(1);} }
		const_reference     	at(size_type n) const { if (n > 0 && n < _capacity) { return (_data[n]); } else {exit(1);} }
		reference 				back() { return (_data[_size - 1]); }
		const_reference 		back() const { return (_data[_size - 1]); }
		reference 				front() { return (_data[0]); }
		const_reference 		front() const { return (_data[0]); }
		allocator_type 			get_allocator() const { return (allocater); }

		// RESIZE METHOD DONE AND WELL TESTED //

		void 			resize (size_type n)
		{
			if (_size == 0){
				_data = allocater.allocate(n);
				//for (size_t i = 0; i < n ; i++)
				//	allocater.construct(_data + i, 0);
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
					//for (size_t i = _size ; i < new_capacity ; i++)
					//	allocater.construct(_new_data + i , 0);
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

			// RESIZE FUNCTION IMPLEMENTATION

			//if (_size == 0)
			//	_capacity *= 2;
			if (_size == _capacity)
			{
				size_t new_capacity = (_capacity != 0) ? _capacity * 2 : 1;
				//this->reserve(new_capacity);
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

			//DONE IMPLEMENTING RESIZE FUNC()

			allocater.construct(_data + _size, value);
			_size++;
			//std::cout << "alright "<< std::endl;
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

		iterator erase (iterator position){
			size_t p = 0;
			for (size_t i = 0; i < _size; i++){
				if (_data[i] == *position){
					p = i;
					size_t t = i + 1;
					while (i < _size && t <= _size){
						_data[i] = _data[t];
						i++;
						t++;
					}
				}
			}
			_size--;
			return (position);
		}

		//iterator erase(iterator position) {
		//	for (iterator i = position; i != end() - 1; ++i)
		//		*i = *(i + 1);
		//	_size--;
		//	return position;
		//}

		iterator erase (iterator first, iterator last){
			size_t diffrence;
			for (size_t i = 0; i < _size ;i++){
				if (*first == _data[i]){
					size_t t = i;
					while (_data[t] != *last)
						t++;
					diffrence = t - i;
					while (i < _size && t <= _size){
						_data[i] = _data[t];
						i++;
						t++;
					}
				}
			}
			_size -= diffrence;
			return (first);
		}

		////////////////////////////////


		iterator insert (iterator position, const value_type& val){
			size_t 	tmp;
			pointer new_data;
			if (_capacity == 0)
				_capacity = 1;
			else if (_size == _capacity)
				_capacity *= 2;
			new_data = allocater.allocate(_capacity);
			_size++;
			for (size_t i = 0; i < _size; i++){
				if (&position == _data + i){
					tmp = i;
					allocater.construct(new_data + i, val);
					position.get_iterator() = (new_data + i);
					i++;
					while (tmp < _size && i < _size){
						allocater.construct(new_data + i, _data[tmp]);
						allocater.destroy(_data + i);
						tmp++;
						i++;
					}
					if (_data != NULL)
						allocater.deallocate(_data, _capacity);
					_data = new_data;
					return (position);
				}				
				allocater.construct(new_data + i, _data[i]);
				allocater.destroy(_data + i);
			}
			return (position);
		}

		void insert (iterator position, size_type n, const value_type& val){
			size_t 	tmp;
			pointer new_data;
			//if (_capacity == 0 || n > (_capacity * 2))
			//	_capacity = n;
			//else if (_size == _capacity || n > _capacity)
			//	_capacity *= 2;
			_capacity += n;
			new_data = allocater.allocate(_capacity);
			_size += n;
			for (size_t i = 0; i < _size; i++){
				if (&position == _data + i){
					tmp = i;
					while (n > 0)
					{
						allocater.construct(new_data + i, val);
						i++;
						n--;
					}
					while (tmp < _size && i < _size){
						allocater.construct(new_data + i, _data[tmp]);
						allocater.destroy(_data + i);
						tmp++;
						i++;
					}
					if (_data != NULL)
						allocater.deallocate(_data, _capacity);
					_data = new_data;
					return ;
				}				
				allocater.construct(new_data + i, _data[i]);
				allocater.destroy(_data + i);
			}
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = nullptr){
			size_t diffrence = last - first;
			_capacity += diffrence;
			_size += diffrence;
			pointer new_data = allocater.allocate(_capacity);
			for (size_t i = 0; i < diffrence ; i++)
			for (size_t i = 0; i < _size ;i++){
				if (&position == _data + i){
					size_t tmp = i;
					while (diffrence > 0){
						allocater.construct(&new_data[i], *first);
						i++;
						first++;
						diffrence--;
					}
					while (i < _size){
						allocater.construct(new_data + i, _data[tmp]);
						allocater.destroy(_data + i);
						tmp++;
						i++;
					}
					if (_data != NULL)
						allocater.deallocate(_data, _capacity);
					_data = new_data;
					return ;
				}
				allocater.construct(new_data + i, _data[i]);
				allocater.destroy(_data + i);
			}
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
			pointer new_data;
			new_data = allocater.allocate(new_capacity);
			for (size_t i = 0; i < n; i++){
				allocater.construct(new_data + i, val);
				if (i < _size)
					allocater.destroy(_data + i);
			}
			allocater.deallocate(_data, _capacity);
			_data = new_data;
			_size = n;
			_capacity = new_capacity;
		}
		
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = nullptr){
			
			size_t difference = last - first;
			pointer new_data = allocater.allocate(difference);

			for (size_t i = 0; i < difference ; i++){
				allocater.construct(new_data + i, *first);
				if (i < _size)
					allocater.destroy(_data + i);
				first++;
			}
			allocater.deallocate(_data, _capacity);
			_data = new_data;
			_capacity = difference;
			_size = difference;
		}


	private :
		T				*_data;
		allocator_type	allocater;
		size_t			_size;
		size_t			_capacity;
		template <typename U>
			friend bool operator== (const vector<U>& lhs, const vector<U>& rhs);
			template <typename U>
			friend bool operator!= (const vector<U>& lhs, const vector<U>& rhs);
			template <typename U>
			friend bool operator<  (const vector<U>& lhs, const vector<U>& rhs);
			template <typename U>
			friend bool operator<= (const vector<U>& lhs, const vector<U>& rhs);
			template <typename U>
			friend bool operator>  (const vector<U>& lhs, const vector<U>& rhs);
			template <typename U>
			friend bool operator>= (const vector<U>& lhs, const vector<U>& rhs);
			template <typename U>
			friend void swap (vector<U>& x, vector<U>& y);
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
template <class T>  
    bool operator== (const vector<T>& lhs, const vector<T>& rhs)
    {
    // return !(lhs < rhs) && !(rhs < lhs);
        if (lhs.capacity() != rhs.capacity())
            return(false);
        return(ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
template <class T>  
    bool operator!= (const vector<T>& lhs, const vector<T>& rhs)
    {
        if (lhs.size() != rhs.size())
            return(1);
        if((lhs.capacity() != rhs.capacity()))
            return(1);
        return(!(ft::equal(lhs.begin(), lhs.end(), rhs.begin())));
    }
template <class T>  
    bool operator< (const vector<T>& lhs, const vector<T>& rhs)
    {
        if (lhs.capacity() < rhs.capacity())
            return(false);
        else if (lhs.capacity() > rhs.capacity())
            return(true);
        else
            return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
template <class T>  
    bool operator<= (const vector<T>& lhs, const vector<T>& rhs)
    {

        if (lhs.capacity() < rhs.capacity())
            return(false);
        else if (lhs.capacity() > rhs.capacity())
            return(true);
        else
        // return((ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())) || (lhs == rhs));
            return !(lhs > rhs);
    }
template <class T>  
    bool operator>  (const vector<T>& lhs, const vector<T>& rhs)
    {

    // return rhs < lhs;
         if (lhs.capacity() > rhs.capacity())
            return(false);
        else if (lhs.capacity() < rhs.capacity())
            return(true);
        else
            return (!(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())));
    }
template <class T>  
    bool operator>= (const vector<T>& lhs, const vector<T>& rhs)
    {
         if (lhs.capacity() > rhs.capacity())
            return(false);
        else if (lhs.capacity() < rhs.capacity())
            return(true);
        else
        // return(!(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())) || !(lhs == rhs));
            return !(lhs < rhs);
    }
template <class T>
    void swap (vector<T>& x, vector<T>& y)
    {
        x.swap(y);
    }
}


#endif