/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:22:26 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/26 19:46:41 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <map>
#include <vector>

int main( void ) {

    std::vector<int>  lst;

    lst.push_back(0);
    lst.push_back(5);
    lst.push_back(6);
    lst.push_back(7);

    try
    {
        std::vector<int>::iterator it = easyfind( lst, 4 );
        (void)it;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::vector<int>::iterator it = easyfind( lst, 5 );
    for (; it != lst.end(); ++it) {
        std::cout << *it << std::endl;
    }
    
    return (0);
}