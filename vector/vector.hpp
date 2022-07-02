/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:15:13 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/02 09:43:32 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <memory>
# include <cstddef>
# include <stdexcept>
# include "../iterators/iterator.hpp"
# include "../algorithms/distance.hpp"
# include "../algorithms/copy.hpp"
# include "../algorithms/copy_backward.hpp"
# include "../algorithms/enable_if.hpp"
# include "../algorithms/is_integral.hpp"
# include "../algorithms/equal.hpp"
# include "../algorithms/lexicographical_compare.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{

		public:
    
      /* ************************************** Types ************************************** */
			typedef T																														value_type;
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
			inline explicit vector (const allocator_type & alloc = allocator_type())
          : _alloc(alloc), _arr(NULL), _size(0), _capacity(0)
      {}
      
			inline explicit vector (size_type n, const value_type & val = value_type()
        , const allocator_type & alloc = allocator_type())
          : _alloc(alloc), _arr(NULL), _size(n), _capacity(n)
      { checkIfValid(*this, n, "cannot create std::vector larger than max_size()"); allocMe(*this, n, val); }

			template <class InputIterator>
			inline vector (InputIterator first, typename enable_if<!is_integral<InputIterator>::value,
        InputIterator>::type last, const allocator_type& alloc = allocator_type())
          : _alloc(alloc), _arr(NULL), _size(ft::distance(first, last)), _capacity(_size)
      { allocMe(*this, _capacity, first, last); }

			inline vector (const vector & x)
          : _alloc(x.get_allocator()), _arr(NULL), _size(0), _capacity(0)
      { *this = x; }

			inline ~vector()
      { clearMe(*this); }

			inline vector &		operator=( vector const & rhs );

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
      inline void                        assign (InputIterator first, InputIterator last);

      inline void                        assign (size_type n, const value_type& val);

      inline void                        push_back (const value_type& val);

      inline void                        pop_back();

      inline iterator                    insert (iterator position, const value_type& val);

      inline void                        insert (iterator position, size_type n, const value_type& val);

      template <class InputIterator>
      inline void                        insert (iterator position, InputIterator first,
                                          typename enable_if<!is_integral<InputIterator>::value,
                                          InputIterator>::type last);

      inline iterator                    erase (iterator position);

      inline iterator                    erase (iterator first, iterator last);

      inline void                        swap(vector & x);

      inline void                        clear();

      
      /* ************************************** Allocator ************************************** */
      inline allocator_type              get_allocator() const;
      
		private:
			allocator_type	_alloc;
			pointer					_arr;
			size_type				_size;
			size_type				_capacity;

      inline void                        allocMe(vector & v, size_t & n, const value_type & val);

      inline void                        allocMe(vector & v, size_t & n, iterator first, iterator last);

      inline void                        allocMe(vector & v, size_t const & n, const_iterator first, const_iterator last);

      inline void                        clearMe(vector & v);

      inline void                        reallocMe(vector & v, size_type & n, value_type const & val);

      inline void                        reallocMe(vector & v, size_type & n, iterator first, iterator last);

      inline void                        reallocMe(vector & v, size_type const & n, const_iterator first, const_iterator last);

      inline void                        replace(vector & v, size_type & n, iterator & first);

      inline void                        replace(vector & v, size_type n, const value_type& val);

      inline void                        checkAndReserve(vector & v, size_type m, size_type n);

      inline void                        isValidInsert(size_type n);

      inline iterator                    storePositionAndReserve(vector & v, iterator & position, size_type reserveSize1, size_type reserveSize2);

      inline bool                        isIteratorInVector(vector & v, iterator & iter);

      inline void                        checkIfValid(vector & v, size_type & n, std::string str);

	};

}

#include "vector.tpp"

#endif /* ********************************************************** VECTOR_H */