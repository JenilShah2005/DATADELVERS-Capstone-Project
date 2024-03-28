#include<bits/stdc++.h>
using namespace std;
void minimize(int *arr,int &M,int &N,int &p){
    int out;
    if(M%2==0) out=M/2;
    else out=M/2+1;
    for(int i=0;i<N;++i){
        int switchs=0;
        if(arr[i]>M/N){
            switchs=arr[i]-M/N;
            for(int j=i+1;j<N;++j){
                if(arr[j]<M/N){
                    if(switchs<=((M/N)-arr[j])){
                        arr[j]+=switchs;
                        cout<<switchs<<" people switch from queue "<<i+1<<" to queue "<<j+1<<"\n";
                        break;
                    }
                    else{
                        switchs-=(M/N)-arr[j];
                        cout<<(M/N)-arr[j]<<" People switch from queue "<<i+1<<" to queue "<<j+1<<"\n";
                        arr[j]=M/N;
                    }
                }
            }
        }
    }
    for(int i=0;(i<N&&out!=0);++i){
        if(arr[i]<M/N){
            out-=M/N-arr[i];
            cout<<M/N-arr[i]<<" People enter to queue "<<i+1<<"\n";
            arr[i]=M/N;
        }
    }
    int rem=M%N;
    for(int i=0;i<rem;++i){
        ++arr[i];
        cout<<"1 person enter to queue "<<i+1<<"\n";
    }
    cout<<"After this Arrengment it will take "<<(p)*(M/N)+p*(rem!=0)<<" min to take all people into the stadium\n";
}

int main(){
    int N,M,p;
    int out;
    cin>>M>>N>>p;
    int arr[N]={0};
    if(M%2==0) out=M/2;
    else out=M/2+1;
    int choice,sum=0;
    cin>>choice;
    if(choice==1){
    for(int i=1;i<=M-out;++i){
        ++arr[rand()%(N)];
    }
    }
    else{
        for(int i=0;i<N;++i){
        cin>>arr[i];
        sum+=arr[i];
        if(sum>=M-out){
            sum-=arr[i];
            arr[i]=M-out-sum;
            sum+=arr[i];
            break;
        }
        }
    }
    for(int i=0;i<N;++i){
        cout<<arr[i]<<"\n";
    }
    minimize(arr,M,N,p);
    return 0;
}