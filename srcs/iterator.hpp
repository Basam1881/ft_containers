/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:14:34 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/15 18:09:46 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include <cstddef>

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
        
      iterator() : _p(NULL) {}
      iterator(pointer p) : _p(p) {}
      iterator(iterator const & src) : _p(NULL) { *this = src; }
      ~iterator() {}

      pointer                   base() const { return _p; }

      iterator &		            operator = ( iterator const & rhs ) { if (this != &rhs) { _p  = rhs._p; } return *this; }
      iterator  		            operator + ( difference_type n ) const { return (_p + n); }
      iterator  		            operator - ( difference_type n ) const { return (_p - n); }

      iterator &                operator += (difference_type n) { _p = _p + n; return *this; }
      iterator &                operator ++ () { ++_p; return *this; }
      iterator                  operator ++ (int) { iterator tmp(*this); _p++; return (tmp); }

      iterator &                operator -= (difference_type n) { _p = _p - n; return *this; }
      iterator &                operator -- () { --_p; return *this; }
      iterator                  operator -- (int) { iterator tmp(*this); _p--; return (tmp); }

      bool                    	operator == ( iterator const & rhs ) { return (_p == rhs._p); }
      bool             	      	operator != ( iterator const & rhs ) { return (_p != rhs._p); }
      bool             	      	operator >= ( iterator const & rhs ) { return (_p >= rhs._p); }
      bool             	      	operator <= ( iterator const & rhs ) { return (_p <= rhs._p); }
      bool             	      	operator > ( iterator const & rhs ) { return (_p > rhs._p); }
      bool             	      	operator < ( iterator const & rhs ) { return (_p < rhs._p); }

      reference                 operator * () const { return *(_p); }
      pointer                   operator -> () const { return _p; }

      reference                 operator [] (difference_type const & n) { return _p[n]; }
      // template<class iterator>
      // friend typename iterator<std::random_access_iterator_tag, int>::difference_type operator- (
      //   const iterator<std::random_access_iterator_tag, int>& lhs,
      //   const iterator<std::random_access_iterator_tag, int>& rhs);
    private:
      pointer     _p;
	};

  // template <class iterator>
  // typename iterator<std::random_access_iterator_tag, int>::difference_type operator- (
  //       const iterator<std::random_access_iterator_tag, int>& lhs,
  //       const iterator<std::random_access_iterator_tag, int>& rhs)
  // {
  //   return (lhs._p - rhs._p);
  // }
  
  
  template <class Category, class T, class Distance = std::ptrdiff_t,
	  	class Pointer = T*, class Reference = T&>
	class reverse_iterator
	{
    public:
        typedef T                                value_type;
        typedef Distance                         difference_type;
        typedef Pointer                          pointer;
        typedef Reference                        reference;
        typedef Category                         iterator_category;
        
      reverse_iterator() : _p(NULL) {}
      reverse_iterator(pointer p) : _p(p) {}
      reverse_iterator(reverse_iterator const & src) : _p(NULL) { *this = src; }
      ~reverse_iterator() {}
      
      pointer                   base() const { return _p; }
      
      reverse_iterator &	      operator = ( reverse_iterator const & rhs ) { if (this != &rhs) { _p  = rhs._p; } return *this; }
      reverse_iterator  	      operator + ( difference_type n ) const { return (_p - n); }
      reverse_iterator  	      operator - ( difference_type n ) const { return (_p + n); }

      reverse_iterator &        operator += (difference_type n) { _p = _p - n; return *this; }
      reverse_iterator &        operator ++ () { --_p; return *this; }
      reverse_iterator          operator ++ (int) { reverse_iterator tmp(*this); _p--; return (tmp); }
      
      reverse_iterator &        operator -= (difference_type n) { _p = _p + n; return *this; }
      reverse_iterator &        operator -- () { ++_p; return *this; }
      reverse_iterator          operator -- (int) { reverse_iterator tmp(*this); _p++; return (tmp); }
      
      bool                    	operator == ( reverse_iterator const & rhs ) { return (_p == rhs._p); }
      bool             	      	operator != ( reverse_iterator const & rhs ) { return (_p != rhs._p); }
      bool             	      	operator >= ( reverse_iterator const & rhs ) { return (_p >= rhs._p); }
      bool             	      	operator <= ( reverse_iterator const & rhs ) { return (_p <= rhs._p); }
      bool             	      	operator > ( reverse_iterator const & rhs ) { return (_p > rhs._p); }
      bool             	      	operator < ( reverse_iterator const & rhs ) { return (_p < rhs._p); }

      reference                 operator * () const { return *(_p); }
      pointer                   operator -> () const { return _p; }

      reference                 operator [] (difference_type n) const { return _p[n]; } 

    private:
      pointer     _p;
	};

  // template <class Iterator>
  // bool operator == (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return ((_p == rhs._p) ? true : false); }

  // template <class Iterator>
  // bool operator != (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return ((_p != rhs._p) ? true : false); }

  // template <class Iterator>
  // bool operator >= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return ((_p >= rhs._p) ? true : false); }

  // template <class Iterator>
  // bool operator <= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return ((_p <= rhs._p) ? true : false); }

  // template <class Iterator>
  // bool operator > (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return ((_p > rhs._p) ? true : false); }

  // template <class Iterator>
  // bool operator < (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return ((_p < rhs._p) ? true : false); }
  
  // template <class Iterator>
  // reverse_iterator<Iterator> operator + (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) { return (n + rev_it); }
  
  // template <class Iterator>
  // typename reverse_iterator<Iterator>::difference_type operator - (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs - rhs); }

}

#endif /* ********************************************************** ITERATOR_H */