const int sensor_pin = A0; // 조도센서 핀 번호
const int threshold = 500; // 테스트 시작 임계값
bool testing_is_started = false; // 테스트가 시작되었는지 여부를 저장하는 변수

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensor_value = analogRead(sensor_pin); // 조도센서 값을 읽어옵니다.
  
  if (!testing_is_started) { // 테스트가 시작되지 않은 경우
    if (sensor_value > threshold) { // 조도센서 값이 임계값 이상인 경우
      Serial.println("Test started");
      testing_is_started = true;
    }
  } else { // 테스트가 시작된 경우
    if (sensor_value <= threshold) { // 조도센서 값이 임계값 이하인 경우
      Serial.println("Test finished");
      while (true); // 프로그램을 멈춥니다.
    }
  }
}
