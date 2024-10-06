//setarea pinilor + variabile//
int buttonPin=2;
volatile int state=LOW;
int led=13;
int temp_ext=A4;
int temp_int=A5;
float temp;

///RGB exterior
int rosu_exterior= 6;
int verde_exterior = 5;
int albastru_exterior = 3;
///END RGB ESTERIOR


///RGB Interior
int rosu_interior= 9;
int  verde_interior = 10;
int albastru_interior = 11;
///END RGB INTERIOR


//END setare pini//////

void setup()
{
  //Setare out RGB interior si exterior.
  pinMode(rosu_exterior, OUTPUT);
  pinMode(verde_exterior, OUTPUT);
  pinMode(albastru_exterior, OUTPUT);
  
  pinMode(rosu_interior, OUTPUT);
  pinMode(verde_interior, OUTPUT);
  pinMode(albastru_interior, OUTPUT);
  //END Setare out RGB interior si exterior.
  
  pinMode(led,OUTPUT); //setare led rosu extern ca output
  pinMode(buttonPin,INPUT);
  Serial.begin(9600);//serial- nu-l vom folosi decat la testare
   attachInterrupt(digitalPinToInterrupt(buttonPin) ,asd, CHANGE);
}

void asd()
{
state= !state; //daca  e dif de state (cazul nostru Low/HIGH)
}

void loop()
{
  if(state==HIGH) //daca e apasat butonul
  {
  digitalWrite(led,state);
    ////cod pentru temperatura 
  interior();
  exterior();
  }
   
  else if(state==LOW)//daca nu se apasa butonul
  {
    digitalWrite(led,LOW);//stinge ledul
  }
}


void exterior()
{
  //senzor temperatura///////
  temp = analogRead(temp_ext);
   temp = temp * 0.48828125; 
   Serial.print("TEMPERATURE = ");
   Serial.print(temp);
   Serial.print("*C");
   Serial.println();
   delay(1000);
  //END senzor temperatura///
  
  if(temp<20) //daca temperatura e mai mica sau egale de 20C
  {
   RGB_ext(0, 0, 255); // aprinde albastru exterior
    delay(1000);
  }
  
  else if((temp>20) && (temp<=35))//Daca temperatura e normala
  {
    RGB_ext(0, 255, 0); // aprinde verde exterior
    delay(1000);
  }
  
  else if(temp>35)//Daca temp. e mai mare de 35.
  {
    RGB_ext(255, 0, 0); // aprinde verde exterior
    delay(1000);
  }
  
  
  
}

void interior()
{
//senzor temperatura///////
  temp = analogRead(temp_ext);
   temp = temp * 0.48828125; 
   Serial.print("TEMPERATURE = ");
   Serial.print(temp);
   Serial.print("*C");
   Serial.println();
   delay(1000);
  //END senzor temperatura///
  
  if(temp<20) //daca temperatura e mai mica sau egale de 20C
  {
    RGB_int(0, 0, 255); // aprinde albastru exterior
    delay(1000);
  }
  
  else if((temp>20) && (temp<=35))//Daca temperatura se afla intre 20C si 35C
  {
    RGB_int(0, 255, 0); // aprinde verde exterior
    delay(1000);
  }
  
  else if(temp>35)//Daca temp. e mai mare de 35.
  {
    RGB_int(255, 0, 0); // aprinde rosu exterior
    delay(1000);
  }
  
    
}
  

//functie pentru culori RGB EX?TERIOR
void RGB_ext(int rosu_exterior_val, int verde_exterior_val, int albastru_exterior_val)
 {
  analogWrite(rosu_exterior, rosu_exterior_val);
  analogWrite(verde_exterior, verde_exterior_val);
  analogWrite(albastru_exterior, albastru_exterior_val);
}
//END Functi culori rgb EXTERIOR


//functie pentru culori RGB INTERIOR
void RGB_int(int rosu_interior_val, int verde_interior_val, int albastru_interior_val)
 {
  analogWrite(rosu_interior, rosu_interior_val);
  analogWrite(verde_interior, verde_interior_val);
  analogWrite(albastru_interior, albastru_interior_val);
}
//END Functi culori rgb INTERIOR
