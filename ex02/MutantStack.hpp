/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:52:28 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/26 20:49:29 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#	define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <iterator>
#include <stack>

template < typename T >
class MutantStack : public std::stack<T>
{

    public:
        /* coplien */
        MutantStack( void ) {

            std::cout << "Mutant created" << std::endl;
        };
        ~MutantStack( void ) {

            std::cout << "Mutant destroyed" << std::endl;
        };
        /* end coplien */

        /* ITERATOR */

        /* *************
        * @iterator class
        ************* */
        class iterator: public std::iterator<
            std::bidirectional_iterator_tag,   // iterator_category
            T,                      // value_type
            T,                      // difference_type
            T*,                     // pointer
            T                       // reference
        > {
            private:
                T* _from;
                T* _to;
                unsigned int _actual;

            public:
                iterator( void ) {}

                /* coplien */
                iterator( T* from, T* to, unsigned int actual ) : _from( from ), _to( to ), _actual( actual ) {
                    std::cout << "Iterator created" << std::endl;
                }

                iterator( iterator const & ref ) : _from ( ref.getFrom() ), _to ( ref.getTo() ), _actual( ref.getActual() )  {
                    std::cout << "iterator copy constructor" << std::endl;
                }
                
                iterator &operator=( const iterator & rhs ) {

                    std::cout << "= overload" << std::endl;
                    this->_from = rhs.getFrom();
                    this->_to = rhs.getTo();
                    this->_actual = rhs.getActual();
                    return (*this);
                }

                ~iterator() {
                    std::cout << "Iterator destroyed" << std::endl;
                }
                /* end coplien */

                /* getter */
                unsigned int	getActual( void ) const	{
                
                    return ( this->_actual );
                }
                T*	getTo( void ) const	{
                
                    return ( this->_to );
                }
                T*  getFrom( void ) const {
                
                    return ( this->_from );
                }

                /* operator overload */
                iterator &  operator++() {
                    if ( this->_from + this->_actual > this->_to )
                        this->_actual = 0;
                    else
                        this->_actual++;
                    return ( *this );
                }
                iterator  operator++(int) {
                    iterator retval( *this );
                    ++(*this);
                    return ( retval );
                }

                iterator &  operator--() {
                    this->_actual--;
                    return ( *this );
                }
                iterator  operator--(int) {
                    iterator retval( *this );
                    --(*this);
                    return ( retval );
                }

                bool    operator==( iterator &other ) const {
                    return ( this->_from + this->_actual == other.getFrom() + other.getActual() );
                }
                bool    operator!=( iterator &other ) const {
                    return ( !(this->_from + this->_actual == other.getFrom() + other.getActual() ) );
                }

                T   operator*() const {
                    if ( this->_from + this->_actual > this->_to )
                    {
                        return ( *(T*)&this->_actual );
                    }
                    return ( *(this->getFrom() + this->_actual ) ); 
                }
                /* end overload */
        };
        
        /* iterator getter */
        iterator end( void ) {
            T* bottom = &this->top() - (this->size() - 1);
            return iterator( bottom, &this->top(), this->size() );
        }

        iterator begin( void ) {
            T* bottom = &this->top() - (this->size() - 1);
            return iterator( bottom, &this->top(), 0 );
        }
};


#endif