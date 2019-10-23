#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

ifstream input;
ofstream output;

struct Node{
	char *symbol;
	int frequency;
	Node *next;
	Node *left;
	Node *right;
};

void TreeTraverse(string *H,Node *A,string C)
{
	output<<A->symbol<<" ";
	if(A->left == NULL && A->right==NULL)
	{
		if(*(A->symbol) >= 'a' && *(A->symbol)<='z')
		{
			H[(int)(*(A->symbol) - 'a')] = C;
		}
		else
		{
			H[(int)(*(A->symbol)-'0')+26] = C;
		}
	}
	else
	{
		string t;
		t = C;
		C.append("0");
		t.append("1");
		TreeTraverse(H,A->left,C);
		TreeTraverse(H,A->right,t);
	}
}

int main()
{
	
	input.open("log.txt");
	output.open("18CS10034_A5_output.txt");

	int n;
	input>>n;
	int freq[36];

	for(int i=0;i<36;i++)
	{
		freq[i]=0;
	}

	for(int i=0;i<n;i++)
	{
		string s;
		getline(input,s);

		for(int j=0;j<s.size();j++)
		{
			if((int)s[j] >='a' && (int)s[j] <='z')
			{
				freq[(int)s[j] - 'a']++;
			}
			else
			{
				freq[(int)s[j] - '0' + 26]++;
			}
		}
	}

	for(int i=0;i<36;i++)
	{
		if(i==0)
		{
			output<<(char)('a'+i)<<"="<<freq[i];
		}
		else if(i<=25)
		{
			output<<","<<(char)('a'+i)<<"="<<freq[i];
		}
		else
		{
			output<<","<<(char)('0'+i-26)<<"="<<freq[i];
		}
	}
	output<<"\n";

	int temp[36];
	for(int i=0;i<36;i++)
		temp[i] = freq[i];
	int max=INT_MIN;
	int index;

	Node *list;
	list = NULL;

	for(int i=0;i<36;i++)
	{
		max = INT_MIN;
		for(int j=0;j<36;j++)
		{
			if(temp[j]>=max)
			{
				max = temp[j];
				index = j;
			}
		}

		char *s;
		s = new char;
		if(index>=0 && index<=25)
		{
			*s = char(index + 'a');
		}
		else
			*s = char(index + '0' -26);

		Node *tem;
		tem = new Node;
		tem->frequency = max;
		tem->symbol = s;
		tem->left = NULL;
		tem->right = NULL;
		tem->next = NULL;

		temp[index] = INT_MIN;

		if(list == NULL)
		{
			list = tem;
		}
		else
		{
			tem->next = list;
			list = tem;
		}

	}

	int count=1;

	while(list->next !=NULL)
	{

		Node *tr;
		tr = list;
		while(tr!=NULL)
		{
			cout<<tr->symbol<<" ";
			tr = tr->next;
		}
		cout<<endl;


		char *a;
		if(count>9)
		{
			a = new char[3];
			a[0] = 'N';
			a[1] = (count/10) + '0';
			a[2] = (count%10) + '0';
		}
		else
		{
			a = new char[2];
			a[0] = 'N';
			a[1] = count + '0';
		}

		Node *temp;
		temp = new Node;
		temp->symbol = a;
		temp->frequency = list->frequency + list->next->frequency;
		temp->left = list;
		temp->right = list->next;
		temp->next = NULL;

		cout<<"a"<<endl;
		list = list->next->next;
		if(list == NULL)
		{
			list = temp;
			break;
		}


		Node *temp1;
		temp1 = list;

		if(list->frequency >= temp->frequency)
		{
			temp->next = list;
			list = temp;
		}
		else
		{
			while(list->next!=NULL)
			{
				if(list->next->frequency >= temp->frequency)
				{
					temp->next = list->next;
					list->next = temp;
					break;
				}
				list = list->next;
			}
			if(list->next==NULL)
			{
				list->next = temp;
			}
			list = temp1;

		}

		count++;

	}

	cout<<list->symbol<<endl;

	string H[36];
	string C = "";

	TreeTraverse(H,list,C);

	output<<"\n";

	for(int i=0;i<36;i++)
	{
		cout<<H[i]<<endl;
	}
	
	for(int i=0;i<36;i++)
	{
		if(i<=25)
		{
			output<<(char)('a'+i)<<" "<<H[i]<<endl;
		}
		else
		{
			output<<(char)('0'+i-26)<<" "<<H[i]<<endl;
		}
	}





}