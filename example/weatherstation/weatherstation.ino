// TODO: license
/**
 * @brief 
 * 
 */

// include library header files
#include <SPI.h>
#include <Ethernet.h>
#include <NRFLite.h>
// include digital temp
// include digital humiture

// set ethernet shield mac
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

// IPAddress server(,,,) // no DNS
// char server[] = "www.server.com"; // using DNS, DynDNS

// Set static IP Address if DHCP fails to assign
// IPAddress ip(,,,); // ethernet shield static ip
// IPAddress myDns(,,,);  // internal dns gateway

// initialize libraries
EthernetClient client;
NRFLite radio;
RadioData data;
var server[] = ",,,";

// string variables
String postData;  // the post message body json format
int humidity;
int degrees;


void setup() {
  // pinMode setup
    
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect, neededd for native usb port only
  }

  // start weatherstation module checks
  Serial.println("initialize weatherstation with dhcp");
  if (Ethernet.being(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // Check for ethernet hardware presence
    if (Ethernet.hardwareStatus() == EhternetNoHardware) {
      Serial.println("Ethernet shield was not found. Sorry, can't run without hardware. :(");
      while(true) {
        delay(1) // do nothing, no point runing wihtout ethernet hardware
      }
    })
    if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Ethernet cable is not connected.");
    }
    // try to configure using IP address instead of DHCP:
    Ethernet.being(mac, ip);
  }
  Serial.println("Connecting... ");
  // else {
    Serial.print(" DHCP assigned IP: ");
    Serial.println(Ethernet.localIp());

    // give the ethernet shield a second to initialize:
    delay(1000);
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
