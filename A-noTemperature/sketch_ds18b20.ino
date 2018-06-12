#include <OneWire.h>
/*
* Описание взаимодействия с цифровым датчиком ds18b20 
* Подключение ds18b20 к ардуино через пин 8  
*/
OneWire ds(8); // Создаем объект OneWire для шины 1-Wire, с помощью которого будет осуществляться работа с датчиком
 
void setup(){
  Serial.begin(9600);
}
 
void loop(){
  
  byte data[2]; 
   
  ds.reset(); 
  ds.write(0xCC); 
  ds.write(0x44);
   
  delay(1000);   
   
  ds.reset(); 
  ds.write(0xCC); 
  ds.write(0xBE); 
 
  data[0] = ds.read(); 
  data[1] = ds.read(); 
 
  float temperature =  ((data[1] << 8) | data[0]) * 0.0625;
   
  Serial.println(temperature);
    
}
