# include "iGraphics.h"
#include<math.h>
#include<stdlib.h>
#include<string.h>
/////////////////////////////////// COMMENTS //////////////

//@note 0 for home
//@note 1 for log in page
//@note 2 for create new account page
//@note 3 for profile homepage join or create
//@note 4 for create class
//@note 5 for announcement page
//@note 6 for profile
//@note 7 for classwork
//@note 8 for people
//@note 9 for grades
//@note 10 for join class

int gameset = 1;

/////////////////////////////////// FILE VARIABLES ////////
FILE *username_input_file=fopen("Files/username_input_file.txt","a+");
FILE *mobile_input_file=fopen("Files/mobile_input_file.txt","a+");
FILE *institution_input_file=fopen("Files/institution_input_file.txt","a+");
FILE *class_input_file=fopen("Files/class_input_file.txt","a+");
FILE *password_input_file=fopen("Files/password_input_file.txt","a+");

FILE *username_checker_file=fopen("Files/username_input_file.txt","r");
FILE *password_checker_file=fopen("Files/password_input_file.txt","r");

FILE *class_code_file=fopen("Files/class_input.txt","a+");
FILE *announcement_file=fopen("Files/announcement.txt","a+");
FILE *joinclass_file=fopen("Files/class_input.txt","r");

/////////////////////////////////// MENU VARIABLES /////////
int showtext=0;
int width=750,lenth=1300;

/////////////////////////////////// CNA VARIABLES //////////
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


char announcement_input[1000];
int index_announcement=0;
char joinclass_class[100];
int index_joinclass_class=0;
///////////////////////////////// LOG IN VARIABLES ///////
char username[100];
int index_username_login=0;
char password[100];
int index_password_login=0;
char star_password[100];


//////////////////////////////////////////////////////
char bc[20][200]= {"Images\\bgone.bmp","Images/loginpage.bmp","Images/cnapage.bmp","Images/homepage.bmp","Images/ccpage.bmp","Images/announcement_page.bmp","Images/profile.bmp","Images/classwork.bmp","Images/people.bmp","Images/grades.bmp","Images/joinclass.bmp","Images/joinclass_home.bmp"};

bool MusicOn=false;
int gamestate=0;
int cna_substate=0;
int cc_substate=0;
int login_substate=0;
int announcement_substate=0;
int l,i;
int password_matched=1;
int joinclass_substate=0;
////////////////////////////////////////////////////////
void home_mouse(int mx,int my)
{
    if(my>=300 && my<=550 && mx>=200 && mx<=370)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
        gamestate=gameset;      /////////////////////////////////////// 5 for testing..set it to 1

    }
    if(my>=300 && my<=550 && mx>=390 && mx<=550)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
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
    if(login_substate==1)
    {
        iSetColor(0,163,109);
        iFilledRectangle(585,386,309,34);


    }
    if(login_substate==2)
    {
        iSetColor(0,163,109);
        iFilledRectangle(585,348,309,34);

    }

    if(showtext==1)
    {
        iText(100,75,"* PASSWORD MUST BE 8 CHARACTER",GLUT_BITMAP_HELVETICA_18);
        iText(100,100,"* USER NAME MUST BE BETWEEN 10 CHARACTER",GLUT_BITMAP_HELVETICA_18);
    }
    iSetColor(0,0,0);
    iText(592,394,username,GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(592,350,star_password,GLUT_BITMAP_HELVETICA_18);
    if(password_matched==0)
    {
        iSetColor(255,0,0);
        iFilledRectangle(585,348,309,34);
        iSetColor(0,0,0);
        iText(590,357,"*PASSWORD DIDN'T MATCH",GLUT_BITMAP_HELVETICA_18);

    }
}
void login_mouse(int mx,int my)
{
    if(my>=650 && my<=750 && mx>=00 && mx<=120)
    {
        PlaySound("Sounds/back.wav",NULL, SND_ASYNC);
        gamestate=0;

    }
    if(my>=0 && my<=100 && mx>=00 && mx<=120)
    {
        PlaySound("Sounds/back.wav",NULL, SND_ASYNC);
        showtext=1;

    }
    if(mx>=585 && mx<=900 && my>=382 && my<=420)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
        login_substate=1;
    }
    if(mx>=585 && mx<=900 && my>=330 && my<=380)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
        login_substate=2;
    }
}
void cna_mouse(int mx,int my)
{
    if(my>=650 && my<=750 && mx>=00 && mx<=120)
    {
        PlaySound("Sounds/back.wav",NULL, SND_ASYNC);
        gamestate=0;

    }
    if(my>=0 && my<=100 && mx>=00 && mx<=120)
    {
        PlaySound("Sounds/back.wav",NULL, SND_ASYNC);
        showtext=1;

    }
    if(mx>=345 && mx<=600 && my>=520 && my<=560)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
        cna_substate=1;
    }
    if(mx>=345 && mx<=600 && my>=480 && my<=520)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
        cna_substate=2;
    }
    if(mx>=345 && mx<=600 && my>=440 && my<=480)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
        cna_substate=3;
    }
    if(mx>=345 && mx<=600 && my>=400 && my<=440)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
        cna_substate=4;
    }
    if(mx>=345 && mx<=600 && my>=300 && my<=350)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
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
void verify_files(int login_substate,int key)
{
    if(key==13)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
        username[index_username_login]='\0';
        password[index_password_login]='\0';
        //printf("%s %s",username,password);
//////////////////////////// PASSWORD MATCHING ////////////
        int l=0,i=0;
        char line[1000];
        char temp[100];
        char line2[1000];
        char temp2[100];

        for(l=0; fgets(line,1000,username_checker_file); l++)
        {
            l++;
            sscanf(line,"%s",&temp);

            if(strcmp(username,temp)==0)
            {
                printf("%d\n",l);
                break;
            }
        }
        for(i=0; i<8; i++)
        {
            password[i]=password[i]+10;
        }
/////////////////////////////////////////// PENDING WORK //////////////////////
        for(i=1; i<=(l+1)/2; i++)
        {
            fgets(line2,1000,password_checker_file);
            sscanf(line2,"%s",&temp2);
        }
        printf("...\n%s  %s\n",password,temp2);
        if(strcmp(password,temp2)==0)
        {
            printf("PASSWORD MATCHED");
            password_matched=1;
            gamestate=3;
        }
        else
        {
            printf("DOESNT MATCH");
            password_matched=0;
            strcmp(password,'\0');
            strcmp(star_password,'\0');
        }

    }


    if(login_substate==1)
    {


        if (key !='\b')
        {
            PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
            username[index_username_login]=key;
            username[index_username_login+1]='\0';
            index_username_login++;
        }
        else
        {
            if(index_username_login>=0)
            {
                PlaySound("Sounds/back.wav",NULL, SND_ASYNC);
                username[index_username_login-1]='\0';
                index_username_login--;
            }
            else
            {
                index_username_login=0;
            }
        }
    }
    if(login_substate==2)
    {
        if (key !='\b')
        {
            PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
            password[index_password_login]=key;
            star_password[index_password_login]='*';
            password[index_password_login+1]='\0';
            star_password[index_password_login+1]='\0';
            index_password_login++;
        }
        else
        {
            if(index_password_login>=0)
            {
                PlaySound("Sounds/back.wav",NULL, SND_ASYNC);
                star_password[index_password_login-1]='\0';
                password[index_password_login-1]='\0';
                index_password_login--;
            }
            else
            {
                index_password_login=0;
            }
        }
    }
}
void input_files(int cna_substate,int key)
{
    if(key==13)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
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
        gamestate=0;
    }
    if(cna_substate==1)
    {


        if (key !='\b')
        {
            PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
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
            PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
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
            PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
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
            PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
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
            PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
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
void input_in_cc( int cc_substate,int key)
{
    if(key==13)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
        username_input[index_username]='\0';
        fprintf(class_code_file, "%s\n", username_input);
        fclose(class_code_file);
        gamestate=5;

    }
    if(cc_substate==1)
    {


        if (key !='\b')
        {
            PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
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
    if(cc_substate==2)
    {
        if (key !='\b')
        {
            PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
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
    if(cc_substate==3)
    {

        if (key !='\b')
        {
            PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
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
    if(cc_substate==4)
    {


        if (key !='\b')
        {
            PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
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
}
void input_in_announcement(int announement_substate,int key)
{


    if(announcement_substate==1)
    {
        if(key==13)
        {
            showtext=1;

            printf("%s",announcement_input);
            PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
            announcement_input[index_announcement]='\0';
            fprintf(announcement_file, "%s\n",announcement_input);
            fclose(announcement_file);

        }


        if (key !='\b')
        {
            PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
            announcement_input[index_announcement]=key;
            announcement_input[index_announcement+1]='\0';
            index_announcement++;
        }
        else
        {
            if(index_announcement>=0)
            {
                announcement_input[index_announcement-1]='\0';
                index_announcement--;
            }
            else
            {
                index_announcement=0;
            }
        }
    }
}
void profile_homepage()
{
    iShowBMP(0,0,bc[3]);

    if(cc_substate==1)
    {
        iSetColor(0,163,109);
        iFilledRectangle(348,513,309,34);


    }
    if(cc_substate==2)
    {
        iSetColor(0,163,109);
        iFilledRectangle(348,472,309,34);

    }
    if(cc_substate==3)
    {
        iSetColor(0,163,109);
        iFilledRectangle(348,432,309,34);

    }
    if(cc_substate==4)
    {
        iSetColor(0,163,109);
        iFilledRectangle(348,393,309,34);
    }


}
void profile_homepage_mouse(int mx,int my)
{
    if(my>=140 && my<=300 && mx>=120 && mx<=450)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
        gamestate=4;

    }
    if(my>=420 && my<=450 && mx>=800 && mx<=1200)
    {
        PlaySound("Sounds/back.wav",NULL, SND_ASYNC);
        gamestate=6;

    }
    if(my>=140 && my<=300 && mx>=450 && mx<=700)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
        gamestate=10;

    }
}
void ccpage()
{
    showtext=0;
    iShowBMP(0,0,bc[4]);

    if(cc_substate==1)
    {
        iSetColor(0,163,109);
        iFilledRectangle(348,513,309,34);


    }
    if(cc_substate==2)
    {
        iSetColor(0,163,109);
        iFilledRectangle(348,472,309,34);

    }
    if(cc_substate==3)
    {
        iSetColor(0,163,109);
        iFilledRectangle(348,432,309,34);

    }
    if(cc_substate==4)
    {
        iSetColor(0,163,109);
        iFilledRectangle(348,393,309,34);
    }

    iSetColor(0,0,0);
    iText(355,525,username_input,GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(355,487,mobile_input,GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(355,445,institution_input,GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,0);
    iText(355,403,class_input,GLUT_BITMAP_HELVETICA_18);
}
void ccmouse(int mx,int my)
{
    if(my>=650 && my<=750 && mx>=00 && mx<=120)
    {
        PlaySound("Sounds/back.wav",NULL, SND_ASYNC);
        gamestate=3;

    }
    if(mx>=345 && mx<=600 && my>=520 && my<=560)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
        cc_substate=1;
    }
    if(mx>=345 && mx<=600 && my>=480 && my<=520)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
        cc_substate=2;
    }
    if(mx>=345 && mx<=600 && my>=440 && my<=480)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
        cc_substate=3;
    }
    if(mx>=345 && mx<=600 && my>=400 && my<=440)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
        cc_substate=4;
    }
}
void announement_mouse(int mx,int my)
{
    if(my>=50 && my<=700 && mx>=00 && mx<=520)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
        announcement_substate=1;
    }
    if(my>=330 && my<=350 && mx>=1000 && mx<=1200)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
        gamestate=7;
    }
    if(my>=290 && my<=310 && mx>=1000 && mx<=1200)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
        gamestate=8;
    }
    if(my>=230 && my<=290 && mx>=1000 && mx<=1200)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
        gamestate=9;
    }
}
void announcement_page()
{
    iShowBMP(0,0,bc[5]);
    iSetColor(255,255,255);
    iText(100,430,announcement_input,GLUT_BITMAP_HELVETICA_18);
    iSetColor(255,255,255);
    iText(1020,500,username_input,GLUT_BITMAP_HELVETICA_18);
    if(showtext==1)
    {
        iSetColor(0,30,240);
        iFilledRectangle(75,165,110,44);
        iSetColor(255,255,255);
        iText(95,180,"POSTED",GLUT_BITMAP_HELVETICA_18);
    }
}
void profile()
{
    iShowBMP(0,0,bc[6]);
    iSetColor(255,255,255);
    iText(200,517,username,GLUT_BITMAP_HELVETICA_18);
    iSetColor(255,255,255);
    iText(1020,500,username_input,GLUT_BITMAP_HELVETICA_18);
}
void profile_mouse(int mx,int my)
{
    if(my>=650 && my<=750 && mx>=00 && mx<=120)
    {
        PlaySound("Sounds/back.wav",NULL, SND_ASYNC);
        gamestate=3;

    }

}
void classwork()
{
    iShowBMP(0,0,bc[7]);
    iSetColor(255,255,255);
    iText(1020,500,username_input,GLUT_BITMAP_HELVETICA_18);
}
void people()
{
    iShowBMP(0,0,bc[8]);
    iSetColor(255,255,255);
    iText(1020,500,username_input,GLUT_BITMAP_HELVETICA_18);
}
void grades()
{
    iShowBMP(0,0,bc[9]);
    iSetColor(255,255,255);
    iText(1020,500,username_input,GLUT_BITMAP_HELVETICA_18);
}
void student_home()
{
    iShowBMP(0,0,bc[11]);
    iSetColor(255,255,255);

}
void backtoannouncement_mouse(int mx,int my)
{
    if(my>=650 && my<=750 && mx>=00 && mx<=120)
    {
        PlaySound("Sounds/back.wav",NULL, SND_ASYNC);
        gamestate=5;

    }
}
void joinclass()
{
    iShowBMP(0,0,bc[10]);
    iSetColor(255,255,255);
    iText(1020,500,username,GLUT_BITMAP_HELVETICA_18);
    iText(180,350,joinclass_class,GLUT_BITMAP_HELVETICA_18);
}
void joinclass_mouse(int mx,int my)
{
    if(my>=300 && my<=450 && mx>=100 && mx<=300)
    {
        PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
        joinclass_substate=1;
    }
}
void input_in_joinclass(int joinclass_substate,int key)
{
    if(joinclass_substate==1)
    {
        printf("%s\n",joinclass_class);
        if(key==13)
        {
            PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
            joinclass_class[index_joinclass_class]='\0';
            char temp[100];
            char temp2[100];
            for(i=1; i<=10; i++)
            {
                fgets(temp,1000,joinclass_file);
                sscanf(temp,"%s",&temp2);
                if(strcmp(temp2,joinclass_class)==0)
                {
                    printf("class code matched\n");
                    gamestate=11;
                    break;
                }
                else printf("doesnt match\n");
            }
        }
        if (key !='\b')
        {
            PlaySound("Sounds/enter.wav",NULL, SND_ASYNC);
            joinclass_class[index_joinclass_class]=key;
            joinclass_class[index_joinclass_class+1]='\0';
            index_joinclass_class++;
        }
        else
        {
            if(index_joinclass_class>=0)
            {
                joinclass_class[index_joinclass_class-1]='\0';
                index_joinclass_class--;
            }
            else
            {
                index_joinclass_class=0;
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
    if(gamestate==3)
    {
        profile_homepage();
    }
    if(gamestate==4)
    {
        ccpage();
    }
    if(gamestate==5)
    {
        announcement_page();
    }
    if(gamestate==6)
    {
        profile();
    }
    if(gamestate==7)
    {
        classwork();
    }
    if(gamestate==8)
    {
        people();
    }
    if(gamestate==9)
    {
        grades();
    }
    if(gamestate==10)
    {
        joinclass();
    }
    if(gamestate==11)
    {
        student_home();
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
        if(gamestate==3)
        {
            profile_homepage_mouse(mx,my);
        }
        if(gamestate==4)
        {
            ccmouse(mx,my);
        }
        if(gamestate==5)
        {
            announement_mouse(mx,my);
        }
        if(gamestate==6)
        {
            profile_mouse(mx,my);
        }
        if(gamestate==7 || gamestate==8 || gamestate==9)
        {
            backtoannouncement_mouse(mx,my);
        }
        if(gamestate==10)
        {
            joinclass_mouse(mx,my);
        }




    }
}
void iKeyboard(unsigned char key)
{
    if(gamestate==2)
    {
        input_files(cna_substate,key);
    }
    if(gamestate==1)
    {
        verify_files(login_substate,key);
    }
    if(gamestate==4)
    {
        input_in_cc(cc_substate,key);
    }
    if(gamestate==5)
    {
        input_in_announcement(announcement_substate,key);
    }
    if(gamestate==10)
    {
        input_in_joinclass(joinclass_substate,key);
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
    iInitialize(lenth, width, "CLASSROOM");

    return 0;
}
