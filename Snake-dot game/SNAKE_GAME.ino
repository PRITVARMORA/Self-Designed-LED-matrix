int u,d,r,l,b[7][9],a,m,k[2][10];
int i,j,v,s,crash;
long c[2][1];

void setup() {
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(18,INPUT_PULLUP);
  pinMode(19,INPUT_PULLUP);
  pinMode(20,INPUT_PULLUP);
  pinMode(21,INPUT_PULLUP);
 attachInterrupt(digitalPinToInterrupt(18), up , FALLING);
 attachInterrupt(digitalPinToInterrupt(19), down , FALLING);
 attachInterrupt(digitalPinToInterrupt(20), right , FALLING);
 attachInterrupt(digitalPinToInterrupt(21), left , FALLING);
 randomSeed(analogRead(A0));
 u=0;
 d=0;
 r=0;
 l=0;
crash=0;
for(j=0;j<9;j++)
{
for(i=0;i<7;i++)
{
  b[i][j]=0;
}
}
b[2][2]=1;
b[2][3]=1;
b[2][4]=1;
b[2][5]=1;
k[0][0]=2;
k[0][1]=2;
k[0][2]=2;
k[0][3]=2;
k[1][0]=5;
k[1][1]=4;
k[1][2]=3;
k[1][3]=2;
dsply(b);
m=2;
s=3;
rendomdot();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() 
{   
  for(i=0;i<s;i++)
  {
    if(k[0][i]==c[0][0] && k[1][i]==c[1][0] )
    {
      rendomdot();
      if(s<9)
      s++;
    }
  }
  if     (m==1) {u=1;}
  else if(m==2) {d=1;}
  else if(m==3) {l=1;}
  else if(m==4) {r=1;}
  
  for(v=0;v<600;v++)
  {
 if(u==1 && k[0][0]>0)
 {
  snakeshift();
  k[0][0]--;
  u=0;
  m=1;
   }
 
 else if(l==1 && k[1][0]>0)
 {snakeshift();
 k[1][0]--;
  l=0;
 m=3;
 }
 
 else if(d==1 && k[0][0]<7)
 {snakeshift();
 k[0][0]++;
  d=0;
  m=2;
 }
 
 else if(r==1 && k[1][0]<9)
 {snakeshift();
 k[1][0]++;
  r=0;
  m=4;
 }
 else if (k[1][0]==0 || k[1][0]==9 || k[0][0]==0 || k[0][0]==7) 
 crash=1;
 if (crash==0)
 {
 evaluet();
 evaluetdot();
 }
 else if(crash==1)
 evaluetcrash();
 dsply(b);
 
  }
}
////////////////////////////////////////////
void up()   {u=1;d=0;r=0;l=0;}
void down() {u=0;d=1;r=0;l=0;}
void right(){u=0;d=0;r=1;l=0;}
void left() {u=0;d=0;r=0;l=1;}
/////////////////////////////////////////////
void dsply(int a[][9])
{
  for(j=0;j<9;j++)
  {
  for(i=1;i<7;i++)
  {
    if(a[i][j] == 1)
    {
      digitalWrite(i,LOW);
    }
    else if(a[i][j] == 0)
    {
      digitalWrite(i,HIGH);
    }
  }
  if(j==0)             {digitalWrite(7,HIGH); }///SHCP clk
  digitalWrite(8,HIGH);/////ch clk
  digitalWrite(8,LOW);
  for(i=1;i<7;i++)     {digitalWrite(i,HIGH); }///ST_CP clk
  digitalWrite(9,HIGH);/////sr clk
  digitalWrite(9,LOW);
  digitalWrite(7,LOW); 
}}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void snakeshift()
{
  for(i=0;i<2;i++)
  {
for(j=s;j>0;j--)
{
   k[i][j]=k[i][j-1] ;
}
  }
}
void evaluet()
{
  for(j=0;j<9;j++)
  {
    for(i=0;i<7;i++)
    {
      b[i][j]=0;
    }
  }
  for(j=s;j>-1;j--)
    {
      b[k[0][j]][k[1][j]]=1;
    }

}
void rendomdot()
{
  c[0][0]=random(1,7);
  c[1][0]=random(1,9);
}
void evaluetdot()
{
  b[c[0][0]][c[1][0]]=1;
}
void evaluetcrash()
{
   for(j=0;j<9;j++)
  {
    for(i=0;i<7;i++)
    {
      b[i][j]=0;
    }
  }
  b[2][2]=1;
    b[3][2]=1;
      b[3][3]=1;
        b[2][3]=1;
          b[2][5]=1;
            b[2][6]=1;
              b[3][5]=1;
                b[3][6]=1;
                  b[6][2]=1;
  b[5][3]=1;
    b[5][4]=1;
      b[5][5]=1;
        b[6][6]=1;                    
  
}

