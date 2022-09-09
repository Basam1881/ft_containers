/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:52:50 by bnaji             #+#    #+#             */
/*   Updated: 2022/09/09 12:16:54 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <vector>
#include "../../map/map.hpp"
#include "../../vector/vector.hpp"
#include "../../bst/avl.hpp"
#include "limits.h"
#include <sys/time.h>

#include "../../algorithms/pair.hpp"
#include "../../algorithms/pair.hpp"
#include "../../bst/avl.hpp"
#include "../PerformanceChecker.hpp"


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
  
  for (int i = 0; i < 10; i++)
    ftmap.insert(ft::pair<int, int>(i, i * 10));
  ftmap.clear();
  for (int i = 0; i < 1000; i++)
    ftmap.insert(ft::pair<int, int>(i, i * 10));
  for (int i = 0; i < 1000 * 2; i++)
    ftmap.insert(ft::pair<int, int>(i, i * 10));
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
    stdmap.insert(std::pair<int, int>(i, i * 10));
  stdmap.insert(stdmap.begin(), stdmap.end());
  stdmap.clear();
  pcheck.stopStandard();
  std::cout << pcheck;
}

bool  checkCapcity() {
  ft::map<int, int> ftmap;
  std::map<int, int> stdmap;

  if (ftmap.size() != stdmap.size() || ftmap.empty() != stdmap.empty() || ftmap.max_size() != stdmap.max_size())
    return false;

  for (int i = 0; i < 10; i++)
    ftmap.insert(ft::pair<int, int>(i, i * 10));
  for (int i = 0; i < 10; i++)
    stdmap.insert(std::pair<int, int>(i, i * 10));

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
    ftmap.insert(ft::pair<int, int>(i, i * 10));
  for (int i = 0; i < 10; i++)
    stdmap.insert(std::pair<int, int>(i, i * 10));

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
    ftmap.insert(ft::pair<int, int>(i, i * 10));
  for (int i = 0; i < 10; i++)
    stdmap.insert(std::pair<int, int>(i, i * 10));
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
    ftmap.insert(ft::pair<int, int>(i, i * 10));
  for (int i = 0; i < 10; i++)
    stdmap.insert(std::pair<int, int>(i, i * 10));
  ft::map<int, int>::reverse_iterator ftit = ftmap.rbegin();
  std::map<int, int>::reverse_iterator stdit = stdmap.rbegin();


  for ( stdit = stdmap.rbegin(); stdit != stdmap.rend(); stdit++, ftit++) {
      if (ftit->first != stdit->first || ftit->second != stdit->second)
        return false;
  }
  ftit--;
  stdit--;
  for ( ; ftit != ftmap.rbegin(); ftit--, stdit--) {
    if (ftit->first != stdit->first || ftit->second != stdit->second)
      return false;
  }
  if ((*ftit).first != (*stdit).first || (*ftit).second != (*stdit).second)
    return false;
  
  return true;
}

bool  checkConstReverseIterators() {
  ft::map<int, int> ftmap;
  std::map<int, int> stdmap;
  
  for (int i = 0; i < 10; i++)
    ftmap.insert(ft::pair<int, int>(i, i * 10));
  for (int i = 0; i < 10; i++)
    stdmap.insert(std::pair<int, int>(i, i * 10));
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
    ftmap.insert(ft::pair<int, int>(i, i * 10));
  for (int i = 0; i < 10; i++)
    stdmap.insert(std::pair<int, int>(i, i * 10));
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
    ftmap.insert(ft::pair<int, int>(i, i * 10));
  for (int i = 0; i < 10; i++)
    stdmap.insert(std::pair<int, int>(i, i * 10));
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

  fillMap< ft::map<int, int>, ft::pair<int, int> >(ftmap1, size);
  fillMap< std::map<int, int>, std::pair<int, int> >(stdmap1, size);
  fillMap< ft::map<int, int>, ft::pair<int, int> >(ftmap2, size);
  fillMap< std::map<int, int>, std::pair<int, int> >(stdmap2, size);
  fillMap< ft::map<int, int>, ft::pair<int, int> >(ftmap3, size);
  fillMap< std::map<int, int>, std::pair<int, int> >(stdmap3, size);

  for (ftit = ftmap1.begin(), stdit = stdmap1.begin(); ftit != ftmap1.end(); ftit++, stdit++)
    if (ftmap1[ftit->first] != stdmap1[stdit->first])
      return false;
  for (ftit = ftmap2.begin(), stdit = stdmap2.begin(); ftit != ftmap2.end(); ftit++, stdit++)
    if (ftmap2[ftit->first] != stdmap2[stdit->first])
      return false;
  for (ftit = ftmap3.begin(), stdit = stdmap3.begin(); ftit != ftmap3.end(); ftit++, stdit++)
    if (ftmap3[ftit->first] != stdmap3[stdit->first])
      return false;

  // for (ftit = ftmap1.begin(); ftit != ftmap1.end(); ftit++)
  //   std::cout << ftit->first << " ";
  // std::cout << std::endl;
  // std::cout << "-------------------------\n";
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
  ftmap3.erase(ftit, ftmap3.end());
  stdmap3.erase(stdit, stdmap3.end());
  ftmap3.clear();
  stdmap3.clear();
  
  for (ftit = ftmap1.begin(), stdit = stdmap1.begin(); ftit != ftmap1.end(); ftit++, stdit++) {
    if (ftmap1[ftit->first] != stdmap1[stdit->first])
      return false;
  }
  for (ftit = ftmap2.begin(), stdit = stdmap2.begin(); ftit != ftmap2.end(); ftit++, stdit++)
    if (ftmap2[ftit->first] != stdmap2[stdit->first])
      return false;
  for (ftit = ftmap3.begin(), stdit = stdmap3.begin(); ftit != ftmap3.end(); ftit++, stdit++)
    if (ftmap3[ftit->first] != stdmap3[stdit->first])
      return false;
  return true;
}

bool  checkOperations() {
  ft::map<int, int> ftmap;
  std::map<int, int> stdmap;
  ft::map<int, int> ftmap1;
  std::map<int, int> stdmap1;
  size_t size = 20;
  ft::map<int, int>::iterator ftit;
  std::map<int, int>::iterator stdit;
  ft::map<int, int>::const_iterator cftit;
  std::map<int, int>::const_iterator cstdit;

  for (int i = 0; i < 10; i++)
    ftmap.insert(ft::pair<int, int>(i * size / 10, i * size));
  for (int i = 0; i < 10; i++)
    stdmap.insert(std::pair<int, int>(i * size / 10, i * size));

  // find()
  for (ftit = ftmap.begin(), stdit = stdmap.begin(); ftit != ftmap.end(); ftit++, stdit++)
    if (ftmap.find(ftit->first)->first != stdmap.find(stdit->first)->first)
      return false;
  for (cftit = ftmap.begin(), cstdit = stdmap.begin(); cftit != ftmap.end(); cftit++, cstdit++)
    if (ftmap.find(cftit->first)->first != stdmap.find(cstdit->first)->first)
      return false;
  if (ftmap.find(size * 10) != ftmap.end() || ftmap1.find(size * 10) != ftmap1.end())
    return false;
  
  // count()
  for (ftit = ftmap.begin(), stdit = stdmap.begin(); ftit != ftmap.end(); ftit++, stdit++)
    if (ftmap.count(ftit->first) != stdmap.count(stdit->first))
      return false;
  if (ftmap.count(size * 10) != stdmap.count(size * 10))
    return false;
  
  // lower_bound()
  for (size_t i = 0; i < 10; i++)
    if (ftmap.lower_bound(i)->first != stdmap.lower_bound(i)->first)
      return false;
  if (ftmap.lower_bound(size * 10) != ftmap.end())
    return false;

  // upper_bound()
  for (size_t i = 0; i < 10; i++)
    if (ftmap.upper_bound(i)->first != stdmap.upper_bound(i)->first)
      return false;
  if (ftmap.upper_bound(size * 10) != ftmap.end())
    return false;

  // equal_range()
  for (size_t i = 0; i < 10; i++)
    if (ftmap.equal_range(i).first->first != stdmap.equal_range(i).first->first)
      return false;

  return true;
}

bool  checkExceptions() {
  std::map<int, int> stdmap;
  ft::map<int, int> ftmap;
  fillMap< ft::map<int, int>, ft::pair<int, int> >(ftmap, 10);
  fillMap< std::map<int, int>, std::pair<int, int> >(stdmap, 10);
  try {
    stdmap.at(20);
  } catch (std::out_of_range & e) {
    try {
      ftmap.at(20);
    } catch (std::out_of_range & e) {
      return true;
    }
  }
  return false;
}

bool checkNestedMapVector() {
  // FT
  ft::map<int, int> mp1;
  mp1.insert(ft::pair<int, int>(1, 10));
  ft::vector<std::string> v1(1, "V1");
  ft::vector<ft::map<int, int> > v2(1, mp1);
  ft::map<std::string, std::string> mp2;
  mp2.insert(ft::pair<std::string, std::string>("1", "10"));
  ft::map<ft::vector<std::string>, ft::vector<ft::map<int, int> > > mp3;
  mp3.insert(ft::pair<ft::vector<std::string>, ft::vector<ft::map<int, int> > >(v1, v2));

  ft::map<ft::map<std::string, std::string>, ft::map<ft::vector<std::string>, ft::vector<ft::map<int, int> > > > mp;
  mp.insert(ft::pair<ft::map<std::string, std::string>, ft::map<ft::vector<std::string>, ft::vector<ft::map<int, int> > > >(mp2, mp3));

  // STD
  std::map<int, int> smp1;
  smp1.insert(std::pair<int, int>(1, 10));
  std::vector<std::string> sv1(1, "V1");
  std::vector<std::map<int, int> > sv2(1, smp1);
  std::map<std::string, std::string> smp2;
  smp2.insert(std::pair<std::string, std::string>("1", "10"));
  std::map<std::vector<std::string>, std::vector<std::map<int, int> > > smp3;
  smp3.insert(std::pair<std::vector<std::string>, std::vector<std::map<int, int> > >(sv1, sv2));

  std::map<std::map<std::string, std::string>, std::map<std::vector<std::string>, std::vector<std::map<int, int> > > > smp;
  smp.insert(std::pair<std::map<std::string, std::string>, std::map<std::vector<std::string>, std::vector<std::map<int, int> > > >(smp2, smp3));

  if (mp[mp2][v1][0][1] != smp[smp2][sv1][0][1] || mp[mp2].find(v1)->first[0] != smp[smp2].find(sv1)->first[0])
    return false;

  return true;
}

int main() {
  std::cout << PURPLE << "checkPerformace:" << RESET << std::endl;
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

  std::cout << PURPLE << "checkOperations:" << RESET;
  checkOperations() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;

  std::cout << PURPLE << "checkExceptions:" << RESET;
  checkExceptions() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;

  std::cout << PURPLE << "checkNestedMapVector:" << RESET;
  checkNestedMapVector() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;
}
