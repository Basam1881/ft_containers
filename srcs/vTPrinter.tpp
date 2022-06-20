/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vTPrinter.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:02:10 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/20 18:45:00 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include "vectorTests.hpp"

template<typename T>
void printStdVec(std::vector<T> v) {
  std::cout << PURPLE << "v             : " << YELLOW;
  for (typename std::vector<T>::iterator it = v.begin(); it != v.end(); it++)
    std::cout << *it << ' ';
  std::cout << RESET << std::endl;
}

template<typename T>
void  printStdVecSize(std::vector<T> v) {
  std::cout << PURPLE << "v size        : " << YELLOW << v.size() << RESET << std::endl;
}

template<typename T>
void  printStdVecCap(std::vector<T> v) {
  std::cout << PURPLE << "v capacity    : " << YELLOW << v.capacity() << RESET << std::endl;
}

template<typename T>
void printMyVec(ft::vector<T> ft_v) {
  std::cout << PURPLE << "ft_v          : " << YELLOW;
  for (typename ft::vector<T>::iterator it = ft_v.begin(); it != ft_v.end(); it++)
    std::cout << *it << ' ';
  std::cout << RESET << std::endl;
}

template<typename T>
void  printMyVecSize(ft::vector<T> ft_v) {
  std::cout << PURPLE << "ft_v size     : " << YELLOW << ft_v.size() << RESET << std::endl;
}

template<typename T>
void  printMyVecCap(ft::vector<T> ft_v) {
  std::cout << PURPLE << "ft_v capacity : " << YELLOW << ft_v.capacity() << RESET << std::endl;
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
