/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:59:53 by bnaji             #+#    #+#             */
/*   Updated: 2022/06/03 14:08:20 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <memory>
# include "vector.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
template < class T, class Alloc = std::allocator<T> >
void vector<T, std::allocator<T> >::func()
{
	std::cout << "FUNC" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/



/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// vector &		operator=( vector const & rhs )
// {
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
// 	return *this;
// }



/*
** --------------------------------- METHODS ----------------------------------
*/
