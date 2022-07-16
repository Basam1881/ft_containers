/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:59:53 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/16 13:17:45 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <memory>
# include "vector.hpp"

namespace ft {
  
  /* ************************************** Constructors ************************************** */
  template < class T, class Alloc>
  inline vector<T, Alloc> &   vector<T, Alloc>::operator=( vector<T, Alloc> const & rhs ) {
    if (this != &rhs)
    {
      if (rhs._capacity > _capacity)
        reallocMe(*this, rhs._capacity, rhs.begin(), rhs.end());
      else
        ft::copy(rhs.begin(), rhs.end(), begin(), _alloc);
      _size = rhs._size;
    }
    return *this;
  }


  /* ************************************** Iterators ************************************** */
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::iterator                  vector<T, Alloc>::begin() { 
    return iterator(_arr);
  }
  
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::const_iterator            vector<T, Alloc>::begin() const {
    return const_iterator(_arr);
  }
  
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::iterator                  vector<T, Alloc>::end() {
    return iterator(_arr + _size);
  }
  
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::const_iterator            vector<T, Alloc>::end() const {
    return const_iterator(_arr + _size);
  }
  
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::reverse_iterator          vector<T, Alloc>::rbegin() {
    return reverse_iterator(_arr + _size - 1);
  }
  
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::const_reverse_iterator    vector<T, Alloc>::rbegin() const {
    return const_reverse_iterator(_arr + _size - 1);
  }
  
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::reverse_iterator          vector<T, Alloc>::rend() {
    return reverse_iterator(_arr - 1);
  }
  
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::const_reverse_iterator    vector<T, Alloc>::rend() const {
    return const_reverse_iterator(_arr - 1);
  }
  
  

  /* ************************************** Element Access ************************************** */
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::reference             vector<T, Alloc>::operator[](size_type n) {
    return _arr[n];
  }
  
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::const_reference       vector<T, Alloc>::operator[](size_type n) const {
    return _arr[n];
  }

  template < class T, class Alloc>
  inline typename vector<T, Alloc>::reference             vector<T, Alloc>::at(size_type n) {
    std::ostringstream str;
    str << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << _size << ")";
    if (n >= _size) throw std::out_of_range(str.str());
    return _arr[n];
  }
  
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::const_reference       vector<T, Alloc>::at(size_type n) const {
    std::ostringstream str;
    str << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << _size << ")";
    if (n >= _size) throw std::out_of_range(str.str());
    return _arr[n];
  }
  
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::reference             vector<T, Alloc>::front() {
    return *_arr;
  }
  
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::const_reference       vector<T, Alloc>::front() const {
    return *_arr;
  }
  
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::reference             vector<T, Alloc>::back() {
    return *(_arr + size() - 1);
  }
  
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::const_reference       vector<T, Alloc>::back() const {
    return *(_arr + size() - 1);
  }
  
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::pointer               vector<T, Alloc>::data() {
    return _arr;
  }
  
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::const_pointer         vector<T, Alloc>::data() const {
    return _arr;
  }
  


  /* ************************************** Capacity ************************************** */
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::size_type    vector<T, Alloc>::size() const {
    return _size;
  }
  
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::size_type    vector<T, Alloc>::max_size() const {
    return (size_t)(-1) / sizeof(T);
  }
  
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::size_type    vector<T, Alloc>::capacity() const {
    return _capacity;
  }
  
  template < class T, class Alloc>
  inline bool                                    vector<T, Alloc>::empty() const {
    return (_size == 0);
  }
  
  template < class T, class Alloc>
  inline void                                    vector<T, Alloc>::resize(size_type n, value_type val) {
    checkIfValid(*this, n, "vector::_M_fill_insert");
    if (n <= _size)
      ft::copy(begin() + n, _size - n, val, _alloc);
    else {
      if (n > _capacity)
        reserve(n);
      ft::copy(end(), n - _size, val, _alloc);
    }
    _size = n;
  }
  
  template < class T, class Alloc>
  inline void                                    vector<T, Alloc>::reserve (size_type n) {
    checkIfValid(*this, n, "vector::reserve");
    if (n > _capacity) {
      vector tmp(*this);
      reallocMe(*this, n, tmp.begin(), tmp.end());
    }
  }
  

  /* ************************************** Modifiers ************************************** */
  template < class T, class Alloc>
  template <class InputIterator>
  inline void             vector<T, Alloc>::assign (InputIterator first, InputIterator last) {
    size_type n = ft::distance(first, last);
    n > _capacity ? reallocMe(*this, n, first, last) : replace(*this, n, first);
    _size = n;
  }
  template < class T, class Alloc>
  inline void             vector<T, Alloc>::assign (typename vector<T, Alloc>::size_type n, const typename vector<T, Alloc>::value_type& val) {
    checkIfValid(*this, n, "cannot create std::vector larger than max_size()");
    n > _capacity ? reallocMe(*this, n, val) : replace(*this, n, val);
    _size = n;
  }

  template < class T, class Alloc>
  inline void             vector<T, Alloc>::push_back (const typename vector<T, Alloc>::value_type& val) {
    checkAndReserve(*this, 1, _capacity * 2);
    _alloc.construct(_arr + _size++, val);
  }

  template < class T, class Alloc>
  inline void             vector<T, Alloc>::pop_back() {
    _alloc.destroy(_arr + _size-- - 1);
  }

  template < class T, class Alloc>
  inline typename vector<T, Alloc>::iterator             vector<T, Alloc>::insert (typename vector<T, Alloc>::iterator position, const typename vector<T, Alloc>::value_type& val) {
    if (_size == _capacity)
      position = storePositionAndReserve(*this, position, 1, _capacity * 2);
    _size++;
    ft::copy_backward(position, end() - 1, end());
    *position = val;
    return position;
  }

  template < class T, class Alloc>
  inline void             vector<T, Alloc>::insert (typename vector<T, Alloc>::iterator position, typename vector<T, Alloc>::size_type n, const typename vector<T, Alloc>::value_type& val) {
    isValidInsert(_size + n);
    size_type oldEnd = _size;
    if (_size + n > _capacity)
      position = storePositionAndReserve(*this, position, _size + n, _size + n);
    _size += n;
    ft::copy_backward(position, begin() + oldEnd, end());
    for (size_type i = 0; i < n; i++)
      *position++ = val;
  }

  template < class T, class Alloc>
  template <class InputIterator>
  inline void             vector<T, Alloc>::insert (typename vector<T, Alloc>::iterator position, InputIterator first, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last) {
    size_type toPos = ft::distance(begin(), position);
    bool exist = isIteratorInVector(*this, first);
    size_type size = ft::distance(first, last);
    size_type toFirst;
    if (exist)
      toFirst = ft::distance(begin(), first);
    insert(position, size, value_type());
    if (exist)
      ft::copy(begin() + toFirst, begin() + toFirst + size, begin() + toPos);
    else
      ft::copy(first, last, begin() + toPos);
  }
  
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::iterator            vector<T, Alloc>::erase (typename vector<T, Alloc>::iterator position) {
    return erase(position, position + 1);
  }
  
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::iterator            vector<T, Alloc>::erase (typename vector<T, Alloc>::iterator first, typename vector<T, Alloc>::iterator last) {
    size_type size = ft::distance(first, last);
    ft::copy(last, end(), first);
    for (size_type i = 0; i < size; i++)
      _alloc.destroy(_arr + _size - i);
    _size -= size;
    return last;
  }

  template < class T, class Alloc>
  inline void              vector<T, Alloc>::swap(vector<T, Alloc> & x) {
    allocator_type  tmpAlloc = x._alloc;
    pointer					tmpArr = x._arr;
    size_type				tmpSize = x._size;
    size_type				tmpCapacity = x._capacity;

    x._alloc = _alloc;
    x._arr = _arr;
    x._size = _size;
    x._capacity = _capacity;

    _alloc = tmpAlloc;
    _arr = tmpArr;
    _size = tmpSize;
    _capacity = tmpCapacity;
  }
  
  template < class T, class Alloc>
  inline void              vector<T, Alloc>::clear() {
    for (size_type i = _size; i > 0; i--, _size--)
      _alloc.destroy(_arr + i);
  }
  
  /* ************************************** Allocator ************************************** */
  template < class T, class Alloc>
  inline typename vector<T, Alloc>::allocator_type             vector<T, Alloc>::get_allocator() const { return _alloc; }

  
  /* ************************************** Vector utils ************************************** */
  template < class T, class Alloc>
  inline void                     vector<T, Alloc>::allocMe(vector<T, Alloc> & v, typename vector<T, Alloc>::size_type & n, const typename vector<T, Alloc>::value_type & val) {
    if (n)
      _arr = _alloc.allocate(n);
    for (size_t i = 0; i < n; i++)
      v.get_allocator().construct(v.begin().base() + i, val);
  }

  template < class T, class Alloc>
  inline void                     vector<T, Alloc>::allocMe(vector<T, Alloc> & v, typename vector<T, Alloc>::size_type & n, typename vector<T, Alloc>::iterator first, typename vector<T, Alloc>::iterator last) {
    if (n) 
      v._arr = v.get_allocator().allocate(n);
    ft::copy(first, last, v.begin(), v.get_allocator());
  }

  template < class T, class Alloc>
  inline void                     vector<T, Alloc>::allocMe(vector<T, Alloc> & v, typename vector<T, Alloc>::size_type const & n, typename vector<T, Alloc>::const_iterator first, typename vector<T, Alloc>::const_iterator last) {
    if (n) 
      v._arr = v.get_allocator().allocate(n);
    ft::copy(first, last, v.begin(), v.get_allocator());
  }

  template < class T, class Alloc>
  inline void                   vector<T, Alloc>::clearMe(vector<T, Alloc> & v) {
    for (iterator it = v.begin(); it != v.end(); it++)
      v._alloc.destroy(it.base());
    v._alloc.deallocate(v.begin().base(), v.capacity());
  }

  template < class T, class Alloc>
  inline void                   vector<T, Alloc>::reallocMe(vector<T, Alloc> & v, typename vector<T, Alloc>::size_type & n, typename vector<T, Alloc>::value_type const & val) {
    clearMe(v);
    allocMe(v, n, val);
    v._capacity = n;
  }

  template < class T, class Alloc>
  inline void                   vector<T, Alloc>::reallocMe(vector<T, Alloc> & v, typename vector<T, Alloc>::size_type & n, typename vector<T, Alloc>::iterator first, typename vector<T, Alloc>::iterator last) {
    clearMe(v);
    allocMe(v, n, first, last);
    v._capacity = n;
  }

  template < class T, class Alloc>
  inline void                   vector<T, Alloc>::reallocMe(vector<T, Alloc> & v, typename vector<T, Alloc>::size_type const & n, typename vector<T, Alloc>::const_iterator first, typename vector<T, Alloc>::const_iterator last) {
    clearMe(v);
    allocMe(v, n, first, last);
    v._capacity = n;
  }
  
  template < class T, class Alloc>
  inline void                     vector<T, Alloc>::replace(vector<T, Alloc> & v, typename vector<T, Alloc>::size_type & n, typename vector<T, Alloc>::iterator & first) {
    for (size_type i = 0; i < v._capacity; i++) {
      v._alloc.destroy(v._arr + i);
      if (i < n) {
        v._alloc.construct(v._arr + i, *first);
        first++;              
      }
    }
  }

  template < class T, class Alloc>
  inline void                     vector<T, Alloc>::replace(vector<T, Alloc> & v, typename vector<T, Alloc>::size_type n, const typename vector<T, Alloc>::value_type& val) {
    for (size_type i = 0; i < v._capacity; i++) {
      v._alloc.destroy(v._arr + i);
      if (i < n)
        v._alloc.construct(v._arr + i, val);
    }
  }

  template < class T, class Alloc>
  inline void                     vector<T, Alloc>::checkAndReserve(vector<T, Alloc> & v, typename vector<T, Alloc>::size_type m, typename vector<T, Alloc>::size_type n) {
    if (!v._capacity)
      v.reserve(m);
    else if (v._size == v._capacity)
      v.reserve(n);
  }
  
  template < class T, class Alloc>
  inline void                   vector<T, Alloc>::isValidInsert(typename vector<T, Alloc>::size_type n) {
    checkIfValid(*this, n, "vector::_M_fill_insert");
    pointer tmp = _alloc.allocate(_size + n);
    _alloc.deallocate(tmp, _size + n);
  }

  template < class T, class Alloc>
  inline typename vector<T, Alloc>::iterator                     vector<T, Alloc>::storePositionAndReserve(vector<T, Alloc> & v, typename vector<T, Alloc>::iterator & position, typename vector<T, Alloc>::size_type reserveSize1, typename vector<T, Alloc>::size_type reserveSize2) {
    size_type i = ft::distance(v.begin(), position);
    checkAndReserve(v, reserveSize1, reserveSize2);
    return (begin() + i);
  }

  template < class T, class Alloc>
  inline bool                   vector<T, Alloc>::isIteratorInVector(vector<T, Alloc> & v, typename vector<T, Alloc>::iterator & iter) {
    for (iterator it = v.begin(); it != v.end(); it++)
      if (it == iter)
        return true;
    return false;
  }

  template < class T, class Alloc>
  inline void                        vector<T, Alloc>::checkIfValid(vector<T, Alloc> & v, vector<T, Alloc>::size_type & n, std::string str) {
    if (n > v.max_size())
      throw std::length_error(str);
    pointer tmp = v._alloc.allocate(n);
    v._alloc.deallocate(tmp, n);
  }


  /* ************************************** Non-Member Function Overloads ************************************** */
  template <class T, class Alloc>
  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
    x.swap(y);
  }

  template <class T, class Alloc>
  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    if (lhs.size() != rhs.size()) return false;
    return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
  }

  template <class T, class Alloc>
  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    return !(lhs == rhs);  
  }

  template <class T, class Alloc>
  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
  }

  template <class T, class Alloc>
  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    return !(rhs < lhs);
  }

  template <class T, class Alloc>
  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    return rhs < lhs;
  }

  template <class T, class Alloc>
  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    return !(lhs < rhs);
  }
  
}
