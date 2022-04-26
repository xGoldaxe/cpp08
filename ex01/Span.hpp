/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:52:15 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/26 20:22:10 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#	define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>

class Span
{

    private:
        unsigned int    _n;
        unsigned int    _space;
        std::vector<int>  _tab;

    protected:
        unsigned int	getN( void ) const;
        unsigned int	getSpace( void ) const;
        const std::vector<int> &	getTab( void ) const;

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

        /* add range */
        template< class Iter >
        void	addRange(
            Iter start,
            Iter end )
        {

            unsigned int distance = static_cast<unsigned int>(std::distance(start, end));
            if (distance > this->_space )
                throw ( fullException() );
            this->_space -= distance;
            std::copy( start, end, this->_tab.begin() );
            return ;
        };
};


#endif