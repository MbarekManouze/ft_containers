/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_Iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:23:29 by mmanouze          #+#    #+#             */
/*   Updated: 2023/03/05 22:41:49 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOE_HPP
# define REVERSE_ITERATOE_HPP

#include <iostream>
#include <cstddef>
#include "Iterator.hpp"
#include "Iterator_traits.hpp"

namespace ft 
{
        template <class T> class Reverse_Iterator
        {
                private :
                        T reverse_iterator_data;
                public :

                        //--------------------member types------------------//

                        typedef             T                                                underlynig_iterator;
                        typedef typename    ft::iterator_traits<T>::iterator_category        iterator_category;
                        typedef typename    ft::iterator_traits<T>::value_type               value_type;
                        typedef typename    ft::iterator_traits<T>::difference_type          difference_type;
                        typedef typename    ft::iterator_traits<T>::pointer                  pointer;
                        typedef typename    ft::iterator_traits<T>::reference                reference;


                        //---------------------base------------------------//


                        underlynig_iterator             base() const {return (reverse_iterator_data);}



                        //-----------------constructors----------------------//


                        Reverse_Iterator():reverse_iterator_data() {}
                        ~Reverse_Iterator() {}
                        explicit Reverse_Iterator( underlynig_iterator object):reverse_iterator_data(object){}
                        template <class iter>
                                Reverse_Iterator(const Reverse_Iterator<iter>& object):reverse_iterator_data(object.base()){}
        
                        //------------------operators-------------------------//

                        bool                            operator!=(const Reverse_Iterator& other) const {return (reverse_iterator_data != other.reverse_iterator_data);}
                        bool                            operator<(const Reverse_Iterator& other) const {return (reverse_iterator_data > other.reverse_iterator_data);}
                        bool                            operator<=(const Reverse_Iterator& other) const {return (reverse_iterator_data >= other.reverse_iterator_data);}
                        bool                            operator>(const Reverse_Iterator& other) const {return (reverse_iterator_data < other.reverse_iterator_data);}
                        bool                            operator>=(const Reverse_Iterator& other) const {return (reverse_iterator_data <= other.reverse_iterator_data);}
                        pointer                         operator->() const {return &(operator*());}
                        reference                       operator[] (difference_type n) const {if (n < 0) {std::cout << "throw exep" << std::endl; /*exit(1);*/} return (reverse_iterator_data[-n-1]);}
                        reference                       operator*() const {underlynig_iterator tmp = reverse_iterator_data; return (*(--tmp));}
                        Reverse_Iterator                operator+(difference_type n) const {return Reverse_Iterator(reverse_iterator_data - n);}
                        Reverse_Iterator                operator-(difference_type n) const {return Reverse_Iterator(reverse_iterator_data + n);}
                        Reverse_Iterator                operator++(int) {Reverse_Iterator tmp = *this;--(reverse_iterator_data); return (tmp);}
                        Reverse_Iterator                operator--(int) {Reverse_Iterator tmp = *this; ++(reverse_iterator_data); return (tmp);}
                        Reverse_Iterator&               operator+=(difference_type n) { reverse_iterator_data = reverse_iterator_data - n; return (*this);}
                        Reverse_Iterator&               operator-=(difference_type n) { reverse_iterator_data = reverse_iterator_data + n; return (*this);}
                        Reverse_Iterator&               operator++() {--(reverse_iterator_data); return (*this);}
                        Reverse_Iterator&               operator--() { ++(reverse_iterator_data); return (*this);}


                        //---------------------relational operators------------------------//


                        template <class temp>
                                difference_type operator-(const Reverse_Iterator<temp>& object) const {return (object.base() - reverse_iterator_data);}
                        template <typename P, typename P2>
                                friend bool operator< (const Reverse_Iterator<P>& obj, const Reverse_Iterator<P2>& obj2);
                        template <class P, class P2>
                                friend bool operator== (const Reverse_Iterator<P>& obj, const Reverse_Iterator<P2>& obj2);
                        template <class P, class P2>
                                friend bool operator!= (const Reverse_Iterator<P>& obj, const Reverse_Iterator<P2>& obj2);
                        template <class P, class P2>
                                friend bool operator<= (const Reverse_Iterator<P>& obj, const Reverse_Iterator<P2>& obj2);
                        template <class P, class P2>
                                friend bool operator> (const Reverse_Iterator<P>& obj, const Reverse_Iterator<P2>& obj2);
                        template <class P, class P2>
                                friend bool operator>= (const Reverse_Iterator<P>& obj, const Reverse_Iterator<P2>& obj2);
        };
        template <typename _T_>
                Reverse_Iterator<_T_>      operator+(typename Reverse_Iterator<_T_>::difference_type n, const Reverse_Iterator<_T_>& object) 
                {
                        return (object + n);
                }
        template <typename P, typename P2>
                bool operator< (const Reverse_Iterator<P>& obj, const Reverse_Iterator<P2>& obj2){ return (obj.reverse_iterator_data > obj2.reverse_iterator_data);}
        template <class P, class P2>
                bool operator== (const Reverse_Iterator<P>& obj, const Reverse_Iterator<P2>& obj2){ return (obj.reverse_iterator_data == obj2.reverse_iterator_data);}
        template <class P, class P2>
                bool operator!= (const Reverse_Iterator<P>& obj, const Reverse_Iterator<P2>& obj2){return (obj.reverse_iterator_data != obj2.reverse_iterator_data);}
        template <class P, class P2>
                bool operator<= (const Reverse_Iterator<P>& obj, const Reverse_Iterator<P2>& obj2){return (obj.reverse_iterator_data >= obj2.reverse_iterator_data);}
        template <class P, class P2>
                bool operator> (const Reverse_Iterator<P>& obj, const Reverse_Iterator<P2>& obj2){return (obj.reverse_iterator_data < obj2.reverse_iterator_data);}
        template <class P, class P2>
                bool operator>= (const Reverse_Iterator<P>& obj, const Reverse_Iterator<P2>& obj2){ return (obj.reverse_iterator_data <= obj2.reverse_iterator_data);}

        #endif

}

