//Implementation of Bisection & False Position Method
#include<bits/stdc++.h>
#include<math.h>

using namespace std;

void menu();
double f(double p);
void bisection();
void false_p();
void comparism();
int degree;
int c[100],cb,cf;
double a,b,x;

int main(){
    int n;
    X: menu();
    cin>>n;
    switch(n){
        case 1: bisection();goto X;
        case 2: false_p(); goto X;
        case 3: comparism(); goto X;
        case 4: break;
        default: cout<<"\nWrong Input\n"; goto X;
   }

    return 0;
}

double f(double p){
    double fx=0.0;
    for(int i=degree;i>=0;i--){
        fx=fx+(c[i]*pow(p,i));
    }

    return fx;
}

void bisection(){
    cb=0;
   // int X;
    double fx,Fx=0;
    cout<<"\nEnter Degree: ";
    cin>>degree;
    cout<<"\nEnter Constants: ";
    for(int i=degree;i>=0;i--){
        cin>>c[i];
    }
    cout<<"\nEnter Intervals: ";
    cin>>a>>b;
 X: x=1.0*(a+b)/2.0;
    fx=f(x);
    while((abs(fx-Fx))>0.001){
        Fx=fx;cb++;
        if(fx<0){
            a=x;goto X;
        }
        else{
            b=x;goto X;
        }
    }
    cout<<"\nX: "<<x<<endl;
    cout<<"Loop Runs : "<<cb<<" Times\n"<<endl;
}

void false_p(){
    cf=0;
    //int X;
    double fx,Fx=0;
    cout<<"\nEnter Degree: ";
    cin>>degree;
    cout<<"\nEnter Constants: ";
    for(int i=degree;i>=0;i--){
        cin>>c[i];
    }
    cout<<"\nEnter Intervals: ";
    cin>>a>>b;

 X: x=(double)(((a*f(b))-(b*f(a)))/(f(b)-f(a)));
    fx=f(x);
    cout<<a<<"\t"<<b<<"\t"<<x<<"\t"<<fx<<endl;
    while(abs(fx-Fx)>0.001){
        Fx=fx;cf++;
        if(fx<0){
            a=x;goto X;
        }
        else{
            b=x;goto X;
        }
    }
    cout<<"\nX: "<<x<<endl;
    cout<<"Loop Runs : "<<cf<<" Times"<<endl;
}

void comparism(){
    cout<<"\nBisection Runs: "<<cb<<" Times"<<endl;
    cout<<"False Position Runs: "<<cf<<" Times\n"<<endl;
}

void menu(){
    cout<<"\n.....MENU.....\n"<<endl;
    cout<<"1. Bisection\n2. False-Position"<<endl;
    cout<<"3. Comparison\n4. Exit"<<endl;
    cout<<"\nEnter Your Choice: ";
}
