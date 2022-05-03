#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> st;
	st.push(5);
	st.push(17);
	// std::cout << st.top() << std::endl;
	// mstack.pop();
	std::cout << st.size() << std::endl;
	std::cout << "<-----------{ iterate }----------->" << std::endl;
	st.push(3);
	st.push(5);
	st.push(737);
	st.push(0);
	MutantStack<int> ms(st);
	MutantStack<int> mstack;
	mstack = ms;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	it--;
	MutantStack<int>::iterator itr;
	std::cout << "<-----------{ reverse iterate }----------->" << std::endl;
	itr = mstack.begin();
	while (it != itr)
	{
		std::cout << *it << std::endl;
		--it;
	}
	std::cout << *it << std::endl;
	std::cout << "<-----------{ reverse iterator }----------->" << std::endl;
	MutantStack<int>::reverse_iterator itre = mstack.rbegin();
	while (itre != mstack.rend())
	{
		std::cout << *itre << std::endl;
		++itre;
	}
	std::cout << "<-----------{traits}----------->" << std::endl;
    std::cout << sizeof( std::iterator_traits<MutantStack<std::string>::iterator >::pointer ) << std::endl;
    std::cout << sizeof( std::iterator_traits<MutantStack<std::string>::iterator >::difference_type ) << std::endl;
    std::cout << sizeof( std::iterator_traits<MutantStack<std::string>::iterator >::value_type ) << std::endl;
    std::cout << sizeof( std::iterator_traits<MutantStack<std::string>::iterator >::iterator_category ) << std::endl;

	return 0;
}