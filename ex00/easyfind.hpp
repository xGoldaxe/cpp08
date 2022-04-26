/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:47:09 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/26 19:46:44 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#	define EASYFIND_HPP


#include <iostream>
#include <algorithm>
#include <vector>

template < typename T >
typename T::iterator easyfind ( T & tab, int value ) {

    typename T::iterator it = std::find ( tab.begin(), tab.end(), value );
    if ( it != tab.end() )
        return ( it );
    throw std::exception();
}

#endif