/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_relational_operators.hpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 08:04:23 by bnaji             #+#    #+#             */
/*   Updated: 2022/09/09 11:54:23 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_RELATIONAL_OPERATORS_HPP
# define ITERATOR_RELATIONAL_OPERATORS_HPP

namespace ft {
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

  template <class Iterator1, class Iterator2>
  typename Iterator2::difference_type operator- (const Iterator1& lhs,
             const Iterator2& rhs) { return lhs.base() - rhs.base(); }
}

#endif 