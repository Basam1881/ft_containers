/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorTests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:35:09 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/22 14:39:00 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include "vectorTests.hpp"

bool  vectorBasic(bool printAllTests) {
  std::cout << PURPLE << "<====================" << WHITE << " vector Basic Test " << PURPLE << "====================>" << RESET << std::endl;
  return (
    vBasicTest1(printAllTests)
    && vBasicTest2(printAllTests)
    && vBasicTest3(printAllTests)
    && vBasicTest4(printAllTests)
    && vBasicTest5(printAllTests)
    && vBasicTest6(printAllTests)
    && vBasicTest7(printAllTests)
    && vBasicTest8(printAllTests)
    && vBasicTest9(printAllTests)
    && vBasicTest10(printAllTests)
    && vBasicTest11(printAllTests)
    && vBasicTest12(printAllTests)
    && vBasicTest13(printAllTests)
    && vBasicTest14(printAllTests)
    && vBasicTest15(printAllTests)
    && vBasicTest16(printAllTests)
    && vBasicTest17(printAllTests)
  );
}

bool  vectorIterators(bool printAllTests) {
  std::cout << PURPLE << "<====================" << WHITE << " vector Iterators Test " << PURPLE << "====================>" << RESET << std::endl;
  size_t n = 20;
  std::vector<int> v(n); ft::vector<int> ft_v(n);
  for (size_t i = 0; i < n; i++) {
    v[i] = i; ft_v[i] = i;
  }
  return (
    vectorIteratorsTest1(v, ft_v, printAllTests, 1)
    && vectorIteratorsTest2(v, ft_v, printAllTests, 2)
    && vectorIteratorsTest3(v, ft_v, printAllTests, 3)
    && vectorIteratorsTest4(v, ft_v, printAllTests, 4)
    && vectorIteratorsTest5(v, ft_v, printAllTests, 5)
    && vectorIteratorsTest6(v, ft_v, printAllTests, 6)
    && vectorIteratorsTest7(v, ft_v, printAllTests, 7)
    && vectorIteratorsTest8(v, ft_v, printAllTests, 8)
    && vectorIteratorsTest9(v, ft_v, printAllTests, 9)
    && vectorIteratorsTest10(v, ft_v, printAllTests, 10)
    && vectorIteratorsTest11(v, ft_v, printAllTests, 11)
    && vectorIteratorsTest12(v, ft_v, printAllTests, 12)
    && vectorIteratorsTest13(v, ft_v, printAllTests, 13)
    && vectorIteratorsTest14(v, ft_v, printAllTests, 14)
    && vectorIteratorsTest15(v, ft_v, printAllTests, 15)
    );
}

bool  vectorConstIterators(bool printAllTests) {
  std::cout << PURPLE << "<====================" << WHITE << " vector Const Iterators Test " << PURPLE << "====================>" << RESET << std::endl;
  size_t n = 20;
  std::vector<int> v(n); ft::vector<int> ft_v(n);
  for (size_t i = 0; i < n; i++) {
    v[i] = i; ft_v[i] = i;
  }
  return (
    vectorConstIteratorsTest1(v, ft_v, printAllTests, 1)
    && vectorConstIteratorsTest2(v, ft_v, printAllTests, 2)
    && vectorConstIteratorsTest3(v, ft_v, printAllTests, 3)
    && vectorConstIteratorsTest4(v, ft_v, printAllTests, 4)
    && vectorConstIteratorsTest5(v, ft_v, printAllTests, 5)
    && vectorConstIteratorsTest6(v, ft_v, printAllTests, 6)
    && vectorConstIteratorsTest7(v, ft_v, printAllTests, 7)
    && vectorConstIteratorsTest8(v, ft_v, printAllTests, 8)
    && vectorConstIteratorsTest9(v, ft_v, printAllTests, 9)
    && vectorConstIteratorsTest10(v, ft_v, printAllTests, 10)
    && vectorConstIteratorsTest11(v, ft_v, printAllTests, 11)
    && vectorConstIteratorsTest12(v, ft_v, printAllTests, 12)
    && vectorConstIteratorsTest13(v, ft_v, printAllTests, 13)
    && vectorConstIteratorsTest14(v, ft_v, printAllTests, 14)
    && vectorConstIteratorsTest15(v, ft_v, printAllTests, 15)
    );
}

bool  vectorReverseIterators(bool printAllTests) {
  std::cout << PURPLE << "<====================" << WHITE << " vector Reverse Iterators Test " << PURPLE << "====================>" << RESET << std::endl;
  size_t n = 20;
  std::vector<int> v(n); ft::vector<int> ft_v(n);
  for (size_t i = 0; i < n; i++) {
    v[i] = i; ft_v[i] = i;
  }
  return (
    vectorReverseIteratorsTest1(v, ft_v, printAllTests, 1)
    && vectorReverseIteratorsTest2(v, ft_v, printAllTests, 2)
    && vectorReverseIteratorsTest3(v, ft_v, printAllTests, 3)
    && vectorReverseIteratorsTest4(v, ft_v, printAllTests, 4)
    && vectorReverseIteratorsTest5(v, ft_v, printAllTests, 5)
    && vectorReverseIteratorsTest6(v, ft_v, printAllTests, 6)
    && vectorReverseIteratorsTest7(v, ft_v, printAllTests, 7)
    && vectorReverseIteratorsTest8(v, ft_v, printAllTests, 8)
    && vectorReverseIteratorsTest9(v, ft_v, printAllTests, 9)
    && vectorReverseIteratorsTest10(v, ft_v, printAllTests, 10)
    && vectorReverseIteratorsTest11(v, ft_v, printAllTests, 11)
    && vectorReverseIteratorsTest12(v, ft_v, printAllTests, 12)
    && vectorReverseIteratorsTest13(v, ft_v, printAllTests, 13)
    && vectorReverseIteratorsTest14(v, ft_v, printAllTests, 14)
    && vectorReverseIteratorsTest15(v, ft_v, printAllTests, 15)
    );
}

bool  vectorConstReverseIterators(bool printAllTests) {
  std::cout << PURPLE << "<====================" << WHITE << " vector Const Reverse Iterators Test " << PURPLE << "====================>" << RESET << std::endl;
  size_t n = 20;
  std::vector<int> v(n); ft::vector<int> ft_v(n);
  for (size_t i = 0; i < n; i++) {
    v[i] = i; ft_v[i] = i;
  }
  return (
    vectorConstReverseIteratorsTest1(v, ft_v, printAllTests, 1)
    && vectorConstReverseIteratorsTest2(v, ft_v, printAllTests, 2)
    && vectorConstReverseIteratorsTest3(v, ft_v, printAllTests, 3)
    && vectorConstReverseIteratorsTest4(v, ft_v, printAllTests, 4)
    && vectorConstReverseIteratorsTest5(v, ft_v, printAllTests, 5)
    && vectorConstReverseIteratorsTest6(v, ft_v, printAllTests, 6)
    && vectorConstReverseIteratorsTest7(v, ft_v, printAllTests, 7)
    && vectorConstReverseIteratorsTest8(v, ft_v, printAllTests, 8)
    && vectorConstReverseIteratorsTest9(v, ft_v, printAllTests, 9)
    && vectorConstReverseIteratorsTest10(v, ft_v, printAllTests, 10)
    && vectorConstReverseIteratorsTest11(v, ft_v, printAllTests, 11)
    && vectorConstReverseIteratorsTest12(v, ft_v, printAllTests, 12)
    && vectorConstReverseIteratorsTest13(v, ft_v, printAllTests, 13)
    && vectorConstReverseIteratorsTest14(v, ft_v, printAllTests, 14)
    && vectorConstReverseIteratorsTest15(v, ft_v, printAllTests, 15)
    );
}

bool  vectorElementAccess(bool printAllTests) {
  std::cout << PURPLE << "<====================" << WHITE << " vector Element Access Test " << PURPLE << "====================>" << RESET << std::endl;
  size_t n = 20;
  std::vector<int> v(n); ft::vector<int> ft_v(n);
  for (size_t i = 0; i < n; i++) {
    v[i] = i; ft_v[i] = i;
  }
  return (
    vectorElementAccessTest1(v, ft_v, printAllTests, 1)
    && vectorElementAccessTest2(v, ft_v, printAllTests, 2)
    && vectorElementAccessTest3(v, ft_v, printAllTests, 3)
    && vectorElementAccessTest4(v, ft_v, printAllTests, 4)
    && vectorElementAccessTest5(v, ft_v, printAllTests, 5)
    && vectorElementAccessTest6(v, ft_v, printAllTests, 6)
    && vectorElementAccessTest7(v, ft_v, printAllTests, 7)
    && vectorElementAccessTest8(v, ft_v, printAllTests, 8)
    && vectorElementAccessTest9(v, ft_v, printAllTests, 9)
    && vectorElementAccessTest10(v, ft_v, printAllTests, 10)
    );
}
