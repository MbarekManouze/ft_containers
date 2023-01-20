/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:52:11 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/19 19:34:30 by mmanouze         ###   ########.fr       */
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
		: allocater(alloc),_capacity(n), _size(0){
			_data = allocater.allocate(n);
		}
		~vector(){ allocater.deallocate(_data, _capacity); }

		value_type &operator[](size_t index){ return (_data[index]); }

		iterator 		begin() { return (iterator (_data)); }
		iterator 		end() { return (iterator (_data + _size)); }
		const_Iterator 	cbegin() const throw() { return (iterator (_data)); }
		const_Iterator 	cend() const throw() { return (iterator (_data + _size)); }
		size_type 		size() const { return (_size); }
		size_t 			max_size() const { return std::numeric_limits<std::size_t>::max() / sizeof(T); }
		size_type 		capacity() const { return (_capacity); }
		bool 			empty() const { return (_size == 0 ? true : false); }
		

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
						new_capacity = n;
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

		void resize (size_type n, const T& value){
			if (n > this->size()){
				size_t new_capacity;
				if (n > (_capacity * 2))
					new_capacity = n;
				if (n > _capacity)
					new_capacity = _capacity * 2;
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

			if (_size == _capacity)
			{
				//std::cout << "capacity     :  " << _capacity << std::endl;
				size_t new_capacity = _capacity ? _capacity * 2 : 1;
				//std::cout << "new_capacity :  " << new_capacity << std::endl;
				pointer _new_data = allocater.allocate(new_capacity);
				for (size_t i = 0; i < _size; i++)
					allocater.construct(_new_data + i , _data[i]);
				//for (size_t i = _size ; i < new_capacity ; i++)
				//	allocater.construct(_new_data + i, 0);
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


	private :
		T				*_data;
		allocator_type	allocater;
		size_t			_size;
		size_t			_capacity;
};

#endif