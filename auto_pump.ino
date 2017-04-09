/**
 * 自动水泵，水位高于一定值时启动水泵，低于时延时关闭水泵
 * 2017-4-9
 * author: jlbnet
 */

int sensorPin = A0; //模拟输入A0
int PUMP_PIN  = 5; //pin5 输出
int LED_PIN = 6; //led指示输出
int sensorValue = 0; //输入的值
bool pumping = false; //是否正在抽水

char buf[128];

void setup() {
  // put your setup code here, to run once:
  pinMode(PUMP_PIN, OUTPUT);  //输出模式
  pinMode(LED_PIN, OUTPUT); //led输出脚，输出模式
  //pinMode(sensorPin, INPUT);
  stop();
  //start();
  Serial.begin(9600);
}

//启动水泵
void start() {
  digitalWrite(PUMP_PIN, LOW); //输出
  digitalWrite(LED_PIN, HIGH); //led点亮
}

//停止水泵
void stop() {
  digitalWrite(PUMP_PIN, HIGH); //关闭
  digitalWrite(LED_PIN, LOW); //关闭led
}

void loop() {
  // put your main code here, to run repeatedly:
  //检测水位传感器输入
  sensorValue = analogRead(sensorPin);
  snprintf(buf, sizeof(buf), "water level: %d", sensorValue);
  Serial.println(buf);
  //水位
  //最低1档：60k, 877
  //有水2档，30k, 767
  //有水3档，20k, 682
  //有水4档，10k, 512
  //最低1档时(>860)，停止水泵，不再抽水
  //高于4档时(<600)，开始水泵抽水
  if(sensorValue > 860 && pumping) {
    //水位低，不抽水
    stop();
    pumping = false;
    delay(5000);
    return;
  }
  if(sensorValue<600 && !pumping) {
    //水位高，开始抽水
    start();
    pumping = true;
    delay(6000);
    return;
  }
  delay(500);
  //Serial.write("start pump ...\n");
  //start();
  //delay(3000);
  //Serial.write("stop pump ...\n");
  //stop();
  //delay(3000);
}
