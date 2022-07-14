/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:59:29 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/14 18:45:04 by bnaji            ###   ########.fr       */
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

    typedef Key														          key_type;
    typedef T															          mapped_type;
    typedef ft::pair<key_type,mapped_type>		      value_type; 
    typedef Compare																	key_compare_less;
    typedef std::greater<Key>                       key_compare_greater;
    typedef std::equal_to<Key>                      key_compare_equal;
    typedef Alloc																		allocator_type;
    typedef std::allocator<AVL>					            avl_allocator;

  private:
    key_compare_less     _isLess;
    key_compare_greater  _isGreater;
    key_compare_equal    _isEqual;
    allocator_type       _alloc;
    avl_allocator        _avlAlloc;
    value_type           _p;
    AVL                  *_parent;
    AVL                  *_left;
    AVL                  *_right;
    int                  _height;

  public:

  /* ************************************** Constructors ************************************** */
    AVL(allocator_type alloc = allocator_type()) : _alloc(alloc),
        _avlAlloc(avl_allocator()), _p(value_type()), _parent(NULL),
        _left(NULL), _right(NULL), _height(0)
    {}

    AVL(value_type p) : _alloc(allocator_type()),
        _avlAlloc(avl_allocator()), _p(p), _parent(NULL), _left(NULL),
        _right(NULL), _height(0)
    {}

    AVL(AVL const & src) : _alloc(allocator_type()),
        _avlAlloc(avl_allocator()), _p(value_type()), _parent(NULL),
        _left(NULL), _right(NULL), _height(0)
    { *this = src; }

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

  /* ************************************** Getters ************************************** */
    key_compare_less const & getLess() {
      return _isLess;
    }

    key_compare_greater const & getGreater() {
      return _isGreater;
    }

    key_compare_equal const & getEqual() {
      return _isEqual;
    }

    value_type const & getPair() {
      return _p;
    }

    AVL * getParent() {
      return _parent;
    }

    AVL * getLeft() {
      return _left;
    }

    AVL * getRight() {
      return _right;
    }

    int const & getHeight() {
      return _right;
    }

    int getAVLHeight(AVL * root) {
      if (root)
        return root->_height;
      return -1;
    }

    int getBalanceFactor(AVL * root) {
      if (root)
        return getAVLHeight(root->_left) - getAVLHeight(root->_right);
      return 0;
    }

    AVL * getLowestKey(AVL * root) {
      AVL * tmp = root;
      while (tmp && tmp->_left) {
        tmp = tmp->_left;
      }
      return tmp;
    }

    key_type getLeftKey(AVL * root, key_type key) {
      key_type leftKey;
      if (root->_left)
        leftKey = root->_left->_p.first;
      else
        leftKey = key;
      return leftKey;
    }

    key_type getRightKey(AVL * root, key_type key) {
      key_type rightKey;
      if (root->_right)
        rightKey = root->_right->_p.first;
      else
        rightKey = key;
      return rightKey;
    }

    AVL * getLeft(AVL * root) {
      if (root)
        return root->_left;
      return root;
    }

    AVL * getRight(AVL * root) {
      if (root)
        return root->_right;
      return root;
    }

  /* ************************************** Utils ************************************** */
    AVL * freeMe(AVL * root) {
      _avlAlloc.deallocate(root, 1);
      return NULL;
    }

    AVL * replace(AVL * dst, AVL * src) {
      AVL * tmp = _avlAlloc.allocate(1);
      *tmp = *src;
      dst = freeMe(dst);
      return tmp;
    }

    void updateHeight(AVL * root) {
      root->_height = std::max(getAVLHeight(root->_left), getAVLHeight(root->_right)) + 1;
    }

    AVL * checkChildrenAndErase(AVL *root) {
      if (!root->_left && !root->_right)
        root = freeMe(root);
      else if (!root->_left)
        root = replace(root, root->_right);
      else if (!root->_right)
        root = replace(root, root->_left);
      else {
        AVL * tmp = getLowestKey(root->_right);
        root->_p = tmp->_p;
        root->_right = erase(root->_right, root->_p.first);
      }
      return root;
    }

    void printAll(AVL * root)
    {
      if (!root)
          return;
      std::cout << root->_p.first << std::endl;
      printAll(root->_left);
      std::cout << root->_p.second << std::endl;
      printAll(root->_right);
    }

  /* ************************************** Rotaters ************************************** */
    AVL * rotateRight(AVL * root) {
      AVL * left = root->_left;
      AVL * leftRight = root->_left->_right;

      root->_left->_right = root;
      root->_left->_right->_parent = root;
      
      root->_left->_parent = root->_parent;
      root->_parent = root->_left;
      root->_left = leftRight;

      updateHeight(root);
      updateHeight(left);

      return left;
    }

    AVL * rotateLeft(AVL * root) {
      AVL * right = root->_right;
      AVL * rightLeft = right->_left;

      root->_right->_left = root;
      root->_right->_left->_parent = root;

      root->_right->_parent = root->_parent;
      root->_parent = root->_right;
      root->_right = rightLeft;

      updateHeight(root);
      updateHeight(right);

      return right;
    }

    AVL * balance(AVL * root, bool isLeftRight, bool isRightLeft) {
      if (!root)
        return root;
      updateHeight(root);
      int balanceFactor = getBalanceFactor(root);    
      if (balanceFactor > 1) {
        if (isLeftRight)
          root->_left = rotateLeft(root->_left);
        root = rotateRight(root);
      }
      else if (balanceFactor < -1) {
        if (isRightLeft)
          root->_right = rotateRight(root->_right);
        root = rotateLeft (root);
      }
      return root;
    }

  /* ************************************** Modifiers ************************************** */
    AVL * insert(AVL * root, value_type p)
    {
      if (!root) {
        AVL * element = _avlAlloc.allocate(1);
        element->_p.first = p.first;
        element->_p.second = p.second;
        return element;
      }
      if (_isLess(p.first, root->_p.first)) {
        root->_left = insert(root->_left, p);
        root->_left->_parent = root;
      }
      else {
        root->_right = insert(root->_right, p);
        root->_right->_parent = root; 
      }
      root = balance(root, p.first > getLeftKey(root, _p.first), p.first < getRightKey(root, _p.first));
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
      else
        root = checkChildrenAndErase(root);
      root = balance(root, getBalanceFactor(getLeft(root)) < 0, getBalanceFactor(getRight(root)) > 0);
      return root;
    }
  };
}

#endif
