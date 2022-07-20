//This code is the Implementation of the Example 6.9 ( S.S. Sastry )

#include<bits/stdc++.h>
using namespace std;

int n;
double x[101],y[101];
string buf;
vector<string>temp;
#define pi 3.1416

void input(){
    ifstream f1;
    f1.open("6.9_p.txt");

    while(! f1.eof()){
        f1>>buf;
        temp.push_back(buf);
        buf.clear();
    }

    for(int i=0,j=0;i<temp.size();i+=2,j++){
        x[j]=stod(temp.at(i));
        y[j]=stod(temp.at(i+1));
        n=j+1;
    }
}

void show(){
    for(int i=0;i<n;i++){
        cout<<"\t"<<x[i]<<"\t\t"<<y[i]<<endl;
    }
}

void double_y(){
    for(int i=0;i<n;i++){
        y[i]*=y[i];
    }
}

double simpson(){
    double h,res,val=0;

    h=x[1]-x[0];
    res=y[0]+y[n-1];

    for(int i=1;i<n-1;i++){
        if(i%2){
            res+=(4.0*y[i]);
        }
        else{
            res+=(2.0*y[i]);
        }
    }

    val=(h*res)/3.0;

    return val;
}

void volume(){
    input();
    cout<<"\n\t X\t\tY\n\t...................."<<endl;
    show();
    double_y();
    cout<<"\n\t X\t\tY*Y\n\t...................."<<endl;
    show();

    cout<<"\n\tThe Volume is: "<<pi*simpson()<<endl;
}


int main(){

    volume();

    return 0;
}
