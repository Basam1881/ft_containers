/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vTBasic.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 10:05:34 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/22 15:01:00 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include "vectorTests.hpp"

std::string vBasictestType(size_t testnum) {
  switch (testnum){
    case 1:
      return " : Default Constructor<int>                           : ";
    case 2:
      return " : Default Constructor<std::string>                   : ";
    case 3:
      return " : Fill Constructor<int> (one Param)                  : ";
    case 4:
      return " : Fill Constructor<std::string> (one Param)          : ";
    case 5:
      return " : Fill Constructor<int> (two Params)                 : ";
    case 6:
      return " : Fill Constructor<std::string> (two Params)         : ";
    case 7:
      return " : Range Constructor<int>                             : ";
    case 8:
      return " : Range Constructor<std::string>                     : ";
    case 9:
      return " : Copy Constructor<int>                              : ";
    case 10:
      return ": Copy Constructor<std::string>                       : ";
    case 11:
      return ": operator=() {empty2empty}                           : ";
    case 12:
      return ": operator=() {empty2filled}                          : ";
    case 13:
      return ": operator=() {filled2empty}                          : ";
    case 14: 
      return ": operator=() {bigger2smaller}                        : ";
    case 15:
      return ": operator=() {smaller2bigger}                        : ";
  }
  return NULL;
}

bool  vBasicTest1(bool printAllTests) {
  std::vector<int> v;
  ft::vector<int> ft_v;
  return vBasictest<int>(v, ft_v, printAllTests, 1, 1000);
}

bool  vBasicTest2(bool printAllTests) {
  std::vector<std::string> v;
  ft::vector<std::string> ft_v;
  return vBasictest<std::string>(v, ft_v, printAllTests, 2, "Bnaji");
}

bool  vBasicTest3(bool printAllTests) {
  std::vector<int> v(3);
  ft::vector<int> ft_v(3);
  return vBasictest<int>(v, ft_v, printAllTests, 3, 1000);
}

bool  vBasicTest4(bool printAllTests) {
  std::vector<std::string> v(4);
  ft::vector<std::string> ft_v(4);
  return vBasictest<std::string>(v, ft_v, printAllTests, 4, "Bnaji");
}

bool  vBasicTest5(bool printAllTests) {
  std::vector<int> v(5, 500);
  ft::vector<int> ft_v(5 , 500);
  return vBasictest<int>(v, ft_v, printAllTests, 5, 1000);
}

bool  vBasicTest6(bool printAllTests) {
  std::vector<std::string> v(6, "Bnaji");
  ft::vector<std::string> ft_v(6, "Bnaji");
  return vBasictest<std::string>(v, ft_v, printAllTests, 6, "Bnaji");
}

bool  vBasicTest7(bool printAllTests) {
  std::vector<int> v1(7, 700);
  ft::vector<int> ft_v1(7, 700);
  std::vector<int> v(v1.begin(), v1.end());
  ft::vector<int> ft_v(ft_v1.begin(), ft_v1.end());
  return vBasictest<int>(v, ft_v, printAllTests, 7, 1000);
}

bool  vBasicTest8(bool printAllTests) {
  std::vector<std::string> v1(8, "Bnaji");
  ft::vector<std::string> ft_v1(8, "Bnaji");
  std::vector<std::string> v(v1.begin(), v1.end());
  ft::vector<std::string> ft_v(ft_v1.begin(), ft_v1.end());
  return vBasictest<std::string>(v, ft_v, printAllTests, 8, "Bnaji");
}

bool  vBasicTest9(bool printAllTests) {
  std::vector<int> v1(9, 900);
  ft::vector<int> ft_v1(9, 900);
  std::vector<int> v(v1);
  ft::vector<int> ft_v(ft_v1);
  return vBasictest<int>(v, ft_v, printAllTests, 9, 1000);

}

bool  vBasicTest10(bool printAllTests) {
  std::vector<std::string> v1(10, "Bnaji");
  ft::vector<std::string> ft_v1(10, "Bnaji");
  std::vector<std::string> v(v1);
  ft::vector<std::string> ft_v(ft_v1);  
  return vBasictest<std::string>(v, ft_v, printAllTests, 10, "Bnaji");
}

bool  vBasicTest11(bool printAllTests) {
  std::vector<std::string> v1;
  ft::vector<std::string> ft_v1;
  std::vector<std::string> v;
  ft::vector<std::string> ft_v;
  v = v1;
  ft_v = ft_v1;
  return vBasictest<std::string>(v, ft_v, printAllTests, 11, "Bnaji");
}

bool  vBasicTest12(bool printAllTests) {
  std::vector<std::string> v1(5, "OPPS");
  ft::vector<std::string> ft_v1(5, "OPPS");
  std::vector<std::string> v;
  ft::vector<std::string> ft_v;
  v = v1;
  ft_v = ft_v1;
  return vBasictest<std::string>(v, ft_v, printAllTests, 12, "Bnaji");
}

bool  vBasicTest13(bool printAllTests) {
  std::vector<std::string> v1;
  ft::vector<std::string> ft_v1;
  std::vector<std::string> v(5, "OPPS");
  ft::vector<std::string> ft_v(5, "OPPS");
  v = v1;
  ft_v = ft_v1;
  return vBasictest<std::string>(v, ft_v, printAllTests, 13, "Bnaji");
}

bool  vBasicTest14(bool printAllTests) {
  std::vector<std::string> v1(10, "Bnaji");
  ft::vector<std::string> ft_v1(10, "Bnaji");
  std::vector<std::string> v(5, "OPPS");
  ft::vector<std::string> ft_v(5, "OPPS");
  v = v1;
  ft_v = ft_v1;
  return vBasictest<std::string>(v, ft_v, printAllTests, 14, "Bnaji");
}

bool  vBasicTest15(bool printAllTests) {
  std::vector<std::string> v1(5, "Bnaji");
  ft::vector<std::string> ft_v1(5, "Bnaji");
  std::vector<std::string> v(10, "OPPS");
  ft::vector<std::string> ft_v(10, "OPPS");
  v = v1;
  ft_v = ft_v1;
  return vBasictest<std::string>(v, ft_v, printAllTests, 15, "Bnaji");
}
