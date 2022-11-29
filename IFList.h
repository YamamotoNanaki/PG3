#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

namespace IF
{
	template <typename T>
	struct Node
	{
		T value;
		Node* prev;
		Node* next;
		Node()
		{
			prev = this;
			next = this;
		}
		Node(T value, Node* prev, Node* next)
		{
			this->value = value;
			this->prev = prev;
			this->next = next;
		}
	};
	template <typename T>
	class List
	{
	private:
		Node<T>* dummy;
		size_t size_;
	public:
		List()
		{
			dummy = new Node<T>();
			size_ = 0;
		}
		~List()
		{
			Clear();
		}

		void Add(T v, Node<T>* node)
		{
			// insert a new node between the current node and the next of current node
			Node<T>* newNode = new Node<T>(v, node, node->next);
			node->next->prev = newNode;
			node->next = newNode;
			// update the current node
			node = newNode;
			size_++;
		}
		void PushFront(T value)
		{
			Node<T>* cur = dummy;
			Add(value, cur);
		}
		void PushBack(T value)
		{
			Node<T>* cur = dummy->prev;
			Add(value, cur);
		}
		void Insert(T value, size_t insertNumber)
		{
			if (insertNumber >= size_) { throw std::out_of_range("配列の範囲外を参照しています"); }
			int i = 0;
			Node<T>* ptr = dummy->next;
			while (ptr != dummy)
			{
				if (i == insertNumber)break;
				i++;
				ptr = ptr->next;
			}
			Add(value, ptr);
		}
		bool Empty()
		{
			return dummy->next == dummy;
		}

		T Remove(Node<T>* node)
		{
			if (Empty())
			{
				throw std::logic_error("配列の要素はありません");
			}
			T ret = node->value;
			node->prev->next = node->next;
			node->next->prev = node->prev;
			delete node;
			size_--;
			return ret;
		}
		T PopFront()
		{
			Node<T>* cur = dummy->next;
			return Remove(cur);
		}

		T PopBack()
		{
			Node<T>* cur = dummy->prev;
			return Remove(cur);
		}

		T Erase(size_t eraseNumber)
		{
			if (eraseNumber >= size_) { throw std::out_of_range("配列の範囲外を参照しています"); }
			int i = 0;
			Node<T>* ptr = dummy->next;
			while (ptr != dummy)
			{
				if (i == eraseNumber)break;
				i++;
				ptr = ptr->next;
			}
			return Remove(ptr);
		}
		void Print()
		{
			Node<T>* ptr = dummy->next;
			while (ptr != dummy)
			{
				std::cout << ptr->value << ' ';
				ptr = ptr->next;
			}
			std::cout << std::endl;
		}

		void Clear()
		{
			while (!Empty())
			{
				PopFront();
			}
		}

		size_t Size()
		{
			return size_;
		}

		T& operator[](size_t num)
		{
			if (num >= size_) { throw std::out_of_range("配列の範囲外を参照しています"); }
			Node<T>* ptr = dummy->next;
			size_t i = 0;
			while (ptr != dummy)
			{
				if (i == num)return ptr->value;
				i++;
				ptr = ptr->next;
			}
			throw std::out_of_range("配列の範囲外を参照しています");
		}
	};
}