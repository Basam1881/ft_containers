/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vTException.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 12:19:26 by bnaji             #+#    #+#             */
/*   Updated: 2022/08/26 12:08:31 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "vectorTests.hpp"


bool  vectorExceptionTest1(bool printAllTests, size_t testnum) {
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.vector(size_t, val)                    : " << RESET;
  
  (void)printAllTests;
  std::vector<int> vec;
  try {
    std::vector<int> v(vec.max_size() + 1);
  } catch (std::length_error & e) {
    try {
      ft::vector<int> ft_v(vec.max_size() + 1);
    } catch (std::length_error & e) {
      try {
        std::vector<int> v(vec.max_size());
      } catch (std::bad_alloc & e) {
        try {
          ft::vector<int> ft_v(vec.max_size());
        } catch (std::bad_alloc & e) {
          std::cout << GREEN << "OK" << RESET << std::endl; return true;
        }
      }
    }
  }

  std::cout << RED << "KO" << RESET << std::endl;
  return false;
}

bool  vectorExceptionTest2(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.operator=(vector)                      : " << RESET;
  
  std::vector<int> v(5, testnum);
  ft::vector<int> ft_v(5, testnum);
  try {
    v = std::vector<int>(v.max_size() + 1);
  } catch (std::length_error & e) {
    try {
      ft_v = ft::vector<int>(v.max_size() + 1);
    } catch (std::length_error & e) {
      try {
        v = std::vector<int>(v.max_size());
      } catch (std::bad_alloc & e) {
        try {
          ft_v = ft::vector<int>(v.max_size());
        } catch (std::bad_alloc & e) {
          if (cmpAll(v, ft_v)) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
          else std::cout << RED << "KO" << RESET << std::endl;
        }
      }
    }
  }
  
  if (!test || printAllTests) { printAll<int>(v, ft_v); }
  
  return test;
}

bool  vectorExceptionTest3(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.resize(size_t, val)                    : " << RESET;
  
  std::vector<int> v(5, testnum);
  ft::vector<int> ft_v(5, testnum);
  try {
    v.resize(v.max_size() + 1);
  } catch (std::length_error & e) {
    try {
      ft_v.resize(v.max_size() + 1);
    } catch (std::length_error & e) {
      try {
        v.resize(v.max_size());
      } catch (std::bad_alloc & e) {
        try {
          ft_v.resize(v.max_size());
        } catch (std::bad_alloc & e) {
          if (cmpAll(v, ft_v)) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
          else std::cout << RED << "KO" << RESET << std::endl;
        }
      }
    }
  }
  
  if (!test || printAllTests) { printAll<int>(v, ft_v); }
  
  return test;
}

bool  vectorExceptionTest4(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.reserve(size_t)                        : " << RESET;
  
  std::vector<int> v(5, testnum);
  ft::vector<int> ft_v(5, testnum);
  try {
    v.reserve(v.max_size() + 1);
  } catch (std::length_error & e) {
    try {
      ft_v.reserve(v.max_size() + 1);
    } catch (std::length_error & e) {
      try {
        v.reserve(v.max_size());
      } catch (std::bad_alloc & e) {
        try {
          ft_v.reserve(v.max_size());
        } catch (std::bad_alloc & e) {
          if (cmpAll(v, ft_v)) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
          else std::cout << RED << "KO" << RESET << std::endl;
        }
      }
    }
  }
  
  if (!test || printAllTests) { printAll<int>(v, ft_v); }
  
  return test;
}

bool  vectorExceptionTest5(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.at(size_t)                             : " << RESET;

  std::vector<int> v(5, testnum);
  ft::vector<int> ft_v(5, testnum);
  try {
    v.at(v.size() + 1);
  } catch (std::out_of_range & e) {
    try {
      ft_v.at(v.size() + 1);
    } catch (std::out_of_range & e) {
      try {
        v.at(-1);
      } catch (std::out_of_range & e) {
        try {
          ft_v.at(-1);
        } catch (std::out_of_range & e) {
          if (cmpAll(v, ft_v)) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
          else std::cout << RED << "KO" << RESET << std::endl;
        }
      }
    }
  }
  
  if (!test || printAllTests) { printAll<int>(v, ft_v); }
  
  return test;
}

bool  vectorExceptionTest6(bool printAllTests, size_t testnum) {
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.at(size_t) const                       : " << RESET;

  const std::vector<int> v(5, testnum);
  const ft::vector<int> ft_v(5, testnum);
  try {
    v.at(v.size() + 1);
  } catch (std::out_of_range & e) {
    try {
      ft_v.at(v.size() + 1);
    } catch (std::out_of_range & e) {
      try {
        v.at(-1);
      } catch (std::out_of_range & e) {
        try {
          ft_v.at(-1);
        } catch (std::out_of_range & e) {
          std::cout << GREEN << "OK" << RESET << std::endl;
          if (printAllTests) printAll<int>(v, ft_v);
          return true;
        }
      }
    }
  }
  
  std::cout << RED << "KO" << RESET << std::endl;
  printAll<int>(v, ft_v);
  
  return false;
}

bool  vectorExceptionTest7(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.assing(size_t, val)                    : " << RESET;
  
  std::vector<int> v(5, testnum);
  ft::vector<int> ft_v(5, testnum);
  try {
    v.assign(v.max_size() + 1, 0);
  } catch (std::length_error & e) {
    try {
      ft_v.assign(v.max_size() + 1, 0);
    } catch (std::length_error & e) {
      try {
        v.assign(v.max_size(), 0);
      } catch (std::bad_alloc & e) {
        try {
          ft_v.assign(v.max_size(), 0);
        } catch (std::bad_alloc & e) {
          if (cmpAll(v, ft_v)) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
          else std::cout << RED << "KO" << RESET << std::endl;
        }
      }
    }
  }
  
  if (!test || printAllTests) { printAll<int>(v, ft_v); }
  
  return test;
}

bool  vectorExceptionTest8(bool printAllTests, size_t testnum) {
  bool test = false;
  std::cout << "\n" << WHITE << testnum << BLUE << " : vector<int>.insert(iterator, size_t, val)          : " << RESET;

  std::vector<int> v(5, testnum);
  ft::vector<int> ft_v(5, testnum);
  try {
    v.insert(v.begin(), v.max_size() - 4, 10);
  } catch (std::length_error & e) {
    try {
      ft_v.insert(ft_v.begin(), v.max_size() - 4, 10);
    } catch (std::length_error & e) {
      try {
        v.insert(v.begin(), v.max_size() - 5, 10);
      } catch (std::bad_alloc & e) {
        try {
          ft_v.insert(ft_v.begin(), v.max_size() - 5, 10);
        } catch (std::bad_alloc & e) {
          if (cmpAll(v, ft_v)) { std::cout << GREEN << "OK" << RESET << std::endl; test = true; }
          else std::cout << RED << "KO" << RESET << std::endl;
        }
      }
    }
  }
  
  if (!test || printAllTests) { printAll<int>(v, ft_v); }
  
  return test;
}
