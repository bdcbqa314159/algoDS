#include <iostream>
#include <vector>

int main(){

	std::cout<<"Working with graphs :)."<<std::endl;

	std::cout<<"=== Dealing with inputs ==="<<std::endl;

	int n{},e{};

	std::vector<std::vector<int>> matrix(n, std::vector<int>(n,0));

	for (int i = 1; i<=e; i++){
		int fv{},sv{};
		std::cin>>fv,sv;
		matrix[fv][sv] = 1;
		matrix[sv][fv] = 1;

	}

	return 0;
}
