
void stages(int i) {
  switch (i) {
      if (!done) {
        case 0:
         BTA_on(bta1);
         break;
      case 1:
        //  MATRIX = first icon (magnifying   glass)
        matrix.fillScreen(0);
        sprite(magnify, PURPLE);
        soundFX();
        done = 1;
        break;
      case 2:
        //MATRIX   = second icon (circle)
        matrix.fillScreen(0);
        sprite(smiley, PURPLE);
        done = 1;
        break;
      case 3:
        //BT_4 = on (3leds)
        BTB_on(btb4);
        done = 1;
        break;
      case 4:
        //MATRIX   = first icon (magnifying glass)
        matrix.fillScreen(0);
        sprite(magnify, PURPLE);
        done = 1;
        break;
      case 5:
        //MATRIX   = second icon (cercle)
        matrix.fillScreen(0);
        sprite(smiley, PURPLE);
        done = 1;
        break;
      case 6:
        // BT_7 = on   (3leds)
        BTA_on(bta7);
        done = 1;
        break;
      case 7:
        // BT_2 = on           (3leds)
        BTB_on(btb2);
        done = 1;
        break;
      case 8:
        //BT_5 = on   (3leds)
        BTA_on(bta5);
        done = 1;
        break;
      case 9:
        //BT_3 = on          (3leds)
        BTA_on(bta3);
        done = 1;
        break;
      case 10:
        //  BT_6 = on          (3leds)
        BTB_on(btb6);
        done = 1;
        break;
      case 11:
        //all lights flick
        flicker_all(5, 200);
        //continue to next (final stage);
      case 12:
        //restart
        alloff();
        index = 0;
        done = 1;
        break;
      }
  }
}


