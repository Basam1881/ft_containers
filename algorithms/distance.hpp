/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:02:46 by bnaji             #+#    #+#             */
/*   Updated: 2022/08/29 18:44:00 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISTANCE_HPP
# define DISTANCE_HPP

# include <iostream>
# include <string>
# include <memory>
# include <cstddef>
# include "../iterators/vectorIterator.hpp"

namespace ft
{
  template<class RandomAccessIterator>
  typename iterator_traits<RandomAccessIterator>::difference_type
  distance (RandomAccessIterator first, RandomAccessIterator last,  ft::random_access_iterator_tag)
  {
    return last.base() - first.base();
  }
  
  template<class RandomAccessIterator>
  typename iterator_traits<RandomAccessIterator>::difference_type
  distance (RandomAccessIterator first, RandomAccessIterator last,  std::random_access_iterator_tag)
  {
    return last.base() - first.base();
  }

  template<class InputIterator>
  typename iterator_traits<InputIterator>::difference_type
  distance (InputIterator first, InputIterator last, ft::input_iterator_tag)
  {
    typename iterator_traits<InputIterator>::difference_type diff;
    for(diff = 0; first != last; first++, diff++);
    return diff;
  }

  template<class InputIterator>
  typename iterator_traits<InputIterator>::difference_type
  distance (InputIterator first, InputIterator last, std::input_iterator_tag)
  {
    typename iterator_traits<InputIterator>::difference_type diff;
    for(diff = 0; first != last; first++, diff++);
    return diff;
  }
  
  template<class Iterator>
  typename iterator_traits<Iterator>::difference_type
  distance (Iterator first, Iterator last)
  {
    // typename iterator_traits<Iterator>::difference_type diff;
    // for(diff = 0; first != last; first++, diff++);
    // return diff;
    return (distance(first, last, typename iterator_traits<Iterator>::iterator_category()));
  }
}

#endif /* ********************************************************** DISTANCE_H */