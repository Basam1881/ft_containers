/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:30:42 by bnaji             #+#    #+#             */
/*   Updated: 2022/08/28 16:39:05 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../PerformanceChecker.hpp"
#include "../../stack/stack.hpp"
#include <stack>
#include <deque>

template<typename stack_type>
void  fillStack(stack_type & stack, size_t size) {
  for (size_t i = 1; i <= size; i++)
    stack.push(i);
}

bool checkConstructor() {
size_t size = 10;
  ft::vector<int> ftvec;
  std::deque<int> stdvec;
  for (size_t i = 1; i <= size; i++)
    ftvec.push_back(i);
  for (size_t i = 1; i <= size; i++)
    stdvec.push_back(i);
  ft::stack<int> ftstack(ftvec);
  std::stack<int> stdstack(stdvec);

  if (ftstack.empty() && ftstack.size() != stdstack.size())
    return false;  
  for (size_t i = 1; i <= 10; i++) {
    if (ftstack.top() != stdstack.top())
      return false;
    ftstack.pop();
    stdstack.pop();
  }
  if (!ftstack.empty())
    return false;  
  return true;
}

bool checkPush() {
  size_t size = 10;
  ft::stack<int> ftstack;
  std::stack<int> stdstack;
  
  for (size_t i = 1; i <= size; i++) {
    ftstack.push(i);
    stdstack.push(i);
    if (ftstack.top() != stdstack.top() && ftstack.size() != stdstack.size())
      return false;
  }
  return true;
}

bool checkPop() {
  size_t size = 10;
  ft::stack<int> ftstack;
  std::stack<int> stdstack;
  fillStack< ft::stack<int> >(ftstack, size);
  fillStack< std::stack<int> >(stdstack, size);
  
  for (size_t i = 1; i <= size; i++) {
    if (ftstack.top() != stdstack.top() && ftstack.size() != stdstack.size())
      return false;
    ftstack.pop();
    stdstack.pop();
  }
    return true;
}

bool checkEmpty() {
  size_t size = 10;
  ft::stack<int> ftstack;
  std::stack<int> stdstack;
  
  if (!ftstack.empty())
    return false;
  fillStack< ft::stack<int> >(ftstack, size);
  fillStack< std::stack<int> >(stdstack, size);

  for (size_t i = 1; i <= size; i++) {
    if (ftstack.empty())
      return false;
    ftstack.pop();
    stdstack.pop();
  }
  if (!ftstack.empty())
    return false;
  return true;
}

bool checkSize() {
  size_t size = 10;
  ft::stack<int> ftstack;
  std::stack<int> stdstack;
  
  if (ftstack.size())
    return false;
  fillStack< ft::stack<int> >(ftstack, size);
  fillStack< std::stack<int> >(stdstack, size);

  for (size_t i = 1; i <= 10; i++) {
    ftstack.pop();
    stdstack.pop();
    if (ftstack.size() != stdstack.size())
      return false;
  }
  return true;
}

bool checkTop() {
  size_t size = 10;
  ft::stack<int> ftstack;
  std::stack<int> stdstack;

  fillStack< ft::stack<int> >(ftstack, size);
  fillStack< std::stack<int> >(stdstack, size);

  for (size_t i = 1; i <= 10; i++) {
    if (ftstack.top() != stdstack.top())
      return false;
    ftstack.pop();
    stdstack.pop();
  }
  return true;
}

bool checkEqual() {
  ft::stack<int> ftstack1;
  ft::stack<int> ftstack2;
  ft::stack<int> ftstack3;
  size_t size = 10;
  fillStack< ft::stack<int> >(ftstack1, size);
  fillStack< ft::stack<int> >(ftstack2, size);
  return ftstack1 == ftstack2 && !(ftstack1 == ftstack3);
}

bool checkNotEqual() {
  ft::stack<int> ftstack1;
  ft::stack<int> ftstack2;
  ft::stack<int> ftstack3;
  size_t size = 10;
  fillStack< ft::stack<int> >(ftstack1, size);
  fillStack< ft::stack<int> >(ftstack2, size);
  return ftstack1 != ftstack3 && !(ftstack1 != ftstack2);
}

bool checkLessThan() {
  ft::stack<int> ftstack1;
  ft::stack<int> ftstack2;
  ft::stack<int> ftstack3;
  size_t size = 10;
  fillStack< ft::stack<int> >(ftstack1, size);
  fillStack< ft::stack<int> >(ftstack2, size / 2);
  return ftstack3 < ftstack2 && ftstack2 < ftstack1
    && !(ftstack1 < ftstack1 || ftstack1 < ftstack2 || ftstack1 < ftstack3);
}

bool checkLessThanOrEqual() {
  ft::stack<int> ftstack1;
  ft::stack<int> ftstack2;
  ft::stack<int> ftstack3;
  size_t size = 10;
  fillStack< ft::stack<int> >(ftstack1, size);
  fillStack< ft::stack<int> >(ftstack2, size / 2);
  return ftstack3 <= ftstack2 && ftstack2 <= ftstack1 && ftstack1 <= ftstack1
    && !(ftstack1 <= ftstack2 || ftstack1 <= ftstack3);
}

bool checkGreaterThan() {
  ft::stack<int> ftstack1;
  ft::stack<int> ftstack2;
  ft::stack<int> ftstack3;
  size_t size = 10;
  fillStack< ft::stack<int> >(ftstack1, size);
  fillStack< ft::stack<int> >(ftstack2, size / 2);
  return ftstack1 > ftstack2 && ftstack2 > ftstack3
    && !(ftstack1 > ftstack1 || ftstack3 > ftstack2 || ftstack2 > ftstack1);
}

bool checkGreaterThanOrEqual() {
  ft::stack<int> ftstack1;
  ft::stack<int> ftstack2;
  ft::stack<int> ftstack3;
  size_t size = 10;
  fillStack< ft::stack<int> >(ftstack1, size);
  fillStack< ft::stack<int> >(ftstack2, size / 2);
  return ftstack1 >= ftstack2 && ftstack2 >= ftstack3 && ftstack1 >= ftstack1
    && !(ftstack3 >= ftstack2 || ftstack2 >= ftstack1);
}

int main() {
  std::cout << PURPLE << "contructor    :" << RESET;
  checkConstructor() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;

  std::cout << PURPLE << "push          :" << RESET;
  checkPush() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;

  std::cout << PURPLE << "pop           :" << RESET;
  checkPop() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;

  std::cout << PURPLE << "empty         :" << RESET;
  checkEmpty() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;

  std::cout << PURPLE << "size          :" << RESET;
  checkSize() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;

  std::cout << PURPLE << "top           :" << RESET;
  checkTop() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;

  // relational operators
  std::cout << PURPLE << "operator == ():" << RESET;
  checkEqual() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;

  std::cout << PURPLE << "operator != ():" << RESET;
  checkNotEqual() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;

  std::cout << PURPLE << "operator < () :" << RESET;
  checkLessThan() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;

  std::cout << PURPLE << "operator <= ():" << RESET;
  checkLessThanOrEqual() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;

  std::cout << PURPLE << "operator > () :" << RESET;
  checkGreaterThan() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;

  std::cout << PURPLE << "operator >= ():" << RESET;
  checkGreaterThanOrEqual() ? std::cout << GREEN <<" OK" << RESET << std::endl : std::cout << RED <<" KO" << RESET << std::endl;

}
