/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:32:43 by mmanouze          #+#    #+#             */
/*   Updated: 2023/03/05 22:58:45 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP


namespace ft
{
    //-------ENABLE_IF----------//

    template<bool true_false, class T = void> 
        struct enable_if {};

    template<class T> 
        struct enable_if<true, T> 
        {
            typedef T type;
        };

    //---------IS_INTEGRAL--------//

    template <typename T>
    struct is_integral {
        static const bool value = false;
    };

    template <>
    struct is_integral<long> {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned int> {
        static const bool value = true;
    };

    template <>
    struct is_integral<int> {
        static const bool value = true;
    };
} 



#endif
