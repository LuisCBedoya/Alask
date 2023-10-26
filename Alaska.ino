/*
  Rui Santos
  Complete project details at Complete project details at https://RandomNerdTutorials.com/cloud-weather-station-esp32-esp8266/

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

*/

#ifdef ESP32
  #include <WiFi.h>
  #include <HTTPClient.h>
#else
  #include <ESP8266WiFi.h>
  #include <ESP8266HTTPClient.h>
  #include <WiFiClient.h>
#endif

#include <Wire.h>
// Definimos la librerias par la conexion a nuestro servidor
#include "FirebaseESP8266.h"


const int trigPin = 2;  //D4
const int echoPin = 0;  //D3
 
// defines variables
float duration;
float distance;



 
// Definimos la direccion host de nuestro servidor
#define FIREBASE_HOST "smarthome-44dd3-default-rtdb.firebaseio.com"
// Definimos el token de nuestro servidor
#define FIREBASE_AUTH "KeBZ9ijJRBpZi0anJapZZyyzjFzN2F8EVIl6FBJs"

const char* ssid = "AGUA_ALASKA";
const char* password = "Popelila1259";

WiFiClient client;

FirebaseData firebaseDataLed;
FirebaseData firebaseDataFan;
FirebaseData firebaseDataTemperature;
FirebaseData firebaseDataHumidity;


//Your Domain name with URL path or IP address with path
const char* serverName = "http://obkvkkib.lucusvirtual.es/esp-post-data.php";

// Keep this API Key value to be compatible with the PHP code provided in the project page.
// If you change the apiKeyValue value, the PHP file /esp-post-data.php also needs to have the same key
String apiKeyValue = "tPmAT5Ab3j7F9";
String sensorName = "DH-SR04";
String sensorLocation = "Alaska norte";
float bomba;
/*#include <SPI.h>
#define BME_SCK 18
#define BME_MISO 19
#define BME_MOSI 23
#define BME_CS 5*/

#define SEALEVELPRESSURE_HPA (1013.25)


// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastTime = 0;
// Timer set to 10 minutes (600000)
//unsigned long timerDelay = 600000;
// Set timer to 30 seconds (30000)
unsigned long timerDelay = 3000;
//definimos el pin para el led
#define LED 5
#define LEDos 16

void setup() {
  Serial.begin(115200);
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
 pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  // (you can also pass in a Wire library object like &Wire2)
   pinMode(LED, OUTPUT);
   pinMode(LEDos, OUTPUT);

 
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Serial.println("Timer set to 30 seconds (timerDelay variable), it will take 30 seconds before publishing the first reading.");
}

void loop() {
  //Send an HTTP POST request every 10 minutes


Serial.println(distance);
  
  if ((millis() - lastTime) > timerDelay) {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      WiFiClient client;
      HTTPClient http;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

       Firebase.getInt(firebaseDataLed,"/light_bulb");
  int datoled=(firebaseDataLed.intData()-24)/10;
 // analogWrite(LED, datoled);
//////////////////////////////////////////////////////////////////
 if (datoled > 0 && datoled < 100){
  
        // manual para encender las luces 
         if (datoled >1 && datoled < 10){
          //aqui para medir porcentaje 
              if (distance <=10 ){
               Serial.println("bomba prendida hasta 10%");
                digitalWrite(LEDos, HIGH);
                 bomba = 1;
               }
               else {
                Serial.println("bomba OFF hasta 10%");
                digitalWrite(LEDos, LOW);
                 bomba = 0;
               }
         }
          
  }
 /////////////////////////////////////////////////////////////////

 //////////////////////////////////////////////////////////////////
 if (datoled > 0 && datoled < 100){
  
        // manual para encender las luces 
         if (datoled >10 && datoled < 20){
          //aqui para medir porcentaje 
              if (distance <=20 ){
               Serial.println("bomba prendida hasta 20%");
                digitalWrite(LEDos, HIGH);
                 bomba = 1;
               }
               else {
                Serial.println("bomba OFF hasta 20%");
                digitalWrite(LEDos, LOW);
                 bomba = 0;
               }
         }
          
  }
 /////////////////////////////////////////////////////////////////
 
 if (datoled > 0 && datoled < 100){
  
        // manual para encender las luces 
         if (datoled >20 && datoled < 30){
          //aqui para medir porcentaje 
              if (distance <=30 ){
               Serial.println("bomba prendida hasta 30%");
                digitalWrite(LEDos, HIGH);
                 bomba = 1;
               }
               else {
                Serial.println("bomba OFF hasta 30%");
                digitalWrite(LEDos, LOW);
                 bomba = 0;
               }
         }
          
  }
  //////////////////////////////////////////////////////////////////
   if (datoled > 0 && datoled < 100){
  
        // manual para encender las luces 
         if (datoled >30 && datoled < 40){
          //aqui para medir porcentaje 
              if (distance <=40 ){
               Serial.println("bomba prendida hasta 40%");
                digitalWrite(LEDos, HIGH);
                 bomba = 1;
               }
               else {
                Serial.println("bomba OFF hasta 40%");
                digitalWrite(LEDos, LOW);
                 bomba = 0;
               }
         }
          
  }
  //////////////////////////////////////////////////////////////////
   if (datoled > 0 && datoled < 100){
  
        // manual para encender las luces 
         if (datoled >40 && datoled < 50){
          //aqui para medir porcentaje 
              if (distance <=50 ){
               Serial.println("bomba prendida hasta 50%");
                digitalWrite(LEDos, HIGH);
                 bomba = 1;
               }
               else {
                Serial.println("bomba OFF hasta 50%");
                digitalWrite(LEDos, LOW);
                 bomba = 0;
               }
         }
          
  }
  //////////////////////////////////////////////////////////////////
   if (datoled > 0 && datoled < 100){
  
        // manual para encender las luces 
         if (datoled >50 && datoled < 60){
          //aqui para medir porcentaje 
              if (distance <=60 ){
               Serial.println("bomba prendida hasta 60%");
                digitalWrite(LEDos, HIGH);
                 bomba = 1;
               }
               else {
                Serial.println("bomba OFF hasta 60%");
                digitalWrite(LEDos, LOW);
                 bomba = 0;
               }
         }
          
  }
  //////////////////////////////////////////////////////////////////
   if (datoled > 0 && datoled < 100){
  
        // manual para encender las luces 
         if (datoled >70 && datoled < 80){
          //aqui para medir porcentaje 
              if (distance <=80 ){
               Serial.println("bomba prendida hasta 80%");
                digitalWrite(LEDos, HIGH);
                 bomba = 1;
               }
               else {
                Serial.println("bomba OFF hasta 80%");
                digitalWrite(LEDos, LOW);
                 bomba = 0;
               }
         }
          
  }
  //////////////////////////////////////////////////////////////////
  if (datoled > 0 && datoled < 100){
  
        // manual para encender las luces 
         if (datoled >80 && datoled < 90){
          //aqui para medir porcentaje 
              if (distance <=80 ){
               Serial.println("bomba prendida hasta 90%");
                digitalWrite(LEDos, HIGH);
                 bomba = 1;
               }
               else {
                Serial.println("bomba OFF hasta 90%");
                digitalWrite(LEDos, LOW);
                 bomba = 0;
               }
         }
          
  }
  //////////////////////////////////////////////////////////////////
    if (datoled > 0 && datoled < 100){
  
        // manual para encender las luces 
         if (datoled >90 && datoled <=100){
          //aqui para medir porcentaje 
              if (distance <=90 ){
               Serial.println("bomba prendida hasta 90%");
                digitalWrite(LEDos, HIGH);
                 bomba = 1;
               }
               else {
                Serial.println("bomba OFF hasta 90%");
                digitalWrite(LEDos, LOW);
                 bomba = 0;
               }
         }
          
  }
  //////////////////////////////////////////////////////////////////
if (datoled <= 0 ) {
        Serial.println("0% bomba apagada");
         digitalWrite(LEDos, LOW);
       bomba = 0;
      }
/////////////////////////////////////////////////////////////////

  Firebase.setInt(firebaseDataHumidity,"humidity", distance);
 

 /////////////////////////////////////////////////////////////////////////

      // Your Domain name with URL path or IP address with path
      http.begin(client, serverName);

      // Specify content-type header
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");

      // Prepare your HTTP POST request data
      String httpRequestData = "api_key=" + apiKeyValue + "&sensor=" + sensorName
                            + "&location=" + sensorLocation + "&value1=" + String(distance)
                            + "&value2=" + String(datoled) + "&value3=" + String(bomba) + "";
      Serial.print("httpRequestData: ");
      Serial.println(httpRequestData);

      // You can comment the httpRequestData variable above
      // then, use the httpRequestData variable below (for testing purposes without the BME280 sensor)
      //String httpRequestData = "api_key=tPmAT5Ab3j7F9&sensor=BME280&location=Office&value1=24.75&value2=49.54&value3=1005.14";

      // Send HTTP POST request
      int httpResponseCode = http.POST(httpRequestData);

  

      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }///////////////////////////////////////////////////////7
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
 
  // Calculating the distance
  distance= 100-(duration*0.034/2.0);
  // Prints the distance on the Serial Monitor
  Serial.print(" Distance: ");
  Serial.println(distance);
  delay(200);
  delay(1000);
}
