#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
using namespace std;
template<class T>
class List {
private:
	
	vector<T>datastore;//khai bao vector datasore;
	// chi so hien tai khi khai bao tren mang
	unsigned int index = 0;

public:
	List();
	virtual ~List();
	//Ham them 1 doi tuong
	void add(T const&);
	//Ham tra gia tri tai vi tri pos
	T get(int pos);
	//Ham tinh so luong cac phan tu
	int dolon();
};
#endif /* LIST_H_ */
