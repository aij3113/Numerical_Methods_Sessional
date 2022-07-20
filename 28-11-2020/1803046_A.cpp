//  This code fits a curve
//  of form y = (a/x)+bx
//  using the method of least squares

#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

double xy[51][4];
double XY[51][9]={0};
double a,b;
int n;
string buffer;
vector<string>temp;

void input(){
    ifstream f1;
    f1.open("Least_Squares.txt");

    while(!f1.eof()){
        f1>>buffer;
        temp.push_back(buffer);
        buffer.clear();
    }

    for(int i=0,j=0;i<temp.size();i+=2,j++){
        xy[j][0]=stod(temp.at(i));
        XY[j][0]=xy[j][0]*xy[j][0];
        xy[j][1]=stod(temp.at(i+1));
        XY[j][1]=xy[j][0]*xy[j][1];
        n=j+1;
    }
}

void show_xy(){
    cout<<"\n\tx   y"<<endl;

    for(int i=0;i<n;i++){
        cout<<"\t"<<xy[i][0]<<"  "<<xy[i][1]<<endl;
    }
}

void brief(){
    cout<<"\tHere The Original Equation is: y = (a/x) + bx"<<endl;
    cout<<"\n\tThe equation can be written as Y = a + bX"<<endl;
    cout<<"\t\twhere Y = x*y  and X = x*x"<<endl;
}

void show_XY(){
    cout<<"\tAfter converting into the equivalent equation we get -"<<endl;
    cout<<"\n\tX\tY\tX*X\tXY"<<endl;
    for(int i=0;i<n;i++){
        XY[i][2]=XY[i][0]*XY[i][0];
        XY[i][3]=XY[i][0]*XY[i][1];
        cout<<"\t"<<XY[i][0]<<"\t"<<XY[i][1]<<"\t"<<XY[i][2]<<"\t"<<XY[i][3]<<endl;
        for(int j=0;j<4;j++){
            XY[n][j]+=XY[i][j];
        }
    }
    cout<<"  -------------------------------------------"<<endl;
    cout<<"  SUM : ";
    for(int i=0;i<4;i++){
        cout<<XY[n][i]<<"\t";
    }
    cout<<endl;
    cout<<"\n\t And we get the following two equations : "<<endl;
    cout<<"\n\t(i) "<<n<<"a + "<<XY[n][0]<<"b = "<<XY[n][1]<<endl;
    cout<<"\t(ii) "<<XY[n][0]<<"a + "<<XY[n][2]<<"b = "<<XY[n][3]<<endl;
}

void solve(){
    b=((n*XY[n][3])-(XY[n][0]*XY[n][1]))/((n*XY[n][2])-(XY[n][0]*XY[n][0]));
    a=(XY[n][1]-(b*XY[n][0]))/n;

    cout<<"\n\tSolving (i) & (ii) we get - "<<endl;
    cout<<"\n\t\t a = "<<a<<"\n\t\t b = "<<b<<endl;

    cout<<"\n\n\tSo the Fitted Equivalent Equation is: Y = "<<a<<" + "<<b<<"X\n"<<endl;
    cout<<"\tand the Fitted Original Equation is: y = ("<<a<<"/x) + "<<b<<"x\n"<<endl;

}

int main(){
    fast;
    input();
    show_xy();
    brief();
    show_XY();
    solve();


    return 0;
}
