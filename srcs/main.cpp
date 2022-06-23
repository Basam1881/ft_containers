/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:52:50 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/23 08:24:32 by bnaji            ###   ########.fr       */
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
  vectorIterators(true);
  std::cout << std::endl << std::endl;
  vectorConstIterators(true);
  std::cout << std::endl << std::endl;
  vectorReverseIterators(true);
  std::cout << std::endl << std::endl;
  vectorConstReverseIterators(true);
  std::cout << std::endl << std::endl;
  vectorElementAccess(true);
  std::cout << std::endl << std::endl;
  vectorCapacity(true);
  std::cout << std::endl << std::endl;
  vectorModifiers(true);
  
  // std::vector<std::string> v1;
  // std::vector<std::string> v(5, "100");
  // v1 = v;
  // std::cout << v1.size() << std::endl;

  // ft::vector<int> v(5, 100);
  // ft::vector<int>::reverse_iterator it = v.rbegin();
  // v.insert(v.rbegin(), 10);
  // for (int i = 0; i < 5; i++)
  //   std::cout << v[i] << std::endl;
  // double sum = 0;
  // double add = 1;

  // // Start measuring time
  // struct timeval begin, end;
  // gettimeofday(&begin, 0);
  
  // int iterations = 10000;
  // for (int i=0; i<iterations; i++) {
  //     sum += add;
  //     add /= 2.0;
  // }
  
  // // Stop measuring time and calculate the elapsed time
  // gettimeofday(&end, 0);
  // long seconds = end.tv_sec - begin.tv_sec;
  // long microseconds = end.tv_usec - begin.tv_usec;
  // double elapsed = seconds + microseconds*1e-6;
  
  // printf("Result: %.20f\n", sum);
  
  // printf("Time measured: %.10f seconds.\n", elapsed);

  // gettimeofday(&begin, 0);
  
  // iterations = 1000;
  // for (int i=0; i<iterations; i++) {
  //     sum += add;
  //     add /= 2.0;
  // }
  
  // // Stop measuring time and calculate the elapsed time
  // gettimeofday(&end, 0);
  // seconds = end.tv_sec - begin.tv_sec;
  // microseconds = end.tv_usec - begin.tv_usec;
  // double elapsed1 = seconds + microseconds*1e-6;
  
  // printf("Result: %.20f\n", sum);
  
  // printf("Time measured: %.10f seconds.\n", elapsed1);

  // printf("\nratio (v / ft_v): %.10f seconds.\n", elapsed / elapsed1);
  
  // ft::vector<int> v(4, 500);
  // v.push_back(100);
  // ft::vector<int>::iterator it = v.begin();
  // ft::vector<int>::iterator it3 = it;
  // ft::vector<int>::const_iterator it1(it);
  // ft::vector<int>::const_iterator it2;
  // // *it = 2;
  // // *it1++;
  // // *it1++;
  // if (it3  == v.begin())
  //   std::cout << *it1++ << ' ' << *it1 << std::endl; 
  // ft::vector<int> v1(4, 500);
  // v1.push_back(100);
  // ft::vector<int>::reverse_iterator it4 = v1.rbegin();
  // ft::vector<int>::reverse_iterator it5 = it4;
  // ft::vector<int>::const_reverse_iterator it6(it4);
  // ft::vector<int>::const_reverse_iterator it7;
  // ft::vector<int>::reverse_iterator it8 = it4;
  // std::cout << std::endl;
  // std::cout << it6[0] << std::endl;
  // std::cout << it6[1] << std::endl;
  // std::cout << it6[2] << std::endl;
  // it8 = 2 + it8;
  // std::cout << std::endl << *it8 << std::endl;
  // *it6++;
  // // *it6++;
  // if ()
  // if (it5  == it6)
  //   std::cout << *it6++ << ' ' << *it6 << std::endl; 
  // std::cout << "Here\n";
  // std::is_integral<int>::value;
  
  
  // std::cout << "\n\n\n" << std::endl;
  // std::cout << "----------------------- v -----------------------\n";
  // std::vector<int> v(5, 500);
  // size_t i = 0;
  // // v.reserve(10);
  // v[4] = 100;
  // v.assign(6, 200);
  // std::vector<int>::iterator it(v.begin());
  // std::cout << "v       : ";
  // for ( ; it != v.end(); it++)
  //   std::cout << v[i++] << " ";
  // // std::cout << v[i] << " ";
  // std::cout << std::endl;
  // std::cout << "size    : " << v.size() << std::endl;
  // std::cout << "capacity: " << v.capacity() << std::endl;
  // // std::cout << "capacity: " << v.capacity() << std::endl;
  // std::cout << "max_size: " << v.max_size() << std::endl;
  // if (v.empty())
  //   std::cout << "empty   : Yes" << std::endl;
  // else
  //   std::cout << "empty   : No" << std::endl;
  // std::cout << "front   : " << v.front() << std::endl;
  // std::cout << "back    : " << v.back() << std::endl;
  // std::cout << "----------------------- v1 -----------------------\n";
  // std::vector<int> v1(v);
  // v1.assign(5, 300);
  // // for(int i = 0; i < 8; i++)
  // //   v1.push_back(5);
  // v1.insert(v1.begin() + v1.size() , v.begin() + 2 , v.end());
  // v1.erase(v1.begin(), v1.begin() + 5);
  // std::cout << "v       : ";
  // for (std::vector<int>::iterator it1(v1.begin()); it1 != v1.end(); it1++)
  //   std::cout << *it1 << " ";
  // std::cout << std::endl;
  // std::cout << "size: " << v1.size() << std::endl;
  // std::cout << "capacity: " << v1.capacity() << std::endl;

  // std::cout << "---------------------- ft_v ----------------------\n";
  // it = v.begin();
  // // std::vector<int>::iterator it1(v.end());
  // ft::vector<int> ft_v(5);
  // i = 0;
  // // ft_v.reserve(10);
  // for (int i = 0; i < 5; i++)
  //   ft_v[i] = 100;
  // // ft_v.assign(6, 200);
  // ft::vector<int>::iterator ft_it(ft_v.begin());
  // std::cout << "ft_v    : ";
  // for ( ; ft_it != ft_v.end(); ft_it++)
  //   std::cout << ft_v[i++] << " ";
  // // std::cout << ft_v[i] << " ";
  // std::cout << std::endl;
  // std::cout << "size    : " << ft_v.size() << std::endl;
  // std::cout << "capacity: " << ft_v.capacity() << std::endl;
  // std::cout << "max_size: " << ft_v.max_size() << std::endl;
  // if (ft_v.empty())
  //   std::cout << "empty   : Yes" << std::endl;
  // else
  //   std::cout << "empty   : No" << std::endl;
  // std::cout << "front   : " << ft_v.front() << std::endl;
  // std::cout << "back    : " << ft_v.back() << std::endl;

  // std::cout << "---------------------- ft_v1 ----------------------\n";
  // ft::vector<int> ft_v1(ft_v);
  // // ft_v.assign(5, 500);
  // // ft_v1.reserve(20);
  // ft_v1.insert(ft_v1.begin() + ft_v1.size() , ft_v.begin() + 2 , ft_v.end());
  // // std::vector<int>::const_iterator ft_itc(v1.begin());
  // // *ft_itc = *(v1.begin());
  // // ft::vector<int>::const_iterator ft_itc(ft_v1.begin());
  // // ft::vector<int>::const_iterator ft_itc1 = ft_v1.begin();
  // ft::vector<int>::iterator ft_it1(ft_v1.begin());
  //   std::cout << "ft_v1   : ";
  // for ( ; ft_it1 != ft_v1.end(); ft_it1++)
  //   std::cout << *ft_it1 << " ";
  // std::cout << std::endl;
  // std::cout << "capacity: " << ft_v1.capacity() << std::endl;
}