#include <OneWire.h>
 
#define PIN_DS18B20 8
 
OneWire oneWire(PIN_DS18B20);
 
DeviceAddress sensorAddress;
 
void setup(void){
  Serial.begin(9600);
  Serial.println("Пример работы с датчиком температуры ds18b20");
 
  Serial.print("Ищем устройства...");
  dallasSensors.begin();
  Serial.print("Найдено ");
  Serial.print(dallasSensors.getDeviceCount(), DEC);
  Serial.println(" устройств.");
 
  // Определяем режим питания (по отдельной линии или через паразитное питание по линии данных)
  Serial.print("Режим паразитного питания: ");
  if (dallasSensors.isParasitePowerMode()) Serial.println("ВКЛЮЧЕН");
  else Serial.println("ВЫКЛЮЧЕН");
 
  // Поиск устройства:
  // Ищем адрес устройства по порядку (индекс задается вторым параметром функции)
  if (!dallasSensors.getAddress(sensorAddress, 0)) Serial.println("Не можем найти первое устройство");

  Serial.print("Адрес устройства: ");
  printAddress(sensorAddress);
  Serial.println();
 
  dallasSensors.setResolution(sensorAddress, 12);
 
  Serial.print("Разрешение датчика: ");
  Serial.print(dallasSensors.getResolution(sensorAddress), DEC);
  Serial.println();
}
 
void loop(void){
  // Запрос на измерения датчиком температуры
 
  Serial.print("Измеряем температуру...");
  dallasSensors.requestTemperatures(); // Просим ds18b20 собрать данные
  Serial.println("Выполнено");
 
  //  Запрос на получение сохраненного значения температуры
  printTemperature(sensorAddress);
 
  // Задержка для того, чтобы можно было что-то разобрать на экране
  delay(1000);
}
 
// Вспомогательная функция печати значения температуры для устройства
void printTemperature(DeviceAddress deviceAddress){
  float tempC = dallasSensors.getTempC(deviceAddress);
  Serial.print("Temp C: ");
  Serial.println(tempC);
}
 
// Вспомогательная функция для отображения адреса датчика ds18b20
void printAddress(DeviceAddress deviceAddress){
  for (uint8_t i = 0; i < 8; i++)
  {
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
}
