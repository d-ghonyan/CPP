#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top before pop(): "<< mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	std::cout << "size: " << mstack.size() << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();


	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "---------------------------------------------------\n";
	MutantStack<int> mstack2;
	MutantStack<int> mstack3(mstack);

	mstack2 = mstack;

	std::cout << "\n";
	std::cout << mstack2.top() << "\n";
	mstack2.pop();
	std::cout << mstack2.top() << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << mstack3.top() << "\n";
	mstack3.pop();
	std::cout << mstack3.top() << "\n";
	std::cout << "\n";

	std::stack<int> s(mstack);
	
	for (; s.size(); )
	{
		std::cout << s.top() << "\n";
		s.pop();
	}
	
	return 0;
}

// int main()
// {
// 	MutantStack<int> ms;

// 	for (int i = 0; i < 100; i++)
// 		ms.push(i);

// 	std::cout << *(ms.begin()) << "\n";
// 	std::cout << *(ms.end() - 1) << "\n";
// }