const int voltIn = A5;
byte incoming_val = 0;
bool isStart = false;
float values[10];
float sum = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(voltIn, INPUT);
}

void loop() 
{
  if(Serial.available() > 0)
  {
    incoming_val = Serial.read();
    if(incoming_val == '1')
    {
      isStart = true;
    }
    else if(incoming_val == '0')
    {
      isStart = false;
    }
  }

  if(isStart == true) 
  {
    for(int j = 0; j < 10; j++) 
    {
      values[j] = analogRead(voltIn);
      delay(25);
    }

    for(int j = 0; j < 10; j++) 
    {
      sum += values[j];
    }

    sum /= 10;

    Serial.println(analogRead(voltIn));

    delay(100);
  }
  
}


