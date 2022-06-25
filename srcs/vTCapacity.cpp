/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vTCapacity.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:23:25 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/25 07:16:09 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include "vectorTests.hpp"


void printVecMaxSize(size_t max_size, size_t ft_max_size) {
  std::cout << PURPLE << "max_size      : " << YELLOW << max_size << RESET << std::endl;
  std::cout << PURPLE << "ft_max_size   : " << YELLOW << ft_max_size << RESET << std::endl;
}

void printVecEmpty(bool empty, bool ft_empty) {
  if (empty)
    std::cout << PURPLE << "empty         : " << YELLOW << "True" << RESET << std::endl;
  else
    std::cout << PURPLE << "empty         : " << YELLOW << "False" << RESET << std::endl;
  if (ft_empty)
    std::cout << PURPLE << "empty         : " << YELLOW << "True" << RESET << std::endl;
  else
    std::cout << PURPLE << "empty         : " << YELLOW << "False" << RESET << std::endl;
}

bool  vectorCapacityTest1(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.size()                                 : " << RESET;
  
  std::vector<int> v;
  ft::vector<int> ft_v;
  std::vector<int> v1(5);
  ft::vector<int> ft_v1(5);
  std::vector<int> v2(5);
  v2 = std::vector<int>();
  ft::vector<int> ft_v2(5);
  ft_v2 = ft::vector<int>();
  
  
  if (ft_v.size() == v.size() && ft_v1.size() == v1.size() && ft_v2.size() == v2.size()) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests) { printAll<int>(v, ft_v); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v1, ft_v1); std::cout << std::endl; }
  if (!test || printAllTests) printAll<int>(v2, ft_v2);
  
  return test;
}

bool  vectorCapacityTest2(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int|char*|std::string>.max_size()           : " << RESET;
  
  std::vector<int> v(5, 100);
  ft::vector<int> ft_v(5, 100);
  char c[] = "|char *|";
  std::vector<char *> v1(5, c);
  ft::vector<char *> ft_v1(5, c);
  std::vector<std::string> v2(5, "|std::string|");
  ft::vector<std::string> ft_v2(5, "|std::string|");
  
  if (ft_v.max_size() == v.max_size() && ft_v1.max_size() == v1.max_size() && ft_v2.max_size() == v2.max_size()) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests){ printAll<int>(v, ft_v); printVecMaxSize(v.max_size(), ft_v.max_size()); std::cout << std::endl;}
  if (!test || printAllTests){ printAll<char *>(v1, ft_v1); printVecMaxSize(v1.max_size(), ft_v1.max_size()); std::cout << std::endl;}
  if (!test || printAllTests){ printAll<std::string>(v2, ft_v2); printVecMaxSize(v2.max_size(), ft_v2.max_size()); }
  
  return test;
}

bool  vectorCapacityTest3(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int|char*|std::string>.capacity()           : " << RESET;
  
  std::vector<int> v(5, 100);
  ft::vector<int> ft_v(5, 100);
  char c[] = "|char *|";
  std::vector<char *> v1(5, c);
  ft::vector<char *> ft_v1(5, c);
  std::vector<std::string> v2(5, "|std::string|");
  ft::vector<std::string> ft_v2(5, "|std::string|");
  
  if (ft_v.capacity() == v.capacity() && ft_v1.capacity() == v1.capacity() && ft_v2.capacity() == v2.capacity()) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests) { printAll<int>(v, ft_v); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<char *>(v1, ft_v1); std::cout << std::endl; }
  if (!test || printAllTests) printAll<std::string>(v2, ft_v2);
  
  return test;
}

bool  vectorCapacityTest4(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.empty()                                : " << RESET;
  
  std::vector<int> v;
  ft::vector<int> ft_v;
  std::vector<int> v1(5);
  ft::vector<int> ft_v1(5);
  std::vector<int> v2(5, 100);
  ft::vector<int> ft_v2(5, 100);
  v2 = std::vector<int>();
  ft_v2 = ft::vector<int>();
  
  if (ft_v.empty() == v.empty() && ft_v1.empty() == v1.empty() && ft_v2.empty() == v2.empty()) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests){ printAll<int>(v, ft_v); printVecEmpty(v.empty(), ft_v.empty()); std::cout << std::endl;}
  if (!test || printAllTests){ printAll<int>(v1, ft_v1); printVecEmpty(v1.empty(), ft_v1.empty()); std::cout << std::endl;}
  if (!test || printAllTests){ printAll<int>(v2, ft_v2); printVecEmpty(v2.empty(), ft_v2.empty()); }
  
  return test;
}

bool  vectorCapacityTest5(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.resize()                               : " << RESET;
  
  std::vector<int> v;
  ft::vector<int> ft_v;
  std::vector<int> v1(5);
  ft::vector<int> ft_v1(5);
  std::vector<int> v2(15, 1);
  ft::vector<int> ft_v2(15, 1);
  std::vector<int> v3(5);
  ft::vector<int> ft_v3(5);
  v.resize(10, 10);
  ft_v.resize(10, 10);
  v1.resize(0, 20);
  ft_v1.resize(0, 20);
  v2.resize(5, 10);
  ft_v2.resize(5, 10);
  v2.resize(10, 20);
  ft_v2.resize(10, 20);
  v3.resize(10, 40);
  ft_v3.resize(10, 40);
  v3.resize(7, 40);
  ft_v3.resize(7, 40);
  
  if (cmpAll(v, ft_v) && cmpAll(v1, ft_v1) && cmpAll(v2, ft_v2)) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests) { printAll<int>(v, ft_v); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v1, ft_v1); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v2, ft_v2); std::cout << std::endl; }
  if (!test || printAllTests) printAll<int>(v3, ft_v3);
  
  return test;
}

bool  vectorCapacityTest6(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.reserve()                              : " << RESET;
  
  std::vector<int> v;
  ft::vector<int> ft_v;
  std::vector<int> v1(5);
  ft::vector<int> ft_v1(5);
  std::vector<int> v2(15, 1);
  ft::vector<int> ft_v2(15, 1);
  std::vector<int> v3(5);
  ft::vector<int> ft_v3(5);
  v.reserve(10);
  ft_v.reserve(10);
  v1.reserve(10);
  ft_v1.reserve(10);
  v2.reserve(5);
  ft_v2.reserve(5);
  v3.reserve(0);
  ft_v3.reserve(0);
  
  if (cmpAll(v, ft_v) && cmpAll(v1, ft_v1) && cmpAll(v2, ft_v2) && cmpAll(v3, ft_v3)) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests) { printAll<int>(v, ft_v); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v1, ft_v1); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v2, ft_v2); std::cout << std::endl; }
  if (!test || printAllTests) printAll<int>(v3, ft_v3);
  
  return test;
}


