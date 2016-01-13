void matrix_circle() {
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  matrix.print(F("O"));
  if (--x < -36) {
    x = matrix.width();
    if (++pass >= 3) pass = 0;
    matrix.setTextColor(colors[pass]);
  }
  matrix.show();
}
