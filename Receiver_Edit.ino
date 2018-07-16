/* Receiver Code code
 * Example of sending data from an Ardunio UNO to NodeMCU through UART
 * Using this code you can send multiple data packets 
 * for instance from different sensors to a NodeMCU from an Arduino
 * This code was written for Telemedicine project of Dhaka Univeristy BMPT Department
 * Author: MD Fiaz Islam Bhuiyan, The University of Texas at Dallas
 * Date: 16th July 2018
   -----------------------------------------------------------------------*/
#include<SoftwareSerial.h>

SoftwareSerial com(D1,D2); // RX, TX

enum {getLdrSensor, getRandomData1, getRandomData2, getRandomData3, getRandomData4, getRandomData5, getRandomData6, getRandomData7 };

int whichNumber = getLdrSensor;

int light, randomData1, randomData2, randomData3, randomData4, randomData5, randomData6, randomData7;

//const char startOfNumberDelimiter = '<';
const char endOfNumberDelimiter   = '|';


boolean newData = false;

int dataNumber = 0;

void setup()             // begining of the setup function
{
  Serial.begin(115200);    
  com.begin(115200); 
  Serial.println("Node is reading...");
                     
}

void processNumber (const long n)
 {
  
  switch (whichNumber)
    {
    case getLdrSensor: 
      Serial.print ("LDR Value = ");
      break;
      
    case getRandomData1: 
      Serial.print ("Random Data1 = ");
      break;

    case getRandomData2: 
      Serial.print ("Random Data2 = ");
      break;

    case getRandomData3: 
      Serial.print ("Random Data3 = ");
      break;

    case getRandomData4: 
      Serial.print ("Random Data4 = ");
      break;

    case getRandomData5: 
      Serial.print ("Random Data5 = ");
      break;

    case getRandomData6: 
      Serial.print ("Random Data6 = ");
      break;

    case getRandomData7: 
      Serial.print ("Random Data7 = ");
      break;
    }

    
  Serial.println (n);
 }  // end of processNumber
 
void processInput ()
 {
 static long receivedNumber = 0;
 static boolean negative = false;
 
 byte c = com.read ();
 
 switch (c)
   {
     
   case endOfNumberDelimiter:  
     if (negative) 
       processNumber (- receivedNumber); 
     else
       processNumber (receivedNumber); 

   // fall through to start a new number
   case 'A': 
     receivedNumber = 0; 
     negative = false;
     whichNumber = getLdrSensor;
     break;
   case 'B': 
     receivedNumber = 0; 
     negative = false;
     whichNumber = getRandomData1;
     break;
   case 'C': 
     receivedNumber = 0; 
     negative = false;
     whichNumber = getRandomData2;
     break;
   case 'D': 
     receivedNumber = 0; 
     negative = false;
     whichNumber = getRandomData3;
     break;
   case 'E': 
     receivedNumber = 0; 
     negative = false;
     whichNumber = getRandomData4;
     break;
   case 'F': 
     receivedNumber = 0; 
     negative = false;
     whichNumber = getRandomData5;
     break;
   case 'G': 
     receivedNumber = 0; 
     negative = false;
     whichNumber = getRandomData6;
     break;
   case 'H': 
     receivedNumber = 0; 
     negative = false;
     whichNumber = getRandomData7;
     break;
     
   case '0' ... '9': 
     receivedNumber *= 10;
     receivedNumber += c - '0';
     break;
     
   case '-':
     negative = true;
     break;
     
   } // end of switch  
 }  // end of processInput
 
void loop ()
 {
    if (com.available ())
        processInput ();
   
 // do other stuff here
 } // end of loop
