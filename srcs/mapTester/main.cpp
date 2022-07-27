/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:52:50 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/27 11:59:31 by bnaji            ###   ########.fr       */
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


int main() {
  PerformanceChecker pcheck;


  pcheck.start();
  ft::map<int, int> ftmapp;
  for (int i = 0; i < 100000; i++) {
    // std::cout << "insert" << i << std::endl;
    ftmapp.insert(ft::make_pair<int, int>(i, i * 10));
    // std::cout << "insertX" << std::endl;
  }
  ftmapp.clear();
  pcheck.stop();
  pcheck.start();
  std::map<int, int> stdmapp;
  for (int i = 0; i < 100000; i++) {
    
    stdmapp.insert(std::make_pair<int, int>(i, i * 10));
  }
  stdmapp.clear();
  pcheck.stopStandard();
  std::cout << pcheck << std::endl;
  pcheck.print();
  
  // for (ft::map<int, int>::iterator ftit = ftmapp.begin(); ftit != ftmapp.end(); ftit++) {
  //   std:: cout << ftit->first << " " << ftit->second << std::endl;
  // }
  //   std:: cout << "size: " << ftmapp.size() << std::endl;
  // for (ft::map<int, int>::iterator ftit = ftmapp.begin(); ftit != ftmapp.end(); ftit++) {
  //   std:: cout << ftit->first << " " << ftit->second << std::endl;
  // }
  
  // for (int i = 0; i < 2; i++) {
  //   ftmapp.erase(i);
  // }
  
  
  // for (ft::map<int, int>::iterator ftit = ftmapp.begin(); ftit != ftmapp.end(); ftit++) {
  //   std:: cout << ftit->first << " " << ftit->second << std::endl;
  // }
    // std:: cout << "size: " << ftmapp.size() << std::endl;
  // ft::pair<std::string, std::string> p = ft::make_pair<std::string, std::string>("hello", "world");
  // ft::AVL<std::string, std::string> myavl, * root = NULL;
  // root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi3", "three"));
  // root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi4", "four"));
  // root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi5", "five"));
  // root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi6", "six"));
  // root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi7", "seven"));

  // root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi8", "eight"));
  // root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi2", "two"));

  // root = myavl.erase(root, "hi7");
  // root->printAll(root);
  // root = myavl.erase(root, "hi3");
  // root->printAll(root);
  // std::cout << "Hello\n";
  // typedef ft::iterator<ft::bidirectional_iterator_tag, ft::AVL<std::string, std::string>	> iterator;
  // iterator myit(root->getLowestKey(root));
  // std::cout << "decrement1" << std::endl;
  // iterator myit(root->getLowestKey(root));
  // iterator myit(root->getHighestKey(root));
  // typedef ft::reverse_iterator<iterator> reverse_iterator;
  // reverse_iterator myit(root->getLowestKey(root));
  // for ( ; myit != reverse_iterator(root->getLowEnd()); myit++) {
  // for ( ; myit != iterator(root->getLowEnd()); myit--) {
    // if (myit != iterator(root->getEnd()))
    // std::cout << "<--- " << myit->first << " - " << myit->second << " --->" << std::endl;
      // std::cout << "<--- " << myit.getLowEnd() << " - " << root->getLowestKey(root->getMasterRoot()) << " --->" << std::endl;

    // myit++;  
    // myit--;
    // std::cout << "decrement2" << std::endl;
  // }
  // std::cout << "<--- " << myit->first << "-" << myit->second << " --->" << std::endl;
  // myit++;
  // myit++;
  // std::cout << "<--- " << (*myit).first << " --->" << std::endl << std::endl;
  // root->printAll(root);
  // root->getEnd() = root->getEnd();
  // myit += 1;
  // for ( myit = iterator(root->getHighestKey(root)); myit != iterator(root->getLowestKey(root)); myit--)
  //   std::cout << "<--- " << (*myit).first << " --->" << std::endl;
  // std::cout << "<--- " << (*myit).first << " --->" << std::endl << std::endl;

  // myit++;            
  // root = myavl.erase(root, "hi8");
  // root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi9", "nine"));
  // myavl.erase(root, "hi4");
  // root = myavl.erase(root, "hi7");
  // root = myavl.erase(root, "hi");

  // ft::map<std::string, std::string> ftmap(iterator(root->getLowestKey(root)), iterator(root->getHighestKey(root)));
  // ft::map<int, int> ftmap;
  // ft::pair<int, int> p = ft::make_pair<int, int>(1, 10);
  
  // ftmap.insert(ft::make_pair<int, int>(1, 10));
  // ftmap.insert(ft::make_pair<int, int>(1, 10));
  // ftmap.insert(ft::make_pair<int, int>(2, 20));
  // ftmap.insert(ft::make_pair<int, int>(3, 30));
  // ftmap.insert(ft::make_pair<int, int>(4, 40));
  // ft::map<int, int>::iterator myfit = ftmap.find(2);
  // myfit = ftmap.find(4);
  // ft::map<int, int>::reverse_iterator tt = ftmap.rbegin();
  // std:: cout << "size: " << ftmap.size() << std::endl;
  // ft::pair<int, int> ptt = ft::make_pair<int, int>(333, 333);
  
  // for (; tt != ftmap.rend(); tt++) {
  //   std:: cout << tt->first << " " << tt->second << std::endl;
  // }
  
  // ftmap.erase(myfit);
  // ftmap.erase(ftmap.begin(), ftmap.end());
  // ftmap.clear();
  // myfit = ftmap.find(1);
  // ftmap.erase(4);
  // ftit++;
  // ftit1++;
  // ftmap[0];  

  // ft::map<int, int> ftmap1(ftmap);
  // tt = ftmap1.begin();
  // ft::map<int, int> ftmap1;
  // ftmap1.insert(ft::make_pair<int, int>(5, 50));
  // ftmap1.insert(ft::make_pair<int, int>(6, 60));
  // ftmap1.swap(ftmap);
  // ft::map<int, int>::iterator t1 = ftmap.find(1);
  // ft::map<int, int>::key_compare com = ftmap.key_comp();
  // std:: cout << "size: " << ftmap1.size() << std::endl;
  // for (tt = ftmap1.rbegin(); tt != ftmap1.rend(); tt++) {
  //   std:: cout << tt->first << " " << tt->second << std::endl;
  // }
  // std::map<int, int> mmap2;
  // std::cout << mmap2.max_size() << std::endl;
  // std::map<std::string, std::string> mmap;
  // std::map<std::string, std::string>::iterator itt = mmap.begin();
  // for ( ; itt != mmap.end(); itt++)
  //   std::cout << "hello\n";
  // std::cout << mmap.max_size() << std::endl;
  // ft::pair<int, int> p1(ft::make_pair(4, 40));
  // std:: cout << p1.first << " " << p1.second << std::endl;
  // mmap["hi7"] = "seven";
  // std::cout << mmap.max_size() << std::endl;
  // mmap.insert(std::pair<std::string, std::string>("hi5", "five"));
  // mmap.insert(std::pair<std::string, std::string>("hi6", "six")); 
  // mmap.insert(std::pair<std::string, std::string>("hi4", "four"));
  // mmap.insert(std::pair<std::string, std::string>("hi3", "three"));
  // mmap.insert(std::pair<std::string, std::string>("hi8", "eight"));
  // std::map<std::string, std::string> mmap1(mmap.begin(), mmap.end());
  // std::map<std::string, std::string>::iterator it = mmap1.begin();
  // std::pair< std::string, std::string> pmap = std::make_pair<std::string, std::string>("WHAT", "THE FUCK");
  // *it = pmap;
  // std::cout << mmap.lower_bound("hi4")->second << std::endl;
  // std::cout << "|" << it->first << " " << it->second << "| " << std::endl;
  // for (it = mmap1.begin(); it != mmap1.end(); it++ ) {
  //   std::cout << "|" << it->first << " " << it->second << "| ";
  // }
  // std::cout << std::endl;

}
