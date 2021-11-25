#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>

std::vector<int> removeDuplicates(int* arr, int size){

	std::vector<int> output;
	std::unordered_map<int, bool> myMap;

	for (int i=0; i<size; i++){
		if (myMap.count(arr[i]) == 0){
			output.push_back(arr[i]);
			myMap[arr[i]] = true;
		}
	}

	return output;
}

template <class T>
class MapNode{

public:
	std::string key;
	T value;
	MapNode<T>* next;

	MapNode(std::string key, T value): key(key), value(value){

	}

	~MapNode(){
		delete next;
	}

};

class MyMap{

	MapNode<T>** buckets;
	int counter;
	int numBuckets;

	int getBucketIndex(std::string key){
		int hashCode = 0;

		int base = 1;
		int p = 37;

		for (int i = key.size()-1 ; i>=0 ; i--){
			hashCode += key[i]*base;
			base *= p;

			hashCode = hashCode%numBuckets;
			base = base%numBuckets;
		}

		return hashCode%numBuckets;
	}

	void rehash(){

		MapNode<T>** temp = buckets;
		buckets = new MapNode<T>*[2*numBuckets];

		for (int i = 0; i<numBuckets*2 ; i++){
			buckets[i] = NULL;
		}

		int oldBucketSize = numBuckets;
		numBuckets *= 2;
		counter = 0;

		for (int i = 0; i<oldBucketSize; i++){
			MapNode<T>* head = temp[i];

			while(head){

				std::string key = head->key;
				T value = head->value;
				insert(key, value);

				head = head->next;
			}
		}

		for (int i = 0; i < oldBucketSize; i++){
			delete temp[i];
		}

		delete []temp;

	}

public:
	MyMap(): counter(0), numBuckets(5){
		buckets = new MapNode<T>*[numBuckets];

		for (int i = 0; i<numBuckets; i++){
			buckets[i] = NULL;
		}
	}

	~MyMap(){
		for (int i = 0; i<numBuckets; i++){
			delete buckets[i];
		}

		delete []buckets;
	}

	int size(){
		return counter;
	}

	T getValue(std::string key){
		int bucketIndex = getBucketIndex(key);
		MapNode<T>* head = buckets[bucketIndex];


		while (head){

			if (head->key == key){
				return head->value;
			}

			head = head->next;
		}

		return 0;
	}

	void insert(std::string key, T value){
		int bucketIndex = getBucketIndex(key);
		MapNode<T>* head = buckets[bucketIndex];

		while (head){

			if(head->key == key){
				head->value = value;
				return;
			}

			head = head->next;
		}

		MapNode<T>* node = new MapNode<T>(key, value);
		node->next = buckets[bucketIndex];
		buckets[bucketIndex] = node;
		counter++;

		double loadFactor = (1.*counter)/numBuckets;

		if (loadFactor > 0.7){
			rehash();
		}

		return;
	}

	T remove(std::string key){
		int bucketIndex = getBucketIndex(key);
		MapNode<T>* head = buckets[bucketIndex];
		MapNode<T>* prev = NULL;

		while (head){
			if (head->key == key){
				if (prev == NULL){
					buckets[bucketIndex] = head->next;
				}
				else{
					prev->next = head->next;
				}

				T value = head->value;
				head->next = NULL;
				delete head;
				counter --;

				return value;
			}
			prev = head;
			head = head->next;
		}

		return 0;

	}

	double getLoadFactor(){
		return (1.*counter)/numBuckets;
	}
};

int main(){
	std::cout<<"Usage of map and unordered map."<<std::endl;

	std::unordered_map<std::string, int> myMap;
	std::pair<std::string, int> p("abc", 1);

	myMap.insert(p);
	myMap["def"] = 2;

	std::cout<<myMap["abc"]<<std::endl;
	std::cout<<myMap.at("def")<<std::endl;
	// std::cout<<myMap.at("xyz")<<std::endl; //throw exception
	std::cout<<myMap["xyz"]<<std::endl; //if not present, create the key and put zero

	std::cout<<"Size :"<<myMap.size()<<std::endl;
	std::cout<<myMap["fgh"]<<std::endl;

	//Checking if the key is present.
	if (myMap.count("fgh") > 0){
		std::cout<<"fgh is present"<<std::endl;
	}
	else{
		std::cout<<"fgh is not present"<<std::endl;
	}

	std::cout<<"Size :"<<myMap.size()<<std::endl;
	//update
	std::cout<<"at fgh : "<<myMap["fgh"]<<std::endl;
	myMap["fgh"] = 20;
	std::cout<<"at fgh : "<<myMap["fgh"]<<std::endl;
	//erase
	myMap.erase("fgh");
	std::cout<<"erasing..."<<std::endl;
	std::cout<<"Size :"<<myMap.size()<<std::endl;

	std::cout<<"========= Remove Duplicates =========="<<std::endl;

	int a[] = {1,2,3,4,5,6,1,2,2,3,6,7,1,9,10};
	std::vector<int> ans = removeDuplicates(a, 15);

	for (int i = 0; i<ans.size(); i++){
		std::cout<<ans.at(i)<<std::endl;
	}

	std::cout<<"========= Iterators with unordered map =========="<<std::endl;

	std::unordered_map<std::string, int> myMap1;
	myMap1["abc"] = 1;
	myMap1["abc1"] = 2;
	myMap1["abc2"] = 3;
	myMap1["abc3"] = 4;
	myMap1["abc4"] = 5;
	myMap1["abc5"] = 6;

	std::unordered_map<std::string, int>::iterator it;

	for (it = myMap1.begin(); it != myMap1.end(); it++){
		std::cout<<it->first<<" : "<<it->second<<std::endl;
	}

	std::cout<<"========= Iterators with map =========="<<std::endl;

	std::map<std::string, int> myMap2;
	myMap2["abc"] = 1;
	myMap2["abc1"] = 2000;
	myMap2["abc2"] = 3;
	myMap2["abc3"] = 40;
	myMap2["abc4"] = 5;
	myMap2["abc5"] = -90;

	std::map<std::string, int>::iterator it1;

	for (it1 = myMap2.begin(); it1 != myMap2.end(); it1++){
		std::cout<<it1->first<<" : "<<it1->second<<std::endl;
	}

	std::cout<<"========= Iterators with vectors =========="<<std::endl;

	std::vector<int> v;
	v.push_back(12);
	v.push_back(2);
	v.push_back(3);
	v.push_back(9);
	v.push_back(-1);
	v.push_back(4);


	std::vector<int>::iterator it2;

	for (it2 = v.begin(); it2 != v.end(); it2++){
		std::cout<<*it2<<" "<<std::endl;
	}

	//find

	//erase
	// std::unordered_map<std::string, int>::iterator it_find = myMap1.find("abc");
	// myMap1.erase(it_find);
	myMap1.erase(myMap1.begin(), myMap1.end());

	if (myMap1.find("abc") == myMap1.end()){
		std::cout<<"Not present"<<std::endl;
	}
	else{
		std::cout<<"present"<<std::endl;
	}

	for (it = myMap1.begin(); it != myMap1.end(); it++){
		std::cout<<it->first<<" : "<<it->second<<std::endl;
	}
	std::cout<<"Size: "<<myMap1.size()<<std::endl;

	//Auto key word:
	// auto iterator it1;
	// std::map<std::string, int>::iterator it1;
	// Good but need to be used with parcimony
	auto test = 12;
	std::cout<<test<<std::endl;

	std::cout<<"========= myMap testing =========="<<std::endl;

	MyMap<int> ourMap;

	for (int i = 0; i<10; i++){
		char c = '0'+i;
		std::string key = "abc";
		key += c;
		int value = 1+i;
		ourMap.insert(key,value);
		std::cout<<ourMap.getLoadFactor()<<std::endl;
	}

	std::cout<<ourMap.size()<<std::endl;

	ourMap.remove("abc1");
	ourMap.remove("abc6");
	for (int i = 0; i<10; i++){
		char c = '0'+i;
		std::string key = "abc";
		key += c;
		std::cout<<key<<": "<<ourMap.getValue(key)<<std::endl;
	}

	std::cout<<ourMap.size()<<std::endl;

	return 0;
}
