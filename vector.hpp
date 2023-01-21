/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:52:11 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/21 23:48:52 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <new>
#include <memory>
#include "Iterator.hpp"

template < class T, class Alloc = std::allocator<T> > class vector
{
	public :

		typedef Iterator<T> 					iterator;
		typedef T 								value_type;
		typedef Alloc							allocator_type;
		typedef T& 								reference;
		typedef const T* 						const_reference;
		typedef T* 								pointer;
		typedef const T* 						const_pointer;
		//typedef typename Alloc::diffrence_type 	difference_type;
		typedef typename Alloc::size_type 		size_type; 
		typedef T* 								Iterator;
		typedef const T* 						const_Iterator;
		
		vector():_size(0), _capacity(0), allocater(), _data(0){}
		vector(size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: allocater(alloc),_capacity(n), _size(n){
			_data = allocater.allocate(n);
			for (size_t i = 0; i < n; i++)
				allocater.construct(_data + i, val);
		}
		~vector(){ allocater.deallocate(_data, _capacity); }

		value_type &operator[](size_t index){ return (_data[index]); }

		iterator 				begin() { return (iterator (_data)); }
		iterator 				end() { return (iterator (_data + _size)); }
		const_Iterator 			cbegin() const throw() { return (iterator (_data)); }
		const_Iterator 			cend() const throw() { return (iterator (_data + _size)); }
		size_type 				size() const { return (_size); }
		size_t 					max_size() const { return std::numeric_limits<std::size_t>::max() / sizeof(T); }
		size_type 				capacity() const { return (_capacity); }
		bool 					empty() const { return (_size == 0 ? true : false); }
		reference     			at(size_type n) { if (n > 0 && n < _capacity) { return (_data[n]); } }
		const_reference     	at(size_type n) const { if (n > 0 && n < _capacity) { return (_data[n]); } }
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
				for (size_t i = 0; i < n ; i++)
					allocater.construct(_data + i, 0);
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
						allocater.construct(_new_data + i, _data[i]);
					for (size_t i = _size ; i < new_capacity ; i++)
						allocater.construct(_new_data + i , 0);
					for (size_t i = 0; i < _capacity ; i++)
						allocater.destroy(_data + i);
					allocater.deallocate(_data, _capacity);
					_data = _new_data;
					_capacity = new_capacity;
					_size = n;
				}
				else if (n < _size){
					pointer _new_data = allocater.allocate(n);
					for (size_t i = 0; i < n; i++)
						allocater.construct(_new_data + i, _data[i]);
					for (size_t i = _size ; i < n ; i++)
						allocater.construct(_new_data + i, 0);
					for (size_t i = 0; i < _capacity; i++)
						allocater.destroy(_data + i);	
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
					allocater.construct(new_data + i, _data[i]);
				for (size_t i = this->size(); i < n; i++)
					allocater.construct(new_data + i, value);
				for (size_t i = 0; i < _capacity; i++)
					allocater.destroy(_data + i);
				allocater.deallocate(_data, _capacity);
				_data = new_data;
				_capacity = new_capacity;
				_size = n;
			}
			else{
				pointer new_data = allocater.allocate(_capacity);
				for (size_t i = 0; i < n ;i++)
					allocater.construct(new_data + i, _data[i]);
				for (size_t i = 0; i < this->size() ;i++)
					allocater.destroy(_data + i);
				allocater.deallocate(_data, _capacity);
				_data = new_data;
				_size = n;
			}
		}

		/////////////////////////////////
		
		void push_back(const value_type& value){

			// RESIZE FUNCTION IMPLEMENTATION

			if (_size == 0)
				_capacity *= 2;
			if (_size == _capacity)
			{
				size_t new_capacity = _capacity ? _capacity * 2 : 1;
				pointer _new_data = allocater.allocate(new_capacity);
				for (size_t i = 0; i < _size; i++)
					allocater.construct(_new_data + i , _data[i]);
				for (size_t i = _size ; i < new_capacity ; i++)
					allocater.construct(_new_data + i, 0);
				for (size_t i = 0; i < _size; i++)
					allocater.destroy(_data + i);
				allocater.deallocate(_data ,_size);
				_data = _new_data;
				_capacity = new_capacity;
			}

			//DONE IMPLEMENTING RESIZE FUNC()

			_data[_size] = value;
			_size++;
			//std::cout << "alright "<< std::endl;
		}

		/////////////////////////////////

		iterator erase (iterator position){
			for (size_t i = 0; i < _size; i++){
				if (_data[i] == *position){
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
			if (_size == _capacity)
				_capacity *= 2;
			new_data = allocater.allocate(_capacity);
			_size++;
			for (size_t i = 0; i < _size; i++){
				if (&position == _data + i){
					tmp = i;
					allocater.construct(new_data + i, val);
					i++;
					while (tmp < _size && i < _size){
						allocater.construct(new_data + i, _data[tmp]);
						tmp++;
						i++;
					}
					for (size_t i = 0; i < _capacity; i++)
						allocater.destroy(_data + i);
					allocater.deallocate(_data, _capacity);
					_data = new_data;
					return (position);
				}				
				allocater.construct(new_data + i, _data[i]);
			}
			return (position);
		}

		void insert (iterator position, size_type n, const value_type& val){
			size_t 	tmp;
			pointer new_data;
			if (_size == _capacity)
				_capacity *= 2;
			new_data = allocater.allocate(_capacity);
			_size += n;
			for (size_t i = 0; i < _size; i++){
				if (&position == _data + i){
					tmp = i;
					while (n > 0)
					{
						allocater.construct(new_data + i, val);
						n--;
					}
					i++;
					while (tmp < _size && i < _size){
						allocater.construct(new_data + i, _data[tmp]);
						tmp++;
						i++;
					}
					for (size_t i = 0; i < _capacity; i++)
						allocater.destroy(_data + i);
					allocater.deallocate(_data, _capacity);
					_data = new_data;
				}				
				allocater.construct(new_data + i, _data[i]);
			}
		}


	private :
		T				*_data;
		allocator_type	allocater;
		size_t			_size;
		size_t			_capacity;
};

#endif