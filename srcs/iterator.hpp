/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:14:34 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/19 02:26:14 by bnaji            ###   ########.fr       */
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
  
  //  template <class it>
  // typename it<ft::random_access_iterator_tag, int>::difference_type operator- (
  //       const it<ft::random_access_iterator_tag, int>& lhs,
  //       const iterator<ft::random_access_iterator_tag, int>& rhs)
  // {
  //   return (lhs._p - rhs._p);
  // }
  
  // template <class Category, class T, class Distance = std::ptrdiff_t,
	//   	class Pointer = T*, class Reference = T&>
	// class const_iterator
  // {
  //   public:
  //       typedef T                                value_type;
  //       typedef Distance                         difference_type;
  //       typedef Pointer                          pointer;
  //       typedef Reference                        reference;
  //       typedef Category                         iterator_category;
        
  //     const_iterator() : _p(NULL) {}
  //     const_iterator(pointer p) : _p(p) {}
  //     const_iterator(const_iterator const & src) : _p(NULL) { *this = src; }
  //     ~const_iterator() {}

  //     pointer                   base() const { return _p; }

  //     const_iterator &          operator = ( const_iterator const & rhs ) { if (this != &rhs) { _p  = rhs._p; } return *this; }
  //     const_iterator            operator + ( difference_type n ) const { return (_p + n); }
  //     const_iterator            operator - ( difference_type n ) const { return (_p - n); }

  //     const_iterator &          operator += (difference_type n) { _p = _p + n; return *this; }
  //     const_iterator &          operator ++ () { ++_p; return *this; }
  //     const_iterator            operator ++ (int) { const_iterator tmp(*this); _p++; return (tmp); }

  //     const_iterator &          operator -= (difference_type n) { _p = _p - n; return *this; }
  //     const_iterator &          operator -- () { --_p; return *this; }
  //     const_iterator            operator -- (int) { const_iterator tmp(*this); _p--; return (tmp); }

  //     bool                    	operator == ( const_iterator const & rhs ) { return (_p == rhs._p); }
  //     bool             	      	operator != ( const_iterator const & rhs ) { return (_p != rhs._p); }
  //     bool             	      	operator >= ( const_iterator const & rhs ) { return (_p >= rhs._p); }
  //     bool             	      	operator <= ( const_iterator const & rhs ) { return (_p <= rhs._p); }
  //     bool             	      	operator > ( const_iterator const & rhs ) { return (_p > rhs._p); }
  //     bool             	      	operator < ( const_iterator const & rhs ) { return (_p < rhs._p); }

  //     reference                 operator * () const { return *(_p); }
  //     pointer                   operator -> () const { return _p; }

  //     reference                 operator [] (difference_type const & n) { return _p[n]; }
  //     // template<class const_iterator>
  //     // friend typename const_iterator<ft::random_access_const_iterator_tag, int>::difference_type operator- (
  //     //   const const_iterator<ft::random_access_const_iterator_tag, int>& lhs,
  //     //   const const_iterator<ft::random_access_const_iterator_tag, int>& rhs);
  //   protected:
  //     pointer     _p;
  // };
  
  template <class Category, class T, class Distance = std::ptrdiff_t,
	  	class Pointer = T*, class Reference = T&>
	class iterator /* : public const_iterator<Category, T> */
	{
    public:
        typedef T                                value_type;
        typedef Distance                         difference_type;
        typedef Pointer                          pointer;
        typedef Reference                        reference;
        typedef Category                         iterator_category;
        
      // iterator() : const_iterator<Category, T>(){}
      // iterator(pointer p) : const_iterator<Category, T>(p) {}
      // iterator(iterator<Category, T> const & src) : const_iterator<Category, T>(src) { *this = src; }
      // iterator(iterator<Category, const T> & src) : const_iterator<Category, T>(src) { *this = src; }
      // ~iterator() {}

      iterator() : _p(NULL) {}
      iterator(pointer p) : _p(p) {}
      // iterator(iterator const & src) : _p(NULL) { *this = src; }
      iterator(iterator<Category, const T> const & src) : _p(NULL) { *this = src; }
      ~iterator() {}

      pointer                   base() const { return this->_p; }
      // pointer                   base() const { return this->_p; }

      // iterator &		            operator = ( iterator const & rhs ) { if (this != &rhs) { this->_p  = rhs._p; } return *this; }
      iterator &		            operator = ( iterator<Category, const T> const & rhs ) { /* if (this != &rhs) */ this->_p  = rhs.base(); return *this; }
      iterator  		            operator + ( difference_type n ) const { return (this->_p + n); }
      iterator  		            operator - ( difference_type n ) const { return (this->_p - n); }

      iterator &                operator += (difference_type n) { this->_p = this->_p + n; return *this; }
      iterator &                operator ++ () { ++this->_p; return *this; }
      iterator                  operator ++ (int) { iterator tmp(*this); this->_p++; return (tmp); }

      iterator &                operator -= (difference_type n) { this->_p = this->_p - n; return *this; }
      iterator &                operator -- () { --this->_p; return *this; }
      iterator                  operator -- (int) { iterator tmp(*this); this->_p--; return (tmp); }

      bool                    	operator == ( iterator const & rhs ) { return (this->_p == rhs._p); }
      bool             	      	operator != ( iterator const & rhs ) { return (this->_p != rhs._p); }
      bool             	      	operator >= ( iterator const & rhs ) { return (this->_p >= rhs._p); }
      bool             	      	operator <= ( iterator const & rhs ) { return (this->_p <= rhs._p); }
      bool             	      	operator > ( iterator const & rhs ) { return (this->_p > rhs._p); }
      bool             	      	operator < ( iterator const & rhs ) { return (this->_p < rhs._p); }

      reference                 operator * () const { return *(this->_p); }
      pointer                   operator -> () const { return this->_p; }

      reference                 operator [] (difference_type const & n) { return this->_p[n]; }
      // template<class iterator>
      // friend typename iterator<ft::random_access_iterator_tag, int>::difference_type operator- (
      //   const iterator<ft::random_access_iterator_tag, int>& lhs,
      //   const iterator<ft::random_access_iterator_tag, int>& rhs);
      private:
        pointer     _p;
	};

  
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