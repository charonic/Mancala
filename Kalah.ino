/*
  Player Turn
  Scoring
  confirm button+pot-meter
  Extra Turn

*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String inputString = "";
boolean stringComplete = false;



int mancalaGame[] = {0, 4, 4, 4, 4, 4, 4, 0, 4, 4, 4, 4, 4, 4}; /*8-13 =p2*/
int player1goal = 0;
int player2goal = 7;

int player1score;
int player2score;

boolean gameOver = false;

int potPin = 8;
int confirmButton = 9;
int buttonState = 0;
int val;

boolean movebead = false;
void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  curPlayerTurn = 1;
  

  pinMode(confirmButton, INPUT);
  pinMode(12, OUTPUT);

}




void loop() {
  lcd.noBlink();
  delay(3000);
  lcd.blink();
  delay(3000);
  val = analogRead(potPin);
  val = map(val, 0, 1023, 0, 13);

  buttonState = digitalRead(confirmButton);

  if(buttonState == HIGH){

   if (gameOver != true) {
    if (stringComplete == true || movebead == true){
      movebead = false;
      Serial.println(inputString);
    // clear the string:
    int arraySelector = inputString.toInt();
    if (arraySelector >= 0 && arraySelector <= 13) {
      if (arraySelector == player1goal || arraySelector == player2goal) {
        lcd.clear();
        lcd.print("Can't choose");
        lcd.setCursor(0, 1);
        lcd.print(" goals");
        Serial.println("Cant choose goals");
      } else {
        lcd.clear();
        lcd.print(mancalaGame[arraySelector]);
        Serial.println(mancalaGame[arraySelector]);
        int curBoxValue = mancalaGame[arraySelector];
        mancalaGame[arraySelector] = 0;
        for (int i = 0; i < curBoxValue; i++) {
          int curPosition = arraySelector + 1 + i; /* if curPosition > 13, then curPosition = 0;  once it becomes greater than 13, reset curPosition to 0, i needs to be reset, take the current i, subtract 1 from it. try i - 1. */
          mancalaGame[curPosition] =  mancalaGame[curPosition] + 1;

     if (curPosition > 13) {
      int curPosition = 0 + i - 1;   

        }
      }

  }

    }

    
void whoWon() { /*function definition not allowed before {*/
  if (mancalaGame[1] == 0 && mancalaGame[2] == 0 && mancalaGame[3] == 0 && mancalaGame[4] == 0 && mancalaGame[5] == 0 && mancalaGame[6] == 0) {
    gameOver = true;
  } else if (mancalaGame[8] == 0 && mancalaGame[9] == 0 && mancalaGame[10] == 0 && mancalaGame[11] == 0 && mancalaGame[12] == 0 && mancalaGame[13] == 0) {
    gameOver = true;
  }
  
    inputString = "";
    stringComplete = false;

   /*8 for (int z = 0; z < 14; z++ ) {
      Serial.print("Pos ");
      Serial.print(z);
      Serial.print(" : ");
      Serial.print(mancalaGame[z]);
      Serial.print(", ");
    }
    Serial.println(); */

  /* else if {( mancalaGame[1] != 0 && mancalaGame[2] != 0 &&  mancalaGame[3] != 0 && mancalaGame[4] != 0 && mancalaGame[5] != 0 && mancalaGame[6] != 0 && mancalaGame[8] != 0 && mancalaGame[9] != 0 && mancalaGame[10] != 0 && mancalaGame[11] != 0 && mancalaGame[12] != 0 && mancalaGame[13] != 0) { gameOver != true;}}
    } */
 
    /*gameOver(whoWon());} /*probably add actual code here.*/
  } 

   if (gameOver = true && player1score > player2score) {
    lcd.clear();
    lcd.print("Player 1 wins!");

  } else {
    if (gameOver = true && player2score > player1scorel) {
      lcd.clear();
      lcd.print("Player 2 Wins!");
    }

  
  


  //look at examples, pressed example, pressed should run the move function, 
  // once button works, take out the Serials.
 

    }
  } 

}

}
}/* closes loop*/

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
  }
//everytime someone makes a move, check who won, anytime a person clicks a button, check who won.
