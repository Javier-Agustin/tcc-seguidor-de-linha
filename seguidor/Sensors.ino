
int v_s_min[6] = { 1023, 1023, 1023, 1023, 1023, 1023 };
int v_s_max[6] = { 0, 0, 0, 0, 0, 0 };
volatile int s_p[6];
boolean online;

int pos;
int l_pos;


void calibracion() {

  int v_s[6];

  for (int j = 0; j < 300; j++) {
    delay(30);
    v_s[0] = analogRead(A0);
    v_s[1] = analogRead(A1);
    v_s[2] = analogRead(A2);
    v_s[3] = analogRead(A3);
    v_s[4] = analogRead(A4);
    v_s[5] = analogRead(A5);

    for (int i = 0; i < 6; i++) {

      Serial.print(v_s[i]);
      Serial.print("\t");
    }
    Serial.println();

    for (int i = 0; i < 6; i++) {
      if (v_s[i] < v_s_min[i]) {
        v_s_min[i] = v_s[i];
      }
    }


    for (int i = 0; i < 6; i++) {
      if (v_s[i] > v_s_max[i]) {
        v_s_max[i] = v_s[i];
      }
    }
  }


  Serial.print("Minimos");
  Serial.print("\t");

  for (int i = 0; i < 6; i++) {
    Serial.print(v_s_min[i]);
    Serial.print("\t");
  }
  Serial.println();

  Serial.print("Maximos");
  Serial.print("\t");

  for (int i = 0; i < 6; i++) {
    Serial.print(v_s_max[i]);
    Serial.print("\t");
  }
}

void readSensors() {

  volatile int s[6];



  s[0] = analogRead(A0);
  s[1] = analogRead(A1);
  s[2] = analogRead(A2);
  s[3] = analogRead(A3);
  s[4] = analogRead(A4);
  s[5] = analogRead(A5);

  

  for (int i = 0; i < 6; i++) {
    if (s[i] < v_s_min[i]) {
      s[i] = v_s_min[i];
    }

    if (s[i] > v_s_max[i]) {
      s[i] = v_s_max[i];
    }
    s_p[i] = map(s[i], v_s_min[i], v_s_max[i], 100, 0);
  }


  volatile int sum = s_p[0] + s_p[1] + s_p[2] + s_p[3] + s_p[4] + s_p[5];
  if (sum > 100) {
    online = 1;
    Serial.println("estou aqui");
    Serial.println(sum);

  } else {

    Serial.println("opa");
    online = 0;
    sum = 100;
  }


  if (online) {
  /*Serial.println("Detectando linha!");
  for (int i = 0; i < 6; i++) {
    Serial.print("Sensor ");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(s_p[i]);
    Serial.print("\t");
  }
  Serial.println();  // Salto de linha após imprimir os valores
} else {
  Serial.println("Fora da linha.");*/
}



}




int GetPos() {
  readSensors();
  int prom = -2.5 * s_p[0] - 1.5 * s_p[1] - 0.5 * s_p[2] + 0.5 * s_p[3] + 1.5 * s_p[4] + 2.5 * s_p[5];
  int sum = s_p[0] + s_p[1] + s_p[2] + s_p[3] + s_p[4] + s_p[5];

  if (online) {
    pos = int(100.0 * prom / sum);
  } else {
    if (l_pos < 0) {
      pos = -255;
    }
    if (l_pos >= 0) {
      pos = 255;
    }
  }
  l_pos = pos;
  return pos;
}
