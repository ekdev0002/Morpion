/*made by KABORE ERIC

le main ci-présent constitue l'ordonanceur de notre programme*/


#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include"jeu.h"

//declation des variables générales du "main"

    SDL_Surface *ecran = NULL, *imagefond = NULL,*texte=NULL;
    SDL_Rect positionfond,position;
    SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleur_text = {250, 30, 200},couleur_icone={255,0,0};

    /*la variable continuer sera le parametre de controle de la boucle générale du projet et
    la variable retour_menu celui de la boucle du jeu*/
    int continuer =1,retour_menu=3;


    // le sous programme menu_principal affichera le menu principal à chaque fois gu'il sera appelé
    void menu_principal()
    {


    ecran = SDL_SetVideoMode(1000,650, 32,SDL_HWSURFACE | SDL_DOUBLEBUF);
    imagefond = SDL_LoadBMP("image/welcome1.bmp");
    SDL_BlitSurface(imagefond, NULL, ecran, &positionfond);
    SDL_Flip(ecran);

//affichage du texte du menu

    //coordonnée  de l'mage du fond
    positionfond.x=0;
    positionfond.y=0;

    //affichage du texte du menu

    position.x=250;
    position.y=200;

    police = TTF_OpenFont("ITCEDSCR.ttf", 65);
    texte = TTF_RenderText_Blended(police, "morpion",couleur_icone);
    SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */

    position.x=300;
    position.y=0;

    police=TTF_OpenFont("BERNHC.ttf",110);
    texte = TTF_RenderText_Blended(police, "VS",couleur_icone);
    SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */



    position.x=60;
    position.y=100;

    police=TTF_OpenFont("BERNHC.ttf",20);
    texte = TTF_RenderText_Blended(police, "1.Jouer",couleur_text);
    SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */

    position.y=160;
    police=TTF_OpenFont("BERNHC.ttf",20);
    texte = TTF_RenderText_Blended(police, "2.quitter",couleur_text);
    SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */

    position.x=800;
    position.y=30;

    police=TTF_OpenFont("BERNHC.ttf",30);
    texte = TTF_RenderText_Blended(police, "Made by",couleur_icone);
    SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */

    position.x=700;
    position.y=100;

    police=TTF_OpenFont("BERNHC.ttf",30);
    texte = TTF_RenderText_Blended(police, "YABYOURE ERIC KABORE",couleur_text);
    SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */


    //mise à jour l'ecran
    SDL_Flip(ecran);

    }

    //enfin le main
    int main(int argc, char *argv[])
    {

    //initialisation



    SDL_Init(SDL_INIT_VIDEO);


    TTF_Init();

    SDL_WM_SetCaption("Morpion", NULL);
    SDL_WM_SetIcon(SDL_LoadBMP("image/icone.bmp"), NULL);



    menu_principal();

    //boucle générale du jeu

    while (continuer)//si continuer =0 on sort de la boucle

    {

    SDL_WaitEvent(&event);//on attend un evenement

    switch(event.type)
    {
        case SDL_QUIT:
        continuer = 0;
        break;

        case SDL_MOUSEBUTTONUP:
            {
               retour_menu=3;

                if(event.button.button==SDL_BUTTON_LEFT ||event.button.button==SDL_BUTTON_RIGHT)//clic droit ou clic gauche ca marche
                    {if(event.button.x>60 && event.button.x<260 && event.button.y>100&& event.button.y<120)//on compare les coordonnées du clic

                    while(retour_menu)//si retour_menu =0 on srt de la boucle
                    {
                        vidange_plateau();//on reinitialise toutes les variables du jeu
                        retour_menu=jeu(ecran);
                    }
};


                if(event.button.x>60 && event.button.x<120 && event.button.y>160 && event.button.y<180)
                {
                    continuer=0; //veut arrêter le jeu

                 }


            }break;
        case SDL_KEYDOWN:
            {switch(event.key.keysym.sym)
               {
                   case SDLK_ESCAPE: // Veut arrêter le jeu
                       continuer = 0;
                        break;
                }
            }break;
    }


    }

    // Effacement des surfaces en mémoire

    SDL_FreeSurface(imagefond);
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_Quit();
    exit (0);
    return EXIT_SUCCESS;
}
