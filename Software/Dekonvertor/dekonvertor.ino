void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  String bin1 = "1001000";
  String bin2 = "1100101";
  String bin3 = "1101100";
  String bin4 = "1101111";

  Serial.println(dek(bin1));
  Serial.println(dek(bin2));
  Serial.println(dek(bin3));
  Serial.println(dek(bin4));
  Serial.println(" ");
  Serial.println(binToDec(bin1));
  Serial.println(binToDec(bin2));
  Serial.println(binToDec(bin3));
  Serial.println(binToDec(bin4));

}


void loop() {
  // put your main code here, to run repeatedly:

}

int dek(String bin)
{
  int decimalniBroj = 0;
  for (int i = 0; i < bin.length(); i++) {
    String bit = String(bin[i]);
    decimalniBroj = decimalniBroj + pow(2*bit.toInt(), bin.length() - 1 - i);
  }

  return decimalniBroj;
}

int binToDec(String binarniZapis) {
  int decimalniBroj = 0;
  int duljina = binarniZapis.length();

  for (int i = 0; i < binarniZapis.length(); i++) {
    char bit = binarniZapis.charAt(i);
    int tezina = binarniZapis.length() - i - 1;

    if (bit == '1') {
      decimalniBroj += 1 << tezina;
    }
  }

  return decimalniBroj;
}