/*made by KABORE ERIC
  fonctions et sous-programmes qui sera seront appelés dans le main*/

#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

/*caze est une matrice carrée d'ordre 3, la corespondance du plateau sous forme de matrice pour pouvoir traiter l'algorithme du jeu,
le plateu plein permettra de savoir combien de case ont été cochés
la variable b de stocker la valeur de retour de la fonction victoire
la variable k la valeur renvoyée par la fonction victoire*/

int caze[3][3],plateau_plein;
int b=2,k,tour,retour=3,signaler_gagnant=0;



//fonction pour bloquer le programme en pause

void pause(int a)
{
    int tempsprecedent=0,tempsactuel=0,stop=2;
    SDL_Event event;
    tempsprecedent=SDL_GetTicks();
    while(stop!=0)
        {
            tempsactuel=SDL_GetTicks();
            if(tempsactuel- tempsprecedent>a)
             stop=0;


    SDL_PollEvent(&event);
    switch(event.type)
    {
    case SDL_NOEVENT:{if(tempsactuel- tempsprecedent>a)
             stop=0;
        }break;

    default:{
            if(tempsactuel- tempsprecedent>a)
             stop=0;
        }break;

    }
}
}

void tour_joueur(int a,int c,SDL_Surface *scre)//sous programme pour annoncer qui doit jouer et en cas de victoire le scintillement des cases alignées
{


    SDL_Surface *ima,*texte;
    SDL_Rect positionf,positionj;
    SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};
    positionj.x=0;
    positionj.y=0;
    int i,j;

    if( c!=1 && c!=2 && plateau_plein!=9)
    {

    switch(a) //affichage du joueur dont c'est le tour de jouer
    {
        case 1:{ima = SDL_LoadBMP("image/jouer1.bmp");
    SDL_BlitSurface(ima, NULL,scre, &positionj);
    SDL_Flip(scre);}break;

        case 2:{ima = SDL_LoadBMP("image/jouer2.bmp");
    SDL_BlitSurface(ima, NULL,scre, &positionj);
    SDL_Flip(scre);}break;
    }
    }
    else
    {
      ima = SDL_LoadBMP("image/stop.bmp");
    SDL_BlitSurface(ima, NULL,scre, &positionj);
    SDL_Flip(scre);

    switch(signaler_gagnant)//scintillement des cases caochée
    {
        case 1 :{


        j=0;
        while(j!=10)
        {
           j++;
        SDL_Delay(100);
           for(i=0;i<3;i++)
              {
                positionj.x=225;
                positionj.y=150+150*i;
                ima = SDL_LoadBMP("image/signaler1.bmp");
                SDL_BlitSurface(ima, NULL,scre, &positionj);
                SDL_Flip(scre);
              }

        SDL_Delay(100);
           for(i=0;i<3;i++)
              {
                positionj.x=225;
                positionj.y=150+150*i;
                ima = SDL_LoadBMP("image/signaler2.bmp");
                SDL_BlitSurface(ima, NULL,scre, &positionj);
                SDL_Flip(scre);
              }

            }

        }break;
        case 2:
            {

            j=0;
            while(j!=10)
              {
               j++;
               SDL_Delay(100);
               for(i=0;i<3;i++)
                 {
                   positionj.x=450;
                   positionj.y=150+150*i;
                   ima = SDL_LoadBMP("image/signaler1.bmp");
                   SDL_BlitSurface(ima, NULL,scre, &positionj);
                   SDL_Flip(scre);
                  }

               SDL_Delay(100);
               for(i=0;i<3;i++)
                 {
                   positionj.x=450;
                   positionj.y=150+150*i;
                   ima = SDL_LoadBMP("image/signaler2.bmp");
                   SDL_BlitSurface(ima, NULL,scre, &positionj);
                   SDL_Flip(scre);
                  }

               }

        }break;
        case 3:
            {
                j=0;
               while(j!=10)
               {

               j++;
               SDL_Delay(100);
               for(i=0;i<3;i++)
                 {
                   positionj.x=680;
                   positionj.y=150+150*i;
                   ima = SDL_LoadBMP("image/signaler1.bmp");
                   SDL_BlitSurface(ima, NULL,scre, &positionj);
                   SDL_Flip(scre);
                  }
               SDL_Delay(100);
               for(i=0;i<3;i++)
                 {
                   positionj.x=680;
                   positionj.y=150+150*i;
                   ima = SDL_LoadBMP("image/signaler2.bmp");
                   SDL_BlitSurface(ima, NULL,scre, &positionj);
                   SDL_Flip(scre);
                  }
               }

            }break;

        case 4:
            {
               j=0;
                while(j!=10)
                {
                    j++;
                    SDL_Delay(100);
                    for(i=0;i<3;i++)
                    {
                        positionj.y=110;
                        positionj.x=210+235*i;
                        ima = SDL_LoadBMP("image/signaler1.bmp");
                        SDL_BlitSurface(ima, NULL,scre, &positionj);
                        SDL_Flip(scre);
                    }
                    SDL_Delay(100);
                    for(i=0;i<3;i++)
                    {
                        positionj.y=110;
                        positionj.x=210+235*i;
                        ima = SDL_LoadBMP("image/signaler2.bmp");
                        SDL_BlitSurface(ima, NULL,scre, &positionj);
                        SDL_Flip(scre);
                    }
                }

                }break;

        case 5:
            {
                j=0;
                while(j!=10)
                {
                    j++;
                    SDL_Delay(100);
                    for(i=0;i<3;i++)
                       {
                        positionj.y=450;
                        positionj.x=210+235*i;
                        ima = SDL_LoadBMP("image/signaler1.bmp");
                        SDL_BlitSurface(ima, NULL,scre, &positionj);
                        SDL_Flip(scre);
                       }
                    SDL_Delay(100);
                    for(i=0;i<3;i++)
                       {
                        positionj.y=450;
                        positionj.x=210+235*i;
                        ima = SDL_LoadBMP("image/signaler2.bmp");
                        SDL_BlitSurface(ima, NULL,scre, &positionj);
                        SDL_Flip(scre);
                       }
                }


            }break;
        case 6 :
            {
                j=0;
                while(j!=10)
                {
                    j++;
                    SDL_Delay(100);
                   for(i=0;i<3;i++)
                      {
                        positionj.y=125+160*i;
                        positionj.x=225+235*i;
                        ima = SDL_LoadBMP("image/signaler1.bmp");
                        SDL_BlitSurface(ima, NULL,scre, &positionj);
                        SDL_Flip(scre);
                       }
                    SDL_Delay(100);
                   for(i=0;i<3;i++)
                      {
                        positionj.y=125+160*i;
                        positionj.x=225+235*i;
                        ima = SDL_LoadBMP("image/signaler2.bmp");
                        SDL_BlitSurface(ima, NULL,scre, &positionj);
                        SDL_Flip(scre);
                       }
                }


            }break;
        case 7:
            {
                j=0;
                SDL_Delay(100);
                while(j!=10)
                {
                    j++;
                    SDL_Delay(100);
                    for(i=0;i<3;i++)
                      {
                        positionj.y=125+160*i;
                        positionj.x=675-235*i;
                        ima = SDL_LoadBMP("image/signaler1.bmp");
                        SDL_BlitSurface(ima, NULL,scre, &positionj);
                        SDL_Flip(scre);
                        }
                    SDL_Delay(100);
                    for(i=0;i<3;i++)
                      {
                        positionj.y=125+160*i;
                        positionj.x=675-235*i;
                        ima = SDL_LoadBMP("image/signaler2.bmp");
                        SDL_BlitSurface(ima, NULL,scre, &positionj);
                        SDL_Flip(scre);
                        }
                }


            }break;
        case 8:
            {
                j=0;
                while(j!=10)
                {
                    j++;
                    SDL_Delay(100);
                    for(i=0;i<3;i++)
                      {
                        positionj.y=280;
                        positionj.x=210+235*i;
                        ima = SDL_LoadBMP("image/signaler1.bmp");
                        SDL_BlitSurface(ima, NULL,scre, &positionj);
                        SDL_Flip(scre);
                       }
                    SDL_Delay(100);
                    for(i=0;i<3;i++)
                      {
                        positionj.y=280;
                        positionj.x=210+235*i;
                        ima = SDL_LoadBMP("image/signaler2.bmp");
                        SDL_BlitSurface(ima, NULL,scre, &positionj);
                        SDL_Flip(scre);
                       }
                }


            }break;
    }


    }
}

//fontion pour reinitialiser les variables du jeu
void vidange_plateau()
{
    int i,j;
    plateau_plein=0;
    b=5;
    k=3;
    tour=1;
    retour=3;
    signaler_gagnant=0;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            caze[i][j]=0;

    }
}

// fonction  pour afficher les croix et les images de resultats

void afficher(int a,int u,int v,SDL_Surface  *ima,SDL_Surface  *scre)
{

    SDL_Rect positiondecroix;
    positiondecroix.x=u;
    positiondecroix.y=v;
    switch(a)
    {
        case 1:{ima = SDL_LoadBMP("image/Croix.bmp");
    SDL_BlitSurface(ima, NULL,scre, &positiondecroix);
    SDL_Flip(scre);}break;

        case 2:{ima = SDL_LoadBMP("image/Croix2.bmp");
    SDL_BlitSurface(ima, NULL,scre, &positiondecroix);
    SDL_Flip(scre);}break;
        case 3:{ima = SDL_LoadBMP("image/victoire1.bmp");
    SDL_BlitSurface(ima, NULL,scre, &positiondecroix);
    SDL_Flip(scre);}break;
        case 4:{ima = SDL_LoadBMP("image/victoire2.bmp");
    SDL_BlitSurface(ima, NULL,scre, &positiondecroix);
    SDL_Flip(scre);}break;
        case 5:{ima = SDL_LoadBMP("image/egalite.bmp");
    SDL_BlitSurface(ima, NULL,scre, &positiondecroix);
    SDL_Flip(scre);}break;
    }

}


//fonction pour tester la victoire et renvoyer une valeur en conséguence. elle traite aussi une variable pour savoir qu'elle sont les cases cochées.

int victoire ()
{

    if(   (caze[0][0]==caze[0][1]) && (caze[0][1]==caze[0][2]) )
        {

            if(caze[0][2]==1)
              {k=1;
              signaler_gagnant=1;}
         else if(caze[0][2]==2)
              {k=2;
               signaler_gagnant=1;}}
    if( (caze[1][0]==caze[1][1]) && (caze[1][1]==caze[1][2]) )
        {if(caze[1][2]==1)
            {k=1;
            signaler_gagnant=2;}
         else if(caze[1][2]==2)
                {k=2;
                signaler_gagnant=2;}
                }
    if( (caze[2][0]==caze[2][1]) && (caze[2][1]==caze[2][2]) )
        {if(caze[2][2]==1)
          {k=1;
          signaler_gagnant=3;}
            else if(caze[2][2]==2)
                {k=2;
                signaler_gagnant=3;}}
    if( (caze[0][0]==caze[1][0]) && (caze[1][0]== caze[2][0]) )
        {if(caze[2][0]==1)
          {k=1;
          signaler_gagnant=4;}
            else if(caze[2][0]==2)
                {k=2;
                signaler_gagnant=4;}}
    if( (caze[0][1]==caze[1][1]) && (caze[1][1]==caze[2][1]) )
        {if(caze[2][1]==1)
          {k=1;
          signaler_gagnant=8;}
            else if(caze[2][1]==2)
                {k=2;
                signaler_gagnant=8;}}
    if( (caze[0][2]==caze[1][2]) && (caze[1][2]==caze[2][2]) )
         {if(caze[2][2]==1)
           {k=1;
           signaler_gagnant=5;}
            else if(caze[2][2]==2)
                {k=2;
                signaler_gagnant=5;}}
    if( (caze[0][0]==caze[1][1]) && (caze[1][1]==caze[2][2]) )
        {if(caze[2][2]==1)
          {k=1;
          signaler_gagnant=6;}
            else if(caze[2][2]==2)
                {k=2;
                signaler_gagnant=6;}}
    if( (caze[2][0]==caze[1][1]) && (caze[1][1]==caze[0][2]) )
        {if(caze[0][2]==1)
          {k=1;
          signaler_gagnant=7;}
            else if(caze[0][2]==2)
                {k=2;
                signaler_gagnant=7;}}


      return (k);
}

//fonction pour lancer le jeu

int jeu(SDL_Surface  *screen)
{


    SDL_Surface *image,*texte;
    SDL_Rect positionf,position;
    SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {200, 100, 50};


    positionf.x=0;
    positionf.y=0;

    image = SDL_LoadBMP("image/plateau.bmp");
    SDL_BlitSurface(image, NULL,screen, &positionf);
    SDL_Flip(screen);
    positionf.x=150;
    positionf.y=75;
    image = SDL_LoadBMP("image/PlateauVide.bmp");
    SDL_BlitSurface(image, NULL,screen, &positionf);

    SDL_Flip(screen);


    tour_joueur(tour,3,screen);

    while( b!=1 && b!=2 && plateau_plein<9)

    {


    SDL_WaitEvent(&event);
    switch(event.type)
    {

        case SDL_MOUSEBUTTONUP://gestion du clic de la souris
            {




            if(event.button.button==SDL_BUTTON_LEFT ||event.button.button==SDL_BUTTON_RIGHT)//clic droit ou clic gauche
             {


          //où le clic a été effectué?


                 if(event.button.x>150 && event.button.x<383 && event.button.y>75 && event.button.y<241 && (caze[0][0]==0))

                     {caze[0][0]=tour;
                        afficher(tour,150,75,image,screen);

                        plateau_plein=plateau_plein+1;
                        tour=tour+1;


                 if(tour==3)
                    tour=1;

                    tour_joueur(tour,victoire(),screen);

                        }
                 if(event.button.x>150 && event.button.x<383 && event.button.y>241 && event.button.y<407 && (caze[0][1]==0) )

                        {caze[0][1]=tour;
                            afficher(tour,150,241,image,screen);
                            plateau_plein=plateau_plein+1;

                            tour=tour+1;
                 if(tour==3)
                    tour=1;

                    tour_joueur(tour,victoire(),screen);}
                if(event.button.x>150 && event.button.x<383 && event.button.y>407 && event.button.y<573 && (caze[0][2]==0) )

                          {caze[0][2]=tour;
                           afficher(tour,150,407,image,screen);
                           plateau_plein=plateau_plein+1;

                           tour=tour+1;
                 if(tour==3)
                    tour=1;
                    tour_joueur(tour,victoire(),screen);}
                if(event.button.x>383 && event.button.x<616 && event.button.y>75 && event.button.y<241 && (caze[1][0]==0) )

                           {caze[1][0]=tour;
                            afficher(tour,383,75,image,screen);
                            plateau_plein=plateau_plein+1;

                            tour=tour+1;
                 if(tour==3)
                    tour=1;
                    tour_joueur(tour,victoire(),screen);}

                if(event.button.x>383 && event.button.x<616 && event.button.y>241 && event.button.y<407 && (caze[1][1]==0))


                           {caze[1][1]=tour;
                            afficher(tour,383,241,image,screen);
                            plateau_plein=plateau_plein+1;

                            tour=tour+1;
                 if(tour==3)
                    tour=1;
                    tour_joueur(tour,victoire(),screen);}

                if(event.button.x>383 && event.button.x<616 && event.button.y>407 && event.button.y<573 && (caze[1][2]==0))

                           {caze[1][2]=tour;
                            afficher(tour,383,407,image,screen);
                            plateau_plein=plateau_plein+1;

                            tour=tour+1;
                 if(tour==3)
                    tour=1;
                    tour_joueur(tour,victoire(),screen);}

            if(event.button.x>616 && event.button.x<849 && event.button.y>75 && event.button.y<241 && (caze[2][0]==0) )

                           {caze[2][0]=tour;
                            afficher(tour,616,75,image,screen);
                            plateau_plein=plateau_plein+1;

                            tour=tour+1;
                 if(tour==3)
                    tour=1;
                    tour_joueur(tour,victoire(),screen);}

         if(event.button.x>616 && event.button.x<849 && event.button.y>241 && event.button.y<407 && (caze[2][1]==0) )


                           {caze[2][1]=tour;
                            afficher(tour,616,241,image,screen);
                            plateau_plein=plateau_plein+1;

                            tour=tour+1;
                 if(tour==3)
                    tour=1;
                    tour_joueur(tour,victoire(),screen);}


            if(event.button.x>616 && event.button.x<849 && event.button.y>407 && event.button.y<573 && (caze[2][2]==0) )

                           {caze[2][2]=tour;
                            afficher(tour,616,407,image,screen);
                            plateau_plein=plateau_plein+1;

                            tour=tour+1;
                 if(tour==3)
                    tour=1;
                    tour_joueur(tour,victoire(),screen);}

                 b=victoire(1);
            }
    }
        case SDL_KEYDOWN:
          {switch(event.key.keysym.sym)
            {
              case SDLK_ESCAPE: // Veut arrêter le jeu
                   exit (0);
                  break;
             }
           }break;
        case SDL_QUIT:
        exit (0);
        break;



    }//pour fermer switch



    };//pour fermer le while

    pause(3000); // mettre le grogramme en pause

    afficher(b+2,0,0,image,screen);


    position.x=0;
    position.y=550;

     police=TTF_OpenFont("BERNHC.ttf",30);
    texte = TTF_RenderText_Blended(police, " Voulez-vous rejouer? oui / non",couleurNoire);
    SDL_BlitSurface(texte, NULL, screen, &position); /* Blit du texte */
    SDL_Flip(screen);
     pause(3);

    pause(3000);
    while(retour!=0 && retour!=1)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_MOUSEBUTTONUP:
            {
                 if(event.button.x>310 && event.button.x<360 && event.button.y>550 && event.button.y<600 )
                 {
                     retour=0;  // 0 pour quitter
                     menu_principal();//affichage du menu principal
                 }
                 if(event.button.x>250 && event.button.x<300 && event.button.y>550 && event.button.y<600 )
                 {
                     retour=1;//   1 pour continuer
                 }

            }break;
        case SDL_KEYDOWN:
        {switch(event.key.keysym.sym)
        {
        case SDLK_ESCAPE: // Veut arrêter le jeu
        exit (0);
        break;
        }
        }break;
        case SDL_QUIT:
        exit (0);
        break;


            }
    }
        SDL_FreeSurface(image);
        SDL_FreeSurface(screen);




return (retour);
}
