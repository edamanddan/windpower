//Lee los datos de la matriz principal
//Calcula los parámetros necesarios para determinar densidad de aire húmedo mediante método de temperatura virtual
#include "iostream"
#include "fstream"
#include "string"
#include "iomanip"
#include "cmath"
using namespace std;
double suma(double O[],int , double );
double intenI(double Q[], double t[], double r[], int , double );
double intenH(double P[], double W[], double M[], int , double );







int main()
{
int lv=28561;    
double data [5][28561];
double HR[28561], P[28561], TK[28561], TC[28561], e[28561], es[28561], w[28561], q[28561], Tv[28561], rhoi[28561], rhoh[28561],v[28561];
double Ii[28561], Ih[28561], Ii15[28561], Ih15[28561], Ii20[28561], Ih20[28561], Ii25[28561], Ih25[28561];
double Rv=461.52, Rd=287.053; 

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

    
    for(x=0;x<28561;x++)
    {
        HR[x]=data[0][x]/100;
        P[x]=data[3][x]*100;        
        TC[x]=data[1][x];
    }
    for(x=0;x<28561;x++)
    {
        TK[x]=TC[x]+273.15;
        v[x]=data[2][x];
    }
 
 
 //CALCULAR DENSIDADES GAS IDEAL:
 
for(x=0;x<28561;x++)
{
    rhoi[x]=P[x]/(Rd*TK[x]);
    //cout<<rhoi[x]<<endl;
}

double s=0, pRhoi;
for(x=0;x<28561;x++)
{
    s=s+rhoi[x];
}

pRhoi=s/28561;

//CALCULAR DENSIDAD GAS HUMEDO METODO DE TEmperatura Virtual

//calcular es

for(x=0;x<28561;x++)
{
    es[x]=611.2*exp(((17.67*TC[x])/(TC[x]+243.5)));
}

for(x=0;x<28561;x++)
{
    e[x]=HR[x]*es[x];
}

for(x=0;x<28561;x++)
{
    w[x]=(e[x]*Rd)/(Rv*(P[x]-e[x]));
}

for(x=0;x<28561;x++)
{
    q[x]=w[x]/(w[x]+1);
}

for(x=0;x<28561;x++)
{
    Tv[x]=(1+(((Rv/Rd)-1)*q[x]))*TK[x];
}

for(x=0;x<28561;x++)
{
    rhoh[x]=P[x]/(Rd*Tv[x]);
}

double ss=0, pRhoh;
for(x=0;x<28561;x++)
{
    ss=ss+rhoh[x];
}

pRhoh=ss/28561;

//cout<<pRhoi<<"   "<<pRhoh<<endl;

//EXTRAPOLACIÓN VELOCIDADES z15,z20,z25
double Zo=1.5, Zr=9, Z15=15, Z20=20, Z25=25, v15[lv], v20[lv], v25[lv];

    for(x=0;x<lv;x++)
    {
        v15[x]=v[x]*((log(Z15/Zo))/(log(Zr/Zo)));
        v20[x]=v[x]*((log(Z20/Zo))/(log(Zr/Zo)));
        v25[x]=v[x]*((log(Z25/Zo))/(log(Zr/Zo)));
        
    }
    
//CALCULANDO INTENSIDADES
for(x=0;x<28561;x++)
{
    Ii[x]=0.5*rhoi[x]*v[x]*v[x]*v[x];
    Ih[x]=0.5*rhoh[x]*v[x]*v[x]*v[x];
    Ii15[x]=0.5*rhoi[x]*v15[x]*v15[x]*v15[x];
    Ih15[x]=0.5*rhoh[x]*v15[x]*v15[x]*v15[x];
    Ii20[x]=0.5*rhoi[x]*v20[x]*v20[x]*v20[x];
    Ih20[x]=0.5*rhoh[x]*v20[x]*v20[x]*v20[x];
    Ii25[x]=0.5*rhoi[x]*v25[x]*v25[x]*v25[x];
    Ih25[x]=0.5*rhoh[x]*v25[x]*v25[x]*v25[x];
    
}

//CALCULANDO INTENSIDADES MEDIAS

double mIi,mIh,mIi15,mIh15,mIi20,mIh20,mIi25,mIh25;

mIi=suma(Ii,28561,0)/28561;
mIh=suma(Ih,28561,0)/28561;
mIi15=suma(Ii15,28561,0)/28561;
mIh15=suma(Ih15,28561,0)/28561;
mIi20=suma(Ii20,28561,0)/28561;
mIh20=suma(Ih20,28561,0)/28561;
mIi25=suma(Ii25,28561,0)/28561;
mIh25=suma(Ih25,28561,0)/28561;

    //cout<<"Promedio intensidad gas ideal"<<"   "<<mIi<<endl;
  //  cout<<"Promedio intensidad gas humedo"<<"   "<<mIh<<endl;
    //cout<<"Promedio intensidad gas ideal15"<<"   "<<mIi15<<endl;
   // cout<<"Promedio intensidad gas humedo15"<<"   "<<mIh15<<endl;
   // cout<<"Promedio intensidad gas ideal20"<<"   "<<mIi20<<endl;
  //  cout<<"Promedio intensidad gas humedo20"<<"   "<<mIh20<<endl;
  //  cout<<"Promedio intensidad gas ideal25"<<"   "<<mIi25<<endl;
  //  cout<<"Promedio intensidad gas humedo25"<<"   "<<mIh25<<endl;


//CALCULO ERRORES
    

double Des[lv], dTC=0.5, De[lv],dHR=0.02, Dw[lv], dP=12, epsi=Rv/Rd, Dq[lv], DTv[lv], dTK=0.5, dv=0.1, drhoH[lv], drhoI[lv];

for(x=0;x<lv;x++)
{
 Des[x]=(611.2*exp((17.67*TC[x])/(TC[x]+243.5))*((17.67/(TC[x]+243.5))-((17.67*TC[x])/((TC[x]+243.5)*(TC[x]+243.5)))))*dTC;
}
//Error e
for(x=0;x<lv;x++)
{
    De[x]=(es[x]*dHR)+(HR[x]*Des[x]);
}

//error w
for(x=0;x<lv;x++)
{
    Dw[x]= (((1/epsi)*((1/(P[x]-e[x]))+(e[x]/((P[x]-e[x])*(P[x]-e[x])))))*De[x])+(((-1/epsi)*(e[x]/((P[x]-e[x])*(P[x]-e[x]))))*dP);
}

//error q
for(x=0;x<lv;x++)
{
    Dq[x]= ((1/(w[x]+1)) - (w[x]/((w[x]+1)*(w[x]+1))))*Dw[x];
}

//error Tv
for(x=0;x<lv;x++)
{
    DTv[x]= (((epsi*TK[x])-TK[x])*Dq[x])+((1+(q[x]*epsi)-q[x])*dTK);
}

//Error densidad gas humedo
for(x=0;x<lv;x++)
{
    drhoH[x]= ((1/(Rd*Tv[x]))*dP) + ((P[x]/(Rd*Tv[x]*Tv[x]))*DTv[x]);
}

//Error densidad gas ideal
for(x=0;x<lv;x++)
{
    drhoI[x]=((1/(Rd*TK[x]))*dP) + ((P[x]/(Rd*TK[x]*TK[x]))*dTK);
}

//MATRIZ DE RESULTADOS:
for(x=0;x<lv;x++)
{
    cout<<v[x]<<"\t"<<v15[x]<<"\t"<<v20[x]<<"\t"<<v25[x]<<"\t"<<rhoi[x]<<"\t"<<rhoh[x]<<"\t"<<drhoI[x]<<"\t"<<drhoH[x]<<endl;
}



}
double suma(double O[],int i, double c)
{
    for(int x=0;x<i;x++)
    {
        c=c+O[x];
    }
    return c;
}

double intenI(double Q[], double t[], double r[], int i, double c)
{
    c=(0.5*pow(Q[i],3))*t[i] + ((3/2)*r[i]*pow(Q[i],2))*0.1;
    return c;
}

double intenH(double P[], double W[], double M[], int i, double c)
{
    c=(0.5*pow(P[i],3))*W[i] + ((3/2)*M[i]*pow(P[i],2))*0.1;
    return c;
}

    
