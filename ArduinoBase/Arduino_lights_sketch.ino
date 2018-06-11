/* Arduino Base with lights on/off.
Начальный этап. Построение ардуино с вкл/выкл лампочек. */
 
void setup() 
{ 
pinMode(2, OUTPUT); 
pinMode(3, OUTPUT); 
pinMode(4, OUTPUT); 
pinMode(5, OUTPUT); 
pinMode(6, OUTPUT); 
pinMode(7, INPUT); 
} 

void lights_on (byte pin_start, byte pin_finish){ 
if (pin_start < pin_finish){ 
for (int pin = pin_start; pin <= pin_finish; pin++) 
{ 
digitalWrite(pin, HIGH); 
delay(100); 
} 
} 
else { 
for (int pin = pin_start; pin>=pin_finish; pin--) 
{ 
digitalWrite(pin, HIGH); 
delay(100); 
} 
} 
} 

void lights_off(byte pin_start, byte pin_finish){ 
if (pin_start < pin_finish){ 
for (int pin = pin_start; pin <= pin_finish; pin++) 
{ 
digitalWrite(pin, LOW); 
delay(100); 
} 
} 
else { 
for (int pin = pin_start; pin>=pin_finish; pin--) 
{ 
digitalWrite(pin, LOW); 
delay(100); 
} 
} 
} 



void loop() 
{ 
bool p7 = digitalRead(7); 

while (p7 == 0){ 
p7 = digitalRead(7); 
} 

if (p7 == 1){ 
delay(100); // Delay a little bit to improve simulation performance 

lights_on (6,2); 

delay(200); 

lights_off(2,6); 
} 
}
