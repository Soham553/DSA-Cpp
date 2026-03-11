#include <iostream>
using namespace std;


class stack{
	public:
		int *arr;
		int size;
		int top;

		stack(int size){
			this -> size = size;
			arr = new int[size];
			top = -1;
		}

		void push(int element){
			if(size - top > 1){
				top++;
				arr[top] = element;
			}else{
				cout<<"Stack overflow"<<endl;				}

		}

		void pop(){
			if(top >= 0){
				top--;
				cout<<arr[top]<<"   is removed"<<endl;
			}else{
				cout<<"stack overflow"<<endl;
			}
		}

};

int main(){
   	stack s(5);
	s.push(4);
	s.push(4);
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(9);
	s.pop();
}
