/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectortests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 09:35:09 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/18 10:07:04 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include "vectorTests.hpp"


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
    && vBasicTest9(printAllTests)
    && vBasicTest10(printAllTests)
  );
}
