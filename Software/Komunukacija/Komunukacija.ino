void setup() 
{
  Serial.begin(9600); // Inicijalizacija serijske komunikacije
  String word = "Hello"; // Reč za konvertovanje
  
  String binary[word.length()];

  for (int i = 0; i < word.length(); i++) {
    int asciiValue = word.charAt(i); // Dobijanje ASCII vrednosti pojedinačnog karaktera

    String binslovo;
    for (int i = 7; i >= 0; i--) {
      int bit = (asciiValue >> i) & 1;
      binslovo = binslovo + String(bit);
    }
    binary[i] = binslovo;
  }

  for (int l = 0; l < word.length(); l++)
  {
    Serial.print(binary[l]);
    Serial.print(" ");
  }
}

void loop() {

}
