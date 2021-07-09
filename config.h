// Dados MQTT
#define IO_USERNAME  "teuz007"
#define IO_KEY       "aio_HSNC90hybJtPW8nKRHAIKNU0EcKq"

// Dados Wi-Fi
#define   WIFI_SSID   "peixeiro 2.4"
#define   WIFI_PASS   "Ab034033"

// Dados para comunicação
#include "AdafruitIO_WiFi.h"
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
