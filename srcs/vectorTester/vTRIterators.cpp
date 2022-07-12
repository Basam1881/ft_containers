/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vTRIterators.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:41:43 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/02 07:35:25 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "vectorTests.hpp"

bool  vectorReverseIteratorsTest1(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.rbegin()                               : " << RESET;
  if (*ft_v.rbegin() == *v.rbegin()) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_v.rbegin(), *v.rbegin());
  return test;
}

bool  vectorReverseIteratorsTest2(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.rend()                                 : " << RESET;
  if (*--ft_v.rend() == *--v.rend()) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*--ft_v.rend(), *--v.rend());
  return test;
}

bool  vectorReverseIteratorsTest3(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::reverse_iterator(iterator)            : " << RESET;
  ft::vector<int>::reverse_iterator ft_it(ft_v.rbegin() + testnum);
  std::vector<int>::reverse_iterator it(v.rbegin() + testnum);
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorReverseIteratorsTest4(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::reverse_iterator.operator=()          : " << RESET;
  ft::vector<int>::reverse_iterator ft_it;
  ft_it = ft_v.rbegin() + testnum;
  std::vector<int>::reverse_iterator it;
  it = v.rbegin() + testnum;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorReverseIteratorsTest5(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::reverse_iterator.operator+()          : " << RESET;
  ft::vector<int>::reverse_iterator ft_it;
  ft_it = ft_v.rbegin() + testnum;
  std::vector<int>::reverse_iterator it;
  it = v.rbegin() + testnum;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorReverseIteratorsTest6(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::reverse_iterator.operator-()          : " << RESET;
  ft::vector<int>::reverse_iterator ft_it;
  ft_it = ft_v.rend() - (ft_v.size() - testnum);
  std::vector<int>::reverse_iterator it;
  it = v.rend() - (v.size() - testnum);
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorReverseIteratorsTest7(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::reverse_iterator.operator+=()         : " << RESET;
  ft::vector<int>::reverse_iterator ft_it = ft_v.rbegin();
  ft_it += testnum;
  std::vector<int>::reverse_iterator it = v.rbegin();
  it += testnum;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorReverseIteratorsTest8(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::reverse_iterator.operator-=()         : " << RESET;
  ft::vector<int>::reverse_iterator ft_it = ft_v.rend();
  ft_it -= (ft_v.size() - testnum);
  std::vector<int>::reverse_iterator it = v.rend();
  it -= (v.size() - testnum);
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorReverseIteratorsTest9(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::reverse_iterator.operator++()         : " << RESET;
  ft::vector<int>::reverse_iterator ft_it = ft_v.rbegin();
  ++ft_it;
  std::vector<int>::reverse_iterator it = v.rbegin();
  ++it;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorReverseIteratorsTest10(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::reverse_iterator.operator++(int)     : " << RESET;
  ft::vector<int>::reverse_iterator ft_it = ft_v.rbegin();
  ft_it++;
  std::vector<int>::reverse_iterator it = v.rbegin();
  it++;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorReverseIteratorsTest11(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::reverse_iterator.operator--()        : " << RESET;
  ft::vector<int>::reverse_iterator ft_it = ft_v.rend();
  --ft_it;
  std::vector<int>::reverse_iterator it = v.rend();
  --it;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorReverseIteratorsTest12(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::reverse_iterator.operator--(int)     : " << RESET;
  ft::vector<int>::reverse_iterator ft_it = ft_v.rend();
  ft_it--;
  std::vector<int>::reverse_iterator it = v.rend();
  it--;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorReverseIteratorsTest13(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::reverse_iterator.operator[]()        : " << RESET;
  ft::vector<int>::reverse_iterator ft_it = ft_v.rbegin();
  std::vector<int>::reverse_iterator it = v.rbegin();
  if (ft_it[testnum] == it[testnum]) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(ft_it[testnum], it[testnum]);
  return test;
}

bool  vectorReverseIteratorsTest14(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : reverse_iterator = ptrdiff_t + reverse_iterator   : " << RESET;
  ft::vector<int>::reverse_iterator ft_it = ft_v.rbegin();
  ft_it = testnum + ft_it;
  std::vector<int>::reverse_iterator it = v.rbegin();
  it = testnum + it;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorReverseIteratorsTest15(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : ptrdiff_t = reverse_iterator - reverse_iterator   : " << RESET;
  size_t mt;
  mt = ft_v.rend() - ft_v.rbegin();
  size_t t;
  t = v.rend() - v.rbegin();
  if (mt == t) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(mt, t);
  return test;
}
