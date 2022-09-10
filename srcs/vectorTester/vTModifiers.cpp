/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vTModifiers.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 07:51:19 by bnaji             #+#    #+#             */
/*   Updated: 2022/09/10 18:51:22 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "vectorTests.hpp"

void printVecInsertPosition(int pos, int ft_pos) {
  std::cout << PURPLE << "pos_val       : " << YELLOW << pos << RESET << std::endl;
  std::cout << PURPLE << "ft_pos_val    : " << YELLOW << ft_pos << RESET << std::endl;
}

bool  vectorModifiersTest1(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE
    << " : vector<int>.assign(iterator, iterator)             : " << RESET;
  
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
  
  if (cmpAll(v, ft_v) && cmpAll(v1, ft_v1) && cmpAll(v2, ft_v2) && cmpAll(v3, ft_v3)) {
    std::cout << GREEN << "OK" << RESET << std::endl; test = true;
    }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests) { printAll<int>(v, ft_v); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v1, ft_v1); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v2, ft_v2); std::cout << std::endl; }
  if (!test || printAllTests) printAll<int>(v3, ft_v3);
  
  return test;
}

bool  vectorModifiersTest2(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE
    << " : vector<int>.assign(size_t, val)                    : " << RESET;
  
  std::vector<int> v;
  ft::vector<int> ft_v;
  std::vector<int> v1(5, 1);
  ft::vector<int> ft_v1(5, 1);
  std::vector<int> v2(15, 2);
  ft::vector<int> ft_v2(15, 2);
  std::vector<int> v3(20, 3);
  ft::vector<int> ft_v3(20, 3);
  v.assign(v.size(), *v1.begin());
  ft_v.assign(ft_v.size(), *ft_v1.begin());
  v.assign(v1.size(), *v1.begin());
  ft_v.assign(ft_v1.size(), *ft_v1.begin());
  v1.assign(v.size(), *v1.begin());
  ft_v1.assign(ft_v.size(), *ft_v1.begin());
  v2.assign(v3.size(), *v.begin());
  ft_v2.assign(ft_v3.size(), *ft_v.begin());
  v3.assign(v.size(), *v.begin());
  ft_v3.assign(ft_v.size(), *ft_v.begin());
  v3.assign(v2.size(), *v2.begin());
  ft_v3.assign(ft_v2.size(), *ft_v2.begin());
  
  if (cmpAll(v, ft_v) && cmpAll(v1, ft_v1) && cmpAll(v2, ft_v2) && cmpAll(v3, ft_v3)) {
    std::cout << GREEN << "OK" << RESET << std::endl; test = true;
  }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests) { printAll<int>(v, ft_v); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v1, ft_v1); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v2, ft_v2); std::cout << std::endl; }
  if (!test || printAllTests) printAll<int>(v3, ft_v3);
  
  return test;
}

bool  vectorModifiersTest3(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE
    << " : vector<int>.push_back()                            : " << RESET;
  
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
  
  if (cmpAll(v, ft_v) && cmpAll(v1, ft_v1)) {
    std::cout << GREEN << "OK" << RESET << std::endl; test = true;
  }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests) { printAll<int>(v, ft_v); std::cout << std::endl; }
  if (!test || printAllTests) printAll<int>(v1, ft_v1);
  
  return test;
}

bool  vectorModifiersTest4(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE
    << " : vector<int>.pop_back()                             : " << RESET;
  
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
  
  if (cmpAll(v, ft_v) && cmpAll(v1, ft_v1)) {
    std::cout << GREEN << "OK" << RESET << std::endl; test = true;
  }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests) { printAll<int>(v, ft_v); std::cout << std::endl; }
  if (!test || printAllTests) printAll<int>(v1, ft_v1);
  
  return test;
}

bool  vectorModifiersTest5(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE
    << " : vector<int>.insert(iter, val)                      : " << RESET;
  
  std::vector<int> v(0);
  ft::vector<int> ft_v(0);
  std::vector<int> v1(4, 1);
  ft::vector<int> ft_v1(4, 1);
  std::vector<int>::iterator it;
  ft::vector<int>::iterator ft_it;
  std::vector<int>::iterator it1;
  ft::vector<int>::iterator ft_it1;
  v.insert(v.begin(), 1);
  ft_v.insert(ft_v.begin(), 1);
  v.insert(v.begin(), 2);
  ft_v.insert(ft_v.begin(), 2);
  v.insert(v.end() - 1, 3);
  ft_v.insert(ft_v.end() - 1, 3);
  it = v.insert(v.end(), 4);
  ft_it = ft_v.insert(ft_v.end(), 4);
  v1.reserve(v1.size() * 2);
  ft_v1.reserve(v1.size() * 2);
  v1.insert(v1.begin() + 4, 2);
  ft_v1.insert(ft_v1.begin() + 4, 2);
  v1.insert(v1.begin() + v1.size(), 3);
  ft_v1.insert(ft_v1.begin() + ft_v1.size(), 3);
  v1.insert(v1.begin() + v1.size(), 4);
  ft_v1.insert(ft_v1.begin() + ft_v1.size(), 4);
  v1.insert(v1.begin() + v1.size(), 5);
  ft_v1.insert(ft_v1.begin() + ft_v1.size(), 5);
  it1 = v1.insert(v1.begin() + v1.size(), 5);
  ft_it1 = ft_v1.insert(ft_v1.begin() + ft_v1.size(), 5);
  if (cmpAll(v, ft_v) && cmpAll(v1, ft_v1) && *it == *ft_it && *it1 == *ft_it1) {
    std::cout << GREEN << "OK" << RESET << std::endl; test = true;
  }
  else std::cout << RED << "KO" << RESET << std::endl;

  if (!test || printAllTests) { printAll<int>(v, ft_v); printVecInsertPosition(*it, *ft_it); std::cout << std::endl;}
  if (!test || printAllTests) { printAll<int>(v1, ft_v1); printVecInsertPosition(*it1, *ft_it1); }

  return test;
}

bool  vectorModifiersTest6(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE
    << " : vector<int>.insert(iter, size_t, val)              : " << RESET;
  
  std::vector<int> v(0);
  ft::vector<int> ft_v(0);
  std::vector<int> v1(4, 1);
  ft::vector<int> ft_v1(4, 1);
  v.insert(v.begin(), 0, 1);
  ft_v.insert(ft_v.begin(), 0, 1);
  v.insert(v.begin(), 5, 2);
  ft_v.insert(ft_v.begin(), 5, 2);
  v.insert(v.end() - 1, 0, 3);
  ft_v.insert(ft_v.end() - 1, 0, 3);
  v.insert(v.end(), v.size(), 4);
  ft_v.insert(ft_v.end(), ft_v.size(), 4);
  
  v1.reserve(v1.size() * 2);
  ft_v1.reserve(ft_v1.size() * 2);
  v1.insert(v1.begin() + 4, v1.size(), 2);
  ft_v1.insert(ft_v1.begin() + 4, ft_v1.size(), 2);
  v1.insert(v1.begin() + v1.size(), v1.capacity(), 3);
  ft_v1.insert(ft_v1.begin() + ft_v1.size(), ft_v1.capacity(), 3);
  v1.insert(v1.begin() + v1.size(), v1.capacity(), 4);
  ft_v1.insert(ft_v1.begin() + ft_v1.size(), ft_v1.capacity(), 4);
  v1.insert(v1.begin() + v1.size(), 0, 5);
  ft_v1.insert(ft_v1.begin() + ft_v1.size(), 0, 5);
  
  if (cmpAll(v, ft_v) && cmpAll(v1, ft_v1)) {
    std::cout << GREEN << "OK" << RESET << std::endl; test = true;
  }
  else std::cout << RED << "KO" << RESET << std::endl;

  if (!test || printAllTests) { printAll<int>(v, ft_v); std::cout << std::endl; }
  if (!test || printAllTests) printAll<int>(v1, ft_v1);

  return test;
}

bool  vectorModifiersTest7(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE
    << " : vector<int>.insert(iter, iter, iter)               : " << RESET;
  
  std::vector<int> v(0);
  ft::vector<int> ft_v(0);
  std::vector<int> v1(4, 1);
  ft::vector<int> ft_v1(4, 1);
  std::vector<int> v2(4, 2);
  ft::vector<int> ft_v2(4, 2);
  std::vector<int> v3(4, 3);
  ft::vector<int> ft_v3(4, 3);
  std::vector<int> v4(4, 4);
  ft::vector<int> ft_v4(4, 4);
  
  v.insert(v.begin(), v.begin(), v.end());
  ft_v.insert(ft_v.begin(), ft_v.begin(), ft_v.end());
  v.insert(v.begin(), v1.begin(), v1.end() - 1);
  ft_v.insert(ft_v.begin(), ft_v1.begin(), ft_v1.end() - 1);
  v.insert(v.end() - 1, v.begin(), v.begin() + 1);
  ft_v.insert(ft_v.end() - 1, ft_v.begin(), ft_v.begin() + 1);
  v.insert(v.end(), v2.end() - 2, v2.end());
  ft_v.insert(ft_v.end(), ft_v2.end() - 2, ft_v2.end());
  v.insert(v.end(), v3.begin(), v3.begin());
  ft_v.insert(ft_v.end(), ft_v3.begin(), ft_v3.begin());
  v.insert(v.end(), v4.end(), v4.end());
  ft_v.insert(ft_v.end(), ft_v4.end(), ft_v4.end());
  v.insert(v.end() - 3, v4.begin(), v4.end());
  ft_v.insert(ft_v.end() - 3, ft_v4.begin(), ft_v4.end());
  v.reserve(v.size() * 2);
  ft_v.reserve(ft_v.size() * 2);
  v.insert(v.end(), v3.begin(), v3.end());
  ft_v.insert(ft_v.end(), ft_v3.begin(), ft_v3.end());
  

  
  if (cmpAll(v, ft_v)) {
    std::cout << GREEN << "OK" << RESET << std::endl; test = true;
  }
  else std::cout << RED << "KO" << RESET << std::endl;

  if (!test || printAllTests) printAll<int>(v, ft_v);

  return test;
}

bool  vectorModifiersTest8(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE
    << " : vector<int>.erase(iter)                            : " << RESET;
  
  std::vector<int> v(0);
  ft::vector<int> ft_v(0);
  std::vector<int> v1(4, 1);
  ft::vector<int> ft_v1(4, 1);
  std::vector<int> v2(4, 2);
  ft::vector<int> ft_v2(4, 2);
  
  v1.erase(v1.begin() + 1);
  ft_v1.erase(ft_v1.begin() + 1);
  v1.erase(v1.begin() + 1);
  ft_v1.erase(ft_v1.begin() + 1);
  v1.erase(v1.end() - 1);
  ft_v1.erase(ft_v1.end() - 1);
  v2.erase(v2.end() - 2);
  ft_v2.erase(ft_v2.end() - 2);
  v2.erase(v2.end() - 2);
  ft_v2.erase(ft_v2.end() - 2);
  v2.erase(v2.begin());
  ft_v2.erase(ft_v2.begin());
  v2.erase(v2.begin());
  ft_v2.erase(ft_v2.begin());
  

  if (cmpAll(v1, ft_v1) && cmpAll(v2, ft_v2)) {
    std::cout << GREEN << "OK" << RESET << std::endl; test = true;
  }
  else std::cout << RED << "KO" << RESET << std::endl;

  if (!test || printAllTests) { printAll<int>(v1, ft_v1); std::cout << std::endl; }
  if (!test || printAllTests) printAll<int>(v2, ft_v2);

  return test;
}

bool  vectorModifiersTest9(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE
    << " : vector<int>.erase(iter, iter)                      : " << RESET;
  
  std::vector<int> v(4, 1);
  ft::vector<int> ft_v(4, 1);
  std::vector<int> v1(4, 1);
  ft::vector<int> ft_v1(4, 1);
  std::vector<int> v2(9, 2);
  ft::vector<int> ft_v2(9, 2);
  
  v.erase(v.begin(), v.end());
  ft_v.erase(ft_v.begin(), ft_v.end());
  v.erase(v.begin(), v.begin());
  ft_v.erase(ft_v.begin(), ft_v.begin());
  v1.erase(v1.begin(), v1.begin());
  ft_v1.erase(ft_v1.begin(), ft_v1.begin());
  v1.erase(v1.end() - 1, v1.end());
  ft_v1.erase(ft_v1.end() - 1, ft_v1.end());
  v1.erase(v1.begin(), v1.begin() + 1);
  ft_v1.erase(ft_v1.begin(), ft_v1.begin() + 1);
  v2.erase(v2.begin(), v2.begin() + (v2.size() / 3));
  ft_v2.erase(ft_v2.begin(), ft_v2.begin() + (ft_v2.size() / 3));
  v2.erase(v2.end() - (v2.size() / 3), v2.end());
  ft_v2.erase(ft_v2.end() - (ft_v2.size() / 3), ft_v2.end());
  v2.erase(v2.begin() + 1, v2.end() - 1);
  ft_v2.erase(ft_v2.begin() + 1, ft_v2.end() - 1);
  

  if (cmpAll(v, ft_v) && cmpAll(v1, ft_v1) && cmpAll(v2, ft_v2)) {
    std::cout << GREEN << "OK" << RESET << std::endl; test = true;
  }
  else std::cout << RED << "KO" << RESET << std::endl;

  if (!test || printAllTests) { printAll<int>(v, ft_v); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v1, ft_v1); std::cout << std::endl; }
  if (!test || printAllTests) printAll<int>(v2, ft_v2);

  return test;
}

bool  vectorModifiersTest10(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE
    << " : vector<int>.swap(vector)                          : " << RESET;
  
  std::vector<int> v;
  ft::vector<int> ft_v;
  std::vector<int> v1(4, 1);
  ft::vector<int> ft_v1(4, 1);
  std::vector<int> v2(9, 2);
  ft::vector<int> ft_v2(9, 2);
  std::vector<int> v3(15, 3);
  ft::vector<int> ft_v3(15, 3);

  v.swap(v1);
  ft_v.swap(ft_v1);
  v1.swap(v3);
  ft_v1.swap(ft_v3);
  v2.swap(v3);
  ft_v2.swap(ft_v3);
  

  if (cmpAll(v, ft_v) && cmpAll(v1, ft_v1) && cmpAll(v2, ft_v2) && cmpAll(v3, ft_v3)) {
    std::cout << GREEN << "OK" << RESET << std::endl; test = true;
  }
  else std::cout << RED << "KO" << RESET << std::endl;

  if (!test || printAllTests) { printAll<int>(v, ft_v); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v1, ft_v1); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v2, ft_v2); std::cout << std::endl; }
  if (!test || printAllTests) printAll<int>(v3, ft_v3);

  return test;
}

bool  vectorModifiersTest11(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE
    << " : vector<int>.clear()                               : " << RESET;
  
  std::vector<int> v;
  ft::vector<int> ft_v;
  std::vector<int> v1(4, 1);
  ft::vector<int> ft_v1(4, 1);
  std::vector<int> v2(9, 2);
  ft::vector<int> ft_v2(9, 2);
  
  v.clear();
  ft_v.clear();
  v1.clear();
  ft_v1.clear();
  v2.reserve(20);
  ft_v2.reserve(20);
  v2.clear();
  ft_v2.clear();
  

  if (cmpAll(v, ft_v) && cmpAll(v1, ft_v1) && cmpAll(v2, ft_v2)) {
    std::cout << GREEN << "OK" << RESET << std::endl; test = true;
  }
  else std::cout << RED << "KO" << RESET << std::endl;

  if (!test || printAllTests) { printAll<int>(v, ft_v); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v1, ft_v1); std::cout << std::endl; }
  if (!test || printAllTests) printAll<int>(v2, ft_v2);

  return test;
}
