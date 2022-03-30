/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:27:43 by pleveque          #+#    #+#             */
/*   Updated: 2022/03/30 16:53:30 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm> 
#include "Span.hpp"
#include <stdlib.h>
#include <limits>
#include <climits>

/* COPLIEN */

Span::Span( void ) : _n( 0 ), _size( 0 ), _tab( NULL )	{

    return ;
}

Span::Span( unsigned int n ) : _n( n ), _size( 0 ), _tab( new int[n] )	{

    return ;
}

Span::~Span( void ) {

    delete[] _tab;
    return ;
}

Span::Span( Span const &src ) : _n( src.getN() ), _size( src.getSize() ),  _tab( NULL )	{

    *this = src;
    
    return ;
}

Span &	Span::operator=( Span const & rhs )	{

    if ( this != &rhs ) {

        this->_n = rhs.getN();
        this->_size = rhs.getSize();
        delete[] this->_tab;
        this->_tab = new int[rhs.getN()];
        for (unsigned int i = 0; i < rhs.getN(); i++)
            this->_tab[i] = rhs.getTab()[i];
    }

    return (*this);
}

/* END COPLIEN */

unsigned int	Span::getN( void ) const	{

    return ( this->_n );
}

int *	Span::getTab( void ) const	{

    return ( this->_tab );
}

unsigned int	Span::getSize( void ) const	{

    return ( this->_size );
}

/* others */

void	Span::addNumber( int value )	{

    if ( this->_size >= this->_n )
        throw ( Span::fullException() );
    this->_tab[this->_size] = value;
    this->_size += 1;
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

    if ( this->_size < 2 )
        throw ( Span::tooSmallException() );

    unsigned int diff = std::numeric_limits<unsigned long>::max();
    for (unsigned int i = 0; i < this->_size - 1; i++)
    {
        unsigned int newDiff = getDiff( this->_tab[i], this->_tab[i + 1]);
        diff = std::min<unsigned int>( newDiff, diff );
    }
    
    /* CODE HERE */
    return ( diff );
}

unsigned int	Span::longestSpan( void )	{

    if ( this->_size < 2 )
        throw ( Span::tooSmallException() );

    int min = *std::min_element( this->_tab, this->_tab + this->_size );
    int max = *std::max_element( this->_tab, this->_tab + this->_size );

    return getDiff(min, max);
}