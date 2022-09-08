/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:53:52 by bnaji             #+#    #+#             */
/*   Updated: 2022/09/08 13:37:35 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft {
  template <class Iterator>
	class reverse_iterator
	{
    public:
      typedef Iterator                                                  iterator_type;
      typedef typename iterator_traits<Iterator>::value_type            value_type;
      typedef typename iterator_traits<Iterator>::difference_type       difference_type;
      typedef typename iterator_traits<Iterator>::pointer               pointer;
      typedef typename iterator_traits<Iterator>::reference             reference;
      typedef typename iterator_traits<Iterator>::iterator_category     iterator_category;

      reverse_iterator() : _it(Iterator()) {}
      explicit reverse_iterator (iterator_type it) : _it(it) {}
      template <class Iter>
      reverse_iterator(const reverse_iterator<Iter>& rev_it) : _it(rev_it.base()) {}
      ~reverse_iterator() {}

      iterator_type             base () const { return _it; }

      reverse_iterator  	      operator + ( difference_type n ) const { return reverse_iterator(_it - n); }
      reverse_iterator  	      operator - ( difference_type n ) const { return reverse_iterator(_it + n); }

      reverse_iterator &        operator += (difference_type n) { _it -= n; return *this; }
      reverse_iterator &        operator ++ () { _it--; return *this; }
      reverse_iterator          operator ++ (int) { iterator_type tmp = _it; _it--; return reverse_iterator(tmp); }

      reverse_iterator &        operator -= (difference_type n) { _it += n; return *this; }
      reverse_iterator &        operator -- () { _it++; return *this; }
      reverse_iterator          operator -- (int) { iterator_type tmp = _it; _it++; return reverse_iterator(tmp); }

      reference                 operator * () const { iterator_type tmp = _it; return *(--tmp); }
      pointer                   operator -> () const { return &(operator*()); }

      operator reverse_iterator<const Iterator>() { return reverse_iterator<const Iterator>(this->base()); }

      reference                 operator [] (difference_type n) const { return _it.base()[-n-1]; } 

      private:
        Iterator    _it;
	};
  
  template <class Iterator1, class Iterator2>
  bool operator== ( const reverse_iterator<Iterator1> & lhs,
                    const reverse_iterator<Iterator2> & rhs) { return lhs.base() == rhs.base(); }
  template <class Iterator1, class Iterator2>
  bool operator!= ( const reverse_iterator<Iterator1> & lhs,
                    const reverse_iterator<Iterator2> & rhs) { return lhs.base() != rhs.base(); }
  template <class Iterator1, class Iterator2>
  bool operator<  ( const reverse_iterator<Iterator1> & lhs,
                    const reverse_iterator<Iterator2> &rhs) { return lhs.base() > rhs.base(); }
  template <class Iterator1, class Iterator2>
  bool operator<= ( const reverse_iterator<Iterator1> & lhs,
                    const reverse_iterator<Iterator2> & rhs) { return lhs.base() >= rhs.base(); }
  template <class Iterator1, class Iterator2>
  bool operator>  ( const reverse_iterator<Iterator1> & lhs,
                    const reverse_iterator<Iterator2> & rhs) { return lhs.base() < rhs.base(); }
  template <class Iterator1, class Iterator2>
  bool operator>= ( const reverse_iterator<Iterator1> & lhs,
                    const reverse_iterator<Iterator2> & rhs) { return lhs.base() <= rhs.base(); }
  template <class Iterator>
  reverse_iterator<Iterator> operator+ (
    typename reverse_iterator<Iterator>::difference_type n,
    const reverse_iterator<Iterator>& rev_it) { return (rev_it + n); }

  template <class Iterator1, class Iterator2>
  typename reverse_iterator<Iterator2>::difference_type operator- (
    const reverse_iterator<Iterator1>& lhs,
    const reverse_iterator<Iterator2>& rhs) { return rhs.base() - lhs.base(); }
}

#endif