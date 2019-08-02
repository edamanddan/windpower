/*Programa que calcula las frecuencias en las velocidades de viento para el analisis Weibull, para diferentes Z (9,15,20,25 [m], lee los datos de la matriz final 2019, y los almacena en matriz para exportar a texto*/

#include "iostream"
#include "fstream"
#include "string"
#include "iomanip"
#include "cmath"

using namespace std;
float counter(float v[],int, int);
int coin(int C[],int,int);

int main()
{
float data [5][28561];
int x,y;

ifstream in ("matrix2019.txt");

if (!in){
    cout<<"Not open file. \n";
    return 0;
    }

    for (y=0; y<28561;y++)
    {
        for (x=0;x<5;x++)
        {
            in>>data[x][y];
            
        }
    }
  
    in.close();

float v[28561];

for(x=0;x<28561;x++)
{
    v[x]=data[2][x];
}

float Zo=1.5, Zr=9, Z15=15, Z20=20, Z25=25, v15[28624], v20[28624], v25[28624];

    for(x=0;x<28561;x++)
    {
        v15[x]=v[x]*((log(Z15/Zo))/(log(Zr/Zo)));
        v20[x]=v[x]*((log(Z20/Zo))/(log(Zr/Zo)));
        v25[x]=v[x]*((log(Z25/Zo))/(log(Zr/Zo)));
    }

    
int r=0,C[30],C1[30],C2[30],C3[30];
    
for(x=0;x<30;x++)
{
    C[x]=counter(v,x,r);
    C1[x]=counter(v15,x,r);
    C2[x]=counter(v20,x,r);
    C3[x]=counter(v25,x,r);
}

int freq[coin(C,x,r)],freq1[coin(C1,x,r)],freq2[coin(C2,x,r)],freq3[coin(C3,x,r)];

for(x=0;x<coin(C,x,r);x++)
{
    freq[x]=C[x];
    cout<<x+1<<"\t"<<freq[x]<<endl;
}

cout<<endl;

for(x=0;x<coin(C1,x,r);x++)
{
    freq1[x]=C1[x];
    cout<<x+1<<"\t"<<freq1[x]<<endl;
}

cout<<endl;

for(x=0;x<coin(C2,x,r);x++)
{
    freq2[x]=C2[x];
    cout<<x+1<<"\t"<<freq2[x]<<endl;
}

cout<<endl;

for(x=0;x<coin(C3,x,r);x++)
{
    freq3[x]=C3[x];
    cout<<x+1<<"\t"<<freq3[x]<<endl;
}

cout<<endl;

int sum1=0,sum2=0,sum3=0,sum4=0;

for(x=0;x<coin(C,x,r);x++)
{
    sum1=freq[x]+sum1;
}
for(x=0;x<coin(C1,x,r);x++)
{
    sum2=freq1[x]+sum2;
}
for(x=0;x<coin(C2,x,r);x++)
{
    sum3=freq2[x]+sum3;
}
for(x=0;x<coin(C3,x,r);x++)
{
    sum4=freq3[x]+sum4;
}
cout<<sum1<<" "<<sum2<<" "<<sum3<<" "<<sum4<<endl;

}


float counter(float v[], int i,int c)
{
    
    for(int x=0; x<28561;x++)
    {
        if(v[x]>=i&&v[x]<i+1)
        {
            c=c+1;
        }
    }
    return c;
}

int coin(int C[],int i,int c)
{
    for(int x=0;x<30;x++)
    {
        if(C[x]!=0)
        {
            c=c+1;
        }
    }
    return c;
}




