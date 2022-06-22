/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vTElementAccess.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 07:54:36 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/22 14:38:05 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include "vectorTests.hpp"

bool vectorElementAccessTest1(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.operator[]                             : " << RESET;
  
  size_t i = 0;
  for  ( ; ft_v[i] == v[i] && i < v.size() - 1; i++);
  
  if (i == v.size() - 1) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests) printAll<int>(v, ft_v);
  
  return test;
}

bool vectorElementAccessTest2(std::vector<int> const & v, ft::vector<int> const & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.const_operator[]                       : " << RESET;
  
  size_t i = 0;
  for  ( ; ft_v[i] == v[i] && i < v.size() - 1; i++);
  
  if (i == v.size() - 1) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests) printAll<int>(v, ft_v);
  
  return test;
}

bool vectorElementAccessTest3(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.at()                                   : " << RESET;
  
  size_t i = 0;
  for  ( ; ft_v.at(i) == v.at(i) && i < v.size() - 1; i++);
  
  if (i == v.size() - 1) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests) printAll<int>(v, ft_v);
  
  return test;
}

bool vectorElementAccessTest4(std::vector<int> const & v, ft::vector<int> const & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.const_at()                             : " << RESET;

  size_t i = 0;
  for  ( ; ft_v.at(i) == v.at(i) && i < v.size() - 1; i++);
  
  if (i == v.size() - 1) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests) printAll<int>(v, ft_v);
  
  return test;
}

bool vectorElementAccessTest5(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.back()                                 : " << RESET;

  
  if (ft_v.front() == v.front()) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests) printAll<int>(v, ft_v);
  
  return test;
}

bool vectorElementAccessTest6(std::vector<int> const & v, ft::vector<int> const & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.const_front()                          : " << RESET;
  
  if (ft_v.front() == v.front()) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests) printAll<int>(v, ft_v);
  
  return test;
}

bool vectorElementAccessTest7(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.back()                                 : " << RESET;

  
  if (ft_v.back() == v.back()) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests) printAll<int>(v, ft_v);
  
  return test;
}

bool vectorElementAccessTest8(std::vector<int> const & v, ft::vector<int> const & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.const_back()                           : " << RESET;
  
  if (ft_v.back() == v.back()) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests) printAll<int>(v, ft_v);
  
  return test;
}

bool vectorElementAccessTest9(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.data()                                 : " << RESET;

  size_t i = 0;
  for  ( ; ft_v.at(i) == v.at(i) && i < v.size() - 1; i++);
  
  if (i == v.size() - 1) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests) printAll<int>(v, ft_v);
  
  return test;
}

bool vectorElementAccessTest10(std::vector<int> const & v, ft::vector<int> const & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.const_data()                           : " << RESET;
  
  size_t i = 0;
  for  ( ; ft_v.at(i) == v.at(i) && i < v.size() - 1; i++);
  
  if (i == v.size() - 1) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  
  if (!test || printAllTests) printAll<int>(v, ft_v);
  
  return test;
}
