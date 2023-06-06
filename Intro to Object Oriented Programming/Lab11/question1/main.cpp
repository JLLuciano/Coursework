#include <iostream>
#include <list> 
#include <string>

using namespace std;
//Using code from page 255-256, ch15: Multiple Inheritance from Volume 2 book
template<class T>
class SList {
	class SNode {//Using the same format as the one presented on the final exam for linked list
		T data; //creating a node
		SNode<T>* next;
		SNode() {
			this->next = nullptr;
		}
	};
	
public:
	// Declaration necessary so the following 
	// 'friend' statement sees this 'iterator' 
	// instead of std::iterator:
	T head;
	SList() {
		this->head = nullptr;
	}
	class iterator;
	friend class iterator;
	class iterator : public std::iterator<
		std::bidirectional_iterator_tag, T, ptrdiff_t> {
		SList<T>::iterator it;
		SList<T>* r;
	public:
		// "typename" necessary to resolve nesting: 
		iterator(SList<T>& lst,
			const typename SList<T>::iterator& i)
			: r(&lst), it(i) {}
		bool operator==(const iterator& x) const {
			return it == x.it;
		}
		bool operator!=(const iterator& x) const {
			return !(*this == x);
		}
		SList<T>::reference operator*() const {
			return *it;
		}
		iterator& operator++() {
			++it;
			if (it == r->end())
				it = r->begin();
			return *this;
		}
		iterator operator++(int) {
			iterator tmp = *this;
			++* this;
			return tmp;
		}
		iterator& operator--() {
			if (it == r->begin())
				it = r->end();
			--it;
			return *this;
		}
		iterator operator--(int) {
			iterator tmp = *this;
			--* this;
			return tmp;
		}
		iterator insert(const T& x) {
			return iterator(*r, r->insert(it, x));
		}
		iterator erase() {
			return iterator(*r, r->erase(it));
		}
	};
	void push_back(const T& x) {
		lst.push_back(x);
	}
	iterator begin() {
		return iterator(lst, lst.begin());
	}
	int size() { return lst.size(); }
};
int main() {
	SList<string> rs;
	rs.push_back("one");
	rs.push_back("two");
	rs.push_back("three");
	rs.push_back("four");
	rs.push_back("five");
	SList<string>::iterator it = rs.begin();
	it++; it++;
	it.insert("six");
	it = rs.begin();
	// Twice around the ring: 
	for (int i = 0; i < rs.size() * 2; i++)
		cout << *it++ << endl;
} ///:~