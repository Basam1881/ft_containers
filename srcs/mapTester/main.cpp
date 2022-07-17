/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:52:50 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/17 19:19:42 by bnaji            ###   ########.fr       */
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


int main() {
  std::map<std::string, std::string> mmap;

  // ft::pair<std::string, std::string> p = ft::make_pair<std::string, std::string>("hello", "world");
  ft::AVL<std::string, std::string> myavl, * root = NULL;
  root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi3", "three"));
  root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi4", "four"));
  root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi5", "five"));
  root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi6", "six"));
  root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi7", "seven"));

  root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi8", "eight"));
  root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi2", "two"));

  // root = myavl.erase(root, "hi7");
  // root = myavl.erase(root, "hi3");
  // std::cout << "Hello\n";
  typedef ft::iterator<ft::bidirectional_iterator_tag, ft::AVL<std::string, std::string>	> iterator;
  // typedef ft::reverse_iterator<iterator> reverse_iterator;
  iterator myit(root->getLowestKey(root));
  // myit;
  // myit = reverse_iterator(root->getHighestKey(root));
  // if (root->getEnd() && root->getEnd() == root->getHighestKey(root)->getEnd())
  //   std::cout << "fuck yeah\n";
  for ( ; iterator(root->getEnd()) != myit; myit++)
    std::cout << "<--- " << myit->first << " --->" << std::endl;
  std::cout << "<--- " << myit->first << "-" << myit->second << " --->" << std::endl;
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
  ft::map<int, int> ftmap;
  // ft::pair<int, int> p = ft::make_pair<int, int>(1, 10);
  ftmap.insert(ft::make_pair<int, int>(1, 10));
  ftmap.insert(ft::make_pair<int, int>(1, 20));
  
  // ftmap.insert(ft::make_pair<int, int>(3, 30));
  // ftmap.insert(ft::make_pair<int, int>(4, 40));
  ft::map<int, int> ftmap1(ftmap);
  ft::map<int, int>::iterator tt;
  tt = ftmap1.begin();
  for ( ; tt != ftmap1.end(); tt++) {
    std:: cout << tt->first << " " << tt->second << std::endl;
  }
  std::cout << ftmap1.at(1) << std::endl;
  // if (tt != ftmap.end())
  // if (tt != ftmap.end())
  //   tt++;
  // std:: cout << tt->first << " " << tt->second << std::endl;
  // if (tt != ftmap.end())
  //   tt++;
  // if (tt != ftmap.end())
  // std:: cout << tt->first << " " << tt->second << std::endl;

  // std::cout << root->getpair().second << std::endl;
  ft::pair<int, int> p1(ft::make_pair(4, 40));
  // std:: cout << p1.first << " " << p1.second << std::endl;
  mmap["hi7"] = "seven";
  mmap.insert(std::pair<std::string, std::string>("hi5", "five"));
  mmap.insert(std::pair<std::string, std::string>("hi6", "two")); 
  mmap.insert(std::pair<std::string, std::string>("hi4", "four"));
  mmap.insert(std::pair<std::string, std::string>("hi3", "three"));
  mmap.insert(std::pair<std::string, std::string>("hi8", "eight"));
  // mmap.erase("hi4");
  // mmap.erase("hi4");
  // it--;
  // it--;
  // it--;
  // it--;
  // std::cout << "|" << it->first << " " << it->second << "| ";
  // std::cout << "|" << it->first << " " << it->second << "| ";
  // it--;
  // std::cout << "|" << it->first << " " << it->second << "| ";
  // it--;
  // std::cout << "|" << it->first << " " << it->second << "| ";
  // it--;
  // std::cout << "|" << it->first << " " << it->second << "| ";
  // it--;
  // std::cout << "|" << it->first << " " << it->second << "| ";
  std::map<std::string, std::string> mmap1(mmap.begin(), mmap.end());
  std::map<std::string, std::string>::iterator it = mmap1.begin();
  std::cout << "|" << it->first << " " << it->second << "| " << std::endl;
  for (it = mmap1.begin(); it != mmap1.end(); it++ ) {
    std::cout << "|" << it->first << " " << it->second << "| ";
  }
  std::cout << std::endl;
  std::cout << "|" << it->first << " " << it->second << "| " << std::endl;
  // std::cout << "|" << it->first << " " << it->second << "| ";
  // it++;
  // it++;
  // it++;
  // it++;
  // it++;
  // it--;
  // it++;
  // std::cout << "|" << it->first << " " << it->second << "| ";
  // it++;
  // std::cout << "|" << it->first << " " << it->second << "| ";
  // std::cout << std::endl;
  // *it;
    // it++;
    // std::cout << "|" << it->first << " " << it->second << "| ";
}
