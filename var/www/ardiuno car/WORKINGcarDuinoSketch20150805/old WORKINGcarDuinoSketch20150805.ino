char c;
void setup(){
  Serial.begin(9600);
  Serial.println("program started");
  pinMode(9, OUTPUT);  // 9  = forward pin - used by f and g
  pinMode(10, OUTPUT); // 10 = right pin - used by r and s
  pinMode(11, OUTPUT); // 11 = left pin - used by l and m
  pinMode(12, OUTPUT); // 12 = backward pin - used by b and c
}

void loop(){
if (Serial.available() > 0)
  {
  c = Serial.read();
  Serial.println(c);
}

if (c=='f')
  {
  digitalWrite(9, HIGH);
}
if (c=='g')
  {
  digitalWrite(9, LOW);
}
if (c=='b')
  {
  digitalWrite(12, HIGH);
}
if (c=='c')
  {
  digitalWrite(12, LOW);
}
if (c=='l')
  {
  digitalWrite(11, HIGH);
}
if (c=='m')
  {
  digitalWrite(11, LOW);
}
if (c=='r')
  {
  digitalWrite(10, HIGH);
}
if (c=='s')
  {
  digitalWrite(10, LOW);
}
}
