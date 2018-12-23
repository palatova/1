#include<iostream>
#include"stack_on_list.h"
#include<stdexcept>
#include <stack>
//конструктор копирования для стека 
StackOnList::StackOnList(const StackOnList& obj) 
	:data_(obj.data_)
{
	StackOnList nstack;
	Node *head = obj.data_->next;
	while (head!= nullptr) {
		nstack.Push(head->data);
		head = head->next;
	}
	
}
StackOnList::~StackOnList() {
	Clear();
}
StackOnList& StackOnList::operator=(const StackOnList& obj)
{
	if (this != &obj) {
		StackOnList nstack;
		Node *head = obj.data_;
		while (head != nullptr) {
			nstack.Push(head->data);
			head = head->next;
		}
	}
	return *this;
}
int StackOnList::Top() const {
	if (nullptr == data_) {
		throw std::logic_error("Try get top from empty stack");
	}
	return data_->data;
}
void StackOnList::Pop() noexcept {
	if (nullptr != data_) {
		Node* node_deleted(data_);
		data_ = data_->next;
		delete node_deleted;
	}
}
void StackOnList::Clear() noexcept {
	while (!IsEmpty()) {
		Pop();
	}
}
bool StackOnList::IsEmpty()const noexcept {
	return nullptr == data_;
}
void StackOnList::Push(const int value) {
	data_ = new Node(data_, value);
}

std::ostream& StackOnList::WriteTo(std::ostream& ostrm) const{
	Node* printed_node(data_);
	ostrm << '{';
	while (printed_node){
		ostrm << printed_node->data;
		printed_node = printed_node->next;
		if (printed_node) {
			ostrm << ", ";
		}
	}
	ostrm << '}';
	return ostrm;
}



