#include<iostream>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

struct node* getNode(int data)
{
	node* newNode=new node();
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

void inorder(struct node* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
int maxDepth(struct node* node)
{
   if (node==NULL)
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);

       /* use the larger one */
       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
   }
}
void preorder(struct node* root)
{
	if (root != NULL)
	{   cout<<"\n";
	    for(int i=0;i<2*(maxDepth(root));i++)
            cout<<"-";
	    cout<<root->data<<" ";
		preorder(root->left);

		preorder(root->right);
	}
}

struct node* Insert(struct node* root, int data)
{
	if (root == NULL)
		return getNode(data);

	if (data < root->data)
		root->left  = Insert(root->left, data);
	else if (data > root->data)
		root->right = Insert(root->right, data);

	return root;
}

int FindHeight(node* root)
{
	if(root==NULL)
		return 0;

	else
	{
		int lb=FindHeight(root->left);
		int rb=FindHeight(root->right);
		return max(lb,rb)+1;
	}
}

int main()
{
	node* root=NULL;
	root=Insert(root,7);
	Insert(root,9);
	Insert(root,4);
	Insert(root,1);
	Insert(root,5);

	cout<<"Inorder: ";
	inorder(root);
	cout<<"Preorder: ";
	preorder(root);

	cout<<endl;

	cout<<"Height of the tree is "<<FindHeight(root)<<endl;
	cout<<"Max. Depth of the tree is "<<FindHeight(root)-1;

	return 0;
}
