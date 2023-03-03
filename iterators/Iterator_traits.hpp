/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:34:36 by mmanouze          #+#    #+#             */
/*   Updated: 2023/03/02 15:56:38 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP
#include <cstddef>
#include<iostream>
#include"Iterator.hpp"

//template<>
//class iterator_traits<int> {
  
//}

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

#endif