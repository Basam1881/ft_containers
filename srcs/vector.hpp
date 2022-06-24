/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:15:13 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/24 07:59:48 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include <cstddef>
# include <stdexcept>
# include "iterator.hpp"
# include "distance.hpp"
# include "copy.hpp"
# include "copy_backward.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"

namespace ft
{
	
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{

		public:
    
      /* ************************************** Types ************************************** */
			typedef T																																				  value_type;
			typedef Alloc																																		  allocator_type;
			typedef typename allocator_type::reference																			  reference;
			typedef typename allocator_type::const_reference																  const_reference;
			typedef typename allocator_type::pointer																				  pointer;
			typedef typename allocator_type::const_pointer																	  const_pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, value_type>			    iterator;
			typedef typename ft::iterator<ft::random_access_iterator_tag, const value_type>   const_iterator;
			typedef typename ft::reverse_iterator<iterator>                                   reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>                             const_reverse_iterator;
			typedef ptrdiff_t																																  difference_type;
			typedef size_t																																	  size_type;
			
      /* ************************************** Constructors ************************************** */
			inline explicit vector (const allocator_type & alloc = allocator_type())
          : _alloc(alloc), _arr(NULL), _size(0), _capacity(0)
      {}
      
			inline explicit vector (size_type n, const value_type & val = value_type()
        , const allocator_type & alloc = allocator_type())
          : _alloc(alloc), _arr(NULL), _size(n), _capacity(n)
      { allocMe(*this, n, val); }

			template <class InputIterator>
			inline vector (InputIterator first, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last,
        const allocator_type& alloc = allocator_type())
          : _alloc(alloc), _arr(NULL), _size(ft::distance(first, last)), _capacity(_size)
      { allocMe(*this, _capacity, first, last); }

			inline vector (const vector & x)
          : _alloc(x.get_allocator()), _arr(NULL), _size(0), _capacity(0)
      { *this = x; }

			inline ~vector()
      { clearMe(*this); }

			inline vector &		operator=( vector const & rhs );

      /* ************************************** Iterators ************************************** */
			inline iterator					        	begin();
			inline const_iterator 		        	begin() const;
			inline iterator					        	end();
			inline const_iterator 		        	end() const;
			inline reverse_iterator						rbegin();
			inline const_reverse_iterator 			rbegin() const;
			inline reverse_iterator						rend();
			inline const_reverse_iterator 			rend() const;

      /* ************************************** Capacity ************************************** */
      inline size_type                   size() const;
      inline size_type                   max_size() const;
      inline size_type                   capacity() const;
      inline bool                        empty() const;
      inline void                        resize(size_type n, value_type val = value_type());
      inline void                        reserve (size_type n);

      /* ************************************** Element Access ************************************** */
      inline reference                   operator[] (size_type n);
      inline const_reference             operator[] (size_type n) const;
      inline reference                   at (size_type n);
      inline const_reference             at (size_type n) const;
      inline reference                   front();
      inline const_reference             front() const;
      inline reference                   back();
      inline const_reference             back() const;
      inline pointer                     data();
      inline const_pointer               data() const;

      /* ************************************** Modifiers ************************************** */
      template <class InputIterator>
      inline void assign (InputIterator first, InputIterator last)
      {
        size_type n = ft::distance(first, last);
        if (n > _capacity) {
          clearMe(*this);
          allocMe(*this, n, first, last);
          _capacity = n;
        }
        else
          replace(*this, n, first);
        _size = n;
      }
      inline void assign (size_type n, const value_type& val) 
      {
        if (n > _capacity) {
          clearMe(*this);
          allocMe(*this, n, val);
          _capacity = n;
        }
        else
          replace(*this, n, val);
        _size = n;
      }

      inline void push_back (const value_type& val)
      {
        checkAndReserve(*this, 1, _capacity * 2);
        _alloc.construct(_arr + _size++, val);
      }

      inline void pop_back()
      {
        _alloc.destroy(_arr + _size-- - 1);
      }

      inline iterator insert (iterator position, const value_type& val)
      {
        if (_size == _capacity)
          position = storePositionAndReserve(*this, position, 1, _capacity * 2);
        ++_size;
        ft::copy_backward(position , end() - 1, end() );
        *position = val;
        return position;
      }

      inline void insert (iterator position, size_type n, const value_type& val)
      {
        isValidInsert(_size + n);
        size_type oldEnd = _size;
        if (_size + n > _capacity)
          position = storePositionAndReserve(*this, position, _size + n, _size + n);
        _size += n;
        ft::copy_backward(position, begin() + oldEnd, end());
        for (size_type i = 0; i < n; i++)
          *position++ = val;
      }

      template <class InputIterator>
      inline void insert (iterator position, InputIterator first, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last)
      {
        size_type i = 0;
        bool exist = false;
        for(iterator itmp = begin(); itmp != position; itmp++, i++);
        for (iterator it = begin(); it != end(); it++)
          if (it == first)
            exist = true;
        for ( size_type j = 0; first != last  ; first++, j++) {
          size_type f = 0;
          size_type n = 0;
          if (exist) {
            for(iterator itmp = begin(); itmp != first; itmp++, f++);
            for(iterator itmp = first; itmp != last; itmp++, n++);
          }
          insert(begin() + i + j, *first);
          if (exist) {
            first = begin() + f;
            last = first + n;
          }
        }
      }

      // iterator erase (iterator position)
      // {
      //   size_type i = store(position);
      //   reserve(_capacity);
      //   i = 
        
      // }
      // iterator erase (iterator first, iterator last)
      // {
        
      // }
      
      /* ************************************** Allocator ************************************** */
      inline allocator_type get_allocator() const { return _alloc; }
      
		private:
			allocator_type	_alloc;
			pointer					_arr;
			size_type				_size;
			size_type				_capacity;
      
      inline void printArr() {
        size_type i = 0;
        for (; i != size(); i++)
          std::cout << _arr[i] << ' ';
        std::cout << std::endl;
      }
      
      inline size_type store(iterator it) {
        iterator tmp = begin();
        size_type i = 0;
        for( ; tmp != it && tmp != end(); tmp++, i++);
        return i;
      }

      inline void  allocMe(vector & v, size_t & n, const value_type & val) {
        if (n)
          _arr = _alloc.allocate(n);
        for (size_t i = 0; i < n; i++)
          v.get_allocator().construct(v.begin().base() + i, val);
      }

      inline void  allocMe(vector & v, size_t & n, iterator first, iterator last) {
        if (n) 
          v._arr = v.get_allocator().allocate(n);
        ft::copy(first, last, v.begin(), v.get_allocator());
      }

      inline void clearMe(vector & v) {
        for (iterator it = v.begin(); it != v.end(); it++)
          v._alloc.destroy(it.base());
        v._alloc.deallocate(v.begin().base(), v.capacity());
      }
      
      inline void  replace(vector & v, size_type & n, iterator & first) {
        for (size_type i = 0; i < v._capacity; i++) {
          v._alloc.destroy(v._arr + i);
          if (i < n) {
            v._alloc.construct(v._arr + i, *first);
            first++;              
          }
        }
      }
      
      inline void  replace(vector & v, size_type n, const value_type& val) {
        for (size_type i = 0; i < v._capacity; i++) {
          v._alloc.destroy(v._arr + i);
          if (i < n)
            v._alloc.construct(v._arr + i, val);
        }
      }

      inline void  checkAndReserve(vector & v, size_type m, size_type n) {
        if (!v._capacity)
          v.reserve(m);
        else if (v._size == v._capacity)
          v.reserve(n);
      }
      
      inline void isValidInsert(size_type n) {
        if (n > max_size())
          throw std::length_error("vector::_M_fill_insert");
        pointer tmp = _alloc.allocate(_size + n);
        _alloc.deallocate(tmp, _size + n);
      }

      inline iterator  storePositionAndReserve(vector & v, iterator & position, size_type reserveSize1, size_type reserveSize2) {
        size_type i = ft::distance(v.begin(), position);
        checkAndReserve(v, reserveSize1, reserveSize2);
        return (begin() + i);
      }

      // inline bool isIteratorInVector(vector & v, iterator it) {
        
      // }


	};
}

#include "vector.tpp"

#endif /* ********************************************************** VECTOR_H */