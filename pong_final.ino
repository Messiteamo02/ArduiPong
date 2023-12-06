//Declaracion de librerias
#include <ESP32Lib.h>
#include <Ressources/Font6x8.h>
#include "AiEsp32RotaryEncoder.h"

//pin configuration
const int redPin = 12;
const int greenPin = 14;
const int bluePin = 27;
const int hsyncPin = 26;
const int vsyncPin = 25;

//pin del rotary 1
#define ROTARY_ENCODER_A_PIN 34
#define ROTARY_ENCODER_B_PIN 35
#define ROTARY_ENCODER_BUTTON_PIN 18
#define ROTARY_ENCODER_VCC_PIN -1
#define ROTARY_ENCODER_STEPS 4

//pin del rotary 2
#define ROTARY_ENCODERj2_A_PIN 32
#define ROTARY_ENCODERj2_B_PIN 33
#define ROTARY_ENCODERj2_BUTTON_PIN 19
#define ROTARY_ENCODERj2_VCC_PIN -1
#define ROTARY_ENCODERj2_STEPS 4

AiEsp32RotaryEncoder rotaryEncoder = AiEsp32RotaryEncoder(ROTARY_ENCODER_A_PIN, ROTARY_ENCODER_B_PIN, ROTARY_ENCODER_BUTTON_PIN, ROTARY_ENCODER_VCC_PIN, ROTARY_ENCODER_STEPS);
AiEsp32RotaryEncoder rotaryEncoderj2 = AiEsp32RotaryEncoder(ROTARY_ENCODERj2_A_PIN, ROTARY_ENCODERj2_B_PIN, ROTARY_ENCODERj2_BUTTON_PIN, ROTARY_ENCODERj2_VCC_PIN, ROTARY_ENCODERj2_STEPS);

// VGA Device
VGA3Bit vga;
// Pelota
float Pposx = 0;
float Pposy = 0;
float Pvelx = 2;
float Pvely = 2;
int Pradio = 5;
//aceleracion 
float a = 0.2;
// Paletas
float pal1posx = 0;
float pal1posy = 0;
float pal2posx = 0;
float pal2posy = 0;
// Puntaje inicial
int Puntaje1 = 0;
int Puntaje2 = 0;

int EstadoDelJuego = 0;
// H = Alto
float H = 10;
// W = Ancho
float W = 50;
// C = Centro
float C = W/2;

int CantRev = 0;
int d = CantRev/5;

void setup() {
  vga.setFrameBufferCount(2);
  vga.init(vga.MODE400x300, redPin, greenPin, bluePin, hsyncPin, vsyncPin);

  Pposx = vga.xres / 2;
  Pposy = vga.yres / 2;
  vga.setFont(Font6x8);

  pal1posx = 1;
  pal1posy = vga.yres / 2;

  pal2posx = vga.xres - H;
  pal2posy = vga.yres / 2;

  setupRotary();
}

void loop() {
  switch (EstadoDelJuego) {
    case 0:
      Pantallainicio();
      break;

    case 1:
      PantallaJuego();
      break;
    case 2:
      Ganadorj1();
      break;
    case 3:
      Ganadorj2();
      break;
  }
  vga.show();
}