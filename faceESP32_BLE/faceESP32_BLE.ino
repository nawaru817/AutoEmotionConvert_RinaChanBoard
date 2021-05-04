/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Social networks:            http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example shows how to use ESP32 BLE
  to connect your project to Blynk.

  Warning: Bluetooth support is in beta!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#define BLYNK_USE_DIRECT_CONNECT

#include <BlynkSimpleEsp32_BLE.h>
#include <BLEDevice.h>
#include <BLEServer.h>

#include <FastLED.h>
 #define NUM_LEDS 216
    #define DATA_PIN 15

    CRGB leds[NUM_LEDS];//LEDストリップの変数宣言:

    int val1;
    int val2;
    int val3;
    int swt = 0;
    int swt2 = 0;
    int oldval = HIGH;
    int oldval2 = HIGH;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "GkArma3UbHyXu7D7IhhkYoMTJcdnFW9f";

void setup()
{
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);// fastLED初期化:
  FastLED.setBrightness(20); 
  
  // Debug console
  Serial.begin(9600);

  Serial.println("Waiting for connections...");

  Blynk.setDeviceName("Blynk");

  Blynk.begin(auth);

//マニュアルモードで使うインプットピン
// pinMode(14,INPUT_PULLUP);
 pinMode(2, INPUT_PULLUP);
 pinMode(0,INPUT_PULLUP);

  
}

void loop()
{

 Blynk.run();


 ////マニュアルモードとBLEモード切替
  val1 = digitalRead(2);
  val2 = digitalRead(0);//BLEモード切替ピン
  //val3 = digitalRead(14);

///スイッチ
  if(val1 == LOW && oldval == HIGH){
      
    swt = 1 + swt;
    if(swt == 10){
      swt = 0;
    }
     delay(10);
    }
        oldval = val1;




//マニュアルモードひな形
//  int face?[] = {};//顔の配列データ:
//
//if(val1 == HIGH && val2 == LOW){
//  
//    for(int i = 0; i < 58; i++){
//    
//        leds[face?[i]].setRGB(51,255,153); 
//         // leds[0] = CRGB::Red;でledsテープの0番目のLEDの色を指定:
//  }
//        FastLED.show(); 
//        delay(1);
//
//} else if(val1 == LOW && val2 == LOW){
//          FastLED.clear();
//          FastLED.show(); 
//        delay(1);



/////////////////////////////////////  
//デフォ１


    int face[] = {1,13,20,21,32,33,38,39,50,51,56,57,68,69,74,75,86,87,109,111,122,124,149,156,168,173,187,188,189,190};//顔の配列データ:



if(swt == 1 && val2 == HIGH){

  
    for(int i = 0; i < 30; i++){
    
        leds[face[i]].setRGB(51,255,153); 
         // leds[0] = CRGB::Red;でledsテープの0番目のLEDの色を指定:
  }
        FastLED.show(); 
        delay(1);

} else if((swt == 0 || swt > 1) && val2 == HIGH){
          FastLED.clear();
          //FastLED.show(); 
          //delay(1);
        

      
}

////////////////////////////////
//デフォ２

   int face1[] = {1,16,20,21,32,33,38,39,50,51,56,57,68,69,74,75,86,87,109,111,122,124,149,150,151,152,153,154,155,156,167,174,186,187,188,189,190,191};//顔の配列データ:


if(swt == 2 && val2 == HIGH){
  
    for(int i = 0; i < 38; i++){
    
        leds[face1[i]].setRGB(51,255,153); 
         // leds[0] = CRGB::Red;でledsテープの0番目のLEDの色を指定:
  }
    FastLED.show(); 
        delay(1); 
} else if((swt == 0 || swt > 2) && val2 == HIGH){
          FastLED.clear();
          //FastLED.show(); 
        //delay(1); 
           
}

////////////////////////////////
//デフォ３

   int face2[] = {1,2,15,16,21,22,31,32,41,48,57,58,67,68,73,74,87,88,108,110,123,125,131,132,133,134,135,136,137,138,149,156,168,173,187,188,189,190};//顔の配列データ:


if(swt == 3 && val2 == HIGH){
  
    for(int i = 0; i < 38; i++){
    
        leds[face2[i]].setRGB(51,255,153); 
         // leds[0] = CRGB::Red;でledsテープの0番目のLEDの色を指定:
  }
    FastLED.show(); 
        delay(1); 
} else if((swt == 0 || swt > 3) && val2 == HIGH){
          FastLED.clear();
             // FastLED.show(); 
        //delay(1); 
           
}

////////////////////////////////
//デフォ４

   int face3[] = {37,38,51,52,55,56,57,58,67,68,69,70,74,75,86,87,108,110,123,125,148,157,167,168,169,170,171,172,173,174};//顔の配列データ:


if(swt == 4 && val2 == HIGH){
  
    for(int i = 0; i < 30; i++){
    
        leds[face3[i]].setRGB(51,255,153); 
         // leds[0] = CRGB::Red;でledsテープの0番目のLEDの色を指定:
  }
    FastLED.show(); 
        delay(1); 
} else if((swt == 0 || swt > 4) && val2 == HIGH){
          FastLED.clear();
             // FastLED.show(); 
        //delay(1); 
           
}

////////////////////////////////
//デフォ5

   int face4[] = {0,1,16,17,20,21,32,33,40,49,54,55,56,57,68,69,70,71,91,93,104,106,108,110,123,125,131,132,133,134,135,136,137,138,149,156,168,173,187,188,189,190};//顔の配列データ:


if(swt == 5 && val2 == HIGH){
  
    for(int i = 0; i < 42; i++){
    
        leds[face4[i]].setRGB(51,255,153); 
         // leds[0] = CRGB::Red;でledsテープの0番目のLEDの色を指定:
  }
    FastLED.show(); 
        delay(1); 
} else if((swt == 0 || swt > 5) && val2 == HIGH){
          FastLED.clear();
              //FastLED.show(); 
        //delay(1); 
           
}

////////////////////////////////
//デフォ6

   int face5[] = {18,19,34,35,38,39,50,51,58,67,74,75,79,80,81,82,86,87,90,91,97,100,106,107,115,118,126,127,128,129,133,136,140,141,142,143,150,154,162,163,164,165,168,169,170,171,172,173,176,177,178,179,185,191};//顔の配列データ:


if(swt == 6 && val2 == HIGH){
  
    for(int i = 0; i < 54; i++){
    
        leds[face5[i]].setRGB(51,255,153); 
         // leds[0] = CRGB::Red;でledsテープの0番目のLEDの色を指定:
  }
    FastLED.show(); 
        delay(1); 
} else if((swt == 0 || swt > 6) && val2 == HIGH){
          FastLED.clear();
              //FastLED.show(); 
        //delay(1); 
           
}

////////////////////////////////
//デフォ7

   int face6[] = {20,21,32,33,37,38,40,49,50,52,55,56,57,58,67,68,69,70,74,75,86,87,88,105,107,124,150,151,154,155,166,167,170,171,174,175};//顔の配列データ:


if(swt == 7 && val2 == HIGH){
  
    for(int i = 0; i < 36; i++){
    
        leds[face6[i]].setRGB(51,255,153); 
         // leds[0] = CRGB::Red;でledsテープの0番目のLEDの色を指定:
  }
    FastLED.show(); 
        delay(1); 
} else if((swt == 0 || swt > 7) && val2 == HIGH){
          FastLED.clear();
             // FastLED.show(); 
        //delay(1); 
           
}

  ////////////////////////////////
//デフォ8

   int face7[] = {19,20,33,34,39,40,49,50,59,66,73,74,75,76,85,86,87,88,110,112,122,124,127,129,139,141,168,169,172,173,184,185,188,189,192,193};//顔の配列データ:


if(swt == 8 && val2 == HIGH){
  
    for(int i = 0; i < 36; i++){
    
        leds[face7[i]].setRGB(51,255,153); 
         // leds[0] = CRGB::Red;でledsテープの0番目のLEDの色を指定:
  }
    FastLED.show(); 
        delay(1); 
} else if((swt == 0 || swt > 8) && val2 == HIGH){
          FastLED.clear();
             // FastLED.show(); 
        //delay(1); 
           
}

  ////////////////////////////////
//デフォ9

   int face8[] = {3,4,5,14,15,16,20,22,23,24,31,33,34,35,38,40,41,42,49,51,52,53,56,60,67,71,75,76,77,86,87,88,132,151,156,170,171,172,173};//顔の配列データ:


if(swt == 9 && val2 == HIGH){
  
    for(int i = 0; i < 39; i++){
    
        leds[face8[i]].setRGB(51,255,153); 
         // leds[0] = CRGB::Red;でledsテープの0番目のLEDの色を指定:
  }
    FastLED.show(); 
        delay(1); 
} else if((swt == 0 || swt > 9) && val2 == HIGH){
          FastLED.clear();
              FastLED.show(); 
        delay(1); 
           
}

}


//////////////////////////////////////////////////////////
//BLEモードひな形
//BLYNK_WRITE(Vn){ //ボタンの数字
//
//  int pinData = param.asInt();
//  
//          int face[] = {};//顔の配列データ:
//    
//  if(pinData == 1){
//  
//   for(int i = 0; i < n; i++){ //配列の要素数
//    
//        leds[face[i]].setRGB(51,255,153); 
//
//  }
//
//        FastLED.show(); 
//        delay(1); // leds[0] = CRGB::Red;でledsテープの0番目のLEDの色を指定:
//
//} else {
//
//        FastLED.clear();
//        FastLED.show();
//  
//       }
//}


BLYNK_WRITE(V0){ //家虎

  int pinData = param.asInt();
  
          int face[] = {4,14,19,20,21,22,23,24,25,32,33,34,37,39,40,41,43,47,48,49,50,57,58,65,68,69,70,73,74,76,77,79,83,93,95,96,101,103,105,109,110,112,113,115,118,120,123,124,148,157,167,174,186,187,188,189,190,191};//顔の配列データ:
    
  if(pinData == 1){
  
   for(int i = 0; i < 58; i++){
    
        leds[face[i]].setRGB(51,255,153); 
         // leds[0] = CRGB::Red;でledsテープの0番目のLEDの色を指定:
  }
  FastLED.show(); 
        delay(1);
} else {

        FastLED.clear();
        FastLED.show();
        delay(1);
  
       }
}


BLYNK_WRITE(V1){ //んあー

  int pinData = param.asInt();
  
          int face[] = {18,19,34,35,38,39,50,51,58,67,74,75,79,80,81,82,86,87,90,91,97,100,106,107,115,118,126,127,128,129,133,136,140,141,142,143,150,154,162,163,164,165,168,169,170,171,172,173,176,177,178,179,185,191};//顔の配列データ:
    
  if(pinData == 1){
  
   for(int i = 0; i < 54; i++){
    
        leds[face[i]].setRGB(51,255,153); 
       
  }

   FastLED.show(); 
        delay(1); // leds[0] = CRGB::Red;でledsテープの0番目のLEDの色を指定:
        
} else {

        FastLED.clear();
        FastLED.show();
        delay(1);
  
       }
}


BLYNK_WRITE(V2){ //（＞ω＜）

  int pinData = param.asInt();
  
          int face[] = {36,53,55,70,74,87,93,97,101,104,110,114,117,119,123,127,132,135,137,142,144,150,152,153,155,161,169,172};//顔の配列データ:
    
  if(pinData == 1){
  
   for(int i = 0; i < 28; i++){ //配列の要素数
    
        leds[face[i]].setRGB(51,255,153); 

  }

        FastLED.show(); 
        delay(1); // leds[0] = CRGB::Red;でledsテープの0番目のLEDの色を指定:

} else {

        FastLED.clear();
        FastLED.show();
        delay(1);
  
       }
}



BLYNK_WRITE(V4){ //デフォ

  int pinData = param.asInt();
  
          int face[] = {1,13,20,21,32,33,38,39,50,51,56,57,68,69,74,75,86,87,109,111,122,124,149,156,168,173,187,188,189,190};//顔の配列データ:
    
  if(pinData == 1){
  
   for(int i = 0; i < 30; i++){
    
        leds[face[i]].setRGB(51,255,153);

  }

          FastLED.show(); 
        delay(1);
        
} else {

        FastLED.clear();
        FastLED.show();
        delay(1);
  
       }
}

  BLYNK_WRITE(V3){

  int pinData = param.asInt();
    FastLED.setBrightness(pinData); 
    FastLED.show();
    delay(1);
  
}
