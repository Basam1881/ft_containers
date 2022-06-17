/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTests.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:02:45 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/17 11:09:04 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORTESTS_CPP
# define VECTORTESTS_CPP

# define GREEN "\033[38;5;46m"
# define WHITE "\033[1;37m"
# define BLUE "\033[1;36m"
# define YELLOW "\033[1;33m"
# define RED "\033[1;31m"
# define PURPLE "\033[1;35m"
# define RESET "\033[m"

template<typename T>
void printStdVec(std::vector<T> v);

template<typename T>
void  printStdVecSize(std::vector<T> v);

template<typename T>
void  printStdVecCap(std::vector<T> v);

template<typename T>
void printMyVec(ft::vector<T> ft_v); 

template<typename T>
void  printMyVecSize(ft::vector<T> ft_v);

template<typename T>
void  printMyVecCap(ft::vector<T> ft_v);

template<typename T>
void  printAll(std::vector<T> v, ft::vector<T> ft_v);

#include "vTPrinter.tpp"

template<typename T>
bool cmpVecs(std::vector<T> v, ft::vector<T> ft_v);

template<typename T>
bool  cmpVecsSize(std::vector<T> v, ft::vector<T> ft_v);

template<typename T>
bool  cmpVecsCap(std::vector<T> v, ft::vector<T> ft_v);

template<typename T>
bool  cmpAll(std::vector<T> v, ft::vector<T> ft_v);

#include "vTCmp.tpp"

bool  vectorBasic(bool printAllTests);

#endif
