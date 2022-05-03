#include "MutantStack.hpp"
#include <list>

int main()
{
	std::list<int> st;
	st.push_back(5);
	st.push_back(17);
	// std::cout << st.top() << std::endl;
	// mstack.pop();
	std::cout << st.size() << std::endl;
	std::cout << "<-----------{ iterate }----------->" << std::endl;
	st.push_back(3);
	st.push_back(5);
	st.push_back(737);
	st.push_back(0);
	std::list<int> ms(st);
	std::list<int> mstack;
	mstack = ms;
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	it--;
	std::list<int>::iterator itr;
	std::cout << "<-----------{ reverse iterate }----------->" << std::endl;
	itr = mstack.begin();
	while (it != itr)
	{
		std::cout << *it << std::endl;
		--it;
	}
	std::cout << *it << std::endl;
	std::cout << "<-----------{ reverse iterator }----------->" << std::endl;
	std::list<int>::reverse_iterator itre = mstack.rbegin();
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