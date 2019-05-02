#include<iostream>
#include<string>
using namespace std;

class node
{
	private:
		node* lchild;
		node* rchild;
		node* mchild;
		string data;
	public:
		node()
		{
			lchild = NULL;
			mchild = NULL;
			rchild = NULL; 
		}
	friend class tree;
};

class tree
{
	private:
		string arr[20];
		node* root;
	public:
		tree()
		{
			root = NULL;
		}
		
		void initialize_array();
		node* create_node(string n);
		void construct();
		void traverse();
			
};

node* tree::create_node(string n)
{
	node* temp = new node;
	temp->data = n;
	return temp;
}

void tree::construct()
{
	root = create_node(arr[0]);
	node *l2, *l3, *l7, *l9,*l11,*l13;
	l2 = create_node(arr[1]);
	l3 = create_node(arr[2]);
	l7 = create_node(arr[6]);
	l9 = create_node(arr[8]);
	l11 = create_node(arr[10]);
	l13 = create_node(arr[12]);
	
	root->lchild = l2;
	root->rchild = l3; 
	l2->lchild = create_node(arr[3]);
	l2->rchild = create_node(arr[4]);
	l2->mchild = l3;
	l3->lchild = create_node(arr[5]);	
	l3->rchild = l7;
	l7->lchild = create_node(arr[7]);
	l7->rchild = l9;
	l9->lchild = create_node(arr[9]);
	l9->rchild = l11;
	l11->lchild = create_node(arr[11]);
	l11->rchild = l13;
	l13->rchild = root;
	
}

void tree::traverse()
{
	node* temp = root;
	char ch;
	while(temp)
	{
	cout<<temp->data;
	cin>>ch;
	if(ch == 'Y' || ch == 'y')
		temp = temp->lchild;
	else if (ch == 'n' || ch == 'N')
		temp = temp->rchild;
	else 
		temp = temp->mchild;
	}
}

void tree::initialize_array()
{
	arr[0] = "\nDo you like working with people? y/n ";
	arr[1] = "\nGood for you! Now, which job sounds more appealing:\nPress Y for Kindergarten Teacher\nPress N for Company Executive\nPress any other key for others. ";
	arr[2] = "\nDo you like working with machines? y/n ";
	arr[3] = "\nYou're a helper!\nYou want a career that lets you help and take care of others.\nCareer ideas include: Nurse, Teacher, Social worker, Counselor, Personal Trainer.";
	arr[4] = "\nYou're a persuader! \nYou seek a career that allows you to gain power and influence.\nCareer ideas include: Financial Advisor, Attorney, Executive, Real Estate Agent, PR specialist.";
	arr[5] = "\nYou're a builder!\n You prefer a career that allows you to be hands-on and learn practical skills.\nCareer Ideas include Carpenter, Police Officer, Pilot, Firefighter, Forester. ";
	arr[6] = "\nAre you artistic or creative? y/n ";
	arr[7] = "\nYou're a creator!\n You want a career that allows you to be artistic and original.\nCareer Ideas include Graphic Designer, Author, Musician, Photographer";
	arr[8] = "\nDo you have a secret love of spreadsheets and filing systems? y/n ";
	arr[9] = "\nYou're an organizer!\n You like a career that lets you put your skills to work organizing info, data and files.\nCareer ideas include Office Manager, Programmer, Accountant, Paralegal, Librarian. ";
	arr[10] = "\nOkay, okay, Do you like Science? y/n ";
	arr[11] = "\nYou're a thinker!\n You prefer a career that involves research, theory and understanding complex ideas. Career ideas include Doctor, Engineer, Social Scientist, College Professor, Researcher, etc. ";
	arr[12] = "\nHmm, it seems you don't like anything that might actually earn you money.\nPress N to start again. "; 
}

int main()
{
tree obj;
obj.initialize_array();
obj.construct();
obj.traverse();

return 0;
}
















