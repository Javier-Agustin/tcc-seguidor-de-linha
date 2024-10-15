#define PINLED 13

int velocidad_0 = 0;
int velocidad_1 = 50;
int velocidad_2 = 70;
int velocidad_3 = 100;
int velocidad_4 = 120;
int velocidad_5 = 140;
int velocidad_6 = 180;
int velocidad_7 = 200;

int posicion_ideal = 0;


float Kprop = 1.5;
float Kderiv = 12.5;

int base = velocidad_4;
int error_pasado = 0;


void setup() {
  Serial.begin(115200);
  HL298n_init();
  
  delay(700);

  Motores(0, 0);

  delay(700);
  digitalWrite(PINLED, HIGH);
  
  calibracion();
  digitalWrite(PINLED, LOW);
  delay(1000);
  digitalWrite(PINLED, HIGH);
  base = velocidad_4;
  delay(1000);
  digitalWrite(PINLED, LOW);
}


void loop() {

  int p = GetPos();

  detectGeo();

  int error = p - posicion_ideal;
  int d_error = error - error_pasado;
  int correction_power = int(Kprop * error) + int(Kderiv * (d_error));


  if (correction_power > 255)
   {
    correction_power = 255;
  }

  else if (correction_power < -255) 
  {
    correction_power = -255;
  }

  Motores(base + correction_power, base + -correction_power);
  error_pasado = error;
}
