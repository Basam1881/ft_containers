/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 05:05:32 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/11 17:45:26 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR_HPP
# define MAKE_PAIR_HPP

#include "pair.hpp"

namespace ft {
  template <class T1,class T2>
  ft::pair<T1, T2> make_pair (T1 x, T2 y)
  {
    return ( pair<T1,T2>(x,y) );
  }
}

#endif
