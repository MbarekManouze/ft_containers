/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits_map.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:13:51 by mmanouze          #+#    #+#             */
/*   Updated: 2023/03/05 13:33:20 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_MAP_HPP
# define ITERATOR_TRAITS_MAP_HPP


#include "map_iterator.hpp"

namespace ft
{

  template<class Iterator>
  class iterator_traits_map{
    public:
          typedef typename Iterator::difference_type    difference_type;
          typedef typename Iterator::value_type         value_type;
          typedef typename Iterator::pointer            pointer;
          typedef typename Iterator::reference          reference;
          typedef typename Iterator::iterator_category  iterator_category;
  };

  template <class T>
  class iterator_traits_map<T*>
  {
    public:
          typedef std::ptrdiff_t                  difference_type;
          typedef T                               value_type;
          typedef T*                              pointer;
          typedef T&                              reference;
          typedef std::bidirectional_iterator_tag iterator_category;
  };

  template <class T>
  class iterator_traits_map<const T*>
  {
    public:
          typedef std::ptrdiff_t                  difference_type;
          typedef T                               value_type;
          typedef const T*                        pointer;
          typedef const T&                        reference;
          typedef std::bidirectional_iterator_tag iterator_category;
  };

}







#endif