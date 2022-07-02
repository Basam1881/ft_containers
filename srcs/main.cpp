/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:52:50 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/02 09:46:53 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "../vector/vector.hpp"
#include "../map/map.hpp"
#include "vectorTests.hpp"
#include "limits.h"
#include <sys/time.h>

void  help() {
  int i = 1;
  std::cout << i++ << " : \"" << "Vall" << "\"" << std::endl;
  std::cout << i++ << " : \"" << "VallValgrind" << "\"" << std::endl;
  std::cout << i++ << " : \"" << "Vbasic" << "\"" << std::endl;
  std::cout << i++ << " : \"" << "Viterator" << "\"" << std::endl;
  std::cout << i++ << " : \"" << "VconstIterator" << "\"" << std::endl;
  std::cout << i++ << " : \"" << "VreverseIterator" << "\"" << std::endl;
  std::cout << i++ << " : \"" << "VconstReverseIterator" << "\"" << std::endl;
  std::cout << i++ << " : \"" << "VelementAccess" << "\"" << std::endl;
  std::cout << i++ << " : \"" << "Vcapacity" << "\"" << std::endl;
  std::cout << i++ << ": \"" << "Vmodifiers" << "\"" << std::endl;
  std::cout << i++ << ": \"" << "VnonMemberFunctions" << "\"" << std::endl;
  std::cout << i++ << ": \"" << "Vexceptions" << "\"" << std::endl;
}

int main() {
  std::string str;
  std::cout << PURPLE << "Enter test name: " << RESET;
  while (std::cin >> str) {
    if (!str.compare("Vall") || !str.compare("1"))
      vectorAll(false, false);
    else if (!str.compare("VallValgrind") || !str.compare("2"))
      vectorAll(false, true);
    else if (!str.compare("Vbasic") || !str.compare("3"))
      vectorBasic(false);
    else if (!str.compare("Viterator") || !str.compare("4"))
      vectorIterators(false);
    else if (!str.compare("VconstIterator") || !str.compare("5"))
      vectorConstIterators(false);
    else if (!str.compare("VreverseIterator") || !str.compare("6"))
      vectorReverseIterators(false);
    else if (!str.compare("VconstReverseIterator") || !str.compare("7"))
      vectorConstReverseIterators(false);
    else if (!str.compare("VelementAccess") || !str.compare("8"))
      vectorElementAccess(false);
    else if (!str.compare("Vcapacity") || !str.compare("9"))
      vectorCapacity(false);
    else if (!str.compare("Vmodifiers") || !str.compare("10"))
      vectorModifiers(false);
    else if (!str.compare("VnonMemberFunctions") || !str.compare("11"))
      vectorNonMemberFunctions(false);
    else if (!str.compare("Vexceptions") || !str.compare("12"))
      vectorException(false);
    else if (!str.compare("help"))
      help();
    else
      std::cout << RED << "Invalid test" << RESET << std::endl;
    std::cout << PURPLE << "Enter test name: " << RESET;
  }
  std::cout << std::endl << std::endl;

  
}