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

    float data [2][20], freq[20],acum[20],weibull[20],dis[20], k=1.23448, C=2.8451;
     
    int x,y; 
    
ifstream in ("V-F(U)15.txt");

if (!in){
    cout<<"Not open file. \n";
    return 0;
    }

    for (y=0; y<20;y++)
    {
        for (x=0;x<2;x++)
        {
            in>>data[x][y];
        }
    }

    
 in.close();
     
    for(x=0;x<20;x++)
    {
        freq[x]=data[1][x];
    }
    
    for(x=0;x<20;x++)
    {
        acum[x]=freq[x]/28624;
    }
    
    for(x=0;x<20;x++)
    {
        weibull[x]=(k/C)*(pow((x/C),(k-1)))*exp(-pow((x/C),k));
    }
    
    for(x=0;x<20;x++)
    {
        dis[x]=weibull[x]-acum[x];
    }
    for(x=0;x<20;x++)
    {
        cout<<x+1<<"\t"<<freq[x]<<"\t"<<acum[x]<<"\t"<<weibull[x]<<"\t"<<dis[x]<<endl;
    }

}
