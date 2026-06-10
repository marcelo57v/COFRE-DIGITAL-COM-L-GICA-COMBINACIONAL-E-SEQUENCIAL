# Cofre Digital

Projeto de um sistema de segurança digital microcontrolado baseado em Arduino. Este repositório contém o código-fonte, os diagramas elétricos e a documentação técnica para a montagem de um cofre com validação de senha, feedback audiovisual e acionamento de trava eletromecânica.

Projeto desenvolvido como parte das atividades da disciplina de **Circuitos Digitais** do curso de Engenharia da Computação da **Universidade Federal do Maranhão (UFMA)**.

---

## Funcionalidades

* **Autenticação Segura:** Inserção de senha numérica através de um teclado matricial 4x4.
* **Feedback Visual:** Interface interativa utilizando um display LCD (com módulo I2C) para exibir mensagens de status (ex: "Aguardando...", "Senha Correta", "Acesso Negado") e LEDs indicadores (Verde para sucesso, Vermelho para erro).
* **Feedback Sonoro:** Alertas sonoros via buzzer para cada tecla pressionada e respostas específicas para sucesso ou falha na autenticação.
* **Mecanismo de Trava:** Acionamento de um relé que controla o motor/fechadura solenoide responsável por destravar a porta do cofre.

---

## Hardware e Componentes

A simulação e validação do hardware foram realizadas na plataforma **Tinkercad**. A lista completa de materiais e os diagramas podem ser encontrados na pasta `/hardware`.

**Principais Componentes Utilizados:**
* 1x Placa Arduino Uno R3
* 1x Teclado Matricial 4x4
* 1x Display LCD 16x2 (com interface I2C)
* 1x Módulo Relé
* 1x Motor CC / Fechadura Solenoide (representando a trava)
* 1x Buzzer (Piezo)
* LEDs (Verde e Vermelho) e resistores apropriados

> **Visualização do Circuito:**
> Você pode conferir a montagem na protoboard [aqui](hardware/montagem_protoboard.png) e o diagrama esquemático [aqui](hardware/esquema_eletrico.png).

---

## Simulação no Tinkercad

Acesse o link público da simulação: https://www.tinkercad.com/things/dHVTRizpx5P-cofre-arduino
Clique em "Iniciar Simulação".
Utilize o teclado matricial interativo na tela para testar as senhas e observar o comportamento do display, LEDs e do motor.

## Estrutura do Repositório

text
cofre-digital/
├── src/                        # Código-fonte principal
│   └── cofre_digital.ino       # Código em C++ para a Arduino IDE
├── hardware/                   # Diagramas e especificações físicas
│   ├── esquema_eletrico.png    # Diagrama de ligações
│   ├── montagem_protoboard.png # Representação visual do circuito
│   └── lista_componentes.png   # Tabela BOM (Bill of Materials)
├── assets/                     # Imagens e recursos visuais do README
│   └── fluxograma_logica.png   # Fluxograma de funcionamento do código
├── .gitignore                  
├── LICENSE                     
└── README.md

## Integrantes do Grupo
* DERIANE FERREIRA OLIVEIRA - 20240057711
* HELTON ALVES SÁ - 20260009631
* MARCELO ADRIEL CAMARA ALMEIDA - 2020002392
* MARCOS GABRIEL BAHURY RODRIGUES - 2023037248
