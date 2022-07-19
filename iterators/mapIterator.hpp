/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:14:34 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/19 18:15:37 by bnaji            ###   ########.fr       */
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
	  	class Pointer = typename T::pointer, class Reference = typename T::reference>
	class iterator
	{
    public:
      
      typedef T                                value_type;
      typedef Distance                         difference_type;
      typedef Pointer                          pointer;
      typedef Reference                        reference;
      typedef Category                         iterator_category;

      iterator() : _node(NULL), _Highest(NULL), _lowest(NULL), _highEnd(NULL), _lowEnd(NULL) {}
      iterator(value_type * node) : _node(node) { _lowest = node->getLowestKey(node->getMasterRoot()); _Highest = node->getHighestKey(node->getMasterRoot()); _highEnd = node->getHighEnd(); _lowEnd = node->getLowEnd();
      // std::cout << _node->getPair().first << " != " << node->getMasterRoot()->getPair().first << " != " << node->getLowestKey(node->getMasterRoot())->getPair().first << std::endl;
      }
      iterator (iterator const & src) : _node(NULL), _Highest(NULL), _lowest(NULL) { *this = src; }
      ~iterator() {}

      value_type *              getNode () const { return _node; }

      value_type *              getHighEnd () const { return _highEnd; }

      value_type *              getLowEnd () const { return _lowEnd; }

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
      value_type *                             _node;
      value_type *                             _Highest;
      value_type *                             _lowest;
      value_type *                             _highEnd;
      value_type *                             _lowEnd;

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