/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:47:09 by pleveque          #+#    #+#             */
/*   Updated: 2022/03/30 14:38:50 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#	define EASYFIND_HPP


#include <iostream>
#include <algorithm>

/* return index, -1 if doesnt exit */

template < typename T >
int easyfind ( T tab, int value ) {

    typename T::iterator it = std::find ( tab.begin(), tab.end(), value );
    if ( it != tab.end() )
        return ( std::distance(tab.begin(), it) );
    return ( -1 );
}

#endif