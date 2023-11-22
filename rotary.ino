boolean rotClick = false;
boolean rotClickj2 = false;
void rotary_onButtonClick()
{
  rotClick = !rotClick;
}
void rotaryj2_onButtonClick()
{
  rotClickj2 = !rotClickj2;
  
}

void rotary_loop()
{ 
 /* */
  //dont print anything unless value changed
  if (rotaryEncoder.encoderChanged())
  {
    pal1posy = rotaryEncoder.readEncoder();
    //pal1posy = pal1posy*velocidad;
  }
  if (rotaryEncoder.isEncoderButtonClicked())
  {
    rotary_onButtonClick();
    //dont print anything unless value changed
  }

    //pal2
   if (rotaryEncoderj2.encoderChanged())
  {
    pal2posy = rotaryEncoderj2.readEncoder();
    
  }
  if (rotaryEncoderj2.isEncoderButtonClicked())
  {
    rotaryj2_onButtonClick();
  }
    //pal2

}
void IRAM_ATTR readEncoderISR()
{
  rotaryEncoder.readEncoder_ISR();
  rotaryEncoderj2.readEncoder_ISR();
}

 void setupRotary() {
    rotaryEncoder.begin(); 
    rotaryEncoder.setup(readEncoderISR);

    rotaryEncoderj2.begin();
    rotaryEncoderj2.setup(readEncoderISR);
    

    bool circleValues = false;
    rotaryEncoder.setBoundaries(0+3, 290-20, circleValues); //minValue, maxValue, circleValues true|false (when max go to min and vice versa)
    //rotaryEncoder.disableAcceleration(); //acceleration is now enabled by default - disable if you dont need it
    //rotaryEncoder.setAcceleration(250); //or set the value - larger number = more accelearation; 0 or 1 means disabled acceleration
    rotaryEncoderj2.setBoundaries(0+3, 290-20, circleValues); //minValue, maxValue, circleValues true|false (when max go to min and vice versa)
    //rotaryEncoderj2.disableAcceleration();
  }