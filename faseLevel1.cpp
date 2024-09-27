#include "FaseLevel1.hpp"
#include "inimigo.hpp"
#include <iostream>
#include <conio.h>
#include "Game.hpp"
#include "Handler.hpp"
#include <windows.h>

void FaseLevel1::init()
{
    //  Criando os objetos de jogo

    inimigosVivos = 12;
    inimigosMortos = 0;

    player = new Player(ObjetoDeJogo("Player", Sprite("rsc/nave.img"), 66, 103));

    // Adicionando inimigos a fase
    aliens.push_back(new Enemy(ObjetoDeJogo("Enemy1", Sprite("rsc/inimigo.img"), 5, 20)));
    objs.push_back(aliens.back());

    aliens.push_back(new Enemy(ObjetoDeJogo("Enemy2", Sprite("rsc/inimigo.img"), 5, 40)));
    objs.push_back(aliens.back());

    aliens.push_back(new Enemy(ObjetoDeJogo("Enemy3", Sprite("rsc/inimigo.img"), 5, 60)));
    objs.push_back(aliens.back());

    aliens.push_back(new Enemy(ObjetoDeJogo("Enemy4", Sprite("rsc/inimigo.img"), 5, 80)));
    objs.push_back(aliens.back());

    aliens.push_back(new Enemy(ObjetoDeJogo("Enemy5", Sprite("rsc/inimigo.img"), 5, 100)));
    objs.push_back(aliens.back());

    aliens.push_back(new Enemy(ObjetoDeJogo("Enemy6", Sprite("rsc/inimigo.img"), 5, 120)));
    objs.push_back(aliens.back());

    aliens.push_back(new Enemy(ObjetoDeJogo("Enemy7", Sprite("rsc/inimigo.img"), 5, 140)));
    objs.push_back(aliens.back());

    aliens.push_back(new Enemy(ObjetoDeJogo("Enemy8", Sprite("rsc/inimigo.img"), 5, 160)));
    objs.push_back(aliens.back());

    aliens.push_back(new Enemy(ObjetoDeJogo("Enemy10", Sprite("rsc/inimigo.img"), 5, 180)));
    objs.push_back(aliens.back());

    aliens.push_back(new Enemy(ObjetoDeJogo("Enemy11", Sprite("rsc/inimigo.img"), 5, 200)));
    objs.push_back(aliens.back());

    aliens.push_back(new Enemy(ObjetoDeJogo("Enemy12", Sprite("rsc/inimigo.img"), 5, 220)));
    objs.push_back(aliens.back());

    objs.push_back(player);

    objs.push_back(new ObjetoDeJogo("HUD", Sprite("rsc/HUD_cima.img"), 0, 0));

    objs.push_back(new ObjetoDeJogo("Life", TextSprite("####################"), 1, 32));
    SpriteBase *tmp = const_cast<SpriteBase *>(objs.back()->getSprite());
    life = dynamic_cast<TextSprite *>(tmp);
}

unsigned FaseLevel1::run(SpriteBuffer &screen)
{
    char ent;

    for (int i = 0; i < 70; i++)
    {
        for (auto alien : aliens)
        {
            alien->desativarObj();
        }

        player->moveUp(1);
        Sleep(10);

        screen.clear();
        draw(screen);
        system("cls");
        show(screen);
    }

    player->setPosL(66);

    for (auto alien : aliens)
    {
        alien->ativarObj();
    }

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

        // Movimentação do jogador
        if (ent == 'a' && player->getPosC() > 12)
        {
            player->moveLeft(3);
        }
        else if (ent == 'd' && player->getPosC() < screen.getLargura() - player->getSprite()->getLargura() - 13)
        {
            player->moveRight(3);
        }
        else if (ent == 'x')
        {
            // Cria um novo projétil
            Sprite *spriteProjetil = new Sprite("rsc/projetil.img");
            Projetil *novoProjetil = new Projetil(ObjetoDeJogo("projetil", *spriteProjetil, player->getPosL(), player->getPosC()), 5, Projetil::Direcao::CIMA);
            novoProjetil->setPosC(posC + player->getSprite()->getLargura() / 2 - novoProjetil->getSprite()->getLargura() / 2); // Centraliza o projétil
            objs.push_back(novoProjetil);
            handlerProjeteis.adicionarProjetil(novoProjetil);
        }
        else if (ent == 'q')
        {
            return Fase::QUIT_GAME; // Encerra o jogo
        }

        handlerProjeteis.atualizarProjeteis();

        // Verifica colisões entre projéteis e inimigos
        for (auto itProjeteis = handlerProjeteis.getProjeteisAtivos().begin(); itProjeteis != handlerProjeteis.getProjeteisAtivos().end();)
        {
            Projetil *projetil = *itProjeteis;
            bool projetilRemovido = false;

            for (auto alien : aliens)
            {
                if (projetil->colideCom(*alien))
                {
                    projetil->desativarObj();
                    alien->sofrerAtaque(player->atacar());

                    if (!alien->isAlive())
                        alien->desativarObj();
                        inimigosMortos++;
                }
            }

            if (projetilRemovido)
            {
                handlerProjeteis.removerProjetil(projetil);
                itProjeteis = handlerProjeteis.getProjeteisAtivos().begin();
            }
            else
            {
                ++itProjeteis;
            }
         }

        //player colidiu com um inimigo?
        for (auto alien : aliens)
        {
            if (player->colideCom(*alien))
            {
                player->sofrerAtaque(alien->atacar());

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

                life->setText(std::string(player->getLife() / 5, '#'));
                update();
            }

            if (alien->isAlive())
            {
                allMortos = false;
            }
            else if (!alien->isAlive())
            {
                allMortos = true;
            }
        }

        if ((inimigosMortos/2) == 12)
        {
            return Fase::END_FASE;
        }

        // Atualiza a tela
        screen.clear();
        update();
        draw(screen);
        system("cls");
        std::cout << inimigosMortos << std::endl;
        show(screen);
    }
}