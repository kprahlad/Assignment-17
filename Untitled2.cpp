#include<iostream>
using namespace std;
int heap[100],i=0;
void insert(int data)
{
	heap[i]=data;
	if(i)
	{
		int j=i;
		while(j&&heap[(j-1)/2]<heap[j])
		{
			int k=heap[j];
			heap[j]=heap[(j-1)/2];
			heap[(j-1)/2]=k;
			j=(j-1)/2;
		}
	}
	i++;
}
void print()
{
	cout<<endl;	
	for(int k=0;k<i;k++) cout<<heap[k]<<" ";
}
void remove()
{
	if(i)
	{
		heap[0]=heap[i-1];
		int j=0,flag=1;
		while(flag)
		{
			if(2*j+1>i) flag=0;
			else 
			{
				int max=2*j+2;
				if(max>i) max--;
				else if (heap[max]<heap[max-1]) max--;
				if(heap[max]>heap[j])
				{
					int k=heap[j];
					heap[j]=heap[max];
					heap[max]=k;
					j=max;
				}
				else flag=0;
			}
		}
		i--;
	}
	else cout<<"No heap!";
}
int main()
{
	insert(12);
	insert(10);
	insert(16);
	insert(24);
	insert(20);
	insert(11);
	insert(21);
	insert(6);
	print();
	remove();
	print();
	remove();
	print();
}
