#include <iostream>

template <class T>
class BTNode{

public:
	T data;
	BTNode<T>* left;
	BTNode<T>* right;

BTNode(T data):data(data), left(NULL), right(NULL){

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

	BTNode<int>* insertData(BTNode<int>* root, int data){

		if (!root){
			BTNode<int>* node = new BTNode<int>(data);
			return node;
		}

		if (root->data < data){
			root->right = insertData(root->right, data);
		}

		else if (root->data > data){
			root->left = insertData(root->left, data);
		}

		return root;

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

		print(root->left);
		print(root->right);
	}

	bool hasData(BTNode<int>* root, int data){
		if (!root) return false;

		if (root->data > data){
			return hasData(root->left, data);
		}

		else if (root->data < data){
			return hasData(root->right, data);
		}

		return true;
	}

	int minV(BTNode<int>* root){

		if (!root){
			std::cout<<"No Tree so no min!"<<std::endl;
			return -1;
		}

		while(root->left){
			root = root->left;
		}

		return root->data;

	}

	int maxV(BTNode<int>* root){

		if (!root){
			std::cout<<"No Tree so no min!"<<std::endl;
			return -1;
		}

		while(root->right){
			root = root->right;
		}

		return root->data;

	}

	BTNode<int>* deleteData(BTNode<int>* root, int data){

		if (!root) return NULL;

		if (root->data < data){
			root->right = deleteData(root->right, data);
		}

		else if (root->data > data){
			root->left = deleteData(root->left, data);
		}

		else{
			if (root->left == NULL && root->right == NULL){
				delete root;
				return NULL;
			}

			else if (root->left == NULL && root->right != NULL){
				BTNode<int>* temp = root->right;
				root->right = NULL;
				delete root;
				return temp;
			}

			else if (root->left != NULL && root->right == NULL){
				BTNode<int>* temp = root->left;
				root->left = NULL;
				delete root;
				return temp;
			}

			else{
				BTNode<int>* minNode = root->right;
				while(minNode->left){
					minNode = minNode->left;
				}

				int minData = minNode->data;
				root->data = minData;
				root->right = deleteData(root->right, data);
			}

		}

		return root;
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

		if (root->left != NULL && root->right == NULL){
			Pair leftLL = convertToLL(root->left);
			leftLL.tail->right = root;

			Pair ans;
			ans.head = leftLL.head;
			ans.tail = root;

			return ans;
		}

		if (root->left == NULL && root->right != NULL){
			Pair rightLL = convertToLL(root->right);
			root->right = rightLL.head;

			Pair ans;
			ans.head = root;
			ans.tail = rightLL.tail;

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
		root = insertData(root, data);
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
		BTNode<int>* temp = p.head;

		while(temp){
			temp->left = NULL;
			temp = temp->right;
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

	std::cout<<"#############"<<std::endl;
	std::cout<<b.hasData(100)<<std::endl;
	std::cout<<b.hasData(15)<<std::endl;

	std::cout<<"#############"<<std::endl;
	std::cout<<b.minV()<<std::endl;
	std::cout<<b.maxV()<<std::endl;

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

	return 0;
}
