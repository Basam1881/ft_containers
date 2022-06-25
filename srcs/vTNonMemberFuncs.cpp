/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vTNonMemberFuncs.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 09:26:27 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/25 10:10:05 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include "vectorTests.hpp"

bool  vectorNonMemberFunctionsTest1(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : ft::swap(vector, vector)                           : " << RESET;
  
  std::vector<int> v;
  ft::vector<int> ft_v;
  std::vector<int> v1(4, 1);
  ft::vector<int> ft_v1(4, 1);
  std::vector<int> v2(9, 2);
  ft::vector<int> ft_v2(9, 2);
  std::vector<int> v3(15, 3);
  ft::vector<int> ft_v3(15, 3);

  std::swap(v, v1);
  ft::swap(ft_v, ft_v1);
  std::swap(v1, v3);
  ft::swap(ft_v1, ft_v3);
  std::swap(v2, v3);
  ft::swap(ft_v2, ft_v3);

  if (cmpAll(v, ft_v) && cmpAll(v1, ft_v1) && cmpAll(v2, ft_v2) && cmpAll(v3, ft_v3)) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;

  if (!test || printAllTests) { printAll<int>(v, ft_v); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v1, ft_v1); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v2, ft_v2); std::cout << std::endl; }
  if (!test || printAllTests) printAll<int>(v3, ft_v3);

  return test;
}

bool  vectorNonMemberFunctionsTest2(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : ft::operator==(vector, vector)                     : " << RESET;
  
  std::vector<int> v(4, 1);
  ft::vector<int> ft_v(4, 1);
  std::vector<int> v1(4, 1);
  ft::vector<int> ft_v1(4, 1);
  std::vector<int> v2(4, 1);
  ft::vector<int> ft_v2(4, 1);
  v2.push_back(2);
  ft_v2.push_back(2);

  if (v == v && v == v1 && !(v == v2) && !(v2 == v1) && ft_v == ft_v && ft_v == ft_v1 && !(ft_v == ft_v2) && !(ft_v2 == ft_v1)) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;

  if (!test || printAllTests) { printAll<int>(v, ft_v); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v1, ft_v1); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v2, ft_v2); }

  return test;
}

bool  vectorNonMemberFunctionsTest3(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : ft::operator!=(vector, vector)                     : " << RESET;
  
  std::vector<int> v(4, 1);
  ft::vector<int> ft_v(4, 1);
  std::vector<int> v1(4, 1);
  ft::vector<int> ft_v1(4, 1);
  std::vector<int> v2(4, 1);
  ft::vector<int> ft_v2(4, 1);
  v2.push_back(2);
  ft_v2.push_back(2);

  if (!(v != v) && !(v != v1) && v != v2 && v2 != v1 && !(ft_v != ft_v) && !(ft_v != ft_v1) && ft_v != ft_v2 && ft_v2 != ft_v1) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;

  if (!test || printAllTests) { printAll<int>(v, ft_v); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v1, ft_v1); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v2, ft_v2); }

  return test;
}

bool  vectorNonMemberFunctionsTest4(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : ft::operator<(vector, vector)                      : " << RESET;
  
  std::vector<int> v(2, 1);
  ft::vector<int> ft_v(2, 1);
  std::vector<int> v1(4, 1);
  ft::vector<int> ft_v1(4, 1);
  std::vector<int> v2(4, 2);
  ft::vector<int> ft_v2(4, 2);


  if (!(v < v) && v < v1 && v < v2 && v1 < v2 && !(ft_v < ft_v) && ft_v < ft_v1 && ft_v < ft_v2 && ft_v1 < ft_v2) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;

  if (!test || printAllTests) { printAll<int>(v, ft_v); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v1, ft_v1); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v2, ft_v2); }

  return test;
}

bool  vectorNonMemberFunctionsTest5(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : ft::operator<=(vector, vector)                     : " << RESET;
  
  std::vector<int> v(2, 1);
  ft::vector<int> ft_v(2, 1);
  std::vector<int> v1(4, 1);
  ft::vector<int> ft_v1(4, 1);
  std::vector<int> v2(4, 2);
  ft::vector<int> ft_v2(4, 2);


  if (v <= v && v <= v1 && v <= v2 && v1 <= v2 && ft_v <= ft_v && ft_v <= ft_v1 && ft_v <= ft_v2 && ft_v1 <= ft_v2) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;

  if (!test || printAllTests) { printAll<int>(v, ft_v); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v1, ft_v1); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v2, ft_v2); }

  return test;
}

bool  vectorNonMemberFunctionsTest6(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : ft::operator>(vector, vector)                      : " << RESET;
  
  std::vector<int> v(2, 1);
  ft::vector<int> ft_v(2, 1);
  std::vector<int> v1(4, 1);
  ft::vector<int> ft_v1(4, 1);
  std::vector<int> v2(4, 2);
  ft::vector<int> ft_v2(4, 2);


  if (!(v2 > v2) && v2 > v1 && v2 > v && v1 > v && !(ft_v2 > ft_v2) && ft_v2 > ft_v1 && ft_v2 > ft_v && ft_v1 > ft_v) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;

  if (!test || printAllTests) { printAll<int>(v, ft_v); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v1, ft_v1); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v2, ft_v2); }

  return test;
}

bool  vectorNonMemberFunctionsTest7(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : ft::operator>=(vector, vector)                     : " << RESET;
  
  std::vector<int> v(2, 1);
  ft::vector<int> ft_v(2, 1);
  std::vector<int> v1(4, 1);
  ft::vector<int> ft_v1(4, 1);
  std::vector<int> v2(4, 2);
  ft::vector<int> ft_v2(4, 2);


  if (v2 >= v2 && v2 >= v1 && v2 >= v && v1 >= v && ft_v2 >= ft_v2 && ft_v2 >= ft_v1 && ft_v2 >= ft_v && ft_v1 >= ft_v) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;

  if (!test || printAllTests) { printAll<int>(v, ft_v); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v1, ft_v1); std::cout << std::endl; }
  if (!test || printAllTests) { printAll<int>(v2, ft_v2); }

  return test;
}