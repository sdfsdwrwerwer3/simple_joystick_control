#define x 5
#define y 6
#define stoped 130
#define max 200
#define min 100

void setup() {
  Serial.begin(9600);

  pinMode(x,OUTPUT);
  pinMode(y,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);

}

void loop() {
  int xr=analogRead(A0);
  int yr=analogRead(A1);

  Serial.print(xr);
  Serial.print(",");
  Serial.println(yr);

  analogWrite(A0,xr);
  analogWrite(A1,yr);
}
