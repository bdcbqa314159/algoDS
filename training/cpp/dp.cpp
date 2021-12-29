#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int fibonacci1(int n){

	if (n==0||n==1){
		return n;
	}

	return fibonacci1(n-1)+fibonacci1(n-2);
}

int fibonacci2(int n, int* arr){

	if (n==0||n==1){
		return n;
	}

	if (arr[n] != 0){
		return arr[n];
	}

	int ans = fibonacci2(n-1, arr) + fibonacci2(n-2, arr);
	arr[n] = ans;

	return ans;
}

int fibonacci3(int n){

	if (n == 0 || n == 1){
		return n;
	}

	int* dp = new int(n+1);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i<=n; i++)
		dp[i] = dp[i-1]+dp[i-2];

	int answer = dp[n];
	delete dp;

	return answer;
}

int fibonacci4(int n){

	if (n == 0 || n == 1)
		return	n;

	int x = 0;
	int y = 1;

	int z = 0;

	for (int i = 2; i<=n; i++){
		z = x+y;
		x = y;
		y = z;
	}

	return z;

}

//Problem: what is the minimal cost to reach 1 with -1, /2 & /3 operations?
int minSteps1(int n){

	if (n<=1)
		return 0;

	int x = minSteps1(n-1);

	int y,z;
	y = z = INT_MAX;

	if( n % 2 ==0)
		y = minSteps1(n/2);

	if ( n % 3==0)
		z = minSteps1(n/3);

	return std::min(x, std::min(y,z))+1;

}

int helper1(int n, int* ans){

	if (n<=1)
		return 0;

	if (ans[n] != -1)
		return ans[n];

	int x = helper1(n-1, ans);

	int y,z;
	y = z = INT_MAX;

	if ( n%2 == 0)
		y = helper1(n/2, ans);

	if ( n%3 == 0)
		z = helper1(n/3, ans);

	int output = std::min(x,std::min(y,z))+1;
	ans[n] = output;

	return output;
}

int minSteps2(int n){

	int* ans = new int(n+1);

	for (int i = 0; i<=n ; i++)
		ans[i] = -1;

	return helper1(n, ans);

}

int minSteps3(int n){

	if (n <= 1) return 0;

	int* dp = new int(n+1);

	dp[0] = 0;
	dp[1] = 0;

	for (int i = 2; i<=n; i++){
		int x = dp[i-1];
		int y = INT_MAX;
		int z = INT_MAX;

		if (i%2 == 0) y = dp[i/2];
		if (i%3 == 0) z = dp[i/3];

		dp[i] = std::min(x, std::min(y,z))+1;
	}

	int out = dp[n];

	delete dp;
	return out;

}

int minSteps4(int n){

	if (n<=1) return 0;

	int* dp = new int(n+1);

	dp[0] = 0;
	dp[1] = 0;

	for (int i = 2; i<=n; i++){
		dp[i] = dp[i-1]+1;

		if ( i%2 == 0) dp[i] = std::min(dp[i], dp[i/2]+1);
		if ( i%3 == 0) dp[i] = std::min(dp[i], dp[i/3]+1);

	}

	int out = dp[n];
	delete dp;

	return out;



}

//Number of ways to reach the top with at most a k size jump
int climbingStairsGeneralized(int n, int k){

	int* dp = new int(n+1);

	dp[0] = 1;

	for (int i = 1; i<=n; i++){
		int ans = 0;

		for (int j = 1; j<=k; j++){
			if (i-j>=0){
				ans += dp[i-j];
			}
		}

		dp[i] = ans;
	}

	int result = dp[n];
	delete dp;
	return result;
}

int climbingStairs2(int n){

	if (n==0 || n==1) return 1;

	int* dp = new int(n+1);

	dp[0] = dp[1] = 1;

	for (int i = 2; i<=n; i++){
		dp[i] = dp[i-1]+dp[i-2];
	}


	int result = dp[n];
	delete dp;

	return result;
}

int climbingStairs1(int n){

	if (n==0 || n==1) return 1;

	return climbingStairs1(n-1)+climbingStairs1(n-2);
}


//Part2
int helper2(std::string text1, int i, std::string text2, int j){

	if (text1.size() == i || text2.size() == j){
		return 0;
	}

	if (text1[i] == text2[j]){
		return 1+helper2(text1, i+1, text2, j+1);
	}

	else{
		return std::max(helper2(text1, i+1, text2, j), helper2(text1, i, text2, j+1));
	}

}


int longestCommonSubsequence1(std::string text1, std::string text2){

	return helper2(text1, 0, text2, 0);

}

int longestCommonSubsequence2(std::string text1, std::string text2){

	int m = text1.size();
	int n = text1.size();

	int dp[m+1][n+1];

	for (int i = 0; i<=m; i++){
		for (int j = 0; j<=n; j++){

			if (i == 0|| j==0){
				dp[i][j] = 0;
			}

			else if (text1[i] == text2[j]){
				dp[i][j] = 1+dp[i-1][j-1];
			}

			else{
				dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[m][n];

}

int mD1(std::string s1, int m, std::string s2, int n){

	if ( m == 0 ) return n;

	if ( n == 0 ) return m;

	if (s1[m-1] == s2[n-1])
		return mD1(s1, m-1, s2, n-1);

	int insertion = mD1(s1, m, s2, n-1);
	int deletion = mD1(s1, m-1, s2, n);
	int replacement = mD1(s1, m-1, s2, n-1);

	return 1+ std::min(insertion, std::min(deletion, replacement));

}

int editDistance1(std::string s1, std::string s2){

	return mD1(s1, s1.size(), s2, s2.size());

}

int editDistance2(std::string s1, std::string s2){

	int m = s1.size();
	int n = s2.size();

	int dp[m+1][n+1];

	for (int i = 0; i<=m; i++){
		for (int j = 0; j<=n; j++){
			if (i == 0) dp[i][j] = j;

			else if (j == 0) dp[i][j] = i;

			else if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];

			else{
				int insertion = dp[i][j-1];
				int deletion = dp[j-1][i];
				int replacement = dp[i-1][j-1];
				dp[i][j] = std::min(insertion, std::min(deletion, replacement))+1;
			}
		}
	}

	return dp[m][n];


}


int knapsack1(int n, int W, std::vector<int> &prices, std::vector<int>& weights){

	if (n == 0 || W == 0) return 0;

	if (weights[n-1]>W) return knapsack1(n-1, W, prices, weights);

	else{
		int include = knapsack1(n-1, W-weights[n-1], prices, weights)+prices[n-1];
		int exclude = knapsack1(n-1, W, prices, weights);

		return std::max(include, exclude);
	}
}

int knapsackSolution1(std::vector<int> &prices, std::vector<int> &weights, int W){

	return knapsack1(prices.size(), W, prices, weights);

}

int knapsackSolution2(std::vector<int> &prices, std::vector<int> &weights, int W){

	int n = prices.size();

	int dp[n+1][W];

	for (int i = 0; i<=n; i++){
		for (int j = 0; j<=W; j++){
			if (i ==0 || j == 0){
				dp[i][j] = 0;
			}

			else if(weights[i-1]>j){
				dp[i][j] = dp[i-1][j];
			}

			else{
				int include = prices[i-1]+dp[i-1][j-weights[i-1]];
				int exclude = dp[i-1][j];

				dp[i][j] = std::max(include , exclude);
			}
		}
	}

	return dp[n][W];

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
	std::cout<<"For "<<n<<" fibonacci4("<<n<<")="<<fibonacci4(n)<<std::endl;
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

void testingClimbingStairs(){
	std::cout<<"===Climbing Stairs==="<<std::endl;
	int n;
	std::cin>>n;


	std::cout<<"n = "<<n<<" --> "<<climbingStairsGeneralized(n, 2)<<std::endl;
	std::cout<<"n = "<<n<<" --> "<<climbingStairs2(n)<<std::endl;
	std::cout<<"n = "<<n<<" --> "<<climbingStairs1(n)<<std::endl;
}

void testingLongestCommonSubsequence(){

	std::string st1 = "apple";
	std::string st2 = "ample";
	int ans1 = longestCommonSubsequence1(st1, st2);
	int ans2 = longestCommonSubsequence2(st1, st2);

	std::cout<<"For "<<st1<<" and "<<st2<<" we have a length of "<<ans1<<std::endl;
	std::cout<<" for the smallest common subsequence."<<std::endl;
	std::cout<<"With dp, for "<<st1<<" and "<<st2<<" we have a length of "<<ans2<<std::endl;
	std::cout<<" for the smallest common subsequence."<<std::endl;
}

void testingSmallestCommonSequence(){
	std::string st1 = "horse";
	std::string st2 = "ros";
	int ans1 = editDistance1(st1, st2);
	int ans2 = editDistance2(st1, st2);

	std::cout<<"For "<<st1<<" and "<<st2<<" we have a length of "<<ans1<<std::endl;
	std::cout<<" for edit distance"<<std::endl;
	std::cout<<"With dp, for "<<st1<<" and "<<st2<<" we have a length of "<<ans2<<std::endl;
	std::cout<<" for the smallest common subsequence."<<std::endl;
}

void testingKnapsack01(){

	std::vector<int> prices;
	prices.push_back(60);
	prices.push_back(100);
	prices.push_back(120);

	std::vector<int> weights;
	weights.push_back(10);
	weights.push_back(20);
	weights.push_back(30);

	int W = 50;

	std::cout<<"Knapsack: "<< knapsackSolution1(prices, weights, W)<<std::endl;
	std::cout<<"Knapsack dp : "<< knapsackSolution2(prices, weights, W)<<std::endl;


}

int main(){
	std::cout<<"Working with dp :)"<<std::endl;

	// testingFibonacci();
	// testingMinimumStepsToOne();
	// testingClimbingStairs();
 	// testingLongestCommonSubsequence();
 	testingSmallestCommonSequence();
	testingKnapsack01();

	return 0;
}
