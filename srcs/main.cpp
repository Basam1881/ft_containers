/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:52:50 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/24 07:09:54 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include "vectorTests.hpp"
#include "limits.h"
#include <sys/time.h>

int main() {
  vectorBasic(true);
  std::cout << std::endl << std::endl;
  vectorIterators(false);
  std::cout << std::endl << std::endl;
  vectorConstIterators(false);
  std::cout << std::endl << std::endl;
  vectorReverseIterators(false);
  std::cout << std::endl << std::endl;
  vectorConstReverseIterators(false);
  std::cout << std::endl << std::endl;
  vectorElementAccess(false);
  std::cout << std::endl << std::endl;
  vectorCapacity(false);
  std::cout << std::endl << std::endl;
  vectorModifiers(true);

  
/* 
  try { v1.insert(v1.begin() + v1.size(), v1.max_size() + 1, 5); }
  catch (const std::length_error& le) {}
  try { ft_v1.insert(ft_v1.begin() + ft_v1.size(), v1.max_size() + 1, 5); }
  catch (const std::length_error& le) {}
  try { v1.insert(v1.begin() + v1.size(), v1.max_size() / 2, 5); }
  catch (const std::bad_alloc& le) {}
  try { ft_v1.insert(ft_v1.begin() + ft_v1.size(), ft_v1.max_size() / 2, 5); }
  catch (const std::bad_alloc& le) {}
 */
}