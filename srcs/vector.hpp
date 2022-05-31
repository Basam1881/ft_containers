/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:15:13 by bnaji             #+#    #+#             */
/*   Updated: 2022/05/28 13:06:52 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef vector_HPP
# define vector_HPP

# include <iostream>
# include <string>
# include <vector>
# include <memory>

template < class T, class Alloc = std::allocator<T> >
class vector : public std::vector<T>
{

	public:

		vector();
		vector( vector const & src );
		~vector();

		vector &		operator=( vector const & rhs );

		void				func();

	private:
		Alloc							_alloc;

};

#include "vector.tpp"

#endif /* ********************************************************** vector_H */