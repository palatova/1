#include<iostream>
#include <sstream>
#include"stack_on_list.h"
int main() {
	StackOnList stDef;
	std::cout << "Let's create stack. Stack is " << stDef << std::endl;
	std::cout << "Is def create stack emty -> " << stDef.IsEmpty() << std::endl;

	StackOnList st;
	int val(10);
	std::cout << "Let's push " << val << std::endl;
	st.Push(val);
	std::cout << "Stack1 is " << st << std::endl;
	st.Push(12);
	st.Push(13);
	StackOnList st2 =st;
	std::cout << "Check operator= stack2 = stack1 = " << st2 << std::endl;
	std::cout << "Is stack empty -> " << st.IsEmpty() << std::endl;
	std::cout << "Top value is   -> " << st.Top() << std::endl;
	std::cout << "Let's pop " << std::endl;
	st.Pop();
	std::cout << "Stack is " << st << std::endl;
	std::cout << "Is stack empty -> " << st.IsEmpty() << std::endl;

	std::cout << "Let's push values from " << (val + 1) << " to " << (val + 3) << std::endl;
	st.Push(val + 1);
	st.Push(val + 2);
	st.Push(val + 3);
	std::cout << "Stack is " << st << std::endl;
	std::cout << "Top value is   -> " << st.Top() << std::endl;
	system("pause");
}



