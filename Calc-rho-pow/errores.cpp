//Programa lee datos de un archivo .txt y almacena en matriz
//Almacena cada columna en un vector
//De acuerdo a índices podrá generar promedios móviles
#include "iostream"
#include "fstream"
#include "string"
#include "iomanip"
#include "cmath"
using namespace std;

int main()
{
float data [14][28624], hum[28624], temp[28624], vel[28624], pres[28624], egi[28624], T[28624], vartheta[28624], Es[28624], evartheta[28624];
float eEst[28624], ePv[28624], ePd[28624], Pv[28624], Pd[28624], erho[28624], gi[28624], eIi[28624], rhoH[28624], eIh[28624];
float eso=6.1078, errorv=0.1, errorh=2, errort=0.5, errorp=0.12;
float c0=0.99999683,c1=-0.90826951e-2,c2=0.78736169e-4,c3=-0.61117958e-6,c4=0.43884187e-8;
float c5=-0.29883885e-10,c6=0.21874425e-12,c7=-0.17892321e-14,c8=0.11112018e-16,c9=-0.30994571e-19;
float R=287.058, Rd=287.05, Rv=461.495;
int x,y;

ifstream in ("resss.txt");

if (!in){
    cout<<"Not open file. \n";
    return 0;
    }

    for (y=0; y<28624;y++)
    {
        for (x=0;x<14;x++)
        {
            in>>data[x][y];
        }
    }
    
 in.close();
 
    for(x=0;x<28624;x++)
    {
        hum[x]=data[0][x];
        temp[x]=data[1][x];
        vel[x]=data[2][x];
        pres[x]=data[4][x];
             
    }
    //centigrados a kelvin
    for(x=0;x<28624;x++)
    {
        T[x]=temp[x]+273.15;
    }
    
    //para el gas ideal:
    for(x=0;x<28624;x++)
    {
        egi[x]= ((1/(R*T[x]))*errorp) + ((pres[x]*100)/((R*T[x]*T[x])))*errort;    //error gas ideal instantaneo
    }
    
    //para gas humedo:
    

    
    //calcular vartheta
    for(x=0;x<28624;x++)
    {
        vartheta[x]=c0+T[x]*c1+(pow(T[x],2))*c2+(pow(T[x],3))*c3+(pow(T[x],4))*c4+(pow(T[x],5))*c5+(pow(T[x],6))*c6+(pow(T[x],7))*c7+(pow(T[x],8))*c8+(pow(T[x],9))*c9;
        
    }    
    
    //calcular Es
    for(x=0;x<28624;x++)
    {
        Es[x]=eso/(pow(vartheta[x],8));
        
    }    
    
    //error de vartheta
    for(x=0;x<28624;x++)
    {
        evartheta[x]=(c1+2*T[x]*c2+3*(pow(T[x],2))*c3+4*(pow(T[x],3))*c4+5*(pow(T[x],4))*c5+6*(pow(T[x],5))*c6+7*(pow(T[x],6))*c7+8*(pow(T[x],7))*c8+9*(pow(T[x],8))*c9)*errort;
    }
    
    //error de Es(T)
    for(x=0;x<28624;x++)
    {
        eEst[x]=((8*eso)/(pow(vartheta[x],9)))*evartheta[x];
    }
    

    //error de Pv
    for(x=0;x<28624;x++)
    {
        ePv[x]=Es[x]*errorh + hum[x]*eEst[x];
    }    
    
    //error de Pd
    for(x=0;x<28624;x++)
    {
        ePd[x]=errorp+ePv[x]; 
        
    } 
    
    //calcular Pv
    for(x=0;x<28624;x++)
    {
        Pv[x]=hum[x]*Es[x]; 
        
    }     
    
    //calcular Pd
    for(x=0;x<28624;x++)
    {
        Pd[x]=(pres[x]*100)-Pv[x]; 
    }     
       
    
    //error RHO
    for(x=0;x<28624;x++)
    {
       erho[x]=(((Pd[x]/(Rd*(pow(T[x],2)))) - (Pv[x]/(Rv*(pow(T[x],2)))) )*errort) + (1/(Rd*T[x]))*ePd[x] + (1/(Rv*T[x]))*ePv[x]; 
        
    }    
       
       
    //calcular densidad gas ideal
    for(x=0;x<28624;x++)
    {
            gi[x]=(pres[x]*100)/(R*T[x]);
    }
    
    
    //error intensidad gas ideal
    for(x=0;x<28624;x++)
    {
        eIi[x]=((0.5*(pow(vel[x],3)))*egi[x]) + (3/2*gi[x]*vel[x]*vel[x])*errorv;
    }
    
    
    //Calcular densidad gas humedo
    for(x=0;x<28624;x++)
    {
        rhoH[x]=(Pd[x]/(Rd*T[x])) + (Pv[x]/(Rv*T[x]));
    }    
    
    
    
    //error intensidad gas humedo
    
    for(x=0;x<28624;x++)
    {
        eIh[x]=((0.5*(pow(vel[x],3)))*erho[x]) + (3/2*rhoH[x]*vel[x]*vel[x])*errorv;
    }
    
    cout<<"eGasI\tevarth\teEst\tePv\tePd\terho\teIi\teIh"<<endl;
    
    for(x=0;x<28624;x++)
    {
       // cout<<egi[x]<<"\t"<<evartheta[x]<<"\t"<<eEst[x]<<"\t"<<ePv[x]<<"\t"<<ePd[x]<<"\t"<<erho[x]<<"\t"<<eIi[x]<<"\t"<<eIh[x]<<endl;
    }
    
    //Calcular promedios de errores:
    float p1=0,p2=0,p3=0,p4=0,p5=0,p6=0,p7=0,p8=0;
    float pr1,pr2,pr3,pr4,pr5,pr6,pr7,pr8;
    
    for(x=0;x<28624;x++)
    {
        p1=p1+egi[x];
        p2=p2+evartheta[x];
        p3=p3+eEst[x];
        p4=p4+ePv[x];
        p5=p5+ePd[x];
        p6=p6+erho[x];
        p7=p7+eIi[x];
        p8=p8+eIh[x];
    }
    
    pr1=p1/28624;
    pr2=p2/28624;
    pr3=p3/28624;
    pr4=p4/28624;
    pr5=p5/28624;
    pr6=p6/28624;
    pr7=p7/28624;
    pr8=p8/28624;
    
    cout<<pr1<<endl;
    cout<<pr2<<endl;
    cout<<pr3<<endl;
    cout<<pr4<<endl;
    cout<<pr5<<endl;
    cout<<pr6<<endl;
    cout<<pr7<<endl;
    cout<<pr8<<endl;
    
    
}
