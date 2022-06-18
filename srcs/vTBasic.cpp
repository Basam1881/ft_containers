/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vTBasic.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 10:05:34 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/18 13:34:03 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include "vectorTests.hpp"

std::string testType(size_t testnum) {
  switch (testnum){
    case 1:
      return " : Default Constructor<int>                   : ";
    case 2:
      return (" : Default Constructor<std::string>           : ");
    case 3:
      return " : Fill Constructor<int> (one Param)          : ";
    case 4:
      return " : Fill Constructor<std::string> (one Param)  : ";
    case 5:
      return " : Fill Constructor<int> (two Params)         : ";
    case 6:
      return " : Fill Constructor<std::string> (two Params) : ";
    case 7:
      return " : Range Constructor<int>                     : ";
    case 8:
      return " : Range Constructor<std::string>             : ";
    case 9:
      return " : Copy Constructor<int>                      : ";
    case 10:
      return ": Copy Constructor<std::string>              : ";
  }
  return NULL;
}

bool  vBasicTest1(bool printAllTests) {
  std::vector<int> v;
  ft::vector<int> ft_v;
  return test<int>(v, ft_v, printAllTests, 1);
}

bool  vBasicTest2(bool printAllTests) {
  std::vector<std::string> v;
  ft::vector<std::string> ft_v;
  return test<std::string>(v, ft_v, printAllTests, 2);
}

bool  vBasicTest3(bool printAllTests) {
  std::vector<int> v(3);
  ft::vector<int> ft_v(3);
  return test<int>(v, ft_v, printAllTests, 3);
}

bool  vBasicTest4(bool printAllTests) {
  std::vector<std::string> v(4);
  ft::vector<std::string> ft_v(4);
  return test<std::string>(v, ft_v, printAllTests, 4);
}

bool  vBasicTest5(bool printAllTests) {
  std::vector<int> v(5, 500);
  ft::vector<int> ft_v(5 , 500);
  return test<int>(v, ft_v, printAllTests, 5);
}

bool  vBasicTest6(bool printAllTests) {
  std::vector<std::string> v(6, "Bnaji");
  ft::vector<std::string> ft_v(6, "Bnaji");
  return test<std::string>(v, ft_v, printAllTests, 6);
}

bool  vBasicTest7(bool printAllTests) {
  std::vector<int> v1(7, 700);
  ft::vector<int> ft_v1(7, 700);
  std::vector<int> v(v1.begin(), v1.end());
  ft::vector<int> ft_v(ft_v1.begin(), ft_v1.end());
  return test<int>(v, ft_v, printAllTests, 7);
}

bool  vBasicTest8(bool printAllTests) {
  std::vector<std::string> v1(8, "Bnaji");
  ft::vector<std::string> ft_v1(8, "Bnaji");
  std::vector<std::string> v(v1.begin(), v1.end());
  ft::vector<std::string> ft_v(ft_v1.begin(), ft_v1.end());
  return test<std::string>(v, ft_v, printAllTests, 8);
}

bool  vBasicTest9(bool printAllTests) {
  std::vector<int> v1(9, 900);
  ft::vector<int> ft_v1(9, 900);
  std::vector<int> v(v1);
  ft::vector<int> ft_v(ft_v1);
  return test<int>(v, ft_v, printAllTests, 9);

}

bool  vBasicTest10(bool printAllTests) {
  std::vector<std::string> v1(10, "Bnaji");
  ft::vector<std::string> ft_v1(10, "Bnaji");
  std::vector<std::string> v(v1);
  ft::vector<std::string> ft_v(ft_v1);  
  return test<std::string>(v, ft_v, printAllTests, 10);
}