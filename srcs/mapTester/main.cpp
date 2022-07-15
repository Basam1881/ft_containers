/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:52:50 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/15 19:27:49 by bnaji            ###   ########.fr       */
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

  typedef ft::iterator<ft::bidirectional_iterator_tag, ft::AVL<std::string, std::string>	> iterator;
  iterator myit;

  myit = iterator(root->getLowestKey(root));
  for ( ; iterator(root->getHeighestKey(root)) != myit; myit++)
    std::cout << "<--- " << (*myit).first << " --->" << std::endl;
  std::cout << "<--- " << (*myit).first << " --->" << std::endl << std::endl;
  for ( myit = iterator(root->getHeighestKey(root)); myit != iterator(root->getLowestKey(root)); myit--)
    std::cout << "<--- " << (*myit).first << " --->" << std::endl;
  std::cout << "<--- " << (*myit).first << " --->" << std::endl << std::endl;

  // myit++;
  // root = myavl.erase(root, "hi8");
  // root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi9", "nine"));
  // root = myavl.erase(root, "hi3");
  // myavl.erase(root, "hi7");
  // myavl.erase(root, "hi4");
  // root = myavl.erase(root, "hi7");
  // root = myavl.erase(root, "hi");
  root->printAll(root);

  // std::cout << root->getpair().second << std::endl;
  ft::pair<int, int> p1(ft::make_pair(4, 40));
  std:: cout << p1.first << " " << p1.second << std::endl;
  mmap["hi7"] = "seven";
  mmap.insert(std::pair<std::string, std::string>("hi5", "five"));
  mmap.insert(std::pair<std::string, std::string>("hi6", "two"));
  mmap.insert(std::pair<std::string, std::string>("hi4", "four"));
  mmap.insert(std::pair<std::string, std::string>("hi3", "three"));
  mmap.insert(std::pair<std::string, std::string>("hi8", "eight"));
  // mmap.erase("hi4");
  // mmap.erase("hi4");
  std::map<std::string, std::string>::iterator it = mmap.begin();
  std::cout << "|" << it->first << " " << it->second << "| " << std::endl;
  for (it = mmap.begin(); it != mmap.end(); it++ ) {
    std::cout << "|" << it->first << " " << it->second << "| ";
  }
  // it--;
    // std::cout << "|" << it->first << " " << it->second << "| ";
    // it++;
    // std::cout << "|" << it->first << " " << it->second << "| ";
  std::cout << std::endl;
}
