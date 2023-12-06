void PantallaJuego(){
  rotary_loop();
  vga.clear(0);

  //mover pelota
  Pposx += (Pvelx);
  Pposy += (Pvely);

  //colision de la pelota con bordes superior e inferior
  if ((Pposy < Pradio) || (Pposy > vga.yres - Pradio)) {
    Pposx -= (Pvelx);
    Pposy -= (Pvely);
    Pvely *= -1;
  }
  //colision de la pelota con bordes izquierdo y derecho
  if ((Pposx < Pradio) || (Pposx > vga.xres - Pradio)) {
    Pposx -= (Pvelx);
    Pposy -= (Pvely);
    Pvelx = Pvelx<0?2:-2;
    Pposx = vga.xres / 2;
    Pposy = vga.yres / 2;
    CantRev = 0;
  }
  // Calcula las posiciones de los bordes de las paletas y de la pelota
  int pal1Right = pal1posx + H;
  int pal2Right = pal2posx + H;
  int pal1Left = pal1posx;
  int pal2Left = pal2posx;
  int pal1Top = pal1posy;
  int pal2Top = pal2posy;
  int pal1Bottom = pal1posy + W;
  int pal2Bottom = pal2posy + W;

  int ballLeft = Pposx - Pradio;
  int ballRight = Pposx + Pradio;
  int ballTop = Pposy - Pradio;
  int ballBottom = Pposy + Pradio;

  // Comprobar colisión con paleta 1
  if (ballRight >= pal2Left && ballTop <= pal2Bottom && ballBottom >= pal2Top) {
    Pposx -= (Pvelx);
    Pposy -= (Pvely);
    Pvelx *= -1;
    Pvely *= 1;
    CantRev++;
    d = CantRev/3;
    if(CantRev >= 3){
      Pvelx = 2*d;
      Pvely = 2*d;
    }
  }
  // Comprobar colisión con paleta 2
  if (ballLeft <= pal1Right && ballTop <= pal1Bottom && ballBottom >= pal1Top) {
    Pposx -= (Pvelx);
    Pposy -= (Pvely);
    Pvelx *= -1;
    Pvely *= 1;
    CantRev ++;
    d = CantRev/3; 
    if(CantRev >= 3){
      Pvelx = 2*-d;
      Pvely = 2*-d;
    }
  }
  
  if(ballLeft = C){
    Pvely *= 1;
  }
  else{
  Pvely *= -1;
  }


  //mostrar Pelota
  vga.circle(Pposx, Pposy, Pradio, vga.RGB(255, 255, 255));

  //mostrar paletas
  vga.rect(pal1posx, pal1posy, H, W, vga.RGB(0, 255, 255)); 
  vga.fillCircle(pal1posx, pal1posy, 1, vga.RGB(255, 0, 0));
  vga.rect(pal2posx, pal2posy, H, W, vga.RGB(255, 255, 0));
  vga.fillCircle(pal2posx, pal2posy, 1, vga.RGB(255, 0, 0));

  //linea del media
  vga.line(200, 300, 200, 0, vga.RGB(255, 255, 255));

  // Puntaje 1

  if (Pposx == 390) {
    Puntaje1++;
  }

  if (Puntaje1 >= 1) {
    vga.circle(180, 20, 3, vga.RGB(0, 255, 255));
  }
  if (Puntaje1 >= 2) {
    vga.circle(160, 20, 3, vga.RGB(0, 255, 255));

  }
  if (Puntaje1 >= 3) {
    vga.circle(140, 20, 3, vga.RGB(0, 255, 255));
    delay(1000);
    EstadoDelJuego = 2;
  }

  // puntaje 2

  if (Pposx == 10) {

    Puntaje2++;
  }

  if (Puntaje2 >= 1) {

    vga.circle(220, 20, 3, vga.RGB(255, 255, 0));
  }
  if (Puntaje2 >= 2) {

    vga.circle(240, 20, 3, vga.RGB(255, 255, 0));
  }
  if (Puntaje2 >= 3) {

    vga.circle(260, 20, 3, vga.RGB(255, 255, 0));
    delay(1000);
    EstadoDelJuego = 3;
  }
  }