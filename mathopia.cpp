
#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<time.h>
#include<iomanip.h>
#include<stdlib.h>

ifstream f1;

int yolo=0, polo=0, a[2][2], b[3][3], c[2][2], d[3][3], rep=0, timeup=0, end=0, result[15][1], marks=0;
char choice, ques[3]="a", userans[15][15], actans[15][15];
const float pi=3.141;
time_t t1,t2;

void assign()
{
 for(int i=0;i<15;i++)
 {
  strcpy(userans[i]," ");
  strcpy(actans[i]," ");
 }
}

int min=20,n=1,sec=0,once=0;
void timecnt(int check=0)
{
 int f=0;
 t2=time(NULL);
 sec=t2-t1;
 gotoxy(58,5);
 if(min>9)
  cout<<"TIME LEFT - "<<min<<" : ";
 else
  cout<<"TIME LEFT - 0"<<min<<" : ";
 if(sec>=60 || sec==0)
 {
  if(sec==0 && once==0)
  {
   min--; cout<<"00"; t2=time(NULL);
   delay(1000); sec=t2-t1;
   once=1; f=1;
  }
  else if(sec!=0)
  {
   sec=(60-(60*n-sec));
   if(sec%60==0)
   {
    min--; n++;
   }
  }
 }
 if(sec==0 && f==0)
  cout<<"00";
 else if((60-sec)>9 && f==0)
  cout<<60-sec;
 else if((60-sec)<=9 && f==0)
  cout<<'0'<<60-sec;
 if(sec>=1200)
  timeup=1;
 if(check==1)
  delay(1000);
}

void timemanage()
{
 while(!kbhit())
 {
  timecnt(1);
  if(timeup==1)
   break;
 }
}

void copy1()
{
 settextstyle(SMALL_FONT,HORIZ_DIR,5);
 time_t now; now=time(&now); tm*ltm=localtime(&now);
 gotoxy(63,2);
 /*if(ltm->tm_min<10 && ltm->tm_sec<10)
  cout<<ltm->tm_hour<<" : "<<'0'<<ltm->tm_min<<" : "<<'0'<<ltm->tm_sec;
 else if(ltm->tm_min<10)
  cout<<ltm->tm_hour<<" : "<<'0'<<ltm->tm_min<<" : "<<ltm->tm_sec;
 else if(ltm->tm_sec<10)
  cout<<ltm->tm_hour<<" : "<<ltm->tm_min<<" : "<<'0'<<ltm->tm_sec;
 else*/
  cout<<ltm->tm_hour<<" : "<<ltm->tm_min<<" : "<<ltm->tm_sec;
 gotoxy(7,2);
 /*if(ltm->tm_mday<10 && 1+ltm->tm_mon<10)
  cout<<'0'<<ltm->tm_mday<<" - "<<'0'<<1+ltm->tm_mon<<" - "<<1900+ltm->tm_year;
 else if(ltm->tm_mday<10)
  cout<<'0'<<ltm->tm_mday<<" - "<<1+ltm->tm_mon<<" - "<<1900+ltm->tm_year;
 else if(1+ltm->tm_mon<10)
  cout<<ltm->tm_mday<<" - "<<'0'<<1+ltm->tm_mon<<" - "<<1900+ltm->tm_year;
 else*/
  cout<<ltm->tm_mday<<" - "<<1+ltm->tm_mon<<" - "<<1900+ltm->tm_year;
}

void copy2()
{
 settextstyle(SMALL_FONT,HORIZ_DIR,5);
 outtextxy(10,20,"Max Marks = 15 * 2 = 30");
 outtextxy(465,20,"Max Time = 20 min");
 outtextxy(25,440,"PRESS Q TO QUIT THE TEST");
 outtextxy(400,440,"PRESS ESC TO EXIT THE PROGRAM");
}

void graphics(char check='n')
{
 clrscr();
 cleardevice();
 setbkcolor(LIGHTBLUE);
 setcolor(WHITE);
 setfillstyle(SOLID_FILL,YELLOW);
 bar(0,0,getmaxx(),10);
 bar(0,48,217,58);
 bar(425,48,getmaxx(),58);
 bar(217,45,425,50);
 bar(0,420,getmaxx(),430);
 bar(0,(getmaxy()-10),getmaxx(),getmaxy());
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
 outtextxy(232,12,"M A T H O P i A");
 settextstyle(SMALL_FONT,HORIZ_DIR,5);
 if(check=='t')
 {
  copy2();
  outtextxy(180,390,"Press enter to submit your answer.");
  timecnt();
 }
 else if(check=='s')
 {
  copy2();
  outtextxy(102,387,"Which question do you want to answer? ___");
  timecnt();
 }
 else if(check=='1' || check=='2')
 {
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
  outtextxy(280,90,"RESULT");
  settextstyle(SMALL_FONT,HORIZ_DIR,6);
  outtextxy(140,275,"Do you want the analysis of the test?");
  setfillstyle(SOLID_FILL,RED);
  if(check=='1')
   bar(220,315,270,340);
  else if(check=='2')
   bar(352,315,402,340);
  outtextxy(230,320,"YES");
  outtextxy(365,320,"NO");
  copy1();
  outtextxy(15,440,"PRESS Q TO RETURN TO PREVIOUS MENU");
  outtextxy(400,440,"PRESS ESC TO EXIT THE PROGRAM");
  for(int i=0;i<15;i++)
   if(result[i][0]==1)
    marks+=2;
  gotoxy(28,12);
  cout<<"MARKS OBTAINED :   "<<marks<<" / 30 ";
 }
 else if(check=='a')
 {
  copy1();
  outtextxy(220,440,"PRESS ENTER TO CONTINUE");
 }
 else if(check=='n')
 {
  outtextxy(15,440,"PRESS Q TO RETURN TO PREVIOUS MENU");
  outtextxy(400,440,"PRESS ESC TO EXIT THE PROGRAM");
  copy1();
 }
 gotoxy(1,1); cout<<endl<<endl<<endl<<endl<<endl;
}

void keyhit()
{
 while(!kbhit())
  copy1();
 choice=getch();
 if(choice==27)
  end=1;
 if(choice=='q')
  end=2;
}

void analysis()
{
 char r='1'; int q=0;
 while(end==0)
 {
  graphics(r);
  keyhit();
  switch(choice)
  {
   case 77: r='2'; break;
   case 75: r='1'; break;
   case 13: {
	     if(r=='2')
	      end=2;
	     else if(r=='1')
	     {
	      graphics('a'); q=0;
	      settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	      outtextxy(215,85,"ANALYSIS OF TEST");
	      gotoxy(5,13); cout<<"MARKS OBTAINED :   "<<marks<<" / 30 ";
	      for(int i=0;i<15;i++)
	       if(userans[i][0]!=' ')
		q++;
	      gotoxy(5,16);
	       cout<<"QUESTIONS ANSWERED :   "<<q;
	      gotoxy(5,19);
	       cout<<"QUESTIONS CORRECT :   "<<marks/2;
	      gotoxy(47,9);
	       cout<<"YOUR ANSWER"<<"\t"<<"CORRECT ANSWER";
	      int y=11;
	      for(i=0;i<15;i++,y++)
	      {
	       gotoxy(43,y); cout<<'Q'<<i+1<<")  ";
	       if(userans[i][0]!=' ')
		puts(userans[i]);
	       else
		cout<<"NOT ANSWERED";
	       gotoxy(68,y); puts(actans[i]);
	      }
	      setfillstyle(SOLID_FILL,YELLOW);
	      bar(getmaxx()/2-2,120,getmaxx()/2+2,420);
	      getch();
	      end=2;
	     }
	    }
  }
 }
 if(end==2)
  end=0;
}

void mainscreen(int z)
{
 graphics();
 int x=20,y=195;
 setfillstyle(SOLID_FILL,YELLOW);
 bar(207,0,217,420);
 bar(415,0,425,420);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
 for(int i=0;i<3;i++)
 {
  if((i+1)==z)
  {
   setfillstyle(SOLID_FILL,RED);
   bar(x,y,x+160,y+40);
  }
  switch(i)
  {
   case 0: outtextxy(40,200,"LEARNING"); break;
   case 1: outtextxy(270,200,"DOUBTS"); break;
   case 2: outtextxy(500,200,"TESTS"); break;
  }
  x=x+215;
 }
}

void outputlearn(int z)
{
 int x=15,y=70;
 graphics();
 settextstyle(SMALL_FONT,HORIZ_DIR,5);
 for(int i=0;i<10;i++)
 {
  if((i+1)==z)
  {
   setfillstyle(SOLID_FILL,RED);
   bar(0,y-5,x+360,y+20);
  }
  switch(i)
  {
   case 0 :outtextxy(x,y,"Chapter 1:  Linear Equations In One Variable"); break;
   case 1 :outtextxy(x,y,"Chapter 2:  Linear Equations In Two Variables"); break;
   case 2 :outtextxy(x,y,"Chapter 3:  Quadratic Equations"); break;
   case 3 :outtextxy(x,y,"Chapter 4:  Cubic Equations"); break;
   case 4 :outtextxy(x,y,"Chapter 5:  Matrices"); break;
   case 5 :outtextxy(x,y,"Chapter 6:  Determinants"); break;
   case 6 :outtextxy(x,y,"Chapter 7:  Geometrical Figures"); break;
   case 7 :outtextxy(x,y,"Chapter 8:  Trigonometry"); break;
   case 8 :outtextxy(x,y,"Chapter 9:  Logarithmic and Exponential Functions"); break;
   case 9 :outtextxy(x,y,"Chapter 10: Numbers"); break;
  }
  y=y+30;
 }
}

void outputdoubts(int z)
{
 int x=15,y=70;
 graphics();
 settextstyle(SMALL_FONT,HORIZ_DIR,5);
 for(int i=0;i<7;i++)
 {
  if((i+1)==z)
  {
   setfillstyle(SOLID_FILL,RED);
   bar(0,y-5,x+200,y+20);
  }
  switch(i)
  {
   case 0 : outtextxy(x,y,"1. Solving Equations"); break;
   case 1 : outtextxy(x,y,"2. Shapes and Figures"); break;
   case 2 : outtextxy(x,y,"3. Matrices"); break;
   case 3 : outtextxy(x,y,"4. Basic Trigonometry"); break;
   case 4 : outtextxy(x,y,"5. Logarithm"); break;
   case 5 : outtextxy(x,y,"6. Exponential"); break;
   case 6 : outtextxy(x,y,"7. Arithematic Operations"); break;
  }
  y=y+40;
 }
}

void outputtests(int z)
{
 int x=15,y=100;
 graphics();
 settextstyle(SMALL_FONT,HORIZ_DIR,5);
 for(int i=0;i<10;i++)
 {
  if((i+1)==z)
  {
   setfillstyle(SOLID_FILL,RED);
   bar(0,y-5,x+250,y+20);
  }
  switch(i)
  {
   case 0 : outtextxy(x,y,"TEST-1"); break;
   case 1 : outtextxy(x,y,"TEST-2"); break;
   case 2 : outtextxy(x,y,"TEST-3"); break;
  }
  y=y+70;
 }
}

void readmainL(char a)
{
 while(!f1.eof())
 {
  f1.get(a);
  cout<<a;
 }
 getch();
}

void readlearn(int z)
{
 char a,b[25];
 int pos[5]={0,0,0,0,0};
 switch(z)
 {
  case 1:{
	  f1.open("Chap1");
	  readmainL(a); break;
	 }
  case 2:{
	  f1.open("Chap2");
	  readmainL(a); break;
	 }
  case 3:{
	  f1.open("Chap3");
	  readmainL(a); break;
	 }
  case 4:{
	  f1.open("Chap4");
	  readmainL(a); break;
	 }
  case 5:{
	  f1.open("Chap5");
	  while(!f1.eof())
	  {
	   f1>>b;
	   if(strcmp(b,"column.")==0)
	   {
	    pos[0]=f1.tellg()+1;
	   }
	   if(strcmp(b,"2_|")==0)
	   {
	    pos[1]=f1.tellg()+1;
	   }
	   if(strcmp(b,"example")==0)
	   {
	    pos[2]=f1.tellg()+1;
	   }
	   if(strcmp(b,"co-factors}")==0)
	   {
	    pos[3]=f1.tellg()+1; break;
	   }
	  } f1.close(); f1.open("Chap5");
	  while(!f1.eof())
	  {
	   f1.get(a);
	   if(f1.tellg()==pos[0] || f1.tellg()==pos[1] || f1.tellg()==pos[2] || f1.tellg()==pos[3])
	   {
	    getch();
	    graphics('a');
	   } cout<<a;
	  }
	  getch(); break;
	 }
  case 6:{
	  f1.open("Chap6");
	  while(!f1.eof())
	  {
	   f1>>b;
	   if(strcmp(b,"determinants.")==0)
	   {
	    pos[0]=f1.tellg()+1; break;
	   }
	  } f1.close(); f1.open("Chap6");
	  while(!f1.eof())
	  {
	   f1.get(a);
	   if(f1.tellg()==pos[0])
	   {
	    getch();
	    graphics('a');
	   } cout<<a;
	  }
	  getch(); break;
	 }
  case 7:{
	  f1.open("Chap7");
	  while(!f1.eof())
	  {
	   f1>>b;
	   if(strcmp(b,"triangle.")==0)
	   {
	    pos[0]=f1.tellg()+1;
	   }
	   if(strcmp(b,"3*3.14*radius*radius")==0)
	   {
	    pos[1]=f1.tellg()+1;
	   }
	  } f1.close(); f1.open("Chap7");
	  while(!f1.eof())
	  {
	   f1.get(a);
	   if(f1.tellg()==782 || f1.tellg()==1393)
	   {
	    getch(); graphics('a');
	   } cout<<a;
	  }
	  getch(); break;
	 }
  case 8:{
	  f1.open("Chap8");
	  readmainL(a); break;
	 }
  case 9:{
	  f1.open("Chap9");
	  readmainL(a); break;
	 }
  case 10:{
	   f1.open("Chap10");
	   readmainL(a); break;
	  }
 }
 f1.close();
}

void readmainA(char a[15])
{
 int i=0,j=0;
 while(!f1.eof())
 {
  f1>>a; j=0;
  while(j<strlen(a))
  {
   if(a[2]==')')
    actans[i][j]=a[j+3];
   else
    actans[i][j]=a[j+4];
   j++;
  }
  i++;
  if(i==15)
   break;
 }
}

void readans(int z)
{
 char a[15];
 switch(z)
 {
  case 1:{
	  f1.open("Ans1"); readmainA(a); break;
	 }
  case 2:{
	  f1.open("Ans2"); readmainA(a); break;
	 }
  case 3:{
	  f1.open("Ans3"); readmainA(a); break;
	 }
 }
 f1.close();
}

void readT1(char a[20])
{
 if(a[0]=='Q' && a[1]==ques[0] && ques[0]=='9' && a[2]==')')
  while(strcmpi(a,"Q10)")!=0)
  {
   cout<<' '<<a;
   f1>>a;
  }
 else if(a[0]=='Q' && a[1]==ques[0] && a[2]==')')
  while(a[1]!=ques[0]+1)
  {
   if(a[0]=='Q' && a[2]==')')
    cout<<endl<<' '<<a<<"  ";
   else
    cout<<a<<' ';
   f1>>a;
  }
}

void readT2(char a[20])
{
 if(a[0]=='Q' && a[1]==ques[0] && a[2]==ques[1] && ques[1]=='5' && a[3]==')')
  while(!f1.eof())
  {
   if(a[0]=='Q' && a[3]==')')
    cout<<endl<<' '<<a<<"  ";
   else
    cout<<a<<' ';
   f1>>a;
  }
 else if(a[0]=='Q' && a[1]==ques[0] && a[2]==ques[1] && a[3]==')')
  while(a[2]!=ques[1]+1)
  {
   if(a[0]=='Q' && a[3]==')')
    cout<<endl<<' '<<a<<"  ";
   else
    cout<<a<<' ';
   f1>>a;
  }
}

void readmainT(char a[20])
{
 while(!f1.eof())
 {
  f1>>a;
  if(strlen(ques)==1 && isdigit(ques[0]) && ques[0]>0)
   readT1(a);
  else if(strlen(ques)==2 && ques[0]=='1' && isdigit(ques[1]) && ques[1]<'6')
  {
   readT2(a);
  }
  else
  {
   if(!strcmpi(a,"Test-1") || !strcmpi(a,"Test-2") || !strcmpi(a,"Test-3"))
    cout<<"\t\t\t\t    "<<a<<endl;
   else if(a[0]=='Q' && (a[2]==')' || a[3]==')'))
    cout<<endl<<' '<<a<<"  ";
   else
    cout<<a<<' ';
  }
 }
}

void readtests(int z)
{
 char a[20]; int lim=atoi(ques);
 switch(z)
 {
  case 1:{
	  f1.open("Test1");
	  readmainT(a); break;
	 }
  case 2:{
	  f1.open("Test2");
	  readmainT(a); break;
	  }
  case 3:{
	  f1.open("Test3");
	  readmainT(a); break;
	  }
 }
 f1.close();
 if(userans[lim-1][0]==' ' && lim!=0)
  if((strlen(ques)==1 && isdigit(ques[0])) || (strlen(ques)==2 && isdigit(ques[0]) && ques[1]<'6'))
  {
   cout<<endl<<endl<<"ANSWER:  ";
   timemanage(); gotoxy(10,9); gets(userans[lim-1]);
  }
}

void testresult()
{
 for(int i=0;i<15;i++)
 {
  if(strcmpi(userans[i],actans[i])==0)
   result[i][0]=1;
  else
   result[i][0]=0;
 }
 cleardevice();
 setbkcolor(BLACK);
 delay(2000);
 graphics('r');
 analysis();
}

void dispcontent2(int array[2][2])
{
 for (int i=0;i<2;i++)
 {
  cout<<"|"<<' ';
  for (int j=0;j<2;j++)
   cout<<array[i][j]<<' ';
  cout<<"|"<<endl<<"    ";
 }
}

void dispcontent3(int array[3][3])
{
 for (int i=0;i<3;i++)
 {
  cout<<"|"<<' ';
  for (int j=0;j<3;j++)
   cout<<array[i][j]<<' ';
  cout<<"|"<<endl<<"    ";
 }
}

void matrixdisp()
{
 if(polo==1)
 {
  cout<<"a = "; dispcontent2(a);
  cout<<endl<<"b = "; dispcontent2(c);
 }
 else if(polo==2)
 {
  cout<<"a = "; dispcontent3(b);
  cout<<endl<<"b = "; dispcontent3(d);
 }
 else if(yolo==1)
 {
  cout<<"a = ";
  dispcontent2(a);
 }
 else if(yolo==2)
 {
  cout<<"a = ";
  dispcontent3(b);
 }
 cout<<endl<<endl;
}

void accept(char opt)
{
 if(opt=='1')
 {
  cout<<"Enter elements of a 2 X 2 matrix"<<endl<<endl;
  if(rep==0)
  {
   cout<<"a = ";
   yolo=1;
  }
  else if(rep==1)
  {
   cout<<"b = ";
   polo=1;
  }
  for (int i=0;i<2;i++)
  {
   for (int j=0;j<2;j++)
   {
    if(rep==0)
     cin>>a[i][j];
    else if(rep==1)
     cin>>c[i][j];
   }
  }
 }
 else if(opt=='2')
 {
  cout<<"Enter elements of a 3 X 3 matrix"<<endl<<endl;
  if(rep==0)
  {
   cout<<"a = ";
   yolo=2;
  }
  else if(rep==1)
  {
   cout<<"b = ";
   polo=2;
  }
  for (int i=0;i<3;i++)
  {
   for (int j=0;j<3;j++)
   {
    if(rep==0)
     cin>>b[i][j];
    else if(rep==1)
     cin>>d[i][j];
   }
  }
 }
 cout<<endl;
 rep++;
}

void trace()
{
 cout<<"Trace of a matrix is the sum of the elements present along the major diagonal"<<endl<<endl;
 cout<<"Thus, the trace of the matrix is: "<<endl;
 cout<<"tr(a) = ";
 if (yolo == 1)
 {
  int x=0;
  x = a[0][0] + a[1][1];
  if (a[1][1] >= 0)
   cout<<a[0][0]<<" + "<<a[1][1]<<endl;
  else
   cout<<a[0][0]<<" + "<<'('<<a[1][1]<<')'<<endl;
  cout<<"      = "<<x;
   }
  else if (yolo == 2)
   {
    int x=a[0][0]+a[1][1]+a[2][2];
    if (a[1][1] >= 0 && a[2][2] >= 0)
     cout<<a[0][0]<<" + "<<a[1][1]<<" + "<<a[2][2]<<endl;
    else if (a[1][1] < 0 && a[2][2] < 0)
     cout<<a[0][0]<<" + "<<'('<<a[1][1]<<')'<<" + "<<'('<<a[2][2]<<')'<<endl;
    else if (a[1][1] >= 0 && a[2][2] < 0)
     cout<<a[0][0]<<" + "<<a[1][1]<<" + "<<'('<<a[2][2]<<')'<<endl;
    else if (a[1][1] < 0 && a[2][2] >= 0)
     cout<<a[0][0]<<" + "<<'('<<a[1][1]<<')'<<" + "<<a[2][2]<<endl;
    cout<<"      = "<<x<<endl;
   }
 getch();
}

void power(char opt)
{
 graphics();
 matrixdisp();
 if (yolo == 1)
 {
  int k=0;
  for (int i=0;i<2;i++)
  {
   for (int j=0;j<2;j++)
   {
    if (i==0)
     k=1;
    else
     k=0;
    b[i][j] = (a[i][i] * a[i][j]) + (a[i][k] * a[k][j]);
   }
  }
  if (opt=='1')
  {
   cout<<"a^2 = ";
   for (int i=0;i<2;i++)
   {
    cout<<"|"<<' ';
    for (int j=0;j<2;j++)
    cout<<b[i][j]<<' ';
    cout<<"|"<<endl<<"      ";
   }
   cout<<endl;
  }
  else if(opt=='2')
  {
   cout<<"a^3 = ";
   for (int i=0;i<2;i++)
   {
    cout<<"|"<<' ';
    for (int j=0;j<2;j++)
    {
     if (i==0)
      k=1;
     else
      k=0;
     cout<<(b[i][i]*a[i][j])+(b[i][k]*a[k][j])<<' ';
    }
    cout<<"|"<<endl<<"      ";
   }
   cout<<endl;
  }
 }
 else if (yolo == 2)
 {
  int k=0, t=0;
  for (int i=0;i<3;i++)
  {
   for (int j=0;j<3;j++)
   {
    if (i==0)
    {
     k=1;
     t=2;
    }
    else if (i==1)
    {
     k=0;
     t=2;
    }
    else
    {
     k=1;
     t=0;
    }
    b[i][j] = (a[i][i]*a[i][j]) + (a[i][k]*a[k][j]) + (a[i][t]*a[t][j]);
   }
  }
  if (opt=='1')
  {
   cout<<"a^2 = ";
   for (int i=0;i<3;i++)
   {
    cout<<"|"<<' ';
    for (int j=0;j<3;j++)
     cout<<b[i][j]<<' ';
    cout<<"|"<<endl<<"      ";
   }
  }
  else if (opt=='2')
  {
   cout<<"a^3 =";
   for (int i=0;i<3;i++)
   {
    cout<<"|"<<' ';
    for (int j=0;j<3;j++)
    {
     if (i==0)
     {
      k=1;
      t=2;
     }
     else if (i==1)
     {
      k=0;
      t=2;
     }
     else
     {
      k=1;
      t=0;
     }
     cout<<(b[i][i]*a[i][j]) + (b[i][k]*a[k][j]) + (a[i][t]*a[t][j]);
    }
    cout<<"|"<<endl<<"      ";
   }
  }
 }
 getch();
}

void det()
{
 if (yolo == 1)
 {
  int x = a[0][0] * a[1][1];
  int y = a[0][1] * a[1][0];
  cout<<"For a 2 X 2 matrix, determinant can be found by,"<<endl<<endl;
  cout<<"det(a) = {   { Product of elements  -  { Product of elements    }"<<endl;
  cout<<"                 of major row }            of minor row }"<<endl<<endl;
  if(y>=0)
  cout<<"       = "<<x<<" - "<<y<<endl;
  else
  cout<<"       = "<<x<<" - "<<'('<<y<<')'<<endl;
  cout<<"       = "<<x-y<<endl;
 }
 else if (yolo == 2)
 {
  int x = (b[1][1] * b[2][2] - b[2][1] * b[1][2]);
  int y = (b[1][0] * b[2][2] - b[2][0] * b[1][2]);
  int z = (b[1][0] * b[2][1] - b[2][0] * b[1][1]);
  int k = (b[0][0] * x) - (b[0][1] * y) + (b[0][2] * z);
  cout<<"For a 3 X 3 matrix, determinant can be found by,"<<endl<<endl;
  cout<<"det(a) = {  { Product of first  _ { Product of second - { Product of third  }"<<endl;
  cout<<"		     element of first       element of first     element of first "<<endl;
  cout<<"		      row with its           row with its         row with its "<<endl;
  cout<<"                cofactor }             cofactor }           cofactor } "<<endl<<endl;
  cout<<"       = [("<<b[0][0]<<")*("<<x<<")] + [("<<b[0][1]<<")*("<<-y<<")] + [("<<b[0][2]<<")*("<<z<<")]"<<endl;
  cout<<"       = "<<'('<<b[0][0]*x<<") + ("<<b[0][1]*(-y)<<") + ("<<b[0][2]*z<<')'<<endl;
  cout<<"       = "<<k<<endl;
 }
 getch();
}

void adjoint()
{
 cout<<"Adjoint of any matrix is the transpose of the matrix formed by its co-factors"<<endl<<endl;
 cout<<"The matrix of the co-factors of the given matrix is:"<<endl<<endl;
 if (yolo == 1)
 {
  int c[3][3];
  for (int i=0;i<2;i++)
  {
   for (int j=0;j<2;j++)
   if (i!=j)
   c[i][j] = - (a[i][j]);
  }
  c[0][0]=a[1][1];   c[1][1]=a[0][0];
  cout<<"A = ";
  for (i=0;i<2;i++)
  {
   cout<<"|"<<' ';
   for (int j=0;j<2;j++)
   cout<<c[j][i]<<' ';
   cout<<"|"<<endl<<"    ";
  }
  cout<<endl<<"Thus, Adjoint of the matrix entered is:"<<endl<<endl;
  cout<<"adj(a) = A'"<<endl;
  cout<<"       = ";
  for (i=0;i<2;i++)
  {
   cout<<"|"<<' ';
   for (int j=0;j<2;j++)
   cout<<c[i][j]<<' ';
   cout<<"|"<<endl<<"         ";
  }
 }
 else if (yolo == 2)
 {
  int c[3][3];
  c[0][0] = (b[1][1] * b[2][2]) - (b[2][1] * b[1][2]);
  c[0][1] = -((b[1][0] * b[2][2]) - (b[2][0] * b[1][2]));
  c[0][2] = (b[1][0] * b[2][1]) - (b[2][0] * b[1][1]);
  c[1][0] = -((b[0][1] * b[2][2]) - (b[2][1] * b[0][2]));
  c[1][1] = (b[0][0] * b[2][2]) - (b[2][0] * b[0][2]);
  c[1][2] = -((b[0][0] * b[2][1]) - (b[2][0] * b[0][1]));
  c[2][0] = (b[0][1] * b[1][2]) - (b[1][1] * b[0][2]);
  c[2][1] = -((b[0][0] * b[1][2]) - (b[1][0] * b[0][2]));
  c[2][2] = (b[0][0] * b[1][1]) - (b[1][0] * b[0][1]);
  cout<<"A = ";
  for (int i=0;i<3;i++)
  {
   cout<<'|'<<' ';
   for (int j=0;j<3;j++)
   cout<<c[j][i]<<' ';
   cout<<'|'<<endl<<"    ";
  }
  cout<<endl<<"Adjoint of the matrix entered is :"<<endl<<endl;
  cout<<"adj(a) = A'"<<endl;;
  cout<<"       = ";
  for (i=0;i<3;i++)
  {
   cout<<"|"<<' ';
   for (int j=0;j<3;j++)
   cout<<c[i][j]<<' ';
   cout<<"|"<<endl<<"         ";
  }
 }
 getch();
}

void inv()
{
 cout<<"Inverse of any matrix 'a' is given as :"<<endl;
 cout<<"  a^-1 = adj(a) / |a|"<<endl<<endl;
 if (yolo == 1)
 {
  int c[2][2];
  for(int i=0;i<2;i++)
  {
   for(int j=0;j<2;j++)
   if(i!=j)
   c[i][j]=-(a[i][j]);
  }
  c[1][1]=a[0][0];  c[0][0]=a[1][1];
  int x = (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);
  if (x==0)
  cout<<"The inverse of the entered matrix doesn't exist as |a| = 0"<<endl;
  else
  {
   cout<<"Thus, Inverse of the given matrix is "<<endl;
   cout<<"a^-1 = "<<'('<<float(1/x)<<')';
   for (i=0;i<2;i++)
   {
    cout<<"|"<<' ';
    for(int j=0;j<2;j++)
    cout<<c[i][j]<<' ';
    cout<<'|'<<endl<<"       ";
   }
   cout<<endl<<"     = ";
   for (i=0;i<2;i++)
   {
    cout<<"|"<<' ';
    for (int j=0;j<2;j++)
    cout<<float(c[i][j]/x)<<' ';
    cout<<'|'<<endl<<"       ";
   }
  }
 }
 else if (yolo == 2)
 {
  int c[3][3];
  c[0][0] = (b[1][1] * b[2][2]) - (b[2][1] * b[1][2]);
  c[0][1] = -((b[1][0] * b[2][2]) - (b[2][0] * b[1][2]));
  c[0][2] = (b[1][0] * b[2][1]) - (b[2][0] * b[1][1]);
  c[1][0] = -((b[0][1] * b[2][2]) - (b[2][1] * b[0][2]));
  c[1][1] = (b[0][0] * b[2][2]) - (b[2][0] * b[0][2]);
  c[1][2] = -((b[0][0] * b[2][1]) - (b[2][0] * b[0][1]));
  c[2][0] = (b[0][1] * b[1][2]) - (b[1][1] * b[0][2]);
  c[2][1] = -((b[0][0] * b[1][2]) - (b[1][0] * b[0][2]));
  c[2][2] = (b[0][0] * b[1][1]) - (b[1][0] * b[0][1]);
  int x = (b[0][0] * c[0][0]) + (b[0][1] * c[0][1]) + (b[0][2] * c[0][2]);
  if (x==0)
  cout<<"The inverse of the entered matrix doesn't exist as |a| = 0"<<endl;
  else
  {
   cout<<"Thus, Inverse of the given matrix is "<<endl;
   cout<<"a^-1 = "<<'('<<float(1/x)<<')';
   for (int i=0;i<3;i++)
   {
    cout<<"|"<<' ';
    for (int j=0;j<3;j++)
    cout<<c[i][j]<<' ';
    cout<<'|'<<endl<<"       ";
   }
   cout<<endl<<"     = ";
   for (i=0;i<3;i++)
   {
    cout<<'|'<<' ';
    for (int j=0;j<3;j++)
    cout<<float(c[i][j]/x)<<' ';
    cout<<'|'<<endl<<"       ";
   }
  }
 }
 getch();
}

void type()
{
 if (yolo==1)
 {
  int q=0,p=0,r=0,s=0,c=0;
  for (int i=0;i<2;i++)
  {
   for (int j=0;j<2;j++)
   if(a[i][j]==0)
    q++;
  }
  if (q==4)
  {
   c=1;
   cout<<"The matrix entered is a null matrix as all its elements are 0."<<endl;
  }
  for (i=0;i<2;i++)
  if (a[i][i]==1)
   p++;
  for (i=0;i<2;i++)
  {
   for (int j=0;j<i;j++)
    if (a[i][j]==0)
     r++;
  }
  for (i=0;i<2;i++)
  {
   for (int j=1;j>i;j--)
    if (a[i][j]==0)
     s++;
  }
  if (p==2 && r==1 && s==1)
  {
   c=2;
   cout<<"The matrix entered is an identity matrix as all the elements of it's major diagonal are 1 and rest of them are 0."<<endl;
  }
  p=0,q=0,r=0,s=0;
  if (c==0)
  {
   for (i=0;i<2;i++)
   {
    for (int j=0;j<2;j++)
    {
     if(a[1][0]==0 && ((i!=1 || j!=0) && a[i][j]!=0))
      p++;
     if(a[0][1]==0 && ((i!=0 || j!=1) && a[i][j]!=0))
      q++;
     if(a[1][1]==a[0][0] && (i!=j && a[i][j]==0))
      r++;
     if(a[1][1]!=a[0][0] && (i!=j && a[i][j]==0))
      s++;
    }
   }
   if (p==3)
    cout<<"The matrix entered is an upper triangular matrix as all the elements below the major diagonal are 0."<<endl;
   if (q==3)
    cout<<"The matrix entered is a lower triangular matrix as all the elements above the major diagonal are 0."<<endl;
   if (r==2)
    cout<<"The matrix entered is a scalar matrix as all the elements along major diagonal are equal and rest of them are 0."<<endl;
   if (s==2)
    cout<<"The matrix entered is a diagonal matrix as all the elements are present along the major diagonal and rest of them are 0."<<endl;
   if (p==3 || q==3 || r==2 || s==2)
    c=3;
   int d[2][2], k=0;
   for (i=0;i<2;i++)
   {
    for (int j=0;j<2;j++)
    {
     if (i==0)
      k=1;
     else
      k=0;
     d[i][j] = (a[i][i]*a[i][j]) + (a[i][k]*a[k][j]);
    }
   }
   k=0;
   for (i=0;i<2;i++)
   {
    for (int j=0;j<2;j++)
     if (a[i][j] == d[i][j])
      k++;
   }
   if (k==4)
   {
    c=4;
    cout<<"The matrix entered is an idempotent matrix as a^2 = a :"<<endl<<endl;
    cout<<"a^2 = ";
    for (i=0;i<2;i++)
    {
     cout<<"|"<<' ';
     for (int j=0;j<2;j++)
     cout<<d[i][j]<<' ';
     cout<<"|"<<endl<<"     ";
    }
   }
   p=0; r=0; s=0;
   for (i=0;i<2;i++)
    if (d[i][i]==1)
     p++;
   for (i=0;i<2;i++)
   {
    for (int j=0;j<i;j++)
    if (d[i][j] == 0)
    r++;
   }
   for (i=0;i<2;i++)
   {
    for (int j=1;j>i;j--)
     if (d[i][j] == 0)
      s++;
   }
   if (p==2 && r==1 && s==1)
   {
    c=5;
    cout<<"The matrix entered is an involtary matrix as a^2 = I :"<<endl<<endl;
    cout<<"a^2 =";
    for (i=0;i<2;i++)
    {
     cout<<"|"<<' ';
     for (int j=0;j<2;j++)
      cout<<d[i][j]<<' ';
     cout<<"|"<<endl<<"     ";
    }
   }
   if(c==0)
    cout<<"The matrix entered is a general square matrix."<<endl;
  }
 }
 else if (yolo == 2)
 {
  int q=0,p=0,r=0,s=0,c=0;
  for (int i=0;i<3;i++)
   for (int j=0;j<3;j++)
    if (b[i][j]==0)
     q++;
  if (q==9)
  {
   c=1;
   cout<<"The matrix entered is a null matrix as all its elements are 0."<<endl;
  }
  for (i=0;i<3;i++)
   if (b[i][i]==1)
    p++;
  for (i=0;i<3;i++)
   for (j=0;j<i;j++)
    if (b[i][j]==0)
     r++;
  for (i=0;i<3;i++)
   for (j=2;j>i;j--)
    if (b[i][j]==0)
     s++;
  if (p==3 && r==3 && s==3)
  {
   c=2;
   cout<<"The matrix entered is an identity matrix as all the elements of its major diagonal are 1 and rest of them are 0."<<endl;
  }
  if (c==0)
  {
   p=0;q=0;r=0;s=0;
   for (i=0;i<3;i++)
   {
    for (int j=0;j<3;j++)
    {
     if (b[1][0]==0 && b[2][0]==0 && b[2][1]==0 && b[i][j]!=0)
      p++;
     if (b[0][1]==0 && b[0][2]==0 && b[1][2]==0 && b[i][j]!=0)
      q++;
     if (b[0][0]==b[1][1] && b[1][1]==b[2][2] && (i!=j && b[i][j]==0))
      r++;
     if ((b[0][0]!=b[1][1] || b[1][1]!=b[2][2] || b[0][0]!=b[2][2]) && (i!=j && b[i][j]==0))
      s++;
    }
   }
   if (p==6)
    cout<<"The matrix entered is an upper triangular matrix as all the elements below the major diagonal are 0."<<endl;
   if (q==6)
    cout<<"The matrix entered is a lower triangular matrix as all the elements above the major diagonal are 0."<<endl;
   if (r==6)
    cout<<"The matrix entered is a scalar matrix as all the elements along major diagonal are equal and rest of them are 0."<<endl;
   if (s==6)
    cout<<"The matrix entered is a diagonal matrix as all the elements are present along the major diagonal and rest of them are 0."<<endl;
   if (p==6 || q==6 || r==6 || s==6)
    c=3;
   int d[3][3],k,t;
   for (i=0;i<3;i++)
   {
    for (int j=0;j<3;j++)
    {
     if (i==0)
     {
      k=1;
      t=2;
     }
     else if (i==1)
     {
      k=0;
      t=2;
     }
     else
     {
      k=1;
      t=0;
     }
     d[i][j] = (b[i][i] * b[i][j]) + (b[i][k] * b[k][j]) + (b[i][t] * b[t][j]);
    }
   }
   k=0;
   for (i=0;i<3;i++)
   {
    for (int j=0;j<3;j++)
     if (b[i][j] == d[i][j])
      k++;
   }
   if (k==9)
   {
    c=4;
    cout<<"The matrix entered is an idempotent matrix as a^2 = a :"<<endl;
    cout<<"a^2 = ";
    for (i=0;i<3;i++)
    {
     cout<<'|'<<' ';
     for (int j=0;j<3;j++)
      cout<<d[i][j]<<' ';
     cout<<'|'<<endl<<" ";
    }
   }
   p=0;r=0;s=0;
   for (i=0;i<3;i++)
   if (d[i][i] == 1)
    p++;
   for (i=0;i<3;i++)
    for (j=0;j<i;j++)
     if (d[i][j] == 0)
      r++;
   for (i=0;i<3;i++)
    for (j=2;j>i;j--)
     if (d[i][j] == 0)
      s++;
   if (p==3 && r==3 && s==3)
   {
    c=5;
    cout<<"The matrix entered is an involtary matrix as a^2 = I :"<<endl;
    cout<<"a^2 = ";
    for (i=0;i<3;i++)
    {
     cout<<'|'<<' ';
     for (int j=0;j<3;j++)
      cout<<d[i][j]<<' ';
     cout<<'|'<<endl<<" ";
    }
   }
   if (c==0)
    cout<<"The matrix entered is a general square matrix."<<endl;
  }
 }
 getch();
}

void transpose()
{
 cout<<"Transpose of any matrix 'a' is represented as 'a'' and it is given as :"<<endl;
 cout<<"If a = A(i,j) ,where i and j represent the row and column number respectively,"<<endl;
 cout<<"then a' = A(j,i)"<<endl<<endl;
 if (yolo == 1)
 {
  cout<<"a' = ";
  for (int i=0;i<2;i++)
  {
   cout<<"|"<<' ';
   for (int j=0;j<2;j++)
   cout<<a[j][i]<<' ';
   cout<<"|"<<endl<<"     ";
  }
  int k=0,m=0;
  for (i=0;i<2;i++)
  {
   for (int j=0;j<2;j++)
   {
    if (a[j][i]==a[i][j])
     k++;
    else if(a[j][i]==(-a[i][j]))
     m++;
   }
  }
  cout<<endl;
  if (k==4)
   cout<<"The entered matrix is symmetric."<<endl;
  else if (m==2)
   cout<<"The entered matrix is skew symmetric."<<endl;
  else
   cout<<"The entered matrix is neither symmetric nor skew symmteric."<<endl;
 }
 else if (yolo == 2)
 {
  cout<<"a' = ";
  for (int i=0;i<3;i++)
  {
   cout<<'|'<<' ';
   for (int j=0;j<3;j++)
    cout<<b[j][i]<<' ';
   cout<<'|'<<endl<<"     ";
  }
  int k=0,m=0;
  for (i=0;i<3;i++)
  {
   for (int j=0;j<3;j++)
   {
    if (b[i][j] == b[j][i])
     k++;
    else if (b[i][j]!=0 && b[j][i]==(-b[i][j]))
     m++;
   }
  }
  int f=0;
  for (i=0;i<3;i++)
  {
   for (int j=0;j<3;j++)
    if (b[i][j] != 0)
     f++;
  }
  cout<<endl;
  if (k==9)
   cout<<"The entered matrix is symmetric as a'= a."<<endl;
  else if (m==f)
   cout<<"The entered matrix is skew symmetric as a'=-(a)."<<endl;
  else
   cout<<"The entered matrix is neither symmetric nor skew symmteric."<<endl;
 }
 getch();
}

void matrix1()
{
 int o=0;
 while(end==0)
 {
  graphics();
  cout<<"Which Matrix?"<<endl<<endl;
  cout<<"1. 2 X 2"<<endl<<endl;
  cout<<"2. 3 X 3"<<endl<<endl;
  cout<<endl<<endl<<"Enter your option : "<<endl<<endl;
  int x=wherex(),y=wherey();
  keyhit();
  if(end!=0)
   break;
  gotoxy(x,y); cout<<choice; delay(500);
  graphics();
  if(choice=='1' || choice=='2')
  {
   accept(choice); rep=0;
   end=0;
  }
  else
  {
   cout<<"No such matrix size available!"<<endl; delay(1200);
   o=1;
   break;
  }
  if(o==0)
  {
   while(end==0)
   {
    graphics();
    cout<<"1.Type of matrix"<<endl<<endl;
    cout<<"2.Transpose of matrix"<<endl<<endl;
    cout<<"3.Trace of matrix"<<endl<<endl;
    cout<<"4.Power of matrix"<<endl<<endl;
    cout<<"5.Determinant of matrix"<<endl<<endl;
    cout<<"6.Adjoint of matrix"<<endl<<endl;
    cout<<"7.Inverse of matrix"<<endl<<endl;
    cout<<endl<<endl<<"Enter your option : "<<endl<<endl; x=wherex(),y=wherey();
    keyhit();
    if(end!=0)
     break;
    gotoxy(x,y); cout<<choice; delay(500);
    graphics('a');
    matrixdisp();
    switch(choice)
    {
     case '1' : type(); break;
     case '2' : transpose(); break;
     case '3' : trace(); break;
     case '4' : {
		 while(end==0)
		 {
		  graphics();
		  cout<<"Choose power of the matrix."<<endl<<endl;
		  cout<<"1) Square of the matrix"<<endl<<endl;
		  cout<<"2) Cube of the matrix"<<endl<<endl;
		  cout<<endl<<endl<<"Enter your option : "<<endl<<endl; x=wherex(),y=wherey();
		  keyhit();
		  if(end!=0)
		  break;
		  gotoxy(x,y); cout<<choice; delay(500);
		  graphics('a');
		  if(choice!='1' && choice!='2')
		  {
		   cout<<"No such power is available!"; delay(1200);
		   break;
		  }
		  else
		  power(choice);
		 }
		 if(end==2)
		  end=0;
		 break;
		}
     case '5' : det(); break;
     case '6' : adjoint(); break;
     case '7' : inv(); break;
     default  : cout<<"No such option available!"<<endl; delay(1200);
    }
   }
   if(end==2)
    end=0;
  }
 }
 if(end==2)
  end=0;
 yolo=0;
}

void adding(char opt)
{
 if(opt=='1')
  cout<<"a+b =";
 else if (opt=='2')
  cout<<"a-b =";
 if(polo==1)
 {
  for(int i=0;i<2;i++)
  {
   cout<<'|'<<' ';
   for(int j=0;j<2;j++)
   {
    if(opt=='1')
     cout<<a[i][j]+c[i][j]<<' ';
    else if (opt=='2')
     cout<<a[i][j]-c[i][j]<<' ';
   }
   cout<<'|'<<endl<<"     ";
  }
 }
 else if (polo==2)
 {
  for (int i=0;i<3;i++)
  {
   cout<<'|'<<' ';
   for (int j=0;j<3;j++)
   {
    if (opt=='1')
     cout<<b[i][j]+d[i][j]<<' ';
    else if (opt=='2')
     cout<<b[i][j]-d[i][j]<<' ';
   }
   cout<<'|'<<endl<<"     ";
  }
 }
 getch();
}

void scalermult(float k)
{
 cout<<k<<" * a =";
 if(polo==1)
 {
  for (int i=0;i<2;i++)
  {
   cout<<'|'<<' ';
   for (int j=0;j<2;j++)
    cout<<a[i][j]*k<<' ';
   cout<<'|'<<endl<<"       ";
  }
  cout<<endl<<endl<<k<<" * b =";
  for (i=0;i<2;i++)
  {
   cout<<'|'<<' ';
   for (int j=0;j<2;j++)
   cout<<c[i][j]*k<<' ';
   cout<<'|'<<endl<<"       ";
  }
 }
 else if(polo==2)
 {
  for (int i=0;i<3;i++)
  {
   cout<<'|'<<' ';
   for (int j=0;j<3;j++)
    cout<<b[i][j]*k<<' ';
   cout<<'|'<<endl<<"       ";
  }
  cout<<endl<<endl<<k<<" * b =";
  for (i=0;i<3;i++)
  {
   cout<<'|'<<' ';
   for (int j=0;j<3;j++)
    cout<<d[i][j]*k<<' ';
   cout<<'|'<<endl<<"       ";
  }
 }
 getch();
}

void matrixmult()
{
 cout<<"a * b =";
 if(polo==1)
 {
  int k=0;
  for(int i=0;i<2;i++)
  {
   cout<<'|'<<' ';
   for(int j=0;j<2;j++)
   {
    if(i==0)
     k=1;
    else if(i==1)
     k=0;
    cout<< (a[i][i] * c[i][j]) + (a[i][k] * c[k][j])<<' ';
   }
   cout<<'|'<<endl<<"       ";
  }
 }
 else if(polo==2)
 {
  int k,t;
  for (int i=0;i<3;i++)
  {
   cout<<'|'<<' ';
   for (int j=0;j<3;j++)
   {
    if (i==0)
    {
     k=1;
     t=2;
    }
    else if (i==1)
    {
     k=0;
     t=2;
    }
    else
    {
     k=1;
     t=0;
    }
    cout<<(b[i][i]*d[i][j])+(b[i][k]*d[k][j])+(b[i][t]*d[t][j])<<' ';
   }
   cout<<'|'<<endl<<"     ";
  }
 }
 getch();
}


void matrix2()
{
 while (end==0)
 {
  int o=0;
  graphics();
  cout<<"Choose matrix."<<endl<<endl<<"1) 2 X 2"<<endl<<endl<<"2) 3 X 3"<<endl<<endl;
  cout<<endl<<endl<<"Enter your option : "<<endl<<endl; int x=wherex(),y=wherey();
  keyhit();
  if(end!=0)
   break;
  gotoxy(x,y); cout<<choice; delay(500);
  graphics();
  if(choice=='1' || choice=='2')
  {
   accept(choice); accept(choice);
   rep=0;
  }
  else
  {
   cout<<"No such matrix is available!"<<endl<<endl; delay(1200);
   o=1; break;
  }
  if(o==0)
  {
   while (end==0)
   {
    graphics();
    cout<<"Choose the operation you need."<<endl<<endl;
    cout<<"1) Addition of matrices"<<endl<<endl;
    cout<<"2) Subtraction of matrices"<<endl<<endl;
    cout<<"3) Scaler multiplication of matrices"<<endl<<endl;
    cout<<"4) Matrix multiplication"<<endl<<endl;
    cout<<endl<<endl<<"Enter your option : "<<endl<<endl; x=wherex(),y=wherey();
    keyhit();
    if(end!=0)
     break;
    gotoxy(x,y); cout<<choice; delay(500);
    float x;
    graphics('a');
    matrixdisp();
    switch (choice)
    {
     case '1': adding(choice); break;
     case '2': adding(choice); break;
     case '3': {
		graphics();
		cout<<"Enter the scalar you want to multiply to the matrices : "<<endl<<endl;
		cin>>x;
		graphics(); matrixdisp();
		scalermult(x); break;
	       }
     case '4': matrixmult(); break;
     default : {
		cout<<"No such option is available!";
		delay(1200); break;
	       }
    }
   }
   if(end==2)
    end=0;
  }
 }
 if(end==2)
  end=0;
 polo=0;
}

void arith()
{
 float a,b;
 char opt;
 cout<<"Enter your question : "<<endl<<endl;
 cin>>a;
 cin>>opt;
 cin>>b;
 graphics('a');
 switch(opt)
 {
  case '+': {
	     cout<<setw(15)<<a<<endl<<endl<<setw(13)<<"+  "<<b<<endl<<setw(17)<<"--------"<<endl<<setw(15)<<a+b<<endl<<setw(17)<<"--------"<<endl<<endl;
	     cout<<a<<" + "<<b<<" = "<<a+b<<endl; break;
	    }
  case '-': {
	     cout<<setw(15)<<a<<endl<<endl<<setw(13)<<"-  "<<b<<endl<<setw(17)<<"--------"<<endl<<setw(15)<<a-b<<endl<<setw(17)<<"--------"<<endl<<endl;
	     cout<<a<<" - "<<b<<" = "<<a-b<<endl; break;
	    }
  case '*': {
	     cout<<setw(15)<<a<<endl<<endl<<setw(13)<<"*  "<<b<<endl<<setw(17)<<"--------"<<endl<<setw(15)<<a*b<<endl<<setw(17)<<"--------"<<endl<<endl;
	     cout<<a<<" * "<<b<<" = "<<a*b<<endl; break;
	    }
  case '/': {
	     if (b!=0)
	      cout<<a<<" / "<<b<<" = "<<a/b<<endl;
	     else
	      cout<<"Undefined!"<<endl;
	      break;
	    }
  case '%': {
	     if (b!=0)
	      cout<<a<<" % "<<b<<" = "<<(int(a)%int(b))<<endl;
	     else
	      cout<<"Undefined!"<<endl;
	     break;
	     }
  default: {
  graphics();
  cout<<"No such operation found!"<<endl;
  }
 }
 getch();
}

void trigo()
{
 double x; char m[6]; int check=0,f=0;
 while(end==0)
 {
  graphics();
  check=0; f=0;
  cout<<"Enter the trignometric function and the angle to be worked with : "<<endl<<endl<<"Eg: tan 5"<<endl<<endl;
  for(int i=0;i<6;i++)
  {
   m[i]=getch();
   if(m[i]==' ')
   {
    m[i]='\0'; break;
   }
   if(m[i]==27)
    end=1;
   if(m[i]=='q')
    end=2;
   if(end!=0)
    break;
   if(m[i]==13)
   {
    graphics();
    cout<<"No such function found!"<<endl; check=1; delay(1200); break;
   }
   cout<<m[i];
  }
  if(end==0 && check==0)
  {
   cout<<' '; cin>>x;
   graphics('a');
   if(i==3)
   {
    if(strcmpi(m,"sin")==0)
     cout<<endl<<"sin("<<x<<") = "<<sin(x)<<endl;
    else if(strcmpi(m,"cos")==0)
     cout<<endl<<"cos("<<x<<") = "<<cos(x)<<endl;
    else if(strcmpi(m,"tan")==0)
     cout<<endl<<"tan("<<x<<") = "<<tan(x)<<endl;
    else if(strcmpi(m,"sec")==0)
    {
     if(cos(x)!=0)
      cout<<endl<<"sec("<<x<<") = "<<(1/cos(x))<<endl;
     else
      cout<<endl<<"Undefined value!"<<endl;
    }
    else if(strcmpi(m,"cot")==0)
    {
     if(tan(x)!=0)
      cout<<endl<<"cot("<<x<<") = "<<1/tan(x)<<endl;
     else
      cout<<endl<<"Undefined value!"<<endl;
    }
    else
    {
     f=1; graphics();
     cout<<"No such function found!"<<endl; delay(1200);
    }
    if(f==0)
    getch();
   }
   else if(i==5)
   {
    if(strcmpi(m,"cosec")==0)
    {
     if(sin(x)!=0)
      cout<<endl<<"cosec("<<x<<") = "<<(1/sin(x))<<endl;
     else
      cout<<endl<<"Undefined value!"<<endl;
    }
    else
    {
     f=1; graphics();
     cout<<"No such function found!"<<endl; delay(1200);
    }
    if(f==0)
    getch();
   }
   else
   {
    f=1; graphics();
    cout<<"No such function found!"<<endl; delay(1200);
   }
  }
 }
}

void log()
{
 double x;
 while (end==0)
 {
  graphics();
  cout<<"Choose one."<<endl<<endl;
  cout<<"1. Natural log"<<endl<<endl;
  cout<<"2. Log with base 10"<<endl<<endl;
  cout<<endl<<endl<<"Enter your option : "<<endl<<endl;
  int x=wherex(),y=wherey();
  keyhit();
  if(end!=0)
   break;
  gotoxy(x,y); cout<<choice; delay(500);
  if(choice=='1' || choice=='2')
  {
   graphics();
   cout<<endl<<"Enter a number : "<<endl<<endl;
   cin>>x;
   graphics('a');
   switch (choice)
   {
    case '1':{
	      cout<<endl<<"Log with base e is written as ln(x)"<<endl<<endl;
	      cout<<"ln("<<x<<") = "<<log(x)<<endl;
	      getch(); break;
	     }
    case '2':{
	      cout<<endl<<"log10 ("<<x<<") = "<<log10(x)<<endl;
	      getch(); break;
	     }
   }
  }
  else
  {
   graphics();
   cout<<"No such option is available!"<<endl; delay(1200);
  }
 }
}

void pow()
{
 float x, z; char num[6]; int i=0,check=0;
 while(end==0)
 {
  graphics(); check=0;
  for(i=0;i<6;i++)
   num[i]='\0';
  i=0;
  cout<<endl<<"Enter a number (upto 5 digits) : "<<endl<<endl;
  while(num[i]!=13)
  {
   if(i>5)
   {
    graphics();
    cout<<"Numbers greater than 5 digits not allowed!"<<endl;
    delay(1200); break;
   }
   num[i]=getch();
   if(num[0]==27)
    end=1;
   if(num[0]=='q')
    end=2;
   if(end!=0)
    break;
   if(num[i]=='.');
   else if(!isdigit(num[i]))
   {
    if(num[i]==13)
     check=1;
    else
    {
     graphics();
     cout<<"Enter the number please!"<<endl; delay(1200);
    }
    break;
   }
   cout<<num[i]; i++;
  }
  if(check==1)
  {
   x=atof(num);
   cout<<endl<<endl<<"Enter power : "<<endl<<endl;
   cin>>z;
   graphics('a');
   if(x==0 && z==0)
    cout<<endl<<"Indeterminate"<<endl;
   else
   {
    if(z!=0.5 && z!=-0.5)
     cout<<endl<<x<<'^'<<z<<" = "<<pow(x,z)<<endl;
    else
     cout<<endl<<x<<"^1/2 = "<<sqrt(x)<<endl;
   }
   getch();
  }
 }
}

void lineq11()
{
 float a,b,c,d,v;
 cout<<endl<<"General equation of 1 degree in one variable is given as : "<<endl<<endl;
 cout<<"ax + b = cx + d  ,where x is the variable of 1 degree."<<endl<<endl;
 cout<<"Enter Variables (a,b,c,d) : "<<endl<<endl;
 cout<<"a = "; cin>>a;
 cout<<"b = "; cin>>b;
 cout<<"c = "; cin>>c;
 cout<<"d = "; cin>>d;
 graphics('a');
 cout<<endl<<"Given Equation : "<<endl<<endl;
 cout<<a<<"x + "<<b<<" = "<<c<<"x + "<<d<<endl<<endl;
 if((a-c)!=0)
 {
  if((d-b)==0)
   v=1;
  else
   v=(d-b)/(a-c);
  cout<<"x = "<<v;
 }
 else
  cout<<"x can have infintely many solutions."<<endl;
 getch();
}

void lineq12()
{
 float a,b,c;
 cout<<endl<<"General equation of 1 degree in one variable is given as : "<<endl<<endl;
 cout<<"ax + b = d  ,where x is the variable of 1 degree"<<endl<<endl;
 cout<<"Enter values of Variables (a,b,c)"<<endl<<endl;
 cout<<"a = "; cin>>a;
 cout<<"b = "; cin>>b;
 cout<<"c = "; cin>>c;
 graphics('a');
 cout<<endl<<"Given Equation : "<<endl<<endl;
 cout<<a<<"x + "<<b<<" = "<<c<<endl<<endl;
 cout<<"Now, "<<b<<" will be taken to the RHS, to give "<<c-b<<endl;
 cout<<"This makes the equation as :"<<endl;
 cout<<a<<"x = "<<c-b<<endl;
 float z = ((c-b)/a);
 cout<<"Finally, "<<a<<"is taken to the RHS, thus ,"<<endl<<endl;
 cout<<"x = "<<z<<endl;
 getch();
}

void lineq1()
{
 while (end==0)
 {
  graphics();
  cout<<endl<<"Which form is your equation in?"<<endl<<endl;
  cout<<"1. ax + b = cx + d"<<endl<<endl;
  cout<<"2. ax + b = d"<<endl<<endl;
  cout<<endl<<endl<<"Enter your option : "<<endl<<endl;
  int x=wherex(),y=wherey();
  keyhit();
  if(end!=0)
   break;
  gotoxy(x,y); cout<<choice; delay(500);
  graphics();
  switch(choice)
  {
   case '1':lineq11(); break;
   case '2':lineq12(); break;
   default :{
	     cout<<"No such option is available!";
	     delay(1200); break;
	    }
  }
 }
 if(end==2)
  end=0;
}

void lineq2()
{
 float a,b,c,d,e,f;
 cout<<endl<<"General equation of 1 degree in two variables is represented as : "<<endl<<endl;
 cout<<"ax + by = c  , where x and y are the two variables of 1 degree."<<endl<<endl;
 cout<<"Now ,enter two equations "<<endl;
 cout<<"Enter variables for first equation : "<<endl<<endl;
 cout<<"a = "; cin>>a;
 cout<<"b = "; cin>>b;
 cout<<"c = "; cin>>c;
 cout<<endl<<"Enter variables second equation : "<<endl<<endl;
 cout<<"d = "; cin>>d;
 cout<<"e = "; cin>>e;
 cout<<"f = "; cin>>f;
 graphics('a');
 cout<<endl<<"The two equations are :"<<endl<<endl;
 cout<<a<<"x + "<<b<<"y = "<<c<<endl<<endl;
 cout<<d<<"x + "<<e<<"y = "<<f<<endl<<endl<<endl;
 if(a/d==b/e && b/e==c/f && c/f==a/d)
  cout<<"The given equations have infinte number of solutions as both the lines are coincident lines."<<endl;
 else if(a/d==b/e && b/e!=c/f && c/f!=a/d)
  cout<<"The given equations have no solution as both the lines are parallel lines."<<endl;
 else
 {
  float  r = a;
  if (a!=d)
  {
   a=a*d;
   b=b*d;
   c=c*d;
   d=d*r;
   e=e*r;
   f=f*r;
  }
  cout<<"New equations : "<<endl<<endl;
  cout<<a<<"x + "<<b<<"y = "<<c<<endl;
  cout<<d<<"x + "<<e<<"y = "<<f<<endl<<endl;
  float v=(b-e), n=(c-f);
  float q=(n/v);
  cout<<"Revised : "<<endl<<v<<"y = "<<n<<endl<<endl<<"SO, y = "<<n/v;
  cout<<" and x = "<<(c-(b*q))/a;
 }
 getch();
}

void quad()
{
 int a,b,c,d;
 cout<<endl<<"General representation of a quadratic equation in x : "<<endl<<endl;
 cout<<"ax^2 + bx + c = 0"<<endl<<endl;
 cout<<"Enter the coefficients and the constant term : "<<endl<<endl;
 cout<<"a = ";cin>>a;
 cout<<"b = ";cin>>b;
 cout<<"c = ";cin>>c;
 graphics('a');
 cout<<endl<<"Given equation : "<<a<<' '<<"x^2 + "<<b<<' '<<"x + "<<c<<" = 0"<<endl<<endl;
 float D = ((b*b)-(4*a*c)),y;
 cout<<"The discriminant of the given quadratic equation is : "<<endl<<endl;
 cout<<"D = [b^2 - 4 * a * c]"<<endl;
 cout<<"  = "<<D<<endl<<endl;
 if(D>=0)
  y=sqrt(D);
 if(D==0)
 {
  cout<<"The roots are equal as D=0 and are = [(-b)/(2*a)]"<<endl;
  cout<<"                                   = "<<((-b)/(2*a))<<endl;
 }
 else if(D>0)
 {
  cout<<"The roots are unequal as D>0 and are = [(-b +- (D^1/2)/(2*a)]"<<endl;
  cout<<"                                  = "<<((-b+y)/(2*a))<<" and "<<((-b-y)/(2*a))<<endl;
 }
 else
 cout<<"The quadratic equation entered doesn't have real roots as D<0."<<endl;
 getch();
}

void shape(char x,char y)
{
 graphics('a');
 setcolor(RED);
 setlinestyle(SOLID_LINE,1,4);
 if(x=='1')
 {
  switch(y)
  {
   case '1':{
	     rectangle(250,70,350,170);
	     outtextxy(300,175,"a");
	     setcolor(YELLOW);
	     line(250,70,350,170);
	     line(300,120,365,120);
	     outtextxy(367,115,"Diagonal");
	     outtextxy(285,190,"SQUARE"); break;
	    }
   case '2':{
	     rectangle(240,70,390,140);
	     outtextxy(315,145,"L");
	     outtextxy(230,105,"B");
	     setcolor(YELLOW);
	     line(240,70,390,140);
	     line(315,105,405,105);
	     outtextxy(407,100,"Diagonal");
	     outtextxy(295,160,"RECTANGLE"); break;
	    }
   case '3':{
	     line(250,70,250,170);
	     outtextxy(240,120,"H");
	     line(250,70,300,70);
	     outtextxy(275,55,"L1");
	     line(250,170,350,170);
	     outtextxy(300,172,"L2");
	     line(300,70,350,170);
	     setcolor(YELLOW);
	     outtextxy(275,185,"TRAPEZIUM"); break;
	    }
   case '4':{
	     circle(300,120,50);
	     outtextxy(325,125,"r");
	     setcolor(YELLOW);
	     line(300,120,350,120);
	     outtextxy(285,185,"CIRCLE"); break;
	    }
  }
 }
 else if(x=='2')
 {
  switch(y)
  {
   case '1':{
	     rectangle(200,95,300,195);
	     outtextxy(250,197,"a");
	     rectangle(250,75,350,175);
	     line(200,95,250,75);
	     line(350,175,300,195);
	     line(300,95,350,75);
	     line(200,195,250,175);
	     setcolor(YELLOW);
	     line(200,95,350,175);
	     line(275,135,365,135);
	     outtextxy(370,132,"Diagonal");
	     outtextxy(240,210,"CUBE"); break;
	    }
   case '2':{
	     rectangle(150,115,300,195);
	     outtextxy(245,173,"L");
	     outtextxy(145,155,"H");
	     rectangle(200,65,350,145);
	     outtextxy(325,170,"B");
	     line(150,115,200,65);
	     line(300,195,350,145);
	     line(300,115,350,65);
	     line(150,195,200,145);
	     setcolor(YELLOW);
	     line(150,115,350,145);
	     line(250,130,365,130);
	     outtextxy(370,127,"Diagonal");
	     outtextxy(215,210,"CUBOID"); break;
	    }
   case '3':{
	     ellipse(300,80,0,360,40,20);
	     ellipse(300,170,0,360,40,20);
	     line(260,80,260,170);
	     line(340,80,340,170);
	     circle(450,120,45);
	     outtextxy(250,125,"h");
	     outtextxy(473,117,"r");
	     setcolor(YELLOW);
	     line(450,120,495,120);
	     line(330,78,430,78);
	     outtextxy(275,195,"CYLINDER"); break;
	    }
   case '4':{
	     ellipse(300,170,0,360,40,20);
	     line(340,170,300,70);
	     line(260,170,300,70);
	     circle(450,130,45);
	     outtextxy(473,127,"r");
	     outtextxy(305,120,"h");
	     outtextxy(270,120,"l");
	     setcolor(YELLOW);
	     line(450,130,495,130);
	     line(330,170,430,170);
	     line(300,70,300,170);
	     outtextxy(285,195,"CONE"); break;
	    }
   case '5':{
	     ellipse(320,170,0,360,60,20);
	     ellipse(320,170,0,180,60,80);
	     outtextxy(315,120,"r");
	     outtextxy(350,167,"r");
	     setcolor(YELLOW);
	     line(320,170,380,170);
	     line(320,170,320,90);
	     outtextxy(275,195,"HEMI-SPHERE"); break;
	    }
   case '6':{
	     circle(320,130,70);
	     ellipse(320,130,0,360,15,70);
	     ellipse(320,130,0,360,70,15);
	     outtextxy(315,75,"r");
	     outtextxy(355,127,"r");
	     setcolor(YELLOW);
	     line(320,130,390,130);
	     line(320,130,320,60);
	     outtextxy(295,210,"SPHERE"); break;
	    }
  }
 }
 cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
}

void mensuration()
{
 char opt1=' ',opt2=' ';
 while(end==0)
 {
  graphics();
  cout<<"Choose one."<<endl<<endl;
  cout<<"1. 2-D figures"<<endl<<endl;
  cout<<"2. 3-D figures"<<endl<<endl;
  cout<<endl<<endl<<"Enter your option : "<<endl<<endl;
  int x=wherex(),y=wherey();
  keyhit();
  opt1=choice;
  if(end!=0)
   break;
  gotoxy(x,y); cout<<opt1; delay(500);  graphics();
  if(opt1=='1')
  {
   while(end==0)
   {
    graphics();
    cout<<"Which Shape?"<<endl<<endl;
    cout<<"1. Square"<<endl<<endl;
    cout<<"2. Rectangle"<<endl<<endl;
    cout<<"3. Trapezium"<<endl<<endl;
    cout<<"4. Circle"<<endl<<endl;
    cout<<endl<<endl<<"Enter your option : "<<endl<<endl;
    x=wherex(),y=wherey();
    keyhit();
    opt2=choice;
    if(end!=0)
     break;
    gotoxy(x,y); cout<<opt2; delay(500); graphics();
    switch(opt2)
    {
     case '1':{
	       int a;
	       cout<<"SIDE(a) ?"<<endl<<endl;
	       cout<<"a = "; cin>>a;
	       shape(opt1,opt2);
	       cout<<endl<<endl<<"Perimeter of  Square = 4 * a"<<endl;
	       cout<<"                     = "<<4*a<<endl<<endl;
	       cout<<"Area of a Square = a * a"<<endl;
	       cout<<"                 = "<<a*a<<endl<<endl;
	       getch(); break;
	      }
     case '2':{
	       int b,c;
	       cout<<"SIDES - Length(L) and Breadth(B) ?"<<endl<<endl;
	       cout<<"L = "; cin>>b;
	       cout<<"B = "; cin>>c;
	       shape(opt1,opt2);
	       cout<<endl<<endl<<"Perimeter of  Rectangle = 2 * (L + B)"<<endl;
	       cout<<"                        = "<<2*(b+c)<<endl<<endl;
	       cout<<"Area of a Rectangle = L * B"<<endl;
	       cout<<"                    = "<<b*c<<endl<<endl;
	       getch(); break;
	      }
     case '3':{
	       int d,e,f;
	       cout<<"SIDES - L1, L2 and Height(H) ?"<<endl<<endl;
	       cout<<"L1 = "; cin>>d;
	       cout<<"L2 = "; cin>>e;
	       cout<<"H = "; cin>>f;
	       shape(opt1,opt2);
	       double l=((d-e)*(d-e)+f*f);
	       cout<<endl<<endl<<"Perimeter of  Trapezium = Sum of all sides"<<endl;
	       cout<<"                        = "<<d+e+f+sqrt(l)<<endl<<endl;
	       cout<<"Area of Trapezium = 1/2 * H * (L1 + L2)"<<endl;
	       cout<<"                  = "<<(0.5*f*(d+e))<<endl<<endl;
	       getch(); break;
	      }
     case '4':{
	       int g;
	       cout<<"Radius(r) ?"<<endl<<endl;
	       cout<<"r = "; cin>>g;
	       shape(opt1,opt2);
	       cout<<endl<<endl<<"Perimeter of  Circle = 2 * 3.14 * r"<<endl;
	       cout<<"                     = "<<2*pi*g<<endl<<endl;
	       cout<<"Area of Circle = 3.14 * r^2"<<endl;
	       cout<<"               = "<<pi*g*g<<endl<<endl;
	       getch(); break;
	      }
     default :cout<<"No such option is available!"<<endl; delay(1200);
    }
   }
   if(end==2)
    end=0;
  }
  else if(opt1=='2')
  {
   while(end==0)
   {
    graphics();
    cout<<"Which figure?"<<endl<<endl;
    cout<<"1. Cube"<<endl<<endl;
    cout<<"2. Cuboid"<<endl<<endl;
    cout<<"3. Cylinder"<<endl<<endl;
    cout<<"4. Cone"<<endl<<endl;
    cout<<"5. Hemisphere"<<endl<<endl;
    cout<<"6. Sphere"<<endl<<endl;
    cout<<endl<<endl<<"Enter your option : "<<endl<<endl;
    x=wherex(),y=wherey();
    keyhit();
    opt2=choice;
    if(end!=0)
     break;
    gotoxy(x,y); cout<<opt2; delay(500); graphics();
    switch(opt2)
    {
     case '1':{
	       int a;
	       cout<<"SIDE(a)?"<<endl<<endl;
	       cout<<"a = "; cin>>a;
	       shape(opt1,opt2);
	       cout<<endl<<endl<<"Diagonal of Cube = 2^1/2 * a"<<endl;
	       cout<<"                 = "<<sqrt(2)*a<<endl<<endl;			 cout<<"Surface Area of Cube = 6 * a * a = 6 * a^2"<<endl;
	       cout<<"                         "<<6*a*a<<endl<<endl;
	       cout<<"Vole of Cube = a * a * a = a^3"<<endl;
	       cout<<"             = "<<a*a*a<<endl<<endl;
	       getch(); break;
	      }
     case '2':{
	       int l,b,h;
	       cout<<"SIDES - Length(L),Breadth(B) and Height(H) ?"<<endl<<endl;
	       cout<<"L = "; cin>>l;
	       cout<<"B = "; cin>>b;
	       cout<<"H = "; cin>>h;
	       double x=((l*l)+(b*b)+(h*h));
	       shape(opt1,opt2);
	       cout<<endl<<endl<<"Diagonal of Cuboid = [L^2 + B^2 + H^2]^1/2 "<<endl;
	       cout<<"                   = "<<sqrt(x)<<endl<<endl;
	       cout<<"Surface Area of a Cuboid = 2 * (L*B + B*H + H*L)"<<endl;
	       cout<<"                         = "<<2*((l*b)+(b*h)+(h*l))<<endl<<endl;
	       cout<<"Volume of Cuboid = L * B * H"<<endl;
	       cout<<"                 = "<<l*b*h<<endl<<endl;
	       getch(); break;
	      }
     case '3':{
	       int r,h;
	       cout<<"Radius(r) and Height(h) ?"<<endl<<endl;
	       cout<<"r = "; cin>>r;
	       cout<<"h = "; cin>>h;
	       shape(opt1,opt2);
	       cout<<endl<<endl<<"Surface Area of Cylinder = (2 * 3.14 * r * h) + (2 * 3.14 * r^2"<<endl;
	       cout<<"                         = 2 * 3.14 * r * (h + r)"<<endl;
	       cout<<"                         = "<<(2*pi*r*(r+h))<<endl<<endl;
	       cout<<"Volume of Cylinder = 3.14 * r^2 * h"<<endl;
	       cout<<"                   = "<<pi*r*r*h<<endl<<endl;
	       getch(); break;
	      }
     case '4':{
	       int r,h;
	       cout<<"Radius(r) and Height(h)?"<<endl<<endl;
	       cout<<"r = "; cin>>r;
	       cout<<"h = "; cin>>h;
	       double l=((r*r)+(h*h));
	       shape(opt1,opt2);
	       cout<<endl<<endl<<"Slant height of Cone(l) = (r^2 + h^2)^1/2"<<endl;
	       cout<<"                        = "<<sqrt(l)<<endl<<endl;
	       cout<<"Surface Area of Cone = (3.14 * r * l) + (3.14 * r^2)"<<endl;
	       cout<<"                     = 3.14 * r * (l + r)"<<endl;
	       cout<<"                     = "<<pi*r*(l+r)<<endl<<endl;
	       cout<<"Volume of Cone = 1/3 * 3.14 * r^2 * h"<<endl;
	       cout<<"               = "<<float((pi*r*r*h)/3)<<endl<<endl;
	       getch(); break;
	      }
     case '5':{
	       int r;
	       cout<<"Radius(r) ?"<<endl<<endl;
	       cout<<"r = "; cin>>r; shape(opt1,opt2);
	       cout<<endl<<endl<<"Surface Area of Hemisphere = 3 * 3.14 * r^2"<<endl;
	       cout<<"                           = "<<(3*pi*r*r)<<endl<<endl;
	       cout<<"Volume of Hemisphere = 2/3 * 3.14 * r^3"<<endl;
	       cout<<"                     = "<<float((2*pi*r*r*r)/3)<<endl<<endl;
	       getch(); break;
	      }
     case '6':{
	       int r;
	       cout<<"Radius(r) ?"<<endl<<endl;
	       cout<<"r = "; cin>>r; shape(opt1,opt2);
	       cout<<endl<<endl<<"Surface Area of Sphere = 4 * 3.14 * r^2"<<endl;
	       cout<<"                       = "<<(4*pi*r*r)<<endl<<endl;
	       cout<<"Volume of Sphere = 4/3 * 3.14 * r^3"<<endl;
	       cout<<"                 = "<<float((4*pi*r*r*r)/3)<<endl<<endl;
	       getch(); break;
	      }
     default :cout<<"No such option is available!"<<endl; delay(1200);
    }
   }
   if(end==2)
    end=0;
  }
  else
  {
   cout<<"No such option is available!"<<endl; delay(1200);
  }
 }
}

void main()
{
 clrscr();
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"c:\\turboc3\\bgi");
 setbkcolor(CYAN);
 setfillstyle(XHATCH_FILL,RED);
 bar(0,0,15,500);
 bar(0,0,700,16);
 bar(625,0,640,500);
 bar(0,465,640,500); delay(400);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
 outtextxy(235,150,"W E L C O M E ");
 outtextxy(226,170,"-------------"); delay(1000);
 outtextxy(300,225,"T O");
 outtextxy(285,245,"-----"); delay(1000);
 outtextxy(227,295,"M A T H O P i A");
 outtextxy(214,315,"---------------"); delay(2500);
 int g=1,f=1,h=1,w=1;
 while(end==0)
 {
  mainscreen(g);
  keyhit();
  if(choice==77)
  {
   if(g>0 && g<3)
   {
    g++;
    mainscreen(g);
   }
  }
  else if(choice==75)
  {
   if(g>1 && g<4)
   {
    g--;
    mainscreen(g);
   }
  }
  else if(choice==13)
  {
   if(g==1)
   {
    while(end==0)
    {
     outputlearn(h); keyhit();
     if(end!=0)
      break;
     switch(choice)
     {
      case 72: {
		if(h>1 && h<11)
		{
		 h--;
		 outputlearn(h);
		}
		break;
	       }
      case 80: {
		if(h>0 && h<10)
		{
		 h++;
		 outputlearn(h);
		}
		break;
	       }
      case 13: {
		graphics('a');
		readlearn(h);
	       }
     }
    }
    h=1;
   }
   else if(g==2)
   {
    while(end==0)
    {
     outputdoubts(f);
     keyhit();
     if(end!=0)
      break;
      switch(choice)
      {
       case 72: {
		 if(f>1 && f<8)
		 {
		  f--;
		 outputdoubts(f);
		 }
		 break;
		}
       case 80: {
		 if(f>0 && f<7)
		 {
		  f++;
		  outputdoubts(f);
		 }
		 break;
		}
       case 13: {
		 graphics();
		 switch(f)
		 {
		  case 1: {
			   while(end==0)
			   {
			    graphics();
			    cout<<"Enter the degree of the equation (Max-Quadratic) : "<<endl<<endl;
			    int x=wherex(),y=wherey();
			    keyhit();
			    if(end!=0)
			     break;
			    gotoxy(x,y); cout<<choice; delay(500);
			    graphics();
			    if(choice=='1')
			    {
			     while(end==0)
			     {
			      graphics();
			      cout<<"Number of variables - 1 or 2 ?"<<endl<<endl;
			      x=wherex(),y=wherey();
			      keyhit();
			      if(end!=0)
			       break;
			      gotoxy(x,y); cout<<choice; delay(500);
			      graphics();
			      if(choice=='1')
			       lineq1();
			      else if(choice=='2')
			       lineq2();
			      else
			      {
			       cout<<"Number of variables can only be 1 or 2!"; delay(1200);
			      }
			     }
			     if(end==2)
			      end=0;
			    }
			    else if(choice=='2')
			    {
			     while(end==0)
			     {
			      graphics();
			      cout<<"Press enter to continue."<<endl;
			      keyhit();
			      graphics();
			      if(end!=0)
			       break;
			      else if(choice==13)
			       quad();
			      else
			      {
			       cout<<"ERROR!"<<endl; delay(1500);
			      }
			     }
			     if(end==2)
			      end=0;
			    }
			    else
			    {
			     cout<<"No such option is available!"; delay(1200);
			    }
			   }
			   break;
			  }
		  case 2: mensuration();
			   break;
		  case 3: {
			   while(end==0)
			   {
			    graphics();
			    cout<<"Matrices you want to work with - 1 or 2 ?"<<endl<<endl;
			    int x=wherex(),y=wherey();
			    keyhit();
			    if(end!=0)
			     break;
			    gotoxy(x,y); cout<<choice; delay(500);
			    graphics();
			    if(choice=='1')
			     matrix1();
			    else if(choice=='2')
			     matrix2();
			    else
			    {
			     cout<<"No such option is available!"; delay(1200);
			    }
			   }
			   break;
			  }
		  case 4: trigo(); break;
		  case 5: log(); break;
		  case 6: pow(); break;
		  case 7: {
			   while(end==0)
			   {
			    graphics();
			    cout<<"Press enter to continue."<<endl;
			    keyhit(); graphics();
			    if(choice==13)
			     arith();
			    else if(end!=0)
			     break;
			    else
			    {
			     cout<<"ERROR!"<<endl; delay(1200);
			    }
			   }
			   break;
			  }
			 }
		    if(end==2)
		     end=0;
		    break;
		 }
		}
      } f=1;
     }
     else if(g==3)
     {
      while(end==0)
      {
       outputtests(w); keyhit();  assign(); min=20; sec=0; timeup=0; once=0;
       if(end!=0)
	break;
       switch(choice)
       {
	case 72: {
		  if(w>1 && w<4)
		  {
		   w--;
		   outputtests(w);
		  }
		  break;
		 }
	case 80: {
		  if(w>0 && w<3)
		  {
		   w++;
		   outputtests(w);
		  }
		  break;
		 }
	case 13: {
		  t1=time(NULL); int i=1,f=0,correct=0;
		  while(end==0 && timeup!=1 && i<16)
		  {
		   graphics('s'); readtests(w); correct=0;
		   timemanage();
		   if(timeup==1)
		    break;
		   gotoxy(51,25); ques[0]=getch();
		   if(ques[0]==27)
		    end=1;
		   if(ques[0]=='q')
		    end=2;
		   if(end!=0)
		    break;
		   if(ques[0]==13)
		    while(ques[0]!=13)
		    {
		     gotoxy(51,25); ques[0]=getch(); cout<<ques[0];
		    }
		   else
		   cout<<ques[0];
		   timemanage();
		   if(timeup==1)
		    break;
		   gotoxy(52,25); ques[1]=getch();
		   if(ques[1]!=13)
		   {
		    cout<<ques[1]; timemanage();
		    if(timeup==1)
		     break;
		    ques[2]=getch();
		   }
		   if(timeup==1)
		    break;
		   if(isdigit(ques[0]) && ques[0]>'0' && ques[1]==13)
		   {
		    correct=1; ques[1]='\0';
		   }
		   else if(ques[0]=='1' && isdigit(ques[1]) && ques[1]<'6' && ques[2]==13)
		   {
		    correct=1; ques[2]='\0';
		   }
		   if(correct==1)
		   {
		    if(userans[atoi(ques)-1][0]==' ')
		    {
		     graphics('t'); readtests(w); i++;
		    }
		    else if(atoi(ques)>0 && userans[atoi(ques)-1][0]!=' ')
		    {
		     gotoxy(51,25); cout<<"    QUESTION ALREADY ANSWERED!"; delay(1200);
		    }
		   }
		   else
		   {
		    gotoxy(51,25); cout<<"    NO QUESTION FOUND!"; delay(1200);
		   }
		   strcpy(ques,"a  ");
		  }
		  if(f==0)
		  {
		   readans(w); f=1;
		  }
		  if(i==16 || timeup==1 || end==2)
		  {
		   if(end==2)
		    end=0;
		   testresult();
		  }
		  strcpy(ques,"a");
		   break;
		 }
       }
      }
     }
     if(end==2)
      end=0;
  } w=1;
 }
 if(end==1 || end==2)
 {
  cleardevice();
  setbkcolor(CYAN);
  setfillstyle(XHATCH_FILL,RED);
  bar(0,0,15,500);
  bar(0,0,700,16);
  bar(625,0,640,500);
  bar(0,465,640,500);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
  gotoxy(0,0);
  outtextxy(235,150,"A Project by : ");
  outtextxy(260,190,"Shubhankar Raj");
  delay(3500);
 }
}




