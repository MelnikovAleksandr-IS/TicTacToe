#include <SFML/Graphics.hpp>
#include <cstdlib>

using namespace sf;

bool zanyatoli[9] = { 0 };

int mojnoliPC()
{
	int mojnov = 0;
	bool nuuuuu = false;
	while (!nuuuuu)
	{
		mojnov = rand() % 9;
		if (!zanyatoli[mojnov])
		{
			nuuuuu = true;
		}
	}
	return mojnov;
}

bool kaktakktovigral(bool n, bool k, bool m)
{
	if (n && k && m)
	{
		return true;
	}
}

class ticiticitactac                                                   // Класс для изображения крестиков и ноликов
{
public:
	Sprite yach[9];
	bool dadanetnet[9];

	void upd(int& mivibrali)
	{
		for (int n = 0; n < 9; n++)
		{
			yach[n].setTextureRect(IntRect(200 * (mivibrali - 1), 0, 200, 200));
		}
	}

	ticiticitactac(Texture& kartinka)
	{
		for (int n = 0; n < 9; n++)
		{
			yach[n].setTexture(kartinka);
			dadanetnet[n] = false;
		}
		for (int n = 0; n < 3; n++)
		{
			for (int k = 0; k < 3; k++)
			{
				yach[n * 3 + k].setPosition(200 * k, 200 * n);
			}
		}
	}
};

int main()
{
	RenderWindow Win(VideoMode(600, 600), L"Крестики-Нолики");         // 

	Image iconka;                                                      // Иконка игры
	if (!iconka.loadFromFile("Images/im.png"))                         
	{                                                                  
		return 1;                                                      
	}                                                                  
	Win.setIcon(32, 32, iconka.getPixelsPtr());                        

	Texture krestikinoliki;                                            // Выбор между крестиками и ноликами
	if (!krestikinoliki.loadFromFile("Images/chtoza.png"))
	{
		return 2;
	}
	Sprite choise[2];
	for (int n = 0; n < 2; n++)
	{
		choise[n].setTexture(krestikinoliki);
		choise[n].setPosition(50 + 300 * n, 180);
	}

	Texture pole;                                                      // Картинка поля
	if (!pole.loadFromFile("Images/joopel2.png"))
	{
		return 3;
	}
	Sprite p(pole);

	Font font;                                                         //
	if (!font.loadFromFile("Images/pico-8.ttf"))
	{
		return 4;
	}
	Text pobedniytxt;                                                  //   
	pobedniytxt.setFont(font);
	pobedniytxt.setCharacterSize(60);
	pobedniytxt.setString("Game Over!");
	pobedniytxt.setFillColor(Color::Blue);
	pobedniytxt.setOutlineThickness(3);
	pobedniytxt.setOutlineColor(Color::Black);
	pobedniytxt.setPosition(Vector2f{ Win.getSize() / 13u });

	bool okonchanie = false, aPCvoobsheloh = false;
	bool poziciadlyaokonchaniya[8][2];

	int mivibrali = 0;                                                 // Элемент проверки

	ticiticitactac ME(krestikinoliki), PC(krestikinoliki);

	int kolvozabitih = 0;

	while (Win.isOpen())
	{
		Vector2i POS = Mouse::getPosition(Win);

		Event event;
		while (Win.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				Win.close();
			}
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.key.code == Mouse::Left)
				{
					if (mivibrali == 0)
					{
						for (int n = 0; n < 2; n++)
						{
							if (choise[n].getGlobalBounds().contains(POS.x, POS.y))
							{
								mivibrali = n + 1; // Если 1, то крестик. Если 2 - нолик
							}
						}
					}
					else
					{
						for (int n = 0; n < 9; n++)
						{
							if (ME.yach[n].getGlobalBounds().contains(POS.x, POS.y) && !zanyatoli[n])
							{
								ME.dadanetnet[n] = true;
								zanyatoli[n] = 1;
								kolvozabitih++;
								aPCvoobsheloh = true;
							}
						}
					}
				}
			}
		}
		for (int n = 0; n < 2; n++)
		{
			if (choise[n].getGlobalBounds().contains(POS.x, POS.y))
			{
				choise[n].setTextureRect(IntRect(200 * n, 200, 200, 200));
			}
			else
			{
				choise[n].setTextureRect(IntRect(200 * n, 0, 200, 200));
			}
		}

		for (int n = 0; n < 8; n++)
		{
			if (n < 3)
			{
				poziciadlyaokonchaniya[n][0] = kaktakktovigral(ME.dadanetnet[3 * n], ME.dadanetnet[1 + 3 * n], ME.dadanetnet[2 + 3 * n]);
				poziciadlyaokonchaniya[n][1] = kaktakktovigral(PC.dadanetnet[3 * n], PC.dadanetnet[1 + 3 * n], PC.dadanetnet[2 + 3 * n]);
			}
			else if (n >= 3 && n < 6)
			{
				poziciadlyaokonchaniya[n][0] = kaktakktovigral(ME.dadanetnet[n - 3], ME.dadanetnet[n], ME.dadanetnet[n + 3]);
				poziciadlyaokonchaniya[n][1] = kaktakktovigral(PC.dadanetnet[n - 3], PC.dadanetnet[n], PC.dadanetnet[n + 3]);
			}
			else if (n >= 6)
			{
				poziciadlyaokonchaniya[n][0] = kaktakktovigral(ME.dadanetnet[2 * (n - 6)], ME.dadanetnet[4], ME.dadanetnet[8 - 2 * (n - 6)]);
				poziciadlyaokonchaniya[n][1] = kaktakktovigral(PC.dadanetnet[2 * (n - 6)], PC.dadanetnet[4], PC.dadanetnet[8 - 2 * (n - 6)]);
			}
			for (int k = 0; k < 2; k++)
			{
				if (poziciadlyaokonchaniya[n][k])
				{
					okonchanie = true;
				}
			}
		}

		int chPC = 0;

		if (aPCvoobsheloh && !okonchanie && kolvozabitih < 9)
		{
			kolvozabitih++;
			chPC = mojnoliPC();
			aPCvoobsheloh = false;
			PC.dadanetnet[chPC] = true;
			zanyatoli[chPC] = 1;
		}

		ME.upd(mivibrali);
		int PCvibral = mivibrali + 1;
		if (PCvibral == 3)
		{
			PCvibral = 1;
		}
		PC.upd(PCvibral);

		Win.clear(Color::Black);
		if (mivibrali == 0)
		{
			for (int n = 0; n < 2; n++)
			{
				Win.draw(choise[n]);
			}
		}
		else
		{
			Win.draw(p);
			for (int n = 0; n < 9; n++)
			{
				if (ME.dadanetnet[n])
				{
					Win.draw(ME.yach[n]);
				}
				if (PC.dadanetnet[n])
				{
					Win.draw(PC.yach[n]);
				}
			}
		}
		if (okonchanie)
		{
			Win.draw(pobedniytxt);
		}
		Win.display();
	}
	return 0;
}
