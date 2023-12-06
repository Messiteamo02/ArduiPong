void Ganadorj2() {
  Puntaje1 = 0;
  Puntaje2 = 0;
  Pposx = vga.xres/2;
  Pposy = vga.yres/2;
  CantRev = 0;
  d = 0;
  vga.fillCircle(vga.xres / 2, vga.yres / 2, 500, vga.RGB(255, 255, 0));
  vga.fillCircle(vga.xres / 2, vga.yres / 2, 50, vga.RGB(0, 0, 0));
  for (int i = 0; i < 20; i++) {
    vga.print("___GANADOR___");
  }
   if (rotaryEncoderj2.encoderChanged())
  {
     delay(1000);
     EstadoDelJuego = 0;
  }
 
}