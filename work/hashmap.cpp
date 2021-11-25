#include <iostream>
#include <unordered_map>
#include <string>

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


int main(){

	std::cout<<"Training with hashmaps..."<<std::endl;
	usageInbuiltHashMap();


	return 0;
}
