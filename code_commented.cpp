
#include<ctype.h>
#include<math.h>
#include<stdio.h>
#define M_PI 3.14159265358979323846264338327950288419716939937510
#define false 0
#define true 1
const int BOARD_X = 31;
const int BOARD_Y = 28;
int board_array[BOARD_X][BOARD_Y] =
{{8,5,5,5,5,5,5,5,5,5,5,5,5,1,1,5,5,5,5,5,5,5,5,5,5,5,5,7},
{6,0,0,0,0,0,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,0,0,0,0,0,0,6},
{6,0,8,1,1,7,0,8,1,1,1,7,0,2,4,0,8,1,1,1,7,0,8,1,1,7,0,6},
{6,0,2,11,11,4,0,2,11,11,11,4,0,2,4,0,2,11,11,11,4,0,2,11,11,4,0,6},
{6,0,9,3,3,10, 0,9,3,3,3,10,0,9,10,0,9,3,3,3,10,0,9,3,3,10,0,6},
{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
{6,0,8,1,1,7,0,8,7,0,8,1,1,1,1,1,1,7,0,8,7,0,8,1,1,7,0,6},
{6,0,9,3,3,10,0,2,4,0,9,3,3,11,11,3,3,10,0,2,4,0,9,3,3,10,0,6},
{6,0,0,0,0,0,0,2,4,0,0,0,0,2,4,0,0,0,0,2,4,0,0,0,0,0,0,6},
{9,5,5,5,5,7,0,2,11,1,1,7,0,2,4,0,8,1,1,11,4,0,8,5,5,5,5,10},
{0,0,0,0,0,6,0,2,11,3,3,10,0,9,10,0,9,3,3,11,4,0,6,0,0,0,0,0},
{0,0,0,0,0,6,0,2,4,0,0,0,0,0,0,0,0,0,0,2,4,0,6,0,0,0,0,0},
{0,0,0,0,0,6,0,2,4,0,8,5,5,1,1,5,5,7,0,2,4,0,6,0,0,0,0,0},
{5,5,5,5,5,10,0,9,10,0,6,0,0,0,0,0,0,6,0,9,10,0,9,5,5,5,5,5},
{0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0},
{5,5,5,5,5,7,0,8,7,0,6,0,0,0,0,0,0,6,0,8,7,0,8,5,5,5,5,5},
{0,0,0,0,0,6,0,2,4,0,9,5,5,5,5,5,5,10,0,2,4,0,6,0,0,0,0,0},
{0,0,0,0,0,6,0,2,4,0,0,0,0,0,0,0,0,0,0,2,4,0,6,0,0,0,0,0},
{0,0,0,0,0,6,0,2,4,0,8,1,1,1,1,1,1,7,0,2,4,0,6,0,0,0,0,0},
{8,5,5,5,5,10,0,9,10,0,9,3,3,11,11,3,3,10,0,9,10,0,9,5,5,5,5,7},
{6,0,0,0,0,0,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,0,0,0,0,0,0,6},
{6,0,8,1,1,7,0,8,1,1,1,7,0,2,4,0,8,1,1,1,7,0,8,1,1,7,0,6},
{6,0,9,3,11,4,0,9,3,3,3,10,0,9,10,0,9,3,3,3,10,0,2,11,3,10,0,6},
{6,0,0,0,2,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,4,0,0,0,6},
{2,1,7,0,2,4,0,8,7,0,8,1,1,1,1,1,1,7,0,8,7,0,2,4,0,8,1,4},
{2,3,10,0,9,10,0,2,4,0,9,3,3,11,11,3,3,10,0,2,4,0,9,10,0,9,3,4},
{6,0,0,0,0,0,0,2,4,0,0,0,0,2,4,0,0,0,0,2,4,0,0,0,0,0,0,6},
{6,0,8,1,1,1,1,11,11,1,1,7,0,2,4,0,8,1,1,11,11,1,1,1,1,7,0,6},
{6,0,9,3,3,3,3,3,3,3,3,10,0,9,10,0,9,3,3,3,3,3,3,3,3,10,0,6},
{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
{9,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,10}};
int pebble_array[BOARD_X][BOARD_Y] =
 {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
 {0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0},
 {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
 {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
 {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
 {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
 {0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0},
 {0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0},
 {0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0},
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
 {0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0},
 {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
 {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
 {0,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,0},
 {0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0},
 {0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0},
 {0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0},
 {0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0},
 {0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0},
 {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
GLubyte list[5];
int tp_array[31][28];
int pebbles_left;
double speed1 = 0.1;
double angle1 = 90;
double a=13.5, b=23;
bool animate = false;
int lives=3;
int points=0;
bool open_move[4];
bool gameover = false;
int num_ghosts = 4;
int start_timer=3;
void keys();
void RenderScene();
unsigned char ckey='w';
void mykey(unsigned char key,int x,int y);
bool Open(int a,int b);

//In the Move function, a and b represent Pacman's current position on the game board. speed1 and angle1 appear to control Pacman's movement speed and direction, respectively. The if statements check if the user has pressed the arrow keys for moving Pacman up, down, left, or right, and whether the space in the direction Pacman wants to move is open. If so, animate is set to true, and angle1 is set to the appropriate angle for moving in that direction.

//In the Pac function, Pacman is drawn as a yellow sphere using glutSolidSphere. The glTranslatef calls are used to translate Pacman's position to the appropriate location on the game board. The glPushMatrix and glPopMatrix calls are used to save and restore the current state of OpenGL, allowing different effects to be applied to Pacman without affecting the rest of the scene.

void Move()
{
    a += speed1*cos(M_PI/180*angle1);
    b += speed1*sin(M_PI/180*angle1);
    if(animate&&ckey==GLUT_KEY_UP&& (int) a - a > -0.1 && angle1 != 270) //w
    {
        if (Open(a,b-1)){
            animate = true;
            angle1 = 270;
        }
    }
    else if(animate&&ckey==GLUT_KEY_DOWN&& (int) a - a > -0.1 && angle1 != 90)// s
    {
        if (Open(a,b+1))
        {
            animate = true;
            angle1= 90;
        }
    }
    else if(animate&&ckey==GLUT_KEY_LEFT&& (int) b - b > -0.1 && angle1 != 180)//a
    {
        if (Open(a-1,b))
        {
            animate = true;
            angle1 = 180;
        }
    }
    else if(animate&&ckey==GLUT_KEY_RIGHT&& (int) b - b > -0.1 && angle1 != 0)//d
    {
        if (Open(a+1,b))
        {
            animate = true;
            angle1 = 0;
        }
    }
}
void Pac(void)
{
//Draw Pacman
    glColor3f(1,1,0);
    glPushMatrix();                //tells OpenGL to store the current state that we are in. This then allows us to perform a bunch of different effects
    glTranslatef(a,-b,0);
    glTranslatef(0.5,0.6,0);
    glTranslatef((float)BOARD_X/-2.0f,(float)BOARD_Y/2.0f,0.5);
    glutSolidSphere(0.5,15,10);
    glPopMatrix();                //Then when we want to go back to our previous state, we call glPopMatrix ().
}
//Monster Drawing And Moving Begins
class Ghost
{
    public:
    bool transporting;
    float color[3];
    double speed;
    bool in_jail;
    int jail_timer;
    double angle;
    double x, y;
    Ghost(double, double);
    ~Ghost(void);                            //destructer
    void Move();                            //Move the Monster
    void Update(void);                     //Update Monster State
    void Chase(double, double, bool*);    //Chase Pacman
    bool Catch(double, double);          //collision detection
    void Reinit(void);
    void Draw(void);                   //Draw the Monster
    void game_over(void);
};
Ghost *ghost[4];
Ghost::~Ghost(void){}
Ghost::Ghost(double tx, double ty)
{
    tx = x;
    ty = y;
    angle = 90;
    speed =1;
    color[0] = 1;
    color[1] = 0;
    color[2] = 0;
    in_jail = true;
    jail_timer = 1000;// start timer for 10 sec for them to be inside the jail
}
void Ghost::Reinit(void)
{
    in_jail = true;
    angle = 90;
}
//Move Monster
void Ghost::Move()
{
    x += speed*cos(M_PI/180*angle);
    y += speed*sin(M_PI/180*angle);
}
void Ghost::game_over(){}
void Ghost::Update(void)
{
    if ((int)x == 0 && (int) y == 14 && (!(transporting)))
    {
        angle=180;
    }
    if (x < 0.1 && (int) y == 14)
    {
        x = 26.9;
        transporting = true;
    }
    if ((int)x == 27 && (int) y == 14 && (!(transporting)))
    {
        angle=0;
    }
    if (x > 26.9 && (int) y == 14)
    {
        x = 0.1;
        transporting = true;
    }
    //Where to go after coming out of jail
    if (in_jail && (int) (y+0.9) == 11)
    {
        in_jail = false;
        angle = 0;
    }
    if (in_jail && ((int)x == 13 || (int)x == 14))
    {
        angle = 270;
    }
    //if time in jail is up, position for exit
    if (jail_timer == 0 && in_jail)
    {
        //move right to exit
        if (x < 13)
            angle = 0;
        if (x > 14)
            angle = 180;
    }
    //decrement time in jail counter
    if (jail_timer > 0)
        jail_timer--;
}
//This is a member function of the Ghost class, which returns a boolean value indicating whether the ghost has caught the player or not.
//
//The function takes in two double parameters px and py, which represent the current position of the player.
//
//The function then checks if the distance between the ghost's current position (x,y) and the player's current position (px,py) is less than 0.2 in both the x and y directions. If the distance is less than 0.2 in both directions, it means that the player is close enough to the ghost for the ghost to catch them. In that case, the function returns true, indicating that the ghost has caught the player.
//
//If the distance is greater than or equal to 0.2 in either direction, the function returns false, indicating that the ghost has not caught the player.
bool Ghost::Catch(double px, double py)
{// Collision Detection
    if (px - x < 0.2 && px - x > -0.2 && py - y < 0.2 && py - y > -0.2)
    {
        return true;
    }
    return false;
}
void Ghost::Chase(double px, double py, bool *open_move)
{
    int c=1;
    bool moved = false;
    //if pac is close and below then change direction
    if ((int) angle == 0 || (int) angle == 180)
    {
        if ((int)c*py > (int)c*y && open_move[1])
            angle = 90;
        else if ((int)c*py < (int)c*y && open_move[3])
            angle = 270;
    }//upar wala ka dusra case
    else if ((int) angle == 90 || (int) angle == 270)
    {
        if ((int)c*px > (int)c*x && open_move[0])
            angle = 0;
        else if ((int)c*px < (int)c*x && open_move[2])
            angle = 180;
    }
    //Random Moves Of Monsters if pac isnt close
    if ((int) angle == 0 && !open_move[0])
        angle = 90;
    if ((int) angle == 90 && !open_move[1])
        angle = 180;
    if ((int) angle == 180 && !open_move[2])
        angle = 270;
    if ((int) angle == 270 && !open_move[3])
        angle = 0;
    if ((int) angle == 0 && !open_move[0])
        angle = 90;
}
void Ghost::Draw(void)
{
    glColor3f(color[0],color[1],color[2]);
    glPushMatrix();
    glTranslatef(x,-y,0);
    glTranslatef(0.5,0.6,0);
    glTranslatef((float)BOARD_X/-2.0f, (float)BOARD_Y/2.0f,0.5);
    glutSolidSphere(.5,10,10);
    glPopMatrix();
}
void tp_restore(void)
{
    for (int ISO = 0; ISO < BOARD_X; ISO++)
    {
        for (int j = 0; j < BOARD_Y; j++)
        {
            tp_array[ISO][j] = pebble_array[ISO][j];
        }
    }
    pebbles_left = 244;
}
void Draw(void)
{
//split board drawing in half to avoid issues with depth
    for (int ISO = 0; ISO < BOARD_X; ISO++)
    {
        for (int j = 0; j < BOARD_Y/2; j++)
        {
            int call_this = 0;
            glPushMatrix();
            glTranslatef(-(float) BOARD_X / 2.0f,-(float) BOARD_Y / 2.0f, 0);
            glTranslatef(j, BOARD_Y - ISO,0);
            glPushMatrix();
            glTranslatef(0.5,0.5,0);
            switch (board_array[ISO][j])
            {
                case 4:
                    glRotatef(90.0,0,0,1);
                case 3:
                    glRotatef(90.0,0,0,1);
                case 2:
                    glRotatef(90.0,0,0,1);
                case 1:
                    call_this = 1;
                    break;
                case 6:
                    glRotatef(90.0,0,0,1);
                case 5:
                    call_this = 2;
                    break;
                case 10:
                    glRotatef(90.0,0,0,1);
                case 9:
                    glRotatef(90.0,0,0,1);
                case 8:
                    glRotatef(90.0,0,0,1);
                case 7:
                    call_this = 3;
                    break;
            }
            glScalef(1,1,0.5);
            glTranslatef(-0.5,-0.5,0);
            glCallList(list[call_this]);
            glPopMatrix();
            //now put on the top of the cell
            if (call_this != 0 || board_array[ISO][j] == 11)
            {
                glTranslatef(0,0,-0.5);
                glCallList(list[4]);
            }
            glPopMatrix();
            if (tp_array[ISO][j] > 0)
            {
//                ye color dots ka hai
                glColor3f(0,300,1/(float)tp_array[ISO][j]);
                glPushMatrix();
                glTranslatef(-(float) BOARD_X / 2.0f,-(float) BOARD_Y / 2.0f, 0);
                glTranslatef(j, BOARD_Y - ISO,0);
                glTranslatef(0.5,0.5,0.5);
                glutSolidSphere(0.1f*((float)tp_array[ISO][j]),6,6);
                glPopMatrix();
            }
        }
    }
    int ISO;
    for (ISO= 0; ISO< BOARD_X; ISO++)
    {
        for (int j = BOARD_Y-1; j >= BOARD_Y/2; j--)
        {
            glColor3f(0,0.1,1);
            int call_this = 0;
            glPushMatrix();
            glTranslatef(-(float) BOARD_X / 2.0f,-(float) BOARD_Y / 2.0f, 0);
            glTranslatef(j, BOARD_Y - ISO,0);
            glPushMatrix();
            glTranslatef(0.5,0.5,0);
            switch (board_array[ISO][j])
            {
                case 4:
                    glRotatef(90.0,0,0,1);
                case 3:
                    glRotatef(90.0,0,0,1);
                case 2:
                    glRotatef(90.0,0,0,1);
                case 1:
                    call_this = 1;
                    break;
                case 6:
                    glRotatef(90.0,0,0,1);
                case 5:
                    call_this = 2;
                    break;
                case 10:
                    glRotatef(90.0,0,0,1);
                case 9:
                    glRotatef(90.0,0,0,1);
                case 8:
                    glRotatef(90.0,0,0,1);
                case 7:
                    call_this = 3;
                    break;
            }
            glScalef(1,1,0.5);
            glTranslatef(-0.5,-0.5,0);
            glCallList(list[call_this]);
            glPopMatrix();
            //now put on top
            if (call_this != 0 || board_array[ISO][j] == 11)
            {
                glTranslatef(0,0,-0.5);
                glCallList(list[4]);
            }
            glPopMatrix();
            if (tp_array[ISO][j] > 0)
            {
                glColor3f(0,300,1/(float)tp_array[ISO][j]);
                glPushMatrix();
                glTranslatef(-(float) BOARD_X / 2.0f,-(float) BOARD_Y / 2.0f, 0);
                glTranslatef(j, BOARD_Y - ISO,0);
                glTranslatef(0.5,0.5,0.5);
                glutSolidSphere(0.1f*((float)tp_array[ISO][j]),6,6);
                glPopMatrix();
            }
        }
    }
    Pac();
}
bool Open(int a, int b)
{
    if (board_array[b][a] > 0){
        return false;
    }
    return true;
}

void mykey(unsigned char key,int x,int y)
{
    if (start_timer > 0)
    {
        start_timer--;
    }
}
//specialDown(int key,int x,int y): This function is called when a special key (such as the arrow keys) is pressed. The parameters key, x, and y represent the key code, the x and y coordinates of the mouse at the time of the event.
//Within this function, the code first checks if start_timer is greater than 0, and if so, it decrements start_timer by 1. The variables a and b likely represent the current position of Pac-Man on the game board. The code then updates the value of ckey to the current key code.
//
//The function then checks which arrow key was pressed and whether the Pac-Man character can move in that direction. If the conditions are met, the animate flag is set to true and the angle1 variable is set to the appropriate angle (270 for up, 90 for down, 180 for left, and 0 for right).
//
//P_Reinit(): This function reinitializes Pac-Man's position and direction. It sets the values of a and b to 13.5 and 23 respectively, angle1 to 90, and animate to false. The Pac() function is likely called to redraw the Pac-Man character on the game board.
void specialDown(int key,int x,int y)
{
    if (start_timer > 0)
        start_timer--;
    ckey=key;
    //The expression (int) a - a > -0.1 checks if the difference between a and (int)a (the integer part of a) is greater than -0.1. If this condition is true, it means that Pac-Man is not exactly at an integer position in the vertical direction, and hence can move up by at least one unit.
    if(key==GLUT_KEY_UP&& (int) a - a > -0.1 && angle1 != 270) //w
    {
        if (Open(a, b - 1))//The function Open(a, b - 1) likely checks if the position one unit above Pac-Man's current position (i.e., at (a, b - 1)) is open for Pac-Man to move into. If this function returns true, it means that Pac-Man can move up one unit.
        {
            animate = true;
            angle1 = 270;
        }
    }
    else if(key==GLUT_KEY_DOWN&& (int) a - a > -0.1 && angle1 != 90)// s
    {
        if (Open(a,b + 1))
        {
            animate = true;
            angle1= 90;
        }
    }
    else if(key==GLUT_KEY_LEFT&& (int) b - b > -0.1 && angle1 != 180)//a
    {
        if (Open(a-1,b))
        {
            animate = true;
            angle1 = 180;
        }
    }
    else if(key==GLUT_KEY_RIGHT&& (int) b - b > -0.1 && angle1 != 0)//d
    {
        if (Open(a+1, b))
        {
            animate = true;
            angle1 = 0;
        }
    }
}
void P_Reinit()
{
    a = 13.5;
    b = 23;
    angle1 = 90;
    animate = false;
    Pac();
}
void G_Reinit(void)
{
    start_timer = 3;
    //ghost initial starting positions
    int start_x[4] = {11,12,15,16};
    float ghost_colors[4][3] = {{255,0,0},{120,240,120},{255,200,200},{255,125,0}};
    for (int i = 0; i < num_ghosts; i++)
    {
        ghost[i]->Reinit();
        ghost[i]->x = start_x[i];
        ghost[i]->y = 14;
        ghost[i]->jail_timer = i*33 + 66;
        ghost[i]->speed = 0.1 - 0.01*(float)i;
        //colorize ghosts
        for (int j = 0; j < 3; j++)
            ghost[i]->color[j] = ghost_colors[i][j]/255.0f;
    }
}
void Write(char *string)
{
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *string++);
}
//Display Function->This Function Is Registered in glutDisplayFunc
void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //Through Movement->From One End To The Other
    if ((int)a == 27 && (int) b == 14 && angle1 == 0)                 //go outside of box
    {
        a = 0;
        animate = true;
    }
    else if ((int)(a + 0.9) == 0 && (int) b == 14 && angle1 == 180)  //collide with the ghost inside the box where all ghost are present
    {
        a = 27;
    animate = true;
    }
    //Collision Detection For PacMan
    if (animate)
        Move();
    if(!(Open((int)(a + cos(M_PI/180*angle1)),(int)(b + sin(M_PI/180*angle1)))) && a - (int)a < 0.1 && b - (int)b < 0.1)
        animate = false;
    if (tp_array[(int)(b+0.5)][(int)(a+0.5)]== 1)    //to calculate no of pebbles eaten
    {
        tp_array[(int)(b+0.5)][(int)(a+0.5)]= 0;
        pebbles_left--;
        points+=1;
    }
    if (pebbles_left == 0)
    {
        G_Reinit();
        P_Reinit();
        tp_restore();
        points=0;
        lives=3;
    }
    if (!gameover)
        Draw();
    for (int d = 0; d < num_ghosts; d++)
    {
        if (!gameover && start_timer == 0)
            ghost[d]->Update();
        if (!ghost[d]->in_jail && ghost[d]->x - (int)ghost[d]->x < 0.1 && ghost[d]->y - (int)ghost[d]->y < 0.1)
        {
            bool open_move[4];
            //Finding Moves
            for (int ang = 0; ang < 4; ang++)
            {
                open_move[ang] = Open((int)(ghost[d]->x + cos(M_PI/180*ang*90)),(int)(ghost[d]->y + sin(M_PI/180*ang*90)));
            }
            //Chase Pac Man
            if(ghost[d]->x - (int)ghost[d]->x < 0.1 && ghost[d]->y - (int)ghost[d]->y < 0.1)
                ghost[d]->Chase(a, b, open_move);
        }
        if (ghost[d]->in_jail && !(Open((int)(ghost[d]->x + cos(M_PI/180*ghost[d]->angle)),(int)(ghost[d]->y + sin(M_PI/180*ghost[d]->angle)))) && ghost[d]->jail_timer > 0 && ghost[d]->x - (int)ghost[d]->x < 0.1 && ghost[d]->y - (int)ghost[d]->y < 0.1)
        {
            ghost[d]->angle = (double)(((int)ghost[d]->angle + 180)%360);
        }
        if (!gameover && start_timer == 0)
            ghost[d]->Move();
        ghost[d]->Draw();
        bool collide = ghost[d]->Catch(a,b);
        //Monster Eats PacMan
        if (collide)
        {
            lives--;
            if (lives == 0)
            {
                gameover = true;
                lives=0;
                ghost[d]->game_over();
            }
            P_Reinit();
            d = 4;
        }
    }
    char tmp_str[40];
    if(gameover==true)
    {
        glColor3f(1,0,1);
        glColor3f(1,0,0);
        glRasterPos2f(-5, 0.5);
        sprintf(tmp_str, "Game Over");
        Write(tmp_str);
    }
    glColor3f(1, 1, 0);
    glRasterPos2f(10, 18);
    sprintf(tmp_str, "Points: %d", points);
    Write(tmp_str);
    glColor3f(1, 0, 1);
    glRasterPos2f(-5, 18);
    sprintf(tmp_str, "PAC MAN");
    Write(tmp_str);
    glColor3f(1, 1, 0);
    glRasterPos2f(-12, 18);
    if(lives<0)
    {
        lives=0;
    }
    sprintf(tmp_str, "Lives: %d", lives);
    Write(tmp_str);
    glutPostRedisplay();                    //glutPostRedisplay may be called within a window's display
    glutSwapBuffers();                      //Performs a buffer swap on the layer in use for the current window
}
//creating boundary walls and their colors -> blue lines (3 types of boxes are there )
void create_list_lib()
{
    //Set Up Maze Using Lists
    list[1] = glGenLists(1);
    glNewList(list[1], GL_COMPILE);   //relation between int type and drawing
    //North Wall
    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 1.0, 1.0);
    glEnd();
    glEndList();
    list[2] = glGenLists(1);
    glNewList(list[2], GL_COMPILE);
    glBegin(GL_QUADS);
    //North Wall
    glColor3f(0,0,1);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 1.0, 1.0);
    //South Wall
    glColor3f(0,0,1);
    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(1.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glEnd();
    glEndList();
    list[3] = glGenLists(1);
    glNewList(list[3], GL_COMPILE);
    glBegin(GL_QUADS);
    //North Wall
    glColor3f(0,0,1);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 1.0, 1.0);
    //East Wall
    glColor3f(0,0,1);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 0.0, 1.0);
    glVertex3f(1.0, 0.0, 0.0);
    glEnd();
    glEndList();
    list[4] = glGenLists(1);
    glNewList(list[4], GL_COMPILE);
    glBegin(GL_QUADS);
    //Top Wall
    glColor3f(-1,0.3,0);
    glVertex3f(1, 1, 1.0);
    glVertex3f(0, 1, 1.0);
    glVertex3f(0, 0, 1.0);
    glVertex3f(1, 0, 1.0);
    glEnd();
    glEndList();
}
//initializing the prespective code till gl-model_view,gluPerspective(60,1.33,0.005,100);  sets up how we get to view the plane
void init()
{
    glEnable(GL_NORMALIZE);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();                        //Reset the co-ordinate system             field of view in degree
    gluPerspective(60,1.33,0.005,100);       //set up a perspective projection matrix : fovy,aspect,znear,zfar
    glMatrixMode(GL_MODELVIEW);              //For transformation
    glLoadIdentity();
    gluLookAt(-1.5, 0, 40, -1.5, 0, 0, 0.0f,1.0f,0.0f);  // //define a viewing transformation
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize(1200, 780);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Computer Graphics Lab Eval -> Pac man game");
    init();
    create_list_lib();
    glutKeyboardFunc(mykey); // setting a timer of pressing 3 keys (any)
    glutSpecialFunc(specialDown);
    glutDisplayFunc(RenderScene);  // op function -> resets and animates
    glEnable(GL_DEPTH_TEST);
    // Set the background color to blue
//        glClearColor(.92f, 0.98f, 0.89f, 0.02f);
    int start_x[4] = {11,12,15,16};
    for(int ISO = 0; ISO < num_ghosts; ISO++)
    {
        ghost[ISO] = new Ghost(start_x[ISO],14);
    }
    //new instances of ghost
    float ghost_colors[4][3] = {{255,0,0},{120,240,120},{255,200,200},{255,125,0}};
    for (int ISO = 0; ISO < num_ghosts; ISO++)
    {
        ghost[ISO]->x = start_x[ISO];
        ghost[ISO]->y = 14;
        ghost[ISO]->speed = 0.1 - 0.01*(float)ISO;
        //colorize ghosts
        for (int j = 0; j < 3; j++)
        ghost[ISO]->color[j] = ghost_colors[ISO][j]/255.0f;
    }
    //tp_array==pebble_array
    for (int ISO = 0; ISO < BOARD_X; ISO++)
    {
        for (int j = 0; j < BOARD_Y; j++)
        {
            tp_array[ISO][j] = pebble_array[ISO][j];
        }
    }
    pebbles_left = 244;
    glutMainLoop();
    return 0;
}
