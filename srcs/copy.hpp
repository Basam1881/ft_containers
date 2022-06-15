/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:26:56 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/14 17:28:13 by bnaji            ###   ########.fr       */
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
    while (first!=last) {
      *result = *first;
      ++result; ++first;
    }
    return result;
  }
}

#endif /* ********************************************************** COPY_H */

