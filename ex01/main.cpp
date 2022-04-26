/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:44:45 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/26 20:21:00 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <stdlib.h>
#include <vector>
#include <time.h> 
#include <list>
#include <iterator>

int main()
{
    Span sp = Span(5);

    
    sp.addNumber(6);
    sp.addNumber(2147483647);    
    sp.addNumber(-2147483648);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "<-----------{cpy}----------->" << std::endl;
    Span cpy( sp );
    Span ope = sp;

    std::cout << ope.shortestSpan() << std::endl;
    std::cout << ope.longestSpan() << std::endl;
    std::cout << cpy.shortestSpan() << std::endl;
    std::cout << cpy.longestSpan() << std::endl;

    std::cout << "<-----------{1000k}----------->" << std::endl;
    srand (time(NULL));
    Span spk = Span(1000000);
    for (size_t i = 0; i < 1000000; i++)
    {
        spk.addNumber( rand() );
    }
    std::cout << spk.shortestSpan() << std::endl;
    std::cout << spk.longestSpan() << std::endl;

    std::cout << "<-----------{exceptions}----------->" << std::endl;

    try
    {
        sp.addNumber(7);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    Span sp2 = Span(5);
    try
    {
        std::cout << sp2.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "<-----------{generator}----------->" << std::endl;
    Span spore = Span(5);
    std::list<int> v;
    v.push_back( 10 );
    v.push_back( 20 );
    v.push_back( 30 );
    v.push_back( 40 );
    v.push_back( 60 );

    spore.addRange( v.begin(), v.end() );
    //should print 10 and 50
    std::cout << spore.shortestSpan() << std::endl;
    std::cout << spore.longestSpan() << std::endl;

    std::cout << "<-----------{exception}----------->" << std::endl;
    try
    {
        Span spare = Span(2);
        // 5 in 2, will throw a full error
        spare.addRange( v.begin(), v.end() );
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}