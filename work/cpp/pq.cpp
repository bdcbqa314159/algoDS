#include <iostream>
#include <vector>

class PrioirityQueue{
	std::vector<int> pq;

public:
	PrioirityQueue(){

	}

	bool isEmpty(){
		return pq.size() == 0;
	}

	int getSize(){
		return pq.size();
	}

	int getMinimum(){

		if (isEmpty()){
			std::cout<<"--pq empty--"<<std::endl;
			return INT_MAX;
		}

		return pq[0];

	}

	void insert(int element){

		pq.push_back(element);
		int cI = pq.size()-1;

		while (cI > 0 ){
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
			std::cout<<"--pq empty--"<<std::endl;
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

			if (lci < pq.size() && pq[lci] < pq[mini]){
				mini = lci;
			}

			if (rci < pq.size() && pq[rci] < pq[mini]){
				mini = rci;
			}

			if (pq[pi] == pq[mini]){
				break;
			}
			std::swap(pq[pi], pq[mini]);
			pi = mini;
		}

		return ans;

	}


};


int main(){

	std::cout<<"Training with priority queues."<<std::endl;

	PrioirityQueue p;

	p.insert(100);
	p.insert(10);
	p.insert(15);
	p.insert(4);
	p.insert(17);
	p.insert(21);
	p.insert(67);

	std::cout<<p.getSize()<<std::endl;
	std::cout<<p.getMinimum()<<std::endl;

	while (!p.isEmpty()){
		std::cout<<p.removeMin()<<" ";
	}

	std::cout<<std::endl;


	return 0;
}