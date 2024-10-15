


# define AIN1 12    // pin 1 de dirección del Motor Izquierdo
# define AIN2 13   // pin 2 de dirección del Motor Izquierdo
# define PWMA 11   // pin PWM del Motor Izquierdo


# define BIN1 8    // pin 1 de dirección del Motor Derecho
# define BIN2 9    // pin 2 de dirección del Motor Derecho
# define PWMB 10    // pin PWM del Motor Derecho


void HL298n_init() {

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

}

void MotorEsquerda(int value) {
  if (value >= 0) {
    // si valor positivo vamos hacia adelante

    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
  } else {
    // si valor negativo vamos hacia atras

    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    value *= -1;
  }
  analogWrite(PWMA, value);
}


void MotorDireita(int value) {
  if (value >= 0) {
    // si valor positivo vamos hacia adelante

    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
  } else {
    // si valor negativo vamos hacia atras

    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    value *= -1;
  }
  analogWrite(PWMB, value);
}


void Motores(int left, int right) {
  MotorEsquerda(left);
  MotorDireita(right);
}
