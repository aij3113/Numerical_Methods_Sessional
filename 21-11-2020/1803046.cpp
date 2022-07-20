//  This code checks whether a given
//  non-singular square matrix is
//  Lower Triangular
//  Upper Triangular
//  or  Non-Triangular.

#include<bits/stdc++.h>
using namespace std;

double x[51][51];
int n;

void input(){
    cout<<"\n\tEnter N*N Matrix's N: ";
    cin>>n;

    int v;

    freopen("Matrix.txt","r",stdin);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v;
            x[i][j]=v;
        }
    }
}

void show(){
    cout<<"\n\tThe Matrix is :"<<endl;
    for(int i=0;i<n;i++){
        cout<<"\t";
        for(int j=0;j<n;j++){
            cout<<"  "<<x[i][j];
        }
        cout<<endl;
    }
}

int islow(){
    int z=1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(x[i][j]!=0){
                z=0;
                break;
            }
        }
        if(!z){
            break;
        }
    }
    return z;
}

int isup(){
    int z=1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(x[j][i]!=0){
                z=0;
                break;
            }
        }
        if(!z){
            break;
        }
    }
    return z;
}

void check(){
    int low,up;

    low=islow();
    up=isup();

    if(low||up){
        if(low&&up){
            cout<<"\n\tBoth Lower & Upper Triangular Matrix"<<endl;
        }
        else if(low){
            cout<<"\n\tLower Triangular Matrix"<<endl;
        }
        else if(up){
            cout<<"\n\tUpper Triangular Matrix"<<endl;
        }
    }
    else{
        cout<<"\n\tNon-Triangular Matrix"<<endl;
    }

}

int main(){

    input();
    show();
    check();


    return 0;
}
