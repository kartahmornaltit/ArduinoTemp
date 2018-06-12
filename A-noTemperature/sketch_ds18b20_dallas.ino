#include <OneWire.h>
#include <DallasTemperature.h>
 
#define PIN_DS18B20 8  // Номер пина Arduino с подключенным датчиком
 
OneWire oneWire(PIN_DS18B20);  // Аналогично создаем объект OneWire

DallasTemperature dallasSensors(&oneWire); // Создаем объект DallasTemperature для работы с сенсорами, передавая ему ссылку на объект для работы с OneWire.
 
DeviceAddress sensorAddress; // Специальный объект для хранения адреса устройства
 
void setup(void){
  Serial.begin(9600);
  Serial.println("Пример работы с датчиком температуры ds18b20 с помощью библиотеки DallasTemperature");
 
  Serial.print("Ищем устройства...");
  dallasSensors.begin();
  Serial.print("Найдено ");
  Serial.print(dallasSensors.getDeviceCount(), DEC);
  Serial.println(" устройств");
 
  Serial.print("Режим паразитного питания: ");
  if (dallasSensors.isParasitePowerMode()) Serial.println("ВКЛЮЧЕН");
  else Serial.println("ВЫКЛЮЧЕН");
 
  sensorAddress = { 0x28, 0x1D, 0x39, 0x31, 0x2, 0x0, 0x0, 0xF0 };  // если хотим задать адрес устройства вручную
 
  // Поиск устройства:
  // Ищем адрес устройства по порядку (индекс задается вторым параметром функции)
  if (!dallasSensors.getAddress(sensorAddress, 0)) Serial.println("Не можем найти первое устройство");
 
  // 2-ой вариант с помощью OneWire, перезапускаем поиск:
  oneWire.reset_search();
 
  // Находим первое устройство и запоминаем его адрес в sensorAddress
  if (!oneWire.search(sensorAddress)) Serial.println("Unable to find address for sensorAddress");
 
  // Отображаем адрес ds18b20, который мы нашли:
  Serial.print("Адрес устройства: ");
  printAddress(sensorAddress);
  Serial.println();
 
  dallasSensors.setResolution(sensorAddress, 12); // разрешение датчика в 12 бит (точность уменьшится, скорость данных увеличится)
 
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
