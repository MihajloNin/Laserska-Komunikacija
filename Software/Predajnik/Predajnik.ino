void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, OUTPUT);

  String word = "Hello";
  String binarniZapis = konvert(word);
  Serial.println(" ");
  Serial.print(binarniZapis);
  Serial.println(" ");
  char nizSlova[binarniZapis.length()];
  binarniZapis.toCharArray(nizSlova, binarniZapis.length()+1);

  for(int i = 0; i < binarniZapis.length(); i++)
  {
    if(nizSlova[i] == '1')
    {
      digitalWrite(7, HIGH);
    }
    else
    {
      digitalWrite(7, LOW);
    }
    delay(500);
  }

  digitalWrite(7, LOW);
  }

void loop() 
{
  // put your main code here, to run repeatedly:
  // digitalWrite(7, HIGH);
}

String konvert(String rec)
{
  String binary[rec.length()];
  String binarnaRec = "1";

  for (int i = 0; i < rec.length(); i++) {
    int asciiValue = rec.charAt(i); // Dobijanje ASCII vrednosti pojedinačnog karaktera

    String binslovo = "";
    for (int i = 6; i >= 0; i--) {
      int bit = (asciiValue >> i) & 1;
      binslovo = binslovo + String(bit);
    }
    binary[i] = binslovo;
    binarnaRec = binarnaRec + binary[i];
  }

  binarnaRec = binarnaRec + "0000011";

  return binarnaRec;
}