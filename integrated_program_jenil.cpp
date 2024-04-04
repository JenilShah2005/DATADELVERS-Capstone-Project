#include<bits/stdc++.h>
using namespace std;
int M,N,out;
float p,switch_time,time_spend;
void display_gates(int *arr){
    cout<<"Distribution of people in gates: ";
    for(int i=0;i<N;++i){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
void enter(int *arr){
    if(out<=0){
        cout<<"There are No people outside Re-try\n";
        return;
    }
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
                cout<<"\n";
            }
    }
    int t;
    if(index.size()>1){
        cout<<"You want to enter in which gate: ";
        cin>>t;
        for(int i=0;true;++i){
                if(t==index[i]+1){
                    break;
                }
                else if(i+1==(index.size())){
                    cout<<"Invalid input retry\n";
                    cout<<"You want to enter in which gate: "<<endl;
                    cin>>t;
                    i=-1;
                }
            }
        ++arr[t-1];
    }
    else ++arr[index[0]];
    --out;
}
void last_person_time(int *arr,int gtn){
    cout<<"The time taken by the last person to get entry in stadium from gate no.: "<<gtn<<" is "<<p*arr[gtn-1]<<" mins. \n";
}
void distribution(int G,int *arr){
    vector<int> c;
    if (N<=0||M<=0){
        cerr << "This values are not acceptable!!" << endl;
        return ;
    }
     float temp1= (arr[G-1]-1)*p;
     int x=0;
    for(int i=0;i<N;++i){
        if(i==G-1){
            continue;
        }
        if(temp1>(arr[i])*p+(switch_time)){
            temp1 = (arr[i])*p+(switch_time);
            x = i;
        }
    }
    cout<<"Distribution of people in gates: ";
    for(int i=0;i<N;++i){
        cout<<arr[i]<< " ";
        if(arr[i]==arr[x]){
            c.push_back(i);
        }
    }
    cout<<endl;
    if(temp1==(arr[G-1]-1)*p) cout<<"Current queue in which you are, is best!"<<endl;
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
            for(int i=0;true;++i){
                if(ans==c[i]+1){
                    break;
                }
                else if(i+1==(c.size())){
                    cout<<"Invalid input retry\n";
                    cout<<"In which gate you want to switch ?"<<endl;
                    cin>>ans;
                    i=-1;
                }
            }
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
        time_spend+=switch_time;
        if(time_spend>=p){
            cout<<"Entry Proceeded in each gate.\n";
            time_spend-=p;
            for(int i=0;i<N;++i){
                if(arr[i]>0){
                --arr[i];
                }
                --M;
            }
        }
    }
}
void minimize(int *arr){
    for(int i=0;(i<N&&out>0);++i){
        if(arr[i]<M/N){
            out-=M/N-arr[i];
            if(out<0){
                cout<<M/N-arr[i]+out<<" People from remaining people enter to queue "<<i+1<<"\n";
                arr[i]=M/N;
                arr[i]+=out;
            }
            else{
                cout<<M/N-arr[i]<<" People from remaining people enter to queue "<<i+1<<"\n";
                arr[i]=M/N;
            }
        }
    }
    int rem=M%N;
    for(int i=0;i<rem&&out>0;++i){
        if(arr[i]<=M/N){
        ++arr[i];
        cout<<"1 People from remaining people enter to queue "<<i+1<<"\n";
        --out;
        }
    }
    int k=0;
    int switchs=0;
    for(int i=0;i<N;++i){
        if((arr[i]>(M/N+1)&&rem!=0)||(arr[i]>M/N&&rem==0)){
            switchs=arr[i]-M/N;
            arr[i]-=switchs;
            for(int j=i+1;j<N;++j){
                if(arr[j]<M/N){
                    if(switchs<=((M/N)-arr[j])){
                        arr[j]+=switchs;
                        cout<<switchs<<" People switch from queue "<<i+1<<" to queue "<<j+1<<"\n";
                        switchs=0;
                        break;
                    }
                    else{
                        switchs-=(M/N)-arr[j];
                        cout<<(M/N)-arr[j]<<" People switch from queue "<<i+1<<" to queue "<<j+1<<"\n";
                        arr[j]=M/N;
                        k=i;
                    }
                }
            } 
        }
    }
    for(int i=0;i<N&&switchs>0;++i){
        if(i!=k)
        cout<<"1 Person switch from queue "<<k+1<<" to queue "<<i+1<<"\n";
        ++arr[i];
        --switchs;
    }
    cout<<"After this Arrangement it will take "<<(p)*(M/N)+p*(rem!=0)<<" minutes to take all people into the stadium\n";
}
void menu(int *arr){
    cout<<"\n\nEnter 1 to switch the queue\n"
        <<"Enter 2 to choose in which gate you want to Enter\n"
        <<"Enter 3 to get minimized overall time to take all people in\n"
        <<"Enter 4 to get the last person time in a given queue\n"
        <<"Enetr 0 to end the program\n"
        <<"Enter Your choice: ";
    int choice;
    cin>>choice;
    int gtn;
    switch(choice){
        case 1:
         while(1){
                 cout<< "Enter the gate no. from which you want to switch: ";
                cin>>gtn;
                if(arr[gtn-1]==0){
                    cout<<"Invalid input as enetred queue is empty."<<endl;
                }
                else
                break;

            }
        if(!(gtn>=1&&gtn<=N)){
            cout<<"Invalid Gate number please retry.\n";
        }
        else
        system("CLS");
        cout<<"The total number of people present(M) are: "<<M<<"\nThe total number gates(N) are "<<N<<"\nThe time for entry(p) in mins is "<<p<<"\n";
        distribution(gtn,arr);
        display_gates(arr);
        menu(arr);
        break;
        case 2:
        system("CLS");
        cout<<"The total number of people present are: "<<M<<"\nThe total number gates are "<<N<<"\nThe value of p in mins is "<<p<<"\n";
        display_gates(arr);
        enter(arr);
        display_gates(arr);
        menu(arr);
        break;
        case 3:
        system("CLS");
        cout<<"The total number of people present are: "<<M<<"\nThe total number gates are "<<N<<"\nThe value of p in mins is "<<p<<"\n";
        display_gates(arr);
        minimize(arr);
        display_gates(arr);
        break;
        case 4:
        system("CLS");
        cout<<"The total number of people present are: "<<M<<"\nThe total number gates are "<<N<<"\nThe value of p in mins is "<<p<<"\n";
        display_gates(arr);
        cout << "Enter the gate no. from which you want to switch: ";
        cin>>gtn;
        last_person_time(arr,gtn);
        display_gates(arr);
        menu(arr);
        break;
        case 0:
        return;
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
    cout<< "Enter the time for a single person to enter (p in mins): ";
    cin>> p;
    if(N<=0 || M<=0 || p<0) {cout<<"Invalid inputs"<<endl; exit(1);}
    else{
    while(true){
        cout<<"Enter time to switch from a line (in mins): ";
        cin>>switch_time;
        if(switch_time>=p){
            cout<<"Switch time can't be grater than entry time! Re-enter\n";
        }
        else{
            break;
        }
    }
    cout<<endl;

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
        cout<<"Enter the number of people in the queues of each gate "<<i+1<<": ";
        cin>>arr[i];
        sum+=arr[i];
        if(sum>M-out){
            sum-=arr[i];
            arr[i]=M-out-sum;
            sum+=arr[i];
            cout<<"Total number of people exceed M/2 therefore only "<<arr[i]<<" People entered this queue\n";
            break;
        }
        }
        if(sum<M-out){
            out=M-sum;
        }
    }
    display_gates(arr);
    menu(arr);
    }
}