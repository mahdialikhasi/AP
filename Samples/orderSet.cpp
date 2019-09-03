#include <iostream>
#include <string.h>
using namespace std;
template <class T>
class orderSet
{
	T *order;
	int size;
	void sort(T *order, int size){
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size - 1; ++j)
			{
				if(order[j] > order[j+1]){
					T temp = order[j + 1];
					order[j + 1] = order[j];
					order[j] = temp;
				}
			}
		}
	}
	void show() const{
		for (int i = 0; i < size; ++i)
		{
			cout << order[i] << " " ;
		}
		cout << endl;
	}
public:
	int getSize(){
		return size;
	}
	orderSet(const orderSet<T> &a){
		size = a.size;
		order = NULL;
		order = new T[a.size];
		memcpy(order, a.order, a.size * sizeof(T));
	}

	orderSet(){
		size = 0;
		order = NULL;
	}
	~orderSet(){
		delete[] order;
	}
	void insert(T a){
		for (int i = 0; i < size ; ++i)
		{
			if(a == order[i]){
				return;
			}
		}
		T *newOrder = new T[size + 1];
		memcpy(newOrder, order, size * sizeof(T));
		size++;
		newOrder[size - 1] = a;
		if(order != NULL){
			delete[] order;
		}
		order = newOrder;
		sort(order, size);
		return;
	}
	T &operator[](int a){
		if(a < size){
			return order[a];	
		}else{
			return order[size - 1];
		}
		
	}
	const T operator[](int a) const{
		if(a < size){
			return order[a];	
		}else{
			return order[size - 1];
		}
		
	}
	/*orderSet<T> operator=(const orderSet<T> ord){
		if(order != NULL){
			delete[] order;
			order = NULL;
			size = 0; 
		}
		order = new T[ord.size];
		memcpy(order, ord.order, ord.size * sizeof(T));
		size = ord.size;

		return *this;

	}*/
	orderSet<T> &operator=(const orderSet<T> &ord){
		if(order != NULL){
			delete[] order;
			order = NULL;
			size = 0; 
		}
		order = new T[ord.size];
		memcpy(order, ord.order, ord.size * sizeof(T));
		size = ord.size;

		return *this;

	}
	orderSet<T> operator-(const orderSet<T> &x){
		orderSet<T> c;
		int status;
		for (int i = 0; i < size; ++i)
		{
			status = 0;
			for (int j = 0; j < x.size; ++j)
			{
				if((x.order)[j] == this->order[i]){
					status = 1;
					break;
				}
			}
			if(status == 0){
				c.insert(order[i]);
			}
		}
		
		return c;
	}
	orderSet<T> operator+(const orderSet<T> &ord){
		orderSet<T> a;
		
		for (int i = 0; i < size; ++i)
		{
			a.insert(this->order[i]);
		}
		for (int i = 0; i < ord.size; ++i)
		{
			a.insert(ord[i]);
		}
		
		return a;
	}
	orderSet<T> &operator++(){
		for (int i = 0; i < size; ++i)
		{
			order[i]++;
		}
		return *this;
	}
	orderSet<T> &operator++(int){
		orderSet<T> a = *this;
		for (int i = 0; i < size; ++i)
		{
			order[i]++;
		}
		return a;
	}
	orderSet<T> &operator--(){
		for (int i = 0; i < size; ++i)
		{
			order[i]--;
		}
		return *this;
	}
	orderSet<T> &operator--(int){
		orderSet<T> a = *this;
		for (int i = 0; i < size; ++i)
		{
			order[i]--;
		}
		return a;
	}
	/*template <class A >
	friend ostream &operator<<(ostream &out, orderSet<A> &data);*/		
	template <class A >
	friend ostream &operator<<(ostream &out, const orderSet<A> &data);
};
/*template <class T>
ostream &operator<<(ostream &out, orderSet<T> &data){
	for(int i = 0; i < data.size; i++){
		out << data[i] << endl;
	}
	return out;
}*/
template <class T>
ostream &operator<<(ostream &out, const orderSet<T> &data){
	for(int i = 0; i < data.size; i++){
		out << data[i] << endl;
	}
	return out;
}
int main(){
	orderSet<int> s;
	s.insert(2);
	s.insert(4);
	s.insert(5);
	
	orderSet<int> p;
	p.insert(9);
	p.insert(4);

	const orderSet<int> q = p + s;
	orderSet<int> z = p - s;
	cout << z;
	//orderSet<float> d = p + s; //error

	cout << q;
	//q++; //error
	orderSet<int> p2(++p);
	cout << q[2] << '\n' << p[4];
	return 0;
}