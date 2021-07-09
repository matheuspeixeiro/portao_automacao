// controle portão de casa

#include "config.h"

const byte RELE = D0;

AdafruitIO_Feed *feedPortao = io.feed("PORTAO");

void setup() {
  pinMode(RELE, OUTPUT);
  digitalWrite(RELE, HIGH);
  
  Serial.begin(115200);
  delay(10);

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

  //conectando à nuvem adafruit io
  Serial.print("Conectando ao Adafruit IO");
  io.connect();
  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println(io.statusText()); // mostrar que foi conectado
  Serial.println("Setup concluído");
  
  // instancia um handler para recepção da mensagem do feed L1 
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
