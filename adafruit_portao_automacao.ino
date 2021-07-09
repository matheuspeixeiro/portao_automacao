// Automação de portão elétrico com ESP8266 e Adafruit IO MQTT-Broker
// OBS.: Para carregar este script em seu ESP8266, é necessário instalar
// as bibliotecas da Adafruit IO e do ESP8266.

// Electric gate automation with ESP8266 and Adafruit IO MQTT-Broker
// OBS.: To load this script on your ESP8266, you need to install the 
// Adafruit IO and ESP8266 libraries.

// By: Matheus Peixeiro . Follow me: github.com/matheuspeixeiro .

#include "config.h"

const byte RELE = D0;

// Instanciamento do feed da Adafruit (feed = variáveis na nuvem)
AdafruitIO_Feed *feedPortao = io.feed("PORTAO");

void setup() {
  pinMode(RELE, OUTPUT);
  digitalWrite(RELE, HIGH);
  
  Serial.begin(115200);
  delay(10);

  // Chama a função conectaBroker
  conectaBroker();
}

void loop() {// processa as mensagens e mantem a conexão ativa
  byte state = io.run();

  // verifica se está conectado
  if(state == AIO_NET_DISCONNECTED | state == AIO_DISCONNECTED){
    conectaBroker(); //função para conectar ao broker
  }
}

void conectaBroker(){

  //conectando à nuvem adafruit io mqtt-broker
  Serial.print("Conectando ao Adafruit IO");
  io.connect();
  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println(io.statusText()); // mostrar que foi conectado
  Serial.println("Setup concluído");
  
  // instancia um handler para recepção da mensagem do feed PORTAO
  feedPortao->onMessage(handlePortao);

  //obtendo valor atual:
  feedPortao->get();
  
}

void handlePortao(AdafruitIO_Data *data) {
  // Mensagem 
  Serial.print("Recebido  <- ");
  Serial.print(data->feedName());
  Serial.print(" : ");
  Serial.println(data->value());

  //Aciona saída conforme dado recebido
  if(data->isTrue()) {// se for 1
    digitalWrite(RELE, LOW);
    delay(2000);
    digitalWrite(RELE, HIGH);
    delay(2000);
  }
    
}
