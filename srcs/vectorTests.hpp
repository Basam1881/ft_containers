/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTests.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:02:45 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/22 16:59:39 by bnaji            ###   ########.fr       */
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
#include <limits.h>


/* ************************************** Printers ************************************** */
template<typename T>
void printStdVec(std::vector<T> const & v);

template<typename T>
void  printStdVecSize(std::vector<T> const & v);

template<typename T>
void  printStdVecCap(std::vector<T> const & v);

template<typename T>
void printMyVec(ft::vector<T> const & ft_v); 

template<typename T>
void  printMyVecSize(ft::vector<T> const & ft_v);

template<typename T>
void  printMyVecCap(ft::vector<T> const & ft_v);

template<typename T>
void printVecIters(T it, T ft_it);

template<typename T>
void  printAll(std::vector<T> const & v, ft::vector<T> const & ft_v);

#include "vTPrinter.tpp"


/* ************************************** Cmparators ************************************** */

template<typename T>
bool cmpVecs(std::vector<T> & v, ft::vector<T> & ft_v);

template<typename T>
bool  cmpVecsSize(std::vector<T> & v, ft::vector<T> & ft_v);

template<typename T>
bool  cmpVecsCap(std::vector<T> & v, ft::vector<T> & ft_v);

template<typename T, typename vec>
void  cmpPerformanceHelper(size_t testnum, T value);

template<typename T>
bool  cmpBasicPerformance(size_t testnum, bool printAllTests, T value);

template<typename T>
bool  cmpAll(std::vector<T> & v, ft::vector<T> & ft_v);

#include "vTCmp.tpp"



std::string vBasictestType(size_t testnum);
template<typename T>
bool  vBasictest(std::vector<T> & v, ft::vector<T> & ft_v, bool printAllTests, size_t testnum, T value) {
  bool test = false;  
  std::cout << WHITE << testnum << BLUE << vBasictestType(testnum) << RESET;
  if (cmpAll<T>(v, ft_v) && cmpBasicPerformance<T>(testnum, false, value)) {
    test = true;
    std::cout << GREEN << "OK" << RESET << std::endl;
  }
  else
    std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests) {
    if (testnum == 16) {
      printStdVecSize<T>(v);
      printMyVecSize<T>(ft_v);
      printStdVecCap<T>(v);
      printMyVecCap<T>(ft_v);
    }
    else
      printAll<T>(v, ft_v);
    cmpBasicPerformance<T>(testnum, true, value);
  }
  std::cout << std::endl;
  return test;
}
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
bool  vBasicTest11(bool printAllTests);
bool  vBasicTest12(bool printAllTests);
bool  vBasicTest13(bool printAllTests);
bool  vBasicTest14(bool printAllTests);
bool  vBasicTest15(bool printAllTests);
bool  vectorBasic(bool printAllTests);

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

bool  vectorConstReverseIteratorsTest1(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstReverseIteratorsTest2(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstReverseIteratorsTest3(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstReverseIteratorsTest4(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstReverseIteratorsTest5(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstReverseIteratorsTest6(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstReverseIteratorsTest7(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstReverseIteratorsTest8(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstReverseIteratorsTest9(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstReverseIteratorsTest10(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstReverseIteratorsTest11(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstReverseIteratorsTest12(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstReverseIteratorsTest13(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstReverseIteratorsTest14(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstReverseIteratorsTest15(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorConstReverseIterators(bool printAllTests);

bool  vectorElementAccessTest1(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorElementAccessTest2(std::vector<int> const & v, ft::vector<int> const & ft_v, bool printAllTests, size_t testnum);
bool  vectorElementAccessTest3(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorElementAccessTest4(std::vector<int> const & v, ft::vector<int> const & ft_v, bool printAllTests, size_t testnum);
bool  vectorElementAccessTest5(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorElementAccessTest6(std::vector<int> const & v, ft::vector<int> const & ft_v, bool printAllTests, size_t testnum);
bool  vectorElementAccessTest7(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorElementAccessTest8(std::vector<int> const & v, ft::vector<int> const & ft_v, bool printAllTests, size_t testnum);
bool  vectorElementAccessTest9(std::vector<int> & v, ft::vector<int> & ft_v, bool printAllTests, size_t testnum);
bool  vectorElementAccessTest10(std::vector<int> const & v, ft::vector<int> const & ft_v, bool printAllTests, size_t testnum);
bool  vectorElementAccess(bool printAllTests);

bool  vectorCapacityTest1(bool printAllTests, size_t testnum);
bool  vectorCapacityTest2(bool printAllTests, size_t testnum);
bool  vectorCapacityTest3(bool printAllTests, size_t testnum);
bool  vectorCapacityTest4(bool printAllTests, size_t testnum);
bool  vectorCapacityTest5(bool printAllTests, size_t testnum);
// bool  vectorCapacityTest6(bool printAllTests, size_t testnum);
// bool  vectorCapacityTest7(bool printAllTests, size_t testnum);
// bool  vectorCapacityTest8(bool printAllTests, size_t testnum);
// bool  vectorCapacityTest9(bool printAllTests, size_t testnum);
// bool  vectorCapacityTest10(bool printAllTests, size_t testnum);
bool  vectorCapacity(bool printAllTests);



#endif
