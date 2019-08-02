#include<Wire.h>            //Comunications via Cable
#include "RTClib.h"         //Real Time Clock Lib
#include <DHT.h>            //DHT22 Module Lib (Temperature)
#include <SPI.h>            //SD required Lib
#include <SD.h>             //SD principal Lib
#include <SFE_BMP180.h>     //BMP Lib (Pressure)
SFE_BMP180 pressure;        //Define tipe of module for Pressure
File myFile;                //Name of comand for SD write.
#define DHTPIN 3            //Define pin of Temp Module
#define DHTTYPE DHT22       //Define type of DHT used
DHT dht(DHTPIN, DHTTYPE);   //Function for DHT module
RTC_DS3231 rtc;             //Define type of RTC used
const int chipSelect = 10;  //Pin used by SD card module
const bool eco=true;
int count = 0;
//ULTIMO INICIO DE TOMA DE DATOS 15:39:00, CORREGIR FECHAS A PARTIR DE 18-10-17-------FUNCIONANDO SIN BMP180

#define LOG_INTERVAL 10000  //Data logging interval
#define SYNC_INTERVAL 10000 //Sync interval
uint32_t syncTime = 0;      //Initiate counter sync
#define ECHO_TO_SERIAL 1    
#define WAIT_TO_START 0

#define redLEDpin 5
#define greenLEDpin 4

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


int a, b, c, u, v, w, x, y, z;    //Variables for program
float l1, v1, a1;                 //variables for anemometer 1
float l2, v2, a2;                 //variables for anemometer 2
float vs, watt, vr;               //Variables for solar panel
double PresionBase;
double Presion=0;
double Altura=0;
double Temperatura=0;
char status;

void setup()
{
  Serial.begin(9600);
  Serial.println();
  pinMode(redLEDpin,OUTPUT);
  pinMode(greenLEDpin,OUTPUT);


  Serial.println("All Modules TEST!...");
  pinMode(chipSelect,OUTPUT);

  if(!SD.begin(chipSelect))
  {
    Serial.print("Card failed, or not present");
    digitalWrite(redLEDpin,HIGH);
    while(1);
   }

   Serial.println("Card initialized");

Wire.begin(); 
  if(!rtc.begin())
  {
    myFile.println("RTC failed");
    #if ECHO_TO_SERIAL
    Serial.println("RTC failed");
    #endif
  }
  else
    Serial.println("RTC initialized, begin datalogging");

if (!SD.exists("weather.txt"))
{
  myFile=SD.open("weather.txt", FILE_WRITE);
  if(myFile){
    myFile.println("Date \t Time \t Hum \t Temp \t Vel2 \t Vel1 \t Solar \t Press \t D-W");
    myFile.close();
    #if ECHO_TO_SERIAL
    Serial.println("Date \t Time \t Hum \t Temp \t Vel2 \t Vel1 \t Solar \t Press \t D-W");
    #endif
    }
  }
else
{Serial.println("Error to load file...");
  }
  
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

dht.begin();
//SensorStart();
  
}                           //end of Void Setup

void loop()
{

  DateTime now=rtc.now();
  ReadSensor();

  delay ((LOG_INTERVAL -1) - (millis() % LOG_INTERVAL));

  digitalWrite(greenLEDpin, HIGH);

  uint32_t m = millis();

   myFile=SD.open("weather.txt", FILE_WRITE);
   if(myFile){
      digitalWrite(greenLEDpin, HIGH);
             myFile.print(now.day(), DEC); 
             myFile.print("/");
             myFile.print(now.month(), DEC);
             myFile.print("/");
             myFile.print(now.year(), DEC);
             myFile.print("\t");
             myFile.print(now.hour(), DEC);
             myFile.print(":");
             myFile.print(now.minute(), DEC);
             myFile.print(":");
             myFile.print(now.second(), DEC);
             myFile.print("\t");
       #if ECHO_TO_SERIAL
       Serial.print(now.day(), DEC);
       Serial.print("/");
       Serial.print(now.month(), DEC);
       Serial.print("/");
       Serial.print(now.year(), DEC);
       Serial.print("\t");
       Serial.print(now.hour(), DEC);
       Serial.print(':');
       Serial.print(now.minute(), DEC);
       Serial.print(':');
       Serial.print(now.second(), DEC);
       Serial.print("\t");
       #endif

       float h=dht.readHumidity();
       float t=dht.readTemperature();
       l1=analogRead(0);
       v1=(((l1*5.0)/1024)*1000);
       a1=(v1/33.1923);  
       l2=analogRead(1);//anemometro2
       v2=(((l2*5.0)/1024)*1000);
       a2=(v2/30.3489196);
       vs=analogRead(2);//panel solar
       vr=((vs*5.0)/1024);
       watt=(0.975*205.13*vr);
        a=digitalRead(7);
        b=digitalRead(8);
        c=digitalRead(9);

             myFile.print(h);
             myFile.print("\t");
             myFile.print(t);
             myFile.print("\t");
             myFile.print(a1);
             myFile.print("\t");
             myFile.print(a2);
             myFile.print("\t");
             myFile.print(watt);
             myFile.print("\t");
             myFile.print(Presion);
             myFile.print("\t");
#if ECHO_TO_SERIAL
    Serial.print(h);
    Serial.print("\t");
    Serial.print(t);
    Serial.print("\t");
    Serial.print(a1);
    Serial.print("\t");
    Serial.print(a2);
    Serial.print("\t");
    Serial.print(watt);
    Serial.print("\t");
    Serial.print(Presion);
    Serial.print("\t");
 #endif
             

if((a==LOW)&&(b==HIGH)&&(c==HIGH))
  {
  Serial.print("N");
  myFile.print("N");
  }
  else
  {
    if((a==HIGH)&&(b==LOW)&&(c==HIGH))
    {
      Serial.print("N-E");
      myFile.print("N-E");
      }
      else
      {
        if ((a==LOW)&&(b==LOW)&&(c==HIGH))
        {
          Serial.print("E");
          myFile.print("E");
          }
          else
          {
            if((a==HIGH)&&(b==HIGH)&&(c==LOW))
            {
              Serial.print("S-E");
              myFile.print("S-E");
              }
              else
              {
                if((a==LOW)&&(b==HIGH)&&(c==LOW))
                {
                  Serial.print("S");
                  myFile.print("S");
                  }
                  else
                  {
                    if((a==HIGH)&&(b==LOW)&&(c==LOW))
                    {
                      Serial.print("S-O");
                      myFile.print("S-O");
                      }
                      else
                      {
                        if((a==LOW)&&(b==LOW)&&(c==LOW))
                        {
                          Serial.print("O");
                          myFile.print("O");
                          }
                          else
                          {
                            if((a==HIGH)&&(b==HIGH)&&(c==HIGH))
                            {
                              Serial.print("N-O");
                              myFile.print("N-O");
                              }
                              else
                              Serial.print("ERROR");
                              myFile.print("ERROR");
                              }
                        }
                    }
                  }
               }
           }
        }
     

  
  myFile.println();
  Serial.println();

  myFile.close();
       }

if((millis()-syncTime) < SYNC_INTERVAL) return;
syncTime = millis();
digitalWrite(greenLEDpin, LOW);
digitalWrite(redLEDpin, HIGH);
delay(50);
digitalWrite(redLEDpin, LOW);

       
       
   }

void SensorStart() {

  //Secuencia de inicio del sensor

  if (pressure.begin())
    Serial.println();
  else
  {

    Serial.println("BMP180 init fail (disconnected?)\n\n");
    while (1);
  }

  //Se inicia la lectura de temperatura
  status = pressure.startTemperature();
  if (status != 0)  {
    delay(status);
    //Se lee una temperatura inicial
    status = pressure.getTemperature(Temperatura);
    if (status != 0)    {
      //Se inicia la lectura de presiones
      status = pressure.startPressure(3);
      if (status != 0)      {
        delay(status);
        //Se lee la presión inicial incidente sobre el sensor en la primera ejecución
        status = pressure.getPressure(PresionBase, Temperatura);
      }
    }
  }
}


void ReadSensor() {
  //En este método se hacen las lecturas de presión y temperatura y se calcula la altura

  //Se inicia la lectura de temperatura
  status = pressure.startTemperature();
  if (status != 0)
  {
    delay(status);
    //Se realiza la lectura de temperatura
    status = pressure.getTemperature(Temperatura);
    if (status != 0)
    {
      //Se inicia la lectura de presión
      status = pressure.startPressure(3);
      if (status != 0)
      {
        delay(status);
        //Se lleva a cabo la lectura de presión,
        //considerando la temperatura que afecta el desempeño del sensor

        status = pressure.getPressure(Presion, Temperatura);
        if (status != 0)
        {
          //Se hace el cálculo de la altura en base a la presión leída en el Setup
          Altura = pressure.altitude(Presion, PresionBase);
        }
        else Serial.println("error en la lectura de presion\n");
      }
      else Serial.println("error iniciando la lectura de presion\n");
    }
    else Serial.println("error en la lectura de temperatura\n");
  }
  else Serial.println("error iniciando la lectura de temperatura\n");

}

  
