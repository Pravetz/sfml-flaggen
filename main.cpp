#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include <iostream>


using namespace sf;

int w = 300, h = 200;
int flagtype;
int heraldry;
int hv;
int save_int = 0;

int main(int argc, char** argv)
{
	using namespace std;
	
	//////////////////////////////////////////////
	// [i] - information for debugging			//
	// [^] - successfully completed operation	//
	//////////////////////////////////////////////
	
	srand(time(0));
	flagtype = rand() % 3 + 1; /* 1 - monocolor, 2 - bicolor, 3 - tricolor  */
	heraldry = rand() % 10; /* CHANGE THIS LINE IF YOU ADDED OR REMOVED HERALDRY IN THE ASSETS/GFX */
	hv = rand() % 2 + 1; /*1 - horizontal, 2 - vertical */
	
	std::cout <<"[i] "<<flagtype<<" "<<heraldry<<" "<<hv<<std::endl;
	
	sf::RenderWindow app(sf::VideoMode(w, h, 32), "SFML Flag generation tool by Pravetz");
	
	save_int = atoi(argv[1]);
	
	sf::RenderTexture texture;
	
	if (!texture.create(300, 200))
	{
		return -1;
	}
	
	Texture sector;
	
	Texture sector2;
	
	sector.loadFromFile("assets/gfx/sectr.png");
	sector2.loadFromFile("assets/gfx/sectr2.png");
	
	Texture nsector;
	Texture nsector2;
	
	nsector.loadFromFile("assets/gfx/nsectr.png");
	nsector2.loadFromFile("assets/gfx/nsectr2.png");
	
	Sprite ns(nsector);
	Sprite ns2(nsector2);
	
	Sprite s(sector);
	Sprite s1(sector);
	Sprite s2(sector);
	
	Sprite s3(sector2);	
	Sprite s4(sector2);
	Sprite s5(sector2);	
	
	Sprite s6;
	
	Texture flag_elements;
	
	if(heraldry > 0){
		flag_elements.loadFromFile("assets/gfx/"+std::to_string(heraldry)+".png");
	}
	
	Sprite fl_e(flag_elements);
	
	///////////////////// POSITIONS /////////////////////////
	
	if (flagtype == 3 && hv == 2 && heraldry != 9 && heraldry != 8){		// TRICOLORS
		s.setPosition(0,0);				//
		s1.setPosition(100,0);			//
		s2.setPosition(200,0);			//
	}
	
	if (flagtype == 3 && hv == 1 && heraldry != 9 && heraldry != 8){		//
		s3.setPosition(0,0);			//
		s4.setPosition(0,67);			//
		s5.setPosition(0,133);			//
	}
	
	if (flagtype == 2 && hv == 2){		// BICOLORS
		s.setPosition(0,0);				//
		s1.setPosition(150,0);			//
	}
	
	if (flagtype == 2 && hv == 1){		//
		s3.setPosition(0,0);			//
		s4.setPosition(0,100);			//
	}
	
	
	//////////// SCALING FOR MONOCOLORS /////////////
	if (flagtype == 1){
		sf::Vector2u size_flag = sector.getSize();
		sf::Vector2u size_window = app.getSize();
		
		float scale_x = (float) size_window.x / size_flag.x;
		float scale_y = (float) size_window.y / size_flag.y;
		
		s6.setTexture(sector);
		s6.setScale(scale_x, scale_y);
	}
	
	//////////// SCALING FOR BICOLORS /////////////
	if (flagtype == 2 && hv == 2 && heraldry != 9){
		sf::Vector2u size_flag = sector.getSize();
		
		float scale_x = size_flag.x / 2;
		s.setScale(scale_x, 1);
		s1.setScale(scale_x, 1);
	}
	
	if (flagtype == 2 && hv == 2 && heraldry == 9){ 	// SPECIAL SCALING
		sf::Vector2u size_flag = sector.getSize();		// FOR NORDIC CROSS ELEMENT(9.png)
		
		float scale_x = size_flag.x * 2;
		s1.setScale(scale_x, 1);
		s1.setPosition(100,0);
	}
	
	if (flagtype == 2 && hv == 1){
		sf::Vector2u size_flag = sector2.getSize();
		
		float scale_y = size_flag.y / 2;
		s3.setScale(1, scale_y);
		s4.setScale(1, scale_y);
	}
	
	/////////////////////// SCALING FOR TRICOLORS //////////////////////
	
	if (flagtype == 3 && hv == 2 && heraldry == 9){ 	// SPECIAL TRICOLOR SCALING
		sf::Vector2u size_flag = sector.getSize();		// FOR NORDIC CROSS ELEMENTS("9.png", "8.png")
		
		float scale_x = size_flag.x * 2;
		s2.setScale(scale_x, 1);
		s2.setPosition(100,0);
	}
	
	if (flagtype == 3 && hv == 2 && heraldry == 8){ 	// SPECIAL TRICOLOR SCALING
		sf::Vector2u size_flag = sector.getSize();		// FOR NORDIC CROSS ELEMENTS("9.png", "8.png")
		
		float scale_x = size_flag.x / 2;
		s.setScale(scale_x, 1);
		s2.setScale(scale_x, 1);
		s.setPosition(0,0);
		s2.setPosition(150,0);
	}
	
	if (flagtype == 3 && hv == 1 && heraldry == 8 || heraldry == 9){ 	// SPECIAL TRICOLOR SCALING
		sf::Vector2u size_flag = sector2.getSize();						// FOR NORDIC CROSS ELEMENTS("9.png", "8.png")
		
		float scale_y = size_flag.y / 2;
		s3.setScale(1, scale_y);
		s5.setScale(1, scale_y);
		
		s3.setPosition(0,0);
		s5.setPosition(0,100);
	}
	
	///////////////////////////////////////////////////////////////
	
	if(heraldry < 8){
		fl_e.setPosition(130,75);
	}
	
	int r, g, b;
	
	////////////////////////// Coloring ////////////////////////////
	
	///////////////////////////////////////////////////////////////
	//							TRICOLORS						 //
	///////////////////////////////////////////////////////////////
	
	if(flagtype == 3 && hv == 2 && heraldry != 8 && heraldry != 9){
		s.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] stripe 1: "<<r<<" "<<g<<" "<<b<<endl;
		s1.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] stripe 2: "<<r<<" "<<g<<" "<<b<<endl;
		s2.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] stripe 3: "<<r<<" "<<g<<" "<<b<<endl;
	}
	
	if(flagtype == 3 && hv == 1 && heraldry != 8 && heraldry != 9){
		s3.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] stripe 1: "<<r<<" "<<g<<" "<<b<<endl;
		s4.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] stripe 2: "<<r<<" "<<g<<" "<<b<<endl;
		s5.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] stripe 3: "<<r<<" "<<g<<" "<<b<<endl;
	}
	
	if(flagtype == 3 && hv == 2 && heraldry == 8){
		s.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] stripe 1: "<<r<<" "<<g<<" "<<b<<endl;
		s2.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] stripe 2: "<<r<<" "<<g<<" "<<b<<endl;
		ns2.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] cross: "<<r<<" "<<g<<" "<<b<<endl;
	}
	
	if(flagtype == 3 && hv == 2 && heraldry == 9){
		s.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] stripe 1: "<<r<<" "<<g<<" "<<b<<endl;
		s2.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] stripe 2: "<<r<<" "<<g<<" "<<b<<endl;
		ns.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] cross: "<<r<<" "<<g<<" "<<b<<endl;
	}
	
	if(flagtype == 3 && hv == 1 && heraldry == 9){
		s3.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] stripe 1: "<<r<<" "<<g<<" "<<b<<endl;
		s5.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] stripe 2: "<<r<<" "<<g<<" "<<b<<endl;
		ns.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] cross: "<<r<<" "<<g<<" "<<b<<endl;
	}
	
	if(flagtype == 3 && hv == 1 && heraldry == 8){
		s3.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] stripe 1: "<<r<<" "<<g<<" "<<b<<endl;
		s5.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] stripe 2: "<<r<<" "<<g<<" "<<b<<endl;
		ns2.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] cross: "<<r<<" "<<g<<" "<<b<<endl;
	}
	
	///////////////////////////////////////////////////////////////
	//							BICOLORS						 //
	///////////////////////////////////////////////////////////////
	
	if(flagtype == 2 && hv == 2){
		s.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] stripe 1: "<<r<<" "<<g<<" "<<b<<endl;
		s1.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] stripe 2: "<<r<<" "<<g<<" "<<b<<endl;
	}
	
	if(flagtype == 2 && hv == 1){
		s3.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] stripe 1: "<<r<<" "<<g<<" "<<b<<endl;
		s4.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] stripe 2: "<<r<<" "<<g<<" "<<b<<endl;
	}
	
	///////////////////////////////////////////////////////////////
	//							MONOCOLOR						 //
	///////////////////////////////////////////////////////////////
	
	if(flagtype == 1){
		s6.setColor(sf::Color( r = rand() % 256, g = rand() % 256, b = rand() % 256));
			std::cout<<"[i] color: "<<r<<" "<<g<<" "<<b<<endl;
	}
	
	while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                app.close();
        }
	
	
	texture.clear(sf::Color::Black);
	
	if (flagtype == 3 && hv == 2 && heraldry != 8 && heraldry != 9){
		texture.draw(s);
		texture.draw(s1);
		texture.draw(s2);
	}
	
	if (flagtype == 3 && hv == 2 && heraldry == 8){
		texture.draw(s);
		texture.draw(s2);
		texture.draw(ns2);
	}
	
	if (flagtype == 3 && hv == 2 && heraldry == 9){
		texture.draw(s);
		texture.draw(s2);
		texture.draw(ns);
	}
	
	if (flagtype == 3 && hv == 1 && heraldry != 8 && heraldry != 9){
		texture.draw(s3);
		texture.draw(s4);
		texture.draw(s5);
	}
	
	if (flagtype == 3 && hv == 1 && heraldry == 8){
		texture.draw(s3);
		texture.draw(s5);
		texture.draw(ns2);
	}
	
	if (flagtype == 3 && hv == 1 && heraldry == 9){
		texture.draw(s3);
		texture.draw(s5);
		texture.draw(ns);
	}
	
	if (flagtype == 2 && hv == 2){
		texture.draw(s);
		texture.draw(s1);
	}
	
	if (flagtype == 2 && hv == 1){
		texture.draw(s3);
		texture.draw(s4);
	}
	
	if (flagtype == 1){
		texture.draw(s6);
	}
	
	if(heraldry > 0){
		texture.draw(fl_e);
	}
	
	texture.display();
	
	std::string SAVED_FILENAME = std::to_string(flagtype)+" "+std::to_string(heraldry)+" "+std::to_string(hv)+".png";
	
	if(save_int == 1){
		texture.getTexture().copyToImage().saveToFile(SAVED_FILENAME);
	}
	
	app.clear(sf::Color(220,220,220));
	
	
    Sprite sprite(texture.getTexture());
    
    app.draw(sprite);
    app.display();
        }
    
    if(save_int == 1){
		std::cout <<"[^] Saved flag."<<std::endl;
	}
    
	return 0;
}
