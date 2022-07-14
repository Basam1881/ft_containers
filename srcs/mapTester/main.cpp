/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:52:50 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/14 11:28:21 by bnaji            ###   ########.fr       */
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
  // std::vector<std::string>::iterator v;
  
  // ft::pair<std::string, std::string> p = ft::make_pair<std::string, std::string>("hello", "world");
  // p.first = 2;
  // p.second = 20;
  ft::AVL<std::string, std::string> myavl, * root = NULL;
  root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi3", "three"));
  root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi4", "four"));
  root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi5", "five"));
  root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi6", "six"));
  root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi7", "seven"));
  root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi8", "eight"));
  root = myavl.insert(root, ft::make_pair<std::string, std::string>("hi2", "two"));
  // std::cout << "HELLO world ------ ";
  root = myavl.erase(root, "hi8");
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
  // mmap.erase("hi4");
  // mmap.erase("hi4");
  for (std::map<std::string, std::string>::iterator it = mmap.begin(); it != mmap.end(); it++ ) {
    std::cout << "|" << it->first << " " << it->second << "| ";
  }
  std::cout << std::endl;
}
