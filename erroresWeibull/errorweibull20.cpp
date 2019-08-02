//Programa lee datos de un archivo .txt y almacena en matriz
//Almacena cada columna en un vector
//Calcula discrepancias y evalua funcion weibull
#include "iostream"
#include "fstream"
#include "string"
#include "iomanip"
#include "cmath"
using namespace std;

int main()
{

    float data [2][22], freq[22],acum[22],weibull[22],dis[22], k=1.2063973 C=3.9509125;
     
    int x,y; 
    
ifstream in ("V-F(U)20.txt");

if (!in){
    cout<<"Not open file. \n";
    return 0;
    }

    for (y=0; y<22;y++)
    {
        for (x=0;x<2;x++)
        {
            in>>data[x][y];
        }
    }

    
 in.close();
     
    for(x=0;x<22;x++)
    {
        freq[x]=data[1][x];
    }
    
    for(x=0;x<22;x++)
    {
        acum[x]=freq[x]/28624;
    }
    
    for(x=0;x<22;x++)
    {
        weibull[x]=(k/C)*(pow((x/C),(k-1)))*exp(-pow((x/C),k));
    }
    
    for(x=0;x<22;x++)
    {
        dis[x]=weibull[x]-acum[x];
    }
    for(x=0;x<22;x++)
    {
        cout<<x+1<<"\t"<<freq[x]<<"\t"<<acum[x]<<"\t"<<weibull[x]<<"\t"<<dis[x]<<endl;
    }

}
