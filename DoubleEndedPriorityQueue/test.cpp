#include "MinMaxHeap.h"
#include <set>
#include <iostream>
#include <ctime>

using namespace std;

void PushAndDeleteTest(){
	int N = 1000;
	MinMaxHeap<int> h;
	multiset<int> s;
	cout << "push and delete test start." << endl;
	for (int i = 0; i < N; i++){
		int v = rand();
		h.push(v);

		s.insert(v);
		if (h.getMin() != *s.begin())cerr << "expected: " << (*s.begin()) << ", actual: " << h.getMin() << endl;
		if (h.getMax() != *std::prev(s.end(), 1))cerr << "expected: " << *std::prev(s.end(), 1) << ", actual: " << h.getMax() << endl;
	}
	cout << "push test finished!" << endl;
	for (int i = 0; i < N - 1; i++){
		if (i & 1){
			h.deleteMax();
			s.erase(std::prev(s.end(), 1));
		}
		else{
			h.deleteMin();
			s.erase(s.begin());
		}
		if (h.getMin() != *s.begin())cerr << "expected: " << (*s.begin()) << ", actual: " << h.getMin() << endl;
		if (h.getMax() != *std::prev(s.end(), 1))cerr << "expected: " << *std::prev(s.end(), 1) << ", actual: " << h.getMax() << endl;
	}
	cout << "delete test finished!" << endl;
}

void EmptyAndSizeTest(){
    int N = 100;
    MinMaxHeap<int> h;
    cout << "empty test start." << endl;
    for(int i=0 ; i < N ; i++){
        int v = rand();
        h.push(v);
    }
    for(int i=0 ; i < 2*N ; i++){
        if(!h.isEmpty()){
            if(h.getSize()==0)cerr << "expected: positive number, actual: 0" << endl;
            h.deleteMax();
        }else{
            if(h.getSize()!=0)cerr << "expected: 0, actual: " << h.getSize() << endl;
        }
    }
    cout << "empty test finished!" << endl;
}

double GetTime(){
	return (double)clock() / CLOCKS_PER_SEC;
}

void PerformanceTest(){
	int N = 1000000;
	MinMaxHeap<int> h;
	multiset<int> s;
	vector<int> values;

	cout << "performance test start." << endl;
	for (int i = 0; i < N; i++){
		values.push_back(rand());
	}

	double heapInsertTime = GetTime();
	for (int i = 0; i < N; i++){
		h.push(values[i]);
	}
	heapInsertTime = GetTime() - heapInsertTime;

	double setInsertTime = GetTime();
	for (int i = 0; i < N; i++){
		s.insert(values[i]);
	}
	setInsertTime = GetTime() - setInsertTime;
	cout << "push test finished!" << endl;
	cout << "heap time: " << heapInsertTime << endl;
	cout << "set time: " << setInsertTime << endl;


	double heapDeleteTime = GetTime();
	for (int i = 0; i < N - 1; i++){
		if (i & 1){
			h.deleteMax();
		}
		else{
			h.deleteMin();
		}
	}
	heapDeleteTime = GetTime() - heapDeleteTime;


	double setDeleteTime = 0;
	for (int i = 0; i < N - 1; i++){
		if (i & 1){
			s.erase(std::prev(s.end(), 1));
		}
		else{
			s.erase(s.begin());
		}
	}
	setDeleteTime = GetTime() - setDeleteTime;
	cout << "delete test finished!" << endl;
	cout << "heap time: " << heapDeleteTime << endl;
	cout << "set time: " << setDeleteTime << endl;
}


int main(){
	PushAndDeleteTest();
    EmptyAndSizeTest();
	PerformanceTest();
	return 0;
}
