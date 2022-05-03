/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:52:28 by pleveque          #+#    #+#             */
/*   Updated: 2022/05/03 11:18:51 by pleveque         ###   ########.fr       */
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
        MutantStack( const MutantStack &src ) : std::stack<T>(src) {

            std::cout << "Mutant copy construction" << std::endl;
            // *this = src;
        }
        ~MutantStack( void ) {

            std::cout << "Mutant destroyed" << std::endl;
        };
        MutantStack &operator=( const MutantStack &rhs ) {

            std::stack<T>::operator=(rhs);
            std::cout << "mutant assignation" << std::endl;
            return *this;
        }
        /* end coplien */

        /* ITERATOR */
        typedef typename std::stack<T>::container_type::iterator                    iterator;
        typedef typename std::stack<T>::container_type::const_iterator              const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator            reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator      const_reverse_iterator;

        /* iterators */
        iterator            begin( void ) { return std::stack<T>::c.begin(); }
        const_iterator      begin( void ) const { return std::stack<T>::c.begin(); }
        iterator            end( void ) { return std::stack<T>::c.end(); }
        const_iterator      end( void ) const { return std::stack<T>::c.end(); }

        /* reverse iterators */
        reverse_iterator            rbegin( void ) { return std::stack<T>::c.rbegin(); }
        const_reverse_iterator      rbegin( void ) const { return std::stack<T>::c.rbegin(); }
        reverse_iterator            rend( void ) { return std::stack<T>::c.rend(); }
        const_reverse_iterator      rend( void ) const { return std::stack<T>::c.rend(); }
};


#endif