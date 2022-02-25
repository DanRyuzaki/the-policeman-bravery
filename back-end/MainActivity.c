/*** Robot Story Making : R3C Camp & Coding Competition
   Theme : A Hero Saves The Day
   Title : The Policeman Bravery
   Senior Coders
   Team Camarin High School (CHS)
   John Leinard Flores
   Danielle Adan ***/

int LRmotorsSpeedGlobalReciever = 100, //recieves the recommended speed of the robot for every scene or crossline, default : 100
    LmotorsSpeedGlobalReciever = 100,//recieves the recommended speed of the robot for every scene or crossline, default : 100
    RmotorsSpeedGlobalReciever = 100,//recieves the recommended speed of the robot for every scene or crossline, default : 100
    whiteLineColorValue = 0512, //white line color value
    intCrosslineCounter, //storage for crossline counter
    storeAnalog0and4, // stores and sum of the 2 major sensors or analogs
    pa0,pa4,pa8; //analogs

double sceneGlobalReciever; //recieves which scene is currently visualizing

void setup(){ //Main Activity
}

void loop(){
    //Main Activity: Loop
    //All voids and functions will be declared here
    basicLineTracingActivity(); //major activity
    basicCrosslineTracingActivity(); //major activity
    endingSceneActivity(storeAnalog0and4, 185000); //sub activity
    sceneNumberLCDActivity(sceneGlobalReciever); //sub activity   
}


void basicLineTracingActivity(){
    //One Straight line tracing Activity
    pa0 = analog(0); pa4 = analog(4); pa8 = analog(8);
    if((pa0 > whiteLineColorValue))
    {
         tl(LmotorsSpeedGlobalReciever); 
         storeAnalog0and4++; //store how many times pa0 hit the white lines
    }else if((pa4 > whiteLineColorValue)){
        tr(RmotorsSpeedGlobalReciever); 
        storeAnalog0and4++; //store how many times pa0 hit the black lines
    }else{
        fd(LRmotorsSpeedGlobalReciever); 
    }
}

void basicCrosslineTracingActivity(){
    //crossline tracing Activity
   pa0 = analog(0); pa4 = analog(4); pa8 = analog(8);

    if(pa0 > whiteLineColorValue && pa4 > whiteLineColorValue){
        intCrosslineCounter++;
        switch(intCrosslineCounter){

          case 1:
          sceneGlobalReciever = 1;
          LRmotorsSpeedGlobalReciever = 50;
          fd(LRmotorsSpeedGlobalReciever); sleep(790);
          sr(RmotorsSpeedGlobalReciever); sleep(651);
        break;

          case 2:
          sceneGlobalReciever = 2;
          LRmotorsSpeedGlobalReciever = 100;
          fd(LRmotorsSpeedGlobalReciever); sleep(170);
          LRmotorsSpeedGlobalReciever = 100;
        break;
        
          case 3:
          sceneGlobalReciever = 2.5; 
          fd(LRmotorsSpeedGlobalReciever);sleep(510);
          sr(RmotorsSpeedGlobalReciever); sleep(701);
          LRmotorsSpeedGlobalReciever = 50;
        break;

          case 4:
          sceneGlobalReciever = 3;
          fd(LRmotorsSpeedGlobalReciever); sleep(1470);
        break;
         
          case 5:
          sceneGlobalReciever = 4;
          LRmotorsSpeedGlobalReciever = 10;
          RmotorsSpeedGlobalReciever = 10;
          fd(LRmotorsSpeedGlobalReciever); sleep(3750);
          sr(RmotorsSpeedGlobalReciever); sleep(2300);
          fd(LRmotorsSpeedGlobalReciever); sleep(3000);
          LRmotorsSpeedGlobalReciever = 100;
          RmotorsSpeedGlobalReciever = 100;
        break;
        
          case 6:
          sceneGlobalReciever = 5;
          pa8obj(true,1,5,7);
          LRmotorsSpeedGlobalReciever = 500;
          fd(LRmotorsSpeedGlobalReciever); sleep(196);
          tr(RmotorsSpeedGlobalReciever);  sleep(607);
          fd(LRmotorsSpeedGlobalReciever); sleep(170);
        break;

          case 7:
          sceneGlobalReciever = 6;
          LRmotorsSpeedGlobalReciever = 1000;
          fd(LRmotorsSpeedGlobalReciever); sleep(170);
        break;

          case 8:
         sceneGlobalReciever = 6.5;
         LRmotorsSpeedGlobalReciever = 100;
         fd(LRmotorsSpeedGlobalReciever); sleep(1000);
         LRmotorsSpeedGlobalReciever = 60;
         bk(LRmotorsSpeedGlobalReciever); sleep(1000);
         sr(RmotorsSpeedGlobalReciever); sleep(641);
         LRmotorsSpeedGlobalReciever = 1000; sleep(170);
        break;

         case 9:
         sceneGlobalReciever = 7;
         fd(LRmotorsSpeedGlobalReciever); sleep(2200);
         pa8obj(false,0,0,0); 
         bk(LRmotorsSpeedGlobalReciever); sleep(2340);
        break;
         
         case 10:
         sceneGlobalReciever = 7.2;
         LRmotorsSpeedGlobalReciever = 50;
         bk(LRmotorsSpeedGlobalReciever); sleep(56);
         beep(); sleep(500); // 1st beep before explosion
         beep(); sleep(500); // 2nd beep before explosion
         beep(); sleep(500); // 3rd beep before explosion
         sceneGlobalReciever = 7.5;
         tl(LmotorsSpeedGlobalReciever); sleep(1462);
         LRmotorsSpeedGlobalReciever = 1000;
        break;

         case 11: 
          tl(LmotorsSpeedGlobalReciever); sleep(1422);
        break;
        
         case 12:
         sceneGlobalReciever = 8;
         fd(LRmotorsSpeedGlobalReciever); sleep(90);
         LRmotorsSpeedGlobalReciever = 100;
        break;

         case 13:
         sceneGlobalReciever = 8.5;
         fd(LRmotorsSpeedGlobalReciever); sleep(250);
        break;

          default:
            fd(100);
            sleep(100);
         break;
        }
    }
}

void sceneNumberLCDActivity(double scene){
  //displays which part of the storyline is currently playing by the robot

   if((scene == 7.5))
    lcd("B000000OOM!!!!"); //when the bomb explodes
  else if((scene == 8.5))
    lcd("THE END!"); //indicates that the story ends
  else
   lcd("SCENE : %d",scene); //catch : normally display the scene number

}

void endingSceneActivity(int sum,int max){
  //specific activity or void once the story reach the 8th scene
  if(sum > max){
  RmotorsSpeedGlobalReciever = 50; 
  sr(RmotorsSpeedGlobalReciever); sleep(4180);
  sl(RmotorsSpeedGlobalReciever); sleep(2490);
  sceneGlobalReciever = 8.5; sleep(50);
  system_stop(); //end all activity
 }
}

void pa8obj(bool use,int color,int scenestart, int sceneend){
    if((use == true)){
        //analog channel where it sends the color value of the ground or an object
    pa0 = analog(0); pa4 = analog(4); pa8 = analog(8);
    int redValue = 500;
   if(sceneGlobalReciever >= scenestart && sceneGlobalReciever <= sceneend){
     if(pa8 > redValue){
     keep_up();
     fd(LRmotorsSpeedGlobalReciever); 
     }
    }
 }else{
     keep_down();
 }
}

void errorReciever(int typeoferror){
  //recieves logical and expected errors
  switch(typeoferror){
    case 001:
    //1st type
    lcd("E%d:Invalid sensor's movement value.",typeoferror);
    sleep(1000);
    system_stop();
    beep();
      break;
      
    default: 
     lcd("E%d:Unidentified error",typeoferror);
    system_stop();
    beep();
    break;
  }
}