# Техническое задание "ArduinoTemp"


## Оглавление
* [Введение](#ВВЕДЕНИЕ)
  * [Назначение](#НАЗНАЧЕНИЕ)
  * [Целевая аудитория](#МАСШТАБ-ПРОЕКТА)
* [Общее описание](#ОБЩЕЕ-ОПИСАНИЕ)
  * [Описание](#ОПИСАНИЕ)
  * [Общая Функциональность](#ОБЩАЯ-ФУНКЦИОНАЛЬНОСТЬ)
    * [С точки зрения разработчиков](#С-ТОЧКИ-ЗРЕНИЯ-РАЗРАБОТЧИКОВ)
    * [С точки зрения клиента](#С-ТОЧКИ-ЗРЕНИЯ-КЛИЕНТА)
  * [Функции продукта](#ФУНКЦИИ-ПРОДУКТА)
    * [Бэкенд (микропроцессор)](#БЭКЕНД-МИКРОПРОЦЕССОР)
    * [Фронтенд (сайт)](#ФРОНТЕНД-САЙТ)
    * [Бэкенд (сервер)](#БЭКЕНД-СЕРВЕР)
  * [Характеристики пользователя](#ХАРАКТЕРИСТИКИ-ПОЛЬЗОВАТЕЛЯ)
  * [Ограничения](#ОГРАНИЧЕНИЯ)
* [Детальные требования](#ДЕТАЛЬНЫЕ-ТРЕБОВАНИЯ)
  * [Требования ко внешним интерфейсам](#ТРЕБОВАНИЯ-КО-ВНЕШНИМ-ИНТЕРФЕЙСАМ)
    * [Интерфейс пользователя](#ИНТЕРФЕЙС-ПОЛЬЗОВАТЕЛЯ-САЙТ)
    * [Серверный интерфейс (API)](#СЕРВЕРНЫЙ-ИНТЕРФЕЙС-api)
  * [Функциональные требования](#ФУНКЦИОНАЛЬНЫЕ-ТРЕБОВАНИЯ)
  * [Описание возможностей](#ОПИСАНИЕ-ВОЗМОЖНОСТЕЙ)
  * [Системные требования](#СИСТЕМНЫЕ-ТРЕБОВАНИЯ)
  * [Перспективы развития](#ПЕРСПЕКТИВЫ-РАЗВИТИЯ)
  * [Стек технологий](#СТЕК-ТЕХНОЛОГИЙ)


## ВВЕДЕНИЕ
### НАЗНАЧЕНИЕ
Создание системы для измерения температуры и отслеживания ее в реальном времени с помощью веб интерфейса.

### ЦЕЛЕВАЯ АУДИТОРИЯ
Пользователи данного устройства.


## ОБЩЕЕ ОПИСАНИЕ
### ОПИСАНИЕ
Данная система прдставляет собой устройство для измерения температуры и отправки её на сервер, а также веб интерфейса для отслеживания значений температуры в реальном времени. 

### ОБЩАЯ ФУНКЦИОНАЛЬНОСТЬ
#### С ТОЧКИ ЗРЕНИЯ РАЗРАБОТЧИКОВ
* Создать плату для измерения температуры и отправки полученных данных на сервер;
* Создать сервер с базой данных для хранения значений температуры;
* Создать веб интерфейс для отображения графика температуры в реальном времени.
#### С ТОЧКИ ЗРЕНИЯ КЛИЕНТА
* Предоставить возможность отслеживания температуры;
* Получение информативных графиков в режиме реального времени

### ФУНКЦИИ ПРОДУКТА
#### БЭКЕНД (ПЛАТА)
* Считывание темпертуры;
* Передача данных температуры.
#### ФРОНТЕНД (САЙТ)
* Просмотр графика температуры в реальном времени;
* Просмотр графика температуры за определенный период.
#### БЭКЕНД (СЕРВЕР)
* Хранение всех значений температуры.

### ХАРАКТЕРИСТИКИ ПОЛЬЗОВАТЕЛЯ
* Владелец данного устройства для измерения темературы;
* Пользователь, имеющий доступ к сети Интернет.

### ОГРАНИЧЕНИЯ
* Устройство для измерения темпереатуры должно быть создано по имеющейся схеме.


## ДЕТАЛЬНЫЕ ТРЕБОВАНИЯ
### ТРЕБОВАНИЯ КО ВНЕШНИМ ИНТЕРФЕЙСАМ
#### ИНТЕРФЕЙС ПОЛЬЗОВАТЕЛЯ (САЙТ)
[Макет сайта](https://gomockingbird.com/projects/ghpz87a/TnMd3U)  
Интерфейс пользователя представляет собой сайт, который включает в себя следующие страницы:
1. **Страница Realtime**  
Отображение температуры на данный момент.
![Realtime temperature](./images/1-Home-Realtime.png)

2. **Страница History**  
Отображение графика изменения температур за указанный промежуток времени.
![Custom temperature](./images/2-History.png)
#### СЕРВЕРНЫЙ ИНТЕРФЕЙС (API)

### ФУНКЦИОНАЛЬНЫЕ ТРЕБОВАНИЯ

### ОПИСАНИЕ ВОЗМОЖНОСТЕЙ

### СИСТЕМНЫЕ ТРЕБОВАНИЯ

### ПЕРСПЕКТИВЫ РАЗВИТИЯ

### СТЕК ТЕХНОЛОГИЙ
