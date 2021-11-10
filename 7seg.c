#define d_a 12  //定义数码管a 接引脚 2
#define d_b 11
#define d_c 10
#define d_d 9
#define d_e 8
#define d_f 7
#define d_g 6
#define d_h 5

//const int seg7[] = {12, 11, 10, 9, 8, 7};

#define COM1 A3
#define COM2 A2
#define COM3 A1
#define COM4 A0

//const int scan[] = { A3, A2, A1, A0 };
int i, j, k, l, q, z;
int na, nb, nc, nd;
int tm=50;
int thu, hun, ten, one;

//数码管0-9码值
unsigned char num[17][8] =
{
 //a  b  c  d  e  f  g  h 
  {1, 1, 1, 1, 1, 1, 0, 0},     //0
  {0, 1, 1, 0, 0, 0, 0, 0},     //1
  {1, 1, 0, 1, 1, 0, 1, 0},     //2
  {1, 1, 1, 1, 0, 0, 1, 0},     //3
  {0, 1, 1, 0, 0, 1, 1, 0},     //4
  {1, 0, 1, 1, 0, 1, 1, 0},     //5
  {1, 0, 1, 1, 1, 1, 1, 0},     //6
  {1, 1, 1, 0, 0, 0, 0, 0},     //7
  {1, 1, 1, 1, 1, 1, 1, 0},     //8
  {1, 1, 1, 1, 0, 1, 1, 0},     //9
};

void setup()
{
  Serial.begin(9600);
  pinMode(d_a,OUTPUT);    //设置为输出引脚
  pinMode(d_b,OUTPUT);
  pinMode(d_c,OUTPUT);
  pinMode(d_d,OUTPUT);
  pinMode(d_e,OUTPUT);
  pinMode(d_f,OUTPUT);
  pinMode(d_g,OUTPUT);
  pinMode(d_h,OUTPUT);

  pinMode(COM1,OUTPUT);
  pinMode(COM2,OUTPUT);
  pinMode(COM3,OUTPUT);
  pinMode(COM4,OUTPUT);
//  pinMode(scan[A3],OUTPUT);
//  pinMode(scan[A2],OUTPUT);
//  pinMode(scan[A1],OUTPUT);
//  pinMode(scan[A0],OUTPUT);
}

void loop()
{

//  //累加循环当去到9999自动从0开机计数
 while(tm>=0){
    tm=i;
    i--;
    thu=i/1000;
    hun=(i-thu*100)/100;
    ten=(i-hun*100)/10;
    one=i-ten*10;
  }
  Serial.print(thu);
  delay(2);
  Serial.print(hun);
  delay(2);
  Serial.print(ten);
  delay(2);
  Serial.print(one);
  delay(2);
//            Display(1,thu);//第一位数码管显示l的值
//            delay(2);
//            Display(2,hun);//第二位数码管显示k的值
//            delay(2);
//            Display(3,ten);//第三位数码管显示j的值
//            delay(2);
//            Display(4,one);//第四位数码管显示i的值
//            delay(2);
//nd=9; //個
//nc=9; //十
//nb=9; //百
//na=9; //千
//z=0;
//  for(l=nd;l>=z;l--)
//  {
//    for(k=nc;k>=z;k--)
//    {
//      for(j=nb;j>=z;j--)
//      {
//        for(i=na;i>=z;i--)
//        {
//      //一秒钟快闪125次，就等于一秒，
//          //1000/8=125
//         for(q=0;q<125;q++)
//          {
//            
//            Display(1,l);//第一位数码管显示l的值
//            delay(2);
//            Display(2,k);//第二位数码管显示k的值
//            delay(2);
//            Display(3,j);//第三位数码管显示j的值
//            delay(2);
//            Display(4,i);//第四位数码管显示i的值
//            delay(2);
//            //delay(4);
//  } 
//  }
//  }
//  }
//  }


//  for(l=9;l>=0;l--)
//  {
//    for(k=9;k>=0;k--)
//    {
//      for(j=9;j>=0;j--)
//      {
//        for(i=9;i>=0;i--)
//        {
//          //一秒钟快闪125次，就等于一秒，
//          //1000/8=125
//          for(int q = 0;q<125;q++)
//          {
//            delay(1000);
//          }
//        }
//      }
//    }
//  }

}

void Display(unsigned char com,unsigned char n)     //显示函数，com可选数值范围1-4，num可选数值范围0-9
{
  digitalWrite(d_a,LOW);      //去除余晖
  digitalWrite(d_b,LOW);
  digitalWrite(d_c,LOW);
  digitalWrite(d_d,LOW);
  digitalWrite(d_e,LOW);
  digitalWrite(d_f,LOW);
  digitalWrite(d_g,LOW);
  digitalWrite(d_h,LOW);

  switch(com)           //选通位选
  {
    case 1:
      digitalWrite(COM1,LOW);   //选择位1
      digitalWrite(COM2,HIGH);
      digitalWrite(COM3,HIGH);
      digitalWrite(COM4,HIGH);
//      digitalWrite(scan[A3],0);   //选择位1
//      digitalWrite(scan[A2],1);
//      digitalWrite(scan[A1],1);
//      digitalWrite(scan[A0],1);
      break;
    case 2:
      digitalWrite(COM1,HIGH);
      digitalWrite(COM2,LOW);   //选择位2
      digitalWrite(COM3,HIGH);
      digitalWrite(COM4,HIGH);
//      digitalWrite(scan[A3],1);
//      digitalWrite(scan[A2],0);//选择位2
//      digitalWrite(scan[A1],1);
//      digitalWrite(scan[A0],1);
      break;
    case 3:
      digitalWrite(COM1,HIGH);
      digitalWrite(COM2,HIGH);
      digitalWrite(COM3,LOW);   //选择位3
      digitalWrite(COM4,HIGH);
//      digitalWrite(scan[A3],1);
//      digitalWrite(scan[A2],1);
//      digitalWrite(scan[A1],0);//选择位3
//      digitalWrite(scan[A0],1);
      break;
    case 4:
      digitalWrite(COM1,HIGH);
      digitalWrite(COM2,HIGH);
      digitalWrite(COM3,HIGH);
      digitalWrite(COM4,LOW);   //选择位4
//      digitalWrite(scan[A3],1);
//      digitalWrite(scan[A2],1);
//      digitalWrite(scan[A1],1);
//      digitalWrite(scan[A0],0);//选择位4
      break;
    default:break;
  }

  digitalWrite(d_a,num[n][0]);      //a查询码值表
  digitalWrite(d_b,num[n][1]);
  digitalWrite(d_c,num[n][2]);
  digitalWrite(d_d,num[n][3]);
  digitalWrite(d_e,num[n][4]);
  digitalWrite(d_f,num[n][5]);
  digitalWrite(d_g,num[n][6]);
  digitalWrite(d_h,num[n][7]);
}
