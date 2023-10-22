int velocidade = 0;
int incremento;
int decremento;
int desliga;
int motor = 3;

void setup() {
  Serial.begin(9600);
    pinMode(5, INPUT_PULLUP);
    pinMode(6, INPUT_PULLUP);
    pinMode(9, INPUT_PULLUP);
    pinMode(motor, OUTPUT);
}

void loop() {
  decremento = digitalRead(5);
  incremento = digitalRead(9);
  desliga = digitalRead(6);
  Serial.println(incremento);
  
  if(desliga != 1){
      velocidade = 0;
  }
    if(incremento != 1){
      velocidade++;
    }
  
    
    if (decremento != 1){
      velocidade--;
    }
    
    
    if(velocidade > 255){
      velocidade = 255;
    }
 
  
    if(velocidade < 0){
      velocidade = 0;
    }
    analogWrite(motor,velocidade);
  }
