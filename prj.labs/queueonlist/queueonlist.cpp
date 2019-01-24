/*#include<iostream>
#include"queueonlist.h"
#include<stdexcept>

Queue::QueueOnList(const Queue& obj)
	:data_(obj.data_)
{
	QueueOnList nqueue;

	Node *head = obj.data_->next; // to next or not to next - that is the question...

	while (head != nullptr) {
		nstack.Push(head->data);
		head = head->next;
	}

}
QueueOnList::~QueueOnList() {
	Clear();
}
QueueOnList& QueueOnList::operator=(const QueueOnList& obj)
{
	if (this != &obj) {
		QueueOnList nstack;
		Node *head = obj.data_;
		while (head != nullptr) {
			nstack.Push(head->data);
			head = head->next;
		}
	}
	return *this;
}
int QueueOnList::Top() const {
	if (nullptr == data_) {
		throw std::logic_error("Try get top from empty stack");
	}
	return data_->data;
}
void QueueOnList::Pop() noexcept {
	if (nullptr != data_) {
		Node* node_deleted(data_);
		data_ = data_->next;
		delete node_deleted;
	}
}
void QueueOnList::Clear() noexcept {
	while (!IsEmpty()) {
		Pop();
	}
}
bool QueueOnList::IsEmpty()const noexcept {
	return nullptr == data_;
}
void QueueOnList::Push(const int value) {
	data_ = new Node(data_, value);
}

std::ostream& QueueOnList::WriteTo(std::ostream& ostrm) const {
	Node* printed_node(data_);
	ostrm << '{';
	while (printed_node) {
		ostrm << printed_node->data;
		printed_node = printed_node->next;
		if (printed_node) {
			ostrm << ", ";
		}
	}
	ostrm << '}';
	return ostrm;
}
*/
#include "queueonlist.h"



Queue::Queue(int size)

	:size_(size + 1)

{

	data_ = new int[size_];

}



Queue::Queue(const Queue& queue)

	: size_(queue.size_)

	, first_(queue.first_)

	, last_(queue.last_)

{

	data_ = new int[size_];

	for (int i = 0; i < size_; i++)

	{

		data_[i] = queue.data_[i];

	}

}



Queue::~Queue()

{

	delete[] data_;

}



bool Queue::IsEmpty() const

{

	return first_ == last_;

}



bool Queue::IsFull() const

{

	return (first_ == (last_ + 1) % size_) && ((size_ - 1) != 0);

}



int Queue::Top() const

{

	if (IsEmpty())

	{

		throw std::out_of_range("empty");

	}

	return data_[first_];

}



int Queue::Pop()

{

	if (IsEmpty())

	{

		throw std::out_of_range("empty");

	}

	int data = data_[first_];

	first_ = (first_ + 1) % size_;

	return data;

}



void Queue::Push(int value)

{

	if (IsFull())

	{

		throw std::out_of_range("full");

	}

	data_[last_] = value;

	last_ = (last_ + 1) % size_;

}



std::ostream & Queue::WriteTo(std::ostream & strm) const

{

	strm << "{";

	if (size_ > 1)

	{

		int i = first_;

		while (i != last_)

		{

			strm << data_[i];

			i = (i + 1) % size_;

			if (last_ != i)

			{

				strm << ", ";

			}

		}

	}

	strm << "}";

	return strm;

}



Queue& Queue::operator=(const Queue& queue)

{

	if (this != &queue)

	{

		if (queue.size_ > size_)

		{

			int* new_data = new int[queue.size_];

			delete data_;

			data_ = new_data;

		}

		int i = queue.first_;

		while (i != queue.last_)

		{

			data_[i] = queue.data_[i];

			i = (i + 1) % queue.size_;

		}

		first_ = queue.first_;

		last_ = queue.last_;

	}

	return *this;

}



std::ostream& operator<<(std::ostream& strm, Queue& queue)

{

	return queue.WriteTo(strm);

}



int Queue::GetSize()

{

	return size_ - 1;

}
using namespace std;



Queue queue1;

cout << "Check default contructor. Return: ";

queue1.WriteTo(cout);

cout << endl << endl;

Queue queue2(13);

cout << "Check constructor with size in parametr. Queue size = 13. GetSize return: ";

cout << queue2.GetSize() << endl << endl;

queue2.Push(2);

queue2.Push(4);

queue2.Push(27);

queue2.Push(7);

Queue queue3(queue2);

cout << "Check constructor with queue in parametr. " << endl;

cout << "queue2: ";

queue2.WriteTo(cout);

cout << endl;

cout << "queue2 size = " << queue2.GetSize() << endl;

cout << "queue3(queue2) return queue3: ";

queue3.WriteTo(cout);

cout << endl;

cout << "queue3 size = " << queue3.GetSize() << endl;

cout << endl;

cout << "Check function IsEmpty. queue1 is empty. queue1.IsEmpty() return: ";

cout << queue1.IsEmpty() << endl << endl;

cout << "Check function IsEmpty. queue2 isn't empty. queue2.IsEmpty() return: ";

cout << queue2.IsEmpty() << endl << endl;

queue2.Push(7);

queue2.Push(7);

queue2.Push(7);

queue2.Push(7);

queue2.Push(7);

queue2.Push(7);

queue2.Push(7);

queue2.Push(7);

queue2.Push(7);

cout << "Check function Full. queue2 is full. queue2.IsFull() return: ";

cout << queue2.IsFull() << endl << endl;

cout << "Check function IsFull. queue1 isn't full. queue1.IsFull() return: ";

cout << queue1.IsFull() << endl << endl;

cout << "Check function Top(). queue3: ";

queue3.WriteTo(cout);

cout << endl;

cout << "queue3.Top() return: " << queue3.Top() << endl << "queue3 retern: ";

queue3.WriteTo(cout);

cout << endl << endl;

cout << "Check function Pop(). queue3: ";

queue3.WriteTo(cout);

cout << endl;

cout << "queue3.Pop() return: " << queue3.Pop() << endl << "queue3 retern: ";

queue3.WriteTo(cout);

cout << endl << endl;

cout << "Check function GetSize. queue size = 13. queue.GetSize() return: " << queue2.GetSize() << endl << endl;

cout << "Check function Push(). queue3 :";

queue3.WriteTo(cout);

cout << endl;

cout << "queue3.Push(15) return queue3: ";

queue3.Push(15);

queue3.WriteTo(cout);

cout << endl << endl;

cout << "Check operator=. " << endl;

cout << "queue2: ";

queue2.WriteTo(cout);

cout << endl;

cout << "queue3: ";

queue3.WriteTo(cout);

cout << endl;

cout << "queue2 = queue3 return queue2: ";

queue2 = queue3;

queue2.WriteTo(cout);

cout << endl << endl;



