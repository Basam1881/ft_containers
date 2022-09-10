/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 09:09:48 by bnaji             #+#    #+#             */
/*   Updated: 2022/09/10 18:24:20 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

namespace ft {
  
  /* ************************************** Constructors ************************************** */
  template < class Key, class T, class Compare, class Alloc>
  inline map<Key, T, Compare, Alloc>& map<Key, T, Compare, Alloc>::operator= (const map<Key, T,
    Compare, Alloc>& x) {
    if (this != &x) {
      clear();
      insert(x.begin(), x.end());
      _alloc = x._alloc;
      _avlAlloc = x._avlAlloc;
      _comp = x._comp;
    }
    return *this;
  }


  /* ************************************** Iterators ************************************** */
  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::iterator
      map<Key, T, Compare, Alloc>::begin() {
    return !_size ? end() : iterator(_root->getLowestKey(_root), _uselessEnd, _root);
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::const_iterator
      map<Key, T, Compare, Alloc>::begin() const {
    return !_size ? end() : const_iterator(_root->getLowestKey(_root), _uselessEnd, _root);
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::iterator
      map<Key, T, Compare, Alloc>::end() {
    return iterator(_uselessEnd, _uselessEnd, _root);
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::const_iterator
      map<Key, T, Compare, Alloc>::end() const {
    return const_iterator(_uselessEnd, _uselessEnd, _root);
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::reverse_iterator
      map<Key, T, Compare, Alloc>::rbegin() {
    return reverse_iterator(end());
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::const_reverse_iterator
      map<Key, T, Compare, Alloc>::rbegin() const {;
    return const_reverse_iterator(end());
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::reverse_iterator
      map<Key, T, Compare, Alloc>::rend() {
    return reverse_iterator(begin());    
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::const_reverse_iterator
      map<Key, T, Compare, Alloc>::rend() const {
    return const_reverse_iterator(begin());
  }

  /* ************************************** Capacity ************************************** */
  template<class Key, class T, class Compare, class Alloc>
  inline bool   map<Key, T, Compare, Alloc>::empty() const {
    return _size == 0;
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::size_type
      map<Key, T, Compare, Alloc>::size() const {
    return _size;
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::size_type
      map<Key, T, Compare, Alloc>::max_size() const {
    return std::numeric_limits<size_type>::max() / (sizeof(avl_type *)) * 2 / 10;
  }


  /* ************************************** Element Access ************************************** */
  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::mapped_type&
      map<Key, T, Compare, Alloc>::operator[] (const typename map<Key, T,
      Compare, Alloc>::key_type& k) {
    avl_type * tmp = _root->search(_root, k);
    if (!tmp) {
      _root = _root->insert(_root, value_type(k, mapped_type()));
      _size++;
      tmp = _root->search(_root, k);
    }
    return tmp->getPair().second;
  }
  
  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::mapped_type&
      map<Key, T, Compare, Alloc>::at (const typename map<Key, T, Compare, Alloc>::key_type& k) {
    avl_type * tmp = _root->search(_root, k);
    std::ostringstream str;
    str << "map::_M_range_check: __n (which is " << k << ") >= this->size() (which is "
      << _size << ")";
    if (!tmp) throw std::out_of_range(str.str());
    return tmp->getPair().second;
  }

  template<class Key, class T, class Compare, class Alloc>
  inline const typename map<Key, T, Compare, Alloc>::mapped_type&
      map<Key, T, Compare, Alloc>::at (const typename map<Key, T,
      Compare, Alloc>::key_type& k) const {
    avl_type * tmp = _root->search(_root, k);
    std::ostringstream str;
    str << "map::_M_range_check: __n (which is " << k << ") >= this->size() (which is "
      << _size << ")";
    if (!tmp) throw std::out_of_range(str.str());
    return tmp->getPair().second;
  }


  /* ************************************** Modifiers ************************************** */
  template<class Key, class T, class Compare, class Alloc>
  inline ft::pair<typename map<Key, T, Compare, Alloc>::iterator, bool>
      map<Key, T, Compare, Alloc>::insert (const typename map<Key, T,
      Compare, Alloc>::value_type& val) {
    avl_type * tmp = _root->search(_root, val.first);
    if (!tmp) {
      _root = _root->insert(_root, val);
      _size++;
      return ft::pair<iterator, bool>(iterator(_root
        ->search(_root, val.first), _uselessEnd, _root), true);
    }
    return ft::pair<iterator, bool>(iterator(tmp, _uselessEnd, _root), false);
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::iterator
      map<Key, T, Compare, Alloc>::insert (iterator position, const value_type& val) {
    (void)position;
    return insert(val).first;
  }

  template<class Key, class T, class Compare, class Alloc>
  template <class InputIterator>
  inline void   map<Key, T, Compare, Alloc>::insert (InputIterator first, InputIterator last) {
    for ( ; first != last; first++)
      insert(*first);
  }

  template<class Key, class T, class Compare , class Alloc>
  inline void   map<Key, T, Compare, Alloc>::erase (map<Key, T,
      Compare, Alloc>::iterator position) {
    erase(position->first);
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::size_type
      map<Key, T, Compare, Alloc>::erase (const typename map<Key, T, Compare, Alloc>::key_type& k) {
    if (_root->search(_root, k))
      _size--;
    else
      return 0;
    _root = _root->erase(_root, k);
    if (!_size)
      _root = NULL;
    return 1;
  }

  template<class Key, class T, class Compare, class Alloc>
  inline void map<Key, T, Compare, Alloc>::erase (map<Key, T,
      Compare, Alloc>::iterator first, map<Key, T, Compare, Alloc>::iterator last) {
    iterator it;
    size_type count = 0, keyIndex = 0;

    if (!_size || first == last)
      return ;
    for (it = first; it != last; it++, count++);
    key_type * keys = _keyAlloc.allocate(count);

    for (it = first; it != last; it++, keyIndex++)
      _keyAlloc.construct(keys + keyIndex, it->first);
    for (size_type cnt = 0; cnt < count; cnt++)
      erase(keys[cnt]);
    _keyAlloc.destroy(keys);
    _keyAlloc.deallocate(keys, count);
  }

  template<class Key, class T, class Compare, class Alloc>
  inline void map<Key, T, Compare, Alloc>::swap (map& x) {
    avl_type *            tmpRoot = _root;
    size_type             tmpSize = _size;
    key_compare           tmpComp = _comp;
    allocator_type        tmpAlloc = _alloc;

    _root = x._root;
    _size = x._size;
    _comp = x._comp;
    _alloc = x._alloc;

    x._root = tmpRoot;
    x._size = tmpSize;
    x._comp = tmpComp;
    x._alloc = tmpAlloc;
  }

  template<class Key, class T, class Compare, class Alloc>
  inline void map<Key, T, Compare, Alloc>::clear() {
    if (_size)
      erase(begin(), end());
  }


  /* ************************************** Observers ************************************** */
  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::key_compare
      map<Key, T, Compare, Alloc>::key_comp() const { return _comp; }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::value_compare
      map<Key, T, Compare, Alloc>::value_comp() const { return value_compare(); }


  /* ************************************** Operations ************************************** */
  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::iterator
      map<Key, T, Compare, Alloc>::find (const typename map<Key, T, Compare, Alloc>::key_type& k) {
    avl_type * tmp = _root->search(_root, k);
    if (tmp)
      return iterator(tmp, _uselessEnd, _root);
    return end();
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::const_iterator
      map<Key, T, Compare, Alloc>::find (const typename map<Key, T,
      Compare, Alloc>::key_type& k) const {
    avl_type * tmp = _root->search(_root, k);
    if (tmp)
      return iterator(tmp, _uselessEnd, _root);
    return end();
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::size_type
      map<Key, T, Compare, Alloc>::count (const typename map<Key, T,
      Compare, Alloc>::key_type& k) const {
    return _root->search(_root, k) != NULL;
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::iterator
      map<Key, T, Compare, Alloc>::lower_bound (const typename map<Key, T,
      Compare, Alloc>::key_type& k) {
    if (!_size) return end();
    iterator it = begin();
    while (_comp(it->first, k) && it != end())
      it++;
    return it;
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::const_iterator
      map<Key, T, Compare, Alloc>::lower_bound (const typename map<Key, T,
      Compare, Alloc>::key_type& k) const {
    if (!_size) return end();
    const_iterator it = begin();
    while (_comp(it->first, k) && it != end())
      it++;
    return it;
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::iterator
      map<Key, T, Compare, Alloc>::upper_bound (const typename map<Key, T,
      Compare, Alloc>::key_type& k) {
    if (!_size) return end();
    iterator it = begin();
    while (_comp(it->first, k) && it != end())
      it++;
    if (it != end() && it->first == k)
      it++;
    return it;
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::const_iterator
      map<Key, T, Compare, Alloc>::upper_bound (const typename map<Key, T,
      Compare, Alloc>::key_type& k) const {
    if (!_size) return end();
    const_iterator it = begin();
    while (_comp(it->first, k) && it != end())
      it++;
    if (it != end() && it->first == k)
      it++;
    return it;
  }

  template<class Key, class T, class Compare, class Alloc>
  inline ft::pair<typename map<Key, T, Compare, Alloc>::iterator, typename map<Key, T,
      Compare, Alloc>::iterator>    map<Key, T, Compare, Alloc>::equal_range (
      const typename map<Key, T, Compare, Alloc>::key_type& k) {
    iterator it = lower_bound(k);
    if (it == end())
      return ft::pair<iterator, iterator>(it, it); 
    return ft::pair<iterator, iterator>(it++, it);
  }

  template<class Key, class T, class Compare, class Alloc>
  inline ft::pair<typename map<Key, T, Compare, Alloc>::const_iterator, typename map<Key,
      T, Compare, Alloc>::const_iterator> map<Key, T, Compare, Alloc>::equal_range (
      const typename map<Key, T, Compare, Alloc>::key_type& k) const {
    const_iterator it = lower_bound(k);
    if (it == end())
      return ft::pair<const_iterator, const_iterator>(it, it);
    return ft::pair<const_iterator, const_iterator>(it++, it);
  }


  /* ************************************** Allocator ************************************** */
  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::allocator_type
      map<Key, T,Compare, Alloc>::get_allocator() const {
    return _alloc;
  }


  /* ************************************** Allocator ************************************** */
  template<class Key, class T, class Compare , class Alloc>
  inline void   map<Key, T, Compare, Alloc>::_createUselessEnd() {
    _uselessEnd = _avlAlloc.allocate(1);
    _avlAlloc.construct(_uselessEnd, avl_type());
  }

  template<class Key, class T, class Compare , class Alloc>
  inline void   map<Key, T, Compare, Alloc>::_deleteUselessEnd() {
    _avlAlloc.destroy(_uselessEnd);
    _avlAlloc.deallocate(_uselessEnd, 1);
  }

  
  /* ****************************** Non-Member Function Overloads ****************************** */
  template< class Key, class T, class Compare, class Alloc >
  void swap(map<Key,T,Compare,Alloc>& lhs, map<Key,T,Compare,Alloc>& rhs ) {
    lhs.swap(rhs);
  }

  template< class Key, class T, class Compare, class Alloc >
  bool operator==(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
    if (lhs.size() != rhs.size()) return false;
    return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
  }

  template< class Key, class T, class Compare, class Alloc >
  bool operator!=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
    return !(lhs == rhs);  
  }

  template< class Key, class T, class Compare, class Alloc >
  bool operator<(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
    return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
  }

  template< class Key, class T, class Compare, class Alloc >
  bool operator<=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
    return !(rhs < lhs);
  }

  template< class Key, class T, class Compare, class Alloc >
  bool operator>(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
    return rhs < lhs;
  }

  template< class Key, class T, class Compare, class Alloc >
  bool operator>=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
    return !(lhs < rhs);
  }
}