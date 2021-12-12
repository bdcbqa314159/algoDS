#include <iostream>
#include <vector>
#include <queue>

class PriorityQueue{
	// PriorityQueue
	// ~PriorityQueue
	// bool isEmpty
	// int getSize
	// int getMinimum
	// void insert
	// int removeMin

};

void inPlaceHeapSort(int* pq, int N){


}

void inBuiltMaxHeap(){

	std::cout<<"======Inbuilt Max Heap======"<<std::endl;
	std::priority_queue<int> pq;

	pq.push(16);
	pq.push(1);
	pq.push(7);
	pq.push(167);
	pq.push(72);
	pq.push(45);
	pq.push(32);

	std::cout<<"Size: "<<pq.size()<<std::endl;
	std::cout<<"Biggest element: "<<pq.top()<<std::endl;

	while (!pq.empty()){
		std::cout<<pq.top()<<std::endl;
		pq.pop();
	}

	std::cout<<"Size: "<<pq.size()<<std::endl;

}

void kSortedArray(int* input, int n, int k){



}

void kSmallest(int* a, int n, int k){


}

void testingPriorityQueues(){
	std::cout<<"======Training with priority queues======"<<std::endl;
	PriorityQueue p;

	p.insert(100);
	p.insert(10);
	p.insert(15);
	p.insert(4);
	p.insert(17);
	p.insert(21);
	p.insert(67);

	std::cout<<"Size : "<<p.getSize()<<std::endl;
	std::cout<<"Minimum : "<<p.getMinimum()<<std::endl;

	while (!p.isEmpty()){
		std::cout<<p.removeMin()<<std::endl;

	}
}

void testingInPlaceMinHeapsort(){
	std::cout<<"======Inplace Min Heap Sort======"<<std::endl;
	int test[] = {1,5,0,8,2};
	inPlaceHeapSort(test,5);

	for (int i = 0; i<5; i++){
		std::cout<<test[i]<<" ";
	}

	std::cout<<std::endl;
}

void inBuiltMinHeap(){

	std::cout<<"======Inbuilt Min Heap======"<<std::endl;
	std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
	pq.push(16);
	pq.push(1);
	pq.push(7);
	pq.push(167);
	pq.push(71);
	pq.push(45);
	pq.push(32);

	std::cout<<"Size: "<<pq.size()<<std::endl;
	std::cout<<"Smallest element: "<<pq.top()<<std::endl;

	while (!pq.empty()){
		std::cout<<pq.top()<<std::endl;
		pq.pop();
	}

	std::cout<<"Size: "<<pq.size()<<std::endl;

}

void testingKSortedArray(){

	std::cout<<"======K sorted array algorithm======"<<std::endl;

	int test[] = {10,12,6,7,9};
	kSortedArray(test, 5, 3);

	for (int i = 0; i<5; i++){
		std::cout<<test[i]<<" ";
	}

	std::cout<<std::endl;

}

void testingKSmallestAlgorithm(){

	std::cout<<"======K smallest elements in an array======"<<std::endl;
	int test[] = {10,12,6,7,9,56,0,34,1,2};
	kSmallest(test, 10, 3);

}

int main(){

	std::cout<<"======Working with priority queues======"<<std::endl;
	testingPriorityQueues();
	testingInPlaceMinHeapsort();
	inBuiltMaxHeap();
	testingKSortedArray();
	inBuiltMinHeap();

	return 0;
}
