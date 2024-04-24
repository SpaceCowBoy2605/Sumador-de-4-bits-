// pines del primer display
const int pin1 = 22;
const int pin2 = 23;
const int pin3 = 24;
const int pin4 = 25;
const int pin5 = 26;
const int pin6 = 27;
const int pin7 = 28;

// pines del segundo display
const int pon1 = 29;
const int pon2 = 30;
const int pon3 = 31;
const int pon4 = 32;
const int pon5 = 33;
const int pon6 = 34;
const int pon7 = 35;

const int botones1[] = {37, 38, 39, 40};
const int botones2[] = {41, 42, 43, 44};

void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);

  pinMode(pon1, OUTPUT);
  pinMode(pon2, OUTPUT);
  pinMode(pon3, OUTPUT);
  pinMode(pon4, OUTPUT);
  pinMode(pon5, OUTPUT);
  pinMode(pon6, OUTPUT);
  pinMode(pon7, OUTPUT);


  for (int i = 0; i < 4; i++) {
    pinMode(botones1[i], INPUT);
  }


  for (int i = 0; i < 4; i++) {
    pinMode(botones2[i], INPUT);
  }
}

void loop() {

  int sum1 = 0;
  for (int i = 0; i < 4; i++) {
    sum1 += digitalRead(botones1[i]) << i;
  }

  int sum2 = 0;
  for (int i = 0; i < 4; i++) {
    sum2 += (digitalRead(botones2[i]) << i);
  }

  // Calcular la suma total
  int totalSum = sum1 + sum2;

  // Mostrar la suma total con dos dígitos en ambos displays
  mostrarNumero(totalSum % 10, pin1, pin2, pin3, pin4, pin5, pin6, pin7);
  mostrarNumero(totalSum / 10, pon1, pon2, pon3, pon4, pon5, pon6, pon7);
  delay(1000); 
}

// mostrar los numeros del display
void mostrarNumero(int num, const int pin1, const int pin2, const int pin3, const int pin4, const int pin5, const int pin6, const int pin7) {
  const byte numbers[][7] = {
    {1, 1, 1, 1, 1, 1, 0},  // 0
    {0, 1, 1, 0, 0, 0, 0},  // 1
    {1, 1, 0, 1, 1, 0, 1},  // 2
    {1, 1, 1, 1, 0, 0, 1},  // 3
    {0, 1, 1, 0, 0, 1, 1},  // 4
    {1, 0, 1, 1, 0, 1, 1},  // 5
    {1, 0, 1, 1, 1, 1, 1},  // 6
    {1, 1, 1, 0, 0, 0, 0},  // 7
    {1, 1, 1, 1, 1, 1, 1},  // 8
    {1, 1, 1, 1, 0, 1, 1}   // 9
  };

  digitalWrite(pin1, numbers[num][0]);
  digitalWrite(pin2, numbers[num][1]);
  digitalWrite(pin3, numbers[num][2]);
  digitalWrite(pin4, numbers[num][3]);
  digitalWrite(pin5, numbers[num][4]);
  digitalWrite(pin6, numbers[num][5]);
  digitalWrite(pin7, numbers[num][6]);
}




