/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valueComapre.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 08:40:58 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/20 14:10:06 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALUE_COMPARE_HPP
# define VALUE_COMPARE_HPP

#include "map.hpp"

namespace ft {
  template <class Key, class T, class Compare, class Alloc>
  class ft::map<Key,T,Compare,Alloc>::value_compare
  {
    friend class map;
    protected:
      Compare comp;
      value_compare (Compare c) : comp(c) {}
    public:
      typedef bool result_type;
      typedef value_type first_argument_type;
      typedef value_type second_argument_type;
      bool operator() (const value_type& x, const value_type& y) const {
        return comp(x.first, y.first);
      }
  };
}

#endif