void handle_OnConnect() {
  String s = (const __FlashStringHelper*) MAIN_page;
  server.send(200, "text/html", s);
}

void handleBrightness() {
  int b = server.arg("brightness").toInt();
  Serial.println("brightness");
  Serial.println( b );
  BRIGHTNESS = b;
  server.send(200, "text/plane", "done");
}

void handleDelay() {
  int d = server.arg("delay").toInt();
  Serial.println("delay");
  Serial.println( d );
  delayTime = d;
  server.send(200, "text/plane", "done");
}

void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}
