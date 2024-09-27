#include "FaseLevel2.hpp"
#include <iostream>
#include <conio.h>
#include "Game.hpp"
#include "Handler.hpp"
#include <windows.h>
#include "meteoro.hpp"

void FaseLevel2::init()
{
    MeteorosApagados = 0;  // Inicializando o contador de meteoros apagados

    // Criando os objetos de jogo
    player = new Player(ObjetoDeJogo("Player", Sprite("rsc/nave.img"), 66, 103));

    meteoros.push_back(new Meteoro(ObjetoDeJogo("Meteoro1", Sprite("rsc/meteoro.img"), -10, 50)));
    objs.push_back(meteoros.back());

    meteoros.push_back(new Meteoro(ObjetoDeJogo("Meteoro2", Sprite("rsc/meteoro.img"), -20, 150)));
    objs.push_back(meteoros.back());

    meteoros.push_back(new Meteoro(ObjetoDeJogo("Meteoro3", Sprite("rsc/meteoro.img"), -60, 70)));
    objs.push_back(meteoros.back());

    meteoros.push_back(new Meteoro(ObjetoDeJogo("Meteoro4", Sprite("rsc/meteoro.img"), -40, 80)));
    objs.push_back(meteoros.back());

    meteoros.push_back(new Meteoro(ObjetoDeJogo("Meteoro5", Sprite("rsc/meteoro.img"), -100, 120)));
    objs.push_back(meteoros.back());

    meteoros.push_back(new Meteoro(ObjetoDeJogo("Meteoro6", Sprite("rsc/meteoro.img"), -50, 60)));
    objs.push_back(meteoros.back());

    meteoros.push_back(new Meteoro(ObjetoDeJogo("Meteoro7", Sprite("rsc/meteoro.img"), -25, 75)));
    objs.push_back(meteoros.back());

    meteoros.push_back(new Meteoro(ObjetoDeJogo("Meteoro8", Sprite("rsc/meteoro.img"), -83, 100)));
    objs.push_back(meteoros.back());

    meteoros.push_back(new Meteoro(ObjetoDeJogo("Meteoro9", Sprite("rsc/meteoro.img"), -22, 200)));
    objs.push_back(meteoros.back());
    
    meteoros.push_back(new Meteoro(ObjetoDeJogo("Meteoro10", Sprite("rsc/meteoro.img"), -93, 60)));
    objs.push_back(meteoros.back());

    meteoros.push_back(new Meteoro(ObjetoDeJogo("Meteoro11", Sprite("rsc/meteoro.img"), -105, 75)));
    objs.push_back(meteoros.back());

    meteoros.push_back(new Meteoro(ObjetoDeJogo("Meteoro12", Sprite("rsc/meteoro.img"), -80, 100)));
    objs.push_back(meteoros.back());

    meteoros.push_back(new Meteoro(ObjetoDeJogo("Meteoro13", Sprite("rsc/meteoro.img"), -20, 200)));
    objs.push_back(meteoros.back());

    meteoros.push_back(new Meteoro(ObjetoDeJogo("Meteoro14", Sprite("rsc/meteoro.img"), -97, 2)));
    objs.push_back(meteoros.back());

    meteoros.push_back(new Meteoro(ObjetoDeJogo("Meteoro15", Sprite("rsc/meteoro.img"), -42, 137)));
    objs.push_back(meteoros.back());
    
    meteoros.push_back(new Meteoro(ObjetoDeJogo("Meteoro16", Sprite("rsc/meteoro.img"), -93, 95)));
    objs.push_back(meteoros.back());

    meteoros.push_back(new Meteoro(ObjetoDeJogo("Meteoro17", Sprite("rsc/meteoro.img"), -104, 172)));
    objs.push_back(meteoros.back());

    meteoros.push_back(new Meteoro(ObjetoDeJogo("Meteoro18", Sprite("rsc/meteoro.img"), -80, 50)));
    objs.push_back(meteoros.back());

    meteoros.push_back(new Meteoro(ObjetoDeJogo("Meteoro19", Sprite("rsc/meteoro.img"), -20, 200)));
    objs.push_back(meteoros.back());

    objs.push_back(player);
    objs.push_back(new ObjetoDeJogo("HUD", Sprite("rsc/HUD_cima.img"), 0, 0));

    objs.push_back(new ObjetoDeJogo("Life", TextSprite("####################"), 1, 32));
    SpriteBase *tmp = const_cast<SpriteBase *>(objs.back()->getSprite());
    life = dynamic_cast<TextSprite *>(tmp);
}

unsigned FaseLevel2::run(SpriteBuffer &screen)
{
    char ent;

    for (int i = 0; i < 70; i++)
    {
        player->moveUp(1);
        Sleep(10);

        screen.clear();
        draw(screen);
        system("cls");
        show(screen);
    }

    player->setPosL(66);
    screen.clear();
    draw(screen);
    system("cls");
    show(screen);

    while (true)
    {
        // Lendo entrada
        ent = _getch();
        // Processamento de entrada
        int posL = player->getPosL(), posC = player->getPosC();

        if (ent == 'a' && player->getPosC() > 12)
        {
            player->moveLeft(3);
        }
        else if (ent == 'd' && player->getPosC() < screen.getLargura() - player->getSprite()->getLargura() - 13)
        {
            player->moveRight(3);
        }
        else if (ent == 'q')
        {
            return Fase::QUIT_GAME; 
        }
        else if (ent == 'f')
        {
            return Fase::END_FASE; 
        }

        // Movimentação dos meteoros
        for (auto meteoro : meteoros)
        {
            meteoro->moveDown(2);
        }


        for (auto meteoro : meteoros)
        {
            if (player->colideCom(*meteoro))
            {
                player->sofrerAtaque(meteoro->atacar());

                if (!player->isAlive())
                {
                    life->setText(std::string(player->getLife() / 5, '#'));

                    screen.clear();
                    update();
                    draw(screen);
                    system("cls");
                    std::cout << player->getLife() << std::endl;
                    show(screen);
                    return Fase::GAME_OVER;
                }
            }
                life->setText(std::string(player->getLife() / 5, '#'));
                update();
            }


        screen.clear();
        update();
        draw(screen);
        system("cls");
        show(screen);
    }
}
