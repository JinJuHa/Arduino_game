int distance = 0; //Cm로 계산된 거리값을 저장해두기위해 변수를 선언합니다.
const int LED_RED = 8;
const int LED_BLUE = 7;

void setup() {
  Serial.begin(9600); //거리값을 PC모니터로 쉽게 확인하기위해 시리얼통신을 선언해줍니다.
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE,  OUTPUT);
}

void loop() {
  int volt = map(analogRead(A0), 0, 1023, 0, 5000); 
  /* 거리값을 cm로 변환해주기 쉽게 하기위해서 map 함수를 사용해서 데이터값을 변환후 volt 변수에 넣어 줍니다.*/ 


  distance = (27.61 / (volt - 0.1696)) * 1000; 
  /*거리값을 cm로 변환하는 계산공식 입니다. 변환된 cm값을 distance 변수에 저장합니다.*/

  if(distance < 30){
    digitalWrite(LED_BLUE, HIGH);
    digitalWrite(LED_RED, LOW);
    //Serial.print(distance);  //거리값을 시리얼모니터로 출력해줍니다.
    Serial.println("1");
    // Serial.println(" ");
  }
  else {
    digitalWrite(LED_BLUE, LOW);
    digitalWrite(LED_RED, HIGH);
    //Serial.print(distance);  //거리값을 시리얼모니터로 출력해줍니다.
    // Serial.println(" cm");
    // Serial.println(" ");
  }

  delay(500);
}