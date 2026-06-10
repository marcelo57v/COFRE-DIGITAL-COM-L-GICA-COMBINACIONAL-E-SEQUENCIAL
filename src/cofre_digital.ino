#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// Configuração do Display I2C usando o endereço decimal 32 padrão do Tinkercad
LiquidCrystal_I2C lcd(32, 16, 2);

// --- Configuração do Teclado de Membrana 4x4 ---
const byte LINHAS = 4;
const byte COLUNAS = 4;

// Mapeamento das teclas
char matrizTeclas[LINHAS][COLUNAS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Pinos do Arduino conectados ao teclado
byte pinosLinhas[LINHAS] = {9, 8, 7, 6};
byte pinosColunas[COLUNAS] = {5, 4, 3, 2};

// Inicializa a biblioteca do teclado
Keypad teclado = Keypad(makeKeymap(matrizTeclas), pinosLinhas, pinosColunas, LINHAS, COLUNAS);

// --- Configuração dos Pinos de Saída ---
const int pinoLedVerde = 10;
const int pinoLedVermelho = 11;
const int pinoBuzzer = 12;
const int pinoTrava = 13; // Onde o Motor CC (Simulador de Trava) está ligado

// --- Variáveis da Lógica do Cofre ---
String senhaCorreta = "1234"; // Você pode alterar a senha de 4 dígitos aqui
String senhaDigitada = "";

void setup() {
  // Define os pinos como saída
  pinMode(pinoLedVerde, OUTPUT);
  pinMode(pinoLedVermelho, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoTrava, OUTPUT);

  // Garante que tudo comece desligado/fechado
  digitalWrite(pinoLedVerde, LOW);
  digitalWrite(pinoLedVermelho, LOW);
  digitalWrite(pinoTrava, LOW);

  // Inicializa o Display LCD e força a luz de fundo
  lcd.init();
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.display();
  
  // Exibe a mensagem padrão
  telaInicial();
}

void loop() {
  // Lê a tecla pressionada
  char tecla = teclado.getKey();

  if (tecla) {
    // Toca um bipe rápido de retorno (feedback) para confirmar a digitação
    tone(pinoBuzzer, 1000, 50);

    if (tecla == '*') {
      // O asterisco atua como um botão de "Cancelar / Limpar"
      senhaDigitada = "";
      telaInicial();
    }
    else if (tecla == '#') {
      // A hashtag atua como o botão de "Enter / Confirmar"
      verificarSenha();
    }
    else {
      // Se for um número/letra e ainda não tivermos 4 dígitos, adiciona à senha
      if (senhaDigitada.length() < 4) {
        senhaDigitada += tecla;
        
        // Exibe um asterisco no display por questões de segurança (não mostrar a senha)
        // Calcula a posição centralizada (começa na coluna 6 da segunda linha)
        lcd.setCursor(senhaDigitada.length() - 1 + 6, 1); 
        lcd.print("*");
      }
    }
  }
}

// Função para exibir a tela de espera original
void telaInicial() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Digite a Senha:");
  lcd.setCursor(6, 1); // Prepara o cursor para os asteriscos ficarem centralizados
}

// Função responsável por validar o que o usuário digitou
void verificarSenha() {
  if (senhaDigitada == senhaCorreta) {
    // === CENÁRIO: SENHA CORRETA ===
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Senha Correta!");
    lcd.setCursor(2, 1);
    lcd.print("Cofre Aberto");

    // Acende o LED Verde e aciona o Motor (Trava recolhendo)
    digitalWrite(pinoLedVerde, HIGH);
    digitalWrite(pinoTrava, HIGH); 

    // Toca uma melodia de sucesso (dois bipes felizes)
    tone(pinoBuzzer, 1500, 200);
    delay(250);
    tone(pinoBuzzer, 2000, 400);

    // Mantém o cofre aberto por 3 segundos
    delay(3000);

    // Fecha o cofre automaticamente
    digitalWrite(pinoLedVerde, LOW);
    digitalWrite(pinoTrava, LOW);
    
    // Reseta a variável e a tela
    senhaDigitada = "";
    telaInicial();
  }
  else {
    // === CENÁRIO: SENHA INCORRETA ===
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Senha Incorreta!");
    
    // Acende o LED Vermelho para indicar erro
    digitalWrite(pinoLedVermelho, HIGH);

    // Toca um bipe grave indicando acesso negado
    tone(pinoBuzzer, 300, 500);

    // Aguarda 2 segundos para o usuário ver a mensagem
    delay(2000);

    // Apaga a luz e reseta
    digitalWrite(pinoLedVermelho, LOW);
    senhaDigitada = "";
    telaInicial();
  }
}
