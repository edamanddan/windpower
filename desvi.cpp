//Lee los datos de la matriz principal
//Calcula los parámetros necesarios para determinar densidad de aire húmedo mediante método de temperatura virtual
#include "iostream"
#include "fstream"
#include "string"
#include "iomanip"
#include "cmath"
using namespace std;
float suma(float v[],int , float );


int main()
{
int lv=28561;   
float data[14][lv], v9[lv], v15[lv], v20[lv], v25[lv], rhoI[lv], rhoH[lv], Ii9[lv], Ih9[lv], Ii15[lv], Ih15[lv], Ii20[lv], Ih20[lv], Ii25[lv], Ih25[lv];

int x,y;
ifstream in ("VAL.txt");

if (!in){
    cout<<"Not open file. \n";
    return 0;
    }

    for (y=0; y<lv;y++)
    {
        for (x=0;x<14;x++)
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
    Ii9[x]=data[6][x];
    Ih9[x]=data[7][x];
    Ii15[x]=data[8][x];
    Ih15[x]=data[9][x];
    Ii20[x]=data[10][x];
    Ih20[x]=data[11][x];
    Ii25[x]=data[12][x];
    Ih25[x]=data[13][x];
}

float mv9, mv15,mv20,mv25,mrhoi,mrhoh,mIi9,mIh9,mIi15,mIh15,mIi20,mIh20,mIi25,mIh25;

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

cout<<fixed<<setprecision(5);
cout<<mv9<<endl;
cout<<mv15<<endl;
cout<<mv20<<endl;
cout<<mv25<<endl;
cout<<mrhoi<<endl;
cout<<mrhoh<<endl;
cout<<mIi9<<endl;
cout<<mIh9<<endl;
cout<<mIi15<<endl;
cout<<mIh15<<endl;
cout<<mIi20<<endl;
cout<<mIh20<<endl;
cout<<mIi25<<endl;
cout<<mIh25<<endl;

float C1[lv],C2[lv],C3[lv],C4[lv],C5[lv],C6[lv],C7[lv],C8[lv],C9[lv],C10[lv],C11[lv],C12[lv],C13[lv],C14[lv];
float S1,S2,S3,S4,S5,S6,S7,S8,S9,S10,S11,S12,S13,S14;

for(x=0;x<lv;x++)
{
    C1[x]=(v9[x]-mv9)*(v9[x]-mv9);
    C2[x]=(v15[x]-mv15)*(v15[x]-mv15);
    C3[x]=(v20[x]-mv20)*(v20[x]-mv20);
    C4[x]=(v25[x]-mv25)*(v25[x]-mv25);
    C5[x]=(rhoI[x]-mrhoi)*(rhoI[x]-mrhoi);
    C6[x]=(rhoH[x]-mrhoh)*(rhoH[x]-mrhoh);
    C7[x]=(Ii9[x]-mIi9)*(Ii9[x]-mIi9);
    C8[x]=(Ih9[x]-mIh9)*(Ih9[x]-mIh9);
    C9[x]=(Ii15[x]-mIi15)*(Ii15[x]-mIi15);
    C10[x]=(Ih15[x]-mIh15)*(Ih15[x]-mIh15);
    C11[x]=(Ii20[x]-mIi20)*(Ii20[x]-mIi20);
    C12[x]=(Ih20[x]-mIh20)*(Ih20[x]-mIh20);
    C13[x]=(Ii25[x]-mIi25)*(Ii25[x]-mIi25);
    C14[x]=(Ih25[x]-mIh25)*(Ih25[x]-mIh25);
}

S1=sqrt(suma(C1,lv,0)/lv);
S2=sqrt(suma(C2,lv,0)/lv);
S3=sqrt(suma(C3,lv,0)/lv);
S4=sqrt(suma(C4,lv,0)/lv);
S5=sqrt(suma(C5,lv,0)/lv);
S6=sqrt(suma(C6,lv,0)/lv);
S7=sqrt(suma(C7,lv,0)/lv);
S8=sqrt(suma(C8,lv,0)/lv);
S9=sqrt(suma(C9,lv,0)/lv);
S10=sqrt(suma(C10,lv,0)/lv);
S11=sqrt(suma(C11,lv,0)/lv);
S12=sqrt(suma(C12,lv,0)/lv);
S13=sqrt(suma(C13,lv,0)/lv);
S14=sqrt(suma(C14,lv,0)/lv);


float E1,E2,E3,E4,E5,E6,E7,E8,E9,E10,E11,E12,E13,E14;
E1=S1/sqrt(lv);
E2=S2/sqrt(lv);
E3=S3/sqrt(lv);
E4=S4/sqrt(lv);
E5=S5/sqrt(lv);
E6=S6/sqrt(lv);
E7=S7/sqrt(lv);
E8=S8/sqrt(lv);
E9=S9/sqrt(lv);
E10=S10/sqrt(lv);
E11=S11/sqrt(lv);
E12=S12/sqrt(lv);
E13=S13/sqrt(lv);
E14=S14/sqrt(lv);


cout<<"DESVIACIONES ESTÁNDAR....."<<endl;
cout<<S1<<endl;
cout<<S2<<endl;
cout<<S3<<endl;
cout<<S4<<endl;
cout<<S5<<endl;
cout<<S6<<endl;
cout<<S7<<endl;
cout<<S8<<endl;
cout<<S9<<endl;
cout<<S10<<endl;
cout<<S11<<endl;
cout<<S12<<endl;
cout<<S13<<endl;
cout<<S14<<endl;
cout<<endl;

cout<<"ERRORES MEDIOS ESTÁNDAR....."<<endl;

cout<<E1<<endl;
cout<<E2<<endl;
cout<<E3<<endl;
cout<<E4<<endl;
cout<<E5<<endl;
cout<<E6<<endl;
cout<<E7<<endl;
cout<<E8<<endl;
cout<<E9<<endl;
cout<<E10<<endl;
cout<<E11<<endl;
cout<<E12<<endl;
cout<<E13<<endl;
cout<<E14<<endl;
cout<<endl;

//ENERGÍA
float A=2.54, t=8760, Cp=0.593, ENi9, ENi15,ENi20,ENi25,ENh9,ENh15,ENh20,ENh25;
float EUi9, EUi15,EUi20,EUi25,EUh9, EUh15,EUh20,EUh25;

ENi9=mIi9*A*t/1000;
ENi15=mIi15*A*t/1000;
ENi20=mIi20*A*t/1000;
ENi25=mIi25*A*t/1000;
ENh9=mIh9*A*t/1000;
ENh15=mIh15*A*t/1000;
ENh20=mIh20*A*t/1000;
ENh25=mIh25*A*t/1000;
EUi9=mIi9*A*t*Cp/1000;
EUi15=mIi15*A*t*Cp/1000;
EUi20=mIi20*A*t*Cp/1000;
EUi25=mIi25*A*t*Cp/1000;
EUh9=mIh9*A*t*Cp/1000;
EUh15=mIh15*A*t*Cp/1000;
EUh20=mIh20*A*t*Cp/1000;
EUh25=mIh25*A*t*Cp/1000;


cout<<"ENERGÍA DISPONIBLE Y UTILIZABLE....."<<endl;
cout<<ENi9<<endl;
cout<<ENh9<<endl;
cout<<ENi15<<endl;
cout<<ENh15<<endl;
cout<<ENi20<<endl;
cout<<ENh20<<endl;
cout<<ENi25<<endl;
cout<<ENh25<<endl;
cout<<EUi9<<endl;
cout<<EUh9<<endl;
cout<<EUi15<<endl;
cout<<EUh15<<endl;
cout<<EUi20<<endl;
cout<<EUh20<<endl;
cout<<EUi25<<endl;
cout<<EUh25<<endl;





}

float suma(float v[],int i, float c)
{
    for(int x=0; x<i; x++)
    {
        c=c+v[x];
    }
    return c;
}
