int NSred1 = 10;
int NSyellow1 = 9;
int NSgreen1 = 8;

int WEred1 = 7;
int WEyellow1 = 6;
int WEgreen1 = 5;

int HighLowToggle = 0;
int bootFlag = 1;

void setup(){
    pinMode(NSred1, OUTPUT);
    pinMode(NSyellow1, OUTPUT);
    pinMode(NSgreen1, OUTPUT);
    pinMode(WEred1, OUTPUT);
    pinMode(WEyellow1, OUTPUT);
    pinMode(WEgreen1, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    startup();
}

void loop(){
    
    heartbeat();
    switchLights(1,0,0, 0,0,1);
    delay(15000);
   
    heartbeat();
    switchLights(1,0,0, 0,1,0);
    delay(2500);

    heartbeat();
    switchLights(1,0,0, 1,0,0);
    delay(1500);

    heartbeat();
    switchLights(0,0,1, 1,0,0);
    delay(15000);

    heartbeat();
    switchLights(0,1,0, 1,0,0);
    delay(2500);

    heartbeat();
    switchLights(1,0,0, 1,0,0);
    delay(1500);
 
}

void startup(){
  if (bootFlag ==1) {
    bootFlag = 0;
      for (unsigned int i = 0; i < 2; ++i) {
        heartbeat();
        switchLights(1,1,1, 1,1,1);
        delay(1000);  
       
        switchLights(0,0,0, 0,0,0);
        heartbeat();
        delay(1000);

        switchLights(1,0,0, 0,0,1);
        heartbeat();
        delay(1000);

        switchLights(0,1,0, 0,1,0);
        heartbeat();
        delay(1000);

        switchLights(0,0,1, 1,0,0);
        heartbeat();
        delay(1000);

        switchLights(0,0,0, 0,0,0);
        heartbeat();
        delay(1000);
      }
      
  }
  
}
void heartbeat(){
    if (HighLowToggle == 1) {
      HighLowToggle = 0;
      digitalWrite(LED_BUILTIN, LOW);
    }
    else {
      HighLowToggle = 1;
      digitalWrite(LED_BUILTIN, HIGH);
    }
    
}

void switchLights(int lNSred1,int lNSyellow1, int lNSgreen1, int lWEred1,int lWEyellow1, int lWEgreen1 ){
    digitalWrite(NSred1, lNSred1);
    digitalWrite(NSyellow1, lNSyellow1);
    digitalWrite(NSgreen1, lNSgreen1);

    digitalWrite(WEred1, lWEred1);
    digitalWrite(WEyellow1, lWEyellow1);
    digitalWrite(WEgreen1, lWEgreen1);


}

