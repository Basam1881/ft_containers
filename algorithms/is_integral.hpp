/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:11:06 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/16 09:39:33 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP
namespace ft
{
  template <class T, T v>
  struct integral_constant {
    static const T value = v;
    typedef T value_type;
    typedef integral_constant<T,v> type;
  };

  typedef integral_constant<bool,false> false_type;
  typedef integral_constant<bool,true> true_type;

  template <class _Tp> struct is_integral                     : public false_type {};
  template <>          struct is_integral<bool>               : public true_type {};
  template <>          struct is_integral<char>               : public true_type {};
  template <>          struct is_integral<wchar_t>            : public true_type {};
  template <>          struct is_integral<signed char>        : public true_type {};
  template <>          struct is_integral<short>              : public true_type {};
  template <>          struct is_integral<int>                : public true_type {};
  template <>          struct is_integral<long>               : public true_type {};
  template <>          struct is_integral<long long>          : public true_type {};
  template <>          struct is_integral<unsigned char>      : public true_type {};
  template <>          struct is_integral<unsigned short>     : public true_type {};
  template <>          struct is_integral<unsigned int>       : public true_type {};
  template <>          struct is_integral<unsigned long>      : public true_type {};
  template <>          struct is_integral<unsigned long long> : public true_type {};  
}

#endif
