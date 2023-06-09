#pragma once
#include <iostream>


template<class T> class HashSet;

template<class T> class HashSet {
	struct Node {
		T data;
		Node* next;
		
		Node(const T& value): data(value), next(nullptr) {}
	};

	Node** hashTable;
	int capacity;
	int count;

public:
	HashSet(int capacity1 = 10);
	~HashSet();
	void add(const T& element);
	bool contains(const T& element) const;
	void clear();
	void printSet();

	int hash(const T& element) const{
		return element.hash();
	}

	int getElementIndex(int hash) const{
		return hash % capacity;
	}
	
	int getCapacity() {
		return capacity;
	}

	Node** getHashTable() {
		return hashTable;
	}

	int size() {
		return count;
	}

	bool isEmpty() {
		return count == 0;
	}

	HashSet<T> operator- (const HashSet<T>& other);
	HashSet<T>& operator=(const HashSet<T>& other);


	class Iterator {
		Node** hashTable;
		int capacity;
		int currentIndex;
		Node* currentNode;

	public:
		Iterator(HashSet<T>& object, int index) {
			hashTable = object.getHashTable();
			capacity = object.getCapacity();
			currentIndex = index;
			currentNode = object.hashTable[index];
		}

		T getCurrentItem() const {
			if (currentNode != nullptr) {
				return currentNode->data;
			}
		}

		bool isEnd() {
			for (int i = currentIndex; i < capacity; i++) {
				if (hashTable[i] != nullptr) {
					return false;
				}
			}
			return true;
		}

	  	Iterator& operator++(int) {
			if (currentNode != nullptr) {
				if (currentNode->next != nullptr) {
					currentNode = currentNode->next;
				}
				else {
					currentIndex++;
					while (currentIndex < capacity && hashTable[currentIndex] == nullptr) {
						currentIndex++;
					}

					if (currentIndex >= capacity) {
						currentNode = nullptr;
					}
					else {
						currentNode = hashTable[currentIndex];
					}

				}
				return *this;
			}
		}
	};

	Iterator begin() {
		int currentIndex = 0;
		while (currentIndex < capacity && hashTable[currentIndex] == nullptr) {
			currentIndex++;
		}

		if (currentIndex < capacity) {
			return Iterator(*this, currentIndex);
		}
		else {
			return end();
		}
	}

	Iterator end() {
		return Iterator(*this, capacity);
	}

	
};

// <------------------------------------ HashSet mathods ------------------------------------>
template<class T>
HashSet<T>::HashSet(int capacity1) : capacity(capacity1), count(0) {
	hashTable = new Node*[capacity]();
}

template<class T>
HashSet<T>::~HashSet() {
	clear();
	delete[] hashTable;
}

template<> int HashSet<int>::hash(const int& element) const {
	return element;
}

template<> int HashSet<char>::hash(const char& element) const {
	return (int)element;
}

template<> int HashSet<bool>::hash(const bool& element) const {
	return element;
}

template<> int HashSet<float>::hash(const float& element) const {
	return (int)element;
}

template<> int HashSet<double>::hash(const double& element) const {
	return (int)element;
}

template<> int HashSet<std::string>::hash(const std::string& element) const {
	int sum = 0;
	for (int i = 0; i < element.length(); i++) {
		sum += (int)element[i];
	}
	return sum;
}

template<class T>
bool HashSet<T>::contains(const T& element) const {
	int hash = this->hash(element);
	int index = getElementIndex(hash);
	Node* current = hashTable[index];

	while (current != nullptr) {
		if (current->data == element) {
			return true;
		}
		current = current->next;
	}
	return false;
}

template<class T>
void HashSet<T>::add(const T& element) {
	if (contains(element)) {
		return;
	}
	int hash = this->hash(element);
	int index = getElementIndex(hash);
	Node* newNode = new Node(element);
	if (hashTable[index] == nullptr) {
		hashTable[index] = newNode;
	}
	else {
		Node* p0;
		p0 = hashTable[index];
		hashTable[index] = newNode;
		newNode->next = p0;
	}
	count++;
}

template <typename T>
void HashSet<T>::clear() {
	for (int i = 0; i < capacity; i++) {
		Node* current = hashTable[i];
		while (current != nullptr) {
			Node* next = current->next;
			delete current;
			current = next;
		}
		hashTable[i] = nullptr;
	}
	count = 0;
}


template<class T>
HashSet<T>& HashSet<T>::operator=(const HashSet<T>& other) {
	if (this == &other) {
		return *this; 
	}
	clear();
	for (int i = 0; i < other.capacity; i++) {
		Node* current = other.hashTable[i];
		while (current != nullptr) {
			add(current->data);
			current = current->next;
		}
	}

	return *this;
}

template<class T>
HashSet<T> HashSet<T>::operator- (const HashSet<T>&other) {
	HashSet<T> result(this->capacity);

	for (int i = 0; i < this->capacity; i++) {
		Node* current = this->hashTable[i];
		while (current != nullptr) {
			if (!other.contains(current->data)) {
				result.add(current->data);
			}
			current = current->next;
		}
	}
	return result;
}

template<class T>
void HashSet<T>::printSet() {
	HashSet<T>::Iterator it(*this, 0);
	for (Iterator it = begin(); !it.isEnd(); it++) {
		std::cout << it.getCurrentItem() << " ";
	}
	std::cout << std::endl;
}









































/*void remove(const T& element) {
	int index = hash(element);

	Node* current = hashTable[index];
	Node* prev = nullptr;

	while (current != nullptr) {
		if (current->data == element) {
			if (prev == nullptr) {
				hashTable[index] = current->next;
			}
			else {
				prev->next = current->next;
			}

			delete current;
			count--;
			return;
		}

		prev = current;
		current = current->next;
	}
}*/