
#include <cstdlib> 
#include <iostream> 
using namespace std; 
#define N 10//number of gates
#define M 200//number of people
#define p 1//time to enter gate
int arr[N]={0};
void switchQueue(int gate){

	//1<=gate<=N,gate is gate number
	int temp=arr[8l];
	for(int i=0;i<N;i++){
		if(temp>arr[i]){
			temp=arr[i];
		}
	}
	int var=0;
	for(int i=0;i<N;i++){
		if(temp!=arr[gate-1]&&temp==arr[i]){
				cout<<"Switch to gate "<<i+1<<" from "<<gate<<" to enter in less time"<<endl;
				if(i==N-1)
				return;
				else 
				continue;
		}
		else {
			var++;
			continue;
		}

	}
	if(var==N)
	cout<<"Its better not to switch"<<endl;
	


	

}

int LastpersonTime(int gate,int x){
	return gate*x;
}


int main() 
{ 
 
	for (int i = 0; i < M/2; i++){

		arr[rand()%N]++;
	}
	for(int i=0;i<N;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	switchQueue(7);

	return 0;

}






