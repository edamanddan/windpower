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

    float data [2][25], freq[25],acum[25],weibull[25],dis[25], k=1.1964566, C=4.2534485;
     
    int x,y; 
    
ifstream in ("V-F(U)25.txt");

if (!in){
    cout<<"Not open file. \n";
    return 0;
    }

    for (y=0; y<25;y++)
    {
        for (x=0;x<2;x++)
        {
            in>>data[x][y];
        }
    }

    
 in.close();
     
    for(x=0;x<25;x++)
    {
        freq[x]=data[1][x];
    }
    
    for(x=0;x<25;x++)
    {
        acum[x]=freq[x]/28624;
    }
    
    for(x=0;x<25;x++)
    {
        weibull[x]=(k/C)*(pow((x/C),(k-1)))*exp(-pow((x/C),k));
    }
    
    for(x=0;x<25;x++)
    {
        dis[x]=weibull[x]-acum[x];
    }
    for(x=0;x<25;x++)
    {
        cout<<x+1<<"\t"<<freq[x]<<"\t"<<acum[x]<<"\t"<<weibull[x]<<"\t"<<dis[x]<<endl;
    }

}
