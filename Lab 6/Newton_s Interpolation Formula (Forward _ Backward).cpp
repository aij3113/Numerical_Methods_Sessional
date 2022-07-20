#include<bits/stdc++.h>

using namespace std;


void menu();
void Forward();
void Backward();
void get_x_y();
int n;
int fact(int a);
double x[10],y[10][10],p,h,dx;

int main(){
    get_x_y();
    int a;
 X: menu();
    cin>>a;
    switch(a){
        case 1: Forward(); goto X;
        case 2: Backward(); goto X;
        case 3: get_x_y(); goto X;
        case 4: break;
        default : cout<<"\nWrong Input\n"<<endl; goto X;
    }

    return 0;
}

void Forward(){
    double yx,up;
    p=(dx-x[0])/h;
    int vn=n;
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            y[j][i]=y[j+1][i-1]-y[j][i-1];
        }
    }
    cout<<"\n\tForward Table\n\nX\tY\tdY\t............................."<<endl;
    for(int i=0;i<n;i++){
        cout<<x[i]<<"\t";
        for(int j=0;j<n-i;j++){
            cout<<y[i][j]<<"\t";
        }
        vn--;
        cout<<endl;
    }
    yx=(double)y[0][0];
    for(int i=1;i<n;i++){
        up=p;
        for(int j=1;j<i;j++){
            up=up*(p-j);
        }
        yx=yx+((up*y[0][i])/fact(i));
    }
    cout<<"\nThe Value of F("<<dx<<") is: "<<yx<<endl;
}

void Backward(){
    double yx,up;
    p=(dx-x[n-1])/h;
    int vn=n;
    for(int i=1;i<n;i++){
        for(int j=vn;j>=i;j--){
            y[j][i]=y[j][i-1]-y[j-1][i-1];
        }
    }

    cout<<"\n\tBack-Ward Table\n\nX\tY\tdY\t............................."<<endl;
    for(int i=0;i<n;i++){
        cout<<x[i]<<"\t";
        for(int j=0;j<i+1;j++){
            cout<<y[i][j]<<"\t";
        }
        cout<<endl;
    }
    yx=(double)y[n-1][0];
    for(int i=1;i<n;i++){
        up=p;
        for(int j=1;j<i;j++){
            up=up*(p+j);
        }
        yx=yx+((up*y[n-1][i])/fact(i));
    }
    cout<<"\nThe Value of F("<<dx<<") is: "<<yx<<endl;
}

void menu(){
    cout<<"\n1. Forward\n2. Backward\n3. New Problem\n4. Exit"<<endl;
    cout<<"\nEnter Your Choice: ";
}

void get_x_y(){
    cout<<"\nEnter Number of Points: ";
    cin>>n;
    cout<<"Enter X and Y\nX Y"<<endl;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i][0];
    }
    cout<<"\nEnter Desired X: ";
    cin>>dx;
    h=x[1]-x[0];
}

int fact(int a){
    if(a==0||a==1)
        return 1;
    else
        return (a*fact(a-1));
}
