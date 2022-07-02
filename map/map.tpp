/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 09:09:48 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/02 09:56:16 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

namespace ft {
  
  /* ************************************** Constructors ************************************** */
  // template < class Key, class T, class Compare, class Alloc>
  // inline map<Key, T, Compare, Alloc>& map<Key, T, Compare, Alloc>::operator= (const map<Key, T, Compare, Alloc>& x) {}


  /* ************************************** Iterators ************************************** */
  // template<class Key, class T, class Compare, class Alloc>
  // inline typename map<Key, T, Compare, Alloc>::iterator					        	  map<Key, T, Compare, Alloc>::begin() {
  //   return iterator();
  // }

  // template<class Key, class T, class Compare, class Alloc>
  // inline typename map<Key, T, Compare, Alloc>::const_iterator 		        	map<Key, T, Compare, Alloc>::begin() const {
    
  // }

  // template<class Key, class T, class Compare, class Alloc>
  // inline typename map<Key, T, Compare, Alloc>::iterator					        	  map<Key, T, Compare, Alloc>::end() {
    
  // }

  // template<class Key, class T, class Compare, class Alloc>
  // inline typename map<Key, T, Compare, Alloc>::const_iterator 		        	map<Key, T, Compare, Alloc>::end() const {
    
  // }

  // template<class Key, class T, class Compare, class Alloc>
  // inline typename map<Key, T, Compare, Alloc>::reverse_iterator						  map<Key, T, Compare, Alloc>::rbegin() {
    
  // }

  // template<class Key, class T, class Compare, class Alloc>
  // inline typename map<Key, T, Compare, Alloc>::const_reverse_iterator 			map<Key, T, Compare, Alloc>::rbegin() const {
    
  // }

  // template<class Key, class T, class Compare, class Alloc>
  // inline typename map<Key, T, Compare, Alloc>::reverse_iterator						  map<Key, T, Compare, Alloc>::rend() {
    
  // }

  // template<class Key, class T, class Compare, class Alloc>
  // inline typename map<Key, T, Compare, Alloc>::const_reverse_iterator 			map<Key, T, Compare, Alloc>::rend() const {
    
  // }


  /* ************************************** Capacity ************************************** */
  template<class Key, class T, class Compare, class Alloc>
  inline bool                        map<Key, T, Compare, Alloc>::empty() const {
    return (_size == 0);
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::size_type                   map<Key, T, Compare, Alloc>::size() const {
      return _size;
  }

  template<class Key, class T, class Compare, class Alloc>
  inline typename map<Key, T, Compare, Alloc>::size_type                   map<Key, T, Compare, Alloc>::max_size() const {
    return (size_t)(-1) / (sizeof(T) * 2);
  }


  /* ************************************** Element Access ************************************** */
  // template<class Key, class T, class Compare, class Alloc>
  // inline typename map<Key, T, Compare, Alloc>::mapped_type& map<Key, T, Compare, Alloc>::operator[] (const typename map<Key, T, Compare, Alloc>::key_type& k) {
    
  // }
  
  // template<class Key, class T, class Compare, class Alloc>
  // inline typename map<Key, T, Compare, Alloc>::mapped_type& map<Key, T, Compare, Alloc>::at (const typename map<Key, T, Compare, Alloc>::key_type& k) {
    
  // }

  // template<class Key, class T, class Compare, class Alloc>
  // inline const typename map<Key, T, Compare, Alloc>::mapped_type& map<Key, T, Compare, Alloc>::at (const typename map<Key, T, Compare, Alloc>::key_type& k) const {
    
  // }


  /* ************************************** Modifiers ************************************** */
  // template<class Key, class T, class Compare, class Alloc>
  // inline std::pair<typename map<Key, T, Compare, Alloc>::iterator,bool> map<Key, T, Compare, Alloc>::insert (const typename map<Key, T, Compare, Alloc>::value_type& val) {
    
  // }

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