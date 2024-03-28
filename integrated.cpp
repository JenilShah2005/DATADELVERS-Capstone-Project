#include<bits/stdc++.h>
using namespace std;
int M,N,out;
float p;
void display_gates(int *arr){
    for(int i=0;i<N;++i){
        cout<<arr[i]<<"\n";
    }
}
void enter(int *arr){
    int min=arr[0];vector<int>index;
    for(int i=1;i<N;++i){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    for(int i=0;i<N;++i){
        if(arr[i]==min){
            index.push_back(i);
        }
    }
    cout<<"You can enter to following gate number: ";
    for(int i=0;i<index.size();++i){
        cout<<index[i]+1;
            if(i!=index.size()-1){
            cout<<",";
            }
            else {
                cout<<" ";
            }
    }
    int t;
    if(index.size()>1){
        cout<<"You want to enter in which gate: ";
        cin>>t;
        ++arr[t-1];
    }
    else ++arr[index[0]];
}
void last_person_time(int *arr,int gtn){
    cout<<"The time taken by the last person to enter in line number: "<<gtn<<" is "<<p*arr[gtn]<<" mins. \n";
}
void distribution(int G){
    vector<int> c;
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
void minimize(int *arr){
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
void menu(int *arr){
    cout<<"Enter 1 for choosing line to switch\n"
        <<"Enter 2 for choosing line to Enter\n"
        <<"Enter 3 to minimize the overall queues\n"
        <<"Enter 4 to get the last person time in a given line\n"
        <<"Enter Your choice: ";
    int choice;
    cin>>choice;
    int gtn;
    switch(choice){
        case 1:
        cout << "Enter the gate no. from which you want to switch: ";
        cin>>gtn;
        if(!(gtn>=1&&gtn<=N)){
            cout<<"Invalid Gate number pls retry.\n";
        }
        else
        distribution(gtn);
        display_gates(arr);
        menu(arr);
        break;
        case 2:
        enter(arr);
        display_gates(arr);
        menu(arr);
        break;
        case 3:
        minimize(arr);
        display_gates(arr);
        break;
        case 4:
        cout << "Enter the gate no. from which you want to switch: ";
        cin>>gtn;
        last_person_time(arr,gtn);
        display_gates(arr);
        menu(arr);
        break;
        default:
        cout<<"Invalid choice try again\n";
        display_gates(arr);
        menu(arr);
        break;
    }
}
int main(){
    cout << "Enter the number of gates (N): ";
    cin >> N;
    cout << "Enter the total number of people (M): ";
    cin >> M;
    cout<< "Enter the time for a single person to enter (p): ";
    cin>> p;
    int x,sum=0;
    cout<<"Enter 1 to randomly assign values else you can enter number of peoples in each gate\nEnter your choice: ";
    cin>>x;
    if(M%2==0) out=M/2;
    else out=M/2+1;
    int arr[N]={0};
    if(x==1){
    random_device random;
    mt19937 generate(random());
    uniform_int_distribution<int>distribute(0,N-1);

    for(int i=0;i<M/2;++i){
        int temp = distribute(generate);
        arr[temp]++;
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
    display_gates(arr);
    menu(arr);
}