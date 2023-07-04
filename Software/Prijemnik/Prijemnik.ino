int sensorPin = A0;
int sensorValue = 0;
bool startRead = false;
int brojac = 1;
String slovo = "";
int asciiBroj = 0;
char karakter;

void setup(void) {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}
 
void loop(void) {
  sensorValue = analogRead(sensorPin);
  if(startRead == true)
  {
    if(sensorValue > 0)
    {
      //Serial.print(1);
      slovo = slovo + "1";
    }
    else
    {
      //Serial.print(0);
      slovo = slovo + "0";
    }
  }
  else
  {
    if(sensorValue > 0)
    {
      startRead = true;
    }
  }

  //DO OVDE RADI

  if(brojac == 7)
  {
    asciiBroj = binToDec(slovo);
    //Serial.println(asciiBroj);

    if(asciiBroj == 3)
    {
      exit(0);
    }
    else
    {
      karakter = (char)asciiBroj;
      //Serial.print(karakter);
    }

    brojac = 1;
    slovo = "";
  }
  else
  {
    brojac++;
  }

  delay(500);
}

int binToDec(String binarniZapis) {
  int decimalniBroj = 0;

  /*
  for (int i = 0; i < binarniZapis.length(); i++) {
    String bit = String(binarniZapis[i]);
    decimalniBroj = decimalniBroj + pow(2*bit.toInt(), binarniZapis.length() - i - 1);
  }
  */
  //Serial.print(decimalniBroj);

  for (int i = 0; i < binarniZapis.length(); i++) {
    char bit = binarniZapis.charAt(i);

    if (bit == '1') {
      decimalniBroj += 1 << (binarniZapis.length() - i - 1);
    }
  }
  Serial.println(decimalniBroj);
  return decimalniBroj;
}