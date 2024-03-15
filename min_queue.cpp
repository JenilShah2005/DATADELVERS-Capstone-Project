#include <iostream>
#include<vector>
#include <random>
using namespace std;
void distribution(int N, int M){
    vector<int> c;
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
     int temp1= arr[0], x=0;
    for(int i=1;i<N;++i){
        if(temp1>arr[i]){
            temp1 = arr[i];
            x = i;
        }
    }
    cout<<"Distribution: ";
    for(int i=0;i<N;++i){
        cout<<arr[i]<< " ";
        if(arr[i]==temp1){
            c.push_back(i);
        }
    }
    cout<<endl;
    if(temp1==arr[0]) cout<<"Queue in which you are standing is the best!"<<endl;
    else{
        for(int i=0;i<c.size();++i){
            cout<<"You can switch to gate no."<<c[i]+1<<endl;
        }
    }

}
int main() {
    int gates; 
    int people; 

    cout << "Enter the number of gates (N): ";
    cin >> gates;
    cout << "Enter the total number of people (M): ";
    cin >> people;
    distribution(gates,people);
    return 0;
}