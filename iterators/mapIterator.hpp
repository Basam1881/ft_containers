/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:14:34 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/27 08:50:22 by bnaji            ###   ########.fr       */
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

      iterator() : _node(NULL), _Highest(NULL), _lowest(NULL), _highEnd(NULL), _lowEnd(NULL) {}
      iterator(avl_type * node) : _node(node) { if (_node) {_lowest = _node->getLowestKey(_node->getMasterRoot()); _Highest = _node->getHighestKey(_node->getMasterRoot()); _highEnd = _node->getHighEnd(); _lowEnd = _node->getLowEnd(); }
      // std::cout << _node->getPair().first << " != " << node->getMasterRoot()->getPair().first << " != " << node->getLowestKey(node->getMasterRoot())->getPair().first << std::endl;
      }
      iterator (iterator const & src) : _node(NULL), _Highest(NULL), _lowest(NULL) { *this = src; }
      ~iterator() {}

      avl_type *              getNode () const { return _node; }

      avl_type *              getHighEnd () const { return _highEnd; }

      avl_type *              getLowEnd () const { return _lowEnd; }

      iterator &		            operator = ( iterator<Category, const T> const & rhs ) {  _node  = rhs._node; _lowest = rhs._lowest; _Highest = rhs._Highest; _highEnd = rhs._node->getHighEnd(); _lowEnd = rhs._node->getLowEnd(); return *this; }

      iterator &                operator ++ () {
        if (this->_node == _lowEnd)
          _node = _lowest;
        _increment();
        return *this;
      }
      iterator                  operator ++ (int) { 
        if (this->_node == _lowEnd)
          _node = _lowest;
        iterator tmp(*this); _increment(); return (tmp);
      }

      iterator &                operator -- () {
        if (this->_node == _highEnd)
          _node = _Highest;
        _decrement();
        return *this;
      }
      iterator                  operator -- (int) {
        if (this->_node == _highEnd)
          _node = _Highest;
        iterator tmp(*this); _decrement(); return (tmp);
      }

      operator                  iterator<Category, const value_type>() { return iterator<Category, const value_type>(_node); }

      reference                 operator * () const { return this->_node->getPair(); }
      pointer                   operator -> () const { return this->_node->getPairPointer(); }

      friend bool operator== ( const iterator & lhs,
                        const iterator & rhs) { return lhs.getNode() == rhs.getNode(); }
      friend bool operator!= ( const iterator & lhs,
                        const iterator & rhs) { return lhs.getNode() != rhs.getNode(); }

    protected:
      avl_type *                             _node;
      avl_type *                             _Highest;
      avl_type *                             _lowest;
      avl_type *                             _highEnd;
      avl_type *                             _lowEnd;

      void        _increment() {
        if (_node == _Highest)
          _node = _highEnd;
        else if (_node == _highEnd) {
          _node = NULL;
          _node->getHighEnd();
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
          _node = _lowEnd;
        else if (_node == _lowEnd) {
          _node = NULL;
          _node->getLowEnd();
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
}

# include "reverse_iterator.hpp"

#endif /* ********************************************************** ITERATOR_H */