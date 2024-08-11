#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <class T >
class MutantStack : public std::stack<T>{
public:
	MutantStack(){}
	MutantStack(const MutantStack &obj){
		*this = obj;
	}
	MutantStack &operator=(const MutantStack &obj){
		if (this != &obj)
			std::stack<T>::operator=(obj);
		return (*this);
	}
	~MutantStack(){}

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin(){
		return this->c.begin();
	}
	iterator end(){
		return this->c.end();
	}
};

#endif
