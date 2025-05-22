#include "iGraphics.h"
#include <math.h>
#include <time.h>

double o, x = 256, y = 256 + 206, sx, sy, p;
double xm = 256, ym = 256 + 176, mx, my, pm;
double xh = 256, yh = 256 + 156, hx, hy, ph, H, M, S;
int i;

void drawHomePage();
void drawStartPage();
void drawTimePage();
void drawRulesPage();
void drawAboutPage();
void drawRules1Page();
void drawRules2Page();
void drawRules3Page();

void startButtonClick();
void timeButtonClick();
void rulesbuttonClick();
void aboutButtonClick();
void rules1buttonClick();
void rules2buttonClick();
void rules3buttonClick();
void backBUttonClick();
void back1BUttonClick();

int startButton = 0;
int timeButton = 0;
int rulesButton = 0;
int aboutButton = 0;

int homepage = 1;
int startpage = 0;
int timepage = 0;
int rulespage = 0;
int aboutpage = 0;
int rules1page = 0;
int rules2page = 0;
int rules3page = 0;

// int x = 300, y = 300, r = 20;
/*
    function iDraw() is called again and again by the system.

    */

void iDraw()
{
    // place your drawing codes here
    iClear();

    if (homepage == 1)
    {
        drawHomePage();
    }
    else if (startpage == 1)
    {
        drawStartPage();
    }
    else if (timepage == 1)
    {
        drawTimePage();
    }
    else if (rulespage == 1)
    {
        drawRulesPage();
    }
    else if (aboutpage == 1)
    {
        drawAboutPage();
    }

    else if (rules1page == 1)
    {
        drawRules1Page();
    }
    else if (rules2page == 1)
    {
        drawRules2Page();
    }
    else if (rules3page == 1)
    {
        drawRules3Page();
    }
}

/*
    function iMouseMove() is called when the user presses and drags the mouse.
    (mx, my) is the position where the mouse pointer is.
    */
void iMouseMove(int nx, int ny)
{
    printf("x = %d, y= %d\n", nx, ny);
    // place your codes here

    //  else if (rulespage = 1 && (nx > 0 && nx < 512) && (ny > 362 && ny < 412))
    //  {
    //      rules1buttonClick();
    //  }

    if ((rules1page == 1 | rules2page == 1 | rules3page == 1) && (nx > 0 && nx < 128) && (ny >= 462 && ny <= 512))
    {
        back1BUttonClick();
    }
}

/*
    function iMouse() is called when the user presses/releases the mouse.
    (mx, my) is the position where the mouse pointer is.
    */
void iMouse(int button, int state, int nx, int ny)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        // place your codes here
        // printf("x = %d, y= %d\n", mx, my);
        // x += 10;
        // y += 10;

        if (homepage == 1 && (nx > 0 && nx < 128) && (ny >= 10 && ny <= 60))
        {
            startButtonClick();
        }
        else if (homepage == 1 && (nx > 128 && nx < 256) && (ny >= 10 && ny <= 60))
        {
            timeButtonClick();
        }
        else if (homepage == 1 && (nx > 256 && nx < 384) && (ny >= 10 && ny <= 60))
        {
            rulesbuttonClick();
        }
        else if (homepage == 1 && (nx > 384 && nx < 512) && (ny >= 10 && ny <= 60))
        {
            aboutButtonClick();
        }
        else if ((startpage == 1 | timepage == 1 | rulespage == 1 | aboutpage == 1) && (nx > 0 && nx < 128) && (ny >= 462 && ny <= 512))
        {
            backBUttonClick();
        }
        else if (rulespage = 1 && (nx > 0 && nx < 512) && (ny > 362 && ny < 412))
        {
            rules1buttonClick();
        }
        else if (rulespage = 1 && (nx > 0 && nx < 512) && (ny > 292 && ny < 342))
        {
            rules2buttonClick();
        }
        else if (rulespage = 1 && (nx > 0 && nx < 512) && (ny > 222 && ny < 272))
        {
            rules3buttonClick();
        }
    }

    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        // place your codes here
        // x -= 10;
        // y -= 10;
    }
}

/*
    function iKeyboard() is called whenever the user hits a key in keyboard.
    key- holds the ASCII value of the key pressed.
    */
void iKeyboard(unsigned char key)
{
    if (key == 'q')
    {
        exit(0);
    }
    // place your codes for other keys here
}

/*
    function iSpecialKeyboard() is called whenver user hits special keys like-
    function keys, home, end, pg up, pg down, arraows etc. you have to use
    appropriate constants to detect them. A list is:
    GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
    GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
    GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
    GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
    */
void iSpecialKeyboard(unsigned char key)
{

    if (key == GLUT_KEY_END)
    {
        exit(0);
    }
    // place your codes for other keys here
}
void second()

{
    sx = 206 * cos(p / 57.29);
    sy = 206 * sin(p / 57.29);
    x = 256 + sx;
    y = 256 + sy;
    p = p - 6;
}
void minute()
{
    mx = 176 * cos(pm / 57.29);
    my = 176 * sin(pm / 57.29);
    xm = 256 + mx;
    ym = 256 + my;
    pm = pm - .1;
}
void hour()
{
    hx = 156 * cos(ph / 57.29);
    hy = 156 * sin(ph / 57.29);
    xh = 256 + hx;
    yh = 256 + hy;
    ph = ph - 1 / 600;
}

void drawHomePage()
{
    iSetColor(128, 128, 128);
    iFilledRectangle(0, 0, 512, 512);
    iShowBMP2(0, 0, "image\\Muslim-Day.bmp", 0);
    iShowBMP2(0, 10, "image\\button-_1_.bmp", 0);
    iShowBMP2(128, 10, "image\\button-_1_.bmp", 0);
    iShowBMP2(256, 10, "image\\button-_1_.bmp", 0);
    iShowBMP2(384, 10, "image\\button-_1_.bmp", 0);

    iSetColor(0, 255, 0);
    iText(40, 28, "Clock", GLUT_BITMAP_HELVETICA_18);
    iText(158, 28, "Prayer Time", GLUT_BITMAP_HELVETICA_12);
    iText(276, 28, "Rules of Prayer", GLUT_BITMAP_HELVETICA_12);
    iText(424, 28, "About", GLUT_BITMAP_HELVETICA_18);
}
void drawStartPage()
{
    iSetColor(10, 10, 10);
    iFilledCircle(256, 256, 200); // Large

    iSetColor(0, 255, 0);
    iCircle(256, 256, 205); // out
    iSetColor(0, 0, 255);
    iCircle(256, 256, 185); // nextout
    iSetColor(255, 0, 0);
    for (i = 1, o = (6 / 57.29); i <= 60; i++, o += (6 / 57.29))
    {
        if (i % 5 != 0)
            iFilledCircle(256 + 195 * cos(o), 256 + 195 * sin(o), 4);
        if (i % 5 == 0)
            iFilledCircle(0, 0, 0);
    }

    iSetColor(255, 0, 0);
    iLine(256, 256, x, y); /// second
    iSetColor(0, 120, 120);
    iLine(256, 256, xm, ym); /// minit
    iSetColor(20, 200, 40);
    iLine(256, 256, xh, yh); // HR
    iSetColor(255, 0, 0);
    iText(251, 55, "6", GLUT_BITMAP_HELVETICA_18);
    iText(56, 250, "9", GLUT_BITMAP_HELVETICA_18);
    iText(445, 250, "3", GLUT_BITMAP_HELVETICA_18);
    iText(245, 445, "12", GLUT_BITMAP_HELVETICA_18);

    iSetColor(20, 50, 210);
    iFilledCircle(256, 256, 20); // small

    iShowBMP2(0, 462, "image\\button-_1_.bmp", 0);
    iSetColor(0, 255, 0);
    iText(45, 480, "Back", GLUT_BITMAP_HELVETICA_18);
}
void drawTimePage()
{
    iSetColor(255, 255, 255);
    iFilledRectangle(0, 0, 512, 512);

    // iShowBMP2(0, 0, "image\\Prayer-Times-in-Bengali-_1_.bmp", 0);

    iSetColor(200, 200, 200);
    iFilledRectangle(0, 250, 512, 200);

    iSetColor(20, 200, 0);
    iText(50, 420, "Fajar Prayer Time ---   05:05 AM", GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(20, 200, 0);
    iText(50, 380, "Dhuhur Prayer Time ---  12:11 PM", GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(20, 200, 0);
    iText(50, 340, "Asr Prayer Time  ---    03:31 PM", GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(20, 200, 0);
    iText(50, 300, "Maghrib Prayer Time ---  06:02 PM", GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(20, 200, 0);
    iText(50, 260, "Isha Prayer Time ---    07:18 PM", GLUT_BITMAP_TIMES_ROMAN_24);

    iSetColor(200, 200, 200);
    iFilledRectangle(0, 50, 512, 155);

    iSetColor(20, 200, 0);
    iText(50, 180, "The Forbidden Prayer Times", GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(20, 200, 0);
    iText(50, 140, "Bhor : 6:16 - 6:31 AM  ", GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(20, 200, 0);
    iText(50, 100, "Dhupur : 12:06 - 12:13 PM  ", GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(20, 200, 0);
    iText(50, 60, "Sondha : 5:48 - 6:03 PM  ", GLUT_BITMAP_TIMES_ROMAN_24);

    iShowBMP2(0, 462, "image\\button-_1_.bmp", 0);
    iSetColor(0, 255, 0);
    iText(45, 480, "Back", GLUT_BITMAP_HELVETICA_18);
}

void drawRulesPage()
{
    iSetColor(255, 255, 255);
    iFilledRectangle(0, 0, 512, 512);
    iShowBMP2(0, 362, "image\\360_F_638282823_MzZXu0oFqwBsazulhUhogz8Ay2qjnDpF_512x50.bmp", 0);
    iShowBMP2(0, 362, "image\\Screenshot_2024-02-23_193917_512x50.bmp", 0);
    iShowBMP2(0, 292, "image\\360_F_638282823_MzZXu0oFqwBsazulhUhogz8Ay2qjnDpF_512x50.bmp", 0);
    iShowBMP2(35, 302, "image\\Screenshot_2024-02-23_200155_2_50.bmp", 0);
    iShowBMP2(0, 222, "image\\360_F_638282823_MzZXu0oFqwBsazulhUhogz8Ay2qjnDpF_512x50.bmp", 0);
    iShowBMP2(40, 232, "image\\Screenshot_2024-02-25_220928_50.bmp", 0);

    iShowBMP2(0, 462, "image\\button-_1_.bmp", 0);
    iSetColor(0, 255, 0);
    iText(45, 480, "Back", GLUT_BITMAP_HELVETICA_18);
}

void drawAboutPage()
{
    iSetColor(255,255,255);
    iFilledRectangle(0, 0, 512, 512);

    iShowBMP2(0,200,"image\\Screenshot-2024-03-05-011437.bmp",0);

    iShowBMP2(0, 462, "image\\button-_1_.bmp", 0);
    iSetColor(0, 255, 0);
    iText(45, 480, "Back", GLUT_BITMAP_HELVETICA_18);
}

void drawRules1Page()
{
    iSetColor(255, 255, 255);
    iFilledRectangle(0, 0, 512, 512);

    iShowBMP2(0, 412, "image\\Screenshot_2024-02-23_193917_512x50.bmp", 0);
    iShowBMP2(0, 45, "image\\Screenshot-2024-02-23-193837.bmp", 0);

    iShowBMP2(0, 462, "image\\button-_1_.bmp", 0);
    iSetColor(0, 255, 0);
    iText(45, 480, "Back", GLUT_BITMAP_HELVETICA_18);
}
void drawRules2Page()
{
    iSetColor(255, 255, 255);
    iFilledRectangle(0, 0, 512, 512);

    iShowBMP2(35, 432, "image\\Screenshot_2024-02-23_200155_2_50.bmp", 0);
    iShowBMP2(0, 190, "image\\Screenshot 2024-02-26 221036.bmp", 0);

    iShowBMP2(0, 462, "image\\button-_1_.bmp", 0);
    iSetColor(0, 255, 0);
    iText(45, 480, "Back", GLUT_BITMAP_HELVETICA_18);
}
void drawRules3Page()
{
    iSetColor(255, 255, 255);
    iFilledRectangle(0, 0, 512, 512);

    iShowBMP2(0, 200, "image\\Screenshot-2024-02-23-194456.bmp", 0);
    iShowBMP2(0, 0, "image\\Screenshot-2024-02-23-194514.bmp", 0);

    iShowBMP2(0, 462, "image\\button-_1_.bmp", 0);
    iSetColor(0, 255, 0);
    iText(45, 480, "Back", GLUT_BITMAP_HELVETICA_18);
}
void startButtonClick()
{
    homepage = 0;
    startpage = 1;
}
void timeButtonClick()
{
    homepage = 0;
    startpage = 0;
    timepage = 1;
}
void rulesbuttonClick()
{
    homepage = 0;
    startpage = 0;
    timepage = 0;
    rulespage = 1;
}
void aboutButtonClick()
{
    homepage = 0;
    startpage = 0;
    timepage = 0;
    rulespage = 0;
    aboutpage = 1;
}
void rules1buttonClick()
{
    homepage = 0;
    startpage = 0;
    timepage = 0;
    rulespage = 0;
    aboutpage = 0;
    rules1page = 1;
}
void rules2buttonClick()
{
    homepage = 0;
    startpage = 0;
    timepage = 0;
    rulespage = 0;
    aboutpage = 0;
    rules1page = 0;
    rules2page = 1;
}
void rules3buttonClick()
{
    homepage = 0;
    startpage = 0;
    timepage = 0;
    rulespage = 0;
    aboutpage = 0;
    rules1page = 0;
    rules2page = 0;
    rules3page = 1;
}
void backBUttonClick()
{
    homepage = 1;
    startpage = 0;
    timepage = 0;
    rulespage = 0;
    aboutpage = 0;
}
void back1BUttonClick()
{
    rulespage = 1;
    rules1page = 0;
    rules2page = 0;
    rules3page = 0;
}

int main()
{
    time_t rawtime;
    tm *ptm;

    time(&rawtime);

    ptm = gmtime(&rawtime); // getting time from bios

    H = (ptm->tm_hour + 6) % 24;
    M = ptm->tm_min;
    S = (ptm->tm_sec) + 2;

    ph = (3 - H) * 30.0 - 30 * M / 60.0 - 30 * S / 3600.0 + .1 / 600 + 270 + 90;

    pm = (15 - M) * 6.0 - S / 60.0 + .1 + 270 + 90;

    p = (15 - S) * 6.0 + 6 + 270 + 90;

    second();
    minute();
    hour();

    iSetTimer(1000, second);
    iSetTimer(1000, minute);
    iSetTimer(1000, hour);

    // place your own initialization codes here.
    iInitialize(512, 512, "Muslims Day");
    return 0;
}
