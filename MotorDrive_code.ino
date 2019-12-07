
void forw(int s){
  digitalWrite(f_in_L1,LOW);
  digitalWrite(f_in_L2,HIGH);
  digitalWrite(f_in_R1,LOW);
  digitalWrite(f_in_R2,HIGH);
  digitalWrite(r_in_L1, LOW);
  digitalWrite(r_in_L2, HIGH);
  digitalWrite(r_in_R1,LOW);
  digitalWrite(r_in_R2, HIGH);
  analogWrite(f_pwm1_R,s);
  analogWrite(f_pwm1_L,s);
  analogWrite(r_pwm1_R,s);
  analogWrite(r_pwm1_L,s);
}
void back(int s){
  digitalWrite(f_in_L1,HIGH);
  digitalWrite(f_in_L2,LOW);
  digitalWrite(f_in_R1,HIGH);
  digitalWrite(f_in_R2,LOW);
  digitalWrite(r_in_L1, HIGH);
  digitalWrite(r_in_L2, LOW);
  digitalWrite(r_in_R1, HIGH);
  digitalWrite(r_in_R2, LOW);
  analogWrite(f_pwm1_R,s);
  analogWrite(f_pwm1_L,s);
  analogWrite(r_pwm1_R,s);
  analogWrite(r_pwm1_L,s);
}
void left_turn(int s){
  digitalWrite(f_in_L1,HIGH);
  digitalWrite(f_in_L2,HIGH);
  digitalWrite(f_in_R1,LOW);
  digitalWrite(f_in_R2,HIGH);
  digitalWrite(r_in_L1, HIGH);
  digitalWrite(r_in_L2, HIGH);
  digitalWrite(r_in_R1, LOW);
  digitalWrite(r_in_R2, HIGH);
  analogWrite(f_pwm1_R,s);
  analogWrite(f_pwm1_L,255);
  analogWrite(r_pwm1_R,s);
  analogWrite(r_pwm1_L,255);  
}
void left_turn_back(int s){
  digitalWrite(f_in_L1,HIGH);
  digitalWrite(f_in_L2,HIGH);
  digitalWrite(f_in_R1,HIGH);
  digitalWrite(f_in_R2,LOW);
  digitalWrite(r_in_L1, HIGH);
  digitalWrite(r_in_L2, HIGH);
  digitalWrite(r_in_R1, HIGH);
  digitalWrite(r_in_R2, LOW);
  analogWrite(f_pwm1_R,s);
  analogWrite(f_pwm1_L,255);
  analogWrite(r_pwm1_R,s);
  analogWrite(r_pwm1_L,255);  
}
void right_turn(int s){
  digitalWrite(f_in_L1,LOW);
  digitalWrite(f_in_L2,HIGH);
  digitalWrite(f_in_R1,HIGH);
  digitalWrite(f_in_R2,HIGH);
  digitalWrite(r_in_L1, LOW);
  digitalWrite(r_in_L2, HIGH);
  digitalWrite(r_in_R1, HIGH);
  digitalWrite(r_in_R2, HIGH);
  analogWrite(f_pwm1_R,255);
  analogWrite(f_pwm1_L,s);
  analogWrite(r_pwm1_R,255);
  analogWrite(r_pwm1_L,s);  
}
void right_turn_back(int s){
  digitalWrite(f_in_L1,HIGH);
  digitalWrite(f_in_L2,LOW);
  digitalWrite(f_in_R1,HIGH);
  digitalWrite(f_in_R2,HIGH);
  digitalWrite(r_in_L1, HIGH);
  digitalWrite(r_in_L2, LOW);
  digitalWrite(r_in_R1, HIGH);
  digitalWrite(r_in_R2, HIGH);
  analogWrite(f_pwm1_R,255);
  analogWrite(f_pwm1_L,s);
  analogWrite(r_pwm1_R,255);
  analogWrite(r_pwm1_L,s);  
}

void left_rotate(int s){
  digitalWrite(f_in_L1,HIGH);
  digitalWrite(f_in_L2,LOW);
  digitalWrite(f_in_R1,LOW);
  digitalWrite(f_in_R2,HIGH);
  digitalWrite(r_in_L1, HIGH);
  digitalWrite(r_in_L2, LOW);
  digitalWrite(r_in_R1, LOW);
  digitalWrite(r_in_R2, HIGH);
  analogWrite(f_pwm1_R,s);
  analogWrite(f_pwm1_L,s);
  analogWrite(r_pwm1_R,s);
  analogWrite(r_pwm1_L,s);
}

void right_rotate(int s){
  digitalWrite(f_in_L1,LOW);
  digitalWrite(f_in_L2,HIGH);
  digitalWrite(f_in_R1,HIGH);
  digitalWrite(f_in_R2,LOW);
  digitalWrite(r_in_L1, LOW);
  digitalWrite(r_in_L2, HIGH);
  digitalWrite(r_in_R1, HIGH);
  digitalWrite(r_in_R2, LOW);
  analogWrite(f_pwm1_R,s);
  analogWrite(f_pwm1_L,s);
  analogWrite(r_pwm1_R,s);
  analogWrite(r_pwm1_L,s);  
}
void motor_stop(){
  digitalWrite(f_in_L1,LOW);
  digitalWrite(f_in_L2,LOW);
  digitalWrite(f_in_R1,LOW);
  digitalWrite(f_in_R2,LOW);
  digitalWrite(r_in_L1, LOW);
  digitalWrite(r_in_L2, LOW);
  digitalWrite(r_in_R1, LOW);
  digitalWrite(r_in_R2, LOW);
  analogWrite(f_pwm1_R,0);
  analogWrite(f_pwm1_L,0);
  analogWrite(r_pwm1_R,0);
  analogWrite(r_pwm1_L,0);
}

void active_break(){
  digitalWrite(f_in_L1,HIGH);
  digitalWrite(f_in_L2,HIGH);
  digitalWrite(f_in_R1,HIGH);
  digitalWrite(f_in_R2,HIGH);
  digitalWrite(r_in_L1, HIGH);
  digitalWrite(r_in_L2, HIGH);
  digitalWrite(r_in_R1, HIGH);
  digitalWrite(r_in_R2, HIGH);
  analogWrite(f_pwm1_R,255);
  analogWrite(f_pwm1_L,255);
  analogWrite(r_pwm1_R,255);
  analogWrite(r_pwm1_L,255);
  delay(20); 
  digitalWrite(f_in_L1,LOW);
  digitalWrite(f_in_L2,LOW);
  digitalWrite(f_in_R1,LOW);
  digitalWrite(f_in_R2,LOW);
  digitalWrite(r_in_L1, LOW);
  digitalWrite(r_in_L2, LOW);
  digitalWrite(r_in_R1, LOW);
  digitalWrite(r_in_R2, LOW);
  analogWrite(f_pwm1_R,0);
  analogWrite(f_pwm1_L,0);
  analogWrite(r_pwm1_R,0);
  analogWrite(r_pwm1_L,0);
}
