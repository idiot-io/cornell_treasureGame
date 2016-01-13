

void BTA_on(int group) {
  int length = 3;
  if (group == 0) length = 2; //first group has only 2 pixels


  for (int iii = group; iii <= length; iii++)
    BTA.setPixelColor(iii, BTcolors[1]);
}

void BTB_on(int group) {
  for (int iii = group; iii <= 3; iii++)
    BTB.setPixelColor(iii, BTcolors[1]);
}

void flicker_ST12(int loop_times, int delay_time) {
  for (int jjj = 0; jjj < loop_times; jjj++) {
    for (int iii = 0; iii < pixcount_ST12; iii++)
      ST12.setPixelColor(iii, BTcolors[0]);

    ST12.show();
    delay(delay_time);

    for (int iii = 0; iii < pixcount_ST12; iii++)
      ST12.setPixelColor(iii, BTcolors[1]);

    ST12.show();
    delay(delay_time);
  }
}

void alloff(){
    for (int iii = 0; iii < pixcount_BTB; iii++)
      BTB.setPixelColor(iii, BTcolors[0]);
    for (int iii = 0; iii < pixcount_BTA; iii++)
      BTA.setPixelColor(iii, BTcolors[0]);
    for (int iii = 0; iii < pixcount_ST12; iii++)
      ST12.setPixelColor(iii, BTcolors[0]);

    BTB.show(); BTA.show(); ST12.show();
}

void flicker_all(int loop_times, int delay_time) {
  for (int jjj = 0; jjj < loop_times; jjj++) {
    for (int iii = 0; iii < pixcount_BTB; iii++)
      BTB.setPixelColor(iii, BTcolors[1]);
    for (int iii = 0; iii < pixcount_BTA; iii++)
      BTA.setPixelColor(iii, BTcolors[1]);
    for (int iii = 0; iii < pixcount_ST12; iii++)
      ST12.setPixelColor(iii, BTcolors[1]);

    BTB.show(); BTA.show(); ST12.show();
    delay(200);

    for (int iii = 0; iii < pixcount_BTB; iii++)
      BTB.setPixelColor(iii, BTcolors[0]);
    for (int iii = 0; iii < pixcount_BTA; iii++)
      BTA.setPixelColor(iii, BTcolors[0]);
    for (int iii = 0; iii < pixcount_ST12; iii++)
      ST12.setPixelColor(iii, BTcolors[0]);

    BTB.show(); BTA.show(); ST12.show();
    delay(200);
  }
}

void matrix_mag() {
  matrix.fillScreen(0);
  matrix.setCursor(0, 0);
  matrix.print("X");
  matrix.show();
}

void matrix_circle() {
  matrix.fillScreen(0);
  matrix.setCursor(1, 1);
  matrix.print("X");
  matrix.show();
}

void sprite(const uint8_t* x, unsigned long y){
  byte red = (y & 0xFF0000) >> 16;
  byte green = ( y & 0x00FF00) >> 8;
  byte blue = (y & 0x0000FF);
  matrix.drawBitmap(0,0, x, 8, 8, matrix.Color(red, green, blue));
  matrix.show();
  //matrix.fillScreen(0);
}

