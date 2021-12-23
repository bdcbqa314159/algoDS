#include <iostream>
#include <algorithm>

int fibonacci1(int n){
	if (n == 0 || n == 1){
		return n;
	}

	return fibonacci1(n-1) + fibonacci1(n-2);
}

int fibonacci2(int n, int* arr){
	if (n==0 || n==1){
		return n;
	}

	if (arr[n] != 0){
		return arr[n];
	}

	int output = fibonacci2(n-1, arr)+fibonacci2(n-2, arr);
	arr[n] = output;

	return output;
}

int fibonacci3(int n){
	int *arr = new int(n+1);

	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i<=n; i++){
		arr[i] = arr[i-1]+arr[i-2];
	}
	int ans = arr[n];
	delete arr;

	return ans;
}

int minSteps1(int n){

	if (n<=1){
		return 0;
	}

	int y(INT_MAX), z(INT_MAX);

	int x = minSteps1(n-1);

	if (n%2 == 0){
		y = minSteps1(n/2);
	}

	if (n%3 == 0){
		z = minSteps1(n/3);
	}

	return std::min(x, std::min(y,z))+1;

}

int helper(int n, int* ans){
	if (n<=1){
		return 0;
	}

	if (ans[n] != -1){
		return ans[n];
	}

	int y(INT_MAX), z(INT_MAX);

	int x = helper(n-1, ans);

	if (n%2 == 0){
		y = helper(n/2, ans);
	}

	if (n%3 == 0){
		z = helper(n/3,ans);
	}
	int output = std::min(x, std::min(y,z))+1;
	ans[n] = output;
	return output;
}

int minSteps2(int n){

	int *ans = new int(n+1);
	for (int i =0; i<n+1; i++){
		ans[i] = -1;
	}

	return helper(n, ans);

}

int minSteps3(int n){

	int *dp = new int(n+1);
	dp[0] = 0;
	dp[1] = 0;

	for (int i = 2; i<n+1; i++){

		int x = dp[i-1];
		int y(INT_MAX), z(INT_MAX);

		if (i%2 == 0){
			y = dp[i/2];
		}

		if (i%3 == 0){
			z = dp[i/3];
		}

		dp[i] = std::min(x, std::min(y,z))+1;

	}
	int ans = dp[n];
	delete dp;
	return ans;
}

int minSteps4(int n){

	int *dp = new int(n+1);
	dp[0] = 0;
	dp[1] = 0;

	for (int i = 2; i<n+1; i++){

		dp[i] = dp[i-1]+1;

		if (i%2 == 0){
			dp[i] = std::min(dp[i], dp[i/2]+1);
		}

		if (i%3 == 0){
			dp[i] = std::min(dp[i], dp[i/3]+1);
		}

	}
	int ans = dp[n];
	delete dp;
	return ans;
}


int climbingStairsGeneralized(int n, int k){

	int *dp = new int(n+1);
	dp[0] = 1;

	for (int i = 1; i<n+1; i++){
		int ans = 0;
		for (int j = 1; j<=k; j++){
			if (i-j>=0){
				ans += dp[i-j];
			}
		}

		dp[i]=ans;
 	}

	int result = dp[n];
	delete dp;
	return result;

}


int climbingStairs2(int n){

	int *dp = new int(n+1);
	dp[0] = dp[1] = 1;

	for (int i = 2; i<n+1; i++){
		dp[i] = dp[i-1]+dp[i-2];
	}

	int result = dp[n];
	delete dp;
	return result;

}



int climbingStairs1(int n){
	if (n == 0 || n==1){
		return 1;
	}

	return climbingStairs1(n-1)+climbingStairs1(n-2);
}



void testingFibonacci(){

	std::cout<<"===Recursive Fibonacci==="<<std::endl;
	int n(0);
	std::cin>>n;

	int *arr = new int(n+1);
	for (int i = 0; i<=n; i++){
		arr[i] = 0;
	}

	std::cout<<"For "<<n<<" fibonacci2("<<n<<")="<<fibonacci2(n,arr)<<std::endl;
	std::cout<<"For "<<n<<" fibonacci3("<<n<<")="<<fibonacci3(n)<<std::endl;
	std::cout<<"For "<<n<<" fibonacci1("<<n<<")="<<fibonacci1(n)<<std::endl;

	delete arr;

}

void testingMinimumStepsToOne(){

	std::cout<<"===Minimum steps to 1==="<<std::endl;
	int n;
	std::cin>>n;
	std::cout<<"n = "<<n<<" --> "<<minSteps4(n)<<std::endl;
	std::cout<<"n = "<<n<<" --> "<<minSteps3(n)<<std::endl;
	std::cout<<"n = "<<n<<" --> "<<minSteps2(n)<<std::endl;
	std::cout<<"n = "<<n<<" --> "<<minSteps1(n)<<std::endl;

}

int main(){
	std::cout<<"Working with dp :)"<<std::endl;


	std::cout<<"===Climbing Stairs==="<<std::endl;
	int n;
	std::cin>>n;


	std::cout<<"n = "<<n<<" --> "<<climbingStairsGeneralized(n, 2)<<std::endl;
	std::cout<<"n = "<<n<<" --> "<<climbingStairs2(n)<<std::endl;
	std::cout<<"n = "<<n<<" --> "<<climbingStairs1(n)<<std::endl;


	return 0;
}
