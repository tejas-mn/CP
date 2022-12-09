#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(int data){
		val = data;
		left = NULL;
		right = NULL;
	}
};

class BST{
	private :
		TreeNode* root=NULL;
	public:
		void insertIter(int val){
			TreeNode* node = new TreeNode(val);
			if(root==NULL){
				root = node;
				return;
			}
			
			TreeNode* prev = NULL;
			TreeNode* cur  = root;
			
			while(cur){
				if(val > cur->val){
					prev = cur;
					cur = cur->right;
				}else if(val < cur->val){
					prev = cur;
					cur = cur->left;
				}
			}
			
			if(val < prev->val){
				prev->left = node;
			}else{
				prev->right = node;
			}
		}
		
		TreeNode* insertRecHelper(TreeNode* rt, TreeNode* node){
			if(rt==NULL){
				rt = node;
				return rt;
			}
			
			if(node->val < rt->val){
				rt->left = insertRecHelper(rt->left,node);
			}else if(node->val > rt->val){
				rt->right = insertRecHelper(rt->right,node);
			}
			
			return rt;
		}
		
		void insert(int val){
			TreeNode* node = new TreeNode(val);
			root = insertRecHelper(root, node);
		}
		
		void display(){
			queue<pair<TreeNode*,int>> qp;
			
			qp.push({root,0});
			
			while(!qp.empty()){
				auto front = qp.front();
				qp.pop();
				
				cout<<"Level :"<<front.second<<" "<<front.first->val<<endl;
				
				if(front.first->left!=NULL){
					qp.push({front.first->left, front.second+1});
				}
				
				if(front.first->right!=NULL){
					qp.push({front.first->right, front.second+1});
				}
			}
		}	
};

int main() {
	// Your code goes here;
	
	BST t;
	
	t.insert(10);
	t.insert(20);
	t.insert(30);
	
	t.display();
	
	return 0;
}
