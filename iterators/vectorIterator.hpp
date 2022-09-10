/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:58:56 by bnaji             #+#    #+#             */
/*   Updated: 2022/09/10 17:48:29 by bnaji            ###   ########.fr       */
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
# include "iterator_relational_operators.hpp"

namespace ft
{
  template <class Category, class T, class Distance = std::ptrdiff_t,
	  	class Pointer = T*, class Reference = T&>
	class VectorIterator
	{
    public:
        
      typedef T                                value_type;
      typedef Distance                         difference_type;
      typedef Pointer                          pointer;
      typedef Reference                        reference;
      typedef Category                         iterator_category;

      VectorIterator() : _p(NULL) {}
      VectorIterator(pointer p) : _p(p) {}
      VectorIterator (VectorIterator const & src) : _p(src._p) {}
      ~VectorIterator() {}

      pointer base() const { return this->_p; }

      VectorIterator &  operator = ( VectorIterator<Category, const T> const & rhs ) {
        if (this != &rhs) this->_p  = rhs.base();
        return *this;
      }
      VectorIterator  operator + ( difference_type n ) const { return (this->_p + n); }
      VectorIterator  operator - ( difference_type n ) const { return (this->_p - n); }

      VectorIterator &  operator += (difference_type n) {
        this->_p = this->_p + n; return *this;
      }
      VectorIterator &  operator ++ () { ++this->_p; return *this; }
      VectorIterator  operator ++ (int) {
        VectorIterator tmp(*this); this->_p++; return (tmp);
      }

      VectorIterator &  operator -= (difference_type n) {
        this->_p = this->_p - n; return *this;
      }
      VectorIterator &  operator -- () { --this->_p; return *this; }
      VectorIterator  operator -- (int) {
        VectorIterator tmp(*this); this->_p--; return (tmp);
      }

      reference operator * () const { return *(this->_p); }
      pointer operator -> () const { return this->_p; }

      operator  VectorIterator<Category, const value_type>() {
        return VectorIterator<Category, const value_type>(_p);
      }

      reference operator [] (difference_type const & n) { return this->_p[n]; }

      template <class Iterator1, class Iterator2>
      friend bool operator== ( const Iterator1 & lhs, const Iterator2 & rhs);

      template <class Iterator1, class Iterator2>
      friend bool operator!= ( const Iterator1 & lhs, const Iterator2 & rhs);

      template <class Iterator1, class Iterator2>
      friend bool operator< ( const Iterator1 & lhs, const Iterator2 & rhs);

      template <class Iterator1, class Iterator2>
      friend bool operator<= ( const Iterator1 & lhs, const Iterator2 & rhs);

      template <class Iterator1, class Iterator2>
      friend bool operator> ( const Iterator1 & lhs, const Iterator2 & rhs);

      template <class Iterator1, class Iterator2>
      friend bool operator>= ( const Iterator1 & lhs, const Iterator2 & rhs);

      template <class Iterator>
      friend Iterator operator+ (typename Iterator::difference_type n, const Iterator& it);

      template <class Iterator1, class Iterator2>
      friend typename Iterator2::difference_type operator- (const Iterator1& lhs,
        const Iterator2& rhs);

      protected:
        pointer     _p;
	};
}

# include "reverse_iterator.hpp"

#endif /* ********************************************************** ITERATOR_H */