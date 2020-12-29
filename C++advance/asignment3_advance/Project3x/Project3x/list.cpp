#include "list.h"
#include "employee.h"

template <class T>
List<T>::List() {

}

template <typename T>
List<T>::~List() {

}

template<class T>
void List<T>::add(T const &item) {
	datastore.push_back(item);
}

template<class T>
T List<T>::get(int pos) {
	// TODO: Bạn code xử lý nếu pos < 0 thì ném out_of_range exception
	// TODO: Bạn code xử lý nếu pos >= size của elements
	// TODO: thì ném out_of_range exception
	// TODO: Nếu pos < size thì trả về theo vị trí pos
	if (pos< 0 || pos> datastore.size()) {
		throw "Out of exception";
	}
	return datastore[pos];
}

template<class T>
int List<T>::dolon() {
	// TODO: Bạn code xử lý nếu elements là empty thì trả về 0
	// TODO: ngược lại trả về số lượng các phần tử
	if (datastore.size() == NULL) {
		return 0;
	}
	return datastore.size();
}

