/*
============================================================
  SISTEMA DE CONTROL Y MONITOREO DE TEMPERATURA

  Descripción:
  Sistema embebido basado en Arduino para la medición,
  control y monitoreo de temperatura en un entorno cerrado.
  Implementa control ON/OFF con histéresis, filtrado por
  promedio móvil y sistema de alarmas por niveles.

  Funcionalidades:
  - Lectura de sensor de temperatura analógico
  - Filtrado de señal mediante promedio de N muestras
  - Control de ventilador
  - Sistema de alarmas (advertencia y crítico)
  - Indicadores visuales y acústicos (LEDs + buzzer)
  - Monitoreo por puerto serial

  Autor: Jonathan Gutiérez Piedra
  Carrera: Ingeniería en Electrónica - TEC
  Fecha: 11/06/2026

  Notas:
  - El sistema usa control tipo ON/OFF con histéresis.
  - Temperaturas en °C derivadas de lectura ADC.
============================================================
*/

//Pin del ventilador.
const byte pinVent = 2;
//Pin buzzer de alarma
const byte pinBuzzer = 3;
//Pin alerta rojo
const byte pinRojo = 4;
//Pin alerta amarillo
const byte pinAma = 5;
//Pin del sensor de temperatura.
const byte pinSen = 6;
//Numero de Lecturas para el promedio
const byte NumL=5; 
//Estado en 1=Normal, 2=Advertencia, 3=Critico
byte Estado=0;

bool Encendido=false;

float Temps[NumL]={0.0,0.0,0.0,0.0,0.0};

void setup() {
  Serial.begin(9600);
  pinMode (pinSen , INPUT);
  pinMode (pinVent , OUTPUT);
}

void loop() {
  float suma=0.0;
  for (int i = 0; i<NumL; i++){
  int Med = analogRead(pinSen);
  float Temp = ((Med /1023.0) * 5000)/10;
  suma += Temp;
  delay(200);
  }
  float Promedio=suma/NumL;
  if(Promedio>30.0){
    digitalWrite(pinVent , HIGH);
    Encendido=true;
  }
  if(Promedio<28.0){
    digitalWrite(pinVent , LOW);
    Encendido=false;
  }
  if(Promedio>35){
    digitalWrite(pinAma , HIGH);
    //Estado de Advertencia
    Estado=2;
  }
  else if (digitalRead(pinVent)==HIGH){
    digitalWrite(pinAma , LOW);
    //Estado Normal
    Estado=1;
  }
  if(Promedio>40){
    digitalWrite(pinRojo , HIGH);
    digitalWrite(pinBuzzer , HIGH);
    //Estado Critico
    Estado=3;
  }
  else if (digitalRead(pinVent)==HIGH){
    digitalWrite(pinRojo , LOW);
    digitalWrite(pinBuzzer , LOW);
  }
  Serial.print("Temp: ");
  Serial.println(Promedio);
  Serial.print("°C");
  Serial.print("Ventilador: ");
  if (Encendido=true){
   Serial.println("Encendido");
  }
  else{
   Serial.println("Apagado");
  }
  Serial.print("Estado: ");
  if (Estado=1){
   Serial.println("Normal");
  }
  if (Estado=2){
   Serial.println("Advertencia");
  }
  if (Estado=3){
   Serial.println("Critico");
  }
  else{
  //Para debug
   Serial.println("Sin estado detectado");
  }
}
