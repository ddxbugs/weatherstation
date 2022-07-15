// TODO: license
/**
 * @brief 
 * 
 */

#include <weatherstation.h> 

WeatherStation ws;
Serial serial;
void setup() {
  
  // serial == Hardware Fail
  while (!serial.begin(115200)) {
      return 1;
  }
  
  serial.begin(115200);
  ws.begin(); // initialize ethernet shield, nrf, sends ACK

  // wait for ws to initialize and return
   while (!ws.server()) {
      return 1;
   }
}

void loop() {
  
  ws.getTemperature(currentTime()); // example get function, ws reads temperature pin on remote arduino board
  ws.getHumidity(); // example get function, ws reads humidity pin on remote arduino board
  
  // send text/html code to rpi server
  serial.println("<!DOCTYPE html>");
  serial.println("<html lang='en'>);
  serial.println("<head>");
//  serial.println("<script type='text/javascript' src='js/ws.js'></script>");
  serial.println("</head>");
  serial.println("<body>");
  serial.println("<form input='text' >"); //connectDB, send http request
  serial.println("</body>");
  serial.println("</html>");
}
