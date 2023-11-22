void Ganadorj2() {
  Puntaje1 = 0;
  Puntaje2 = 0;
  vga.fillCircle(vga.xres / 2, vga.yres / 2, 500, vga.RGB(0, 255, 255));
  for (int i = 0; i < 100; i++) {
    vga.print("___GANADOR___");
  }
   if (rotaryEncoderj2.encoderChanged())
  {
     EstadoDelJuego = 0;
  }
 
}