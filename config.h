// Dados MQTT
#define IO_USERNAME  "ADAFRUIT_IO_USERNAME"
#define IO_KEY       "ADAFRUIT_IO_KEY"

// Dados Wi-Fi
#define   WIFI_SSID   "SSID_WIFI"
#define   WIFI_PASS   "PASSWORD_WIFI"

// Dados para comunicação
#include "AdafruitIO_WiFi.h"
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
