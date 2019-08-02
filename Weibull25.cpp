//Programa calcula los parametros Weibull de un archivo txt (V - F[V]) para 15m
#include "iostream"
#include "fstream"
#include "string"
#include "iomanip"
#include "cmath"
using namespace std;
double logu(double v[],int,double);
double sum(double v[],int,double);
double x2(double v[],int , double);
double xiyi(double v[],double t[], int, double);

int main()
{
int x,y;
int lv=25;
double dat=28561;
double data[2][lv],freq[lv],FA[lv],c=0,num[lv],FU[lv],Noln[lv],Y[lv-1],X[lv-1],sumY,sumX,sumXiYi,xi2[lv-1],yi2[lv-1],XiYi[lv-1],sumXi2,sumYi2;
double A, B, r, Delta, k, C,subDelta;

ifstream in ("V-F-25.txt");

if (!in){
    cout<<"Not open file. \n";
    return 0;
    }

    for (y=0; y<lv;y++)
    {
        for (x=0;x<2;x++)
        {
            in>>data[x][y];
        }
        
    }
    
    in.close();

for(x=0;x<lv;x++)
{
    num[x]=x+1;
    freq[x]=data[1][x];
    cout<<num[x]<<"  "<<freq[x]<<endl;
}
for(x=0;x<lv;x++)
{
    c=c+(freq[x]/dat);
    FA[x]=c;
    FU[x]=1-FA[x];

}

for(x=0;x<lv;x++)
{
    Noln[x]=(-1)*logu(FU,x,0);
}

for(x=0;x<lv-1;x++)
{
    Y[x]=logu(Noln,x,0);

}

for(x=0;x<lv-1;x++)
{
    X[x]=logu(num,x,0);
}



for(x=0;x<lv-1;x++)
{
    xi2[x]=x2(X,x,0);
    yi2[x]=x2(Y,x,0);
    XiYi[x]=xiyi(X,Y,x,0);
    cout<<fixed<<setprecision(7)<<X[x]<<"\t"<<Y[x]<<"\t"<<xi2[x]<<"\t"<<yi2[x]<<"\t"<<XiYi[x]<<endl;

}

sumY=sum(Y,lv,0);
sumX=sum(X,lv,0);
sumXi2=sum(xi2,lv,0);
sumYi2=sum(yi2,lv,0);
sumXiYi=sum(XiYi,lv,0);

cout<<sumX<<"\t"<<sumY<<"\t"<<sumXi2<<"\t"<<sumYi2<<"\t"<<sumXiYi<<endl;

//REGRESION LINEAL, CALCULANDO A y B, r & k,C
int n=lv-1;

Delta=(n*sumXi2)-(sumX*sumX);
subDelta=(n*sumYi2)-(sumY*sumY);
A=((sumY*sumXi2)-(sumXiYi*sumX))/Delta;
B=((n*sumXiYi)-(sumX*sumY))/Delta;
r=((n*sumXiYi)-(sumX*sumY))/sqrt((Delta*subDelta));

k=B;
C=exp(-A/k);


cout<<"Resultados:......."<<endl;
cout<<"Factor forma k:   "<<"\t"<<k<<endl;
cout<<"Factor escala C:   "<<"\t"<<C<<endl;
cout<<"Correlacion:   "<<"\t"<<r<<endl;
    

    
    
}

double logu(double v[],int i, double c)
{
     c=log(v[i]);
    return c;
}

double sum(double v[],int i, double c)
{
    for(int x=0;x<i-1;x++)
    {
        c=c+v[x];
    }
    return c;
}

double x2(double v[],int i, double c)
{
    c=v[i]*v[i];
    return c;
}

double xiyi(double v[],double t[], int i, double c)
{
    c=v[i]*t[i];
    return c;
}

