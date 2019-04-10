#include<stdio.h>
#include<dos.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
//#include<ctype.h>
#include<time.h>
void fullscreen()
{
keybd_event(VK_MENU,0x38,0,0);
keybd_event(VK_RETURN,0x1c,0,0);
keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}
void loading();
COORD coord = {0,0};
void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void infhang();
void game();
void help();
void about();
void general();
void display();

void new_account();
void sign_in();
void str();
void level1();
void level2();
void level3();
void level4();
void level5();
void level6();
void level7();
void go_on();
void mode();
void dis();
int cov,coh,d,i,scr=0,hmct=0;
int wrong=6;
char que[80],ans[15];
char name[20],l;
void progress(int);
void carrer_mode();
void showhang(int);
void hang();
int a[5];
struct hangman
    {
       char que[167];
       char ans[167];
    }s[19],ss;
void hang1(struct hangman);
void dishang();
int main()
{
    //textbackground(RED);
    system("COLOR F2");
    fullscreen();
	game();
	return 0;
}
void game()
{
	system("cls");
	int j;
	char ch,sh[50]={" WELCOME TO THE INTEGRATED QUIZ AND HANGMAN GAME "};
gotoxy(30,4);
for(j=0;j<20;j++)
{
Sleep(20);
printf("*");
}
for(j=0;j<50;j++)
{
Sleep(25);
printf("%c",sh[j]);
}
for(j=0;j<20;j++)
{
Sleep(20);
printf("*");
}
printf("\n");
gotoxy(30,3);
for(j=0;j<90;j++)
{
  Sleep(10);
  printf("_");
}
gotoxy(40,10);
printf("Do you want to continue to the world of immense knowledge?? \n");
gotoxy(40,11);
printf("Press Y/y to continue..");
ch=getch();
if (ch=='y'||ch=='Y')
{
mode();
}

else
    exit(0);
}
void mode()
{
    int j,sp=39;
    char ca;
    system("cls");
    gotoxy(55,15);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT MODES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(55,18);
    printf("\xAF\xAF 1. Quick play mode/General Quiz MODE \n");
    gotoxy(55,21);
    printf("\xAF\xAF 2. Hangman mode\n");
    gotoxy(55,24);
    printf("\xAF\xAF 3. Career mode \n");
    gotoxy(55,26);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    for(j=15;j<26;j++)
    {
        gotoxy(99,j);
        printf("\xB2\xB2");
    }
    for(j=16;j<26;j++)
    {
        if(j!=18&&j!=21&&j!=24)
        {
           gotoxy(55,j);
           printf("\xB2\xB2");
        }
    }
    gotoxy(0,35);
    printf("\xAF\xAF\xAF Press \'H\' for help \n");
    printf("\xAF\xAF\xAF Press \'A\' to know about game\n");
    printf("\xAF\xAF\xAF Press \'E\' to exit the game \n");
    while(1){
    ca=tolower(getch());
	switch(ca)
	{
	   case '1':general();
	   case '2':hang();
       case '3':carrer_mode();
       case 'h':help();
       case 'a':about();
       case 'e':exit(0);
       default:gotoxy(55,sp++);
                printf("\aIncorrect Input!!!!! please press proper keys... ");
	}
 }
}
void help()
{
    char ch;
    system("cls");
    printf("-HELP-\n");
    printf("\n-----------------------------------------------------\n");
    printf("The game consists of two modes.They are: quick play and career mode\n");
    printf("Quick play mode has the feature to play the game without any login or sign up and the questions are asked randomly without setting of any difficulty. \n");
    printf("On the career mode, a user can have their own profile where they can login or signup and maintain their career record. \n");
    printf("they can actuallly resume the game at the point of time where they left the last time. ");
    printf("All rights reserved\n");
    gotoxy(10,27);
    printf("\x3C\xC4\xC4\xD9 press Esc to back");
	ch=getch();
	if(ch==27)
	{
	    mode();
    }
    else
        help();
}
void about()
{
    char ch;
    system("cls");
    printf("It is a project made by BCT 1st semestar student\n");
    printf("This project fully focuses upon quiz game for users. \n");
    printf("It is a open source program so anyone can change the source code. \n");
    printf("\n\n\n\n\n\nAll rights reserved : Biplov Karna 017, Ashok Budha 013, Rajan Neupane 034 \n");
    gotoxy(10,27);
    printf("\x3C\xC4\xC4\xD9 press Esc to back");
	ch=getch();
	if(ch==27)
	{
	    mode();
    }
    else
        about();
}
int count=0;
void general()
{char p,i,j,k,l;
int arr[]={1,2,3,4,5,6,7,8,9,10,11,12};
int size=12-1;
srand(time(NULL));

for(p= size;p>0;p--){
    int j=rand()%(p+1);

    int temp = arr[p];
    arr[p]=arr[j];
    arr[j]=temp;
}
system("cls");
printf("  \n\n\n       WELCOME TO GENERAL QUIZ MODE !!!!");
	     printf("\n LOADING PLEASE WAIT... \n");
         for(i=0; i<3; i++)
         {
            printf(".");
            Sleep(500);
          }
for(p=0;p<12;p++){
k=arr[p];
printf("PLEASE CHOOSE THE ANSWER (1/2/3/4)\n\n\n");
switch(k){
case 1:
    system("cls");
    
        printf("1. What is the capital city of AFGHANISTAN?\n\n");
        printf("i. Kathmandu \t\t 2. New Delhi \n 3. Kabul \t\t 4. Islamabaad\n");

        l=getch();
        switch(l){

        case '3': count++; break;
        case '1':
		case '2':
		case '4':printf("\n\a --------------------\n");
		    printf("Wrong answer");
					display();
        default:printf("\n\a --------------------\n");
            printf("Invalid Answer");
        			display();
    }
    break;
case 2:
            system("cls");
            printf("Who is the first elected prime minister of NEPAL??\n\n");
            printf("1.Matrika Prasad Koirala\t\t\t 2. B.P. Koirala\n\n3.Krishna Prasad Bhattarai\t\t4.Girija Prasad Koirala\n");
           l=getch();
        switch(l){

        case '2': count++; break;
        case '1':
		case '3':
		case '4':printf("\n\a --------------------\n");
		    printf("Wrong answer");
				display();
        default: printf("\aInvalid Answer");
    }
    break;
case 3:
            system("cls");
            printf("Who is the first football player to win 5 golden boots and 5 baloon d'or?\n\n");
            printf("1. Cristiano Ronaldo\t\t2.Diego Maradona\n3.Zinedine Zidane\t\t4.Lionel Messi\n");
            l=getch();
        switch(l){

        case '4': count++; break;
        case '1':
		case '2':
		case '3':printf("\n\a --------------------\n");
		    printf("Wrong answer");
				display();
        default:printf("\n\a --------------------\n");
            printf("Invalid Answer");
        		display();
    }
    break;
case 4:
            system("cls");
                printf("Who developed C language ?? \n\n");
                printf("1.Charles Babbage \t\t2.Dennis Ritchie\n3.Lady Ada\t\t4.Guido Van Rossum\n");
                l=getch();
        switch(l){

        case '2': count++; break;
        case '1':
		case '3':
		case '4':printf("\n\a --------------------\n");
		    printf("Wrong answer");
				display();
        default:printf("\n\a --------------------\n");
            printf("Invalid Answer");
        		display();
    }
    break;
case 5:
             system("cls");
             printf("Who gifted The Statue of Liberty to USA?\n");
             printf("1.France\t\t 2.Mexico\n3.UK\t\t4.Germany\n");
             l=getch();
        switch(l){

        case '1': count++; break;
        case '3':
		case '2':
		case '4':printf("\n\a --------------------\n");
		    printf("Wrong answer");
				display();
        default:printf("\n\a --------------------\n");
            printf("Invalid Answer");
        		display();
    }
    break;
case 6:
             system("cls");
             printf("Who wrote the book'War and Peace'?\n");
             printf("1.William Shakespeare\t\t 2.Leo Tolstoy\n3.Dennis Bergkamp\t\t4.Anton Chekhov\n");
             l=getch();
        switch(l){

        case '2': count++; break;
        case '1':
		case '3':
		case '4':printf("\n\a --------------------\n");
		    printf("Wrong answer");
				display();
        default:printf("\n\a --------------------\n");
             printf("Invalid Answer");
        		display();
    }
    break;
case 7:
             system("cls");
             printf("Which country won the first edition of ODI world cup ?\n");
             printf("1.Pakistan\t\t 2.Australia\n3.West Indies\t\t4.India\n");
             l=getch();
        switch(l){

        case '3': count++; break;
        case '1':
		case '2':
		case '4':printf("\n\a --------------------\n");
		    printf("Wrong answer");
				display();
        default:printf("\n\a --------------------\n");
            printf("Invalid Answer\n");
        		display();

    }
    break;
case 8:
           		system("cls");
             printf("Who introduced the first super computer to NEPAL ?\n");
             printf("1.CAN\t\t 2.TU\n3.Kathmandu University\t\t4.Central bureau of statistics\n");
             l=getch();
        switch(l){

        case '3': count++; break;
        case '1':
		case '2':
		case '4':printf("\n\a --------------------\n");
		    printf("Wrong answer");
				display();
        default:printf("\n\a --------------------\n");
            printf("Invalid Answer\n");
        		display();

    }
    break;
case 9:
    system("cls");
             printf("Where was The Alexandar Great ?\n");
             printf("1.Serbia\t\t 2.Macedonia\n3.Greece\t\t4.Albania\n");
             l=getch();
        switch(l){

        case '2': count++; break;
        case '1':
		case '3':
		case '4':printf("\n\a --------------------\n");
		    printf("Wrong answer");
				display();
        default:printf("\n\a --------------------\n");
            printf("Invalid Answer\n");
        		display();
    }
    break;
case 10:
    system("cls");
             printf("Leonardo Di Caprio won the oscar for which movie?\n");
             printf("1.Titanic\t\t 2.Revenant\n3.Inception\t\t4.The Beach\n");
             l=getch();
        switch(l){

        case '2': count++; break;
        case '1':
		case '3':
		case '4':printf("\n\a --------------------\n");
		    printf("Wrong answer");
				display();
        default:printf("\n\a --------------------\n");
            printf("Invalid Answer\n");
        		display();
        }
        break;
    case 11:
          system("cls");
             printf("Who made RaniPokhari?\n");
             printf("1.Pratap Malla\t\t 2.Prithivi Narayan Shah\n3.Bhimsen Thapa\t\t4.Bhupatindra Malla\n");
             l=getch();
        switch(l){

        case '1': count++; break;
        case '2':

		case '3':
		case '4':printf("\n\a --------------------\n");
		    printf("Wrong answer");
				display();
        default:printf("\n\a --------------------\n");
            printf("Invalid Answer\n");
        		display();
        }
        break;
    case 12:
                  system("cls");
             printf("Where was the famous mobile company Nokia from?\n");
             printf("1.USA\t\t 2.Phillipies\n3.Finland\t\t4.Iceland\n");
             l=getch();
        switch(l){

        case '3': count++; break;
        case '1':
		case '2':
		case '4':printf("\n\a --------------------\n");
		    printf("Wrong answer");
				display();
        default:printf("\n\a --------------------\n");
            printf("Invalid Answer\n");
        		display();
        }
        break;

}
}
display();

    }
void carrer_mode()
{
    char n;
    int i,j,sp=37;
    system("cls");
    gotoxy(40,5);
   for(i=0;i<30;i++)
    {
        Sleep(10);
        printf("\x2A");
    }
   printf("  WELCOME TO CAREER MODE  ");
   for(i=0;i<30;i++)
    {
        Sleep(10);
        printf("\x2A");
    }
    gotoxy(55,15);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SELECT MODES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(55,19);
    printf("\xAF\xAF 1.New Account");
    gotoxy(55,22);
    printf("\xAF\xAF 2.Sign in");
    gotoxy(55,26);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    for(j=15;j<26;j++)
    {
        gotoxy(99,j);
        printf("\xB2\xB2");
    }
    for(j=16;j<26;j++)
    {
        if(j!=19&&j!=22)
        {
           gotoxy(55,j);
           printf("\xB2\xB2");
        }
    }
    gotoxy(35,35);
    printf("\x3C\xC4\xC4\xD9 press Esc to back");
    while(1){
	n=getch();
    switch(n)           // SWITCH STATEMENT
		{
			case '1':new_account();
			case '2':sign_in();
			case 27 :mode();
			default:gotoxy(55,sp++);
                    printf("\aIncorrect Input!!!!! please press proper keys... ");

		}
    }
}
void new_account()
{

    int te=0,j=0;
    char c,ch,name1[20],password[20];
    FILE *fp;
    fp=fopen("uname.txt","a+");
    user:
    system("cls");
    puts("New Account");
    puts("Enter user name:");
    fflush(stdin);
    gets(name);
    while(fscanf(fp,"%s",&name1)!=EOF)
    {
        if(strcmp(name1,name)==0)
          {
            printf("SORRY\n\aThis name already exits.\n");
            Sleep(250);
            puts("\n\nDo you want to try again????");
            puts("press y for yes and n for no\n");
            ch=getch();
            if(ch=='y' || ch=='Y')
                goto user;
            else
               carrer_mode();
          }
    }
    fprintf(fp,"%s ",name);
    fclose(fp);
    puts("Enter password:");
    fflush(stdin);
    while(j<18)
	{
	    if(j<0)
            j=0;
        upass:
	    c=getch();

	    if(c==8)
        {
            if(j<=0)
                j=1;
            te=--j;
            gotoxy(te,4);
            printf(" ");
            gotoxy(te,4);

        }
	    else if(c==13) break;
	           else
                {
                printf("*");
                password[j]=c;
                j++;
                }

	}
	password[j]='\0';
	if(j==0)
        goto upass;
    fp=fopen("upass.txt","a+");
    fprintf(fp,"%s ",password);
    fclose(fp);
    str();

}
void sign_in()
{
    int te=0,j=0;
    char c,ch,password[20];
    char name1[20],password1[20];
    FILE *fp,*fp1;
    userpass:
    system("cls");
    puts("Sign in");
    puts("Enter user name:");
    fflush(stdin);
    gets(name);
    puts("Enter password:");
    fflush(stdin);

	while(j<18)
	{
	    if(j<0)
            j=0;
        upass:
	    c=getch();

	    if(c==8)
        {
            if(j<=0)
                j=1;
            te=--j;
            gotoxy(te,4);
            printf(" ");
            gotoxy(te,4);

        }
	    else if(c==13) break;
	           else
                {
                printf("*");
                password[j]=c;
                j++;
                }

	}
	password[j]='\0';
	if(j==0)
        goto upass;
    fp1=fopen("upass.txt","a+");
    fp=fopen("uname.txt","a+");
  while(fscanf(fp,"%s",&name1)!=EOF && fscanf(fp1,"%s",&password1)!=EOF )
  {
    if(strcmp(name1,name)==0 && strcmp(password1,password)==0 )
     {
         printf("  \n\n\n       WELCOME TO QUIZ CAREER MODE !!!! LOGIN IS SUCCESSFUL");
	     printf("\n LOADING PLEASE WAIT... \n");
         for(i=0; i<3; i++)
         {
            printf(".");
            Sleep(500);
          }
	      printf("\n\n\n\t\t\t\tPress any key to continue...");
	      getch();
          go_on();
     }
   }
        printf("\n\aSORRY\n your name and password are incorrect.\n");
        getch();
        fflush(stdin);
        puts("\nDo you want to try again????");
        puts("press y for yes and n no:\t");
        ch=getch();
        if(ch=='y' || ch=='Y')
           goto userpass;
        else
           exit(1);
    fclose(fp);
    fclose(fp1);

}

void str()
{
    printf("\n LOADING PLEASE WAIT... \n");
                 for(i=0; i<3; i++)
                {
                    printf(".");
                    Sleep(500);
                }
    level1();
}
void level1()
{   int cnt=0;
        progress(cnt);
        cnt++;
        system("cls");
        printf("LEVEL 1\n");
        printf("PLEASE CHOOSE THE ANSWER (1/2/3/4)\n\n\n");
        printf("1. What is the capital city of Poland?\n\n");
        printf("i. Warsaw \t\t 2. Islamabad \n 3. Budapest \t\t 4.Munich\n");

        l=getch();
        switch(l){

        case '1':printf("\ncorrect answer !!!!\npress enter key to continue");
                 getch();
                 break;
        case '3':
		case '2':
		case '4':printf("\n\a --------------------\n");
		         printf("Wrong answer !!!");
		         getch();
                 carrer_mode();
        default:printf("\n\a --------------------\n");
                printf("Invalid Answer");
        		getch();
                carrer_mode();
        }

     system("cls");
    printf("PLEASE CHOOSE THE ANSWER (1/2/3/4)\n\n\n");
        printf("2. Who is the current CEO of Google?\n\n");
        printf("i. SK Raman\t\t 2. Sundar Pichai \n 3. Tim Cook \t\t 4. Steve Jobs\n");
        l=getch();
        switch(l){

        case '2':printf("\ncorrect answer !!!!\npress enter key to continue");
                 getch();
                 break;
        case '1':
		case '3':
		case '4':printf("\n\a --------------------\n");
		         printf("Wrong answer !!!");
		         getch();
                 carrer_mode();
        default:printf("\n\a --------------------\n");
                printf("Invalid Answer !!!");
                getch();
                carrer_mode();
    }
     system("cls");
    printf("PLEASE CHOOSE THE ANSWER (1/2/3/4)\n\n\n");
        printf("3. Who made the first programming language in the history of computer ?\n\n");
        printf("i. George Atnasoff \t\t 2. Denis Ritchie \n 3. Charles Babbage\t\t 4. Lady Ada\n");

        l=getch();
        switch(l){

        case '4':printf("\ncorrect answer !!!!\npress enter key to continue");
                 getch();
                 printf("\n GAME IS BEING SAVED PLEASE WAIT... \n");
                 for(i=0; i<3; i++)
                 {
                    printf(".");
                    Sleep(500);
                 }
                 progress(cnt);
                 printf("\ncongratulations !!!\nyou have finished first level\npress enter key to enter next level:");
                 getch();
                 printf("\n LOADING PLEASE WAIT... \n");
                 for(i=0; i<3; i++)
                {
                    printf(".");
                    Sleep(500);
                }
                level2();
        case '1':
		case '2':
		case '3':printf("\n\a --------------------\n");
		         printf("Wrong answer !!!");
		         getch();
                 carrer_mode();
        default:printf("\n\a --------------------\n");
                printf("Invalid Answer !!!");
                getch();
                carrer_mode();

    }
}
void level2()
{
      int cnt=2;
      system("cls");
      printf("LEVEL 2\n");
    printf("PLEASE CHOOSE THE ANSWER (1/2/3/4)\n\n\n");
        printf("1. Who is the current prime minister of UK?\n\n");
        printf("1. David Cameroon \t\t 2. Angela Marquel \n 3. Theresa May \t\t 4. Margaret Thactcher\n");

        l=getch();
        switch(l){

        case '3':printf("\ncorrect answer !!!!\npress enter key to continue");
                 getch();
                 break;
        case '1':
		case '2':
		case '4':printf("\n\a --------------------\n");
		         printf("Wrong answer !!!");
		         getch();
                 carrer_mode();
        default:printf("\n\a --------------------\n");
                printf("Invalid Answer !!!");
                getch();
                carrer_mode();

    }
 system("cls");
    printf("PLEASE CHOOSE THE ANSWER (1/2/3/4)\n\n\n");
        printf("2. What is the scientific name of tiger ?\n\n");
        printf("i. Rana Tigrina \t\t 2. Tigris mammalia \n 3. Pantera Tigris \t\t 4. Naja Naja\n");

        l=getch();
        switch(l){

        case '3':printf("\ncorrect answer !!!!\npress enter key to continue");
                 getch();
                 break;
        case '1':
		case '2':
		case '4':printf("\n\a--------------------\n");
		         printf("Wrong answer !!!");
		         getch();
                 carrer_mode();
        default:printf("\n\a --------------------\n");
                printf("Invalid Answer !!!");
                getch();
                carrer_mode();
    }
 system("cls");
    printf("PLEASE CHOOSE THE ANSWER (1/2/3/4)\n\n\n");
        printf("3. Which of the following was not the founding member of SAARC?\n\n");
        printf("i. China \t\t 2. India \n 3. Afghanistan \t\t 4. Nepal\n");

        l=getch();
        switch(l){

        case '3':printf("\ncorrect answer !!!!\npress enter key to continue");
                 getch();
                 printf("\n GAME IS BEING SAVED PLEASE WAIT... \n");
                 for(i=0; i<3; i++)
                 {
                    printf(".");
                    Sleep(500);
                 }
                 progress(cnt);
                 printf("\ncongratulations !!!\nyou have finished second level\npress enter key to enter next level:");
                 getch();
                 printf("\n LOADING PLEASE WAIT... \n");
                 for(i=0; i<3; i++)
                {
                    printf(".");
                    Sleep(500);
                }
                 level3();
        case '1':
		case '2':
		case '4':printf("\n\a --------------------\n");
		         printf("Wrong answer !!!");
		         getch();
                 carrer_mode();
        default:printf("\n\a --------------------\n");
                printf("Invalid Answer !!!");
                getch();
                carrer_mode();
    }
}
void level3()
{
    int cnt=3;
    system("cls");
    printf("LEVEL 3\n");
    printf("PLEASE CHOOSE THE ANSWER (1/2/3/4)\n\n\n");
        printf("1. Who is the literary figure to win the Madan Puraskar most no. of time?\n\n");
        printf("i. Satya Mohan Joshi \t\t 2. Bhawani Bhikshu \n 3. Daibagya Raj Neupane \t\t 4. Dhruba Chandra Gautam\n");

        l=getch();
        switch(l){

        case '1':printf("\ncorrect answer !!!!\npress enter key to continue");
                 getch();
                 break;
        case '3':
		case '2':
		case '4':printf("\n\a --------------------\n");
		         printf("Wrong answer !!!");
		         getch();
                 carrer_mode();
        default:printf("\n\a--------------------\n");
                printf("Invalid Answer !!!");
                getch();
                carrer_mode();
    }
     system("cls");
    printf("PLEASE CHOOSE THE ANSWER (1/2/3/4)\n\n\n");
        printf("2. Who was the first person killed in Kot Parva?\n\n");
        printf("i. Bam Bahadur Rana \t\t 2. Gagan Singh \n 3. Birdhoj Basnet \t\t 4. Abhiman Singh Basnet\n");

        l=getch();
        switch(l){

        case '4':printf("\ncorrect answer !!!!\npress enter key to continue");
                 getch();
                 break;
        case '1':
		case '2':
		case '3':printf("\n\a --------------------\n");
                 printf("Wrong answer !!!");
                 getch();
                 carrer_mode();
        default:printf("\n\a --------------------\n");
                printf("Invalid Answer !!!");
                getch();
                carrer_mode();
    }
     system("cls");
    printf("PLEASE CHOOSE THE ANSWER (1/2/3/4)\n\n\n");
        printf("3. Which is the most photographed mountain in the world ?\n\n");
        printf("i. Mt. Aconcagua \t\t 2. Mt. Fuji \n 3. Mt. Kilimanjaro \t\t 4. Mt. Elbrus\n");

        l=getch();
        switch(l){

        case '2':printf("\ncorrect answer !!!!\npress enter key to continue");
                 getch();
                 printf("\n GAME IS BEING SAVED PLEASE WAIT... \n");
                 for(i=0; i<3; i++)
                 {
                    printf(".");
                    Sleep(500);
                 }
                 progress(cnt);
                 printf("\ncongratulations !!!\nyou have finished third level\npress enter key to enter next level:");
                 getch();
                 printf("\n LOADING PLEASE WAIT... \n");
                 for(i=0; i<3; i++)
                {
                    printf(".");
                    Sleep(500);
                }
                 level4();
        case '1':
		case '3':
		case '4':printf("\n\a --------------------\n");
		         printf("Wrong answer !!!");
		         getch();
                 carrer_mode();
        default:printf("\n\a --------------------\n");
                printf("Invalid Answer !!!");
                getch();
                carrer_mode();
    }
}
void level4()
{
    int cnt =4;
     system("cls");
     printf("LEVEL 4\n");
    printf("PLEASE CHOOSE THE ANSWER (1/2/3/4)\n\n\n");
        printf("1. Which is the only city to have conducted both Summer and Winter Olympics?\n\n");
        printf("i. Beijing \t\t 2. Sydney \n 3. Sochi \t\t 4. Tokyo\n");

        l=getch();
        switch(l){

        case '1':printf("\ncorrect answer !!!!\npress enter key to continue");
                 getch();
                 break;
        case '3':
		case '2':
		case '4':printf("\n\a --------------------\n");
		         printf("Wrong answer !!!");
		         getch();
                 carrer_mode();
        default:printf("\n\a --------------------\n");
                printf("Invalid Answer !!!");
                getch();
                carrer_mode();
    }
     system("cls");
    printf("PLEASE CHOOSE THE ANSWER (1/2/3/4)\n\n\n");
        printf("2. What was the name of organization established by Martin Luther King to fight slavery ?\n\n");
        printf("1. Humanity for all \t\t 2. All for humanity \n 3. Black Panther  \t\t 4. Pink Panther \n");

        l=getch();
        switch(l){

        case '3':printf("\ncorrect answer !!!!\npress enter key to continue");
                 getch();
                 break;
        case '1':
		case '2':
		case '4':printf("\n\a --------------------\n");
		         printf("Wrong answer !!!");
                 getch();
                 carrer_mode();
        default:printf("\n\a --------------------\n");
                printf("Invalid Answer !!!");
                getch();
                carrer_mode();
    }
     system("cls");
    printf("PLEASE CHOOSE THE ANSWER (1/2/3/4)\n\n\n");
        printf("3. Who was the Prime Minister of Nepal during First World War?\n\n");
        printf("1. Judda Shumsher\t\t 2. Chandra Shumsher \n 3. Bir Shumsher\t\t 4. Junga Bahadur Rana\n");

        l=getch();
        switch(l){

        case '2':printf("\ncorrect answer !!!!\npress enter key to continue");
                 getch();
                 printf("\n GAME IS BEING SAVED PLEASE WAIT... \n");
                 for(i=0; i<3; i++)
                 {
                    printf(".");
                    Sleep(500);
                 }
                 progress(cnt);
                 printf("\ncongratulations !!!\nyou have finished fourth level\npress enter key to enter next level:");
                 getch();
                 printf("\n LOADING PLEASE WAIT... \n");
                 for(i=0; i<3; i++)
                {
                    printf(".");
                    Sleep(500);
                }
                 level5();
        case '1':
		case '3':
		case '4':printf("\n\a --------------------\n");
		         printf("Wrong answer !!!");
                 getch();
                 carrer_mode();
        default:printf("\n\a --------------------\n");
                printf("Invalid Answer !!!");
                getch();
                carrer_mode();
    }
}
void level5()
{
    int cnt=5;
    system("cls");
    printf("LEVEL 5\n");
    printf("PLEASE CHOOSE THE ANSWER (1/2/3/4)\n\n\n");
        printf("1. Who was the man of the match of the Fifa World Cup Final 2010?\n\n");
        printf("i. Robin Van Persie \t\t 2.Pedro Rodriguez \n 3. Andres Iniesta\t\t 4. David Villa\n");

        l=getch();
        switch(l){

        case '3':printf("\ncorrect answer !!!!\npress enter key to continue");
                 getch();
                 break;
        case '1':
		case '2':
		case '4':printf("\n\a --------------------\n");
		         printf("Wrong answer !!!");
                 getch();
                 carrer_mode();
        default:printf("\n\a --------------------\n");
                printf("Invalid Answer !!!");
                getch();
                carrer_mode();
    }
     system("cls");
    printf("PLEASE CHOOSE THE ANSWER (1/2/3/4)\n\n\n");
        printf("2. When is Women's Day celebrated ?\n\n");
        printf("i. 8th March \t\t 2. 12th January \n 3. 25th February \t\t 4. 14th February\n");

        l=getch();
        switch(l){

        case '1':printf("\ncorrect answer !!!!\npress enter key to continue");
                 getch();
                 break;
        case '3':
		case '2':
		case '4':printf("\n \a--------------------\n");
		         printf("Wrong answer !!!");
                 getch();
                 carrer_mode();
        default:printf("\n\a --------------------\n");
                printf("Invalid Answer !!!");
                getch();
                carrer_mode();
    }
     system("cls");
    printf("PLEASE CHOOSE THE ANSWER (1/2/3/4)\n\n\n");
        printf("3. What was the capital city of Usa before Washington DC?\n\n");
        printf("1. Las Vegas\t\t 2. Chicago\n 3. New York\t\t 4. Philadelphia\n");

        l=getch();
        switch(l){

        case '4':printf("\ncorrect answer !!!!\npress enter key to continue");
                 getch();
                 printf("\n GAME IS BEING SAVED PLEASE WAIT... \n");
                 for(i=0; i<3; i++)
                 {
                    printf(".");
                    Sleep(500);
                 }
                 progress(cnt);
                 printf("\ncongratulations !!!\nyou have finished fifth level\npress enter key to enter next level:");
                 getch();
                 printf("\n LOADING PLEASE WAIT... \n");
                 for(i=0; i<3; i++)
                {
                    printf(".");
                    Sleep(500);
                }
                 level6();
        case '1':
		case '2':
		case '3':printf("\n\a --------------------\n");
		         printf("Wrong answer !!!");
                 getch();
                 carrer_mode();
        default:printf("\n\a --------------------\n");
                printf("Invalid Answer !!!");
                getch();
                carrer_mode();
    }
}
void level6()
{
    int cnt=6;
    system("cls");
    printf("LEVEL 6\n");
    printf("PLEASE CHOOSE THE ANSWER (1/2/3/4)\n\n\n");
        printf("1. Where was Nikolas Tesla from?\n\n");
        printf("1.Croatia \t\t 2.Poland \n 3. Spain \t\t 4.Bosnia\n");

        l=getch();
        switch(l){

        case '1':printf("\ncorrect answer !!!!\npress enter key to continue");
                 getch();
                 break;
        case '2':
		case '3':
		case '4':printf("\n\a--------------------\n");
		         printf("Wrong answer !!!");
                 getch();
                 carrer_mode();
        default:printf("\n\a --------------------\n");
                printf("Invalid Answer !!!");
                getch();
                carrer_mode();
    }
     system("cls");
    printf("PLEASE CHOOSE THE ANSWER (1/2/3/4)\n\n\n");
        printf("2.What is the no. of countries involved in EU(European Union) ?\n\n");
        printf("1.12\t\t 2.11\n 3.13\t\t 4.14\n");

        l=getch();
        switch(l){

        case '1':printf("\ncorrect answer !!!!\npress enter key to continue");
                 getch();
                 break;
        case '3':
		case '2':
		case '4':printf("\n\a --------------------\n");
		         printf("Wrong answer !!!");
                 getch();
                 carrer_mode();
        default:printf("\n\a --------------------\n");
                printf("Invalid Answer !!!");
                getch();
                carrer_mode();
    }
         system("cls");
    printf("PLEASE CHOOSE THE ANSWER (1/2/3/4)\n\n\n");
        printf("3.\"The Last Supper\" was the famous creation of whom?\n\n");
        printf("1.Pablo Picasso\t\t 2.Leonardo Da Vinci\n 3. Aristotle\t\t 4.Bekhaman Shakya\n");

        l=getch();
        switch(l){

        case '2':printf("\ncorrect answer !!!!\npress enter key to continue");
                 getch();
                 printf("\n GAME IS BEING SAVED PLEASE WAIT... \n");
                 for(i=0; i<3; i++)
                 {
                    printf(".");
                    Sleep(500);
                 }
                 progress(cnt);
                 printf("\ncongratulations !!!\nyou have finished sixth level\npress enter key to enter next level:");                 system("cls");
                 getch();
                 printf("\n LOADING PLEASE WAIT... \n");
                 for(i=0; i<3; i++)
                {
                    printf(".");
                    Sleep(500);
                }
                 level7();
        case '3':
		case '1':
		case '4':printf("\n\a --------------------\n");
		         printf("Wrong answer !!!");
                 getch();
                 carrer_mode();
        default:printf("\n\a --------------------\n");
                printf("Invalid Answer !!!");
                getch();
                carrer_mode();
    }
}
void level7()
{
    int cnt=7;
    system("cls");
    printf("LEVEL 7\n");
    printf("PLEASE CHOOSE THE ANSWER (1/2/3/4)\n\n\n");
        printf("1.Messi created the world record of highest no. of goals in a calendar year. How many goals did he score that year?\n\n");
        printf("1.79\t\t 2.95\n 3.89\t\t 4.91\n");

        l=getch();
        switch(l){

        case '4':printf("\ncorrect answer !!!!\npress enter key to continue");
                 getch();
                 break;
        case '3':
		case '2':
		case '1':printf("\n\a --------------------\n");
		         printf("Wrong answer !!!");
                 getch();
                 carrer_mode();
        default:printf("\n\a --------------------\n");
                printf("Invalid Answer !!!");
                getch();
                carrer_mode();
    }
    system("cls");
    printf("PLEASE CHOOSE THE ANSWER (1/2/3/4)\n\n\n");
        printf("2.Which was the first INGO to be established in Nepal?\n\n");
        printf("1.ADb\t\t2.ecafe\n3.UNDP\t\t4.UNMIN\n");

        l=getch();
        switch(l){

        case '2':printf("\ncorrect answer !!!!\npress enter key to continue");
                 getch();
                 break;
        case '3':
		case '4':
		case '1':printf("\n\a --------------------\n");
		         printf("Wrong answer !!!");
                 getch();
                 carrer_mode();
        default:printf("\n\a --------------------\n");
                printf("Invalid Answer !!!");
                getch();
                carrer_mode();
    }
         system("cls");
    printf("PLEASE CHOOSE THE ANSWER (1/2/3/4)\n\n\n");
        printf("3.What is the no. of countries involved in EU(European Union) ?\n\n");
        printf("1.12\t\t 2.11\n 3.13\t\t 4.14\n");

        l=getch();
        switch(l){

        case '1':printf("\ncorrect answer !!!!\npress enter key to continue");
                 getch();
                 printf("\n GAME IS BEING SAVED PLEASE WAIT... \n");
                 for(i=0; i<3; i++)
                 {
                    printf(".");
                    Sleep(500);
                 }
                 progress(cnt);
                 printf("\ncongratulations !!!\nyou have finished all level\npress enter key to continue:");
                 getch();
                 printf("\n LOADING PLEASE WAIT... \n");
                 for(i=0; i<3; i++)
                {
                    printf(".");
                    Sleep(500);
                }
                 dis();
        case '3':
		case '2':
		case '4':printf("\n\a --------------------\n");
		         printf("Wrong answer !!!");
                 getch();
                 carrer_mode();
        default:printf("\n\a --------------------\n");
                printf("Invalid Answer !!!");
                getch();
                carrer_mode();
    }
}
void dis()
{

    printf("CONGRATULATIONS !!!!!!!!!!!!\nYOU HAVE SUCCESSFULLY FINISHED QUIZ CAREER MODE.\nTHANK YOU FOR PLAYING THIS GAME.\n KEEP IN TOUCH FOR THE NEXT UPDATE OF THE GAME.\n THANK YOU !!!");
    gotoxy(40,20);
    printf("press any key to go to main menu:");
    getch();
    game();
}


void display(){

		printf("\n\nYour score =%d\n",count);
	if (count==12) {
	printf("You are going thorugh the right path.\n");
printf("Our game provides you with a lot other game play modes.\n");
printf("Tons of other questions are waiting you there.\n");
printf("Enjoy playing interactive hangmans.\n");
printf("Log in and sign up using career mode and create your own profile and save your progress report.\n");
printf("----------------------------------------------------------------------------------------------------------\n");
printf("Thank you for trying this mode\n");
	}

	printf("Press any key...");
	count=0;
	getch();
	game();
}
void progress(int cnt)
{
    int f=0,num;
    char name1[20];
    FILE *fp,*fp1;
    fp=fopen("progress1.txt","r");
    fp1=fopen("temp1.txt","a+");
    while(fscanf(fp,"%s%d",&name1,&num)!=EOF)
    {
        if(strcmp(name1,name)==0)
        {
            f=1;
        }
        else
        {
          fprintf(fp1,"%s %d ",name1,num);
        }
    }
    fclose(fp);
    fclose(fp1);
    remove("progress1.txt");
    rename("temp1.txt","progress1.txt");
    fp=fopen("progress1.txt","a");
    fprintf(fp,"%s %d ",name,cnt);
    fclose(fp);
}
void go_on()
{
    char name1[20];
    int num;
    FILE *fp;
    fp=fopen("progress1.txt","r");
    while(fscanf(fp,"%s%d",&name1,&num)!=EOF)
    {
        if(strcmp(name1,name)==0)
        {
            fclose(fp);
            system("cls");
            printf("\n\tGAME IS CONTINUED FROM WHERE YOU HAVE PREVIOUSLY LEFT....");
	        printf("\n LOADING PLEASE WAIT... \n");
            for(i=0; i<3; i++)
            {
                printf(".");
                Sleep(500);
             }
             printf("\n\n\n\t\t\t\tPress any key to continue...");
	         getch();
            switch(num)
            {
            case 0:level1();
            case 1:level2();
            case 2:level3();
            case 3:level4();
            case 4:level5();
            case 5:level6();
            case 6:level7();
            default:dis();
            }
        }
    }
}
 void hang1( struct hangman ss)
{
int i,winner,counter;
char guess[15]={0};
char hangout[15];
int match;
char al;
strcpy(que,ss.que);
strcpy(ans,ss.ans);
system("cls");
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n");

    d=strlen(ans);
cov=13;coh=d+25;
Sleep(500);
printf("\n\n%s\n",que);
Sleep(500);
for(i=0;i<d;i++)
    {
        printf(" ");
        printf("_");
        hangout[i]='_';
    }
    hangout[d]='\0';                    /**put the NULL character at the end of the hangout string**/
    guess[d] = '\0';                    /**put the NULL character at the end of the guess string**/
    printf("\n\n\n\t Your guess ==> _");
    while(wrong!= 0)
    {
        match= 0;
        fflush(stdin);
        al=tolower(getche());
       Sleep(500);
       loading();
    if(al < 97 || al > 137)
    {
        printf("\n\n\t\a Wrong input TRY AGAIN ");
        match = 2;
    }
    if (match != 2)
    {
        for(counter=0;counter<d;counter++)
	    {

	        if(al==guess[counter])
	        {
                goto start;
	        }
		    else if(al==ans[counter])
		     {
               hangout[counter] = al;
               guess[counter] = al;      /**put the alphabet in another char array to check with the original word**/
               match=1;
             }
        }

	   if(match==0)
	    {
     	      --wrong;
     	      printf("\n\nOops!! \a\'%c\' is a Wrong guess!!!",al);
     	      Sleep(1000);
     	      //delay(50);
              showhang(wrong);
	    }

     }// end of if(match!= 2) condition

    printf("\n\n\t");
    for(i = 0 ; i <d ; i++)
      {
          printf(" ");
          printf("%c",hangout[i]);                /**Show the original Word With blanks and right Input alphabet**/
      }
      start:
      gotoxy(25,13);
      printf("\x20");
      gotoxy(25,13);
       winner = strcmp(guess,ans);      /**upon True comparison it will return 0**/
                if(winner == 0)                             /**if the player guessed the whole word right then he/she is the WINNER**/
                {
                    scr = scr+5*wrong;
                    printf("\n\n\t \t YAHOO!!!!! You are the WINNER !!!!!");
                    printf("\n\t The Word was %s ",ans);
                    printf("\n\n\t\tEASY HUH???\n\n");
                    Sleep(1400);
                    system("cls");
                    printf("\n\t\tyour final score is %d\n",scr);
                    wrong=6;
                    printf("\ncongratulations !!!\npress enter key to enter next level:");
                    getch();
                    printf("\n LOADING PLEASE WAIT... \n");
                    for(i=0; i<3; i++)
                    {
                    printf(".");
                    Sleep(500);
                    }
                    if(hmct==5)
                        dishang();
                    else
                    hang1(s[a[hmct++]]);
                }//end of inner if
    }//end of while loop

      if(wrong == 0)
      {
          scr=scr+5*wrong;
          Sleep(500);
          printf("\n\n\t The man is dead");
          printf("\n\n\tyour final score is %d",scr);
          printf("\n\n\t The Word was %s",ans);
	      printf("\n\n\t Better luck next!!!");
	      scr=0;
	      hmct=0;
	      wrong=6;
	      printf("\n\nEnter any character:");
          getch();
	      game();

      }
}
void showhang(int choice)
 {
     switch(choice)
     {
     case 0:
         system("cls");
         printf("\n%s\n\n",que);
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||   / %c",'\\');
	printf("\n\t||      ");
	printf("\n\nYou have %d tries left ",wrong);
	printf("\n\n\t Your guess ==> _");
	break;
     case 1:
         system("cls");
         printf("\n%s\n\n",que);
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||     %c",'\\');
	printf("\n\t||      ");
	printf("\n\nYou have %d tries left ",wrong);
	printf("\n\n\t Your guess ==> _");
	break;
     case 2:
         system("cls");
         printf("\n%s\n\n",que);
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||    | ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\nYou have %d tries left ",wrong);
	printf("\n\n\t Your guess ==> _");
	break;
     case 3:
         system("cls");
         printf("\n%s\n\n",que);
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO/",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\nYou have %d tries left ",wrong);
	printf("\n\n\t Your guess ==> _");
	break;
     case 4:
         system("cls");
         printf("\n%s\n\n",que);
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||   %cO ",'\\');
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\nYou have %d tries left ",wrong);
	printf("\n\n\t Your guess ==> _");
	break;
     case 5:
         system("cls");
         printf("\n%s\n\n",que);
	printf("\n\t||===== ");
	printf("\n\t||    | ");
	printf("\n\t||    O ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\t||      ");
	printf("\n\nYou have %d tries left ",wrong);
	printf("\n\n\t Your guess ==> _");
	break;
     }
 }
 void hang()
 {
    int g,h;
    int b[5],k=0,temp;
    srand(time(NULL));
    for(g=0;g<5;g++)
    {
       temp=rand()%20;
      for(h=0;h<=4;h++)
      {
        if(temp==a[h]|| temp==b[h])
            break;
      }
    if(h==5)
     {
        b[k]=temp;
        k++;
     }
    else
        g--;
    }
    for(g=0;g<5;g++)
    {
        a[g]=b[g];
    }
    FILE *fp;
    fp=fopen("hangman.txt","a+");
    fread(&s,sizeof(struct hangman),19,fp);
    fclose(fp);
    infhang();
    hang1(s[a[hmct++]]);

 }
 void dishang()
 {
  system("cls");
  printf("\n\t\tyour final score is %d\n",scr);
  printf("CONGRATULATIONS !!!!!!!!!!!!\nYOU HAVE SUCCESSFULLY FINISHED HANGMAN MODE.\nTHANK YOU FOR PLAYING THIS GAME.\n KEEP IN TOUCH FOR THE NEXT UPDATE OF THE GAME.\n THANK YOU !!!");
  scr=0;
  hmct=0;
  wrong=6;
  printf("\n\nEnter any character:");
  getch();
  game();
 }
 void loading()
 {
     int cn0,cn1;
     gotoxy(coh,cov);
    printf("Checking");
     for(cn0=0;cn0<3;cn0++)
     {
         for(cn1=0;cn1<3;cn1++)
            {
              printf(".");
              Sleep(200);
            }
         gotoxy(coh+8,cov);
         for(cn1=0;cn1<3;cn1++)
            {
              printf(" ");
            }
            gotoxy(coh+8,cov);
     }
     gotoxy(coh,cov);
     for(cn1=0;cn1<11;cn1++)
     {
         printf("\x20");
     }

 }
 void infhang()
 {
     int i,j=9;
     system("cls");
      gotoxy(40,5);
   for(i=0;i<30;i++)
    {
        Sleep(10);
        printf("\x2A");
    }
   printf("  WELCOME TO HANGMAN GAME  ");
   for(i=0;i<30;i++)
    {
        Sleep(10);
        printf("\x2A");
    }
    gotoxy(80,j);
    printf("||===== ");
    gotoxy(80,++j);
	printf("||    | ");
	gotoxy(80,++j);
	printf("||   %cO/",'\\');
	gotoxy(80,++j);
	printf("||    | ");
	gotoxy(80,++j);
	printf("||   / %c",'\\');
	gotoxy(80,++j);
	printf("||      ");
     printf("\n\nHangman game consists of 5 levels.\nEach level has one question.\nThere are 6 chances and score of 30 points for each question.\nFor each wrong guess,5 points will be reduced.\nAfter 6 wrong guesses,you will be hanged and game will be finished.");
     printf("\n\nPress any key to continue:");
     getch();
 }
