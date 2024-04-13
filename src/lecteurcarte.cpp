
/**
* \file lecteurcarte.cpp
* \brief Definition des methodes de la classe lecteurcarte
* \authors ELBATTAH et SAPIN-CAPEL
* \date 11 avril 2024
*
* Definition des methodes de la classe lecteurcarte qui est chargée de la lecture de la carte 
*
*/

#include <unistd.h>
#include "lecteurcarte.h"
#include <lcarte.h>
#include <iostream>

/**
 * @brief Construct a new Lecteur Carte:: Lecteur Carte object
 * 
 */
LecteurCarte::LecteurCarte()
{
        numero = 0;
        carte_existe = 0;
}

/**
 * @brief méthode pour lire le numero de la carte et le renvoyer
 * 
 * @return int : numerode la carte
 */
int LecteurCarte::lire_carte()
{
        if(carte_existe == 1){
            attente_insertion_carte();
            if(carte_inseree()){
                    numero = lecture_numero_carte();
                    std::cout<< "numero lu : " << numero<< std::endl;
                    attente_retrait_carte();
                    return numero;
            }
        }
        else{
            std::cout<<"rentrer le numero de la carte"<<std::endl;
            std::cin>>numero;
            std::cout<< "numero lu : " << numero<< std::endl;
        }
        return numero;
}


