/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PerformanceChecker.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:08:46 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/26 15:21:20 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERFORMANCECHECKER_HPP
# define PERFORMANCECHECKER_HPP

# include <iostream>
# include <string>
#include <iomanip>
#include <sys/time.h>

# define GREEN "\033[38;5;46m"
# define WHITE "\033[1;37m"
# define BLUE "\033[1;36m"
# define YELLOW "\033[1;33m"
# define RED "\033[1;31m"
# define PURPLE "\033[1;35m"
# define RESET "\033[m"

class PerformanceChecker
{

	public:

		PerformanceChecker();
		PerformanceChecker( PerformanceChecker const & src );
		~PerformanceChecker();

    void                    start();
    void                    stop();
    void                    stopStandard();
    void                    print() const;

    size_t const &          getMicroSecondsFirst() const;
    size_t const &          getSecondsFirst() const;
    double const &          getElapsedFirst() const;

    size_t const &          getMicroSecondsSecond() const;
    size_t const &          getSecondsSecond() const;
    double const &          getElapsedSecond() const;

		PerformanceChecker &		operator=( PerformanceChecker const & rhs );

	private:
  struct timeval  _begin;
  struct timeval  _end;
  size_t          _microseconds1;
  size_t          _seconds1;
  double          _elapsed1;
  size_t          _microseconds2;
  size_t          _seconds2;
  double          _elapsed2;

};

std::ostream &			operator<<( std::ostream & o, PerformanceChecker const & i );

#endif /* ********************************************** PERFORMANCECHECKER_H */