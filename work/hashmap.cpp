#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>

//Mini interface with inbuilt hashmaps

bool isPresent(std::unordered_map<std::string, int> u_map, std::string key){

	return u_map.count(key);
}

void isPresentInterface(std::unordered_map<std::string, int> u_map, std::string key){

	bool ans = isPresent(u_map, key);

	if (ans){
		std::cout<<key<<" is present."<<std::endl;
	}

	else{
		std::cout<<key<<" is not present."<<std::endl;
	}

}

void givingSize(std::unordered_map<std::string, int> u_map){
	std::cout<<"Size of the u_map : "<<u_map.size()<<std::endl;
}

void updatingHashMap(std::unordered_map<std::string, int> u_map, std::string key, int value){

	bool test = isPresent(u_map, key);

	isPresentInterface(u_map, key);

	if (!test){
		std::cout<<"The default value was "<<u_map[key]<<std::endl;
	}
	else{
		std::cout<<"old value : "<<u_map[key]<<std::endl;
	}

	u_map[key] = value;
	std::cout<<"new value for "<<key<<" : "<<u_map[key]<<std::endl;

}

void erasingValues(std::unordered_map<std::string, int> u_map, std::string key){

	bool test = isPresent(u_map, key);

	if (test){
		std::cout<<"The key "<<key<<" is present"<<std::endl;
		givingSize(u_map);
		u_map.erase(key);
		std::cout<<"... the key is gone now"<<std::endl;
		givingSize(u_map);
	}

	else{
		std::cout<<"The key "<<key<<" is not present"<<std::endl;
		std::cout<<"There is nothing to erase."<<std::endl;
		givingSize(u_map);
	}
}

void usageInbuiltHashMap(){

	std::cout<<"======= Inbuilt hashmaps : unordered_map ======"<<std::endl;

	std::unordered_map<std::string, int> myMap;
	std::string key = "abc";
	std::string key1 = "def";
	std::string key2 = "xyz";

	std::pair<std::string, int> p(key, 1);

	//insert needs pair data structure.
	myMap.insert(p);

	//we can use also [] as arrays & vectors
	myMap[key1] = 2;

	std::cout<<key<<" : "<<myMap[key]<<std::endl;
	std::cout<<key1<<" : "<<myMap.at(key1)<<std::endl;

	//xyz not present, if we ask with .at we will have an exception if we ask
	//with [] we will have 0 value and the key will be added.
	// std::cout<<key2<<" : "<<myMap.at(key2)<<std::endl;
	std::cout<<key2<<" : "<<myMap[key2]<<std::endl;

	givingSize(myMap);

	std::string key3 = "uvw";

	//checking if a key is present

	isPresentInterface(myMap, key3);
	isPresentInterface(myMap, key2);

	//updating values
	givingSize(myMap);

	updatingHashMap(myMap, key2, 20);
	updatingHashMap(myMap, "xcv", 20);

	myMap.erase(key2);
	givingSize(myMap);
	isPresentInterface(myMap, key2);

}

//Remove duplicates algorithm

std::vector<int> removeDuplicates(int* arr, int size){
	std::vector<int> ans;

	std::unordered_map<int, bool> myMap;

	for (int i=0; i<size; i++){
		if (myMap.count(arr[i]) == 0){
			ans.push_back(arr[i]);
			myMap[arr[i]] = true;
		}
	}

	return ans;

}

void removeDuplicates(){
	std::cout<<"====== Remove duplicates algorithm ======"<<std::endl;
	int a[] = {1, 2, 4, 5, 6, 1, 1, 2, 3, 3, 2, 5, 6, 6, 1};
	std::vector<int> ans = removeDuplicates(a, 15);
	for (int i = 0 ; i<ans.size(); i++){
		std::cout<<ans[i]<<" ";
	}
	std::cout<<std::endl;
}

//Iterators
void iteratorsUMap(){
	std::cout<<"====== Iterators with unordered_map ======"<<std::endl;
	std::unordered_map<std::string, int> myMap;
	myMap["abc"] = 1;
	myMap["abc1"] = -23;
	myMap["abc2"] = 190;
	myMap["abc3"] = 11;
	myMap["abc4"] = 5;

	std::unordered_map<std::string, int>::iterator it;

	for (it = myMap.begin(); it != myMap.end(); it++){
		std::cout<<it->first<< " : "<<it->second<<std::endl;
	}

	it = myMap.find("abc");
	isPresentInterface(myMap, "abc");
	myMap.erase(it);
	isPresentInterface(myMap, "abc");

	std::string key = "abc1";

	std::cout<<"Is present with iterators."<<std::endl;
	it = myMap.find(key);
	if (it == myMap.end()){
		std::cout<<key<<" not present."<<std::endl;
	}

	else{
		std::cout<<key<<" is present."<<std::endl;
		std::cout<<key<<" : "<<myMap[key]<<std::endl;
	}

	myMap.erase(myMap.begin(), myMap.end());

	for (it = myMap.begin(); it != myMap.end(); it++){
		std::cout<<it->first<< " : "<<it->second<<std::endl;
	}

	givingSize(myMap);
}

void iteratorsMap(){

	std::cout<<"====== Iterators with map ======"<<std::endl;
	std::map<std::string, int> myMap1;
	myMap1["abc"] = 1;
	myMap1["abc1"] = -23;
	myMap1["abc2"] = 190;
	myMap1["abc3"] = 11;
	myMap1["abc4"] = 5;

	std::map<std::string, int>::iterator it1;

	for (it1 = myMap1.begin(); it1 != myMap1.end(); it1++){
		std::cout<<it1->first<< " : "<<it1->second<<std::endl;
	}
}

void iteratorsVector(){

	std::cout<<"====== Iterators with vectors ======"<<std::endl;
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(34);
	vec.push_back(31);
	vec.push_back(90);
	vec.push_back(-109);

	std::vector<int>::iterator it2;

	for (it2 = vec.begin(); it2 != vec.end(); it2++){
		std::cout<<*it2<<std::endl;
	}
}

void iterators(){
	std::cout<<"====== Iterators with unordered_map / map / vectors ======"<<std::endl;

	iteratorsUMap();
	iteratorsMap();
	iteratorsVector();

}

void autoKeyWord(){

	//Auto key word:
	// auto iterator it1;
	// std::map<std::string, int>::iterator it1;
	// Good but need to be used with parcimony
	auto test = 12;
	std::cout<<test<<std::endl;

}

//Implementing our hashmap

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

template <class T>
class MyMap{

	MapNode<T>** buckets;
	int counter;
	int numBuckets;

	int getBucketIndex(std::string key){

		int hashCode = 0;

		int base = 1;
		int p = 37;

		for (int i = key.size()-1; i >= 0; i--){
			hashCode += key[i]*base;
			base *= p;

			hashCode %= numBuckets;
			base %= numBuckets;
		}

		return hashCode%numBuckets;
	}

	void rehash(){

		MapNode<T>** temp = buckets;

		buckets = new MapNode<T>*[2*numBuckets];

		for (int i = 0; i<numBuckets*2; i++){
			buckets[i] = NULL;
		}

		int oldBucketSize = numBuckets;
		numBuckets *= 2;
		counter = 0;

		for (int i = 0; i<oldBucketSize; i++){
			MapNode<T>* head = temp[i];

			while (head){
				std::string key = head->key;
				T value = head->value;
				insert(key, value);

				head = head->next;
			}
		}

		for (int i = 0; i<oldBucketSize; i++){

			delete temp[i];
		}

		delete []temp;

	}

public:
	MyMap(): counter(0), numBuckets(5){
		buckets = new MapNode<T>*[numBuckets];
		for (int i = 0; i < numBuckets; i++){
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

		std::cout<<"-- key absent -- ";
		return 0;
	}

	void insert(std::string key, T value){
		int bucketIndex = getBucketIndex(key);
		MapNode<T>* head = buckets[bucketIndex];

		while (head){

			if (head->key == key){
				head->value = value;
				return;
			}
		}

		MapNode<T>* node = new MapNode<T>(key, value);
		node->next = buckets[bucketIndex];
		buckets[bucketIndex] = node;
		counter ++;

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
				head = NULL;
				delete head;
				counter --;

				return value;
			}

			prev = head;
			head = head->next;

		}

		std::cout<<key<<" is not present -> 0 is returned"<<std::endl;
		return 0;

	}

	double getLoadFactor(){
		return (1.*counter)/numBuckets;
	}

};

void testingMyMapClass(){
	std::cout<<"====== MyMap class testing ======"<<std::endl;

	MyMap<int> ourMap;

	for (int i = 0; i<10; i++){
		char c = '0'+i;
		std::string key = "abc";
		key += c;
		int value = i+1;
		ourMap.insert(key, value);
		std::cout<<"current load factor: "<<ourMap.getLoadFactor()<<std::endl;
	}

	for (int i = 0; i<10; i++){
		char c = '0'+i;
		std::string key = "abc";
		key += c;

		std::cout<<key<<" : "<<ourMap.getValue(key)<<std::endl;
	}

	std::cout<<"Size : "<<ourMap.size()<<std::endl;
	std::cout<<"Removing abc1 & abc6"<<std::endl;
	ourMap.remove("abc1");
	ourMap.remove("abc6");

	for (int i = 0; i<10; i++){
		char c = '0'+i;
		std::string key = "abc";
		key += c;

		std::cout<<key<<" : "<<ourMap.getValue(key)<<std::endl;
	}

	std::cout<<"Size : "<<ourMap.size()<<std::endl;

}


int main(){

	std::cout<<"Training with hashmaps..."<<std::endl;
	usageInbuiltHashMap();
	removeDuplicates();
	iterators();
	autoKeyWord();
	testingMyMapClass();


	return 0;
}
