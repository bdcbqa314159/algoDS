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

		while (cI>0){
			int pI = (cI-1)/2;
			if (pq[cI] <pq[pI]){
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

		int pi = 0;

		while (true){
			int lci = 2*pi+1;
			int rci = 2*pi+2;
			int mini = pi;

			if (lci<pq.size()&&pq[lci]<pq[mini]){
				mini = lci;
			}

			if (rci<pq.size()&&pq[rci]<pq[mini]){
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

void inPlaceHeapSort(int* pq, int N){

	for (int i =1; i<N; i++){
		int cI = i;

		while(cI>0){
			int pI = (cI-1)/2;

			if (pq[cI]<pq[pI]){
				std::swap(pq[cI], pq[pI]);
				cI = pI;
			}

			else{
				break;
			}
		}
	}

	int temp_size = N;

	while (temp_size>1){
		std::swap(pq[0], pq[temp_size-1]);
		temp_size--;

		int pi = 0;

		while (true){
			int lci = 2*pi+1;
			int rci = 2*pi+2;

			int mini = pi;

			if (lci<temp_size && pq[lci]<pq[mini]){
				mini = lci;
			}

			if (rci<temp_size&& pq[rci]<pq[mini]){
				mini = rci;
			}
			if(pq[pi] == pq[mini]){
				break;
			}

			std::swap(pq[pi], pq[mini]);
			pi = mini;
		}
	}
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

	std::priority_queue<int> pq;

	for (int i = 0; i<k; i++){
		pq.push(input[i]);
	}

	int s = 0;

	for (int i = k; i<n; i++){
		input[s] = pq.top();
		pq.pop();
		s++;
		pq.push(input[i]);
	}

	while (!pq.empty()){
		input[s] = pq.top();
		pq.pop();
		s++;
	}
}

void kSmallest(int* a, int n, int k){

	std::priority_queue<int> pq;

	for(int i = 0; i<k; i++){
		pq.push(a[i]);
	}

	for (int i = k; i<n; i++){
		if (a[i]<pq.top()){
			pq.pop();
			pq.push(a[i]);
		}
	}

	while(!pq.empty()){
		std::cout<<pq.top()<<std::endl;
		pq.pop();
	}

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
