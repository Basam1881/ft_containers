/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:59:29 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/11 17:42:14 by bnaji            ###   ########.fr       */
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

    AVL* Insert(AVL * root, value_type p)
    {
      if (!root) {
        AVL * element = _avlAlloc.allocate(1);
        element->_p.first = p.first;
        element->_p.second = p.second;
        return element;
      }
      if (_isLess(p.first, root->_p.first)) {
      // if (p.first > root->_p.first) {
        // std::cout << " ( " << p.first << " < " << root->_p.first << ") ";
        // std::cout << "- LEFT -";
        root->_left = Insert(root->_left, p);
      }
      else {
        // std::cout << " ( " << p.first << " > " << root->_p.first << ") ";
        // std::cout << "- RIGHT -";
        root->_right = Insert(root->_right, p);
      }
      return root;
    }

    void Inorder(AVL * root)
    {
      if (!root)
          return;
      Inorder(root->_left);
      std::cout << root->_p.second << std::endl;
      Inorder(root->_right);
    }
  };
}

#endif
