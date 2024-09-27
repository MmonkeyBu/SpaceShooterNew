#include "FaseLevel3.hpp"
#include "inimigo.hpp"
#include <iostream>
#include <conio.h>
#include "Game.hpp"
#include "Handler.hpp"
#include <windows.h>
#include "boss.hpp"

void FaseLevel3::init() {

    player = new Player(ObjetoDeJogo("Player", Sprite("rsc/nave.img"), 66, 103));
    boss = new Boss(ObjetoDeJogo("Boss", Sprite("rsc/boss.img"), 5, 100));

    objs.push_back(boss);
    objs.push_back(player);

    objs.push_back(new ObjetoDeJogo("HUD", Sprite("rsc/HUD_cima.img"), 0, 0));
    objs.push_back(new ObjetoDeJogo("Life", TextSprite("####################"), 1, 32));

    SpriteBase *tmp = const_cast<SpriteBase *>(objs.back()->getSprite());
    life = dynamic_cast<TextSprite *>(tmp);
}

unsigned FaseLevel3::run(SpriteBuffer &screen) {
    char ent;
    boss->desativarObj();

    for (int i = 0; i < 70; i++) {
        player->moveUp(1);
        Sleep(10);
        screen.clear();
        draw(screen);
        system("cls");
        show(screen);
    }

    player->setPosL(66);
    boss->ativarObj();

    screen.clear();
    draw(screen);
    system("cls");
    show(screen);

    
    int ataqueEspecialCooldown = 0; 

    while (true) {
        
        if (_kbhit()) { 
            ent = _getch();

            
            int posL = player->getPosL(), posC = player->getPosC();

            
            if (ent == 'a' && player->getPosC() > 12) {
                player->moveLeft(5);
            } else if (ent == 'd' && player->getPosC() < screen.getLargura() - player->getSprite()->getLargura() - 13) {
                player->moveRight(5);
            } else if (ent == 'x') {
                
                Sprite *spriteProjetil = new Sprite("rsc/projetil.img");
                Projetil *novoProjetil = new Projetil(ObjetoDeJogo("projetil", *spriteProjetil, player->getPosL(), player->getPosC()), 5, Projetil::Direcao::CIMA);
                novoProjetil->setPosC(posC + player->getSprite()->getLargura() / 2 - novoProjetil->getSprite()->getLargura() / 2); 
                objs.push_back(novoProjetil);
                handlerProjeteis.adicionarProjetil(novoProjetil);
            } else if (ent == 'q') {
                return Fase::QUIT_GAME; 
            }
        }
            
            //boss tiros
                if (ataqueEspecialCooldown <= 0) {

                Sprite *spriteProjetil = new Sprite("rsc/projetil_boss.img");
                Projetil *novoProjetil = new Projetil(ObjetoDeJogo("projetil", *spriteProjetil, player->getPosL() + 3 , player->getPosC()), 1, Projetil::Direcao::BAIXO);
                novoProjetil->setPosC(boss->getPosC() + player->getSprite()->getLargura() / 2 - novoProjetil->getSprite()->getLargura() / 2);
                objs.push_back(novoProjetil);
                handlerProjeteis.adicionarProjetil(novoProjetil);
                    ataqueEspecialCooldown = 100; 
            } else {
                ataqueEspecialCooldown--; 
            }
        handlerProjeteis.atualizarProjeteis();

       
        for (auto itProjeteis = handlerProjeteis.getProjeteisAtivos().begin(); itProjeteis != handlerProjeteis.getProjeteisAtivos().end();) {
            Projetil *projetil = *itProjeteis;

            if (projetil->colideCom(*boss)) {
                projetil->desativarObj();
                boss->sofrerAtaque(player->atacar());

                itProjeteis = handlerProjeteis.getProjeteisAtivos().erase(itProjeteis);
            } else {
                ++itProjeteis;
            }
            if(projetil->colideCom(*player)){
                projetil->desativarObj();
                boss->sofrerAtaque(boss->atacar());
            }
        }

            if (!boss->isAlive()) {
                boss->desativarObj();
            return Fase::END_FASE; 
    }
        if (player->colideCom(*boss)) {
            player->sofrerAtaque(boss->atacar());

            if (!player->isAlive()) {
                life->setText(std::string(player->getLife() / 5, '#'));
                return Fase::GAME_OVER; 
            }
        }

        boss->update();

        screen.clear();
        update();
        draw(screen);
        system("cls");
        show(screen);
    }
}