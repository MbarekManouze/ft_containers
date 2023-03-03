/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelbakna <lelbakna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:36:32 by lelbakna          #+#    #+#             */
/*   Updated: 2023/01/23 15:16:14 by lelbakna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP
namespace ft
{
    //------------enable_if------------//
    template<bool Cond, class T = void> 
        struct enable_if {};
    template<class T> 
        struct enable_if<true, T> 
        { 
            typedef T type;
        };
    template <typename T>
    struct is_integral {
        static const bool value = false;
    };
    // specialized function
    template <>
    struct is_integral<int> {
        static const bool value = true;
    };
    template <>
    struct is_integral<long> {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned int> {
        static const bool value = true;
    };
} // namespace ft
#endif
// template <typename T, typename Allocator = std::allocator<T> >
// class vector {
// public:
//     // ... other member functions and data members ...

//     using allocator_type = Allocator;
//     using iterator = T*;

//     template <typename InputIterator>
//     vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
//         : _alloc(alloc), _data(nullptr), _size(0), _capacity(0) {
//         _size = std::distance(first, last);
//         _capacity = _size;
//         _data = _alloc.allocate(_size);
//         for (iterator it = _data; first != last; ++first, ++it) {
//             _alloc.construct(it, *first);
//         }
//     }
//     // ... other constructors, such as default constructor, copy constructor, move constructor, etc. ...
// };

