#include<bits/stdc++.h>
using namespace std;

int n;
double x[101];
double y[101][101];
string buffer;
vector<string>tmp;

void input(){
    ifstream f1;
    f1.open("Newton's.txt");

    while(! f1.eof()){
        f1>>buffer;
        tmp.push_back(buffer);
        buffer.clear();
    }

    for(int i=0,j=0;i<tmp.size();i+=2,j++){
        x[j]=stod(tmp.at(i));
        y[j][0]=stod(tmp.at(i+1));
        n=j+1;
    }
}

void NFD(){
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            y[j][i]=y[j+1][i-1]-y[j][i-1];
        }
    }
}

void NBD(){
    for(int i=1;i<n;i++){
        for(int j=n-1;j>=i;j--){
            y[j][i]=y[j][i-1]-y[j-1][i-1];
        }
    }

}

void FDT(){
    cout<<"\n\tForward Table"<<endl;
    for(int i=0;i<n;i++){
        cout<<"\t"<<x[i]<<"\t";
        for(int j=0;j<n-i;j++){
            cout<<y[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}

void BDT(){
    cout<<"\n\tBackward Table"<<endl;
    for(int i=0;i<n;i++){
        cout<<"\t"<<x[i]<<"\t";
        for(int j=0;j<=i;j++){
            cout<<y[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}

int fact(int n){
    if(n==1)
        return 1;
    else
        return n*fact(n-1);
}

double Fp_val(int n,double p){
    double p_o = p;

    for(int i=1;i<n;i++){
        p_o*=(p-i);
    }

    return p_o;
}

double Bp_val(int n,double p){
    double p_o = p;

    for(int i=1;i<n;i++){
        p_o*=(p+i);
    }

    return p_o;
}

double FINT(double val){

    double result = y[0][0];
    double h=x[1]-x[0];
    double p= (val-x[0])/h;

    for(int i=1;i<n;i++){
        result+=(Fp_val(i,p)*y[0][i])/fact(i);
    }

    return result;
}

double BINT(double val){

    double result = y[n-1][0];
    double h=x[1]-x[0];
    double p= (val-x[n-1])/h;

    for(int i=1;i<n;i++){
        result+=(Bp_val(i,p)*y[n-1][i])/fact(i);
    }

    return result;
}

void menu(){

    cout<<"\n\tChoose Option \n"<<endl;
    cout<<"\t1. Forward\n\t2. Backward\n"<<endl;
}

int main(){
    /// Step 1: Input

    input();

    double vx;

    while(true){
        cout<<"\n\tEnter the value of x : ";
        cin>>vx;
        if(!vx){
            break;
        }
        menu();
        int a;
        cout<<"\t";
        cin>>a;
        switch(a){
            case 1: NFD();  /// Newton's Forward Diff.
                    FDT();  /// Forward Diff. Table
                    cout<<"\t"<<FINT(vx)<<endl;   /// Forward Interpolation
                    break;

            case 2: NBD();  /// Newton's Backward Diff.
                    BDT();  /// Backward Diff. Table
                    cout<<"\t"<<BINT(vx)<<endl;   /// Backward Interpolation
                    break;

            default:
                cout<<"Invalid Input\n"<<endl;
                break;
        }
    }


    return 0;
}
