/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PerformanceChecker.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:08:41 by bnaji             #+#    #+#             */
/*   Updated: 2022/07/26 15:25:15 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PerformanceChecker.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PerformanceChecker::PerformanceChecker() : _microseconds1(0), _seconds1(0), _elapsed1(0), _microseconds2(0), _seconds2(0), _elapsed2(0)
{
}

PerformanceChecker::PerformanceChecker( const PerformanceChecker & src ) : _microseconds1(0), _seconds1(0), _elapsed1(0), _microseconds2(0), _seconds2(0), _elapsed2(0)
{
  *this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PerformanceChecker::~PerformanceChecker()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PerformanceChecker &				PerformanceChecker::operator=( PerformanceChecker const & rhs )
{
	if ( this != &rhs )
	{
		this->_begin = rhs._begin;
		this->_end = rhs._end;
		this->_microseconds1 = rhs._microseconds1;
		this->_seconds1 = rhs._seconds1;
		this->_elapsed1 = rhs._elapsed1;
		this->_microseconds2 = rhs._microseconds2;
		this->_seconds2 = rhs._seconds2;
		this->_elapsed2 = rhs._elapsed2;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PerformanceChecker const & i )
{
  o << PURPLE << "Time measured : " << std::setprecision(5) << std::fixed << YELLOW << i.getElapsedFirst() * 1e+6 << WHITE << " Ms" << RESET << std::endl;
  o << PURPLE << "Time measured : " << std::setprecision(5) << std::fixed << YELLOW << i.getElapsedSecond() * 1e+6 << WHITE << " Ms" << RESET << std::endl;
  o << PURPLE << "Faster by     : " << std::setprecision(5) << std::fixed << YELLOW << i.getElapsedSecond() / i.getElapsedFirst() << WHITE << " (ft_v/v)" << RESET<< std::endl;
  o << PURPLE << "Slower by     : " << std::setprecision(5) << std::fixed << YELLOW << i.getElapsedFirst() / i.getElapsedSecond() << WHITE << " (v/ft_v)" << RESET<< std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void                    PerformanceChecker::start() {
  gettimeofday(&_begin, 0);
}
void                    PerformanceChecker::stop() {
  gettimeofday(&_end, 0);
  _seconds1 = _end.tv_sec - _begin.tv_sec;
  _microseconds1 = _end.tv_usec - _begin.tv_usec;
  _elapsed1 = _seconds1 + _microseconds1*1e-6;
}
void                    PerformanceChecker::stopStandard() {
  gettimeofday(&_end, 0);
  _seconds2 = _end.tv_sec - _begin.tv_sec;
  _microseconds2 = _end.tv_usec - _begin.tv_usec;
  _elapsed2 = _seconds2 + _microseconds2*1e-6;
}
void                    PerformanceChecker::print() const {
  std::cout << PURPLE << "Time measured : " << std::setprecision(5) << std::fixed << YELLOW << _elapsed1 * 1e+6 << WHITE << " Ms" << RESET << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

size_t const &          PerformanceChecker::getMicroSecondsFirst() const {
  return _microseconds1;
}
size_t const &          PerformanceChecker::getSecondsFirst() const {
  return _seconds1;
}
double const &          PerformanceChecker::getElapsedFirst() const {
  return _elapsed1;
}
size_t const &          PerformanceChecker::getMicroSecondsSecond() const {
  return _microseconds2;
}
size_t const &          PerformanceChecker::getSecondsSecond() const {
  return _seconds2;
}
double const &          PerformanceChecker::getElapsedSecond() const {
  return _elapsed2;
}


/* ************************************************************************** */