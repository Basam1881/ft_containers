/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:15:13 by bnaji             #+#    #+#             */
/*   Updated: 2022/09/08 08:09:44 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "../vector/vector.hpp"

namespace ft
{
	template <class T, class Container = vector<T> > class stack
	{

		public:

      /* ************************************** Types ************************************** */
			typedef T																														value_type;
			typedef Container																										container_type;
			typedef size_t																											size_type;

      /* ********************************* Member Functions ********************************* */
			inline explicit stack (const container_type& ctnr = container_type()) : _container(ctnr)
      {}

      /* ************************************** Capacity ************************************** */
      inline bool                        empty() const {
        return _container.empty();
      }

      inline size_type                   size() const {
        return _container.size();
      }

      inline value_type&                 top() {
        return _container.back();
      }

      inline const value_type&           top() const {
        return _container.back();
      }

      inline void                        push(const value_type& val) {
        return _container.push_back(val);
      }

      inline void                        pop() {
        return _container.pop_back();
      }

      /* ******************************* Non Member Functions ******************************* */

      template <class T1, class Container1>
      friend bool operator== (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);

      template <class T1, class Container1>
      friend bool operator!= (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);

      template <class T1, class Container1>
      friend bool operator< (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);

      template <class T1, class Container1>
      friend bool operator<= (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);

      template <class T1, class Container1>
      friend bool operator> (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);

      template <class T1, class Container1>
      friend bool operator>= (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs);
      
		protected:
			container_type	_container;
	};

template <class T, class Container>
  bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
    return lhs._container == rhs._container;
}

template <class T, class Container>
  bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
    return lhs._container != rhs._container;
}

template <class T, class Container>
  bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
    return lhs._container < rhs._container;
}

template <class T, class Container>
  bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
    return lhs._container <= rhs._container;
}

template <class T, class Container>
  bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
    return lhs._container > rhs._container;
} 

template <class T, class Container>
  bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
    return lhs._container >= rhs._container;
}

}

#endif /* ********************************************************** VECTOR_H */