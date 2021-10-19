// Heaps Follows following 3 properties :-
// * Binary Tree
// * Complete Binary Tree
// * Heap Order Property

#include<iostream>
#include<vector>
using namespace std;

class Heap{
	vector<int> v;
	bool minHeap;

	bool compare(int curr, int parent){
		if(minHeap){
			return curr < parent; 
		}
		else{
			return parent < curr;
		}
	}

	void heapify(int idx){
		int left = idx * 2;
		int right = left + 1;

		int min_idx = idx;
		int last = v.size() - 1;

		if(left <= last && compare(v[left], v[idx])){
			min_idx = left;
		}
		if(right <= last && compare(v[right], v[min_idx])){
			min_idx = right;
		}

		if(min_idx != idx){
			swap(v[min_idx], v[idx]);
			heapify(min_idx);
		}
	}

public:
	Heap(int size = 10, bool type = true){
		v.reserve(size);
		v.push_back(-1);
		minHeap = type;
	}

	void push(int val){
		v.push_back(val);
		int idx = v.size() - 1;
		int parent = idx / 2;

		while(idx > 1 && compare(v[idx], v[parent])){
			swap(v[idx], v[parent]);
			idx = parent;
			parent = idx / 2;
		}
	}

	void pop(){
		int last = v.size() - 1;
		swap(v[1], v[last]);
		v.pop_back();
		heapify(1);
	}

	int top(){
		return v[1];
	}

	bool empty(){
		return v.size() == 1;
	}
};

int main(){
	Heap h;

	for(int i = 0; i < 5; i++){
		int num;
		cin >> num;
		h.push(num);
	}

	while(!h.empty()){
		cout << h.top() << " ";
		h.pop();
	}
}