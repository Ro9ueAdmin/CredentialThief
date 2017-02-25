char c;
void setup(){
  Serial.begin(9600);
  Serial.println("program started");
  pinMode(12, OUTPUT); // backward pin - used by b and c
  pinMode(11, OUTPUT); // left pin - used by l and m
  pinMode(10, OUTPUT); // right pin - used by r and s
  pinMode(9, OUTPUT);  // forward pin - used by f and g
}

void loop(){
if (Serial.available() > 0)
  {
  c = Serial.read();
  Serial.println(c);
}
else
  {
  delay(100);
}
if (c=='f')
  {
  Serial.println("forward on");
  digitalWrite(9, HIGH);
}
if (c=='g')
  {
  Serial.println("forward off");
  digitalWrite(9, LOW);
}
if (c=='b')
  {
  Serial.println("back on");
  digitalWrite(12, HIGH);
}
if (c=='c')
  {
  Serial.println("back off");
  digitalWrite(12, LOW);
}
if (c=='l')
  {
  Serial.println("left on");
  digitalWrite(11, HIGH);
}
if (c=='m')
  {
  Serial.println("left off");
  digitalWrite(11, LOW);
}
if (c=='r')
  {
  Serial.println("right on");
  digitalWrite(10, HIGH);
}
if (c=='s')
  {
  Serial.println("right off");
  digitalWrite(10, LOW);
}
c='\0';
}
