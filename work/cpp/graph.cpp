#include <iostream>
#include <vector>
#include <queue>

void printDFS(std::vector<std::vector<int> > &v, int sv, std::vector<bool> &visited){
	std::cout<<sv<<std::endl;

	visited[sv] = true;
	int n = v.size();

	for (int i = 0; i<n; i++){
		if(v[sv][i] == 1 && visited[i] == false){

			printDFS(v,i, visited);
		}
	}


}

void DFS(std::vector<std::vector<int> > &v){

	int n = v.size();
	std::vector<bool> visited(n,false);
	int count = 0;
	for (int i = 0; i<n; i++){
		if (visited[i] == false){
			printDFS(v,i,visited);
			count++;
		}
	}

	std::cout<<"No of connect components: "<<count<<std::endl;
}


void printBFS(std::vector<std::vector<int> > &v, int sv, std::vector<bool> &visited){

	std::queue<int> q;
	int n = v.size();

	visited[sv] = true;
	q.push(sv);

	while(!q.empty()){
		int cv = q.front();
		q.pop();
		std::cout<<cv<<std::endl;

		for (int i = 0; i<n; i++){
			if(v[cv][i] == 1 && visited[i] == false){
				q.push(i);
				visited[i] = true;
			}
		}
	}

}

void BFS(std::vector<std::vector<int> > &v){

	int n = v.size();
	std::vector<bool> visited(n,false);
	int count = 0;
	for (int i = 0; i<n; i++){
		if (visited[i] == false){
			printBFS(v,i,visited);
			count++;
		}
	}
	std::cout<<"No of connect components: "<<count<<std::endl;
}


int main(){

	std::cout<<"Working with graphs :)."<<std::endl;

	std::cout<<"=== Dealing with inputs ==="<<std::endl;

	int n,e;

	std::cin>>n>>e;
	std::vector<std::vector<int> > matrix(n, std::vector<int>(n,0));

	for (int i = 1; i<=e; i++){
		int fv,sv;
		std::cin>>fv>>sv;
		matrix[fv][sv] = 1;
		matrix[sv][fv] = 1;

	}


	std::cout<<"DFS"<<std::endl;
	DFS(matrix);
	std::cout<<"BFS"<<std::endl;
	BFS(matrix);


	return 0;
}
