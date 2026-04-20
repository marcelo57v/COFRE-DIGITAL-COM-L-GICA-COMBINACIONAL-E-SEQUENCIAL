# Cofre Digital - Lógica Combinacional e Sequencial

## Descrição do Projeto
Este repositório contém o desenvolvimento de um **Cofre Digital**, realizado como parte da disciplina de Circuitos Digitais da UFMA. O projeto aplica conceitos fundamentais de eletrônica digital, utilizando lógica combinacional para o processamento de dados e lógica sequencial para o controle de estados, sem o uso de microcontroladores.

## Especificações Técnicas
O sistema foi projetado para executar as seguintes funções:
* **Lógica Combinacional:** Responsável pela verificação da senha binária, comparando a entrada do usuário com a chave armazenada através de comparadores e portas lógicas puras.
* **Lógica Sequencial:** Gerencia os estados do cofre (Bloqueado e Aberto) utilizando Flip-Flops para garantir a persistência do estado e a segurança do acionamento.

## Principais Componentes
* **Circuitos Integrados (74xx / 4000):** Portas lógicas básicas para processamento de sinais.
* **Flip-Flops:** Para armazenamento do estado lógico da máquina de estados (FSM).
* **Teclado/Botões:** Interface de entrada para inserção da senha binária.
* **LEDs de Status:** Feedback visual imediato, sendo o LED Verde para acesso permitido e o LED Vermelho para acesso negado.

## Estrutura do Repositório
* `/docs`: Relatórios (TAP e PGP), esquemas elétricos e documentação técnica.
* `/src`: Arquivos de simulação lógica para validação da tabela verdade.
* `/assets`: Imagens do protótipo montado em protoboard e diagramas esquemáticos.

## Integrantes do Grupo
* MARCELO ADRIEL CAMARA ALMEIDA
* HELTON ALVES SÁ
* DERIANE FERREIRA OLIVEIRA
* MARCOS GABRIEL BAHURY RODRIGUES
