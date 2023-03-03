/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:36:32 by lelbakna          #+#    #+#             */
/*   Updated: 2023/03/03 11:49:15 by mmanouze         ###   ########.fr       */
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
} 



#endif
