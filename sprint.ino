#include <WiFi.h>
#include <HTTPClient.h>

//  CONFIGURAÇÕES DO WI-FI 
const char* ssid = "NOME_DO_WIFI";
const char* password = "SENHA_DO_WIFI";


String serverName = "https://e4fe9311-8a5f-4518-8f37-6260e33d2f0f.mock.pstmn.io";


unsigned long ultimaLeitura = 0;
const unsigned long intervalo = 5000; // 5 segundos

void setup() {
  Serial.begin(115200);
  Serial.println("\n=== SIMULAÇÃO IoT VIA HTTP (POSTMAN) ===");

 
  Serial.print("Conectando ao WiFi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  unsigned long inicio = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - inicio < 10000) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✅ WiFi conectado!");
    Serial.print("IP local: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\n Falha ao conectar. Verifique SSID e senha.");
  }

  Serial.print("Endpoint configurado: ");
  Serial.println(serverName);
}

void loop() {
  unsigned long agora = millis();

  if (agora - ultimaLeitura >= intervalo) {
    ultimaLeitura = agora;

    // SIMULANDO DADOS
    float temperatura = random(200, 320) / 10.0; // 20.0 a 32.0 °C
    float umidade = random(400, 700) / 10.0;     // 40.0 a 70.0 %


    String json = "{\"temperatura\": " + String(temperatura, 1) +
                  ", \"umidade\": " + String(umidade, 1) + "}";

    Serial.println("\n====================");
    Serial.println(" Payload JSON:");
    Serial.println(json);

  
    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      http.begin(serverName); 
      http.addHeader("Content-Type", "application/json");

      int codigo = http.POST(json);

      Serial.print(" Código de resposta: ");
      Serial.println(codigo);

      if (codigo > 0) {
        String resposta = http.getString();
        Serial.println(" Resposta do servidor:");
        Serial.println(resposta);
      } else {
        Serial.println(" Erro ao enviar requisição HTTP");
      }
      http.end();
    } else {
      Serial.println("⚠️ WiFi desconectado, tentando reconectar...");
      WiFi.begin(ssid, password);
    }
  }
}
