/*
There are flight paths between cities. If there is a flight between city A and city B then
there is an edge between the cities. The cost of the edge can be the time that flight take
to reach city B from A, or the amount of fuel used for the journey. Represent this as a
graph. The node can be represented by airport name or name of the city. Use adjacency
list representation of the graph or use adjacency matrix representation of the graph.
Check whether the graph is connected or not. Justify the storage representation used.
*/
#include<iostream>
using namespace std;
class Flight
{
	int a[10][10],n;
	string name[10];
	public:
		void read();
		void disp();
};
void Flight::read()
{
	int i,j;
	cout<<"Enter number of cities:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=0;
		}
	}
	for(int k=0;k<n;k++)
	{
		cout<<"Enter name of cities:";
		cin>>name[k];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				a[i][j]=0;
			}
			else
			{
				if(a[i][j]==0)
			{
				char ch;
				cout<<"Is any flight for "<<name[i]<<" to "<<name[j]<<" or not (y/n):";
				cin>>ch;
				if(ch=='y'||ch=='Y')
			{
				cout<<"Enter the time required for the flight (in min):";
				cin>>a[i][j];
				a[j][i]=a[i][j];
			}
			else
			{
				a[i][j]=0;
			}
			}
			}
		}
	}
}

void Flight::disp()
{
	for(int k=0;k<n;k++)
	{
		cout<<"  "<<name[k];
		
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<name[i]<<"|";
		
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"|"<<endl;
	}
}
int main()
{
	Flight f;
	f.read();
	f.disp();
	return 0;
}