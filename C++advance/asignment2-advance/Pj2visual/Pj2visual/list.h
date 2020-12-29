#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

template<class T>
class List {
private:
	// Mảng elements_ khai báo với giả thiết 1000 phần tử
	T elements_[1000];
	// Chỉ số hiện tại khi thao tác trên mảng
	unsigned int index = 0;
public:
	List();
	virtual ~List();
	void add(T const&);
	T get(int pos);
	int size();
};

#endif /* LIST_H_ */
