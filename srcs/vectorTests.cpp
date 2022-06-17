/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectortests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:35:09 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/17 18:58:45 by bnaji            ###   ########.fr       */
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
  ft::vector<int> ft_v(5 , 42);
  bool test = false;
  std::cout << BLUE << "5: Fill Constructor<int> : " << RESET;
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

bool   vBasicTest6(bool printAllTests) {
  std::vector<std::string> v(5, "Bnaji");
  ft::vector<std::string> ft_v(5, "Bnaji");
  bool test = false;
  std::cout << BLUE << "6: Fill Constructor<std::string> : " << RESET;
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

bool   vBasicTest7(bool printAllTests) {
  std::vector<int> v1(3, 500);
  ft::vector<int> ft_v1(3, 500);
  std::vector<int> v(v1.begin(), v1.end());
  ft::vector<int> ft_v(ft_v1.begin(), ft_v1.end());
  bool test = false;
  std::cout << BLUE << "7: Range Constructor<int> : " << RESET;
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

bool   vBasicTest8(bool printAllTests) {
  std::vector<std::string> v1(3, "Bnaji");
  ft::vector<std::string> ft_v1(3, "Bnaji");
  std::vector<std::string> v(v1.begin(), v1.end());
  ft::vector<std::string> ft_v(ft_v1.begin(), ft_v1.end());
  bool test = false;
  std::cout << BLUE << "7: Range Constructor<std::string> : " << RESET;
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



bool  vectorBasic(bool printAllTests) {
  return (
    vBasicTest1(printAllTests)
    && vBasicTest2(printAllTests)
    && vBasicTest3(printAllTests)
    && vBasicTest4(printAllTests)
    && vBasicTest5(printAllTests)
    && vBasicTest6(printAllTests)
    && vBasicTest7(printAllTests)
    && vBasicTest8(printAllTests)
  );
}
