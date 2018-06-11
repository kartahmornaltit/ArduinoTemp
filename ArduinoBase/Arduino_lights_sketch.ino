/* Arduino Base with lights on/off.
Начальный этап. Скетч. Построение ардуино с вкл/выкл лампочек. */
 
void setup() 
{ 
pinMode(2, OUTPUT); // initialize pin 2 as an output 
pinMode(3, OUTPUT); // initialize pin 3 as an output 
pinMode(4, OUTPUT); // initialize pin 4 as an output 
pinMode(5, OUTPUT); // initialize pin 5 as an output
pinMode(6, OUTPUT); // initialize pin 6 as an output
pinMode(7, INPUT);  // initialize pin 7 as an input 
} 

/* Функция lights_on поочередно включает светодиоды. С номера пина, равного первому полученному значению, до номера пина, равного второму полученному значению */

void lights_on (byte pin_start, byte pin_finish){  // функция принимает номера пинов, к которым подключены диоды.
if (pin_start < pin_finish){                       // если первый номер меньше второго, то запускается цикл, который включает диоды по **нарастающей**.
for (int pin = pin_start; pin <= pin_finish; pin++) 
{ 
digitalWrite(pin, HIGH); 
delay(100); 
} 
} 
else { 
for (int pin = pin_start; pin>=pin_finish; pin--)  // иначе диоды включаются по **убывающей**.
{ 
digitalWrite(pin, HIGH); 
delay(100); 
} 
} 
} 

/* Функция lights_off поочередно выключает светодиоды. С номера пина, равного первому полученному значению, до номера пина, равного второму полученному значению */

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
bool p7 = digitalRead(7);  // Инициализация булевой переменной. Считывает сигнал с 7 пина. 0 - кнопка не нажата(выкл), 1 - нажата(вкл)

while (p7 == 0){           // Прогоняем цикл, пока кнопка не нажата (=0)
p7 = digitalRead(7);       // Переменная p7 принимает значение, считанное с 7 пина 
} 
// Нажатие кнопки вывело программу из цикла
if (p7 == 1){ 
delay(100); // Delay a little bit to improve simulation performance 

lights_on (6,2);           // включаем диоды с шестого пина по второй

delay(200); 

lights_off(2,6);           // выключаем диоды со второго по шестой 
} 
}
