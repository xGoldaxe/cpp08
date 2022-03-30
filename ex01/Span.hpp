/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:52:15 by pleveque          #+#    #+#             */
/*   Updated: 2022/03/30 16:24:45 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#	define SPAN_HPP

#include <iostream>
#include <string>

class Span
{

    private:
        unsigned int    _n;
        unsigned int    _size;
        int * _tab;

    public:
        /* coplien */
        Span( void );
        Span( unsigned int n );
        Span( Span const &src );
        ~Span( void );

        Span &   operator=( Span const & rhs );
        /* end coplien */
        void	addNumber( int value );
        unsigned int    shortestSpan( void );
        unsigned int    longestSpan( void );

        unsigned int	getN( void ) const;
        int *	getTab( void ) const;
        unsigned int	getSize( void ) const;
        

        /* exceptions */
        class fullException : public std::exception	{
            public:
                virtual const	char* what() const throw()	{
                    return ("Span: Span is already full");
                }
        };

        class tooSmallException : public std::exception	{
            public:
                virtual const	char* what() const throw()	{
                    return ("Span: Size is too small");
                }
        };
};


#endif