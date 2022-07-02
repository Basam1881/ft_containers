/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 07:48:29 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/02 09:52:28 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <string>
# include <memory>
# include "../iterators/iterator.hpp"

namespace ft {
  template < class Key, class T, class Compare = std::less<Key>,
    class Alloc = std::allocator<std::pair<const Key,T> > >
  class map {
  
  /* ************************************** Value_compare Class ************************************** */
  // template <class Key, class T, class Compare, class Alloc>
  // class map<Key,T,Compare,Alloc>::value_compare
  // {
  //   friend class map;
  // protected:
  //   Compare comp;
  //   value_compare (Compare c) : comp(c) {}
  // public:
  //   typedef bool result_type;
  //   typedef value_type first_argument_type;
  //   typedef value_type second_argument_type;
  //   bool operator() (const value_type& x, const value_type& y) const {
  //     return comp(x.first, y.first);
  //   }
  // }

  public:
    /* ************************************** Types ************************************** */
    typedef Key																													key_type;
    typedef T																														mapped_type;
    typedef std::pair<const key_type,mapped_type>												value_type;
    typedef Compare																											key_compare;
    // typedef map<Key,T,Compare,Alloc>::value_compare											value_compare;
    typedef Alloc																												allocator_type;
    typedef typename allocator_type::reference													reference;
    typedef typename allocator_type::const_reference										const_reference;
    typedef typename allocator_type::pointer														pointer;
    typedef typename allocator_type::const_pointer											const_pointer;
    typedef typename ft::iterator<ft::random_access_iterator_tag,
                                                        value_type>     iterator;
    typedef typename ft::iterator<ft::random_access_iterator_tag,
                                                  const value_type>     const_iterator;
    typedef typename ft::reverse_iterator<iterator>                     reverse_iterator;
    typedef typename ft::reverse_iterator<const_iterator>               const_reverse_iterator;
    typedef ptrdiff_t																										difference_type;
    typedef size_t																											size_type;

    /* ************************************** Constructors ************************************** */
    inline explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()) {}

    template <class InputIterator>
    inline map (InputIterator first, InputIterator last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type()) {}

    inline map (const map& x) {}
    
    inline ~map() {}

    inline map& operator= (const map& x);


    /* ************************************** Iterators ************************************** */
      inline iterator					        	  begin();

      inline const_iterator 		        	begin() const;

      inline iterator					        	  end();

      inline const_iterator 		        	end() const;

      inline reverse_iterator						  rbegin();

      inline const_reverse_iterator 			rbegin() const;

      inline reverse_iterator						  rend();

      inline const_reverse_iterator 			rend() const;


      /* ************************************** Capacity ************************************** */
      inline bool                        empty() const;

      inline size_type                   size() const;

      inline size_type                   max_size() const;


      /* ************************************** Element Access ************************************** */
      mapped_type& operator[] (const key_type& k);
      
      mapped_type& at (const key_type& k);

      const mapped_type& at (const key_type& k) const;


      /* ************************************** Modifiers ************************************** */
      std::pair<iterator,bool> insert (const value_type& val);

      iterator insert (iterator position, const value_type& val);

      template <class InputIterator>
        void insert (InputIterator first, InputIterator last);
      
      void erase (iterator position);

      size_type erase (const key_type& k);

      void erase (iterator first, iterator last);

      void swap (map& x);

      void clear();

      
      /* ************************************** Observers ************************************** */
      key_compare key_comp() const;

      // value_compare value_comp() const;

      
      /* ************************************** Operations ************************************** */
      iterator find (const key_type& k);

      const_iterator find (const key_type& k) const;

      size_type count (const key_type& k) const;

      iterator lower_bound (const key_type& k);

      const_iterator lower_bound (const key_type& k) const;

      iterator upper_bound (const key_type& k);

      const_iterator upper_bound (const key_type& k) const;

      std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const;

      std::pair<iterator,iterator>             equal_range (const key_type& k);

      
      /* ************************************** Allocator ************************************** */
      allocator_type get_allocator() const;

      private:
        size_type             _size;
        allocator_type        _alloc;
      
  };
}

#include "map.tpp"

#endif
