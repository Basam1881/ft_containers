/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vTPrinter.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:02:10 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/17 11:38:19 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"

template<typename T>
void printStdVec(std::vector<T> v) {
  std::cout << "v             : ";
  for (typename std::vector<T>::iterator it = v.begin(); it != v.end(); it++)
    std::cout << *it << ' ';
  std::cout << std::endl;
}

template<typename T>
void  printStdVecSize(std::vector<T> v) {
  std::cout << "v size        : " << v.size() << std::endl;
}

template<typename T>
void  printStdVecCap(std::vector<T> v) {
  std::cout << "v capacity    : " << v.capacity() << std::endl;
}

template<typename T>
void printMyVec(ft::vector<T> ft_v) {
  std::cout << "ft_v          : ";
  for (typename ft::vector<T>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
    std::cout << *it << ' ';
  std::cout << std::endl;
}

template<typename T>
void  printMyVecSize(ft::vector<T> ft_v) {
  std::cout << "ft_v size     : " << ft_v.size() << std::endl;
}

template<typename T>
void  printMyVecCap(ft::vector<T> ft_v) {
  std::cout << "ft_v capacity : " << ft_v.capacity() << std::endl;
}

template<typename T>
void  printAll(std::vector<T> v, ft::vector<T> ft_v) {
  printStdVec<T>(v);
  printMyVec<T>(ft_v);
  printStdVecSize<T>(v);
  printMyVecSize<T>(ft_v);
  printStdVecCap<T>(v);
  printMyVecCap<T>(ft_v);
}
