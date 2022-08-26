/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:59:29 by bnaji             #+#    #+#             */
/*   Updated: 2022/08/26 08:40:45 by bnaji            ###   ########.fr       */
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
  public:
    typedef Key														          key_type;
    typedef T															          mapped_type;
    typedef ft::pair<key_type,mapped_type>		      value_type;
    typedef value_type *		                        pointer;
    typedef value_type &		                        reference;
    typedef Compare																	key_compare_less;
    typedef std::greater<Key>                       key_compare_greater;
    typedef std::equal_to<Key>                      key_compare_equal;
    typedef Alloc																		allocator_type;
    // typedef std::allocator<AVL>					            avl_allocator;

  private:
    key_compare_less     _isLess;
    key_compare_greater  _isGreater;
    key_compare_equal    _isEqual;
    allocator_type       _alloc;
    // avl_allocator        _avlAlloc;
    value_type           _p;
    AVL                  *_highEnd;
    AVL                  *_lowEnd;
    AVL                  *_masterRoot;
    AVL                  *_parent;
    AVL                  *_left;
    AVL                  *_right;
    int                  _height;

  public:

  /* ************************************** Constructors ************************************** */
    AVL(allocator_type alloc = allocator_type()) : _alloc(alloc),
        /* _avlAlloc(avl_allocator()), */ _p(), _highEnd(NULL), _lowEnd(NULL), _masterRoot(this), _parent(NULL),
        _left(NULL), _right(NULL), _height(0)
    {}

    AVL(value_type p) : _alloc(allocator_type()),
        /* _avlAlloc(avl_allocator()), */ _p(p), _highEnd(NULL), _lowEnd(NULL), _masterRoot(this), _parent(NULL), _left(NULL),
        _right(NULL), _height(0)
    {}

    AVL(AVL const & src) : _alloc(allocator_type()),
        /* _avlAlloc(avl_allocator()), */ _p(src._p), _highEnd(NULL), _lowEnd(NULL), _masterRoot(this), _parent(NULL),
        _left(NULL), _right(NULL), _height(0)
    { *this = src; }

    AVL &		operator=( AVL const & rhs ) {
      if ( this != &rhs ) {
        _alloc = rhs._alloc;
        // _avlAlloc = rhs._avlAlloc;
        _highEnd = rhs._highEnd;
        _lowEnd = rhs._lowEnd;
        _parent = rhs._parent;
        _left = rhs._left;
        _right = rhs._right;
        _height = rhs._height;
        if (!_parent)
          _masterRoot = this;
        else
          _masterRoot = rhs._masterRoot;
      }
      return *this;
    }

  /* ************************************** Getters ************************************** */
    key_compare_less getLess() {
      return _isLess;
    }

    key_compare_greater getGreater() {
      return _isGreater;
    }

    key_compare_equal getEqual() {
      return _isEqual;
    }

    value_type & getPair() {
      return _p;
    }

    value_type * getPairPointer() {
      return &_p;
    }

    AVL * getHighEnd() {
      return _highEnd;
    }

    void setHighEnd(AVL * highEnd) {
      _highEnd = highEnd;
    }
    
    AVL * getLowEnd() {
      return _lowEnd;
    }

    void setLowEnd(AVL * lowEnd) {
      _lowEnd = lowEnd;
    }

    AVL * getMasterRoot() {
      return _masterRoot;
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
        // std::cout << tmp->_p.first << " | " << std::endl;
        tmp = tmp->_left;
        // std::cout << tmp->_p.first << " > " << std::endl;
      }
        // std::cout << tmp->_p.first << " >>> " << std::endl;
      return tmp;
    }

    AVL * getHighestKey(AVL * root) {
      AVL * tmp = root;
      while (tmp && tmp->_right) {
        tmp = tmp->_right;
      }
      return tmp;
    }

    key_type getLeftKey(AVL * root, key_type key) {
      if (root->_left)
        return root->_left->_p.first;
      return key;
    }

    key_type getRightKey(AVL * root, key_type key) {
      if (root->_right)
        return root->_right->_p.first;
      return key;
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
      // _avlAlloc.deallocate(root, 1);
      
      // delete root->_highEnd;
      // delete root->_lowEnd;
      
      delete root;
      return NULL;
    }

    AVL * replace(AVL * dst, AVL * src) {
      // AVL * tmpParent = dst->_parent;
      // AVL * tmpMasterRoot = dst->_masterRoot;
      AVL * tmpDst = new AVL(src->_p);
      *tmpDst = *src;
      tmpDst->_parent = dst->_parent;
      if (!tmpDst->_parent)
        tmpDst->_masterRoot = tmpDst;
      else
        tmpDst->_masterRoot = dst->_masterRoot;
      dst = freeMe(dst);
      src = freeMe(src);
      // std::cout << "replace" << std::endl;
      dst = tmpDst;
      // *dst = *src;
      // dst->_parent = tmpParent;
      // dst->_masterRoot = tmpMasterRoot;
      return dst;
    }

    void updateHeight(AVL * root) {
      root->_height = std::max(getAVLHeight(root->_left), getAVLHeight(root->_right)) + 1;
    }

    void  updateMasterRoot(AVL * root) {
      if (!root)
        return ;
      if (root->_parent)
        root->_masterRoot = root->_parent->_masterRoot;
      updateMasterRoot(root->_left);
      updateMasterRoot(root->_right);
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
        AVL * tmpRoot = new AVL(tmp->_p);
        *tmpRoot = *root;
        freeMe(root);
        root = tmpRoot;
        // root->_p = tmp->_p;
        root->_right = erase(root->_right, tmp->_p.first);
      }
      return root;
    }

    void printAll(AVL * root)
    {
      if (!root)
          return;
      std::cout << "<--- " << root->_p.second << " : ( left - ";
      if (root->_left)
        std::cout << root->_left->_p.second << " ) - ( right - ";
      else
        std::cout << "NULL" << " ) - ( right - ";
      if (root->_right)
        std::cout << root->_right->_p.second << " ) - ( parent - ";
      else
        std::cout << "NULL" << " ) - ( parent - ";
      if (root->_parent)
        std::cout << root->_parent->_p.second << " ) - ( masterRoot - ";
      else
        std::cout << "NULL" << " ) - ( masterRoot - ";
      if (root->_masterRoot)
        std::cout << root->_masterRoot->_p.second << " )" << std::endl;
      else  
        std::cout << "NULL )" << std::endl;
      printAll(root->_left);
      printAll(root->_right);
    }

  /* ************************************** Rotaters ************************************** */
    AVL * rotateRight(AVL * root) {
      AVL * left = root->_left;
      AVL * leftRight = root->_left->_right;

      root->_left->_parent = root->_parent;
      root->_left->_right = root;
      root->_parent = root->_left;

      if(leftRight)
        leftRight->_parent = root;
      root->_left = leftRight;
      
      if (root->_masterRoot == root) {
        left->_masterRoot = left;
        updateMasterRoot(left);
      }
      // std::cout << root->_p.second <<" master is " << root->_masterRoot->_p.second << std::endl;
      // std::cout << std::endl;

      updateHeight(root);
      updateHeight(left);

      return left;
    }

    AVL * rotateLeft(AVL * root) {
      AVL * right = root->_right;
      AVL * rightLeft = right->_left;

      root->_right->_parent = root->_parent;
      root->_right->_left = root;
      root->_parent = root->_right;

      if (rightLeft)
        rightLeft->_parent = root;
      root->_right = rightLeft;

      if (root->_masterRoot == root) {
        right->_masterRoot = right;
        updateMasterRoot(right);
      }
      // std::cout << root->_p.second <<" master is " << root->_masterRoot->_p.second << std::endl;
      // std::cout << std::endl;
      updateHeight(root);
      updateHeight(right);

      return right;
    }

    AVL * balance(AVL * root, bool isLeftRight, bool isRightLeft) {
      if (!root)
        return root;
      updateHeight(root);
      // updateMasterRoot(root);
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
      // else
      //   std::cout << "No balance\n";
      // std::cout << root->_p.second << std::endl;
      // if (root->_masterRoot)
      // std::cout << root->_p.second <<" master is " << root->_masterRoot->_p.second << std::endl;
      return root;
    }

  /* ************************************** Modifiers ************************************** */
    AVL * insert(AVL * root, value_type p)
    {
      if (!root) {
        AVL * element = new AVL(p);
        element->_highEnd = new AVL;
        element->_lowEnd = new AVL;
        // element->_p.first = p.first;
        // element->_p.second = p.second;
        element->_masterRoot = element;
        return element;
      }
      if (_isLess(p.first, root->_p.first)) {
        root->_left = insert(root->_left, p);
        root->_left->_parent = root;
        root->_left->_masterRoot = root->_masterRoot;
        if (root->_left->_p == p) {
          delete root->_left->_highEnd;
          delete root->_left->_lowEnd;
        }
        root->_left->_highEnd = root->_highEnd;
        root->_left->_lowEnd = root->_lowEnd;
      }
      else {
        root->_right = insert(root->_right, p);
        root->_right->_parent = root;
        root->_right->_masterRoot = root->_masterRoot;
        if (root->_right->_p == p) {
          delete root->_right->_highEnd;
          delete root->_right->_lowEnd;
        }
        root->_right->_highEnd = root->_highEnd;
        root->_right->_lowEnd = root->_lowEnd;
      }

      root = balance(root, p.first > getLeftKey(root, _p.first), p.first < getRightKey(root, _p.first));
      return root;
    }

    AVL * search(AVL * root, Key key) {
      if (!root || _isEqual(key, root->_p.first))
        return root;
      if (_isLess(key, root->_p.first))
        return search(root->_left, key);
      else if (root == root->getHighestKey(_masterRoot))
        return NULL;
      return search(root->_right, key);
    }

    AVL * erase(AVL * root, Key key) {
      if (!root)
        return root;
      // std::cout << "Erase Balance\n";
      // if (root->_p.second == "three")
      //   std::cout << root->_left->_p.second << " - " << root->_masterRoot->_p.second << std::endl;
      if (_isLess(key, root->_p.first))
        root->_left = erase(root->_left, key);
      else if (_isGreater(key, root->_p.first))
        root->_right  = erase(root->_right, key);
      else
        root = checkChildrenAndErase(root);
      // if (root->_p.second == "two")
      //   std::cout << root->_p.second << " - " << root->_masterRoot->_p.second << std::endl;
      root = balance(root, getBalanceFactor(getLeft(root)) < 0, getBalanceFactor(getRight(root)) > 0);
      return root;
    }
  };
}

#endif
