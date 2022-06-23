/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:59:53 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/23 09:56:01 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <memory>
# include "vector.hpp"

namespace ft {
  
  /* ************************************** Constructors ************************************** */
  template < class T, class Alloc>
  vector<T, Alloc> &		vector<T, Alloc>::operator=( vector<T, Alloc> const & rhs )
  {
    if (this != &rhs)
    {
      if (rhs._capacity > _capacity)
      {
        for (size_type i = 0; i != _size ; i++)
          _alloc.destroy(_arr + i);
        if (_capacity)
          _alloc.deallocate(_arr, _size);
        _arr = _alloc.allocate(rhs._capacity);        
        for (size_type i = 0; i < rhs._size; i++) 
          _alloc.construct(_arr + i, rhs._arr[i]);
        _capacity = rhs._capacity;
      }
      else
      {
        size_type i = 0;
        for ( ; i < rhs._size; i++) {
          _arr[i] = rhs._arr[i];
        }
      }
      _size = rhs._size;
    }
    return *this;
  }

  
  /* ************************************** Iterators ************************************** */
  template < class T, class Alloc>
  typename vector<T, Alloc>::iterator					        	vector<T, Alloc>::begin() { 
    return iterator(_arr);
  }
  
  template < class T, class Alloc>
  typename vector<T, Alloc>::const_iterator 		        	vector<T, Alloc>::begin() const { return const_iterator(_arr); }
  
  template < class T, class Alloc>
  typename vector<T, Alloc>::iterator					        	vector<T, Alloc>::end() { return iterator(_arr + _size); }
  
  template < class T, class Alloc>
  typename vector<T, Alloc>::const_iterator 		        	vector<T, Alloc>::end() const { return const_iterator(_arr + _size); }
  
  template < class T, class Alloc>
  typename vector<T, Alloc>::reverse_iterator						vector<T, Alloc>::rbegin() { return reverse_iterator(_arr + _size - 1); }
  
  template < class T, class Alloc>
  typename vector<T, Alloc>::const_reverse_iterator 			vector<T, Alloc>::rbegin() const { return const_reverse_iterator(_arr + _size - 1); }
  
  template < class T, class Alloc>
  typename vector<T, Alloc>::reverse_iterator						vector<T, Alloc>::rend() { return reverse_iterator(_arr - 1); }
  
  template < class T, class Alloc>
  typename vector<T, Alloc>::const_reverse_iterator 			vector<T, Alloc>::rend() const { return const_reverse_iterator(_arr - 1); }
  
  

  /* ************************************** Element Access ************************************** */
  template < class T, class Alloc>
  typename vector<T, Alloc>::reference vector<T, Alloc>::operator[] (size_type n) { return _arr[n]; }
  
  template < class T, class Alloc>
  typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[] (size_type n) const { return _arr[n]; }
  
  template < class T, class Alloc>
  typename vector<T, Alloc>::reference vector<T, Alloc>::at (size_type n) { if (n >= _size) throw std::out_of_range("ft_vector\n"); return _arr[n]; }
  
  template < class T, class Alloc>
  typename vector<T, Alloc>::const_reference vector<T, Alloc>::at (size_type n) const { if (n >= _size) throw std::out_of_range("ft_vector\n"); return _arr[n]; }
  
  template < class T, class Alloc>
  typename vector<T, Alloc>::reference vector<T, Alloc>::front() { return *_arr; }
  
  template < class T, class Alloc>
  typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const { return *_arr; }
  
  template < class T, class Alloc>
  typename vector<T, Alloc>::reference vector<T, Alloc>::back() { return *(_arr + size() - 1); }
  
  template < class T, class Alloc>
  typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const { return *(_arr + size() - 1); }
  
  template < class T, class Alloc>
  typename vector<T, Alloc>::pointer vector<T, Alloc>::data() { return _arr; }
  
  template < class T, class Alloc>
  typename vector<T, Alloc>::const_pointer vector<T, Alloc>::data() const { return _arr; }
  


  /* ************************************** Capacity ************************************** */
  template < class T, class Alloc>
  typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const { return _size; }
  
  template < class T, class Alloc>
  typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const { return (size_t)(-1) / (sizeof(T)/*  * 2 */); }
  
  template < class T, class Alloc>
  typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const { return _capacity; }
  
  template < class T, class Alloc>
  bool      vector<T, Alloc>::empty() const { return (_size == 0); }
  
  template < class T, class Alloc>
  void      vector<T, Alloc>::resize(size_type n, value_type val)
  {
    size_type i = _size;
    if (n <= _size) {
      i--;
      for ( ; i > n; i--)
        _alloc.construct(_arr + i, val);
    }
    else {
      if (n > _capacity)
        reserve(n);
      for ( ; i < n; i++)
        _alloc.construct(_arr + i, val);
    }
    _size = n;
  }
  
  template < class T, class Alloc>
  void vector<T, Alloc>::reserve (size_type n)
  {
    if (n > _capacity) {
      vector tmp(*this);
      clearMe(*this);
      allocMe(*this, n, tmp.begin(), tmp.end());
      _capacity = n;
    }
  }
  
  
}
