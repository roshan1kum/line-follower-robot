float kp=4.5,ki=10,kd=2.0;
float error=0,P=0,I=0,D=0,PID=0;
float prev_error=0,prev_I=0;
int s1=1,s2=1,s3=1,s4=1,s5=1,s6=1,s0=1,s7=1,a=0,b=0,l1=0,l2=1;
int initial_speed=120;
void read_sensor_values(void);
void calculate_pid(void);
void motor_control(void);
void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(2,INPUT);
    pinMode(4,INPUT);
    pinMode(7,INPUT);
    pinMode(8,INPUT);
    pinMode(13,INPUT);
    pinMode(3,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(9,OUTPUT); 
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
}
void loop()
{
    read_sensor_values();
    calculate_pid();
    motor_control();
}
void read_sensor_values()
{
    a=0;
    s0=digitalRead(A1);
    s1=digitalRead(2);
    s2=digitalRead(4);
    s3=digitalRead(7);
    s4=digitalRead(8);
    s5=digitalRead(13);
    s6=digitalRead(A2);
    s7=digitalRead(A0);

    if(s0==l2 && s1==l2 && s2==l2 && s3==l2 && s4==l2 && s5==l2 && s6==l2 && s7==l1)
    error=8;
    else if(s0==l2 && s1==l2 && s2==l2 && s3==l2 && s4==l2 && s5==l2 && s6==l1 && s7==l1)
    error=6;
    else if(s0==l2 && s1==l2 && s2==l2 && s3==l2 && s4==l2 && s5==l2 && s6==l1 && s7==l2)
    error=5;
    else if(s0==l2 && s1==l2 && s2==l2 && s3==l2 && s4==l2 && s5==l1 && s6==l1 && s7==l2)
    error=4;
    else if(s0==l2 && s1==l2 && s2==l2 && s3==l2 && s4==l2 && s5==l1 && s6==l2 && s7==l2)
    error=3;
    else if(s0==l2 && s1==l2 && s2==l2 && s3==l2 && s4==l1 && s5==l1 && s6==l2 && s7==l2)
    error=2;
    else if(s0==l2 && s1==l2 && s2==l2 && s3==l2 && s4==l1 && s5==l2 && s6==l2 && s7==l2)
    error=1;
    else if(s0==l2 && s1==l2 && s2==l2 && s3==l1 && s4==l1 && s5==l2 && s6==l2 && s7==l2)
    error=0;
    else if(s0==l2 && s1==l2 && s2==l2 && s3==l1 && s4==l2 && s5==l2 && s6==l2 && s7==l2)
    error=-1;
    else if(s0==l2 && s1==l2 && s2==l1 && s3==l1 && s4==l2 && s5==l2 && s6==l2 && s7==l2)
    error=-2;
    else if(s0==l2 && s1==l2 && s2==l1 && s3==l2 && s4==l2 && s5==l2 && s6==l2 && s7==l2)
    error=-3;
    else if(s0==l2 && s1==l1 && s2==l1 && s3==l2 && s4==l2 && s5==l2 && s6==l2 && s7==l2)
    error=-4;
    else if(s0==l2 && s1==l1 && s2==l2 && s3==l2 && s4==l2 && s5==l2 && s6==l2 && s7==l2)
    error=-5;
    else if(s0==l1 && s1==l1 && s2==l2 && s3==l2 && s4==l2 && s5==l2 && s6==l2 && s7==l2)
    error=-6;
    else if(s0==l1 && s1==l2 && s2==l2 && s3==l2 && s4==l2 && s5==l2 && s6==l2 && s7==l2)
    error=-8;
    else if(s0==l2 && s1==l2 && s2==l2 && s3==l2 && s4==l2 && s5==l2 && s6==l2  && s7==l2 && error==-7)
    error=-9;
    else if(s0==l2 && s1==l2 && s2==l2 && s3==l2 && s4==l2 && s5==l2 && s6==l2  && s7==l2 && error==7)
    error=9;
    
    if(s1==l2 && s2==l2 && s3==l2 && s4==l2 && s5==l2 && s6==l2)
    a=1;
   // else if((s1==l1 && s2==l1 && s3==l1) || (s2==l1 && s3==l1 && s4==l1) || (s3==l1 && s4==l1 && s5==l1) || (s4==l1 && s5==l1 && s6==l1) || (s5==l1 && s6==l1 && s7==l1))
    //a=4;
    //digitalWrite(LED_BUILTIN, LOW);
}
void calculate_pid()
{
    P=error;
    I=I+prev_I;
    D=error-prev_error;
    PID=(kp*P)+(ki*I)+(kd*D);
    prev_I=I;
    prev_error=error;
}
void motor_control()
{
    int left_speed=initial_speed+PID;
    int right_speed=initial_speed-PID;
    constrain(left_speed,0,255);
    constrain(right_speed,0,255);
    
    if(a==1)
    {
        analogWrite(5,90);
        analogWrite(9,90);
        analogWrite(3,0);
        analogWrite(6,0);
      
        
    }
    //else if(a==4)

    
       // digitalWrite(LED_BUILTIN, HIGH);
        
    
    else
    {
        analogWrite(3,left_speed);
        analogWrite(6,right_speed);
        digitalWrite(5,LOW);
        digitalWrite(9,LOW);
        analogWrite(10,255);
       analogWrite(11,255);
    }
}

 
