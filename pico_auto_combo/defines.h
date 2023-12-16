#ifndef DEFINES
#define DEFINES
#endif

#define U_ON digitalWrite(14, LOW)
#define U_OFF digitalWrite(14, HIGH)
#define D_ON digitalWrite(13, LOW)
#define D_OFF digitalWrite(13, HIGH)
#define L_ON digitalWrite(15, LOW)
#define L_OFF digitalWrite(15, HIGH)
#define R_ON digitalWrite(12, LOW)
#define R_OFF digitalWrite(12, HIGH)
#define X_ON digitalWrite(8, LOW)
#define X_OFF digitalWrite(8, HIGH)
#define Y_ON digitalWrite(7, LOW)
#define Y_OFF digitalWrite(7, HIGH)
#define A_ON digitalWrite(4, LOW)
#define A_OFF digitalWrite(4, HIGH)
#define B_ON digitalWrite(3, LOW)
#define B_OFF digitalWrite(3, HIGH)
#define RB_ON digitalWrite(6, LOW)
#define RB_OFF digitalWrite(6, HIGH)
#define RT_ON digitalWrite(2, LOW)
#define RT_OFF digitalWrite(2, HIGH)
#define LB_ON digitalWrite(5, LOW)
#define LB_OFF digitalWrite(5, HIGH)
#define LT_ON digitalWrite(1, LOW)
#define LT_OFF digitalWrite(1, HIGH)


#define A_IN !digitalRead(11)
#define B_IN !digitalRead(10)
#define X_IN !digitalRead(9)
#define Y_IN !digitalRead(20)
#define RB_IN !digitalRead(26)
#define RT_IN !digitalRead(27)
#define LB_IN !digitalRead(21)
#define LT_IN !digitalRead(22)
#define MOD_IN !digitalRead(28)


#define LED_BLINK digitalWrite(0, HIGH); delay(1000); digitalWrite(0, LOW)
#define _1F delay(19)



#define MAX_FILE_NAME "lz" // lz = 2016 different profiles


std::vector<std::function<int()>> a_fire;
std::vector<std::function<int()>> b_fire;
std::vector<std::function<int()>> x_fire;
std::vector<std::function<int()>> y_fire;
std::vector<std::function<int()>> rb_fire;
std::vector<std::function<int()>> rt_fire;
std::vector<std::function<int()>> lb_fire;
std::vector<std::function<int()>> lt_fire;

std::vector<unsigned short> a_delay;
std::vector<unsigned short> b_delay;
std::vector<unsigned short> x_delay;
std::vector<unsigned short> y_delay;
std::vector<unsigned short> rb_delay;
std::vector<unsigned short> rt_delay;
std::vector<unsigned short> lb_delay;
std::vector<unsigned short> lt_delay;




String current_script = "";
String ip_address = "";

std::string ssid = "";
std::string password = "";
bool loop_exited = true;
bool park_loop = false;


