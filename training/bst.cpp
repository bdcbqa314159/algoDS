#include <iostream>

template<class T>
class BTNode{

public:
	T data;
	BTNode<T>* left;
	BTNode<T>* right;

	BTNode(T data): data(data), left(NULL), right(NULL){

	}

	~BTNode(){
		delete left;
		delete right;
	}
};

class Pair{

public:
	BTNode<int>* head;
	BTNode<int>* tail;
};

class BST{

BTNode<int>* root;

BTNode<int>* insertData(BTNode<int>* node, int data){
	if (!node){
		BTNode<int>* root = new BTNode<int>(data);
		return root;
	}

	if (node->data < data){
		node->right = insertData(node->right, data);

	}

	else if (node->data > data){
		node->left = insertData(node->left, data);
	}

	return node;
}

void print(BTNode<int>* node){
	if (!node){
		return;
	}

	std::cout<<node->data<<std::endl;
	if (node->left){
		std::cout<<"L: "<<node->left->data<<std::endl;
	}

	if (node->right){
		std::cout<<"R: "<<node->right->data<<std::endl;
	}

	print(node->left);
	print(node->right);
}

bool hasData(BTNode<int>* node, int data){
	if (!node){
		return false;
	}

	if (node->data > data){
		return hasData(node->left, data);
	}

	else if (node->data < data){
		return hasData(node->right, data);
	}

	else{
		return true;
	}
}

int minV(BTNode<int>* node){
	if (!node){
		std::cout<<"ERROR - tree is empty."<<std::endl;
		return INT_MAX;
	}

	while (node->left){
		node = node->left;
	}

	return node->data;
}

int maxV(BTNode<int>* node){
	if (!node){
		std::cout<<"ERROR - tree is empty."<<std::endl;
	}

	while (node->right){
		node = node->right;
	}

	return node->data;
}

BTNode<int>* deleteData(BTNode<int>* node, int data){

	if (!node){
		return NULL;
	}

	if (node->data < data){
		node->right = deleteData(node->right, data);
	}

	else if (node->data > data){
		node->left = deleteData(node->left, data);
	}

	else{
		if (node->left == NULL && node->right == NULL){
			node = NULL;
			delete node;
			return NULL;
		}

		else if (node->left != NULL && node->right == NULL){
			BTNode<int>* temp = node->left;
			node = NULL;
			delete node;
			return temp;
		}

		else if (node->right != NULL && node->left == NULL){
			BTNode<int>* temp = node->right;
			node = NULL;
			delete node;
			return temp;
		}

		else{
			BTNode<int>* minNode = node->right;
			int minData = 0;
			while (node->left){
				node = node->left;
			}

			minData = node->data;
			node->right = deleteData(node->right, minData);
		}
	}
	return node;
}

Pair convertToLL(BTNode<int>* node){

	if (!node){
		Pair ans;
		ans.head = NULL;
		ans.tail = NULL;

		return ans;
	}

	if (node->left == NULL && node->right == NULL){
		Pair ans;
		ans.head = node;
		ans.tail = node;
		return ans;
	}

	if (node->left != NULL && node->right == NULL){
		Pair leftLL = convertToLL(node->left);
		leftLL.tail->right = node;

		Pair ans;
		ans.head = leftLL.head;
		ans.tail = node;
		return ans;
	}

	else if (node->right != NULL && node->left == NULL){
		Pair rightLL = convertToLL(node->right);
		node->right = rightLL.head;

		Pair ans;
		ans.head = node;
		ans.tail = rightLL.tail;
		return ans;
	}

	else{
		Pair leftLL = convertToLL(node->left);
		Pair rightLL = convertToLL(node->right);

		leftLL.tail->right = node;
		node->right = rightLL.head;

		Pair ans;

		ans.head = leftLL.head;
		ans.tail = rightLL.tail;
		return ans;
	}


}

public:
	BST(): root(NULL){

	}

	void insertData(int data){
		root = insertData(root, data);
	}

	void print(){
		return print(root);
	}

	bool hasData(int data){
		return hasData(root, data);
	}

	int minV(){
		return minV(root);
	}

	int maxV(){
		return maxV(root);
	}

	void deleteData(int data){
		root = deleteData(root, data);
	}

	BTNode<int>* convertToLL(){
		Pair p = convertToLL(root);
		BTNode<int>* tmp = p.head;

		while(tmp){
			tmp->left = NULL;
			tmp = tmp->right;
		}

		return p.head;
	}

	~BST(){
		delete root;
	}

};

int main(){

	std::cout<<"Checking bst :)"<<std::endl;

	BST b;

	b.insertData(10);
	b.insertData(5);
	b.insertData(20);
	b.insertData(7);
	b.insertData(3);
	b.insertData(15);
	b.insertData(100);
	b.insertData(150);

	b.print();

	std::cout<<"#############"<<std::endl;
	std::cout<<b.hasData(100)<<std::endl;
	std::cout<<b.hasData(15)<<std::endl;

	std::cout<<"#############"<<std::endl;
	std::cout<<b.minV()<<std::endl;
	std::cout<<b.maxV()<<std::endl;
	//
	b.deleteData(20);
	std::cout<<"#############"<<std::endl;
	b.print();

	BTNode<int>* head = b.convertToLL();
	BTNode<int>* tmp = head;

	while(tmp){
		std::cout<<tmp->data<<"-> ";
		tmp = tmp->right;
	}

	std::cout<<"END"<<std::endl;

	BST d;

	d.insertData(10);
	d.insertData(15);
	d.insertData(11);

	d.print();

	head = d.convertToLL();
	tmp = head;

	while(tmp){
		std::cout<<tmp->data<<"-> ";
		tmp = tmp->right;
	}

	std::cout<<"END"<<std::endl;

	return 0;
}
