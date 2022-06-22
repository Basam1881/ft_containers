/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vTCmp.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:39:23 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/22 16:58:41 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "vector.hpp"
#include "vectorTests.hpp"

template<typename T>
bool cmpVecs(std::vector<T> & v, ft::vector<T> & ft_v) {
  typename std::vector<T>::iterator it1 = v.begin();
  typename ft::vector<T>::iterator it2 = ft_v.begin();
  for ( ; it1 != v.end() && it2 != ft_v.end(); it1++, it2++)
    if (*it1 != *it2)
      return false;
  return true;
}

template<typename T>
bool  cmpVecsSize(std::vector<T> & v, ft::vector<T> & ft_v) {
  return (v.size() == ft_v.size());
}

template<typename T>
bool  cmpVecsCap(std::vector<T> & v, ft::vector<T> & ft_v) {
  return (v.capacity() == ft_v.capacity());
}

template<typename T, typename vec>
void  cmpPerformanceHelper(size_t testnum, T value) {
  size_t n = 1000;
  size_t m = 2000;
  if (testnum <= 2)
    vec v[n];
  else if (testnum <= 4)
    vec v(n);
  else if (testnum <= 6)
    vec v(n, value);
  else if (testnum <= 8) {
    vec v1(n, value);
    vec v(v1.begin(), v1.end());
  }
  else if (testnum <= 10) {
    vec v1(n, value);
    vec v(v1);
  }
  else if (testnum <= 11) {
    vec v1[n];
    vec v[n];
    for (size_t i = 0; i < n; i++) v[i] = v1[i];
  }
  else if (testnum <= 15) {
    vec v2(m, value);
    vec v1(n, value);
    vec v;
    if (testnum == 12)
      v = v1;
    else if (testnum == 13)
      v1 = v;
    else if (testnum == 14)
      v1 = v2;
    else if (testnum == 15)
      v2 = v1;
  }
  else
    vec v1(n, value);
}

template<typename T>
bool  cmpBasicPerformance(size_t testnum, bool printAllTests, T value) {
  struct timeval begin, end;
  gettimeofday(&begin, 0);
  cmpPerformanceHelper<T, std::vector<T> >(testnum, value);
  gettimeofday(&end, 0);
  long seconds = end.tv_sec - begin.tv_sec;
  long microseconds = end.tv_usec - begin.tv_usec;
  double elapsed = seconds + microseconds*1e-6;
  
  struct timeval begin1, end1;
  gettimeofday(&begin1, 0);
  cmpPerformanceHelper<T, ft::vector<T> >(testnum, value);
  gettimeofday(&end1, 0);
  long seconds1 = end1.tv_sec - begin1.tv_sec;
  long microseconds1 = end1.tv_usec - begin1.tv_usec;
  double elapsed1 = seconds1 + microseconds1*1e-6;
  if (printAllTests) {
    std::cout << PURPLE << "Time measured : " << std::setprecision(5) << std::fixed << YELLOW << elapsed * 1e+6 << WHITE << " Ms" << RESET << std::endl;
    std::cout << PURPLE << "Time measured : " << std::setprecision(5) << std::fixed << YELLOW << elapsed1 * 1e+6 << WHITE << " Ms" << RESET << std::endl;
    std::cout << PURPLE << "Faster by     : " << std::setprecision(5) << std::fixed << YELLOW << elapsed / elapsed1 << WHITE << " (ft_v/v)" << RESET<< std::endl;
    std::cout << PURPLE << "Slower by     : " << std::setprecision(5) << std::fixed << YELLOW << elapsed1 / elapsed << WHITE << " (v/ft_v)" << RESET<< std::endl;
  }
  return (elapsed1 / elapsed < 20);
}

template<typename T>
bool  cmpAll(std::vector<T> & v, ft::vector<T> & ft_v) {
    return (cmpVecs<T>(v, ft_v) && cmpVecsSize<T>(v, ft_v) && cmpVecsCap<T>(v, ft_v));
}
