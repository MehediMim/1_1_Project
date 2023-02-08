# include "iGraphics.h"
#include<math.h>
#include<stdlib.h>
#include<string.h>
// 0 for home
// 1 for log in page
// 2 for c n a page

/////////////////////////////////////////////////
FILE *username_input_file=fopen("Files\\username_input_file.txt","a+");
FILE *mobile_input_file=fopen("Files\\mobile_input_file.txt","a+");
FILE *institution_input_file=fopen("Files\\institution_input_file.txt","a+");
FILE *class_input_file=fopen("Files\\class_input_file.txt","a+");
FILE *password_input_file=fopen("Files\\password_input_file.txt","a+");

////////////////////////////////////////////////MENU VARIABLES
int showtext=0;
int menu_x=1050,menu_y=600,m_x,m_y;
int width=750,lenth=1300;

////////////////////////////////////////////////USER VARIABLES
char username_input[100];
int index_username=0;
char mobile_input[100];
int index_mobile=0;
char institution_input[100];
int index_institution=0;
char class_input[100];
int index_class=0;
char password_input[100];
char encrypted_password_input[100];
int index_password=0;
///////////////////////////////////////////////

//////////////////////////////////////////////////////
char bc[4][200]= {"Images\\bgone.bmp","Images\\loginpage.bmp","Images\\cnapage.bmp","Images\\buttonwhite.bmp"};

bool MusicOn=false;
int gamestate=0;
int cna_substate=0;
int page_substate=0;
/////////////////////////////////////////////////////////////


void home_mouse(int mx,int my)
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
void home_page()
{
    showtext=0;
    iShowBMP(0,0,bc[0]);

}
void login_page()
{
    iShowBMP(0,0,bc[1]);
    if(page_substate==1)
    {
        iSetColor(0,163,109);
        iFilledRectangle(585,386,309,34);


    }
    if(page_substate==2)
    {
        iSetColor(0,163,109);
        iFilledRectangle(585,348,309,34);

    }
    if(showtext==1)
    {
        iText(100,75,"* PASSWORD MUST BE 8 CHARACTER",GLUT_BITMAP_HELVETICA_18);
        iText(100,100,"* USER NAME MUST BE BETWEEN 10 CHARACTER",GLUT_BITMAP_HELVETICA_18);
    }
}
void login_mouse(int mx,int my)
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
    if(mx>=585 && mx<=900 && my>=382 && my<=420)
    {
        PlaySound("Sounds\\enter.wav",NULL, SND_ASYNC);
        page_substate=1;
    }
    if(mx>=585 && mx<=900 && my>=330 && my<=380)
    {
        PlaySound("Sounds\\enter.wav",NULL, SND_ASYNC);
        page_substate=2;
    }
}
void cna_mouse(int mx,int my)
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
    if(mx>=345 && mx<=600 && my>=400 && my<=440)
    {
        PlaySound("Sounds\\enter.wav",NULL, SND_ASYNC);
        cna_substate=4;
    }
    if(mx>=345 && mx<=600 && my>=300 && my<=350)
    {
        PlaySound("Sounds\\enter.wav",NULL, SND_ASYNC);
        cna_substate=5;
    }
}
void cna_page()
{
    iShowBMP(0,0,bc[2]);

    if(cna_substate==1)
    {
        iSetColor(0,163,109);
        iFilledRectangle(348,513,309,34);


    }
    if(cna_substate==2)
    {
        iSetColor(0,163,109);
        iFilledRectangle(348,472,309,34);

    }
    if(cna_substate==3)
    {
        iSetColor(0,163,109);
        iFilledRectangle(348,432,309,34);

    }
    if(cna_substate==4)
    {
        iSetColor(0,163,109);
        iFilledRectangle(348,393,309,34);
    }
    if(cna_substate==5)
    {
        iSetColor(0,163,109);
        iFilledRectangle(348,296,309,34);
    }
    iSetColor(0,0,0);
    iText(355,525,username_input,GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(355,487,mobile_input,GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(355,445,institution_input,GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(355,403,class_input,GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(355,304,password_input,GLUT_BITMAP_HELVETICA_18);


    iSetColor(0,255,255);
    iText(100,75,"* PASSWORD MUST BE 8 CHARACTER",GLUT_BITMAP_HELVETICA_18);
    iText(100,100,"* PRESS ENTER TO PROCEED",GLUT_BITMAP_HELVETICA_18);
    iText(100,125,"* DON'T USE ANY SPACE",GLUT_BITMAP_HELVETICA_18);
}
void input_files(int cna_substate,int key)
{
    if(key==13)
    {
        PlaySound("Sounds\\enter.wav",NULL, SND_ASYNC);
        int i;
        for(i=0; i<8; i++)
        {
            encrypted_password_input[i]=password_input[i]+10;
        }
        encrypted_password_input[i]='\0';
        fprintf(password_input_file, "%s\n", encrypted_password_input);
        fclose(password_input_file);
        username_input[index_username]='\0';
        fprintf(username_input_file, "%s\n", username_input);
        fclose(username_input_file);
        mobile_input[index_mobile]='\0';
        fprintf(mobile_input_file, "%s\n", mobile_input);
        fclose(mobile_input_file);
        institution_input[index_institution]='\0';
        fprintf(institution_input_file, "%s\n", institution_input);
        fclose(institution_input_file);
        class_input[index_class]='\0';
        fprintf(class_input_file, "%s\n", class_input);
        fclose(class_input_file);
        gamestate=1;
    }
    if(cna_substate==1)
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
    if(cna_substate==2)
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
            if(index_mobile>=0)
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
    if(cna_substate==3)
    {

        if (key !='\b')
        {
            PlaySound("Sounds\\enter.wav",NULL, SND_ASYNC);
            institution_input[index_institution]=key;
            institution_input[index_institution+1]='\0';
            index_institution++;
        }
        else
        {
            if(index_institution>=0)
            {
                institution_input[index_institution-1]='\0';
                index_institution--;
            }
            else
            {
                index_institution=0;
            }
        }
    }
    if(cna_substate==4)
    {


        if (key !='\b')
        {
            PlaySound("Sounds\\enter.wav",NULL, SND_ASYNC);
            class_input[index_class]=key;
            class_input[index_class+1]='\0';
            index_class++;
        }
        else
        {
            if(index_class>=0)
            {
                class_input[index_class-1]='\0';
                index_class--;
            }
            else
            {
                index_class=0;
            }
        }
    }
    if(cna_substate==5)
    {


        if (key !='\b')
        {
            PlaySound("Sounds\\enter.wav",NULL, SND_ASYNC);
            password_input[index_password]=key;
            password_input[index_password+1]='\0';
            index_password++;
        }
        else
        {
            if(index_password>=0)
            {
                password_input[index_password-1]='\0';
                index_password--;
            }
            else
            {
                index_password=0;
            }
        }
    }
}
void iDraw()
{

    iClear();
    if(gamestate==0)
    {
        home_page();
    }
    if(gamestate==1)
    {
        login_page();
    }
    if(gamestate==2)
    {
        cna_page();
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
        if(gamestate==0)
        {
            home_mouse(mx,my);
        }
        if(gamestate==1 )
        {
            login_mouse(mx,my);
        }
        if(gamestate==2)
        {
            cna_mouse(mx,my);
        }



    }
}
void iKeyboard(unsigned char key)
{
    if(gamestate==2)
    {
        input_files(cna_substate,key);
    }

}
void iSpecialKeyboard(unsigned char key)
{
    if(gamestate==2)
    {

        if (key == GLUT_KEY_DOWN)
        {
            cna_substate++;
        }
        if (key == GLUT_KEY_UP)
        {
            cna_substate--;
        }
    }
}
int main()
{

    if(MusicOn)
    {
        //PlaySound("Sounds\\Puzzle_click_sound.wav",NULL, SND_ASYNC);
    }
    iInitialize(lenth, width, "CLASSROOM");

    return 0;
}
