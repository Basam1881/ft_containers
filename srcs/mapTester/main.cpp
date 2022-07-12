/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:52:50 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/12 14:31:35 by bnaji            ###   ########.fr       */
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
  
  // ft::pair<int, int> p;
  // p.first = 2;
  // p.second = 20;
  ft::AVL<int, int> * root = NULL;
  ft::AVL<int, int> myavl;
  root = myavl.Insert(root, ft::make_pair(1, 10));
  myavl.Insert(root, ft::make_pair(4, 40));
  myavl.Insert(root, ft::make_pair(2, 20));
  myavl.Insert(root, ft::make_pair(3, 30));
  root->Inorder(root);
  ft::pair<int, int> p1(ft::make_pair(4, 40));
  std:: cout << p1.first << " " << p1.second << std::endl;
  mmap["hi7"] = "seven";
  mmap.insert(std::pair<std::string, std::string>("hi5", "five"));
  mmap.insert(std::pair<std::string, std::string>("hi6", "two"));
  mmap.insert(std::pair<std::string, std::string>("hi4", "four"));
  mmap.insert(std::pair<std::string, std::string>("hi3", "three"));
  for (std::map<std::string, std::string>::iterator it = mmap.begin(); it != mmap.end(); it++ ) {
    std::cout << "|" << it->first << " " << it->second << "| ";
  }
  std::cout << std::endl;
}