/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:48:12 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/26 20:35:01 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main( void ) {

    MutantStack<int> mstacks;

    mstacks.push(2);
    mstacks.push(17);
    mstacks.push(12);
    mstacks.push(1);
    mstacks.push(9);
    MutantStack<int> mstackx( mstacks );
    MutantStack<int> mstack;
    mstack = mstackx;

    std::cout << mstack.top() << std::endl;
    std::cout << mstack.size() << std::endl;

    std::cout << *( &mstack.top() - (mstack.size() - 1)) << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << *it << std::endl;
    std::cout << *ite << std::endl;

    std::cout << *it++ << std::endl;
    std::cout << *it << std::endl;

    std::cout << "<-----------{=operator}----------->" << std::endl;
    MutantStack<int>::iterator cpyop = mstack.begin();
    cpyop = it;
    while (cpyop != ite)
    {
        std::cout << *cpyop << std::endl;
        ++cpyop;
    }
    //should be 5, the size
    std::cout << *cpyop << std::endl;
    std::cout << *++cpyop << std::endl;

    std::cout << "<-----------{cpy}----------->" << std::endl;
    MutantStack<int>::iterator cpy(it);
    while (cpy != ite)
    {
        std::cout << *cpy << std::endl;
        ++cpy;
    }

    std::cout << "<-----------{iterate}----------->" << std::endl;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "<-----------{temoin}----------->" << std::endl;
    std::list<std::string> lst;
    lst.push_back("salut");
    lst.push_back("a");
    lst.push_back("tous");
    lst.push_back("les");
    lst.push_back("amis");
    std::list<std::string>::iterator lit = lst.begin();
    std::list<std::string>::iterator lite = lst.end();
    std::cout << *lit << std::endl;
    // std::cout << *lite << std::endl;

    std::cout << *lit++ << std::endl;
    std::cout << *lit << std::endl;
    std::cout << "<-----------{ite}----------->" << std::endl;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
    // std::cout << *lit << std::endl;
    std::cout << "<-----------{lite}----------->" << std::endl;
    std::cout << *++lite << std::endl;
    std::cout << *++lite << std::endl;
    std::cout << *++lite << std::endl;

    std::cout << "<-----------{my version}----------->" << std::endl;
    MutantStack<std::string> mv;
    mv.push("salut");
    mv.push("a");
    mv.push("tous");
    mv.push("les");
    mv.push("amis");
    MutantStack<std::string>::iterator mvi = mv.begin();
    MutantStack<std::string>::iterator mvie = mv.end();
    std::cout << *mvi << std::endl;
    // std::cout << *lite << std::endl;

    std::cout << *mvi++ << std::endl;
    std::cout << *mvi << std::endl;
    std::cout << "<-----------{ite}----------->" << std::endl;
    while (mvi != mvie)
    {
        std::cout << *mvi << std::endl;
        ++mvi;
    }
    // std::cout << *lit << std::endl;
    std::cout << "<-----------{lite}----------->" << std::endl;
    std::cout << *++mvie << std::endl;
    std::cout << *++mvie << std::endl;
    std::cout << *++mvie << std::endl;

    std::cout << "<-----------{traits}----------->" << std::endl;
    std::cout << sizeof( std::iterator_traits<MutantStack<std::string>::iterator >::pointer ) << std::endl;
    std::cout << sizeof( std::iterator_traits<MutantStack<std::string>::iterator >::difference_type ) << std::endl;
    std::cout << sizeof( std::iterator_traits<MutantStack<std::string>::iterator >::value_type ) << std::endl;
    std::cout << sizeof( std::iterator_traits<MutantStack<std::string>::iterator >::iterator_category ) << std::endl;
    return (0);
}
