/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:52:50 by bnaji             #+#    #+#             */
/*   Updated: 2022/08/20 21:33:05 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <functional>
#include <map>
#include "../../map/map.hpp"
#include "../../bst/avl.hpp"
#include "limits.h"
#include <sys/time.h>

#include "../../algorithms/pair.hpp"
#include "../../algorithms/make_pair.hpp"
#include "../../bst/avl.hpp"
#include "PerformanceChecker.hpp"


template<typename map_type, typename pair_type>
void  fillMap(map_type & map, size_t size) {
  for (size_t i = 0; i < size; i++)
    map.insert(pair_type(i, i * size));
}

void  checkPerformace() {
  PerformanceChecker pcheck;


  pcheck.start();
  ft::map<int, int> ftmap;
  ftmap.clear();
  for (int i = 0; i < 1000; i++)
    ftmap.insert(ftmap.begin(), ftmap.end());
  ftmap.clear();
  for (int i = 0; i < 1000; i++)
    ftmap.insert(ft::make_pair<int, int>(i, i * 10));
  for (int i = 0; i < 1000 * 2; i++)
    ftmap.insert(ft::make_pair<int, int>(i, i * 10));
  ftmap.insert(ftmap.begin(), ftmap.end());
  ftmap.clear();
  
  pcheck.stop();
  pcheck.start();
  std::map<int, int> stdmap;
  stdmap.clear();
  for (int i = 0; i < 1000; i++)
    stdmap[i] = i * 10;
  stdmap.clear();
  for (int i = 0; i < 1000; i++)
    stdmap[i] = i * 10;
  for (int i = 0; i < 1000 * 2; i++)
    stdmap.insert(std::make_pair<int, int>(i, i * 10));
  stdmap.insert(stdmap.begin(), stdmap.end());
  stdmap.clear();
  pcheck.stopStandard();
  std::cout << pcheck << std::endl;
  pcheck.print();
}

bool  checkCapcity() {
  ft::map<int, int> ftmap;
  std::map<int, int> stdmap;
  // std::cout << std::endl << ftmap.max_size() << std::endl; 
  // std::cout << stdmap.max_size() << std::endl;
  if (ftmap.size() != stdmap.size() || ftmap.empty() != stdmap.empty() || ftmap.max_size() != stdmap.max_size())
    return false;

  for (int i = 0; i < 10; i++)
    ftmap.insert(ft::make_pair<int, int>(i, i * 10));
  for (int i = 0; i < 10; i++)
    stdmap.insert(std::make_pair<int, int>(i, i * 10));

  if (ftmap.size() != stdmap.size() || ftmap.empty() != stdmap.empty() || ftmap.max_size() != stdmap.max_size())
    return false;

  for (int i = 5; i < 10; i++)
    ftmap.erase(i);
  for (int i = 5; i < 10; i++)
    stdmap.erase(i);
  
  if (ftmap.size() != stdmap.size() || ftmap.empty() != stdmap.empty() || ftmap.max_size() != stdmap.max_size())
    return false;

  ftmap.clear();
  stdmap.clear();

  if (ftmap.size() != stdmap.size() || ftmap.empty() != stdmap.empty() || ftmap.max_size() != stdmap.max_size())
    return false;

  return true;
}

bool  checkIterators() {
  ft::map<int, int> ftmap;
  std::map<int, int> stdmap;
  
  for (int i = 0; i < 10; i++)
    ftmap.insert(ft::make_pair<int, int>(i, i * 10));
  for (int i = 0; i < 10; i++)
    stdmap.insert(std::make_pair<int, int>(i, i * 10));
  ft::map<int, int>::iterator ftit = ftmap.begin();
  std::map<int, int>::iterator stdit = stdmap.begin();
  
  for ( stdit = stdmap.begin(); stdit != stdmap.end(); stdit++, ftit++)
    if (ftit->first != stdit->first || ftit->second != stdit->second)
      return false;
  ftit--;
  stdit--;
  for ( ; ftit != ftmap.begin(); ftit--, stdit--)
    if (ftit->first != stdit->first || ftit->second != stdit->second)
      return false;
  if ((*ftit).first != (*stdit).first || (*ftit).second != (*stdit).second)
    return false;
  
  return true;
}
bool  checkConstIterators() {
  ft::map<int, int> ftmap;
  std::map<int, int> stdmap;
  
  for (int i = 0; i < 10; i++)
    ftmap.insert(ft::make_pair<int, int>(i, i * 10));
  for (int i = 0; i < 10; i++)
    stdmap.insert(std::make_pair<int, int>(i, i * 10));
  ft::map<int, int>::const_iterator ftit = ftmap.begin();
  std::map<int, int>::const_iterator stdit = stdmap.begin();
  
  for ( stdit = stdmap.begin(); stdit != stdmap.end(); stdit++, ftit++)
    if (ftit->first != stdit->first || ftit->second != stdit->second)
      return false;
  ftit--;
  stdit--;
  for ( ; ftit != ftmap.begin(); ftit--, stdit--)
    if (ftit->first != stdit->first || ftit->second != stdit->second)
      return false;
  if ((*ftit).first != (*stdit).first || (*ftit).second != (*stdit).second)
    return false;
  
  return true;
}

bool  checkReverseIterators() {
  ft::map<int, int> ftmap;
  std::map<int, int> stdmap;
  
  for (int i = 0; i < 10; i++)
    ftmap.insert(ft::make_pair<int, int>(i, i * 10));
  for (int i = 0; i < 10; i++)
    stdmap.insert(std::make_pair<int, int>(i, i * 10));
  ft::map<int, int>::reverse_iterator ftit = ftmap.rbegin();
  std::map<int, int>::reverse_iterator stdit = stdmap.rbegin();
  
  for ( stdit = stdmap.rbegin(); stdit != stdmap.rend(); stdit++, ftit++)
    if (ftit->first != stdit->first || ftit->second != stdit->second)
      return false;
  ftit--;
  stdit--;
  for ( ; ftit != ftmap.rbegin(); ftit--, stdit--)
    if (ftit->first != stdit->first || ftit->second != stdit->second)
      return false;
  if ((*ftit).first != (*stdit).first || (*ftit).second != (*stdit).second)
    return false;
  
  return true;
}

bool  checkConstReverseIterators() {
  ft::map<int, int> ftmap;
  std::map<int, int> stdmap;
  
  for (int i = 0; i < 10; i++)
    ftmap.insert(ft::make_pair<int, int>(i, i * 10));
  for (int i = 0; i < 10; i++)
    stdmap.insert(std::make_pair<int, int>(i, i * 10));
  ft::map<int, int>::const_reverse_iterator ftit = ftmap.rbegin();
  std::map<int, int>::const_reverse_iterator stdit = stdmap.rbegin();
  
  for ( stdit = stdmap.rbegin(); stdit != stdmap.rend(); stdit++, ftit++)
    if (ftit->first != stdit->first || ftit->second != stdit->second)
      return false;
  ftit--;
  stdit--;
  for ( ; ftit != ftmap.rbegin(); ftit--, stdit--)
    if (ftit->first != stdit->first || ftit->second != stdit->second)
      return false;
  if ((*ftit).first != (*stdit).first || (*ftit).second != (*stdit).second)
    return false;
  
  return true;
}

bool  checkMixedIterators() {
  ft::map<int, int> ftmap;
  std::map<int, int> stdmap;
  
  for (int i = 0; i < 10; i++)
    ftmap.insert(ft::make_pair<int, int>(i, i * 10));
  for (int i = 0; i < 10; i++)
    stdmap.insert(std::make_pair<int, int>(i, i * 10));
  ft::map<int, int>::iterator ftit1 = ftmap.begin();
  std::map<int, int>::iterator stdit1 = stdmap.begin();
  ft::map<int, int>::const_iterator ftit2 = ftmap.begin();
  std::map<int, int>::const_iterator stdit2 = stdmap.begin();
  ft::map<int, int>::reverse_iterator ftit3 = ftmap.rbegin();
  std::map<int, int>::reverse_iterator stdit3 = stdmap.rbegin();
  ft::map<int, int>::const_reverse_iterator ftit4 = ftmap.rbegin();
  std::map<int, int>::const_reverse_iterator stdit4 = stdmap.rbegin();
  
  if (ftit1 == ftit2 || ftit1 != ftit2
    || ftit3 == ftit4 || ftit3 != ftit4
    || stdit1 == stdit2 || stdit1 != stdit2
    || stdit3 == stdit4 || stdit3 != stdit4
  ){}
    
  
  return true;
}

bool  checkObservers() {
  ft::map<int, int> ftmap;
  ft::map<int, int>::key_compare ftcomp = ftmap.key_comp();
  std::map<int, int> stdmap;
  std::map<int, int>::key_compare stdcomp = stdmap.key_comp();
  
  for (int i = 0; i < 10; i++)
    ftmap.insert(ft::make_pair<int, int>(i, i * 10));
  for (int i = 0; i < 10; i++)
    stdmap.insert(std::make_pair<int, int>(i, i * 10));
  if (ftcomp(ftmap.begin()->first, ftmap.rbegin()->first) != stdcomp(stdmap.begin()->first, stdmap.rbegin()->first)
    || ftcomp(ftmap.begin()->second, ftmap.rbegin()->second) != stdcomp(stdmap.begin()->second, stdmap.rbegin()->second))
    return false;
  return true;
}

bool  checkElementAccess() {
  ft::map<int, int> ftmap ;
  std::map<int, int> stdmap;
  ft::map<int, int>::iterator ftit;
  std::map<int, int>::iterator stdit;
  ft::map<int, int>::const_iterator cftit;
  std::map<int, int>::const_iterator cstdit;
  fillMap< ft::map<int, int>, ft::pair<int, int> >(ftmap, 10);
  fillMap< std::map<int, int>, std::pair<int, int> >(stdmap, 10);
  ft::map<int, int> const cftmap(ftmap);
  std::map<int, int> const cstdmap(stdmap);

  if (ftmap.size() != stdmap.size())
    return false;

  for (ftit = ftmap.begin(), stdit = stdmap.begin(); ftit != ftmap.end(); ftit++, stdit++)
    if (ftmap[ftit->first] != stdmap[stdit->first])
      return false;
  
  for (ftit = ftmap.begin(), stdit = stdmap.begin(); ftit != ftmap.end(); ftit++, stdit++)
    if (ftmap.at(ftit->first) != stdmap.at(stdit->first))
      return false;

  for (cftit = cftmap.begin(), cstdit = cstdmap.begin(); cftit != cftmap.end(); cftit++, cstdit++)
    if (ftmap.at(0) != stdmap.at(0))
      return false;

  return true;
}

bool  checkModifiers() {
  ft::map<int, int> ftmap1;
  std::map<int, int> stdmap1;
  ft::map<int, int> ftmap2;
  std::map<int, int> stdmap2;
  ft::map<int, int> ftmap3;
  std::map<int, int> stdmap3;
  ft::map<int, int>::iterator ftit;
  std::map<int, int>::iterator stdit;
  size_t size = 10;

  for (size_t i = 0; i < size; i++)
    ftmap1.insert(ft::pair<int, int>(i, i * size));
  for (size_t i = 0; i < size; i++)
    stdmap1.insert(std::pair<int, int>(i, i * size));
  for (size_t i = 0; i < size; i++)
    ftmap2.insert(ftmap2.begin(), ft::pair<int, int>(i, i * size));
  for (size_t i = 0; i < size; i++)
    stdmap2.insert(stdmap2.begin(), std::pair<int, int>(i, i * size));
  for (size_t i = 0; i < size; i++)
    ftmap3.insert(ftmap2.begin(), ftmap2.end());
  for (size_t i = 0; i < size; i++)
    stdmap3.insert(stdmap2.begin(), stdmap2.end());
  
  for (ftit = ftmap1.begin(), stdit = stdmap1.begin(); ftit != ftmap1.end(); ftit++, stdit++)
    if (ftmap1[ftit->first] != stdmap1[stdit->first])
      return false;
  for (ftit = ftmap2.begin(), stdit = stdmap2.begin(); ftit != ftmap2.end(); ftit++, stdit++)
    if (ftmap2[ftit->first] != stdmap2[stdit->first])
      return false;
  for (ftit = ftmap3.begin(), stdit = stdmap3.begin(); ftit != ftmap3.end(); ftit++, stdit++)
    if (ftmap3[ftit->first] != stdmap3[stdit->first])
      return false;

  ftmap1.erase(ftmap1.begin());
  ftmap1.erase(ftmap1.begin());
  stdmap1.erase(stdmap1.begin());
  stdmap1.erase(stdmap1.begin());

  ftmap2.erase(ftmap2.begin()->first);
  ftmap2.erase(ftmap2.begin()->first);
  stdmap2.erase(stdmap2.begin()->first);
  stdmap2.erase(stdmap2.begin()->first);

  ftit = ftmap3.begin();
  stdit = stdmap3.begin();
  ftit++;
  ftit++;
  stdit++;
  stdit++;
  // ftmap3.erase(ftit, ftmap3.end());
  // stdmap3.erase(stdit, stdmap3.end());
  
  for (ftit = ftmap1.begin(), stdit = stdmap1.begin(); ftit != ftmap1.end(); ftit++, stdit++)
    if (ftmap1[ftit->first] != stdmap1[stdit->first])
      return false;
  for (ftit = ftmap2.begin(), stdit = stdmap2.begin(); ftit != ftmap2.end(); ftit++, stdit++)
    if (ftmap2[ftit->first] != stdmap2[stdit->first])
      return false;
  // for (ftit = ftmap3.begin(), stdit = stdmap3.begin(); ftit != ftmap3.end(); ftit++, stdit++)
  //   if (ftmap3[ftit->first] != stdmap3[stdit->first])
  //     return false;
  return true;
}

int main() {
  checkPerformace();

  std::cout << PURPLE << "checkCapacity:" << RESET;
  checkCapcity() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;

  std::cout << PURPLE << "checkIterators:" << RESET;
  checkIterators() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;

  std::cout << PURPLE << "checkConstIterators:" << RESET;
  checkConstIterators() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;

  std::cout << PURPLE << "checkReverseIterators:" << RESET;
  checkReverseIterators() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;

  std::cout << PURPLE << "checkConstReverseIterators:" << RESET;
  checkConstReverseIterators() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;

  std::cout << PURPLE << "checkMixedIterators:" << RESET;
  checkConstIterators() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;

  std::cout << PURPLE << "checkObservers:" << RESET;
  checkObservers() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;

  std::cout << PURPLE << "checkElementAccess:" << RESET;
  checkElementAccess() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;

  std::cout << PURPLE << "checkModifiers:" << RESET;
  checkModifiers() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;
  // std::cout << "deleteeeee: \n";
  // std::cout << PURPLE << "checkElementAccess:" << RESET;
  // checkConstIterators() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;
  // if (checkElementAccess())
  //   std::cout << GREEN <<" OK" << RESET << std::endl;
  // else
  //   std::cout << RED <<" KO" << RESET << std::endl;

}
