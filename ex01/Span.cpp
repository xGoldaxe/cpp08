/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:27:43 by pleveque          #+#    #+#             */
/*   Updated: 2022/03/30 21:20:42 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm> 
#include "Span.hpp"
#include <stdlib.h>
#include <limits>
#include <climits>

/* COPLIEN */

Span::Span( void ) : _n( 0 ),  _space( 0 ), _tab( std::vector<int>(0) )	{

    return ;
}

Span::Span( unsigned int n ) : _n( n ), _space( n ), _tab( std::vector<int>(n) )	{

    return ;
}

Span::~Span( void ) {

    return ;
}

Span::Span( Span const &src ) : _n( src.getN() ), _space( src.getSpace() ), _tab( std::vector<int>(0) )	{

    *this = src;
    
    return ;
}

Span &	Span::operator=( Span const & rhs )	{

    if ( this != &rhs ) {

        this->_n = rhs.getN();
        this->_space = rhs.getSpace();
        std::vector<int>::iterator start = rhs.getTab().begin();
        std::vector<int>::iterator end = rhs.getTab().end();
        this->addRange( start, end );
    }

    return (*this);
}

/* END COPLIEN */

unsigned int	Span::getN( void ) const	{

    return ( this->_n );
}

const std::vector<int> &	Span::getTab( void ) const	{

    return ( this->_tab );
}

unsigned int	Span::getSpace( void ) const	{

    return ( this->_space );
}

/* others */

void	Span::addNumber( int value )	{

    if ( this->_space <= 0 )
        throw ( Span::fullException() );
    this->_tab[this->_n - this->_space] = value;
    return ;
}

unsigned int    getDiff( int a, int b ) {

    if ( a >= 0 && b >= 0 )
        return (static_cast<unsigned int>(abs(a - b)));
    else if ( a < 0 && b < 0 )
        return (static_cast<unsigned int>(abs(a + b)));
    else {
        return ( 
            static_cast<unsigned int>(abs(a))
            + static_cast<unsigned int>(abs(b))
        );
    }
}

unsigned int	Span::shortestSpan( void )	{

    if ( (this->_n - this->_space) < 2 )
        throw ( Span::tooSmallException() );

    unsigned int diff = std::numeric_limits<unsigned long>::max();
    for (unsigned int i = 0; i < (this->_n - this->_space)- 1; i++)
    {
        unsigned int newDiff = getDiff( this->_tab[i], this->_tab[i + 1]);
        diff = std::min<unsigned int>( newDiff, diff );
    }
    
    return ( diff );
}

unsigned int	Span::longestSpan( void )	{

    if ( (this->_n - this->_space) < 2 )
        throw ( Span::tooSmallException() );

    int min = *std::min_element( this->_tab.begin(), this->_tab.end() );
    int max = *std::max_element( this->_tab.begin(), this->_tab.end() );

    return getDiff(min, max);
}

void	Span::addRange(
    std::vector<int>::iterator start,
    std::vector<int>::iterator end )
{

    if ( static_cast<unsigned int>(std::distance(start, end)) > this->_space )
        throw ( Span::fullException() );
    std::copy( start, end, this->_tab.begin() );
    return ;
}