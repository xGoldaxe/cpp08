/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:22:26 by pleveque          #+#    #+#             */
/*   Updated: 2022/03/30 14:39:58 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <map>
#include <list>

int main( void ) {

    std::list<int>  lst;

    lst.push_back(0);
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    std::cout << "index find: " << easyfind< std::list<int> >( lst, 4 ) << std::endl;
    return (0);
}