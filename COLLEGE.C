#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<ctype.h>
/* A 3-D Matrix that would store the no. of orbs at the base position and
also the player no. at the upper level.*/
int a[8][8][2];
//i,j for normal rows and col. while chance for depicting the player turn
int i,j,chance=1;

//Initialize the Matrix
void initialize()
{
	for(i=0;i<8;i++)
	{

		for(j=0;j<8;j++)
		{
			a[i][j][0]=0;
			a[i][j][1]=0;
		}
	}
}

//To play the starting Mario theme
void start_sound()
{
	sound(330);delay(100);
	sound (330);delay(300);
	sound (330);delay(300);
	sound (262);delay(100);
	sound (330);delay(300);
	sound (392);delay(700);
	sound (196);delay(700);
	sound (262);delay(300);
	sound (196);delay(300);
	sound (164);delay(300);
	sound (220);delay(100);
	sound (246);delay(300);
	sound (233);delay(500);
	nosound();
}

//Function to print the Matrix
void print()
{
	printf("\n\n");
	for(i=0;i<8;i++)
	{

	    printf("\t----------------------%d---------------------------------\n\t",i+1);
		for(j=0;j<8;j++)

		{
			if(a[i][j][1]==1)
			{
				textcolor(RED);
				if(a[i][j][0]==1)
					cprintf("|  \t  |");
				else if(a[i][j][0]==2)
					cprintf("| \t \t |");
				else if(a[i][j][0]==3)
					cprintf("| \t\t\t |");
				else
					cprintf("|#####|");
			}
			else if(a[i][j][1]==2)
			{
				textcolor(GREEN);
				if(a[i][j][0]==1)
					cprintf("|  \t  |");
				else if(a[i][j][0]==2)
					cprintf("| \t \t |");
				else if(a[i][j][0]==3)
					cprintf("| \t\t\t |");
				else
					cprintf("|#####|");
			}
			else
			{
				textcolor(WHITE);
				cprintf("|     |");
			}
			textcolor(WHITE);
		}
		printf("\n");
	}
}
//Function to check that the entered position is previously occupied or not
int same(int b,int c,int ch)
{
	if((a[b][c][1]==ch)||(a[b][c][1]==0))
		return 1;
	else
	{
		printf("Place Occupied by Opponent");
		delay(1000);
		return 0;
	}
}

//To increment the no. of Orbs
void increment(int pos_i,int pos_j,int player)
{

	if((pos_i==0)&&(pos_j==0))
	{
		if(a[pos_i][pos_j][0]>1)
		{
			a[pos_i][pos_j+1][0]++;
			a[pos_i][pos_j+1][1]=player;
			a[pos_i+1][pos_j][0]++;
			a[pos_i+1][pos_j][1]=player;
			a[pos_i][pos_j][0]=0;
			a[pos_i][pos_j][1]=0;
		}
		else
		{
			a[pos_i][pos_j][0]++;
			a[pos_i][pos_j][1]=player;
		}
	}
	else if((pos_i==0)&&(pos_j==7))
	{
		if(a[pos_i][pos_j][0]>1)
		{
			a[pos_i][pos_j-1][0]++;
			a[pos_i+1][pos_j][0]++;
			a[pos_i][pos_j][0]=0;
			a[pos_i][pos_j-1][1]=player;
			a[pos_i+1][pos_j][1]=player;
			a[pos_i][pos_j][1]=0;
		}
		else
		{
			a[pos_i][pos_j][0]++;
			a[pos_i][pos_j][1]=player;
		}
	}
	else if((pos_i==7)&&(pos_j==0))
	{
		if(a[pos_i][pos_j][0]>1)
		{
			a[pos_i][pos_j+1][0]++;
			a[pos_i-1][pos_j][0]++;
			a[pos_i][pos_j][0]=0;
			a[pos_i][pos_j+1][1]=player;
			a[pos_i-1][pos_j][1]=player;
			a[pos_i][pos_j][1]=0;
		}
		else
		{
			a[pos_i][pos_j][0]++;
			a[pos_i][pos_j][1]=player;
		}
	}
	else if((pos_i==7)&&(pos_j==7))
	{
		if(a[pos_i][pos_j][0]>1)
		{
			a[pos_i][pos_j-1][0]++;
			a[pos_i-1][pos_j][0]++;
			a[pos_i][pos_j][0]=0;
			a[pos_i][pos_j-1][1]=player;
			a[pos_i-1][pos_j][1]=player;
			a[pos_i][pos_j][1]=0;
		}
		else
		{
			a[pos_i][pos_j][0]++;
			a[pos_i][pos_j][1]=player;
		}
	}
	else if((pos_i==0)&&((pos_j>0)&&(pos_j<7)))
	{
		if(a[pos_i][pos_j][0]>2)
		{
			a[pos_i][pos_j-1][0]++;
			a[pos_i+1][pos_j][0]++;
			a[pos_i][pos_j+1][0]++;
			a[pos_i][pos_j][0]=0;
			a[pos_i][pos_j-1][1]=player;
			a[pos_i+1][pos_j][1]=player;
			a[pos_i][pos_j+1][1]=player;
			a[pos_i][pos_j][1]=0;
		}
		else
		{
			a[pos_i][pos_j][0]++;
			a[pos_i][pos_j][1]=player;
		}
	}
	else if((pos_i==7)&&(pos_j>0)&&(pos_j<7))
	{
		if(a[pos_i][pos_j][0]>2)
		{
			a[pos_i][pos_j-1][0]++;
			a[pos_i-1][pos_j][0]++;
			a[pos_i][pos_j+1][0]++;
			a[pos_i][pos_j][0]=0;
			a[pos_i][pos_j-1][1]=player;
			a[pos_i-1][pos_j][1]=player;
			a[pos_i][pos_j+1][1]=player;
			a[pos_i][pos_j][1]=0;
		}
		else
		{
			a[pos_i][pos_j][0]++;
			a[pos_i][pos_j][1]=player;
		}
	}
	else if((pos_j==0)&&(pos_i>0)&&(pos_i<7))
	{
		if(a[pos_i][pos_j][0]>2)
		{
			a[pos_i+1][pos_j][0]++;
			a[pos_i-1][pos_j][0]++;
			a[pos_i][pos_j+1][0]++;
			a[pos_i][pos_j][0]=0;
			a[pos_i+1][pos_j][1]=player;
			a[pos_i-1][pos_j][1]=player;
			a[pos_i][pos_j+1][1]=player;
			a[pos_i][pos_j][1]=0;
		}
		else
		{
			a[pos_i][pos_j][0]++;
			a[pos_i][pos_j][1]=player;
		}
	}
	else if((pos_j==7)&&(pos_i>0)&&(pos_i<7))
	{
		if(a[pos_i][pos_j][0]>2)
		{
			a[pos_i+1][pos_j][0]++;
			a[pos_i-1][pos_j][0]++;
			a[pos_i][pos_j-1][0]++;
			a[pos_i][pos_j][0]=0;
			a[pos_i+1][pos_j][1]=player;
			a[pos_i-1][pos_j][1]=player;
			a[pos_i][pos_j-1][1]=player;
			a[pos_i][pos_j][1]=0;
		}
		else
		{
			a[pos_i][pos_j][0]++;
			a[pos_i][pos_j][1]=player;
		}
	}
	else if((pos_i>0)&&(pos_j>0)&&(pos_i<7)&&(pos_j<7))
	{
		if(a[pos_i][pos_j][0]>3)
		{
			a[pos_i-1][pos_j][0]++;
			a[pos_i+1][pos_j][0]++;
			a[pos_i][pos_j-1][0]++;
			a[pos_i][pos_j+1][0]++;
			a[pos_i][pos_j][0]=0;
			a[pos_i-1][pos_j][1]=player;
			a[pos_i+1][pos_j][1]=player;
			a[pos_i][pos_j-1][1]=player;
			a[pos_i][pos_j+1][1]=player;
			a[pos_i][pos_j][1]=0;
		}
		else
		{
			a[pos_i][pos_j][0]++;
			a[pos_i][pos_j][1]=player;
		}
	}
}
//To check whether the matrix is completely correct in terms of no. of orbs
void check()
{
	int k=0;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if((((i==0)&&(j==0))||((i==0)&&(j==7))||((i==7)&&(j==0))||((i==7)&&(j==7)))&&(a[i][j][0]>1))
			{
				increment(i,j,a[i][j][1]);
				k++;
			}
			else if((((i==0)&&(j>0)&&(j<7))||((i==7)&&(j>0)&&(j<7))||((j==0)&&(i>0)&&(i<7))||((j==7)&&(i>0)&&(i<7)))&&(a[i][j][0]>2))
			{
				increment(i,j,a[i][j][1]);
				k++;
			}
			else if(((i>0)&&(i<7)&&(j>0)&&(j<7))&&(a[i][j][0]>3))
			{
				increment(i,j,a[i][j][1]);
				k++;
			}
		}
	}
	if(k!=0)
		check();
}

//To find the winner
int winner()
{
       int count1=0,count2=0;
       for(i=0;i<8;i++)
       {
		for(j=0;j<8;j++)
		{
			if((a[i][j][0]>0)&&(a[i][j][1]==1))
				count1++;
			else if((a[i][j][0]>0)&&(a[i][j][1]==2))
				count2++;
		}
	}
	if(count1==0)
		return 2;
	else if((count2==0)&&(count1>1))
		return 1;
	else
		return 0;

}

//To play sound at the victory of game
void win_sound()
{
	sound (207);delay(125);
	sound (262);delay(125);
	sound (311);delay(125);
	sound (415);delay(125);
	sound (523);delay(125);
	sound (622);delay(125);
	sound (830);delay(575);
	sound (622);delay(575);
	sound (233);delay(125);
	sound (294);delay(125);
	sound (349);delay(125);
	sound(466);delay(125);
	sound (587);delay(125);
	sound (698);delay(125);
	sound (932);delay(575);
	sound (932);delay(125);
	sound (932);delay(125);
	sound (932);delay(125);
	sound (1046);delay(600);
	nosound();
}
void main()
{
	int m,n,win,ch;
	int gdriver = DETECT, gmode;
	clrscr();
	initialize();
	initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");
	settextstyle(6,0,5);
	outtextxy(200,80,"CHAIN REACTION");
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\tBy Bhargav Yagnik - 17070122077");
	printf("\n\t\t\t   Zainuddin Saiyed  - 17070122079");
	printf("\n\t\t\t   Aditya Singh - 17070122064");
	printf("\n\t\t\t   Rutvik Sonlanki - 17070122066");
	start_sound();
	closegraph();
	clrscr();
	printf("\n\tInstructions for the Game");
	printf("\n\n\t1. A Strategy game for 2 players.");
	printf("\n\n\t2.The Objective of Chain Reaction is to take control of the board by\n\t\teliminating your opponents  orbs");
	printf("\n\n\t3.Players take turns to palce their orbs in cell.");
	printf("\n\n\t4.Once a cell has reached critical mass the orbs explode into the\n\t\tsurrounding cell adding an extra orbs and claiming the cell\n\t\t for the player.");
	printf("\n\n\t5.A Players may only place their orbs in an blank cell or the cell\n\t\tthat contains orbs of their own colour.");
	printf("\n\n\tAs soon as player looses all their orbs they are out of the game");
	printf("\n\n\tPress any key to Continue");
	getch();
	do
	{
		clrscr(); printf("\t\t\t");
		textcolor(RED);
		cprintf("Player 1 has Red colour");
		printf("\n\t\t\t");
		textcolor(GREEN);
		cprintf("Player 2 has Green Colour\n");
		printf("\n\t\tPress '0'. To EXIT\n");
		if(chance==1)
			textcolor(RED);
		else
			textcolor(GREEN);
		cprintf("Enter the place where you want to place your dot(row first):");
		print();  //Print the Matrix
		scanf("%d",&ch);
		fflush(stdin);              //if the user enters a character
		if(ch==-28771)              //by mistake
			exit(0);
		if(ch==0)                   //if the user presses exit the
		{                           //player exiting loses
		     if(chance==1)          //so player_2 and player_1 are the labels

			    goto player_2;
		     else
			    goto player_1;
		}
		else
			m=ch;
		/*If the enteres value is not 0 , then assign it to no.
		of rows i.e. m     */
		scanf("%d",&n);
		m--;
		n--;
		if(((m>=0)&&(m<=7))&&((n>=0)&&(n<=7)))
		if(same(m,n,chance)==1)
		{
			increment(m,n,chance);
			clrscr();
			printf("\n\n\n\n");
   //Print the Matrix after incrementing the orbs
			print();
			delay(1000);
			clrscr();
			check();
    //Print the Matrix after complete increment of the other boxes of matrix
			print();
			win=winner();
			if(win==1)
			{       //Display Winner
				player_1:
				delay(1000);
				clrscr();
				printf("\n\n\n\t\t\tPlayer 1 wins ! ");
				win_sound();
				delay(2000);
				exit(0);
			}
			else if(win==2)
			{
				//Display winner
				player_2:
				delay(1000);
				clrscr();
				printf("\n\n\n\t\t\t Player 2 Wins !");
				win_sound();
				delay(2000);
				exit(0);
			}
			if(chance==1)
				chance=2;
			else
				chance=1;
		}

		else
		{
			print("Enter A valid Position");
			delay(1000);
		}
		print();
	}while(ch!=0);
	getch();
}
