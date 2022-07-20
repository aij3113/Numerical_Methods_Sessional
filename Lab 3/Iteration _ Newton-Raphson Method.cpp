//Implication of Iteration & Newton-Raphson Method
// for the Equation  2x-3=cos(x)

#include<bits/stdc++.h>
#include<math.h>

using namespace std;

#define pi 3.1416;
void menu();
double f(double x);
double f1(double x);
double f2(double x);
void Iteration();
void Newton_Raphson();
void Comparison();
int ci,cn;

int main(){
    int n,X;
 X: menu();
    cin>>n;
    switch(n){
        case 1 : Iteration(); goto X;
        case 2 : Newton_Raphson(); goto X;
        case 3 : Comparison(); goto X;
        case 4 : break;
        default : cout<<"\nWrong Input\n"<<endl; goto X;
    }
    return 0;
}

void Iteration(){
    ci=0;
    double x,temp=0.0;
    cout<<"Enter Initial x: ";
    cin>>x;
    while(abs(x-temp)>0.001){
        temp=x; ci++;
        x=f(x);
    }
    cout<<"\nX: "<<x<<"  Loop Runs: "<<ci<<" times\n"<<endl;
}

void Newton_Raphson(){
    cn=0;
    double x,temp1=0.0;
    cout<<"Enter Initial x: ";
    cin>>x;
    while(abs(x-temp1)>0.001){
        temp1=x; cn++;
        x=x-(f1(x)/f2(x));
    }
    cout<<"\nX: "<<x<<"  Loop Runs: "<<cn<<" times\n"<<endl;
}

void Comparison(){
    cout<<"\nIn Iteration Method Loop Runs: "<<ci<<" times\n"<<endl;
    cout<<"In Newton-Raphson Method Loop Runs: "<<cn<<" times\n"<<endl;
}

double f(double x){
    return (0.5*(3+cos(x)));
}

double f1(double x){
    return ((2*x)-3-(cos(x)));
}

double f2(double x){
    return (2+(sin(x)));
}

void menu(){
    cout<<"\t.....Menu.....\n"<<endl;
    cout<<" 1. Iteration Method"<<endl;
    cout<<" 2. Newton-Raphson Method"<<endl;
    cout<<" 3. Comparison"<<endl;
    cout<<" 4. Exit\n"<<endl;
    cout<<"Enter Your Choice: ";
}

