#include "fasefinal.hpp"
#include "inimigo.hpp"
#include <iostream>
#include <conio.h>
#include "Game.hpp"
#include "Handler.hpp"
#include <windows.h>
#include <conio.h>

void FaseLevel4::init()
{
    player = new Player(ObjetoDeJogo("Player", Sprite("rsc/nave.img"), 66, 103));
    objs.push_back(player);
}

unsigned FaseLevel4::run(SpriteBuffer &screen)
{
    

    screen.clear();
    draw(screen);
    system("cls");
    show(screen);


    int i = 1;
    while(i >= 70)
    {
        // Lendo entrada
        char ent;
        ent = _getch();

        // Movimentação do jogador
        if (ent == 'q')
        {
            return Fase::QUIT_GAME; 
        }
        
                player->moveUp(1);
        Sleep(10);

        screen.clear();
        draw(screen);
        system("cls");
        show(screen);
        i++;
    }

    player->setPosL(66);




        objs.push_back(new ObjetoDeJogo("Mensagem", TextSprite("Seu trabalho acabou...descanse"), 48, 50));
        SpriteBase *tmp = const_cast<SpriteBase *>(objs.back()->getSprite());

        // Atualiza a tela
        screen.clear();
        update();
        draw(screen);
        system("cls");
        show(screen);
    }
