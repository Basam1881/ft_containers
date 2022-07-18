/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 09:09:48 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/18 10:06:15 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

namespace ft {
  
  /* ************************************** Constructors ************************************** */
  template < class Key, class T, class Compare, class Alloc>
  inline map<Key, T, Compare, Alloc>& map<Key, T, Compare, Alloc>::operator= (const map<Key, T, Compare, Alloc>& x) {
    if (this != &x) { _root = x._root; _size = x._size; _comp = x._comp; _alloc = x._alloc; } return *this; }


  /* ************************************** Iterators ************************************** */
  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::iterator					        	  map<Key, T, Compare, Alloc>::begin() {
    return iterator(_root->getLowestKey(_root));
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::const_iterator 		        	map<Key, T, Compare, Alloc>::begin() const {
    return iterator(_root->getLowestKey(_root));
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::iterator					        	  map<Key, T, Compare, Alloc>::end() {
    return iterator(_root->getHighEnd());
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::const_iterator 		        	map<Key, T, Compare, Alloc>::end() const {
    return iterator(_root->getHighEnd());
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::reverse_iterator						  map<Key, T, Compare, Alloc>::rbegin() {
    return iterator(_root->getHighestKey(_root));
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::const_reverse_iterator 			map<Key, T, Compare, Alloc>::rbegin() const {
    return iterator(_root->getHighestKey(_root));
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::reverse_iterator						  map<Key, T, Compare, Alloc>::rend() {
    return iterator(_root->getLowEnd());    
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::const_reverse_iterator 			map<Key, T, Compare, Alloc>::rend() const {
    return iterator(_root->getLowEnd());
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
    return (size_t)(-1) / sizeof(T);
  }


  /* ************************************** Element Access ************************************** */
  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::mapped_type&   map<Key, T, Compare, Alloc>::operator[] (const typename map<Key, T, Compare, Alloc>::key_type& k) {
    if (!_root->search(_root, k)) {
      _root = _root->insert(_root, value_type(k, mapped_type()));
      _size++;
    }
    return _root->search(_root, k)->getPair().second;
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
    return tmp->getPair().second;
  }


  /* ************************************** Modifiers ************************************** */
  template<class Key, class T, class Compare, class Alloc>
  inline ft::pair<typename map<Key, T, Compare, Alloc>::iterator, bool>   map<Key, T, Compare, Alloc>::insert (const typename map<Key, T, Compare, Alloc>::value_type& val) {
    _root = _root->insert(_root, val);
    return ft::pair<iterator,bool>(iterator(_root->search(_root, val.first)), true);
  }

  // template<class Key, class T, class Compare, class Alloc>
  // inline typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::insert (iterator position, const value_type& val) {
    
  // }

  // template <class InputIterator>
  //   template<class Key, class T, class Compare, class Alloc>
  //   void map<Key, T, Compare, Alloc>::insert (InputIterator first, InputIterator last) {
      
  //   }
  
  // template<class Key, class T, class Compare, class Alloc>
  // inline void map<Key, T, Compare, Alloc>::erase (map<Key, T, Compare, Alloc>::iterator position) {
    
  // }

  // template<class Key, class T, class Compare, class Alloc>
  // inline typename map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::erase (const typename map<Key, T, Compare, Alloc>::key_type& k) {
    
  // }

  // template<class Key, class T, class Compare, class Alloc>
  // inline void map<Key, T, Compare, Alloc>::erase (map<Key, T, Compare, Alloc>::iterator first, map<Key, T, Compare, Alloc>::iterator last) {
    
  // }

  // template<class Key, class T, class Compare, class Alloc>
  // inline void map<Key, T, Compare, Alloc>::swap (map& x) {
    
  // }

  // template<class Key, class T, class Compare, class Alloc>
  // inline void map<Key, T, Compare, Alloc>::clear() {
    
  // }

  
  /* ************************************** Observers ************************************** */
  // template<class Key, class T, class Compare, class Alloc>
  // inline typename map<Key, T, Compare, Alloc>::key_compare map<Key, T, Compare, Alloc>::key_comp() const {
    
  // }

  // value_compare value_comp() const {
    
  // }

  
  /* ************************************** Operations ************************************** */
  // template<class Key, class T, class Compare, class Alloc>
  // inline typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::find (const typename map<Key, T, Compare, Alloc>::key_type& k) {
    
  // }

  // template<class Key, class T, class Compare, class Alloc>
  // inline typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::find (const typename map<Key, T, Compare, Alloc>::key_type& k) const {
    
  // }

  // template<class Key, class T, class Compare, class Alloc>
  // inline typename map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::count (const typename map<Key, T, Compare, Alloc>::key_type& k) const {
    
  // }

  // template<class Key, class T, class Compare, class Alloc>
  // inline typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::lower_bound (const typename map<Key, T, Compare, Alloc>::key_type& k) {
    
  // }

  // template<class Key, class T, class Compare, class Alloc>
  // inline typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::lower_bound (const typename map<Key, T, Compare, Alloc>::key_type& k) const {
    
  // }

  // template<class Key, class T, class Compare, class Alloc>
  // inline typename map<Key, T, Compare, Alloc>::iterator map<Key, T, Compare, Alloc>::upper_bound (const typename map<Key, T, Compare, Alloc>::key_type& k) {
    
  // }

  // template<class Key, class T, class Compare, class Alloc>
  // inline typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::upper_bound (const typename map<Key, T, Compare, Alloc>::key_type& k) const {
    
  // }

  // template<class Key, class T, class Compare, class Alloc>
  // inline std::pair<typename map<Key, T, Compare, Alloc>::const_iterator, typename map<Key, T, Compare, Alloc>::const_iterator> map<Key, T, Compare, Alloc>::equal_range (const typename map<Key, T, Compare, Alloc>::key_type& k) const {
    
  // }

  // template<class Key, class T, class Compare, class Alloc>
  // inline std::pair<typename map<Key, T, Compare, Alloc>::iterator, typename map<Key, T, Compare, Alloc>::iterator>             map<Key, T, Compare, Alloc>::equal_range (const typename map<Key, T, Compare, Alloc>::key_type& k) {
    
  // }

  
  /* ************************************** Allocator ************************************** */
  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::allocator_type map<Key, T, Compare, Alloc>::get_allocator() const {
    return _alloc;
  }
}