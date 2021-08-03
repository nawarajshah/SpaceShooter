#include<iostream>
using namespace std;
class Available
{
	private:
		char DayOfweek[30];
		int shiftTime1,shiftTime2,i,NoD;
	public:
		void whenAvailable()
		{
			cout<<"Enter no. of available days:"<<endl;
			cin>>NoD;
			cout<<"Enter available on which day?:"<<endl;
			for(i=0;i<NoD;i++)
			{
				cin>>DayOfweek[i];
			}
			cout<<"Enter shift time1:"<<endl;
			cin>>shiftTime1;
		    
		    cout<<"Enter shift time2:"<<endl;
			cin>>shiftTime2;
		     
		}
		
		void displayAvailable()
		{
			cout<<"Dr. is available for "<<NoD<<" in Week"<<endl;
			cout<<"  **Available days are**:"<<endl;
			for(i=0;i<NoD;i++)
			{
			  cout<<DayOfweek[i]<<endl;
		    
			}
			
			cout<<"1st shift:"<<shiftTime1<<endl<<"2nd shift:"<<shiftTime2<<endl;
		}
		
		
	
};
int main()
{
	Available a1;
	a1.whenAvailable();
	a1.displayAvailable();
	return 0;
	
}
