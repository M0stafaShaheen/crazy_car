#include <SFML/Graphics.hpp>
#include<bits/stdc++.h>


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "crazy car");
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(true);

    sf::Event event;

    // variables

    bool play = true ;
    int xcar1 = 0 ;
    bool space = false ;
    bool enter = false ;
    bool left = false ;
    bool right = false ;
    bool crashblock = false ;
    bool crashcoin = false ;
    bool f2 = false ;
    bool f1 = false ;
    int xcar2 = 0 ;
    int ycar2 = 0 ;
    int yroad1 = 0 ;
    int yroad2 = 0 ;
    int yblock1 = 200 ;
    int yblock2 = 0 ;
    int ycoin = 0 ;
    int x = 0 ;
    int x2 = 0;
    int x3 = 0 ;
    int countcoin = 0 ;

    // font
    sf::Font font;
    font.loadFromFile("data/arial.ttf") ;

    // --------------------
    // text

    sf::Text text1;
    text1.setFont(font) ;
    text1.setString("CRAZY CAR....") ;
    text1.setCharacterSize(40) ;
    text1.setFillColor(sf::Color::Blue) ;
    text1.setPosition(250,250);

    sf::Text text2;
    text2.setFont(font) ;
    text2.setCharacterSize(20);
    text2.setString("START") ;
    text2.setPosition(370,220);
    text2.setFillColor(sf::Color::White);
    text2.setStyle(sf::Text::Bold) ;
    text2.setOutlineThickness(3);
    text2.setOutlineColor(sf::Color::Red) ;

    sf::Text text3;
    text3.setFont(font) ;
    text3.setCharacterSize(20);
    text3.setString("quit") ;
    text3.setPosition(385,315);
    text3.setFillColor(sf::Color::White);
    text3.setStyle(sf::Text::Bold) ;
    text3.setOutlineThickness(3);
    text3.setOutlineColor(sf::Color::Red) ;

    sf::Text text4 ;
    text4.setFont(font) ;
    text4.setCharacterSize(25);
    text4.setString("START : Enter\n Quit : F2" ) ;
    text4.setPosition(580,520);
    text4.setFillColor(sf::Color::Yellow);

    sf::Text text5 ;
    text5.setFont(font) ;
    text5.setCharacterSize(50);
    text5.setString("GAME OVER !!" ) ;
    text5.setPosition(200,200);
    text5.setFillColor(sf::Color::Blue);

    sf::Text text6;
    text6.setFont(font) ;
    text6.setCharacterSize(20);
    text6.setString("NEW GAME") ;
    text6.setPosition(320,320);
    text6.setFillColor(sf::Color::White);
    text6.setStyle(sf::Text::Bold) ;
    text6.setOutlineThickness(3);
    text6.setOutlineColor(sf::Color::Red) ;

    sf::Text text7 ;
    text7.setFont(font) ;
    text7.setCharacterSize(25);
    text7.setString("NEW GAME : F2 \n EXIT : F1" ) ;
    text7.setPosition(560,520);
    text7.setFillColor(sf::Color::Yellow);

    sf::Text text8 ;
    text8.setFont(font) ;
    text8.setCharacterSize(25);
    text8.setString("SCORE : " ) ;
    text8.setPosition(20,20);
    text8.setFillColor(sf::Color::Yellow);

    sf::Text text9 ;
    text9.setFont(font) ;
    text9.setCharacterSize(25);
    text9.setString("0" ) ;
    text9.setPosition(130,20);
    text9.setFillColor(sf::Color::Yellow);


    //---------------------
    // shabes
    sf::RectangleShape rect1 ;
    rect1.setSize(sf::Vector2f(150,60));
    rect1.setPosition(330,200) ;
    rect1. setFillColor(sf::Color::Blue);
    rect1.setOutlineThickness(3);
    rect1.setOutlineColor(sf::Color::White);

    sf::RectangleShape rect3 ;
    rect3.setSize(sf::Vector2f(150,60));
    rect3.setPosition(330,300) ;
    rect3.setFillColor(sf::Color::Blue);
    rect3.setOutlineThickness(3);
    rect3.setOutlineColor(sf::Color::White);

    sf::RectangleShape rect4 ;
    rect4.setSize(sf::Vector2f(180,60));
    rect4.setPosition(290,300) ;
    rect4. setFillColor(sf::Color::Blue);
    rect4.setOutlineThickness(3);
    rect4.setOutlineColor(sf::Color::White);

    // ---------------------
    //photos

    sf::Texture texture1 ;
    texture1.loadFromFile("data/car.png");
    sf::Sprite photo1(texture1);
    photo1.scale(sf::Vector2f(0.3,0.3)) ;
    photo1.setPosition(0,280) ;

    sf::Texture texture2;
    texture2.loadFromFile("data/back6.png") ;
    sf::Sprite photo2(texture2);

    sf::Texture texture3;
    texture3.loadFromFile("data/road3.png") ;
    sf::Sprite photo3(texture3);
    photo3.scale(sf::Vector2f(3.7,3.7));

    sf::Texture texture4;
    texture4.loadFromFile("data/car2.png");
    sf::Sprite photo4(texture4);
    photo4.scale(sf::Vector2f(0.2,0.2));
    photo4.setPosition(200,470);

    sf::Texture texture5;
    texture5.loadFromFile("data/barrier.png");
    sf::Sprite photo5(texture5);
    photo5.scale(sf::Vector2f(0.2,0.2));
    //photo5.setPosition(400,100);
    photo5.setPosition(100,100) ;

    sf::Texture texture6;
    texture6.loadFromFile("data/road3.png") ;
    sf::Sprite photo6(texture6);
    photo6.scale(sf::Vector2f(3.7,3.7));
    photo6.setPosition(400,0) ;

    sf::Texture texture7;
    texture7.loadFromFile("data/road3.png") ;
    sf::Sprite photo7(texture7);
    photo7.scale(sf::Vector2f(3.7,3.7));

    sf::Texture texture8;
    texture8.loadFromFile("data/road3.png") ;
    sf::Sprite photo8(texture8);
    photo8.scale(sf::Vector2f(3.7,3.7));
    photo8.setPosition(400,0) ;

    sf::Texture texture9;
    texture9.loadFromFile("data/coin.png");
    sf::Sprite photo9(texture9);
    photo9.scale(sf::Vector2f(0.125,0.125));
    photo9.setPosition(0,0) ;

    sf::Texture texture10;
    texture10.loadFromFile("data/barrier.png");
    sf::Sprite photo10(texture10);
    photo10.scale(sf::Vector2f(0.2,0.2));
    photo10.setPosition(0,0) ;



    // Start the game loop
    while (play == true)
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if((event.type==sf::Event::KeyPressed)&&(event.key.code==sf::Keyboard::Space))
            {
                space = true ;
            }
            if((event.type==sf::Event::KeyPressed)&&(event.key.code==sf::Keyboard::Enter))
            {
                enter = true ;
            }
            if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left))
            {
                left = true;
            }
            if((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::Right))
            {
                right = true ;
            }
            if((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::F2))
            {
                f2 = true ;
            }

            if((event.type == sf::Event::KeyPressed)&&(event.key.code == sf::Keyboard::F1))
            {
                f1 = true ;
            }
            if(photo4.getGlobalBounds().intersects(photo5.getGlobalBounds())==true ) // car2 --> block
            {
                crashblock = true ;
            }
            if(photo4.getGlobalBounds().intersects(photo10.getGlobalBounds())==true )
            {
                crashblock = true  ;
            }

        }

        // ------------------
        // logic
        if(f1 == true)
        {
            play = false ;
            f1 = false ;
        }
        //---------------
        if((photo1.getPosition().x>=0)&&(photo1.getPosition().x<=300))
        {
            xcar1+=3;
        }
        else
        {
            xcar1=xcar1;
        }
        photo1.setPosition(xcar1,280) ;
        //-------------
        if(left == true)
        {
            xcar2-=30 ;
            left = false ;
        }
        if(right == true)
        {
            xcar2+=30;
            right = false ;
        }
        if(photo4.getPosition().x<10)
        {
            xcar2 = 20 ;
        }
        if(photo4.getPosition().x>660)
        {
            xcar2 = 660 ;
        }
        photo4.setPosition(xcar2,470);
        //-------------

        if((photo3.getPosition().y>=0) &&(photo3.getPosition().y<=100))
        {
            yroad1+=15 ;
        }
        else
        {
            yroad1 = 0;
        }
        photo3.setPosition(0,yroad1) ;
        // ---------------
        if((photo6.getPosition().y>=0) &&(photo6.getPosition().y<=100))
        {
            yroad2+=15 ;
        }
        else
        {
            yroad2 = 0;
        }
        photo6.setPosition(400,yroad2) ;
        //-------------------


        if((photo5.getPosition().y>=0) && (photo5.getPosition().y<=700))
        {
            yblock1+=5 ;
            photo5.setPosition(x2, yblock1);
        }
        else
        {
            yblock1 = 0 ;
            x2 = (1+ (rand() % 300));
            photo5.setPosition(x2, yblock1) ;
        }
        // --------------------

        if((photo10.getPosition().y>=0) && (photo10.getPosition().y<=700))
        {
            yblock2+=5 ;
            photo10.setPosition(x3, yblock2);
        }
        else
        {
            yblock2 = 0 ;
            x3 = (400+ (rand() % 550));
            photo10.setPosition(x3, yblock2) ;
        }
        //----------------------

        if((photo9.getPosition().y>=0) && (photo9.getPosition().y<=700))
        {
            ycoin+=6 ;
            photo9.setPosition(x, ycoin);
        }
        else
        {
            ycoin = 0 ;
            x = (1+ (rand() % 700));
            photo9.setPosition(x, ycoin) ;
        }

        // -----------------------
        if(photo5.getGlobalBounds().intersects(photo4.getGlobalBounds())==true ) // car2 --> block
        {
            crashblock = true ;
        }
        if(photo10.getGlobalBounds().intersects(photo4.getGlobalBounds())==true )
        {
            crashblock = true ;
        }

        if(photo9.getGlobalBounds().intersects(photo4.getGlobalBounds()) == true)
        {
            countcoin++;
            photo9.setPosition(900,900) ;
        }
        // -----------------------

        std::string s =  std::to_string(countcoin);
        text9.setString(s);

        //---------------------

        // rendering


        if((space == false)&&(enter == false))
        {
            window.clear();
            window.draw(text1);
            window.draw(photo1);
            window.display() ;
        }


        if((space == true ))
        {
            window.clear();
            window.draw(photo2) ;
            window.draw(rect1) ;
            window.draw(rect3) ;
            window.draw(text2);
            window.draw(text3) ;
            window.draw(text4);
            window.display();
        }

        if(enter == true)
        {
            space = false ;
            window.clear() ;
            window.draw(photo7);
            window.draw(photo8) ;
            window.draw(photo3);
            window.draw(photo6) ;
            window.draw(photo4) ;
            window.draw(photo5);
            window.draw(photo10) ;
            window.draw(photo9) ;
            window.draw(text8) ;
            window.draw(text9) ;
            window.display() ;
        }
        if(crashblock == true &&enter == false )
        {
            countcoin = 0 ;
            enter = false ;
            window.clear();
            window.draw(text5) ;
            window.draw(rect4) ;
            window.draw(text6) ;
            window.draw(text7) ;
            window.display() ;
        }
        if(f2 == true )
        {
            crashblock = false ;
            enter = true ;
            f2 = false ;
        }

    }
    return 0;
}
