/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_backward.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:11:53 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/02 07:45:19 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COPY_BACKWARD_HPP
# define COPY_BACKWARD_HPP

# include <iostream>
# include <string>
# include <memory>
# include <cstddef>

namespace ft
{
  template<class BidirectionalIterator1, class BidirectionalIterator2>
  BidirectionalIterator2 copy_backward ( BidirectionalIterator1 first, BidirectionalIterator1 last, BidirectionalIterator2 result )
  {
    while (last!=first) *(--result) = *(--last);
    return result;
  }
}

#endif /* ********************************************************** COPY_BACKWARD_H */
