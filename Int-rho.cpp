//Lee los datos de la matriz principal
//Calcula los parámetros necesarios para determinar densidad de aire húmedo mediante método de temperatura virtual
#include "iostream"
#include "fstream"
#include "string"
#include "iomanip"
#include "cmath"
using namespace std;


int main()

{
int lv=28561;   
double data[8][lv], v9[lv], rhoI[lv], rhoH[lv], iRhoI[lv], iRhoH[lv], lnv[lv];

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
    rhoI[x]=data[4][x];
    rhoH[x]=data[5][x];

    //cout<<v9[x]<<"\t"<<v15[x]<<"\t"<<v20[x]<<"\t"<<v25[x]<<"\t"<<rhoI[x]<<"\t"<<rhoH[x]<<"\t"<<erhoI[x]<<"\t"<<erhoH[x]<<endl;
}

//inversas de densidad

for(x=0;x<lv;x++)
{
    iRhoI[x]=log(1/rhoI[x]);
    iRhoH[x]=log(1/rhoH[x]);
    lnv[x]=log(v9[x]);
}


for(x=0;x<lv;x++)
{
    //cout<<fixed<<setprecision(5)<<iRhoI[x]<<"\t"<<iRhoH[x]<<"\t"<<lnv[x]<<endl;
    //cout<<iRhoI[8600+x]<<"     "<<rhoI[8600+x]<<endl;
    cout<<fixed<<setprecision(5)<<rhoI[x]<<"\t"<<rhoH[x]<<"\t"<<v9[x]<<endl;
}

    
}
