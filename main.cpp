#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <iterator>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>


using namespace std;
using namespace sf;

string tile[4][4];
string tileTmp[4][4];
int rCount=0,rCount_2=0;
bool isMov = false;
int keyFlag = 0;
bool mov = false;
int sc = 0;


void allOffset(int a);
bool copyTile(bool check);


void iteratorScore(string str)
{
    if(str == "1") sc+=2;
    if(str == "2") sc+=4;
    if(str == "3") sc+=8;
    if(str == "4") sc+=16;
    if(str == "5") sc+=32;
    if(str == "6") sc+=64;
    if(str == "7") sc+=128;
    if(str == "8") sc+=256;
    if(str == "9") sc+=512;
    if(str == "a") sc+=1024;
    if(str == "b") sc+=2048;
}
void score(RenderWindow& window)
{
    int a = 0,b = sc;
    // cout << "\nb=" << b/10;
    char ch[15];
    //itoa(sc,ch,10);
    Font font;
    font.loadFromFile("pack\\fonts\\f.ttf");
    // Text text("Score: ", font);
    Text text2("Your score:", font);
    text2.setColor(Color::Black);
    text2.setPosition(20,10);
    Text text(ch, font);
    text.setCharacterSize(30);
    text.setColor(Color::Green);
    text.setPosition(200,10);
    window.draw(text);
    window.draw(text2);
}
void KeyPressed()
{



}
bool copyTile(bool check = true)
{
    if(check)
    {
        for(int i = 0; i<4; i++)
        {
            for(int j = 0; j<4; j++)
            {
                tileTmp[i][j] = tile[i][j];
            }

        }
    }
    else
    {
        for(int i = 0; i<4; i++)
        {
            for(int j = 0; j<4; j++)
            {
                if(tileTmp[i][j] != tile[i][j])
                    return true;
            }

        }
    }
}
void randomSetNum()
{
    int r = rand()%4;
    int r2 = rand()%4;
    if(tile[r][r2]=="0")
    {
        tile[r][r2] = "1";
    }
    else
    {
        randomSetNum();
    }
}
string findChar(string str)
{
    string allPos[12] = {"0","1","2","3","4","5","6","7","8","9","a","b"};
    for(int i = 0; i<12; i++)
    {
        if(allPos[i] == str)
            return allPos[i+1];
    }
}
void allOffset(int a)
{


    switch(a)
    {
    case 1:
        copyTile();
        for(int i =0; i<4; i++)
        {
            for(int j=1; j<4; j++)
            {
                if(tile[i][j] != "0")
                {
                    int n = 0;
                    while(n<j)
                    {
                        if(tile[i][n] == "0")
                        {
                            tile[i][n] = tile[i][j];
                            tile[i][j] = "0";
                            mov = true;
                            break;

                        }
                        if(tile[i][n] == tile[i][j])
                        {
                            int nn = n+1;
                            bool ms = true;
                            while(nn<j)
                            {
                                if(tile[i][nn] != "0")
                                    ms = false;
                                nn++;
                            }
                            if(ms)
                            {
                                tile[i][n] = findChar(tile[i][j]);
                                tile[i][j] = "0";
                                iteratorScore(tile[i][n]);
                                mov = true;
                                break;
                            }

                        }
                        n++;
                    }
                }

            }
        }
        if(copyTile(false))
        {
            mov = false;
            randomSetNum();
        }

        break;
    case 2:

        copyTile();
        for(int i =0; i<4; i++)
        {
            for(int j=2; j>=0; j--)
            {
                if(tile[i][j] != "0")
                {
                    int n = 3;
                    while(n>j)
                    {
                        if(tile[i][n] == "0")
                        {
                            tile[i][n] = tile[i][j];
                            tile[i][j] = "0";
                            mov = true;
                            break;

                        }
                        if(tile[i][n] == tile[i][j])
                        {
                            int nn = n-1;
                            bool ms = true;
                            while(nn>j)
                            {
                                if(tile[i][nn] != "0")
                                    ms = false;
                                nn--;
                            }
                            if(ms)
                            {
                                tile[i][n] = findChar(tile[i][j]);
                                tile[i][j] = "0";
                                iteratorScore(tile[i][n]);
                                mov = true;
                                break;
                            }

                        }
                        n--;
                    }
                }

            }
        }
        if(copyTile(false))
        {
            mov = false;
            randomSetNum();
        }

        break;
    case 3:

        copyTile();
        for(int i =1; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                if(tile[i][j] != "0")
                {
                    int n = 0;
                    while(n<i)
                    {
                        if(tile[n][j] == "0")
                        {
                            tile[n][j] = tile[i][j];
                            tile[i][j] = "0";
                            mov = true;
                            break;

                        }
                        if(tile[n][j] == tile[i][j])
                        {
                            int nn = n+1;
                            bool ms = true;
                            while(nn<1)
                            {
                                if(tile[nn][j] != "0")
                                    ms = false;
                                nn++;
                            }
                            if(ms)
                            {
                                tile[n][j] = findChar(tile[i][j]);
                                tile[i][j] = "0";
                                iteratorScore(tile[n][j]);
                                mov = true;
                                break;
                            }

                        }
                        n++;
                    }
                }

            }
        }
        if(copyTile(false))
        {
            mov = false;
            randomSetNum();
        }



        break;
    case 4:

        copyTile();
        for(int i =2; i>=0; i--)
        {
            for(int j=0; j<4; j++)
            {
                if(tile[i][j] != "0")
                {
                    int n = 3;
                    while(n>i)
                    {
                        if(tile[n][j] == "0")
                        {
                            tile[n][j] = tile[i][j];
                            tile[i][j] = "0";
                            mov = true;
                            break;

                        }
                        if(tile[n][j] == tile[i][j])
                        {
                            int nn = n-1;
                            bool ms = true;
                            while(nn>i)
                            {
                                if(tile[nn][j] != "0")
                                    ms = false;
                                nn--;
                            }
                            if(ms)
                            {
                                tile[n][j] = findChar(tile[i][j]);
                                tile[i][j] = "0";
                                iteratorScore(tile[n][j]);
                                mov = true;
                                break;
                            }

                        }
                        n--;
                    }
                }

            }
        }
        if(copyTile(false))
        {
            mov = false;
            randomSetNum();
        }
        break;
    }

}
void draw(RenderWindow &window,int number,float posX, float posY,bool asBegin = false)
{
    string str;
    Clock clock;
    float time = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    switch(number)
    {
    case 0:
        str = "pack\\img\\bgn.jpg";
        break;
    case 1:
        str = "pack\\img\\2.jpg";
        break;
    case 2:
        str = "pack\\img\\4.jpg";
        break;
    case 3:
        str = "pack\\img\\8.jpg";
        break;
    case 4:
        str = "pack\\img\\16.jpg";
        break;
    case 5:
        str = "pack\\img\\32.jpg";
        break;
    case 6:
        str = "pack\\img\\64.jpg";
        break;
    case 7:
        str = "pack\\img\\128.jpg";
        break;
    case 8:
        str = "pack\\img\\256.jpg";
        break;
    case 9:
        str = "pack\\img\\512.jpg";
        break;
    case 1024:
        str = "pack\\img\\1024.jpg";
        break;
    case 2048:
        str = "pack\\img\\2048.jpg";
        break;
    }
    Texture texture;
    texture.loadFromFile(str);
    Sprite sprite(texture);
    sprite.setTexture(texture);
    sprite.setPosition(posX,posY);
    window.draw(sprite);
}
void allDrawing(RenderWindow &window)
{
    for(int i = 0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(tile[i][j] == "0")
            {
                draw(window,0,(j+1)*150-134,(i+1)*150-84,true);
            }

            if(tile[i][j] == "1")
                draw(window,1,(j+1)*150-134,(i+1)*150-84);
            if(tile[i][j] == "2")
                draw(window,2,(j+1)*150-134,(i+1)*150-84);
            if(tile[i][j] == "3")
                draw(window,3,(j+1)*150-134,(i+1)*150-84);
            if(tile[i][j] == "4")
                draw(window,4,(j+1)*150-134,(i+1)*150-84);
            if(tile[i][j] == "5")
                draw(window,5,(j+1)*150-134,(i+1)*150-84);
            if(tile[i][j] == "6")
                draw(window,6,(j+1)*150-134,(i+1)*150-84);
            if(tile[i][j] == "7")
                draw(window,7,(j+1)*150-134,(i+1)*150-84);
            if(tile[i][j] == "8")
                draw(window,8,(j+1)*150-134,(i+1)*150-84);
            if(tile[i][j] == "9")
                draw(window,9,(j+1)*150-134,(i+1)*150-84);

            score(window);
        }
    }
}
void setTile()
{
    srand(time(0));
    int rd = rand()%4;
    int rd2 = rand()%4;

    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<4; j++)
        {
            if(rd == i && rd2 == j)
                tile[i][j] += "1";
            else
                tile[i][j] += "0";
        }
    }
    rd = rand()%4;
    rd2 = rand()%4;
    while(true)
    {
        if(tile[rd][rd2] != "1")
        {

            tile[rd][rd2] = "1";
            break;
        }
        else
        {
            rd = rand()%4;
            rd2 = rand()%4;
        }
    }

    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<4; j++)
        {
            cout<<tile[i][j];
        }
        cout<<"\n";
    }
}
void showArray(int **a)
{
    //system("cls");
    for(int i = 0; i<16; i++)
    {

        cout << "\n";
        cout << i << " " << a[i][0] << " "<<a[i][1];


    }
}


int main()
{
    RenderWindow window(VideoMode(600, 650), "2048",Style::Close);
    setTile();
   // window.setIcon(40,40,)
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if(Keyboard::isKeyPressed(Keyboard::Left))
            {
                allOffset(1);
                cout << "1";
            }
            if(Keyboard::isKeyPressed(Keyboard::Right))
            {
                allOffset(2);
                cout << "2";
            }
            if(Keyboard::isKeyPressed(Keyboard::Up))
            {
                allOffset(3);
                cout << "2";
            }
            if(Keyboard::isKeyPressed(Keyboard::Down))
            {
                allOffset(4);
                cout << "2";
            }
        }
        window.clear(Color(137,87,9));
        allDrawing(window);
        window.display();
    }
    return 0;
}
