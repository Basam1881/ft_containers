/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:35:09 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/02 07:37:17 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "vectorTests.hpp"

bool  vectorBasic(bool printAllTests) {
  std::cout << PURPLE << "<====================" << WHITE << " vector Basic Test " << PURPLE << "====================>" << RESET << std::endl;
  bool test = true;
  if (!vBasicTest1(printAllTests)) test = false;
  if (!vBasicTest2(printAllTests)) test = false;
  if (!vBasicTest3(printAllTests)) test = false;
  if (!vBasicTest4(printAllTests)) test = false;
  if (!vBasicTest5(printAllTests)) test = false;
  if (!vBasicTest6(printAllTests)) test = false;
  if (!vBasicTest7(printAllTests)) test = false;
  if (!vBasicTest8(printAllTests)) test = false;
  if (!vBasicTest9(printAllTests)) test = false;
  if (!vBasicTest10(printAllTests)) test = false;
  if (!vBasicTest11(printAllTests)) test = false;
  if (!vBasicTest12(printAllTests)) test = false;
  if (!vBasicTest13(printAllTests)) test = false;
  if (!vBasicTest14(printAllTests)) test = false;
  if (!vBasicTest15(printAllTests)) test = false;
  return test;
}

bool  vectorIterators(bool printAllTests) {
  std::cout << PURPLE << "<====================" << WHITE << " vector Iterators Test " << PURPLE << "====================>" << RESET << std::endl;
  size_t n = 20;
  std::vector<int> v(n); ft::vector<int> ft_v(n);
  for (size_t i = 0; i < n; i++) {
    v[i] = i; ft_v[i] = i;
  }
  bool test = true;
  if (!vectorIteratorsTest1(v, ft_v, printAllTests, 1)) test = false;
  if (!vectorIteratorsTest2(v, ft_v, printAllTests, 2)) test = false;
  if (!vectorIteratorsTest3(v, ft_v, printAllTests, 3)) test = false;
  if (!vectorIteratorsTest4(v, ft_v, printAllTests, 4)) test = false;
  if (!vectorIteratorsTest5(v, ft_v, printAllTests, 5)) test = false;
  if (!vectorIteratorsTest6(v, ft_v, printAllTests, 6)) test = false;
  if (!vectorIteratorsTest7(v, ft_v, printAllTests, 7)) test = false;
  if (!vectorIteratorsTest8(v, ft_v, printAllTests, 8)) test = false;
  if (!vectorIteratorsTest9(v, ft_v, printAllTests, 9)) test = false;
  if (!vectorIteratorsTest10(v, ft_v, printAllTests, 10)) test = false;
  if (!vectorIteratorsTest11(v, ft_v, printAllTests, 11)) test = false;
  if (!vectorIteratorsTest12(v, ft_v, printAllTests, 12)) test = false;
  if (!vectorIteratorsTest13(v, ft_v, printAllTests, 13)) test = false;
  if (!vectorIteratorsTest14(v, ft_v, printAllTests, 14)) test = false;
  if (!vectorIteratorsTest15(v, ft_v, printAllTests, 15)) test = false;
  return test;
}

bool  vectorConstIterators(bool printAllTests) {
  std::cout << PURPLE << "<====================" << WHITE << " vector Const Iterators Test " << PURPLE << "====================>" << RESET << std::endl;
  size_t n = 20;
  std::vector<int> v(n); ft::vector<int> ft_v(n);
  for (size_t i = 0; i < n; i++) {
    v[i] = i; ft_v[i] = i;
  }
  bool test = true;
  if (!vectorConstIteratorsTest1(v, ft_v, printAllTests, 1)) test = false;
  if (!vectorConstIteratorsTest2(v, ft_v, printAllTests, 2)) test = false;
  if (!vectorConstIteratorsTest3(v, ft_v, printAllTests, 3)) test = false;
  if (!vectorConstIteratorsTest4(v, ft_v, printAllTests, 4)) test = false;
  if (!vectorConstIteratorsTest5(v, ft_v, printAllTests, 5)) test = false;
  if (!vectorConstIteratorsTest6(v, ft_v, printAllTests, 6)) test = false;
  if (!vectorConstIteratorsTest7(v, ft_v, printAllTests, 7)) test = false;
  if (!vectorConstIteratorsTest8(v, ft_v, printAllTests, 8)) test = false;
  if (!vectorConstIteratorsTest9(v, ft_v, printAllTests, 9)) test = false;
  if (!vectorConstIteratorsTest10(v, ft_v, printAllTests, 10)) test = false;
  if (!vectorConstIteratorsTest11(v, ft_v, printAllTests, 11)) test = false;
  if (!vectorConstIteratorsTest12(v, ft_v, printAllTests, 12)) test = false;
  if (!vectorConstIteratorsTest13(v, ft_v, printAllTests, 13)) test = false;
  if (!vectorConstIteratorsTest14(v, ft_v, printAllTests, 14)) test = false;
  if (!vectorConstIteratorsTest15(v, ft_v, printAllTests, 15)) test = false;
  return test;
}

bool  vectorReverseIterators(bool printAllTests) {
  std::cout << PURPLE << "<====================" << WHITE << " vector Reverse Iterators Test " << PURPLE << "====================>" << RESET << std::endl;
  size_t n = 20;
  std::vector<int> v(n); ft::vector<int> ft_v(n);
  for (size_t i = 0; i < n; i++) {
    v[i] = i; ft_v[i] = i;
  }
  bool test = true;
  if (!vectorReverseIteratorsTest1(v, ft_v, printAllTests, 1)) test = false;
  if (!vectorReverseIteratorsTest2(v, ft_v, printAllTests, 2)) test = false;
  if (!vectorReverseIteratorsTest3(v, ft_v, printAllTests, 3)) test = false;
  if (!vectorReverseIteratorsTest4(v, ft_v, printAllTests, 4)) test = false;
  if (!vectorReverseIteratorsTest5(v, ft_v, printAllTests, 5)) test = false;
  if (!vectorReverseIteratorsTest6(v, ft_v, printAllTests, 6)) test = false;
  if (!vectorReverseIteratorsTest7(v, ft_v, printAllTests, 7)) test = false;
  if (!vectorReverseIteratorsTest8(v, ft_v, printAllTests, 8)) test = false;
  if (!vectorReverseIteratorsTest9(v, ft_v, printAllTests, 9)) test = false;
  if (!vectorReverseIteratorsTest10(v, ft_v, printAllTests, 10)) test = false;
  if (!vectorReverseIteratorsTest11(v, ft_v, printAllTests, 11)) test = false;
  if (!vectorReverseIteratorsTest12(v, ft_v, printAllTests, 12)) test = false;
  if (!vectorReverseIteratorsTest13(v, ft_v, printAllTests, 13)) test = false;
  if (!vectorReverseIteratorsTest14(v, ft_v, printAllTests, 14)) test = false;
  if (!vectorReverseIteratorsTest15(v, ft_v, printAllTests, 15)) test = false;
  return test;
}

bool  vectorConstReverseIterators(bool printAllTests) {
  std::cout << PURPLE << "<====================" << WHITE << " vector Const Reverse Iterators Test " << PURPLE << "====================>" << RESET << std::endl;
  size_t n = 20;
  std::vector<int> v(n); ft::vector<int> ft_v(n);
  for (size_t i = 0; i < n; i++) {
    v[i] = i; ft_v[i] = i;
  }
  bool test = true;
  if (!vectorConstReverseIteratorsTest1(v, ft_v, printAllTests, 1)) test = false;
  if (!vectorConstReverseIteratorsTest2(v, ft_v, printAllTests, 2)) test = false;
  if (!vectorConstReverseIteratorsTest3(v, ft_v, printAllTests, 3)) test = false;
  if (!vectorConstReverseIteratorsTest4(v, ft_v, printAllTests, 4)) test = false;
  if (!vectorConstReverseIteratorsTest5(v, ft_v, printAllTests, 5)) test = false;
  if (!vectorConstReverseIteratorsTest6(v, ft_v, printAllTests, 6)) test = false;
  if (!vectorConstReverseIteratorsTest7(v, ft_v, printAllTests, 7)) test = false;
  if (!vectorConstReverseIteratorsTest8(v, ft_v, printAllTests, 8)) test = false;
  if (!vectorConstReverseIteratorsTest9(v, ft_v, printAllTests, 9)) test = false;
  if (!vectorConstReverseIteratorsTest10(v, ft_v, printAllTests, 10)) test = false;
  if (!vectorConstReverseIteratorsTest11(v, ft_v, printAllTests, 11)) test = false;
  if (!vectorConstReverseIteratorsTest12(v, ft_v, printAllTests, 12)) test = false;
  if (!vectorConstReverseIteratorsTest13(v, ft_v, printAllTests, 13)) test = false;
  if (!vectorConstReverseIteratorsTest14(v, ft_v, printAllTests, 14)) test = false;
  if (!vectorConstReverseIteratorsTest15(v, ft_v, printAllTests, 15)) test = false;
  return test;
}

bool  vectorElementAccess(bool printAllTests) {
  std::cout << PURPLE << "<====================" << WHITE << " vector Element Access Test " << PURPLE << "====================>" << RESET << std::endl;
  size_t n = 20;
  std::vector<int> v(n); ft::vector<int> ft_v(n);
  for (size_t i = 0; i < n; i++) {
    v[i] = i; ft_v[i] = i;
  }
  bool test = true;
  if (!vectorElementAccessTest1(v, ft_v, printAllTests, 1)) test = false;
  if (!vectorElementAccessTest2(v, ft_v, printAllTests, 2)) test = false;
  if (!vectorElementAccessTest3(v, ft_v, printAllTests, 3)) test = false;
  if (!vectorElementAccessTest4(v, ft_v, printAllTests, 4)) test = false;
  if (!vectorElementAccessTest5(v, ft_v, printAllTests, 5)) test = false;
  if (!vectorElementAccessTest6(v, ft_v, printAllTests, 6)) test = false;
  if (!vectorElementAccessTest7(v, ft_v, printAllTests, 7)) test = false;
  if (!vectorElementAccessTest8(v, ft_v, printAllTests, 8)) test = false;
  if (!vectorElementAccessTest9(v, ft_v, printAllTests, 9)) test = false;
  if (!vectorElementAccessTest10(v, ft_v, printAllTests, 10)) test = false;
  return test;
}

bool  vectorCapacity(bool printAllTests) {
  std::cout << PURPLE << "<====================" << WHITE << " vector Capacity Test " << PURPLE << "====================>" << RESET << std::endl;
  bool test = true;
  if (!vectorCapacityTest1(printAllTests, 1)) test = false;
  if (!vectorCapacityTest2(printAllTests, 2)) test = false;
  if (!vectorCapacityTest3(printAllTests, 3)) test = false;
  if (!vectorCapacityTest4(printAllTests, 4)) test = false;
  if (!vectorCapacityTest5(printAllTests, 5)) test = false;
  if (!vectorCapacityTest6(printAllTests, 6)) test = false;
  return test;
}

bool  vectorModifiers(bool printAllTests) {
  std::cout << PURPLE << "<====================" << WHITE << " vector Modifier Test " << PURPLE << "====================>" << RESET << std::endl;
  bool test = true;
  if (!vectorModifiersTest1(printAllTests, 1)) test = false;
  if (!vectorModifiersTest2(printAllTests, 2)) test = false;
  if (!vectorModifiersTest3(printAllTests, 3)) test = false;
  if (!vectorModifiersTest4(printAllTests, 4)) test = false;
  if (!vectorModifiersTest5(printAllTests, 5)) test = false;
  if (!vectorModifiersTest6(printAllTests, 6)) test = false;
  if (!vectorModifiersTest7(printAllTests, 7)) test = false;
  if (!vectorModifiersTest8(printAllTests, 8)) test = false;
  if (!vectorModifiersTest9(printAllTests, 9)) test = false;
  if (!vectorModifiersTest10(printAllTests, 10)) test = false;
  if (!vectorModifiersTest11(printAllTests, 11)) test = false;
  return test;
}

bool  vectorNonMemberFunctions(bool printAllTests) {
  std::cout << PURPLE << "<====================" << WHITE << " vector Non-Member Functions Test " << PURPLE << "====================>" << RESET << std::endl;
  bool test = true;
  if (!vectorNonMemberFunctionsTest1(printAllTests, 1)) test = false;
  if (!vectorNonMemberFunctionsTest2(printAllTests, 2)) test = false;
  if (!vectorNonMemberFunctionsTest3(printAllTests, 3)) test = false;
  if (!vectorNonMemberFunctionsTest4(printAllTests, 4)) test = false;
  if (!vectorNonMemberFunctionsTest5(printAllTests, 5)) test = false;
  if (!vectorNonMemberFunctionsTest6(printAllTests, 6)) test = false;
  if (!vectorNonMemberFunctionsTest7(printAllTests, 7)) test = false;
  return test;
}

bool  vectorException(bool printAllTests) {
  std::cout << PURPLE << "<====================" << WHITE << " vector Exception Test " << PURPLE << "====================>" << RESET << std::endl;
  bool test = true;
  if (!vectorExceptionTest1(printAllTests, 1)) test = false;
  if (!vectorExceptionTest2(printAllTests, 2)) test = false;
  if (!vectorExceptionTest3(printAllTests, 3)) test = false;
  if (!vectorExceptionTest4(printAllTests, 4)) test = false;
  if (!vectorExceptionTest5(printAllTests, 5)) test = false;
  if (!vectorExceptionTest6(printAllTests, 6)) test = false;
  if (!vectorExceptionTest7(printAllTests, 7)) test = false;
  if (!vectorExceptionTest8(printAllTests, 8)) test = false;
  return test;
}

bool  vectorAll(bool printAllTests, bool valgrind) {
  bool test = true;
  if (!vectorBasic(printAllTests)) test = false; 
  if (!vectorIterators(printAllTests)) test = false; 
  if (!vectorConstIterators(printAllTests)) test = false; 
  if (!vectorReverseIterators(printAllTests)) test = false; 
  if (!vectorConstReverseIterators(printAllTests)) test = false; 
  if (!vectorElementAccess(printAllTests)) test = false; 
  if (!vectorCapacity(printAllTests)) test = false; 
  if (!vectorModifiers(printAllTests)) test = false; 
  if (!vectorNonMemberFunctions(printAllTests)) test = false; 
  if (!valgrind && !vectorException(printAllTests)) test = false; 
  return test;
}
