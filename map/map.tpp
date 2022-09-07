/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 09:09:48 by bnaji             #+#    #+#             */
/*   Updated: 2022/09/07 08:52:15 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
# include <memory>
# include <iostream>
# include <sstream>
# include <string>

namespace ft {
  
  /* ************************************** Constructors ************************************** */
  template < class Key, class T, class Compare, class Alloc>
  inline map<Key, T, Compare, Alloc>& map<Key, T, Compare, Alloc>::operator= (const map<Key, T, Compare, Alloc>& x) {
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
  inline typename map<Key, T, Compare, Alloc>::iterator					        	  map<Key, T, Compare, Alloc>::begin() {
    if (!_size)
      return iterator(_uselessEnd);
    return iterator(_root->getLowestKey(_root));
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::const_iterator 		        	map<Key, T, Compare, Alloc>::begin() const {
    if (!_size)
      return const_iterator(_uselessEnd);
    return const_iterator(_root->getLowestKey(_root));
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::iterator					        	  map<Key, T, Compare, Alloc>::end() {
    if (!_size)
      return iterator(_uselessEnd);
    return iterator(_root->getHighEnd());
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::const_iterator 		        	map<Key, T, Compare, Alloc>::end() const {
    if (!_size)
      return const_iterator(_uselessEnd);
    return const_iterator(_root->getHighEnd());
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::reverse_iterator						  map<Key, T, Compare, Alloc>::rbegin() {
    if (!_size)
      return reverse_iterator(_uselessEnd);
    return reverse_iterator(_root->getHighEnd());
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::const_reverse_iterator 			map<Key, T, Compare, Alloc>::rbegin() const {
    if (!_size)
      return const_reverse_iterator(_uselessEnd);
    return const_reverse_iterator(_root->getHighEnd());
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::reverse_iterator						  map<Key, T, Compare, Alloc>::rend() {
    if (!_size)
      return reverse_iterator(_uselessEnd);
    return reverse_iterator(_root->getLowestKey(_root));    
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::const_reverse_iterator 			map<Key, T, Compare, Alloc>::rend() const {
    if (!_size)
      return const_reverse_iterator(_uselessEnd);
    return const_reverse_iterator(_root->getLowestKey(_root));
  }

  /* ************************************** Capacity ************************************** */
  template<class Key, class T, class Compare, class Alloc>
  inline bool                                                             map<Key, T, Compare, Alloc>::empty() const {
    return _size == 0;
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::size_type                   map<Key, T, Compare, Alloc>::size() const {
      return _size;
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::size_type                   map<Key, T, Compare, Alloc>::max_size() const {
    return this->_alloc.max_size() / 5;
  }


  /* ************************************** Element Access ************************************** */
  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::mapped_type&   map<Key, T, Compare, Alloc>::operator[] (const typename map<Key, T, Compare, Alloc>::key_type& k) {
    avl_type * tmp = _root->search(_root, k);
    if (!tmp) {
      _root = _root->insert(_root, value_type(k, mapped_type()));
      _size++;
      tmp = _root->search(_root, k);
    }
    return tmp->getPair().second;
  }
  
  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::mapped_type&   map<Key, T, Compare, Alloc>::at (const typename map<Key, T, Compare, Alloc>::key_type& k) {
    avl_type * tmp = _root->search(_root, k);
    std::ostringstream str;
    str << "map::_M_range_check: __n (which is " << k << ") >= this->size() (which is " << _size << ")";
    if (!tmp) throw std::out_of_range(str.str());
    return tmp->getPair().second;
  }

  template<class Key, class T, class Compare, class Alloc>
  inline const typename map<Key, T, Compare, Alloc>::mapped_type&   map<Key, T, Compare, Alloc>::at (const typename map<Key, T, Compare, Alloc>::key_type& k) const {
    avl_type * tmp = _root->search(_root, k);
    std::ostringstream str;
    str << "map::_M_range_check: __n (which is " << k << ") >= this->size() (which is " << _size << ")";
    if (!tmp) throw std::out_of_range(str.str());
    std::cout << tmp->getPair().second << std::endl;
    return tmp->getPair().second;
  }


  /* ************************************** Modifiers ************************************** */
  template<class Key, class T, class Compare, class Alloc>
  inline ft::pair<typename map<Key, T, Compare, Alloc>::iterator, bool>   map<Key, T, Compare, Alloc>::insert (const typename map<Key, T, Compare, Alloc>::value_type& val) {
    avl_type * tmp = _root->search(_root, val.first);
    if (!tmp) {
      _root = _root->insert(_root, val);
      _size++;
      return ft::pair<iterator, bool>(iterator(_root->search(_root, val.first)), true);
    }
    return ft::pair<iterator, bool>(iterator(tmp), false);
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::iterator    map<Key, T, Compare, Alloc>::insert (iterator position, const value_type& val) {
    (void)position;
    return insert(val).first;
  }

  template<class Key, class T, class Compare, class Alloc>
  template <class InputIterator>
  inline void    map<Key, T, Compare, Alloc>::insert (InputIterator first, InputIterator last) {
    for ( ; first != last; first++)
      insert(*first);
  }

  template<class Key, class T, class Compare , class Alloc>
  inline void   map<Key, T, Compare, Alloc>::erase (map<Key, T, Compare, Alloc>::iterator position) {
    erase(position.getNode()->getPair().first);
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::size_type    map<Key, T, Compare, Alloc>::erase (const typename map<Key, T, Compare, Alloc>::key_type& k) {
    if (_root->search(_root, k))
      _size--;
    else
      return 0;
    if (!_size)
      delete _root->getHighEnd();
    _root = _root->erase(_root, k);
    // if (_root)
    // std::cout << "lowest: " << _root->getLowestKey(_root)->getPair().first << std::endl;
    // if (!_root->search(_root, k))
    //   std::cout << "Nice" << std::endl;
    // else
    //   std::cout << "WTF : " << k << std::endl;
    return 1;
  }

  template<class Key, class T, class Compare, class Alloc>
  inline void map<Key, T, Compare, Alloc>::erase (map<Key, T, Compare, Alloc>::iterator first, map<Key, T, Compare, Alloc>::iterator last) {
    iterator f;
    size_type count;

    if (!_size)
      return ;
    for ( count = 0, f = first; f != last; f++, count++);
    key_type * keys = new key_type[count];

    for ( count = 0, f = first; f != last; f++, count++)
      keys[count] = f.getNode()->getPair().first;
    for (size_type cnt = 0; cnt < count; cnt++) {
      // _root->printAll(_root);
      erase(keys[cnt]);
      // std::cout << std::endl << std::endl;
    }
    // _root->printAll(_root);
    delete[] keys;
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
  inline typename map<Key, T, Compare, Alloc>::key_compare map<Key, T, Compare, Alloc>::key_comp() const {
    return _comp;
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::value_compare map<Key, T, Compare, Alloc>::value_comp() const {
    return value_compare();
  }


  /* ************************************** Operations ************************************** */
  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::iterator   map<Key, T, Compare, Alloc>::find (const typename map<Key, T, Compare, Alloc>::key_type& k) {
    avl_type * tmp = _root->search(_root, k);
    if (tmp)
      return iterator(tmp);
    return end();
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::const_iterator   map<Key, T, Compare, Alloc>::find (const typename map<Key, T, Compare, Alloc>::key_type& k) const {
    avl_type * tmp = _root->search(_root, k);
    if (tmp)
      return iterator(tmp);
    return end();
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::size_type    map<Key, T, Compare, Alloc>::count (const typename map<Key, T, Compare, Alloc>::key_type& k) const {
    return _root->search(_root, k) != NULL;
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::iterator   map<Key, T, Compare, Alloc>::lower_bound (const typename map<Key, T, Compare, Alloc>::key_type& k) {
    iterator it = begin();
    while (_comp(it->first, k) && it != end())
      it++;
    return it;
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::const_iterator   map<Key, T, Compare, Alloc>::lower_bound (const typename map<Key, T, Compare, Alloc>::key_type& k) const {
    iterator it = begin();
    while (_comp(it->first, k) && it != end())
      it++;
    return it;
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::iterator   map<Key, T, Compare, Alloc>::upper_bound (const typename map<Key, T, Compare, Alloc>::key_type& k) {
    iterator it = begin();
    while (_comp(it->first, k) && it != end())
      it++;
    if (it->first == k)
      it++;
    return it;
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::const_iterator   map<Key, T, Compare, Alloc>::upper_bound (const typename map<Key, T, Compare, Alloc>::key_type& k) const {
    iterator it = begin();
    while (_comp(it->first, k) && it != end())
      it++;
    if (it->first == k)
      it++;
    return it;
  }

  template<class Key, class T, class Compare, class Alloc>
  inline ft::pair<typename map<Key, T, Compare, Alloc>::iterator, typename map<Key, T, Compare, Alloc>::iterator>             map<Key, T, Compare, Alloc>::equal_range (const typename map<Key, T, Compare, Alloc>::key_type& k) {
    iterator it = lower_bound(k);
    if (it.getNode()->getPair().first == k)
      return ft::pair<iterator, iterator>(it++, it);
    return ft::pair<iterator, iterator>(it, it);
  }

  template<class Key, class T, class Compare, class Alloc>
  inline ft::pair<typename map<Key, T, Compare, Alloc>::const_iterator, typename map<Key, T, Compare, Alloc>::const_iterator> map<Key, T, Compare, Alloc>::equal_range (const typename map<Key, T, Compare, Alloc>::key_type& k) const {
    iterator it = lower_bound(k);
    if (it.getNode()->getPair().first == k)
      return ft::pair<iterator, iterator>(it, ++it);
    return ft::pair<iterator, iterator>(it, it);
  }


  /* ************************************** Allocator ************************************** */
  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::allocator_type map<Key, T, Compare, Alloc>::get_allocator() const {
    return _alloc;
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