/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:14:34 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/16 11:56:16 by bnaji            ###   ########.fr       */
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
  template <class T, T v>
  struct bidirectional_constant {
    static const T value = v;
    typedef T value_type;
    typedef bidirectional_constant<T,v> type;
  };

  typedef bidirectional_constant<bool,false> false_type;
  typedef bidirectional_constant<bool,true> true_type;

  template <class _Tp> struct is_bidirectional                                      : public false_type {};
  template <>          struct is_bidirectional<bidirectional_iterator_tag>          : public true_type {};

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

      iterator() : _node(NULL), _heighest(NULL), _lowest(NULL) { T dumb; _end = &dumb; }
      iterator(value_type * node) : _node(node) { _lowest = _node->getLowestKey(_node->getMasterRoot()); _heighest = _node->getHeighestKey(_node->getMasterRoot()); T dumb; _end = &dumb; }
      iterator (iterator const & src) : _node(NULL), _heighest(NULL), _lowest(NULL) { *this = src; T dumb; _end = &dumb; }
      ~iterator() {}

      value_type *              getNode () const { return _node; }

      iterator &		            operator = ( iterator<Category, const T> const & rhs ) { if (this != &rhs) { this->_node  = rhs._node; _lowest = rhs._lowest; _heighest = rhs._heighest; } return *this; }

      iterator &                operator ++ () { _increment(); return *this; }
      iterator                  operator ++ (int) { iterator tmp(*this); _increment(); return (tmp); }

      iterator &                operator -- () { _decrement(); return *this; }
      iterator                  operator -- (int) { iterator tmp(*this); _decrement(); return (tmp); }

      operator                  iterator<Category, const value_type>() { return iterator<Category, const value_type>(_node); }

      reference                 operator * () const { return this->_node->getPair(); }
      pointer                   operator -> () const { return this->_node->getPairPointer(); }

      template <class Iterator1, class Iterator2>
      friend bool operator== ( const Iterator1 & lhs,
                        const Iterator2 & rhs) { return lhs.getNode() == rhs.base().getNode(); }
      template <class Iterator1, class Iterator2>
      friend bool operator!= ( const Iterator1 & lhs,
                        const Iterator2 & rhs) { return lhs.getNode() != rhs.base().getNode(); }

    protected:
      value_type *                             _node;
      value_type *                             _heighest;
      value_type *                             _lowest;
      value_type *                             _end;

      void        _increment() {
        if (_node == _heighest)
          _node = _end;
        else if (_node == _end)
          _node = NULL;
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
        if (_node == _lowest) {
          _node = NULL;
        }
        else if (_node->getLeft()) {
          _node = _node->getLeft();
          while (_node->getRight())
            _node = _node->getRight();
        }
        else if (_node->getParent()) {
          while (_node->getParent() && _node->getGreater()(_node->getParent()->getPair().first, _node->getPair().first)) {
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