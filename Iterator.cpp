/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:10:34 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/11 15:23:05 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iostream>

template <class T>
class Iterator{
	public :
		Iterator(){
		}
		~Iterator(){
		}
		Iterator &operator*(Iterator const &iterobj) const {return (*data_);}
		Iterator &operator++() {++data_; return (*this)}
		Iterator &operato++(int){
			Iterator tmpiter(*this);
			++data_;
			return (*this);
		}
	private :
		Iterator *data_;
};


#endif