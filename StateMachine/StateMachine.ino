
#include "Arduino.h"

class StateMachine
{
  public:
    int clearState(){
       state=0;
      
    };
    int changeState(int param){
      lastState=state;
      state=transtionFunction[state][param];
      return state;
    };
    int getState(){return state;};
  private:
    int state =0;
    int transtionFunction [6][2] = { {1, 0},
                                     {2, 0},
                                     {3, 1},
                                     {4, 2},
                                     {5, 3},
                                     {0, 4},
    };
    int lastState;
};
StateMachine stateMachine;

const int butPin0 = 11;
int butState0 = LOW;
const int butPin1 = 12;
int butState1 = LOW;

void setup() {
    // initialize the pushbutton pin as an input:
  pinMode(butPin0, INPUT);
  pinMode(butPin1, INPUT);
  Serial.begin(9600);
}

void loop() {
    butState0 = digitalRead(butPin0);
    butState1 = digitalRead(butPin1);
    if (butState0 == HIGH){
      stateMachine.changeState(0);
      Serial.println("botao 0 pressionado estado %d"+ String(stateMachine.getState()));
    }else{
      //
    }
    if (butState1 == HIGH){
       stateMachine.changeState(0);
      Serial.println("botao 1 pressionado estado %d"+ String(stateMachine.getState()));
    }else{
      //
    }
}
