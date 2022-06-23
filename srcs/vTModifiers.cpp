/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vTModifiers.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 07:51:19 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/23 09:51:02 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include "vectorTests.hpp"

bool  vectorModifiersTest1(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.assign(iterator, iterator)      : " << RESET;
  
  std::vector<int> v;
  ft::vector<int> ft_v;
  std::vector<int> v1(5, 1);
  ft::vector<int> ft_v1(5, 1);
  std::vector<int> v2(15, 2);
  ft::vector<int> ft_v2(15, 2);
  std::vector<int> v3(20, 3);
  ft::vector<int> ft_v3(20, 3);
  v.assign(v.begin(), v.end());
  ft_v.assign(ft_v.begin(), ft_v.end());
  v1.assign(v.begin(), v.end());
  ft_v1.assign(ft_v.begin(), ft_v.end());
  v2.assign(v3.begin(), v3.end());
  ft_v2.assign(ft_v3.begin(), ft_v3.end());
  v3.assign(v.begin(), v.end());
  ft_v3.assign(ft_v.begin(), ft_v.end());
  v3.assign(v2.begin(), v2.end());
  ft_v3.assign(ft_v2.begin(), ft_v2.end());
  
  if (cmpAll(v, ft_v) && cmpAll(v1, ft_v1) && cmpAll(v2, ft_v2) && cmpAll(v3, ft_v3)) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests) printAll<int>(v, ft_v);
  std::cout << std::endl;
  if (!test || printAllTests) printAll<int>(v1, ft_v1);
  std::cout << std::endl;
  if (!test || printAllTests) printAll<int>(v2, ft_v2);
  std::cout << std::endl;
  if (!test || printAllTests) printAll<int>(v3, ft_v3);
  
  return test;
}

bool  vectorModifiersTest2(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.assign(size_t, val)             : " << RESET;
  
  std::vector<int> v;
  ft::vector<int> ft_v;
  std::vector<int> v1(5, 1);
  ft::vector<int> ft_v1(5, 1);
  std::vector<int> v2(15, 2);
  ft::vector<int> ft_v2(15, 2);
  std::vector<int> v3(20, 3);
  ft::vector<int> ft_v3(20, 3);
  v.assign(v.size(), *v.begin());
  ft_v.assign(ft_v.size(), *ft_v.begin());
  v1.assign(v.size(), *v.begin());
  ft_v1.assign(ft_v.size(), *ft_v.begin());
  v2.assign(v3.size(), *v3.begin());
  ft_v2.assign(ft_v3.size(), *ft_v3.begin());
  v3.assign(v.size(), *v.begin());
  ft_v3.assign(ft_v.size(), *ft_v.begin());
  v3.assign(v2.size(), *v2.begin());
  ft_v3.assign(ft_v2.size(), *ft_v2.begin());
  
  if (cmpAll(v, ft_v) && cmpAll(v1, ft_v1) && cmpAll(v2, ft_v2) && cmpAll(v3, ft_v3)) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests) printAll<int>(v, ft_v);
  std::cout << std::endl;
  if (!test || printAllTests) printAll<int>(v1, ft_v1);
  std::cout << std::endl;
  if (!test || printAllTests) printAll<int>(v2, ft_v2);
  std::cout << std::endl;
  if (!test || printAllTests) printAll<int>(v3, ft_v3);
  
  return test;
}

// bool  vectorModifiersTest2(bool printAllTests, size_t testnum) {
  
// }

// bool  vectorModifiersTest3(bool printAllTests, size_t testnum) {
  
// }

// bool  vectorModifiersTest4(bool printAllTests, size_t testnum) {
  
// }

// bool  vectorModifiersTest5(bool printAllTests, size_t testnum) {
  
// }

// bool  vectorModifiersTest6(bool printAllTests, size_t testnum) {
  
// }


