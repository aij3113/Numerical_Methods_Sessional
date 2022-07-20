//This code is the Implementation of the Example 6.10 ( S.S. Sastry )

#include<bits/stdc++.h>
using namespace std;

double x[51],y[51];
int n;

void show_xy(){
    cout<<"\n\t X\t  Y\n\t..............."<<endl;
    for(int i=0;i<n;i++){
        cout<<"\t"<<x[i]<<"\t "<<y[i]<<endl;
    }
}

void Trapezoidal(double h){
    double res=y[0]+y[n-1];

    for(int i=1;i<n-1;i++){
        res+=(2*y[i]);
    }
    res=(h*res)/2;

    cout<<"\n\tThe Trapezoidal Integrated Value: "<<res<<endl;
}

void Simpsons(double h){
    double res=y[0]+y[n-1];

    for(int i=1;i<n-1;i++){
        if(i%2){
            res+=(4*y[i]);
        }
        else{
            res+=(2*y[i]);
        }
    }
    res=(h*res)/3;
    cout<<"\n\tThe Simpson's 1/3 Integrated Value: "<<res<<endl;

}

void Init(double h){
    n=(1.0/h)+1;

    x[0]=0.0;
    for(int i=0;i<n;i++){
        x[i]=x[0]+(i*h);
        y[i]=1/(1+x[i]);
    }
    show_xy();
    Trapezoidal(h);
    Simpsons(h);
}

void menu(){
    cout<<"\n\t  Menu of H\n\t............."<<endl;
    cout<<"\t1. 0.5\n\t2. 0.25\n\t3. 0.125\n\t0. Exit\n"<<endl;
    cout<<"\tEnter your Choice: ";
}
int main(){
    int b=1;
    while(b){
        int a;
        menu();
        cin>>a;
        switch(a){
            case 1: Init(0.5); break;
            case 2: Init(0.25); break;
            case 3: Init(0.125); break;
            case 0: b=0; break;

            default: cout<<"Invalid Input\n"<<endl;break;
        }
    }


    return 0;
}
