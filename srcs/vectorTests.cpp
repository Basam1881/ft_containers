/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectortests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:35:09 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/17 12:15:00 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include "vectorTests.hpp"

bool   vBasicTest1(bool printAllTests) {
  std::vector<int> v;
  ft::vector<int> ft_v;
  bool test = false;
  std::cout << BLUE << "1: Default Constructor<int> : " << RESET;
  if (cmpAll<int>(v, ft_v)) {
    test = true;
    std::cout << GREEN << "OK" << RESET << std::endl;
  }
  else
    std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests)
    printAll<int>(v, ft_v);
  std::cout << std::endl;
  return test;
}

bool   vBasicTest2(bool printAllTests) {
  std::vector<std::string> v;
  ft::vector<std::string> ft_v;
  bool test = false;
  std::cout << BLUE << "2: Default Constructor<std::string> : " << RESET;
  if (cmpAll<std::string>(v, ft_v)) {
    test = true;
    std::cout << GREEN << "OK" << RESET << std::endl;
  }
  else
    std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests)
    printAll<std::string>(v, ft_v);
  std::cout << std::endl;
  return test;
}

bool   vBasicTest3(bool printAllTests) {
  std::vector<int> v(5);
  ft::vector<int> ft_v(5);
  bool test = false;
  std::cout << BLUE << "3: Fill Constructor<int> : " << RESET;
  if (cmpAll<int>(v, ft_v)) {
    test = true;
    std::cout << GREEN << "OK" << RESET << std::endl;
  }
  else
    std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests)
    printAll<int>(v, ft_v);
  std::cout << std::endl;
  return test;
}

bool   vBasicTest4(bool printAllTests) {
  std::vector<std::string> v(5);
  ft::vector<std::string> ft_v(5);
  bool test = false;
  std::cout << BLUE << "4: Fill Constructor<std::string> : " << RESET;
  if (cmpAll<std::string>(v, ft_v)) {
    test = true;
    std::cout << GREEN << "OK" << RESET << std::endl;
  }
  else
    std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests)
    printAll<std::string>(v, ft_v);
  std::cout << std::endl;
  return test;
}


bool   vBasicTest5(bool printAllTests) {
  std::vector<int> v(5, 42);
  ft::vector<int> ft_v(5);
  bool test = false;
  std::cout << BLUE << "3: Fill Constructor<int> : " << RESET;
  if (cmpAll<int>(v, ft_v)) {
    test = true;
    std::cout << GREEN << "OK" << RESET << std::endl;
  }
  else
    std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests)
    printAll<int>(v, ft_v);
  std::cout << std::endl;
  return test;
}


bool   vBasicTest3(bool printAllTests) {
  std::vector<int> v(5);
  ft::vector<int> ft_v(5);
  bool test = false;
  std::cout << BLUE << "3: Fill Constructor<int> : " << RESET;
  if (cmpAll<int>(v, ft_v)) {
    test = true;
    std::cout << GREEN << "OK" << RESET << std::endl;
  }
  else
    std::cout << RED << "KO" << RESET << std::endl;
  if (!test || printAllTests)
    printAll<int>(v, ft_v);
  std::cout << std::endl;
  return test;
}

bool  vectorBasic(bool printAllTests) {
  return (
    vBasicTest1(printAllTests)
    && vBasicTest2(printAllTests)
    && vBasicTest3(printAllTests)
    && vBasicTest4(printAllTests)
  );
}
