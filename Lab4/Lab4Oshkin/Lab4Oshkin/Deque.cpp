#include <cstddef>
#include <iostream>
template<typename T>
class DequeBasedOnUnidirectionalLinkedList {

private:
	class Node
	{
	public:
		Node* next;
		T value;
		Node() : next(nullptr), value(NULL) {}
		Node(T v) : next(nullptr), value(v) {}
		//		Node(T v) : next(nullptr), value(v) {}
				//Node(int* v) : next(nullptr), value(v) {}
	};
	Node* first;
	Node* last;
	int count;
public:

	DequeBasedOnUnidirectionalLinkedList() {
		first = nullptr;
		last = nullptr;
		count = 0;
	}
	DequeBasedOnUnidirectionalLinkedList(std::initializer_list<int> ilist) {
		first = nullptr;
		last = nullptr;
		count = 0;
		for (T i : ilist)
		{
			PushBack(i);
		}
	}
	~DequeBasedOnUnidirectionalLinkedList()
	{
		if (count == 0)
			return;
		Node* newLast = first;
		while (true)
		{
			if (newLast->next == nullptr)
			{
				delete newLast;
				break;
			}
			Node* temp = newLast->next;
			delete newLast;
			newLast = temp;
		}
		count = 0;
	}
	DequeBasedOnUnidirectionalLinkedList(const DequeBasedOnUnidirectionalLinkedList& deque)
	{
		first = deque.first;
		last = deque.last;
		count = deque.count;
	}
	DequeBasedOnUnidirectionalLinkedList(DequeBasedOnUnidirectionalLinkedList&& other)
	{
		first = other.first;
		last = other.last;
		count = other.count;
		other.first = nullptr;
		other.last = nullptr;
		other.count = 0;
	}
	DequeBasedOnUnidirectionalLinkedList& operator=(DequeBasedOnUnidirectionalLinkedList&& other)
	{
		if (this == &other)
		{
			return *this;
		}
		if (count != 0)
		{
			Node* newLast = first;
			while (true)
			{
				if (newLast->next == nullptr)
				{
					delete newLast;
					break;
				}
				Node* temp = newLast->next;
				delete newLast;
				newLast = temp;
			}
			count = 0;
		}
		first = other.first;
		last = other.last;
		count = other.count;
		other.first = nullptr;
		other.last = nullptr;
		other.count = 0;
	}



	unsigned  GetSize() const {
		return count;
	}
	bool PushFront(const T& element) {
		Node* newNode = nullptr;
		try {
			newNode = new Node(element);
		}
		catch (std::string error_message) {
			return false;
		}
		newNode->next = first;
		first = newNode;
		if (last == nullptr)
			last = first;
		count++;
		return true;
	}
	bool PopFront(T& element) {
		if (count == 0)
			return false;
		element = first->value;
		count--;
		if (first == last)
		{
			delete first;
			first = nullptr;
			last = nullptr;
			return true;
		}
		Node* newFirst = first->next;
		delete first;
		first = newFirst;
		return true;
	}
	bool PushBack(const T& element) {
		Node* newNode = nullptr;
		try {
			newNode = new Node(element);
		}
		catch (std::string error_message) {
			return false;
		}
		if (nullptr == last)
		{
			last = newNode;
			first = newNode;
		}
		else {
			last->next = newNode;
			last = newNode;

		}
		count++;
		return true;
	}
	bool PopBack(T& element) {
		if (count == 0)
			return false;
		element = last->value;
		count--;
		if (first == last)
		{
			delete last;
			first = nullptr;
			last = nullptr;
			return true;
		}
		Node* newLast = first;
		while (true)
		{
			if (newLast->next == last)
				break;
			newLast = newLast->next;
		}
		delete last;
		last = newLast;
		return true;
	}
	bool PeekFront(T& element) const {
		if (count == 0)
			return false;
		element = first->value;
		return true;

	}
	bool PeekBack(T& element) const {
		if (count == 0)
			return false;
		element = last->value;
		return true;
	}
	void InsertAt(T value, int index) {
		if (index < 0 || index > count)
			return;
		Node* newNode = new Node(value);
		count++;
		if (index == 0)
		{
			newNode->next = first;
			first = newNode;
			return;
		}
		if (index == count - 1)
		{
			last->next = newNode;
			last = newNode;
			return;
		}
		Node* tempPrev = first;
		Node* tempNext = first->next;
		for (int i = 1; i <= index; i++)
		{
			tempPrev = tempNext;
			tempNext = tempNext->next;
		}
		tempPrev->next = newNode;
		newNode->next = tempNext;
	}
	T RemoveAt(int index) {
		if (index < 0 || index > count)
			return NULL;
		Node* newNode = nullptr;
		count--;
		if (index == 0)
		{
			newNode->first;
			first = first.next;
			delete newNode;
			return NULL;
		}
		Node* tempPrev = first;
		Node* tempNext = first->next;
		for (int i = 1; i < index; i++)
		{
			tempPrev = tempNext;
			tempNext = tempNext->next;
		}
		if (index == count)
		{
			last = tempPrev;
			tempPrev->next = nullptr;
		}
		else
			tempPrev->next = tempNext->next;
		T temp = tempNext->value;
		delete tempNext;
		return temp;
	}

};