/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:58:56 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/20 17:35:40 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include <cstddef>
# include <cstdlib>
# include "iterator_traits.hpp"

namespace ft
{
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

      iterator() : _p(NULL) {}
      iterator(pointer p) : _p(p) {}
      iterator (iterator const & src) : _p(NULL) { *this = src; }
      ~iterator() {}

      pointer                   base() const { return this->_p; }

      iterator &		            operator = ( iterator<Category, const T> const & rhs ) { if (this != &rhs) this->_p  = rhs.base(); return *this; }
      iterator  		            operator + ( difference_type n ) const { return (this->_p + n); }
      iterator  		            operator - ( difference_type n ) const { return (this->_p - n); }

      iterator &                operator += (difference_type n) { this->_p = this->_p + n; return *this; }
      iterator &                operator ++ () { ++this->_p; return *this; }
      iterator                  operator ++ (int) { iterator tmp(*this); this->_p++; return (tmp); }

      iterator &                operator -= (difference_type n) { this->_p = this->_p - n; return *this; }
      iterator &                operator -- () { --this->_p; return *this; }
      iterator                  operator -- (int) { iterator tmp(*this); this->_p--; return (tmp); }

      reference                 operator * () const { return *(this->_p); }
      pointer                   operator -> () const { return this->_p; }

      operator                  iterator<Category, const value_type>() { return iterator<Category, const value_type>(_p); }

      reference                 operator [] (difference_type const & n) { return this->_p[n]; }

      protected:
        pointer     _p;
	};

  template <class Iterator1, class Iterator2>
  bool operator== ( const Iterator1 & lhs,
                    const Iterator2 & rhs) { return lhs.base() == rhs.base(); }
  template <class Iterator1, class Iterator2>
  bool operator!= ( const Iterator1 & lhs,
                    const Iterator2 & rhs) { return lhs.base() != rhs.base(); }
  template <class Iterator1, class Iterator2>
  bool operator<  ( const Iterator1 & lhs,
                    const Iterator2 &rhs) { return lhs.base() < rhs.base(); }
  template <class Iterator1, class Iterator2>
  bool operator<= ( const Iterator1  &lhs,
                    const Iterator2 & rhs) { return lhs.base() <= rhs.base(); }
  template <class Iterator1, class Iterator2>
  bool operator>  ( const Iterator1  &lhs,
                    const Iterator2 & rhs) { return lhs.base() > rhs.base(); }
  template <class Iterator1, class Iterator2>
  bool operator>= ( const Iterator1 & lhs,
                    const Iterator2 & rhs) { return lhs.base() >= rhs.base(); }
  template <class Iterator>
  Iterator operator+ (typename Iterator::difference_type n,
             const Iterator& it) { return (it + n); }

  template <class Iterator>
  typename Iterator::difference_type operator- (const Iterator& lhs,
             const Iterator& rhs) { return abs(lhs.base() - rhs.base()); }

}

# include "reverse_iterator.hpp"

#endif /* ********************************************************** ITERATOR_H */