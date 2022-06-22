/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:26:56 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/22 18:40:03 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COPY_HPP
# define COPY_HPP

# include <iostream>
# include <string>
# include <memory>
# include <cstddef>
# include "iterator.hpp"

namespace ft
{
  template<class InputIterator, class OutputIterator>
    OutputIterator copy (InputIterator first, InputIterator last, OutputIterator result)
  {
    while (first!=last) { *result++ = *first++; }
    return result;
  }
  
  template<class InputIterator, class OutputIterator, class T>
    OutputIterator copy (InputIterator first, InputIterator last, OutputIterator result, std::allocator<T> alloc)
  {
    while (first!=last) { alloc.construct(result.base(), *first);  result++; first++; }
    return result;
  }
}

#endif /* ********************************************************** COPY_H */

