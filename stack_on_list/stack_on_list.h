#pragma once
#ifndef STACK_ON_LIST_H
#define STACK_ON_LIST_H

#include <iostream>
#include <iosfwd>

class StackOnList
{
public:
	StackOnList() = default;
	StackOnList(const StackOnList& obj);
	StackOnList& operator =(const StackOnList& obj);
	void Push(const int value); //эта штука будет присваиваивать значение следующему элементу
	~StackOnList();
	bool IsEmpty() const noexcept;
	void Pop() noexcept;
	int Top() const;
	void Clear() noexcept;
	std::ostream& WriteTo(std::ostream& ostrm) const;
private:
	struct Node {
		Node* next{ nullptr };
		int data{ 0 };
		Node(Node* p, const int v)
			:next(p), data(v) {

		}
	};
private:
	Node * data_{ nullptr };

	};

inline std::ostream& operator <<(std::ostream& ostrm, const StackOnList& stack ){
	return stack.WriteTo(ostrm);
};



#endif STACK_ON_LIST_H







