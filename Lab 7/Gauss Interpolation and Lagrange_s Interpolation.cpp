#include<bits/stdc++.h>

using namespace std;


void menu();
void GF();
void GB();
void LI();
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
        case 1: GF(); goto X;
        case 2: GB(); goto X;
        case 3: LI(); goto X;
        case 4: get_x_y(); goto X;
        case 5: break;
        default : cout<<"\nWrong Input\n"<<endl; goto X;
    }

    return 0;
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

void GF(){
    double yx,g;
    int vn,c;
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            y[j][i]=y[j+1][i-1]-y[j][i-1];
        }
    }
    cout<<"\n\tForward Table\n\nX\tY\tdY\t............................."<<endl;
    vn=n;
    for(int i=0;i<n;i++){
        cout<<x[i]<<"\t";
        for(int j=0;j<vn;j++){
            cout<<y[i][j]<<"\t";
        }
        vn--;
        cout<<endl;
    }

    if(n%2)
        vn=n/2;
    else
        vn=(n/2)-1;

    p=(dx-x[n/2])/h;
    yx=(double)y[vn][0];
    for(int i=1;i<n;i++){
        g=1;
        c=0;
        for(int j=0;j<i;j++){
            if(j%2)
                g*=(p-c);
            else{
                g*=(p+c);
                c++;
            }
        }
        yx+=((g*y[vn][i])/fact(i));

        if(i%2)
            vn--;
    }
    cout<<"\nThe Value of F("<<dx<<") is: "<<yx<<endl;
}

void GB(){
    double yx,g;
    int vn,c;
    for(int i=1;i<n;i++){
        for(int j=i;j<n-i;j++){
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
    vn=n/2;
    p=(dx-x[vn])/h;
    yx=(double)y[vn][0];
    for(int i=1;i<n;i++){

        g=1;
        c=0;
        for(int j=0;j<i;j++){
            if(j%2)
                g*=(p+c);
            else{
                g*=(p-c);
                c++;
            }
        }
        yx+=((g*y[vn][i])/fact(i));

        if(i%2){
            vn++;
        }
    }
    cout<<"\nThe Value of F("<<dx<<") is: "<<yx<<endl;
}

void LI(){
    double yx=0,up,down;

    for(int i=0;i<n;i++){
        up=1;
        for(int j=0;j<n;j++){
            if(j!=i){
                up*=(dx-x[j]);
            }
        }
        down=1;
        for(int j=0;j<n;j++){
            if(j!=i){
                down*=(x[i]-x[j]);
            }
        }
        cout<<up<<"\t"<<down<<endl;
        yx+=((up*y[i][0])/down);
    }

    cout<<"\nThe Value of F("<<dx<<") is: "<<yx<<endl;
}

void menu(){
    cout<<"\n1. Gauss Central Forward\n2. Gauss Central Backward\n3. Lagrange's Interpolation"<<endl;
    cout<<"4.  New Problem\n5. Exit"<<endl;
    cout<<"\nEnter Your Choice: ";
}

int fact(int a){
    if(a==0||a==1)
        return 1;
    else
        return (a*fact(a-1));
}
