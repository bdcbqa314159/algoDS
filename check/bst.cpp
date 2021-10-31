#include <iostream>

template<class T>
class BTNode{

public:
	T data;
	BTNode<int>* left;
	BTNode<int>* right;

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

		if (node->data>data){
			node->left = insertData(node->left,data);
		}

		else{
			node->right = insertData(node->right, data);
		}

		return node;
	}

	void print(BTNode<int>* root){
		if (!root) return;

		std::cout<<root->data<<std::endl;
		if (root->left){
			std::cout<<"L: "<<root->left->data<<std::endl;
		}

		if (root->right){
			std::cout<<"R: "<<root->right->data<<std::endl;
		}

		std::cout<<std::endl;

		print(root->left);
		print(root->right);
	}

	bool hasData(BTNode<int>* node, int data){

		if (!node) return false;

		if (node->data > data){
			return hasData(node->left,data);
		}

		else if (node->data < data){
			return hasData(node->right,data);
		}

		else return true;

	}

	int minV(BTNode<int>* node){
		if (!node) return -1;

		while (node->left){
			node = node->left;
		}

		return node->data;
	}

	int maxV(BTNode<int>* node){

		if (!node) return -1;

		while (node->right){
			node = node->right;
		}

		return node->data;
	}

	BTNode<int>* deleteData(BTNode<int>* node, int data){
		if (!node) return NULL;

		if (node->data > data){
			node->left = deleteData(node->left,data);
		}

		else if (node->data < data){
			node->right = deleteData(node->right,data);
		}

		else{

			if (node->right == NULL && node->left == NULL){
				delete node;
				return NULL;
			}

			else if(node->right == NULL){
				BTNode<int>* tmp = node->left;
				node->left = NULL;
				delete node;
				return tmp;
			}

			else if(node->left == NULL){
				BTNode<int>* tmp = node->right;
				node->right = NULL;
				delete node;
				return tmp;
			}

			else{
				BTNode<int>* minNode = node->right;

				while(minNode->left){
					minNode = minNode->left;
				}

				int minData = minNode->data;
				node->data = minData;
				node->right = deleteData(node->right, data);
			}
		}
		return node;
	}

	Pair convertToLL(BTNode<int>* root){
		if (!root){
			Pair ans;
			ans.head = NULL;
			ans.tail = NULL;
			return ans;
		}

		if (root->left == NULL && root->right == NULL){
			Pair ans;
			ans.head = root;
			ans.tail = root;
			return ans;
		}

		else if (root->left != NULL && root->right == NULL){
			Pair rightLL = convertToLL(root->right);
			root->right = rightLL.head;

			Pair ans;
			ans.head = root;
			ans.tail = rightLL.tail;

			return ans;
		}

		else if (root->right != NULL && root->left == NULL){
			Pair leftLL = convertToLL(root->left);
			leftLL.tail->right = root;

			Pair ans;
			ans.head = leftLL.head;
			ans.tail = root;

			return ans;
		}

		else{
			Pair leftLL = convertToLL(root->left);
			Pair rightLL = convertToLL(root->right);

			leftLL.tail->right = root;
			root->right = rightLL.head;

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
		root = insertData(root,data);
	}

	void print(){
		print(root);
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

	std::cout<<"Checking bst"<<std::endl;

	BST b;

	b.insertData(10);
	b.insertData(5);
	b.insertData(20);
	b.insertData(7);
	b.insertData(3);
	b.insertData(15);

	b.print();

	// std::cout<<b.hasData(100)<<std::endl;
	// std::cout<<b.hasData(15)<<std::endl;
	//
	// std::cout<<b.minV()<<std::endl;
	// std::cout<<b.maxV()<<std::endl;
	//
	// b.deleteData(20);
	//
	// b.print();

	BTNode<int>* head = b.convertToLL();
	BTNode<int>* tmp = head;

	while(tmp){
		std::cout<<tmp->data<<"-> ";
		tmp = tmp->right;
	}

	std::cout<<"END"<<std::endl;

	return 0;
}
