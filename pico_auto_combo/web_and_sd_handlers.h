#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <LEAmDNS.h>
//#include <StreamString.h>
#include <SPI.h>
#include <SD.h>



WebServer server(80);
File get_file;

bool isNum(char c){ 
        
      int x = int(c);

      if(!(x > 47 && x < 58)){
            return false;
      } 
              
      return true;
}

void set_vectors(String script){

    std::map<char, std::function<int()>> conv = {
          {'A', UHold},
          {'B', URel},
          {'C', UPress},
          {'D', DHold},
          {'E', DRel},
          {'F', DPress},
          {'G', LHold},
          {'H', LRel},
          {'I', LPress},
          {'J', RHold},
          {'K', RRel},
          {'L', RPress},
          {'M', AHold},
          {'N', ARel},
          {'O', APress},
          {'P', BHold},
          {'Q', BRel},
          {'R', BPress},
          {'S', XHold},
          {'T', XRel},
          {'U', XPress},
          {'V', YHold},
          {'W', YRel},
          {'X', YPress},
          {'Y', RBHold},
          {'Z', RBRel},
          {'a', RBPress},
          {'b', RTHold},
          {'c', RTRel},
          {'d', RTPress},
          {'e', LBHold},
          {'f', LBRel},
          {'g', LBPress},
          {'h', LTHold},
          {'i', LTRel},
          {'j', LTPress},
          {'k', QCF},
          {'l', QCB},
          {'m', RQCF},
          {'n', RQCB},
          {'o', HCF},
          {'p', HCB},
          {'q', HCFB},
          {'r', HCBF},
          {'s', DP},
          {'t', RDP},
          {'u', SPD},
          {'v', delay_frames}
    };

    x_fire.clear();
    x_delay.clear();

    y_fire.clear();
    y_delay.clear();

    a_fire.clear();
    a_delay.clear();

    b_fire.clear();
    b_delay.clear();

    rb_fire.clear();
    rb_delay.clear();

    rt_fire.clear();
    rt_delay.clear();

    lb_fire.clear();
    lb_delay.clear();

    lt_fire.clear();
    lt_delay.clear();
 
    String temp = "";
    int select = 0;

      for(int i = 0; i < script.length(); i++){
          while(script[i] != ':' && i < script.length()){
                switch(select){
                  case 0:
                    while(isNum(script[i])){
                      temp += script[i];
                      i++;
                    }
                    if(temp.length() > 0){
                      x_fire.push_back(conv['v']);
                      x_delay.push_back(temp.toInt());
                      temp = "";
                    }
                    else{
                      x_fire.push_back(conv[script[i]]);
                      x_delay.push_back(0);
                      i++;
                    }
                    break;
                  case 1:
                    while(isNum(script[i])){
                      temp += script[i];
                      i++;
                    }
                    if(temp.length() > 0){
                      y_fire.push_back(conv['v']);
                      y_delay.push_back(temp.toInt());
                      temp = "";
                    }
                    else{
                      y_fire.push_back(conv[script[i]]);
                      y_delay.push_back(0);
                      i++;
                    }
                    break;
                  case 2:
                    while(isNum(script[i])){
                      temp += script[i];
                      i++;
                    }
                    if(temp.length() > 0){
                      rb_fire.push_back(conv['v']);
                      rb_delay.push_back(temp.toInt());
                      temp = "";

                    }
                    else{
                      rb_fire.push_back(conv[script[i]]);
                      rb_delay.push_back(0);
                      i++;
                    }
                    break;
                  case 3:
                    while(isNum(script[i])){
                      temp += script[i];
                      i++;
                    }
                    if(temp.length() > 0){
                      lb_fire.push_back(conv['v']);
                      lb_delay.push_back(temp.toInt());
                      temp = "";
                    }
                    else{
                      lb_fire.push_back(conv[script[i]]);
                      lb_delay.push_back(0);
                      i++;
                    }
                    break;
                  case 4:
                    while(isNum(script[i])){
                      temp += script[i];
                      i++;
                    }
                    if(temp.length() > 0){
                      a_fire.push_back(conv['v']);
                      a_delay.push_back(temp.toInt());
                      temp = "";
                    }
                    else{
                      a_fire.push_back(conv[script[i]]);
                      a_delay.push_back(0);
                      i++;
                    }
                    break;
                  case 5:
                    while(isNum(script[i])){
                      temp += script[i];
                      i++;
                    }
                    if(temp.length() > 0){
                      b_fire.push_back(conv['v']);
                      b_delay.push_back(temp.toInt());
                      temp = "";
                    }
                    else{
                      b_fire.push_back(conv[script[i]]);
                      b_delay.push_back(0);
                      i++;
                    }
                    break;
                case 6:
                    while(isNum(script[i])){
                      temp += script[i];
                      i++;
                    }
                    if(temp.length() > 0){
                      rt_fire.push_back(conv['v']);
                      rt_delay.push_back(temp.toInt());
                      temp = "";

                    }
                    else{
                      rt_fire.push_back(conv[script[i]]);
                      rt_delay.push_back(0);
                      i++;
                    }
                    break;
                case 7:
                    while(isNum(script[i])){
                      temp += script[i];
                      i++;
                    }
                    if(temp.length() > 0){
                      lt_fire.push_back(conv['v']);
                      lt_delay.push_back(temp.toInt());
                      temp = "";

                    }
                    else{
                      lt_fire.push_back(conv[script[i]]);
                      lt_delay.push_back(0);
                      i++;
                    }
                    break;
                  default:
                    i++;
                    break;
                }              
          }
          select++;
      }


}

#include "html.h"


void handleRoot(){
  handle_html("none", current_script, "");
}

void handleSent(){

  park_loop = true;
  while(!loop_exited){}

  bool found_flag = false;

  /*set the vectors fromt he compiled script, then save the compiled script, and script name, to sd card*/

  current_script = ((server.hasArg("compiled")) ? server.arg("compiled") : "U:X:a:g:O:R:d:j");
  set_vectors(current_script);


  handle_html("sent", ((server.hasArg("compiled")) ? server.arg("compiled") : ""), ((server.hasArg("file-name")) ? server.arg("file-name") : ""));
  park_loop = false;

}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }

  server.send(404, "text/plain", message);

  digitalWrite(0, HIGH);
}

void handle_setup_0(){

  park_loop = true;
  while(!loop_exited){}

  x_fire.reserve(512);
  x_delay.reserve(512);

  y_fire.reserve(512);
  y_delay.reserve(512);

  a_fire.reserve(512);
  a_delay.reserve(512);

  b_fire.reserve(512);
  b_delay.reserve(512);

  rb_fire.reserve(512);
  rb_delay.reserve(512);

  rt_fire.reserve(512);
  rt_delay.reserve(512);

  lb_fire.reserve(512);
  lb_delay.reserve(512);

  lt_fire.reserve(512);
  lt_delay.reserve(512);

  /*
  
  
  
  sd card shit here


    SDCARD:
        - web
            |_index.html
            |_ssid
            |_pass
        - info
            |_ profile_list (eg("chun-li-3s, ken-3s, ..."))
            |_ current_profile (eg("chun-li-3s"))
            |_ current_script 
        - profiles
            |_ ...

  */



pinMode(0, OUTPUT);

const int _MISO = 16;
const int _MOSI = 19;
const int _CS = 17;
const int _SCK = 18;

 SPI.setRX(_MISO);
  SPI.setTX(_MOSI);
  SPI.setSCK(_SCK);

  //LED_BLINK;

  if (!SD.begin(_CS)) {
    return;
  }

  current_script = "U:X:a:g:O:R:d:j";

  set_vectors(current_script);

  get_file = SD.open("ssid.txt", FILE_READ);

  if(get_file){
    ssid = get_file.readStringUntil(';').c_str();
    get_file.close();
  }

  get_file = SD.open("pass.txt", FILE_READ);

  if(get_file){
    password = get_file.readStringUntil(';').c_str();
    get_file.close();
  }

  
  

  park_loop = false;


  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid.c_str(), password.c_str());
  
  // Wait for connection



  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  get_file = SD.open("ip.txt", FILE_WRITE);

  if(get_file){
    get_file.println(WiFi.localIP().toString());
    get_file.close();
  }

  SD.end(1);

  MDNS.begin("picow");

  server.on("/", handleRoot);
  server.on("/send", HTTP_POST, handleSent);
  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });
  server.onNotFound(handleNotFound);
  server.setContentLength(9000);
  server.begin();




  LED_BLINK;

}
void handle_loop_0(){
  server.handleClient();
  MDNS.update();
}