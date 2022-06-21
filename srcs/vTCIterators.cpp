/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vTCIterators.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:03:17 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/21 19:37:07 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include "vectorTests.hpp"

bool  vectorConstIteratorsTest1(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.begin()                                : " << RESET;
  ft::vector<int>::const_iterator ft_it(ft_v.begin());
  std::vector<int>::const_iterator it(v.begin());
  if (*it == *ft_it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstIteratorsTest2(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.end()                                  : " << RESET;
  ft::vector<int>::const_iterator ft_it(ft_v.end() - 1);
  std::vector<int>::const_iterator it(v.end() - 1);
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstIteratorsTest3(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::const_iterator(iterator)              : " << RESET;
  ft::vector<int>::const_iterator ft_it(ft_v.begin() + testnum);
  std::vector<int>::const_iterator it(v.begin() + testnum);
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstIteratorsTest4(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::const_iterator.operator=()            : " << RESET;
  ft::vector<int>::const_iterator ft_it;
  ft_it = ft_v.begin() + testnum;
  std::vector<int>::const_iterator it;
  it = v.begin() + testnum;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstIteratorsTest5(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::const_iterator.operator+()            : " << RESET;
  ft::vector<int>::const_iterator ft_it;
  ft_it = ft_v.begin() + testnum;
  std::vector<int>::const_iterator it;
  it = v.begin() + testnum;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstIteratorsTest6(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::const_iterator.operator-()            : " << RESET;
  ft::vector<int>::const_iterator ft_it;
  ft_it = ft_v.end() - (ft_v.size() - testnum);
  std::vector<int>::const_iterator it;
  it = v.end() - (v.size() - testnum);
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstIteratorsTest7(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::const_iterator.operator+=()           : " << RESET;
  ft::vector<int>::const_iterator ft_it = ft_v.begin();
  ft_it += testnum;
  std::vector<int>::const_iterator it = v.begin();
  it += testnum;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstIteratorsTest8(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::const_iterator.operator-=()           : " << RESET;
  ft::vector<int>::const_iterator ft_it = ft_v.end();
  ft_it -= (ft_v.size() - testnum);
  std::vector<int>::const_iterator it = v.end();
  it -= (v.size() - testnum);
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstIteratorsTest9(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::const_iterator.operator++()           : " << RESET;
  ft::vector<int>::const_iterator ft_it = ft_v.begin();
  ++ft_it;
  std::vector<int>::const_iterator it = v.begin();
  ++it;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstIteratorsTest10(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::const_iterator.operator++(int)       : " << RESET;
  ft::vector<int>::const_iterator ft_it = ft_v.begin();
  ft_it++;
  std::vector<int>::const_iterator it = v.begin();
  it++;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstIteratorsTest11(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::const_iterator.operator--()          : " << RESET;
  ft::vector<int>::const_iterator ft_it = ft_v.end();
  --ft_it;
  std::vector<int>::const_iterator it = v.end();
  --it;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstIteratorsTest12(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::const_iterator.operator--(int)       : " << RESET;
  ft::vector<int>::const_iterator ft_it = ft_v.end();
  ft_it--;
  std::vector<int>::const_iterator it = v.end();
  it--;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstIteratorsTest13(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::const_iterator.operator[]()          : " << RESET;
  ft::vector<int>::const_iterator ft_it = ft_v.begin();
  std::vector<int>::const_iterator it = v.begin();
  if (ft_it[testnum] == it[testnum]) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(ft_it[testnum], it[testnum]);
  return test;
}

bool  vectorConstIteratorsTest14(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : const_iterator = ptrdiff_t + const_iterator       : " << RESET;
  ft::vector<int>::const_iterator ft_it = ft_v.begin();
  ft_it = testnum + ft_it;
  std::vector<int>::const_iterator it = v.begin();
  it = testnum + it;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstIteratorsTest15(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : ptrdiff_t = const_iterator - const_iterator       : " << RESET;
  size_t mt;
  ft::vector<int>::const_iterator ft_it1 = ft_v.begin();
  ft::vector<int>::const_iterator ft_it2 = ft_v.end();
  mt = ft_it2 - ft_it1;
  size_t t;
  std::vector<int>::const_iterator it1 = v.begin();
  std::vector<int>::const_iterator it2 = v.end();
  t = it2 - it1;
  if (mt == t) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(mt, t);
  return test;
}
