/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:14:34 by bnaji             #+#    #+#             */
/*   Updated: 2022/09/05 18:51:09 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include <cstddef>
# include <cstdlib>
# include "../algorithms/pair.hpp"
# include "../algorithms/make_pair.hpp"
# include "../algorithms/enable_if.hpp"
# include "../bst/avl.hpp"
# include "iterator_traits.hpp"


namespace ft
{
  template <class Category, class T, class Distance = std::ptrdiff_t,
	  	class Pointer = T*, class Reference = T&>
	class iterator
	{
    public:
      typedef T                                                                           value_type;
      typedef ft::AVL<typename value_type::first_type, typename value_type::second_type>  avl_type;
      typedef Distance                                                                    difference_type;
      typedef Pointer                                                                     pointer;
      typedef Reference                                                                   reference;
      typedef Category                                                                    iterator_category;

      iterator() : _node(NULL), _Highest(NULL), _lowest(NULL), _highEnd(NULL) {}
      iterator(avl_type * node) : _node(node) {
        if (_node) {
          if (_node == _node->getHighEnd()) {
            _lowest = _node->getLowestKey(_node->getMasterRoot());
            _Highest = _node->getHighestKey(_node->getMasterRoot());
          }
          else {
            _lowest = _node->getLowestKey(_node->getMasterRoot());
            _Highest = _node->getHighestKey(_node->getMasterRoot()); 
          }
          _highEnd = _node->getHighEnd();
        }
      }
      iterator (iterator const & src) : _node(NULL), _Highest(NULL), _lowest(NULL) { *this = src; }
      ~iterator() {}

      avl_type *              getNode () const { return _node; }
      
      avl_type *              base () const { return _node; }

      avl_type *              getHighEnd () const { return _highEnd; }


      iterator &		            operator = ( iterator const & rhs ) {
        if (this != &rhs && _node != rhs._node) {
          _node  = rhs._node;
          _lowest = rhs._lowest;
          _Highest = rhs._Highest;
          _highEnd = rhs._node->getHighEnd();
        }
        return *this;
      }

      iterator &                operator ++ () {
        if (this->_node == _highEnd)
          _node = _lowest;
        else
          _increment();
        return *this;
      }
      iterator                  operator ++ (int) { 
        iterator tmp(*this);
        if (this->_node == _highEnd)
          _node = _lowest;
        else
          _increment();
        return (tmp);  
      }

      iterator &                operator -- () {
        if (this->_node == _highEnd)
          _node = _Highest;
        else
          _decrement();
        return *this;
      }
      iterator                  operator -- (int) {
        iterator tmp(*this);
        if (this->_node == _highEnd)
          _node = _Highest;
        else
          _decrement();
        return (tmp);
      }

      operator                  iterator<Category, const value_type>() { return iterator<Category, const value_type>(_node); }

      reference                 operator * () const { return this->_node->getPair(); }
      pointer                   operator -> () const { return this->_node->getPairPointer(); }

    protected:
      avl_type *                             _node;
      avl_type *                             _Highest;
      avl_type *                             _lowest;
      avl_type *                             _highEnd;

      void        _increment() {
        if (_node == _Highest)
          _node = _highEnd;
        else if (_node == _highEnd) {
          _node = NULL;
          // _node->getHighEnd();
        }
        else if (_node->getRight()) {
          _node = _node->getRight();
          while (_node->getLeft())
            _node = _node->getLeft();
        }
        else if (_node->getParent()) {
          while (_node->getLess()(_node->getParent()->getPair().first, _node->getPair().first))
            _node = _node->getParent();
          _node = _node->getParent();
        }
      }

      void        _decrement() {
        if (_node == _lowest)
          _node = _highEnd;
        else if (_node == _highEnd) {
          _node = NULL;
          // _node->getHighEnd();
        }
        else if (_node->getLeft()) {
          _node = _node->getLeft();
          while (_node->getRight())
            _node = _node->getRight();
        }
        else if (_node->getParent()) {
          while (/* _node->getParent() && */ _node->getGreater()(_node->getParent()->getPair().first, _node->getPair().first)) {
            _node = _node->getParent();
          }
          if (_node->getParent())
            _node = _node->getParent();
        }
      }
	};
  template <class Iterator1, class Iterator2>
  bool operator== ( const Iterator1 & lhs,
                    const Iterator2 & rhs) { return lhs.base() == rhs.base(); }
  template <class Iterator1, class Iterator2>
  bool operator!= ( const Iterator1 & lhs,
                    const Iterator2 & rhs) { return lhs.base() != rhs.base(); }
}

# include "reverse_iterator.hpp"

#endif /* ********************************************************** ITERATOR_H */