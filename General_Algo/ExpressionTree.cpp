#include <bits/stdc++.h>

using namespace std;

class ExprTree
{
private:
	struct Node
	{
		char data;
		Node *left,*right;
	}*root;
	queue<char> que;
	stack<Node*> stk;

public:
	ExprTree()
	{
		initialize();
	}	

	void initialize()
	{
		root = NULL;
	}

	Node* getRoot()
	{
		return root;
	}

	void getData()
	{
		cout<<"Enter the postfix expression string(enter # at the end): ";		
		char expr;
		while(true)
		{
			cin>>expr;
			if(expr == '#')
				return;
			que.push(expr);
		}
	}

	void display()
	{
		while(que.front())
		{
			cout<<que.front()<<" ";
			que.pop();
		}
	}

	void createTree()
	{
		if(que.empty())
		{	
			stk.pop();
			return;
		}
		Node *temp = new Node;
		temp->data = que.front();
		temp->left = temp->right = NULL;
		switch(que.front())
		{
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				temp->right = stk.top();
				stk.pop();
				temp->left = stk.top();
				stk.pop();
				root = temp;
				stk.push(temp);
				break;

			default:
				stk.push(temp);	
		}
		que.pop();
		createTree();
	}

	void preorder(Node *root)
	{
		if(root == NULL)
			return;
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}

	void inorder(Node *root)
	{
		if(root == NULL)
			return;
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}

	void postorder(Node *root)
	{
		if(root == NULL)
			return;
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}

	void print(int i)
	{
		if(i == 1)
		{
			cout<<"Preorder traversal: ";
			preorder(root);
		}
		else if(i == 2)
		{
			cout<<"Inorder traversal: ";
			inorder(root);
		}
		else
		{
			cout<<"Postorder traversal: ";
			postorder(root);
		}
		cout<<endl<<endl;
	}
};

int main()
{
	ExprTree obj;
	obj.getData();
	obj.createTree();
	obj.print(1);
	obj.print(2);
	return 0;
}

