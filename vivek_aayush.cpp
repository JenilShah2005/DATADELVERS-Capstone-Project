#include <iostream>
#include<vector>
#include <random>

using namespace std;

void distribution(int N, int M,int G){
    vector<int> c;
    float p=5;
    float switch_time=p/5;
if (N<=0||M<=0){
        cerr << "This values are not acceptable!!" << endl;
        return ;
    }
    random_device random;
    mt19937 generate(random());
    uniform_int_distribution<int>distribute(0,N-1);

    int arr[N]={0};
    for(int i=0;i<M/2;++i){
        int temp = distribute(generate);
        arr[temp]++;
    }
     int temp1= (arr[G-1]-1)*p;
     int x=0;
    for(int i=0;i<N;++i){
        if(i==G-1){
            continue;
        }
        if(temp1>(arr[i])*p+(p/5)){
            temp1 = arr[i]*p+(p/5);
            x = i;
        }
    }
    cout<<"Distribution: ";
    for(int i=0;i<N;++i){
        cout<<arr[i]<< " ";
        if(arr[i]*p+(p/5)==temp1||(arr[i]-1)*p==temp1){
            c.push_back(i);
        }
    }
    cout<<endl;
    if(temp1==(arr[G-1]-1)*p) cout<<"Current is best!"<<endl;
    else{
        cout<<"You can switch to gate no. ";
        for(int i=0;i<c.size();++i){
            cout<<c[i]+1;
            if(i!=c.size()-1){
            cout<<",";
            }
            else {
                cout<<" ";
            }
            
        }
        cout<<"from gate no. "<<G<<endl;

        if(c.size()>1){
            int ans;
            cout<<"In which gate you want to switch ?"<<endl;
            cin>>ans;

            arr[ans-1]++;
            arr[G-1]--;
            cout<<"Current people in gate no."<<ans<<" are "<<arr[ans-1]<<endl;
            cout<<"Current people in gate no."<<G<<" are "<<arr[G-1]<<endl;

        }
        else if(c.size()==1){
            arr[c[0]]++;
            arr[G-1]--;
            cout<<"Current people in gate no."<<c[0]+1<<" are "<<arr[c[0]]<<endl;
            cout<<"Current people in gate no."<<G<<" are "<<arr[G-1]<<endl;
        }

        
    }



}
int main() {
    int gates; 
    int people; 
    int gtn;
    cout << "Enter the number of gates (N): ";
    cin >> gates;
    cout << "Enter the total number of people (M): ";
    cin >> people;
    cout << "Enter the gate no. from which you want to switch: ";
    cin>>gtn;
    distribution(gates,people,gtn);
    return 0;
}