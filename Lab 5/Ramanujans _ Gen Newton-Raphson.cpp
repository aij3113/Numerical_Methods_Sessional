#include<bits/stdc++.h>

using namespace std;

void menu();
void Gen_N_R();
void Ramanujans();
double f(double a);
double f1(double a);
double f2(double a);
int cn,cr,p=2;

int main(){
    int n;

  X:  menu();
    cin>>n;
    switch(n){
        case 1: Gen_N_R(); goto X;
        case 2: Ramanujans(); goto X;
        case 3 : break;
        default : cout<<"\nWrong Input"<<endl; goto X;
    }

    return 0;
}

void Gen_N_R(){
    cn=0;
    double x,x1,t;

    cout<<"\nEnter Initial X: ";
    cin>>x;
    t=x;
    x=t-(p*(f(t)/f1(t)));
    x1=t-((p-1)*(f1(t)/f2(t)));
    cn++;
    while(abs(x-x1)>=.0001){
        t=x;
        x=t-(p*(f(t)/f1(t)));
        x1=t-((p-1)*(f1(t)/f2(t)));
        cn++;
    }
    cout<<"\n\tX: "<<x<<"\t Loop Runs: "<<cn<<" times\n"<<endl;
}

void Ramanujans(){
    double x1,x2,a[100],b[100];
    int i,j,k;
    for(i=0;i<100;i++){
        a[i]=0;
        b[i]=0;
    }

    a[1]=13.0/12.0,a[2]=-3.0/8.0,a[3]=1.0/24.0, b[1]=1.0;

    for(i=2;i<100;i++){
        for(j=1,k=i-1;j<i&&k>=1;j++,k--){
                b[i]=b[i]+(a[j]*b[k]);
        }
    }
    i=1;  cr=0;
    while(1){
            cr++;
        x1=b[i]/b[i+1];
        x2=b[i+1]/b[i+2];
        cout<<b[i]<<"\t"<<b[i+1]<<"\t"<<x1<<endl;
        if(abs(x1-x2)<=0.0001)
            break;
        else
            i++;
    }
     cout<<"\n\tX: "<<x1<<"\t Loop Runs: "<<cr<<" times\n"<<endl;
}

double f(double a){
    return ((a*a*a)-(a*a)-a+1);
}

double f1(double a){
    return ((3*a*a)-(2*a)-1);
}

double f2(double a){
    return ((6*a)-2);
}

void menu(){
    cout<<"\n\t.....MENU....."<<endl;
    cout<<"1. Generalized Newton-Raphson\n2. Ramanujans"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<"Enter Your Choice: ";
}
