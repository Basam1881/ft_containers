/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:52:50 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/26 16:14:41 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
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
    if (!str.compare("Vall"))
      vectorAll(false, false);
    else if (!str.compare("VallValgrind"))
      vectorAll(false, true);
    else if (!str.compare("Vbasic"))
      vectorBasic(false);
    else if (!str.compare("Viterator"))
      vectorIterators(false);
    else if (!str.compare("VconstIterator"))
      vectorConstIterators(false);
    else if (!str.compare("VreverseIterator"))
      vectorReverseIterators(false);
    else if (!str.compare("VconstReverseIterator"))
      vectorConstReverseIterators(false);
    else if (!str.compare("VelementAccess"))
      vectorElementAccess(false);
    else if (!str.compare("Vcapacity"))
      vectorCapacity(false);
    else if (!str.compare("Vmodifiers"))
      vectorModifiers(false);
    else if (!str.compare("VnonMemberFunctions"))
      vectorNonMemberFunctions(false);
    else if (!str.compare("Vexceptions"))
      vectorException(false);
    else if (!str.compare("help"))
      help();
    else
      std::cout << RED << "Invalid test" << RESET << std::endl;
    std::cout << PURPLE << "Enter test name: " << RESET;
  }
  std::cout << std::endl << std::endl;
}