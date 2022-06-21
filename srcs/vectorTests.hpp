/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTests.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:02:45 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/21 19:20:03 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORTESTS_CPP
# define VECTORTESTS_CPP

# define GREEN "\033[38;5;46m"
# define WHITE "\033[1;37m"
# define BLUE "\033[1;36m"
# define YELLOW "\033[1;33m"
# define RED "\033[1;31m"
# define PURPLE "\033[1;35m"
# define RESET "\033[m"

#include <sys/time.h>
#include <iomanip>

template<typename T>
void printStdVec(std::vector<T> v);

template<typename T>
void  printStdVecSize(std::vector<T> v);

template<typename T>
void  printStdVecCap(std::vector<T> v);

template<typename T>
void printMyVec(ft::vector<T> ft_v); 

template<typename T>
void  printMyVecSize(ft::vector<T> ft_v);

template<typename T>
void  printMyVecCap(ft::vector<T> ft_v);

template<typename T>
void printVecIters(T it, T ft_it);

template<typename T>
void  printAll(std::vector<T> v, ft::vector<T> ft_v);

#include "vTPrinter.tpp"

template<typename T>
bool cmpVecs(std::vector<T> & v, ft::vector<T> & ft_v);

template<typename T>
bool  cmpVecsSize(std::vector<T> & v, ft::vector<T> & ft_v);

template<typename T>
bool  cmpVecsCap(std::vector<T> & v, ft::vector<T> & ft_v);

template<typename T, typename vec>
void  cmpPerformanceHelper(size_t testnum, T value);

template<typename T>
bool  cmpPerformance(size_t testnum, bool printAllTests, T value);

template<typename T>
bool  cmpAll(std::vector<T> & v, ft::vector<T> & ft_v, T value);

#include "vTCmp.tpp"

std::string testType(size_t testnum);

template<typename T>
bool  test(std::vector<T> & v, ft::vector<T> & ft_v, bool printAllTests, size_t testnum, T value) {
  bool test = false;
  std::cout << WHITE << testnum << BLUE << testType(testnum) << RESET;
  if (cmpAll<T>(v, ft_v, testnum, value)) {
    test = true;
    std::cout << GREEN << "OK" << RESET << std::endl;
  }
  else
    std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) {
    printAll<T>(v, ft_v);
    cmpPerformance<T>(testnum, true, value);
  }
  std::cout << std::endl;
  return test;
}


bool  vectorIteratorsTest1(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorIteratorsTest2(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorIteratorsTest3(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorIteratorsTest4(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorIteratorsTest5(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorIteratorsTest6(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorIteratorsTest7(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorIteratorsTest8(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorIteratorsTest9(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorIteratorsTest10(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorIteratorsTest11(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorIteratorsTest12(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorIteratorsTest13(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorIteratorsTest14(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorIteratorsTest15(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorIterators(bool printAllTests);

bool  vectorConstIteratorsTest1(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstIteratorsTest2(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstIteratorsTest3(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstIteratorsTest4(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstIteratorsTest5(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstIteratorsTest6(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstIteratorsTest7(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstIteratorsTest8(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstIteratorsTest9(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstIteratorsTest10(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstIteratorsTest11(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstIteratorsTest12(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstIteratorsTest13(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstIteratorsTest14(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstIteratorsTest15(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstIterators(bool printAllTests);

bool  vectorReverseIteratorsTest1(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorReverseIteratorsTest2(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorReverseIteratorsTest3(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorReverseIteratorsTest4(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorReverseIteratorsTest5(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorReverseIteratorsTest6(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorReverseIteratorsTest7(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorReverseIteratorsTest8(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorReverseIteratorsTest9(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorReverseIteratorsTest10(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorReverseIteratorsTest11(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorReverseIteratorsTest12(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorReverseIteratorsTest13(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorReverseIteratorsTest14(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorReverseIteratorsTest15(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorReverseIterators(bool printAllTests);

bool  vBasicTest1(bool printAllTests);
bool  vBasicTest2(bool printAllTests);
bool  vBasicTest3(bool printAllTests);
bool  vBasicTest4(bool printAllTests);
bool  vBasicTest5(bool printAllTests);
bool  vBasicTest6(bool printAllTests);
bool  vBasicTest7(bool printAllTests);
bool  vBasicTest8(bool printAllTests);
bool  vBasicTest9(bool printAllTests);
bool  vBasicTest10(bool printAllTests);
bool  vectorBasic(bool printAllTests);

#endif
