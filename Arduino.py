// codigo seguidor de linha para Arduino Nano
// Javier Agustin Aranibar González

// Definição dos pinos dos sensores e LED
#define sensor1 A0 // Define o pino do sensor 1
#define sensor2 A1 // Define o pino do sensor 2
#define led 13     // Define o pino do LED

// Definição dos pinos de Controle do motor
#define ENA 11    // Porta PWM
#define ENB 10    // Porta PWM
#define IN1 13    // IN1 e LED compartilham o pino 13
#define IN2 12
#define IN3 9
#define IN4 8

void setup() {
  // Configuração dos sensores e LED
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(led, OUTPUT);

  // Configuração dos pinos de controle do motor
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // Leitura dos sensores
  bool isLineDetected1 = digitalRead(sensor1) == HIGH; // Linha preta detectada pelo sensor 1
  bool isLineDetected2 = digitalRead(sensor2) == HIGH; // Linha preta detectada pelo sensor 2

  // Se ambos os sensores detectarem a linha preta
  if (isLineDetected1 && isLineDetected2) {
    // Acende o LED e liga o motor
    digitalWrite(led, HIGH);

    // Motor move para frente
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
  } else {
    // Apaga o LED e para o motor
    digitalWrite(led, LOW);

    // Motor para
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
  }

}

