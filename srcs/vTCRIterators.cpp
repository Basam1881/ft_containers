/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vTCRIterators.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:03:30 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/22 02:30:39 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include "vectorTests.hpp"

bool  vectorConstReverseIteratorsTest1(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.rbegin()                               : " << RESET;
  ft::vector<int>::const_reverse_iterator ft_it(ft_v.rbegin());
  std::vector<int>::const_reverse_iterator it(v.rbegin());
  if (*it == *ft_it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstReverseIteratorsTest2(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.rend()                                 : " << RESET;
  ft::vector<int>::const_reverse_iterator ft_it(ft_v.rend() - 1);
  std::vector<int>::const_reverse_iterator it(v.rend() - 1);
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstReverseIteratorsTest3(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : const_reverse_iterator(const_reverse_iterator)     : " << RESET;
  ft::vector<int>::const_reverse_iterator ft_it(ft_v.rbegin() + testnum);
  std::vector<int>::const_reverse_iterator it(v.rbegin() + testnum);
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstReverseIteratorsTest4(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::const_reverse_iterator.operator=()    : " << RESET;
  ft::vector<int>::const_reverse_iterator ft_it;
  ft_it = ft_v.rbegin() + testnum;
  std::vector<int>::const_reverse_iterator it;
  it = v.rbegin() + testnum;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstReverseIteratorsTest5(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::const_reverse_iterator.operator+()    : " << RESET;
  ft::vector<int>::const_reverse_iterator ft_it;
  ft_it = ft_v.rbegin() + testnum;
  std::vector<int>::const_reverse_iterator it;
  it = v.rbegin() + testnum;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstReverseIteratorsTest6(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::const_reverse_iterator.operator-()    : " << RESET;
  ft::vector<int>::const_reverse_iterator ft_it;
  ft_it = ft_v.rend() - (ft_v.size() - testnum);
  std::vector<int>::const_reverse_iterator it;
  it = v.rend() - (v.size() - testnum);
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstReverseIteratorsTest7(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::const_reverse_iterator.operator+=()   : " << RESET;
  ft::vector<int>::const_reverse_iterator ft_it = ft_v.rbegin();
  ft_it += testnum;
  std::vector<int>::const_reverse_iterator it = v.rbegin();
  it += testnum;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstReverseIteratorsTest8(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::const_reverse_iterator.operator-=()   : " << RESET;
  ft::vector<int>::const_reverse_iterator ft_it = ft_v.rend();
  ft_it -= (ft_v.size() - testnum);
  std::vector<int>::const_reverse_iterator it = v.rend();
  it -= (v.size() - testnum);
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstReverseIteratorsTest9(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::const_reverse_iterator.operator++()   : " << RESET;
  ft::vector<int>::const_reverse_iterator ft_it = ft_v.rbegin();
  ++ft_it;
  std::vector<int>::const_reverse_iterator it = v.rbegin();
  ++it;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstReverseIteratorsTest10(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::const_rev_iterator.operator++(int)   : " << RESET;
  ft::vector<int>::const_reverse_iterator ft_it = ft_v.rbegin();
  ft_it++;
  std::vector<int>::const_reverse_iterator it = v.rbegin();
  it++;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstReverseIteratorsTest11(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::const_rev_iterator.operator--()      : " << RESET;
  ft::vector<int>::const_reverse_iterator ft_it = ft_v.rend();
  --ft_it;
  std::vector<int>::const_reverse_iterator it = v.rend();
  --it;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstReverseIteratorsTest12(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::const_rev_iterator.operator--(int)   : " << RESET;
  ft::vector<int>::const_reverse_iterator ft_it = ft_v.rend();
  ft_it--;
  std::vector<int>::const_reverse_iterator it = v.rend();
  it--;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstReverseIteratorsTest13(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>::const_rev_iterator.operator[]()      : " << RESET;
  ft::vector<int>::const_reverse_iterator ft_it = ft_v.rbegin();
  std::vector<int>::const_reverse_iterator it = v.rbegin();
  if (ft_it[testnum] == it[testnum]) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(ft_it[testnum], it[testnum]);
  return test;
}

bool  vectorConstReverseIteratorsTest14(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : const_rev_iterator= ptrdiff_t + const_rev_iterator: " << RESET;
  ft::vector<int>::const_reverse_iterator ft_it = ft_v.rbegin();
  ft_it = testnum + ft_it;
  std::vector<int>::const_reverse_iterator it = v.rbegin();
  it = testnum + it;
  if (*ft_it == *it) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(*ft_it, *it);
  return test;
}

bool  vectorConstReverseIteratorsTest15(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : ptrdiff_t= const_rev_iterator - const_rev_iterator: " << RESET;
  size_t mt;
  ft::vector<int>::const_reverse_iterator ft_it1 = ft_v.rbegin();
  ft::vector<int>::const_reverse_iterator ft_it2 = ft_v.rend();
  mt = ft_it2 - ft_it1;
  size_t t;
  std::vector<int>::const_reverse_iterator it1 = v.rbegin();
  std::vector<int>::const_reverse_iterator it2 = v.rend();
  t = it2 - it1;
  if (mt == t) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
  else std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) printVecIters<int>(mt, t);
  return test;
}
