#include <ESP8266WiFi.h>
const char* ssid     = "ssid";
const char* password = "password";

const char* host = "localhost";


int sensorPin = 0; //аналоговый ввод для выхода датчика TMP36
    //разрешение 10 мВ / градус цельсия со смещением на 500 мВ 
    //для отрицательной температуры


    void setup()
    {
      
      Serial.begin(115200);
  delay(100);

  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

 while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); 
    //Serial.begin(9600);
    }


    void loop()
    {
      
      WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
      
    //считываем напряжение датчика
    int reading = analogRead(sensorPin);
    // преобразуем показания в напряжение
    float voltage = reading * 5.0;
    voltage /= 1024.0;
  
    // теперь выводим температуру
    float temperatureC = (voltage - 0.5) * 100 ; //исходя из 10 мВ на градус со смещением 500 мВ
    Serial.print(temperatureC); Serial.println(" degrees C");
    
      String data = "pst=temperature>" + String(temperatureC) + "||data>text";
      
      
      
       Serial.print("Requesting POST: ");
   // Send request to the server:
   client.println("POST / HTTP/1.1");
   client.println("Host: localserver");
   client.println("Accept: */*");
   client.println("Content-Type: application/x-www-form-urlencoded");
   client.print("Content-Length: ");
   client.println(data.length());
   client.println();
   client.print(data);

   delay(500); // Can be changed
  if (client.connected()) { 
    client.stop();  // DISCONNECT FROM THE SERVER
  }
  Serial.println();
  Serial.println("closing connection");
  delay(5000);
}
      
    delay(1000); //ждем секунду
    }








