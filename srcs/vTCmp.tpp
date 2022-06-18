/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vTCmp.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:39:23 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/18 11:31:08 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"

template<typename T>
bool cmpVecs(std::vector<T> & v, ft::vector<T> & ft_v) {
  typename std::vector<T>::iterator it1 = v.begin();
  typename ft::vector<T>::iterator it2 = ft_v.begin();
  for ( ; it1 != v.end() && it2 != ft_v.end(); it1++, it2++)
    if (*it1 != *it2)
      return false;
  return true;
}

template<typename T>
bool  cmpVecsSize(std::vector<T> & v, ft::vector<T> & ft_v) {
  return (v.size() == ft_v.size() ? true : false);
}

template<typename T>
bool  cmpVecsCap(std::vector<T> & v, ft::vector<T> & ft_v) {
  return (v.capacity() == ft_v.capacity() ? true : false);
}

template<typename T>
bool  cmpAll(std::vector<T> & v, ft::vector<T> & ft_v) {
  return (cmpVecs<T>(v, ft_v) && cmpVecsSize<T>(v, ft_v) && cmpVecsCap<T>(v, ft_v));
}
