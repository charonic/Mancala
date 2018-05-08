# Mancala
Final Documentation 

# What is the Title of your Project:
Dropbead, short and simple and it hearkens to a very commonly played variant of Mancala in the U.S..

# Overview
This project revolves around building a Mancala (subtype Kalah) game using Arduino. If the base system can run, then steps can be taken to eventually make this project more acessible. It is the intent of the project in the long term to imitate the feel of Mancala with appropriate sounds, but the current focus is getting the base game flow down.

# Why did want to make this project?
A cheeky answer is that my dreams are bigger than my hands can hold. The real answer is that when prompted this was the very first thing to pop into my head. Why Mancala over literally anything including refining my Midterm for an easier time? There's no answer, Dropbead can actually be changed to offer ease of access to some folks in the future.

# Form factor/ideal size?
Ideally it would be relatively small, currently I'm thinking about as long as a PS Vita. A refined Dropbead would be wide enough to offer easy access to the inputs and compact enough that it could be easy to move around.
 ## Input
    There are two, the potentiometer and the button. The former will dictate the cursor in the LCD, the latter will fire off the code that moves the beads.
    In a game, a player will be watching an LCD, and will decide which hole they'll move the beads through. Once they decided they'll use the potentiometer to move from hole to hole, once they've reached the desired hole, they'll press the button. The button will fire code that will move the "beads" from hole to hole, automating the process.
### Components:
Potentiometer: Done on the advice of a teacher, the potentiometer will dictate which hole you'll move your "beads" from.
Button : This is more of a future placeholder, in the future, a Dropbead can be modified to compensate for the level of disability its user may or may not have. 

## OutPut
The only output is the LCD, or liquid crystal display. OF the pieces and bits inside the arduino starter kit, only the LCD was capable of displaying anything close to a Mancala board, though in writing this I wonder if I could have used a sound based series of out puts to create a Mancala playable with only sounds and the previous inputs.

## Parts
Potentiometer
Wiring
Resistor
220 ohm resistor
10k ohm resistor
LCD monitor
Button
 

# Research 
## Mancala
This board game has been around for quite some time and has many different variations depending on region. The version being used in this project is Kalah, two rank Mancal.

### The Game
A Kalah board is comprised of six consecutive holes and a store for one side and six consecutive holes and a store for the other.
                                        S1  0 0 0 0 0 0 S2
                                        S1  0 0 0 0 0 0 S2 
Each hole will be filled with 4 beans/beads. A player will strategically move the beans from hole to hole in a counter-clockwise manner, depositing one bean in each hole until they run out. Depositing beans in their own Store gains points, should the player run into the opponent's store, they skip it.

The game itself ends when all six holes on one side of the board are empty. If a player still has beans on their side of the board they score those beans.
The person with the most points in their own store wins.


Seems simple enough, but there are some rules to spice things up.

// instead of buttons, use a potentiometer for selection 

#### The Coding Idea?
#### Coding  
##### Pre void setup:
First, gonna slap in the LCD Library with #include <LiquidCrystal.h>, then you have to tell it what pins you're going to use to interact with the LCD, for this we'll use the following: LiquidCrystal lcd(12,11,5,4,3,2);. 
 * LCD 12: Pin 4
 * LCD 11: Pin ~5
 * LCD 5: Ground
 * LCD 4: Pin 12
 * LCD 3: Potentiometer
 * LCD 2: Power

const int switchPin = 6; for the switch
int switchState = 0; current state of switch 
int prevSwitchState = 0; previous state of switch

int currentStoreCountP1 = 0;
int currentStoreCountP2 = 0;

These integers will hold the score of the game.

##### void setup(){}
pinMode(switchPin,INPUT); telling the arduino that switch pin will be an input.
lcd.begin(16,2); tell the LCD that it'll be firing off on 16 characters horizontally for 2 rows.

This is the basics setup of the "board", this should populate the LCD with numbers the would represent the board state.

 lcd.setCursor(3,0);
  lcd.print("4");

As an example, this would show a 4 (for 4 beads) in pocket 2, it's not in lcd.setCursor(2,0); because the top player's Store should be there.


### Changes

##### Rule 1: Free Turn
If you drop the last of your beans within your own store, you receive an Extra Turn, adding this so that it reflects the same type of Mancala I played would be nice.


##### Rule 2: Capture
Should the last piece you drop land in an empty hole on your side, you capture any pieces in the opponents hole directly opposite to it.
adding this so that it reflects the same type of Mancala I played would be nice.

##### Size 
I would prefer to add a second breadboard devoted just towards the inputs, making a sort of miniature controller or at least moving some of the components so they don't cluster around the initial breadboard.

##### Turn System
Right now the system relies on good faith, making an actual turn order system will make it more official.

##### Button pause
Making the button trigger a pause after every press so that it doesn't actively try to move the same hole twice would be nice, this would be done alongside the Turn System.


