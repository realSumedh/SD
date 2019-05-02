#include<iostream>

using namespace std;

class ThreadTree	
{
private:
	int data;
	int lth,rth;
	ThreadTree *lptr,*rptr;
public:
	void Create();
	void Insert(ThreadTree*, ThreadTree*);
	void DisplayInorder(ThreadTree*);
	void DisplayPost(ThreadTree*);
}*root,*temp;



void ThreadTree::Create()	
{
	ThreadTree *nth;
	nth=new ThreadTree;
	nth->lptr=nth->rptr=NULL;
	nth->lth=nth->rth=0;
	cout<<"\nEnter Data: ";
	cin>>nth->data;

	if(root==NULL)	
	{
		root=nth;
		temp =new ThreadTree;
		temp->data=-999;
		temp->lptr=root;
		temp->rptr=temp;
		temp->lth=temp->rth=0;
		root->lptr=root->rptr=temp;
	}

	else
		Insert(root,nth);
}

void ThreadTree::Insert(ThreadTree *temp, ThreadTree *nth)
{
	if(nth->data>temp->data)	
	{
		if(!temp->lth)	
		{
			nth->lptr=temp->lptr;
			temp->lptr=nth;
			nth->rptr=temp;
			temp->lth=1;
		}
		else Insert(temp->lptr,nth);
	}
	else if(nth->data<temp->data)
	{
		if(!temp->rth)
		{
			nth->rptr=temp->rptr;
			temp->rptr=nth;
			nth->lptr=temp;
			temp->rth=1;
		}
		else Insert(temp->rptr,nth);
	}
	else 
	{
		cout<<"\nDuplicate Data Entered";
		return;
	}
}



void ThreadTree::DisplayInorder(ThreadTree *root)
{
	while(root!=temp)
	{
		while(root->lth==1)
		{
			root=root->lptr;
		}
			cout<<root->data<<"\t";
			while(root->rth==0)	
		{
			root=root->rptr;
			if(root==temp)
			return;
			cout<<root->data<<"\t";
		}
		root=root->rptr;


	}
}



int main()
{
	ThreadTree T;
	int choice;
	while(1)	
	{
		cout<<"\n\nThreaded Binary Search Tree"
		"\n1. Insertion"
		"\n2. Display Inorder"
		"\n3. Exit"
		"\nEnter your choice: ";
		cin>>choice;

		switch(choice)	{
		case 1: T.Create();
                break;
		case 2: T.DisplayInorder(root);
                break;
		case 3: return 0;
		break;
		default: cout<<"\nWrong Choice Entered";
	}
	}
	return 0;
}
