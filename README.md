# ⚽ Controle de Temperatura e Umidade em Campos de Futebol 


## 📖 Sobre o Projeto

O projeto Controle de Temperatura e Umidade nos Campos de Futebol tem como objetivo monitorar as condições climáticas do gramado em tempo real, utilizando um microcontrolador ESP32, comunicação HTTP e integração com um dashboard web.

Essa solução permite acompanhar temperatura e umidade de forma contínua, ajudando na manutenção do gramado, prevenção de superaquecimento e otimização da irrigação, garantindo melhores condições de jogo e preservação do campo.

## 🧠 Funcionamento Geral

O ESP32 simula ou coleta dados reais dos sensores (como DHT11/DHT22).

Esses dados são enviados via HTTP POST para um endpoint configurado no Postman Mock Server, simulando uma plataforma IoT na nuvem.

A resposta do servidor confirma o recebimento e pode conter instruções (ex: “ligar ventilador” ou “ativar irrigação”).

Um dashboard web (frontend) consome esses dados e os exibe graficamente em tempo real, permitindo análise e tomada de decisão.

## 📊 Integração com o Dashboard Web

O dashboard foi projetado para consumir os dados JSON do Postman Mock Server e exibi-los de forma visual e interativa.

Principais elementos:

- Gráfico em tempo real: mostra variação da temperatura e umidade.

- Indicadores numéricos: exibição dos valores atuais.

- Alertas automáticos: exibe mensagens quando a temperatura ultrapassa limites definidos.

- Interface responsiva: pode ser acessada via computador, tablet ou celular.



**👉 LINK DO WOKWI ->** [Click aqui para acessar a simulação](https://wokwi.com/projects/446359728707088385)

**👉 LINK DO SITE ->** [Click aqui para acessar ao Site ](link )

## 👩‍💻 Desenvolvedores 

- Julia Schiavi
- Thayna Lopes
- Sofia Bomeny
- Leonardo Grosskopf

