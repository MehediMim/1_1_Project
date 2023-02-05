# include "iGraphics.h"

// 0 for home
// 1 for log in page
// 2 for c n a page

////////////////////////////////////////////////MENU VARIABLES
int showtext=0;
int menu_x=1050,menu_y=600,m_x,m_y;
int width=750,lenth=1300;

////////////////////////////////////////////////USER VARIABLES
char username_input[100];
int index_username=0;
char mobile_input[100];
int index_mobile=0;

char bc[4][200]= {"Images\\bgone.bmp","Images\\loginpage.bmp","Images\\cnapage.bmp","Images\\buttonwhite.bmp"};

bool MusicOn=false;
int gamestate=0;
int cna_substate=0;
// 1 for user name input
// 2 for mobile number input
// 3 for Institute
/////////////////////////////////////////////////////////////
void iDraw()
{

    iClear();
    if(gamestate==0)
    {
        showtext=0;
        iShowBMP(0,0,bc[0]);
    }
    if(gamestate==1)
    {
        iShowBMP(0,0,bc[1]);
        if(showtext==1)
        {
            iText(100,75,"* PASSWORD MUST BE 8 CHARACTER",GLUT_BITMAP_HELVETICA_18);
            iText(100,100,"* USER NAME MUST BE BETWEEN 10 CHARACTER",GLUT_BITMAP_HELVETICA_18);
        }
    }
    if(gamestate==2)
    {
        iShowBMP(0,0,bc[2]);

        if(cna_substate==1)
        {
            iSetColor(0,163,109);
            iFilledRectangle(348,513,309,34);
            iSetColor(0,0,0);
            iText(355,525,username_input,GLUT_BITMAP_HELVETICA_18);
            iSetColor(0,0,0);
            iText(355,487,mobile_input,GLUT_BITMAP_HELVETICA_18);
            iSetColor(0,0,0);
            iText(355,525,username_input,GLUT_BITMAP_HELVETICA_18);

        }
        if(cna_substate==2)
        {
            iSetColor(0,163,109);
            iFilledRectangle(348,472,309,34);
            iSetColor(0,0,0);
            iText(355,525,username_input,GLUT_BITMAP_HELVETICA_18);
            iSetColor(0,0,0);
            iText(355,487,mobile_input,GLUT_BITMAP_HELVETICA_18);
            iSetColor(0,0,0);
            iText(355,525,username_input,GLUT_BITMAP_HELVETICA_18);

        }
        if(cna_substate==3)
        {
            iSetColor(0,163,109);
            iFilledRectangle(348,432,309,34);
            iSetColor(0,0,0);
            iText(355,525,username_input,GLUT_BITMAP_HELVETICA_18);
            iSetColor(0,0,0);
            iText(355,487,mobile_input,GLUT_BITMAP_HELVETICA_18);
            iSetColor(0,0,0);
            iText(355,525,username_input,GLUT_BITMAP_HELVETICA_18);

        }
        if(showtext==1)
        {
            iText(100,75,"* PASSWORD MUST BE 8 CHARACTER",GLUT_BITMAP_HELVETICA_18);
            iText(100,100,"* USER NAME MUST BE BETWEEN 10 CHARACTER",GLUT_BITMAP_HELVETICA_18);
        }
    }



}
void iMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(gamestate==0)          /////////////////////////////menu
        {
            if(my>=300 && my<=550 && mx>=200 && mx<=370)
            {
                PlaySound("Sounds\\enter.wav",NULL, SND_ASYNC);
                gamestate=1;

            }
            if(my>=300 && my<=550 && mx>=390 && mx<=550)
            {
                PlaySound("Sounds\\enter.wav",NULL, SND_ASYNC);
                gamestate=2;

            }
        }
        if(gamestate==1 || gamestate==2)
        {
            if(my>=650 && my<=750 && mx>=00 && mx<=120)
            {
                PlaySound("Sounds\\back.wav",NULL, SND_ASYNC);
                gamestate=0;

            }
            if(my>=0 && my<=100 && mx>=00 && mx<=120)
            {
                PlaySound("Sounds\\back.wav",NULL, SND_ASYNC);
                showtext=1;

            }
        }
        if(gamestate==2)
        {
            if(mx>=345 && mx<=600 && my>=520 && my<=560)
            {
                PlaySound("Sounds\\enter.wav",NULL, SND_ASYNC);
                cna_substate=1;
            }
            if(mx>=345 && mx<=600 && my>=480 && my<=520)
            {
                PlaySound("Sounds\\enter.wav",NULL, SND_ASYNC);
                cna_substate=2;
            }
            if(mx>=345 && mx<=600 && my>=440 && my<=480)
            {
                PlaySound("Sounds\\enter.wav",NULL, SND_ASYNC);
                cna_substate=3;
            }
        }



    }
}

void iKeyboard(unsigned char key)
{
    if(gamestate==2 )        ////////////////// Taking Username
    {
        if(cna_substate==1)         ////////////////// User Name Box
        {


            if (key !='\b')
            {
                PlaySound("Sounds\\enter.wav",NULL, SND_ASYNC);
                username_input[index_username]=key;
                username_input[index_username+1]='\0';
                index_username++;
            }
            else
            {
                if(index_username>=0)
                {
                    username_input[index_username-1]='\0';
                    index_username--;
                }
                else
                {
                    index_username=0;
                }
            }
        }
        if(cna_substate==2)         ////////////////// Mobile Box
        {


            if (key !='\b')
            {
                PlaySound("Sounds\\enter.wav",NULL, SND_ASYNC);
                mobile_input[index_mobile]=key;
                mobile_input[index_mobile+1]='\0';
                index_mobile++;
            }
            else
            {
                if(index_username>=0)
                {
                    mobile_input[index_mobile-1]='\0';
                    index_mobile--;
                }
                else
                {
                    index_mobile=0;
                }
            }
        }

    }
}

void iSpecialKeyboard(unsigned char key)
{

    if (key == GLUT_KEY_END)
    {
        exit(0);
    }
}


int main()
{
    printf("%s\n",username_input);
    if(MusicOn)
    {
        //PlaySound("Sounds\\Puzzle_click_sound.wav",NULL, SND_ASYNC);
    }
    iInitialize(lenth, width, "CLASSROOM");

    return 0;
}
