#include <iostream>
#include <vector>
#include <queue>

class PriorityQueue{

	std::vector<int> pq;

public:
	PriorityQueue(){

	}

	~PriorityQueue(){

	}


	bool isEmpty(){
		return (pq.size() == 0);
	}

	int getSize(){
		return pq.size();
	}

	int getMinimum(){

		if (isEmpty()){
			std::cout<<"--pq is empty--"<<std::endl;
			return INT_MAX;
		}

		return pq[0];
	}

	void insert(int element){

		pq.push_back(element);
		int cI = pq.size()-1;

		while (cI > 0){
			int pI = (cI-1)/2;
			if (pq[cI] < pq[pI]){
				std::swap(pq[cI], pq[pI]);
				cI = pI;
			}

			else{
				break;
			}
		}
	}

	int removeMin(){

		if (isEmpty()){
			std::cout<<"--pq is empty--"<<std::endl;
			return INT_MAX;
		}

		int ans = pq[0];
		std::swap(pq[0], pq[pq.size()-1]);
		pq.pop_back();

		int pi=0;

		while (true){

			int lci = 2*pi+1;
			int rci = 2*pi+2;
			int mini = pi;

			if (lci < pq.size() && pq[lci] < pq[mini]){
				mini = lci;
			}

			if (rci < pq.size() && pq[rci] < pq[mini]){
				mini = rci;
			}

			if (pq[mini] == pq[pi]){
				break;
			}
			std::swap(pq[pi], pq[mini]);
			pi = mini;
		}

		return ans;

	}

};

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

void inPlaceHeapSort(int* pq, int N){

	for (int i = 1; i<N; i++){

		int cI = i;
		while (cI > 0){
			int pI = (cI-1)/2;

			if (pq[cI] < pq[pI]){
				std::swap(pq[cI], pq[pI]);
				cI = pI;
			}

			else{
				break;
			}
		}
	}

	int temp_size = N;

	while (temp_size > 1){
		std::swap(pq[0], pq[temp_size-1]);
		temp_size--;

		int pi = 0;

		while (true){
			int lci = 2*pi+1;
			int rci = 2*pi+2;

			int mini = pi;

			if (lci < temp_size && pq[lci] < pq[mini]){
				mini = lci;
			}

			if (rci < temp_size && pq[rci] < pq[mini]){
				mini = rci;
			}

			if (pq[pi] == pq[mini]){
				break;
			}

			std::swap(pq[pi], pq[mini]);
			pi = mini;
		}
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

void kSortedArray(int* input, int n, int k){
	
}


int main(){

	std::cout<<"Hey priority queues!"<<std::endl;
	testingPriorityQueues();

	// std::cout<<"======K sorted array algorithm======"<<std::endl;
	//
	// int test[] = {10,12,6,7,9};
	// kSortedArray(test, 5);
	//
	// for (int i = 0; i<5; i++){
	// 	std::cout<<test[i]<<" ";
	// }
	//
	// std::cout<<std::endl;

	testingInPlaceMinHeapsort();


	return 0;
}
