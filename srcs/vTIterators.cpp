/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vTIterators.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:35:18 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/21 19:33:42 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include "vectorTests.hpp"

bool  vectorIteratorsTest1(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.begin()                                : " << RESET;
  if (*ft_v.begin() == *v.begin()) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_v.begin(), *v.begin());
  return test;
}

bool  vectorIteratorsTest2(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.end()                                  : " << RESET;
  if (*--ft_v.end() == *--v.end()) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*--ft_v.end(), *--v.end());
  return test;
}

bool  vectorIteratorsTest3(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::iterator(iterator)                    : " << RESET;
  ft::vector<int>::iterator ft_it(ft_v.begin() + testnum);
  std::vector<int>::iterator it(v.begin() + testnum);
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorIteratorsTest4(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::iterator.operator=()                  : " << RESET;
  ft::vector<int>::iterator ft_it;
  ft_it = ft_v.begin() + testnum;
  std::vector<int>::iterator it;
  it = v.begin() + testnum;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorIteratorsTest5(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::iterator.operator+()                  : " << RESET;
  ft::vector<int>::iterator ft_it;
  ft_it = ft_v.begin() + testnum;
  std::vector<int>::iterator it;
  it = v.begin() + testnum;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorIteratorsTest6(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::iterator.operator-()                  : " << RESET;
  ft::vector<int>::iterator ft_it;
  ft_it = ft_v.end() - (ft_v.size() - testnum);
  std::vector<int>::iterator it;
  it = v.end() - (v.size() - testnum);
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorIteratorsTest7(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::iterator.operator+=()                 : " << RESET;
  ft::vector<int>::iterator ft_it = ft_v.begin();
  ft_it += testnum;
  std::vector<int>::iterator it = v.begin();
  it += testnum;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorIteratorsTest8(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::iterator.operator-=()                 : " << RESET;
  ft::vector<int>::iterator ft_it = ft_v.end();
  ft_it -= (ft_v.size() - testnum);
  std::vector<int>::iterator it = v.end();
  it -= (v.size() - testnum);
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorIteratorsTest9(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::iterator.operator++()                 : " << RESET;
  ft::vector<int>::iterator ft_it = ft_v.begin();
  ++ft_it;
  std::vector<int>::iterator it = v.begin();
  ++it;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorIteratorsTest10(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::iterator.operator++(int)             : " << RESET;
  ft::vector<int>::iterator ft_it = ft_v.begin();
  ft_it++;
  std::vector<int>::iterator it = v.begin();
  it++;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorIteratorsTest11(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::iterator.operator--()                : " << RESET;
  ft::vector<int>::iterator ft_it = ft_v.end();
  --ft_it;
  std::vector<int>::iterator it = v.end();
  --it;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorIteratorsTest12(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::iterator.operator--(int)             : " << RESET;
  ft::vector<int>::iterator ft_it = ft_v.end();
  ft_it--;
  std::vector<int>::iterator it = v.end();
  it--;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorIteratorsTest13(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::iterator.operator[]()                : " << RESET;
  ft::vector<int>::iterator ft_it = ft_v.begin();
  std::vector<int>::iterator it = v.begin();
  if (ft_it[testnum] == it[testnum]) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(ft_it[testnum], it[testnum]);
  return test;
}

bool  vectorIteratorsTest14(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : iterator = ptrdiff_t + iterator                   : " << RESET;
  ft::vector<int>::iterator ft_it = ft_v.begin();
  ft_it = testnum + ft_it;
  std::vector<int>::iterator it = v.begin();
  it = testnum + it;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorIteratorsTest15(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : ptrdiff_t = iterator - iterator                   : " << RESET;
  size_t mt;
  mt = ft_v.end() - ft_v.begin();
  size_t t;
  t = v.end() - v.begin();
  if (mt == t) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(mt, t);
  return test;
}
