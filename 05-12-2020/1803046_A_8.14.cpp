// This code solves the problem of Exercise 8.14
// of Introductory Methods of Numerical Analysis
// by S.S. Sastry ( 5th Edition )

#include<bits/stdc++.h>
using namespace std;

double x[51],y[51];
double k1[51],k2[51],k3[51],k4[51],k[51];
double h;

double f(double a,double b){
    return 1+((2*a*b)/(1+(a*a)));
}

void solve_k(int i){
    //this part calculates the value of k1,k2,k3,k4
    k1[i]=h*f(x[i-1],y[i-1]);
    k2[i]=h*f(x[i-1]+(0.5*h),y[i-1]+(0.5*k1[i]));
    k3[i]=h*f(x[i-1]+(0.5*h),y[i-1]+(0.5*k2[i]));
    k4[i]=h*f(x[i-1]+h,y[i-1]+k3[i]);

    //this part calculates (k1 + 2(k2+k3) +k4)
    k[i]=k1[i]+(2*(k2[i]+k3[i]))+k4[i];

    printf("The value of k1 = %.4f",k1[i]);
    printf("\nThe value of k2 = %.4f",k2[i]);
    printf("\nThe value of k3 = %.4f",k3[i]);
    printf("\nThe value of k4 = %.4f\n",k4[i]);
}

void solve_xy(int i){
    //this part calculates set the value of x and solve y(x) according to that
    x[i]=x[i-1]+h;
    y[i]=y[i-1]+(k[i]/6);

    printf("\n\tY(%.1f) = %.5f\n\n",x[i],y[i]);

}


int main(){
    cout<<"\nGiven Equation is Y' = 1 + (2XY/(1+(X*X)))    and Y(0) = 0"<<endl;
    cout<<"\nLet the value of h = 0.1\n"<<endl;
    //Initializing h,x0,y0
    h=0.1;
    x[0]=0; y[0]=0;

    for(int i=1;i<4;i++){
        solve_k(i);
        solve_xy(i);
    }

    return 0;
}
