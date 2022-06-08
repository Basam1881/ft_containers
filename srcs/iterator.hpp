/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:14:34 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/05 14:44:35 by bnaji            ###   ########.fr       */
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
  template <class Category, class T, class Distance = std::ptrdiff_t,
	  	class Pointer = T*, class Reference = T&>
	class iterator
	{
    public:
        typedef T                                value_type;
        typedef Distance                         difference_type;
        typedef Pointer                          pointer;
        typedef Reference                        reference;
        typedef std::random_access_iterator_tag  iterator_category;
        
      iterator() : _p(NULL) {}
      iterator(iterator const & src) : _p(NULL) { *this = src; }
      ~iterator() {}
      
      pointer                  base() const { return _p; }
      
      iterator &		            operator = ( iterator const & rhs ) { if (this != &rhs) { _p  = rhs._p; } return this; }
      iterator  		            operator + ( difference_type const & n ) const { reutrn (_p + n); }
      iterator  		            operator - ( difference_type const & n ) const { reutrn (_p - n); }

      iterator &                operator += (difference_type const & n) { _p = _p + n; return *this; }
      iterator &                operator ++ () { ++_p; return *this; }
      iterator                  operator ++ (difference_type) { iterator tmp(*this); _p++; return (tmp); }
      
      iterator &                operator -= (difference_type const & n) { _p = _p - n; return *this; }
      iterator &                operator -- () { --_p; return *this; }
      iterator                  operator -- (difference_type) { iterator tmp(*this); _p--; return (tmp); }
      
      bool                    	operator == ( iterator const & rhs ) { return ((_p == rhs._p) ? true : false); }
      bool             	      	operator != ( iterator const & rhs ) { return ((_p != rhs._p) ? true : false); }
      bool             	      	operator >= ( iterator const & rhs ) { return ((_p >= rhs._p) ? true : false); }
      bool             	      	operator <= ( iterator const & rhs ) { return ((_p <= rhs._p) ? true : false); }
      bool             	      	operator > ( iterator const & rhs ) { return ((_p > rhs._p) ? true : false); }
      bool             	      	operator < ( iterator const & rhs ) { return ((_p < rhs._p) ? true : false); }

      reference                 operator * () { return *(_p); }
      reference const           operator * () const { return *(_p); }
      pointer                   operator -> () { return _p; }

      reference                 operator [] (difference_type const & n) { return _p[n]; } 
      reference const           operator [] (difference_type const & n) const { return _p[n]; }

    private:
      pointer     _p;
	};

  
  // template <class Category, class T, class Distance = std::ptrdiff_t,
	//   	class Pointer = T*, class Reference = T&>
	// class reverse_iterator
	// {
  //   public:
  //       typedef T                                value_type;
  //       typedef Distance                         difference_type;
  //       typedef Pointer                          pointer;
  //       typedef Reference                        reference;
  //       typedef std::random_access_iterator_tag  iterator_category;
        
  //     reverse_iterator() : _p(NULL) {}
  //     reverse_iterator(reverse_iterator(); const & src) : _p(NULL) { *this = src; }
  //     ~reverse_iterator() {}
      
  //     pointer                  base() const { return _p; }
      
  //     iterator &		            operator = ( iterator const & rhs ) { if (this != &rhs) { _p  = rhs._p; } return this; }
  //     iterator  		            operator + ( difference_type const & n ) const { reutrn (_p + n); }
  //     iterator  		            operator - ( difference_type const & n ) const { reutrn (_p - n); }

  //     iterator &                operator += (difference_type const & n) { _p = _p + n; return *this; }
  //     iterator &                operator ++ () { ++_p; return *this; }
  //     iterator                  operator ++ (int) { if (_p) { iterator tmp(*this); _p++; return (tmp); } }
      
  //     iterator &                operator -= (difference_type const & n) { _p = _p - n; return *this; }
  //     iterator &                operator -- () { --_p; return *this; }
  //     iterator                  operator -- (int) { if (_p) { iterator tmp(*this); _p--; return (tmp); } }
      
  //     bool                    	operator == ( iterator const & rhs ) { return ((_p == rhs._p) ? true : false); }
  //     bool             	      	operator != ( iterator const & rhs ) { return ((_p != rhs._p) ? true : false); }
  //     bool             	      	operator >= ( iterator const & rhs ) { return ((_p >= rhs._p) ? true : false); }
  //     bool             	      	operator <= ( iterator const & rhs ) { return ((_p <= rhs._p) ? true : false); }
  //     bool             	      	operator > ( iterator const & rhs ) { return ((_p > rhs._p) ? true : false); }
  //     bool             	      	operator < ( iterator const & rhs ) { return ((_p < rhs._p) ? true : false); }

  //     reference                 operator * () { return *(_p); }
  //     reference const           operator * () const { return *(_p); }
  //     pointer                   operator -> () { return _p; }

  //     reference                 operator [] (difference_type const & n) { return _p[n]; } 
  //     reference const           operator [] (difference_type const & n) const { return _p[n]; }

  //   private:
  //     pointer     _p;
	// };

  
}

#endif /* ********************************************************** ITERATOR_H */