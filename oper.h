#ifndef OPER_H
#define OPER_H

#include "token.h"
#include "listStack.h"
//#include "listQueue.h"


class oper : public token
{
public:
	oper(){};
	~oper(){};

	void (*fptr)(listStack<token*>& numbers);
	int precedence;
};

#endif
