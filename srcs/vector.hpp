/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:15:13 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/13 20:27:13 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include <cstddef>
# include "iterator.hpp"

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
			typedef typename ft::iterator<std::random_access_iterator_tag, value_type>			            iterator;
			typedef typename ft::iterator<std::random_access_iterator_tag, const value_type>            const_iterator;
			typedef typename ft::reverse_iterator<std::random_access_iterator_tag, value_type>          reverse_iterator;
			typedef typename ft::reverse_iterator<std::random_access_iterator_tag, const value_type>    const_reverse_iterator;
			typedef ptrdiff_t																																           	difference_type;
			typedef size_t																																	           	size_type;
			
      /* ************************************** Constructors ************************************** */
			explicit vector (const allocator_type & alloc = allocator_type()) : _alloc(alloc), _arr(NULL), _size(0), _capacity(0) 
      {}
			explicit vector (size_type n, const value_type & val = value_type(), const allocator_type & alloc = allocator_type()) : _alloc(alloc), _arr(NULL), _size(n), _capacity(n * 2)
      {
        _arr = _alloc.allocate(n);
        for (size_t i = 0; i < n; i++)
          _alloc.construct(_arr + i, val);
      }
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _alloc(alloc), _arr(NULL)
      {
        size_type n = ft::distance(first, last);
        _size = n;
        _capacity = n * 2;
        _arr = _alloc.allocate(n);
        for (size_t i = 0; i < n; i++)
          _alloc.construct(_arr + i, *first++);
      }
			vector (const vector & x) : _alloc(allocator_type()), _arr(NULL), _size(0), _capacity(0)
      {
        *this = x;
      }
			~vector()
      {
        for (size_type i = 0; i < _size; i++) {
          _alloc.destroy(_arr + i);
        }
        _alloc.deallocate(_arr, _capacity);
      }
      


      /* ************************************** Operators ************************************** */
			vector &		operator=( vector const & rhs )
      {
        if (this != rhs)
        {
          if (rhs._size > _capacity)
          {
            size_type i;
            for (i = 0; i != _size ; i++) {
              _alloc.destroy(_arr + i);
            }
            _alloc.deallocate(_arr, _size);
            _arr = _alloc.allocate(rhs._capacity);
            for (i = 0 ; i != rhs._size; i++) {
              _arr[i] = rhs._arr[i];
            }
          }
          else
          {
            size_type i = 0;
            for ( ; i < rhs._size; i++)
              _arr[i] = rhs._arr[i];
          }
          _size = rhs._size;
          _capacity = rhs._capacity;
        }
        return *this;
      }

      /* ************************************** Iterators ************************************** */
			iterator					        	begin() { return _arr; }
			const_iterator 		        	begin() const { return _arr; }
			iterator					        	end() { return (_arr + size()); }
			const_iterator 		        	end() const { return (_arr + size()); }
			reverse_iterator						rbegin() { return (_arr + size()); }
			const_reverse_iterator 			rbegin() const { return (_arr + size()); }
			reverse_iterator						rend() { return _arr; }
			const_reverse_iterator 			rend() const { return _arr; }

      /* ************************************** Capacity ************************************** */
      size_type size() const { return _size; }
      size_type max_size() const { return (sizeof(void *) * 8); }
      size_type capacity() const { return _capacity; }
      bool      empty() const { return (_size != 0 ? false : true); }
      void      resize(size_type n, value_type val = value_type())
      {
        if (n > _size && n > _capacity)
        {
          T * tmp = _alloc.allocate(_size);
          size_type i = 0;
          for ( ; i != _size ; i++) {
            tmp[i] = _arr[i];
            _alloc.destroy(_arr + i);
          }
          _alloc.deallocate(_arr, _size);
          _size = n;
          _arr = _alloc.allocate(_size);
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

      /* ************************************** Element Access ************************************** */
      /* ************************************** Modifiers ************************************** */
      /* ************************************** Allocator ************************************** */
      
		private:
			allocator_type	_alloc;
			T *							_arr;
			size_type				_size;
			size_type				_capacity;

	};
}
  /* ************************************** Non-member functions Overloads ************************************** */

#endif /* ********************************************************** VECTOR_H */