/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:14:34 by bnaji             #+#    #+#             */
/*   Updated: 2022/09/10 17:24:50 by bnaji            ###   ########.fr       */
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
# include "iterator_relational_operators.hpp"


namespace ft
{
  template <class Category, class T, class Compare = std::less<typename T::first_type>,
    class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
	class MapIterator
	{
    public:
      typedef T                                                          value_type;
      typedef Compare                                                    key_compare;
      typedef ft::AVL<typename value_type::first_type,
                      typename value_type::second_type, key_compare>     avl_type;
      typedef Distance                                                   difference_type;
      typedef Pointer                                                    pointer;
      typedef Reference                                                  reference;
      typedef Category                                                   iterator_category;

      MapIterator() : _node(NULL), _Highest(NULL), _lowest(NULL), _End(NULL) {}

      MapIterator(avl_type * node, avl_type * highEnd, avl_type * masterRoot) 
      : _node(node), _End(highEnd), _masterRoot(masterRoot) {
        if (_node && _masterRoot) {
          _lowest = _node->getLowestKey(_masterRoot);
          _Highest = _node->getHighestKey(_masterRoot);
        }
      }
      
      MapIterator (MapIterator const & src) : _node(NULL), _Highest(NULL), _lowest(NULL) {
        *this = src;
      }

      ~MapIterator() {}
      
      avl_type *  base () const {
        return _node;
      }

      MapIterator & operator = ( MapIterator const & rhs ) {
        if (this != &rhs && _node != rhs._node) {
          _node  = rhs._node;
          _lowest = rhs._lowest;
          _Highest = rhs._Highest;
          _End = rhs._End;
          _masterRoot = rhs._masterRoot;
        }
        return *this;
      }

      MapIterator & operator ++ () {
        if (checkIfIncrementOrDecrement(true))
          _increment();
        return *this;
      }

      MapIterator operator ++ (int) {
        MapIterator tmp(*this);
        if (checkIfIncrementOrDecrement(true))
          _increment();
        return (tmp);  
      }

      MapIterator & operator -- () {
        if (checkIfIncrementOrDecrement(false))
          _decrement();
        return *this;
      }

      MapIterator operator -- (int) {
        MapIterator tmp(*this);
        if (checkIfIncrementOrDecrement(false))
          _decrement();
        return (tmp);
      }

      operator  MapIterator<Category, const value_type, key_compare>() {
        return MapIterator<Category, const value_type, key_compare>(_node, _End, _masterRoot);
      }

      reference operator * () const {
        return this->_node->getPair();
      }

      pointer operator -> () const {
        return this->_node->getPairPointer();
      }

      template <class Iterator1, class Iterator2> 
      friend bool operator== ( const Iterator1 & lhs, const Iterator2 & rhs);

      template <class Iterator1, class Iterator2>
      friend bool operator!= ( const Iterator1 & lhs, const Iterator2 & rhs);

    protected:
      avl_type *                             _node;
      avl_type *                             _Highest;
      avl_type *                             _lowest;
      avl_type *                             _End;
      avl_type *                             _masterRoot;

      void  _increment() {
        if (_node->getRight()) {
          _node = _node->getRight();
          while (_node->getLeft())
            _node = _node->getLeft();
        }
        else if (_node->getParent()) {
          while (_node->getComp()(_node->getParent()
            ->getPair().first, _node->getPair().first))
            _node = _node->getParent();
          _node = _node->getParent();
        }
      }

      void  _decrement() {
        if (_node->getLeft()) {
          _node = _node->getLeft();
          while (_node->getRight())
            _node = _node->getRight();
        }
        else if (_node->getParent()) {
          while (!_node->getComp()(_node->getParent()
            ->getPair().first, _node->getPair().first))
            _node = _node->getParent();
          if (_node->getParent())
            _node = _node->getParent();
        }
      }

      bool  checkIfIncrementOrDecrement(bool isIncrement) {
        if (isIncrement) {
          if (_node == _End)
            _node = _lowest;
          else if (_node == _Highest)
            _node = _End;
          else
            return true;
        }
        else {
          if (_node == _End)
            _node = _Highest;
          else if (_node == _lowest)
            _node = _End;
          else
            return true;
        }
        return false;
      }
	};
}

# include "reverse_iterator.hpp"

#endif /* ********************************************************** ITERATOR_H */