/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:59:29 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/12 19:59:53 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_HPP
# define AVL_HPP

#include <iostream>
#include <string>
#include "../algorithms/pair.hpp"
#include "../algorithms/make_pair.hpp"

namespace ft {
  template < class Key, class T, class Compare = std::less<Key>,
    class Alloc = std::allocator<ft::pair<const Key,T> > >
  class AVL {

    typedef Key																			key_type;
    typedef T																				mapped_type;
    typedef ft::pair<key_type,mapped_type>		      value_type;
    typedef Compare																	key_compare;
    typedef Alloc																		allocator_type;
    typedef std::allocator<AVL>					avl_allocator;

  private:
    key_compare          _isLess;
    std::greater<Key>    _isGreater;   
    std::equal_to<Key>   _isEqual;   
    allocator_type       _alloc;
    avl_allocator        _avlAlloc;
    value_type           _p;
    AVL                  *_parent;
    AVL                  *_left;
    AVL                  *_right;

  public:
    AVL(allocator_type alloc = allocator_type()) : _alloc(alloc),
        _avlAlloc(avl_allocator()), _p(value_type()), _parent(NULL), _left(NULL), _right(NULL)
    {}
    

    AVL(value_type p) : _alloc(allocator_type()),
        _avlAlloc(avl_allocator()), _p(p), _parent(NULL), _left(NULL), _right(NULL)
    {}

    AVL &		operator=( AVL const & rhs ) {
      if ( this != &rhs ) {
        _alloc = rhs._alloc;
        _avlAlloc = rhs._avlAlloc;
        _p = rhs._p;
        _parent = rhs._parent;
        _left = rhs._left;
        _right = rhs._right;
      }
      return *this;
    }

    value_type& getpair() {
      return _p;
    }

    AVL * getLowestKey(AVL * root) {
      AVL * tmp = root;
      while (tmp) {
        tmp = tmp->_left;
      }
      return tmp;
    }

    AVL * insert(AVL * root, value_type p)
    {
      if (!root) {
        AVL * element = _avlAlloc.allocate(1);
        element->_p.first = p.first;
        element->_p.second = p.second;
        return element;
      }
      if (_isLess(p.first, root->_p.first))
        root->_left = insert(root->_left, p);
      else
        root->_right = insert(root->_right, p);
      return root;
    }

    AVL * search(AVL * root, Key key) {
      if (!root || _isEqual(key, root->_p.first))
        return root;
      if (_isLess(key, root->_p.first))
        return search(root->_left, key);
      return search(root->_right, key);
    }

    AVL * erase(AVL * root, Key key) {
      if (!root)
        return root;
      if (_isLess(key, root->_p.first))
        root->_left = erase(root->_left, key);
      else if (_isGreater(key, root->_p.first))
        root->_right  = erase(root->_right, key);
      else {
        if (!root->_left && !root->_right) {
          _avlAlloc.deallocate(root, 1);
          return NULL;
        }
        else if (!root->_left) {
          AVL * tmp = _avlAlloc.allocate(1);
          tmp = root->_right;
          _avlAlloc.deallocate(root, 1);
          return tmp;
        }
        else if (!root->_right) {
          AVL * tmp = _avlAlloc.allocate(1);
          tmp = root->_left;
          _avlAlloc.deallocate(root, 1);
          return tmp;
        }
        AVL * tmp = getLowestKey(root->_right);
        root->_p.first = tmp->_p.first;
        root->_right = erase(root->_right, tmp->_p.first);
        
      }
      return root;
    }

    void inorder(AVL * root)
    {
      if (!root)
          return;
      inorder(root->_left);
      std::cout << root->_p.second << std::endl;
      inorder(root->_right);
    }
  };
}

#endif
