/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:14:34 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/14 18:48:02 by bnaji            ###   ########.fr       */
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
# include "../bst/avl.hpp"

namespace ft
{
  struct input_iterator_tag {};
  struct output_iterator_tag {};
  struct forward_iterator_tag : public input_iterator_tag {};
  struct bidirectional_iterator_tag : public forward_iterator_tag {};
  struct random_access_iterator_tag : public bidirectional_iterator_tag {};

  template <class Iterator> struct iterator_traits
  {
   typedef typename Iterator::value_type        value_type;
   typedef typename Iterator::difference_type   difference_type;
   typedef typename Iterator::pointer           pointer;
   typedef typename Iterator::reference         reference;
   typedef typename Iterator::iterator_category iterator_category;
  };
  
  template <class T> struct iterator_traits<T*>
  {
    typedef T                                   value_type;
    typedef ptrdiff_t                           difference_type;
    typedef T*                                  pointer;
    typedef T&                                  reference;
    typedef random_access_iterator_tag          iterator_category;
  };
  
  template <class T> struct iterator_traits<const T*>
  {
    typedef T                                   value_type;
    typedef ptrdiff_t                           difference_type;
    typedef T*                                  pointer;
    typedef T&                                  reference;
    typedef random_access_iterator_tag          iterator_category;
  };

  template <class Category, class T, class Distance = std::ptrdiff_t,
	  	class Pointer = T*, class Reference = T&>
	class iterator
	{
    public:
      
      typedef T                                value_type;
      typedef Distance                         difference_type;
      typedef Pointer                          pointer;
      typedef Reference                        reference;
      typedef Category                         iterator_category;

      iterator() : _node(NULL) { /* Ç>getPair() = NULL; */ }
      iterator(pointer node) : _node(node) { /* _node->getPair() = NULL; */ }
      iterator (iterator const & src) : _node(NULL) { /* _node->getPair() = NULL; */ *this = src; }
      ~iterator() {}

      iterator &		            operator = ( iterator<Category, const T> const & rhs ) { if (this != &rhs) this->_node  = rhs._node; return *this; }

      iterator &                operator ++ () { _increment(); return *this; }
      iterator                  operator ++ (int) { iterator tmp(*this); _increment(); return (tmp); }

      iterator &                operator -- () { _decrement(); return *this; }
      iterator                  operator -- (int) { iterator tmp(*this); _decrement(); return (tmp); }

      operator                  iterator<Category, const value_type>() { return iterator<Category, const value_type>(_node); }

      reference                 operator * () const { return this->_node->getPair(); }
      pointer                   operator -> () const { return &this->_node->getPair(); }

      protected:
        pointer     _node;

        void        _increment() {
          if (_node->getRight()) {
            _node = _node->getRight();
            while (_node->getLeft())
              _node = _node->getLeft();
          }
          else if (_node->getParent()) {
            while (_node->getLess()(_node->getParent(), _node))
              _node = _node->getParent();
            _node = _node->getParent();
          }
        }

        void        _decrement() {
          if (_node->getLeft()) {
            _node = _node->getLeft();
            while (_node->getRight())
              _node = _node->getRight();
          }
          else if (_node->getParent()) {
            while (_node->getGreater()(_node->getParent(), _node))
              _node = _node->getParent();
            _node = _node->getParent();
          }
        }
	};

  // template <class Iterator1, class Iterator2>
  // bool operator== ( const Iterator1 & lhs,
  //                   const Iterator2 & rhs) { return lhs.base() == rhs.base(); }
  // template <class Iterator1, class Iterator2>
  // bool operator!= ( const Iterator1 & lhs,
  //                   const Iterator2 & rhs) { return lhs.base() != rhs.base(); }


 template <class Iterator>
	class reverse_iterator : public iterator<typename Iterator::iterator_category, typename Iterator::value_type>
	{
    public:
//       typedef typename iterator_traits<Iterator>::value_type            value_type;
//       typedef typename iterator_traits<Iterator>::difference_type       difference_type;
//       typedef typename iterator_traits<Iterator>::pointer               pointer;
//       typedef typename iterator_traits<Iterator>::reference             reference;
//       typedef typename iterator_traits<Iterator>::iterator_category     iterator_category;
        
//       reverse_iterator() : iterator<iterator_category, value_type>(NULL) {}
//       reverse_iterator(pointer p) : iterator<iterator_category, value_type>(p) {}
//       reverse_iterator(reverse_iterator const & src) : iterator<iterator_category, value_type>(src) { *this = src; }
//       ~reverse_iterator() {}

//       reverse_iterator &	      operator = ( reverse_iterator const & rhs ) { if (this != &rhs) { this->_p  = rhs._p; } return *this; }

//       reverse_iterator &        operator ++ () { --this->_p; return *this; }
//       reverse_iterator          operator ++ (int) { reverse_iterator tmp(*this); this->_p--; return (tmp); }

//       reverse_iterator &        operator -- () { ++this->_p; return *this; }
//       reverse_iterator          operator -- (int) { reverse_iterator tmp(*this); this->_p++; return (tmp); }

//       operator reverse_iterator<iterator<iterator_category, const value_type> >() { return reverse_iterator<iterator<iterator_category, const value_type> >(this->_p); }

	};
}

#endif /* ********************************************************** ITERATOR_H */