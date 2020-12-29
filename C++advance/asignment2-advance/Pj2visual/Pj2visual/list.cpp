#include "list.h"
#include "employee.h"

template <class T>
List<T>::List() {
}

template <typename T>
List<T>::~List() {

}

template<class T>
void List<T>::add(T const& item) {
	// TODO: Bạn phải code xử lý thêm một item vào đây
	return item;
}

template<class T>
T List<T>::get(int pos) {
	// TODO: Bạn code xử lý nếu pos < 0 thì ném out_of_range exception
	// TODO: Bạn code xử lý nếu pos >= size của elements
	// TODO: thì ném out_of_range exception
	// TODO: Nếu pos < size thì trả về theo vị trí pos
	if (pos < 0||pos>=sizeof(elements_))
	{
		throw "Invalid index";
	}
	return pos;
}

template<class T>
int List<T>::size() {
	// TODO: Bạn code xử lý nếu elements là empty thì trả về 0
	// TODO: ngược lại trả về số lượng các phần tử
	if (elements_ == 0)
	{
		return 0;
	}
	else
		return index;
}
