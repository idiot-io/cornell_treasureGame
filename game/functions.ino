

void BTA_on(int group) {
  int length = 3;
  if (group == 0) length = 2; //first group has only 2 pixels


  for (int iii = group; iii <= length; iii++)
    BTA.setPixelColor(iii, WHITE);
}

void BTB_on(int group) {
  for (int iii = group; iii <= 3; iii++)
    BTB.setPixelColor(iii, WHITE);
}

void flicker_ST12(int loop_times, int delay_time) {
  for (int jjj = 0; jjj < loop_times; jjj++) {
    for (int iii = 0; iii < pixcount_ST12; iii++)
      ST12.setPixelColor(iii, BLACK);

    ST12.show();
    delay(delay_time);

    for (int iii = 0; iii < pixcount_ST12; iii++)
      ST12.setPixelColor(iii, RED);

    ST12.show();
    delay(delay_time);
  }
}

void alloff() {
  for (int iii = 0; iii < pixcount_BTB; iii++)
    BTB.setPixelColor(iii, BLACK);
  for (int iii = 0; iii < pixcount_BTA; iii++)
    BTA.setPixelColor(iii, BLACK);
  for (int iii = 0; iii < pixcount_ST12; iii++)
    ST12.setPixelColor(iii, BLACK);

  BTB.show(); BTA.show(); ST12.show();

  matrix.fillScreen(0); //blank
  matrix.show();
}

void flicker_all(int loop_times, int delay_time) {
  for (int jjj = 0; jjj < loop_times; jjj++) {
    for (int iii = 0; iii < pixcount_BTB; iii++)
      BTB.setPixelColor(iii, WHITE);
    for (int iii = 0; iii < pixcount_BTA; iii++)
      BTA.setPixelColor(iii, WHITE);
    for (int iii = 0; iii < pixcount_ST12; iii++)
      ST12.setPixelColor(iii, RED);

    BTB.show(); BTA.show(); ST12.show();
    delay(delay_time);

    for (int iii = 0; iii < pixcount_BTB; iii++)
      BTB.setPixelColor(iii, BLACK);
    for (int iii = 0; iii < pixcount_BTA; iii++)
      BTA.setPixelColor(iii, BLACK);
    for (int iii = 0; iii < pixcount_ST12; iii++)
      ST12.setPixelColor(iii, BLACK);

    BTB.show(); BTA.show(); ST12.show();
    delay(delay_time);
    if(DEBUG) Serial.print("flicker: "); Serial.println(jjj);
  }
  if(DEBUG)Serial.println("end flivckerr all");
}

void sprite(const uint8_t* x, unsigned long y) {
  byte red = (y & 0xFF0000) >> 16;
  byte green = ( y & 0x00FF00) >> 8;
  byte blue = (y & 0x0000FF);
  matrix.drawBitmap(0, 0, x, 8, 8, matrix.Color(red, green, blue));
  matrix.show();
  //matrix.fillScreen(0);
}

