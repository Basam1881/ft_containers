/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:15:13 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/05 15:55:08 by bnaji            ###   ########.fr       */
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

			typedef T																																					value_type;
			typedef Alloc																																			allocator_type;
			typedef typename allocator_type::reference																				reference;
			typedef typename allocator_type::const_reference																	const_reference;
			typedef typename allocator_type::pointer																					pointer;
			typedef typename allocator_type::const_pointer																		const_pointer;
			typedef typename ft::iterator<std::random_access_iterator_tag, value_type>				iterator;
			typedef typename ft::iterator<std::random_access_iterator_tag, const value_type>	const_iterator;
			typedef ptrdiff_t																																	difference_type;
			typedef size_t																																		size_type;
			
			explicit vector (const allocator_type & alloc = allocator_type()) : _alloc(alloc), _arr(NULL), _size(0), _capacity(0) {}
			explicit vector (size_type n, const value_type & val = value_type(),
						const allocator_type & alloc = allocator_type()) : _alloc(alloc), _arr(NULL), _size(n), _capacity(n) { _arr = _alloc.allocate(n); for (size_t i = 0; i < n; i++) { _arr[i] = val; } }
			template <class InputIterator>
					vector (InputIterator first, InputIterator last,
									const allocator_type& alloc = allocator_type()) {}
			vector (const vector& x) {}
			~vector() {}

			vector &		operator=( vector const & rhs ) {}

			iterator						begin() { return _arr; }
			const_iterator 			begin() const { return _arr; }

			
			void func() {
				std::cout << "Func" << std::endl;
			}

		private:
			allocator_type	_alloc;
			T *							_arr;
			size_type				_size;
			size_type				_capacity;

	};
}

#endif /* ********************************************************** VECTOR_H */