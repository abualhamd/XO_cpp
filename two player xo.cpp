//this is a 2 player xo game
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

void show_arr(char mtrx[],int x_win,int o_win);
int check_row(char arr[]);
int check_col(char arr[]);
int check_main_dgnl(char arr[]);
int check_scnd_dgnl(char arr[]);

int main()
{
    int x_cntr=0,o_cntr=0,turn=0;
    start:

    int i,cntr=0,vlu;
    char arr[9]={0};
    string sqr_ch;

    system("color A");//this controls the color of both the surface and the background

    show_arr(arr,x_cntr,o_cntr);//the function that shows the matrix

    for(i=0;i<9;i++)
    {
        wrng_in:
            system("cls");//to clear the screen
            show_arr(arr,x_cntr,o_cntr);

            if(turn%2==0)
            {
                if(i%2==0)
                    cout<<"player 1:  ";
                else
                    cout<<"player 2:  ";

                cin>>sqr_ch;
            }
            else
           {
                if(i%2!=0)
                    cout<<"player 1:  ";
                else
                    cout<<"player 2:  ";

                cin>>sqr_ch;
            }

            if(sqr_ch.size()>1)//in case the user enters more than one character
            {
                system("cls");
                show_arr(arr,x_cntr,o_cntr);
                cout<<"You should enter only one number between 1 and 9 \n";
                Sleep(3000);//makes the program waits 3 sec before doing anything else
                goto wrng_in;//to resume the program
            }

            if(sqr_ch[0]<49||sqr_ch[0]>57)//in case the user enters a character that isn't a number between 1-9
            {
                cout<<"You should enter only one number between 1 and 9 \n";
                Sleep(2500);//makes the program waits 3 sec before doing anything else
                goto wrng_in;//to resume the program
            }

            sqr_ch[0]-=49;//ASCII code of 1 = 49 and a string is an array of characters so we take the first character

            if(arr[sqr_ch[0]]!=0)//this is to ensure that the user doesn't check a box that's already used
            {
                cout<<"The square is already checked.";
                Sleep(2000);
                goto wrng_in;
            }

            if(turn%2==0)
            {
                if(i%2==0)
                {
                    arr[sqr_ch[0]]='x';
                }
                else
                {
                    arr[sqr_ch[0]]='o';
                }
            }
            else
            {
                if(i%2!=0)
                {
                    arr[sqr_ch[0]]='x';
                }
                else
                {
                    arr[sqr_ch[0]]='o';
                }
            }

            show_arr(arr,x_cntr,o_cntr);

            if(i>3)
            {
                cntr=check_row(arr);
                if(cntr>0)
                    break;
                cntr=check_col(arr);
                if(cntr>0)
                    break;
                cntr=check_main_dgnl(arr);
                if(cntr>0)
                    break;
                cntr=check_scnd_dgnl(arr);
            }

            if(cntr>0)//we use the counter to end the game when one of the players win
                break;
    }
            if(cntr>0)
            {
                if(turn%2==0)
                {
                    if(i%2==0)
                    {
                        cout<<"Player 1 wins. \n";
                        x_cntr++;
                    }

                    else
                    {
                        cout<<"Player 2 wins. \n";
                        o_cntr++;
                    }
                }
                else
                {
                    if(i%2!=0)
                    {
                        cout<<"Player 1 wins. \n";
                        x_cntr++;
                    }

                    else
                    {
                        cout<<"Player 2 wins. \n";
                        o_cntr++;
                    }
                }
            }
    //system("color A");

    if(cntr==0)//just in case
    {
        cout<<"Game ended in a tie. \n";
    }
    //the next part to control starting a new game or not
    cout<<"If you want to play again press 1 or press any other key to exit: \n";
    cin>>vlu;

    if(vlu==1)
    {
        turn++;
        system("cls");//clears the screen
        goto start;
    }

    return 0;
}
void show_arr(char mtrx[],int x_win,int o_win)
{
    system("cls");
    cout<<"player 1 => x        player 2 => o \n";
    cout<<"  win : "<<x_win<<"\t       win : "<<o_win<<endl<<endl;

    for(int i=0;i<9;i++)
    {
        cout<<"     "<<mtrx[i];

        if(((i+1)%3)!=0)
        {
            cout<<"     |";
        }
        else
        {
            if(i+1<9)
            {
                cout<<endl;

                for(int k=0;k<34;k++)
                {
                    cout<<"_";
                }

                cout<<endl;
            }
        }
    }

    cout<<"\n\n";
}
int check_row(char arr[])
{
    int cntr=0;

    for(int r=0;r<9;r+=3)//this loop is to check for rows
    {
        if((arr[r]!=0)&&arr[r]==arr[r+1]&&arr[r+1]==arr[r+2])
        {
            cntr++;
            break;
        }
    }
    return cntr;
}
int check_col(char arr[])
{
    int cntr=0;

    for(int c=0;c<3;c++)//this loop is to check for columns
    {
        if((arr[c]!=0)&&arr[c]==arr[c+3]&&arr[c]==arr[c+6])
        {
            cntr++;
            break;
        }
    }
    return cntr;
}
int check_main_dgnl(char arr[])
{
    int cntr=0;

    if((arr[0]!=0)&&arr[0]==arr[4]&&arr[0]==arr[8])//this one is to check for the main diagonal
    {
        cntr++;
    }
    return cntr;
}
int check_scnd_dgnl(char arr[])
{
    int cntr=0;

    if((arr[2]!=0)&&arr[2]==arr[4]&&arr[2]==arr[6])//this one is to check for the secondary diagonal
    {
        cntr++;
    }
    return cntr;
}
