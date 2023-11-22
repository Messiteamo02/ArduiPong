void Ganadorj1() {
  Puntaje1 = 0;
  Puntaje2 = 0;
  vga.fillCircle(vga.xres / 2, vga.yres / 2, 500, vga.RGB(255, 255, 0));
  for (int i = 0; i < 100; i++) {
    vga.print("___GANADOR___");
  }
  if (rotaryEncoder.encoderChanged()) {
    EstadoDelJuego = 0;
  }
}