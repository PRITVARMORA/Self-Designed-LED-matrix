int p,i,j,h,k,e,m;

int a[10] = {1, 2, 3, 4, 5, 0, 0, 0, 0, 0};


void setup() {
 
pinMode (14,OUTPUT); 
pinMode (15,OUTPUT);
pinMode  (16,OUTPUT);

pinMode  (2,OUTPUT);
pinMode  (3,OUTPUT);
pinMode  (4,OUTPUT);
pinMode  (5,OUTPUT);
pinMode  (6,OUTPUT);
pinMode  (7,OUTPUT);

   

}

void loop() 
{ 
for(p=0;p<50;p++)
{
//----------------------------------------------------------------------------------  
digitalWrite (14,LOW);
digitalWrite (15,LOW);
digitalWrite (16,HIGH);
//----------------------------------------------------------------------------------
for (i=0;i<8 ;i++)
 { 
//---------------------------------------------------------------------------------clear input
digitalWrite (2,HIGH);
digitalWrite (3,HIGH);
digitalWrite (4,HIGH);
digitalWrite (5,HIGH);
digitalWrite (6,HIGH);
digitalWrite (7,HIGH);

//---------------------------------------------------------------------------------clock
  
digitalWrite (14,HIGH);
digitalWrite (14,LOW);
digitalWrite (15,HIGH);
digitalWrite (15,LOW);
//--------------------------------------------------------------------------------function
  alpha(a[i]);
  delay(1);
//--------------------------------------------------------------------------------serial data input
digitalWrite (16,LOW);
//------------------------------------------------------------------------------------------
}
}
shift(a);
delay(1);
}
///////////////////////////////////////////////////////////////////////////////////function---------

void alpha (int h)
{

 if (h==1)        {  int b[]={1,0,0,0,1,1};   logic(b);   }
 else if (h==2)   {  int b[]={1,0,0,1,0,1};   logic(b);   }
 else if (h==3)   {  int b[]={1,0,1,0,0,1};   logic(b);   }
 else if (h==4)   {  int b[]={1,1,0,0,0,1};   logic(b);   }
 else if (h==5)   {  int b[]={1,0,0,0,0,1};   logic(b);   }
else if (h==0)   {  int b[]={0,0,0,0,0,0};   logic(b);   }

}

/////////////////////////////////////////////////////////////////////////////////// logic
void logic (int f[])
{
  for ( e=0;e<6;e++)
  {
    int l=e+2;
    if (f[e]==1)
    digitalWrite (l,LOW);
  }

}   
////////////////////////////////////////////////////////////////////////////////////shift
void shift(int t[])
{
  m=t[9];
for (e=9;e>0;e--)
{
t[e]=t[e-1];
}
t[0]=m;
for (e=0;e<10;e++)
{
a[i]=t[i];
}

}

