/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:15:13 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/18 16:27:05 by bnaji            ###   ########.fr       */
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

			typedef T																																				          	value_type;
			typedef Alloc																																		          	allocator_type;
			typedef typename allocator_type::reference																			          	reference;
			typedef typename allocator_type::const_reference																          	const_reference;
			typedef typename allocator_type::pointer																				          	pointer;
			typedef typename allocator_type::const_pointer																	          	const_pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, value_type>			              iterator;
			typedef typename ft::const_iterator<ft::random_access_iterator_tag, const value_type>       const_iterator;
			typedef typename ft::reverse_iterator<ft::random_access_iterator_tag, value_type>           reverse_iterator;
			typedef typename ft::reverse_iterator<ft::random_access_iterator_tag, const value_type>     const_reverse_iterator;
			typedef ptrdiff_t																																           	difference_type;
			typedef size_t																																	           	size_type;
			
      /* ************************************** Constructors ************************************** */
			explicit vector (const allocator_type & alloc = allocator_type()) : _alloc(alloc), _arr(NULL), _size(0), _capacity(0)
      {}
			explicit vector (size_type n, const value_type & val = value_type(), const allocator_type & alloc = allocator_type()) : _alloc(alloc), _arr(NULL), _size(n), _capacity(n)
      {
        _arr = _alloc.allocate(n);
        for (size_t i = 0; i < n; i++)
          _alloc.construct(_arr + i, val);
      }
			template <class InputIterator>
			vector (InputIterator first, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type& alloc = allocator_type()) : _alloc(alloc), _arr(NULL)
      {
        size_type n = ft::distance(first, last);
        _capacity = n;
        _size = n;
        _arr = _alloc.allocate(n);
        // if (!_arr)
        //   std::cout << "n: " << n << std::endl;
        for (iterator it = begin(); it != end(); it++)
          _alloc.construct(it.base(), *first++);
      }
			vector (const vector & x) : _alloc(x.get_allocator()), _arr(NULL), _size(0), _capacity(0)
      {
        *this = x;
      }
			~vector()
      {
        // clearMe(*this);
        for (size_type i = 0; i < _size; i++)
          _alloc.destroy(_arr + i);
        _alloc.deallocate(_arr, _capacity);
      }

      /* ************************************** Operators ************************************** */
			vector &		operator=( vector const & rhs )
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
            // for (iterator it1 = begin(), it2 = rhs.begin() ; it1 != end() && it2 != rhs.end(); it1++, it2++)
            //   *it1 = *it2;
          }
          else
          {
            size_type i = 0;
            for ( ; i < rhs._size; i++) {
              _arr[i] = rhs._arr[i];
            }
          }
          _size = rhs._size;
          _capacity = rhs._capacity;
        }
        return *this;
      }

      /* ************************************** Iterators ************************************** */
			iterator					        	begin() { return iterator(_arr); }
			const_iterator 		        	begin() const { return const_iterator(_arr); }
			iterator					        	end() { return iterator(_arr + _size); }
			const_iterator 		        	end() const { return const_iterator(_arr + _size); }
			reverse_iterator						rbegin() { return reverse_iterator(_arr + _size - 1); }
			const_reverse_iterator 			rbegin() const { return const_reverse_iterator(_arr + _size - 1); }
			reverse_iterator						rend() { return reverse_iterator(_arr - 1); }
			const_reverse_iterator 			rend() const { return const_reverse_iterator(_arr - 1); }

      /* ************************************** Capacity ************************************** */
      size_type size() const { return _size; }
      size_type max_size() const { return (size_t)(-1) / sizeof(T);/* (sizeof(void *) * 8); */ }
      size_type capacity() const { return _capacity; }
      bool      empty() const { return (_size != 0 ? false : true); }
      void      resize(size_type n, value_type val = value_type())
      {
        if (n > _size && n > _capacity)
        {
          T * tmp = _alloc.allocate(_capacity);
          size_type i = 0;
          for ( ; i != _capacity ; i++) {
            tmp[i] = _arr[i];
            _alloc.destroy(_arr + i);
          }
          _alloc.deallocate(_arr, _capacity);
          _capacity = _size * 2;
          _size = n;
          _arr = _alloc.allocate(_capacity);
          size_type j = 0;
          for ( ; j != i; j++) {
            _arr[j] = tmp[j];
            _alloc.destroy(tmp + j);
          }
          _alloc.deallocate(tmp, _size);
          for ( ; j != _size; j++)
            _arr[j] = val;
        }
        else if (n > _size && n <= _capacity)
        {
          size_type i = 0;
          for ( ; i + _size < n; i++)
            _arr[i] = val;
          _size += i;
        }
        else if (n < _size)
        {
          size_type i = _size - 1;
          for ( ; i > n; i--)
            _arr[i] = value_type();
          _size = i;
        }
      }

      void reserve (size_type n)
      {
        if (n > _capacity)
        {
          T * tmp = _alloc.allocate(_capacity);
          size_type i = 0;
          // tmp = ft::copy(iterator(begin()), iterator(end()), iterator(tmp));
          for ( ; i != _size ; i++) {
            tmp[i] = _arr[i];
            _alloc.destroy(_arr + i);
          }
          _alloc.deallocate(_arr, _capacity);
          _capacity = n;
          _arr = _alloc.allocate(_capacity);
          size_type j = 0;
          for ( ; j != i; j++) {
            _arr[j] = tmp[j];
            _alloc.destroy(tmp + j);
          }
          _alloc.deallocate(tmp, _capacity);
          // for ( ; j != _capacity; j++)
          //   _arr[j] = value_type();
        }
      }

      /* ************************************** Element Access ************************************** */
      reference operator[] (size_type n) { return _arr[n]; }
      const_reference operator[] (size_type n) const { return _arr[n]; }
      reference at (size_type n)
      {
        if (n >= _size)
          throw std::out_of_range("ft_vector\n");
        return _arr[n];
      }
      const_reference at (size_type n) const
      {
        if (n >= _size)
          throw std::out_of_range("ft_vector\n");
        return _arr[n];
      }
      reference front() { return *_arr; }
      const_reference front() const;
      reference back() { return *(_arr + size() - 1); }
      const_reference back() const;

      /* ************************************** Modifiers ************************************** */
      template <class InputIterator>
      void assign (InputIterator first, InputIterator last)
      {
        size_type n = ft::distance(first, last);
        if (n > _capacity) {
          for (size_type i = 0; i < _capacity ; i++)
            _alloc.destroy(_arr + i);
          _alloc.deallocate(_arr, _capacity);
          _capacity = n;
          _size = n;
          _arr = _alloc.allocate(_capacity);
          for (size_type i = 0; i < _capacity ; i++, first++)
            _alloc.construct(_arr + i, *first);
        }
        else {
          _size = n;
          for (size_type i = 0; i < _size; i++) {
            _alloc.destroy(_arr + i);
            if (i < n)
              _arr[i] = *first;
          }
        }
      }
      void assign (size_type n, const value_type& val) 
      {
        if (n > _capacity) {
          for (size_type i = 0; i < _capacity ; i++)
            _alloc.destroy(_arr + i);
          _alloc.deallocate(_arr, _capacity);
          _capacity = n;
          _size = n;
          _arr = _alloc.allocate(_capacity);
          for (size_type i = 0; i < _capacity ; i++)
            _arr[i] = val;
        }
        else {
          for (size_type i = 0; i < _capacity; i++) {
            _alloc.destroy(_arr + i);
            if (i < n)
              _arr[i] = val;
          }
          _size = n;
        }
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
          // printArr();
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
			T *							_arr;
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

      

      // void clearMe(vector & v) {
      //   for (iterator it = v.begin(); it < v.end(); it++)
      //     _alloc.destroy(it.base());
      //   _alloc.deallocate(v.begin(), v.capacity());
      // }

	};
}
  /* ************************************** Non-member functions Overloads ************************************** */

#endif /* ********************************************************** VECTOR_H */