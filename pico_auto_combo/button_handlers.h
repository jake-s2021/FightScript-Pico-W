void handle_setup_1(){

  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);



  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(22, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);
  pinMode(27, INPUT_PULLUP);
  pinMode(28, INPUT_PULLUP);

  U_OFF;
  D_OFF;
  L_OFF;
  R_OFF;
  X_OFF;
  Y_OFF;
  A_OFF;
  B_OFF;
  RB_OFF;
  RT_OFF;
  LB_OFF;
  LT_OFF;

}

void handle_loop_1(){


    while(!(MOD_IN) || park_loop){

      loop_exited = true;

      if(A_IN){
              A_ON;
      }
      else{
              A_OFF;
      }
      if(B_IN){
              B_ON;
      }
      else{
              B_OFF;
      }
      if(X_IN){
              X_ON;
      }
      else{
              X_OFF;
      }
      if(Y_IN){
              Y_ON;
      }
      else{
              Y_OFF;
      }
      if(RB_IN){
              RB_ON;
      }
      else{
              RB_OFF;
      }
      if(RT_IN){
              RT_ON;
      }
      else{
              RT_OFF;
      }
      if(LB_IN){
              LB_ON;
      }
      else{
              LB_OFF;
      }
      if(LT_IN){
              LT_ON;
      }
      else{
              LT_OFF;
      }
    }

    loop_exited = false;

    while(MOD_IN && !park_loop){

       

      if(X_IN){
        auto i = 0;
        while(i < x_fire.size()){
          if(x_fire[i]()){
            delay(16*x_delay[i]);
          }
          i++;
        }
        while(X_IN){}
      }

      if(Y_IN){
        auto i = 0;
        while(i < y_fire.size()){
          if(y_fire[i]()){
            delay(16*y_delay[i]);
          }
          i++;
        }
        while(Y_IN){}
      }

      if(A_IN){
        auto i = 0;
        while(i < a_fire.size()){
          if(a_fire[i]()){
            delay(16*a_delay[i]);
          }
          i++;
        }
        while(A_IN){}
      }

      if(B_IN){
        auto i = 0;
        while(i < b_fire.size()){
          if(b_fire[i]()){
            delay(16*b_delay[i]);
          }
          i++;
        }
        while(B_IN){}
      }

      if(RB_IN){
        auto i = 0;
        while(i < rb_fire.size()){
          if(rb_fire[i]()){
            delay(16*rb_delay[i]);
          }
          i++;
        }
        while(RB_IN){}
      }

      if(RT_IN){
        auto i = 0;
        while(i < rt_fire.size()){
          if(rt_fire[i]()){
            delay(16*rt_delay[i]);
          }
          i++;
        }
        while(RT_IN){}
      }

      if(LB_IN){
        auto i = 0;
        while(i < lb_fire.size()){
          if(lb_fire[i]()){
            delay(16*lb_delay[i]);
          }
          i++;
        }
        while(LB_IN){}
      }

      if(LT_IN){
        auto i = 0;
        while(i < lt_fire.size()){
          if(lt_fire[i]()){
            delay(16*lt_delay[i]);
          }
          i++;
        }
        while(LT_IN){}
      }


    }
    loop_exited = true;
    delay(1);


}



int UPress(){
        U_ON;
        _1F;
        U_OFF;
        return 0;
}

int UHold(){
        U_ON;
        return 0;
}

int URel(){
        U_OFF;
        return 0;
}

int DPress(){
        D_ON;
        _1F;
        D_OFF;
        return 0;
}

int DHold(){
        D_ON;
        return 0;
}

int DRel(){
        D_OFF;
        return 0;
}

int LPress(){
        L_ON;
        _1F;
        L_OFF;
        return 0;
}

int LHold(){
        L_ON;
        return 0;
}

int LRel(){
        L_OFF;
        return 0;
}

int RPress(){
        R_ON;
        _1F;
        R_OFF;
        return 0;
}

int RHold(){
        R_ON;
        return 0;
}

int RRel(){
        R_OFF;
        return 0;
}

int APress(){
        A_ON;
        _1F;
        A_OFF;
        return 0;
}

int AHold(){
        A_ON;
        return 0;
}

int ARel(){
        A_OFF;
        return 0;
}

int BPress(){
        B_ON;
        _1F;
        B_OFF;
        return 0;
}

int BHold(){
        B_ON;
        return 0;
}

int BRel(){
        B_OFF;
        return 0;
}

int XPress(){
        X_ON;
        _1F;
        X_OFF;
        return 0;
}

int XHold(){
        X_ON;
        return 0;
}

int XRel(){
        X_OFF;
        return 0;
}

int YPress(){
        Y_ON;
        _1F;
        Y_OFF;
        return 0;
}

int YHold(){
        Y_ON;
        return 0;
}

int YRel(){
        Y_OFF;
        return 0;
}

int RBPress(){
        RB_ON;
        _1F;
        RB_OFF;
        return 0;
}

int RBHold(){
        RB_ON;
        return 0;
}

int RBRel(){
        RB_OFF;
        return 0;
}

int RTPress(){
        RT_ON;
        _1F;
        RT_OFF;
        return 0;
}

int RTHold(){
        RT_ON;
        return 0;
}

int RTRel(){
        RT_OFF;
        return 0;
}

int LBPress(){
        LB_ON;
        _1F;
        LB_OFF;
        return 0;
}

int LBHold(){
        LB_ON;
        return 0;
}

int LBRel(){
        LB_OFF;
        return 0;
}

int LTPress(){
        LT_ON;
        _1F;
        LT_OFF;
        return 0;
}

int LTHold(){
        LT_ON;
        return 0;
}

int LTRel(){
        LT_OFF;
        return 0;
}

int QCF(){
  D_ON;
  _1F;
  R_ON;
  _1F;
  D_OFF;
  _1F;
  R_OFF;
  return 0;
}

int QCB(){
  D_ON;
  _1F;
  L_ON;
  _1F;
  D_OFF;
  _1F;
  L_OFF;
  return 0;
}

int RQCF(){
  R_ON;
  _1F;
  D_ON;
  _1F;
  R_OFF;
  _1F;
  D_OFF;
  return 0;
}

int RQCB(){
  L_ON;
  _1F;
  D_ON;
  _1F;
  L_OFF;
  _1F;
  D_OFF;
  return 0;
}

int HCF(){
  L_ON;
  _1F;
  D_ON;
  _1F;
  L_OFF;
  _1F;
  R_ON;
  _1F;
  D_OFF;
  _1F;
  R_OFF;
  return 0;
}

int HCB(){
  R_ON;
  _1F;
  D_ON;
  _1F;
  R_OFF;
  _1F;
  L_ON;
  _1F;
  D_OFF;
  _1F;
  L_OFF;

  return 0;
}

int HCFB(){
  L_ON;
  _1F;
  D_ON;
  _1F;
  L_OFF;
  _1F;
  R_ON;
  _1F;
  D_OFF;
  _1F;
  R_OFF;
  L_ON;
  _1F;
  L_OFF;
  return 0;
}

int HCBF(){
  R_ON;
  _1F;
  D_ON;
  _1F;
  R_OFF;
  _1F;
  L_ON;
  _1F;
  D_OFF;
  _1F;
  L_OFF;
  R_ON;
  _1F;
  R_OFF;

  return 0;
}

int DP(){
  R_ON;
  _1F;
  R_OFF;
  D_ON;
  _1F;
  R_ON;
  _1F;
  D_OFF;
  R_OFF;
  return 0;
}

int RDP(){
  L_ON;
  _1F;
  L_OFF;
  D_ON;
  _1F;
  L_ON;
  _1F;
  D_OFF;
  L_OFF;
  return 0;
}

int SPD(){
  L_ON;
  _1F;
  L_OFF;
  D_ON;
  _1F;
  D_OFF;
  R_ON;
  _1F;
  R_OFF;
  U_ON;
  _1F;
  U_OFF;
  return 0;
}

int delay_frames(){
  return 1;
}