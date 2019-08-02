//Lee los datos de la matriz principal
//Calcula los parámetros necesarios para determinar densidad de aire húmedo mediante método de temperatura virtual
#include "iostream"
#include "fstream"
#include "string"
#include "iomanip"
#include "cmath"
using namespace std;

double inten(double v[], double w[], int , double );
double EintenI(double v[],double w[], double z[],int , double );
double EintenH(double v[], double w[], double z[],int , double );
double suma(double j[], int , double );



int main()
{
int lv=28561;   
double data[8][lv], v9[lv], v15[lv], v20[lv], v25[lv], rhoI[lv], rhoH[lv], erhoI[lv], erhoH[lv];

int x,y;
ifstream in ("resul.txt");

if (!in){
    cout<<"Not open file. \n";
    return 0;
    }

    for (y=0; y<lv;y++)
    {
        for (x=0;x<8;x++)
        {
            in>>data[x][y];
        }
    }

in.close();


for(x=0;x<lv;x++)
{
    v9[x]=data[0][x];
    v15[x]=data[1][x];
    v20[x]=data[2][x];
    v25[x]=data[3][x];
    rhoI[x]=data[4][x];
    rhoH[x]=data[5][x];
    erhoI[x]=data[6][x];
    erhoH[x]=data[7][x];
    
    //cout<<v9[x]<<"\t"<<v15[x]<<"\t"<<v20[x]<<"\t"<<v25[x]<<"\t"<<rhoI[x]<<"\t"<<rhoH[x]<<"\t"<<erhoI[x]<<"\t"<<erhoH[x]<<endl;
}


double Ii9[lv], Ih9[lv], Ii15[lv], Ih15[lv], Ii20[lv], Ih20[lv], Ii25[lv], Ih25[lv];
for(x=0;x<lv;x++)
{
    Ii9[x]=inten(v9,rhoI,x,0);
    Ih9[x]=inten(v9,rhoH,x,0);
    Ii15[x]=inten(v15,rhoI,x,0);
    Ih15[x]=inten(v15,rhoH,x,0);
    Ii20[x]=inten(v20,rhoI,x,0);
    Ih20[x]=inten(v20,rhoH,x,0);
    Ii25[x]=inten(v25,rhoI,x,0);
    Ih25[x]=inten(v25,rhoH,x,0);

}


double eIi9[lv], eIh9[lv], eIi15[lv], eIh15[lv], eIi20[lv], eIh20[lv], eIi25[lv], eIh25[lv];
for(x=0;x<lv;x++)
{
    eIi9[x]=EintenI(v9,erhoI,rhoI,x,0);
    eIh9[x]=EintenH(v9,erhoH,rhoH,x,0);
    eIi15[x]=EintenI(v15,erhoI,rhoI,x,0);
    eIh15[x]=EintenH(v15,erhoH,rhoH,x,0);
    eIi20[x]=EintenI(v20,erhoI,rhoI,x,0);
    eIh20[x]=EintenH(v20,erhoH,rhoH,x,0);
    eIi25[x]=EintenI(v25,erhoI,rhoI,x,0);
    eIh25[x]=EintenH(v25,erhoH,rhoH,x,0);
    
}

  cout<<fixed<<setprecision(5)<<v9[0]<<"\t"<<rhoI[0]<<"\t"<<Ii9[0]<<"\t"<<eIi9[0]<<endl;


cout<<endl;

for(x=0;x<lv;x++)
{
    //cout<<v9[x]<<"\t"<<rhoH[x]<<"\t"<<Ih9[x]<<"\t"<<eIh9[x]<<endl;
}

cout<<endl;

for(x=0;x<lv;x++)
{
    //cout<<v15[x]<<"\t"<<rhoI[x]<<"\t"<<Ii15[x]<<"\t"<<eIi15[x]<<endl;
}

cout<<endl;

for(x=0;x<lv;x++)
{
    //cout<<v15[x]<<"\t"<<rhoH[x]<<"\t"<<Ih15[x]<<"\t"<<eIh15[x]<<endl;
}

cout<<endl;

for(x=0;x<lv;x++)
{
    //cout<<v20[x]<<"\t"<<rhoI[x]<<"\t"<<Ii20[x]<<"\t"<<eIi20[x]<<endl;
}

cout<<endl;

for(x=0;x<lv;x++)
{
    //cout<<v20[x]<<"\t"<<rhoH[x]<<"\t"<<Ih20[x]<<"\t"<<eIh20[x]<<endl;
}

cout<<endl;

for(x=0;x<lv;x++)
{
    //cout<<v25[x]<<"\t"<<rhoI[x]<<"\t"<<Ii25[x]<<"\t"<<eIi25[x]<<endl;
}

cout<<endl;

for(x=0;x<lv;x++)
{
   // cout<<v25[x]<<"\t"<<rhoH[x]<<"\t"<<Ih25[x]<<"\t"<<eIh25[x]<<endl;
}

cout<<endl;




double mv9, mv15, mv20, mv25, mrhoi, mrhoh, emrhoI, emrhoH, emIi9, emIh9, emIi15, emIh15,emIi20, emIh20,emIi25, emIh25, mIi9, mIh9, mIi15, mIh15,mIi20, mIh20,mIi25, mIh25 ;

mv9=suma(v9,lv,0)/lv;
mv15=suma(v15,lv,0)/lv;
mv20=suma(v20,lv,0)/lv;
mv25=suma(v25,lv,0)/lv;
mrhoi=suma(rhoI,lv,0)/lv;
mrhoh=suma(rhoH,lv,0)/lv;
mIi9=suma(Ii9,lv,0)/lv;
mIh9=suma(Ih9,lv,0)/lv;
mIi15=suma(Ii15,lv,0)/lv;
mIh15=suma(Ih15,lv,0)/lv;
mIi20=suma(Ii20,lv,0)/lv;
mIh20=suma(Ih20,lv,0)/lv;
mIi25=suma(Ii25,lv,0)/lv;
mIh25=suma(Ih25,lv,0)/lv;
emrhoI=suma(erhoI,lv,0)/lv;
emrhoH=suma(erhoH,lv,0)/lv;
emIi9=suma(eIi9,lv,0)/lv;
emIh9=suma(eIh9,lv,0)/lv;
emIi15=suma(eIi15,lv,0)/lv;
emIh15=suma(eIh15,lv,0)/lv;
emIi20=suma(eIi20,lv,0)/lv;
emIh20=suma(eIh20,lv,0)/lv;
emIi25=suma(eIi25,lv,0)/lv;
emIh25=suma(eIh25,lv,0)/lv;




cout<<"Intensidad ideal 9  "<<mIi9<<endl;
cout<<"Intensidad humedo 9  "<<mIh9<<endl;
cout<<"Intensidad ideal 15  "<<mIi15<<endl;
cout<<"Intensidad humedo 15  "<<mIh15<<endl;
cout<<"Intensidad ideal 20  "<<mIi20<<endl;
cout<<"Intensidad humedo 20  "<<mIh20<<endl;
cout<<"Intensidad ideal 25  "<<mIi25<<endl;
cout<<"Intensidad humedo 25  "<<mIh25<<endl;

cout<<"Errores medios......"<<endl;
cout<<"error densidad ideal  "<<emrhoI<<endl;
cout<<"error densidad humedo  "<<emrhoH<<endl;
cout<<"error Intensidad ideal9  "<<emIi9<<endl;
cout<<"error Intensidad humedo9  "<<emIh9<<endl;
cout<<"error Intensidad ideal15  "<<emIi15<<endl;
cout<<"error Intensidad humedo15  "<<emIh15<<endl;
cout<<"error Intensidad ideal20  "<<emIi20<<endl;
cout<<"error Intensidad humedo20  "<<emIh20<<endl;
cout<<"error Intensidad ideal25  "<<emIi25<<endl;
cout<<"error Intensidad humedo25  "<<emIh25<<endl;

cout<<fixed<<setprecision(5)<<endl;

for(x=0;x<lv;x++)
{
cout<<v9[x]<<"\t"<<v15[x]<<"\t"<<v20[x]<<"\t"<<v25[x]<<"\t"<<rhoI[x]<<"\t"<<rhoH[x]<<"\t"<<Ii9[x]<<"\t"<<Ih9[x]<<"\t"<<Ii15[x]<<"\t"<<Ih15[x]<<"\t"<<Ii20[x]<<"\t"<<Ih20[x]<<"\t"<<Ii25[x]<<"\t"<<Ih25[x]<<endl;
}

}

double inten(double v[], double w[], int i, double a)
{
    a=0.5*w[i]*v[i]*v[i]*v[i];
    return a;
}


double EintenI(double v[],double w[], double z[],int j, double c)
{   double f=3/2;
    c=((0.5*v[j]*v[j]*v[j])*w[j]) + ((f*z[j]*v[j]*v[j])*0.1);
    return c;
}

double EintenH(double v[], double w[], double z[],int k, double d)
{
    double f=3/2;
    d=((0.5*v[k]*v[k]*v[k])*w[k]) + ((f*z[k]*v[k]*v[k])*0.1);
    return d;
}

double suma(double j[], int l, double e)
{
    for(int x=0; x<l; x++)
    {
        e=e+j[x];
    }
    return e;
}



