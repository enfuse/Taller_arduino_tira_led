#include "FastLED.h"

#define NUM_LEDS 16
#define DATA_PIN 4

CRGB leds[NUM_LEDS];

// Definimos constantes 
const int  buttonPin = 2;    // definimos el pin2 para el boton
// Variables will change:
int buttonPushCounter = 0;   // Contador de numero de veces pulado el boton
int buttonState = 0;         // Estado actual del boton
int lastButtonState = 0;     // estado anterior del boton

void setup() {
  //init de los leds
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  // Init del boton:
  pinMode(buttonPin, INPUT);
  //init del puerto serier para ver que ocurre
  Serial.begin(9600);
}


void loop() {
  // Leemos y guardamos el  boton
  buttonState = digitalRead(buttonPin);
  // Comparamos el estado del boton con el estado anterior
  if (buttonState != lastButtonState) {
    // Si es diferente incrementamos el boton
    if (buttonState == HIGH) {
      buttonPushCounter++;
      leds[buttonPushCounter] = CRGB::Red; 
      FastLED.show(); 
      Serial.println("on");
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter);
    } 
  }
  lastButtonState = buttonState;
  if (buttonPushCounter == 15){
    Serial.print("16");
    for(int i = 0; i < NUM_LEDS; i++) { 
      leds[i] = CRGB::Black;
      FastLED.show();
      delay(100);
    }
    buttonPushCounter = 0;
  }
  //Si es multiplo de 4 cambia el color a rosa de ese led
  if (buttonPushCounter % 4 == 0) {
    leds[buttonPushCounter] = CRGB::Pink; 
  }
}

