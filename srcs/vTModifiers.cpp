/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vTModifiers.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 07:51:19 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/23 18:49:16 by bnaji            ###   ########.fr       */
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

bool  vectorModifiersTest3(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.push_back()                     : " << RESET;
  
  std::vector<int> v;
  ft::vector<int> ft_v;
  std::vector<int> v1(5, 1);
  ft::vector<int> ft_v1(5, 1);
  for (int i = 0; i < 6; i++) {
    v.push_back(2);
    ft_v.push_back(2);
    v1.push_back(1);
    ft_v1.push_back(1);
  }
  
  if (cmpAll(v, ft_v) && cmpAll(v1, ft_v1)) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests) printAll<int>(v, ft_v);
  std::cout << std::endl;
  if (!test || printAllTests) printAll<int>(v1, ft_v1);
  
  return test;
}

bool  vectorModifiersTest4(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.pop_back()                      : " << RESET;
  
  std::vector<int> v(1);
  ft::vector<int> ft_v(1);
  std::vector<int> v1(4, 1);
  ft::vector<int> ft_v1(4, 1);
  v.pop_back();
  ft_v.pop_back();
  for (int i = 0; i < 3; i++) {
    v1.pop_back();
    ft_v1.pop_back();
  }
  
  if (cmpAll(v, ft_v) && cmpAll(v1, ft_v1)) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests) printAll<int>(v, ft_v);
  std::cout << std::endl;
  if (!test || printAllTests) printAll<int>(v1, ft_v1);
  
  return test;
}

bool  vectorModifiersTest5(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.insert(iterator, val)            : " << RESET;
  
  std::vector<int> v(0);
  ft::vector<int> ft_v(0);
  std::vector<int> v1(4, 1);
  ft::vector<int> ft_v1(4, 1);
  v.insert(v.begin(), 1);
  ft_v.insert(ft_v.begin(), 1);
  v.insert(v.begin(), 2);
  ft_v.insert(ft_v.begin(), 2);
  // v.insert(v.end() - 1, 3);
  // ft_v.insert(ft_v.end() - 1, 3);
  // v.insert(v.end(), 4);
  // ft_v.insert(ft_v.end(), 4);
  // v1.reserve(v1.size() * 2);
  // ft_v1.reserve(v1.size() * 2);
  // v1.insert(v1.begin() + 6, 2);
  // ft_v1.insert(ft_v1.begin() + 6, 2);
  // v1.insert(v1.begin() + 1, 3);
  // ft_v1.insert(ft_v1.begin() + 1, 3);
  // v1.insert(v1.begin() + v1.capacity(), 4);
  // ft_v1.insert(ft_v1.begin() + ft_v1.capacity(), 4);
  
  if (cmpAll(v, ft_v) && cmpAll(v1, ft_v1)) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;

  if (!test || printAllTests) printAll<int>(v, ft_v);
  std::cout << std::endl;
  if (!test || printAllTests) printAll<int>(v1, ft_v1);

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


