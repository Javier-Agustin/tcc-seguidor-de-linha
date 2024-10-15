
int fin = 0;

int velo = 0;

int l_geo, ll_geo, lll_geo;

int umbral = 505;
int geo = 0;

int HL, HR = 0;

void Read_hits() {

  HL = analogRead(A6);
  HR = analogRead(A7);

  if (HL > umbral) {
    HL = 0;
   // digitalWrite(PINLED, LOW);
  } else {
    HL = 1;
  //  digitalWrite(PINLED, HIGH);
  }

  if (HR > umbral) {
    HR = 0;
  //  digitalWrite(PINLED, LOW);
  } else {
    HR = 1;
  //  digitalWrite(PINLED, HIGH);
  }

  /*Serial.print(HR);
  Serial.print("   ");
  Serial.print(HL);
  Serial.print("   ");
  Serial.print(analogRead(A6));
  Serial.print("   ");
  Serial.print(analogRead(A7));
  Serial.println();*/
}

void detectGeo() {

  Read_hits();


  if ((HL == 0) && (HR == 0)) {
    geo = 0;
  }

  if ((HL == 1) && (HR == 0)) {
    geo = 1;
  }

  if ((HL == 0) && (HR == 1)) {
    geo = 2;
  }

  if ((HL == 1) && (HR == 1)) {
    geo = 3;
  }

  if (l_geo != geo) {




    if (geo == 0 && l_geo == 2 && ll_geo == 0) {

      funcion_HL();
    }
    if (geo == 0 && l_geo == 1 && ll_geo == 0) {

      funcion_HR();
    }

    if (geo == 0 && ((l_geo == 3) || (ll_geo == 3) || (lll_geo == 3))) {

      funcion_Cruce();
    }
    lll_geo = ll_geo;
    ll_geo = l_geo;
    l_geo = geo;
  }

 /* Serial.print(geo);
  Serial.println();
  Serial.print(fin);
  Serial.println();
  Serial.print(velo);
  Serial.println();*/
}

void funcion_HL() {

  fin++;

  switch (fin) {
    case 2:
      base = velocidad_3;
      delay(150);
      base = 0;
      Motores(0, 0);
      delay(15000);
      break;
    default:
      // if nothing else matches, do the default
      // default is optional
      break;
  }
}

void funcion_HR() {

  /*velo++;

  switch (velo) {
    case 18:
      base = velocidad_5;
      break;
    case 24:
      base = velocidad_5;
      break;

    default:
      // if nothing else matches, do the default
      // default is optional
      break;
  }

  Serial.print(fin);
  Serial.println();*/
}


void funcion_Cruce() {

}
