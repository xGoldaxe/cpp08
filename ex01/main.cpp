/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:44:45 by pleveque          #+#    #+#             */
/*   Updated: 2022/05/03 10:50:27 by pleveque         ###   ########.fr       */
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
    std::cout << "<-----------{42 main}----------->" << std::endl;
    Span s = Span(5);
    s.addNumber(6);
    s.addNumber(3);
    s.addNumber(17);
    s.addNumber(9);
    s.addNumber(11);
    std::cout << s.shortestSpan() << std::endl;
    std::cout << s.longestSpan() << std::endl;

    std::cout << "<-----------{other main}----------->" << std::endl;

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
    Span ope;
    ope = sp;

    std::cout << ope.shortestSpan() << std::endl;
    std::cout << ope.longestSpan() << std::endl;
    std::cout << cpy.shortestSpan() << std::endl;
    std::cout << cpy.longestSpan() << std::endl;

    std::cout << "<-----------{10000}----------->" << std::endl;
    srand (time(NULL));
    Span spk = Span(10000);
    for (size_t i = 0; i < 10000; i++)
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
    v.push_back( 6 );
    v.push_back( 3 );
    v.push_back( 17 );
    v.push_back( 9 );

    spore.addNumber( 11 );
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