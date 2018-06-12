#include "DHT.h"

#define DHTPIN 2 // номер пина, к которому подсоединен датчик

// Раскомментируйте в соответствии с используемым датчико
// Инициируем датчик. Используем DHT22.

DHT dht(DHTPIN, DHT22); //если используется датчик dht22 
//DHT dht(DHTPIN, DHT11); //если используется датчик dht11 

void setup() {

Serial.begin(9600);
dht.begin();

}

void loop() {

delay(2000); // задержка 2 секунды между измеренеями 

float h = dht.readHumidity();    // Считываем влажность

float t = dht.readTemperature(); // Считываем температуру
// Проверка удачно прошло ли считывание:
if (isnan(h) || isnan(t)) {

Serial.println("Не удается считать показания");

return;

}

Serial.print("-Humidity: "+h+" %\t"+"-Temperature: "+t+" *C "); // показания

}
