void Pantallainicio() {
  int R = 50;
  vga.fillCircle(vga.xres / 2, vga.yres / 2, 500, vga.RGB(255, 255, 255));//circulo gigante que cubre la pantalla
  for (int i = 0; i < 10; i++) {
    int x1 = random(vga.xres);
    int y1 = random(vga.yres);
    int x2 = random(vga.xres);
    int y2 = random(vga.yres);

    vga.line(x1, y1, x2, y2, vga.RGB(0, 0, 0));
  }
  vga.fillCircle(vga.xres / 2, vga.yres / 2, R, vga.RGB(0, 0, 0));//Circulo negro del medio
  vga.line(200, 300, 200, 0, vga.RGB(255, 255, 255));
  if (rotaryEncoder.isEncoderButtonClicked()) {
    rotary_onButtonClick();
    R = R*2;
    delay(1000);
    EstadoDelJuego = 1;
  }
}