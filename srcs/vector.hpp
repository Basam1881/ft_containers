/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:15:13 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/23 11:08:58 by bnaji            ###   ########.fr       */
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
			explicit vector (const allocator_type & alloc = allocator_type())
          : _alloc(alloc), _arr(NULL), _size(0), _capacity(0)
      {}
      
			explicit vector (size_type n, const value_type & val = value_type()
        , const allocator_type & alloc = allocator_type())
          : _alloc(alloc), _arr(NULL), _size(n), _capacity(n)
      { allocMe(*this, n, val); }

			template <class InputIterator>
			vector (InputIterator first, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last,
        const allocator_type& alloc = allocator_type())
          : _alloc(alloc), _arr(NULL), _size(ft::distance(first, last)), _capacity(_size)
      { allocMe(*this, _capacity, first, last); }

			vector (const vector & x)
          : _alloc(x.get_allocator()), _arr(NULL), _size(0), _capacity(0)
      { *this = x; }

			~vector()
      { clearMe(*this); }

			vector &		operator=( vector const & rhs );

      /* ************************************** Iterators ************************************** */
			iterator					        	begin();
			const_iterator 		        	begin() const;
			iterator					        	end();
			const_iterator 		        	end() const;
			reverse_iterator						rbegin();
			const_reverse_iterator 			rbegin() const;
			reverse_iterator						rend();
			const_reverse_iterator 			rend() const;

      /* ************************************** Capacity ************************************** */
      size_type                   size() const;
      size_type                   max_size() const;
      size_type                   capacity() const;
      bool                        empty() const;
      void                        resize(size_type n, value_type val = value_type());
      void                        reserve (size_type n);

      /* ************************************** Element Access ************************************** */
      reference                   operator[] (size_type n);
      const_reference             operator[] (size_type n) const;
      reference                   at (size_type n);
      const_reference             at (size_type n) const;
      reference                   front();
      const_reference             front() const;
      reference                   back();
      const_reference             back() const;
      pointer                     data();
      const_pointer               data() const;

      /* ************************************** Modifiers ************************************** */
      template <class InputIterator>
      void assign (InputIterator first, InputIterator last)
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
      void assign (size_type n, const value_type& val) 
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

      void push_back (const value_type& val)
      {
        if (_size == _capacity) {
          T * tmp = _alloc.allocate(_capacity);
          size_type i = 0;
          for ( ; i != _capacity ; i++) {
            tmp[i] = _arr[i];
            _alloc.destroy(_arr + i);
          }
          _alloc.deallocate(_arr, _capacity);
          _capacity = _size * 2;
          _size += 1;
          _arr = _alloc.allocate(_capacity);
          size_type j = 0;
          for ( ; j != i; j++) {
            _arr[j] = tmp[j];
            _alloc.destroy(tmp + j);
          }
          _alloc.deallocate(tmp, _size);
          _arr[j] = val;
        }
      }
      
      void pop_back()
      {
        _alloc.destroy(_arr + _size-- - 1);
      }

      iterator insert (iterator position, const value_type& val)
      {
        if (_size == _capacity) {
          iterator itmp = begin();
          // size_type tmp = ft::distance(itmp, position);
          size_type i = 0;
          for( ; itmp != position; itmp++, i++);
          reserve(_size * 2);
          position = begin() + i;
        }
        ++_size;
        ft::copy_backward(position , end() - 1, end() );
        // printArr();
        *position = val;
        return begin();
      }

      void insert (iterator position, size_type n, const value_type& val)
      {
        iterator itmp = begin();
        size_type i = 0;
        for( ; itmp != position; itmp++, i++);
        for ( size_type j = 0; j < n; j++)
          insert(begin() + i + j, val);
      }

      template <class InputIterator>
      void insert (iterator position, InputIterator first, InputIterator last)
      {
        size_type i = 0;
        bool exist = false;
        for(iterator itmp = begin(); itmp != position; itmp++, i++);
        for (iterator it = position; it != end(); it++)
          if (it == first)
            exist = true;
        for ( size_type j = 0; first != last  ; first++, j++) {
          size_type f = 0;
          size_type n = 0;
          if (exist) {
            for(iterator itmp = begin(); itmp != first; itmp++, f++);
            for(iterator itmp = first; itmp != last; itmp++, n++);
          }
          T tmp = *first;
          insert(begin() + i + j, tmp);
          if (exist) {
            first = begin() + f;
            last = first + n;
          }
          // std::cout << "HERE\n";
          // insert(begin() + i + j, first);
          // std::cout << "HERE\n";
          // break;
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
      allocator_type get_allocator() const { return _alloc; }
      
		private:
			allocator_type	_alloc;
			pointer					_arr;
			size_type				_size;
			size_type				_capacity;
      
      void printArr() {
        size_type i = 0;
        for (; i != size(); i++)
          std::cout << _arr[i] << ' ';
        std::cout << std::endl;
      }
      
      size_type store(iterator it) {
        iterator tmp = begin();
        size_type i = 0;
        for( ; tmp != it && tmp != end(); tmp++, i++);
        return i;
      }

      void  allocMe(vector & v, size_t & n, const value_type & val) {
        if (n)
          _arr = _alloc.allocate(n);
        for (size_t i = 0; i < n; i++)
          v.get_allocator().construct(v.begin().base() + i, val);
      }

      void  allocMe(vector & v, size_t & n, iterator first, iterator last) {
        if (n)
          v._arr = v.get_allocator().allocate(n);
        ft::copy(first, last, v.begin(), v.get_allocator());
      }

      void clearMe(vector & v) {
        for (iterator it = v.begin(); it != v.end(); it++)
          v._alloc.destroy(it.base());
        v._alloc.deallocate(v.begin().base(), v.capacity());
      }
      
      void  replace(vector & v, size_type & n, iterator & first) {
        for (size_type i = 0; i < v._capacity; i++) {
            v._alloc.destroy(v._arr + i);
            if (i < n) {
              v._alloc.construct(v._arr + i, *first);
              first++;              
            }
        }
      }
      
      void  replace(vector & v, size_type n, const value_type& val) {
        for (size_type i = 0; i < v._capacity; i++) {
            v._alloc.destroy(v._arr + i);
            if (i < n)
              v._alloc.construct(v._arr + i, val);
        }
      }
      


	};
}

#include "vector.tpp"

#endif /* ********************************************************** VECTOR_H */