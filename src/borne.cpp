
/**
* \file borne.cpp
* \brief c'est le fichier 'main' du projet
* \authors ELBATTAH et SAPIN-CAPEL
* \date 11 avril 2024
*
* c'est le fichier 'main' du projet c'est où on fait appel à toute les classes et executer le code principal
*
*/

#include <iostream>
#include <unistd.h>
#include "memoire_borne.h"
#include "donnees_borne.h"
#include "Voyants.h"
#include "boutons.h"
#include <lcarte.h>
#include "lecteurcarte.h"
#include "Base_client.h"
#include "Trappe.h"
#include "Charge.h"
int numero_current;     /*!< le numero de la carte du client qui est en train de charger son véhicule */ 
int carte_existe = 0;   /*!< cette variable est pour rendre le code génerique avec ou sans carte */ 
/**
 * @brief fonction pour retirer le véhicule en cas de fin de charge ou appui sur le bouton STOP
 * 
 * @param voyant objet pointeur de la classe Voyant
 * @param charge objet pointeur de la classe Charge
 */
void retirer_vehicule(Voyants *voyant, Charge *charge);
int main()
{
    LecteurCarte lecteurcarte;
    Base_client BC;
    Voyants voyant;
    Boutons bouton;
    Trappe trappe;
    Charge charge;

    while (1)
    {
        numero_current = lecteurcarte.lire_carte();
        if(BC.authentifier(numero_current)){
            std::cout<<"le client existe"<<std::endl;
            voyant.blink_charge(VERT);
            std::cout<<"appuyez sur le bouton charge avant que le temps ecoule"<<std::endl;
            if(bouton.attente_boutons(10) == SUCCESS){
                trappe.Open();
                /*  ETAT A  */
                voyant.set_voyant_charge(ROUGE);
                charge.set_pwm(DC);
                std::cout<<"branchez votre prise :)"<<std::endl;
                /*  FIN ETAT A  */
                while(charge.get_tension()!=9);
                std::cout<<"prise branchee :)"<<std::endl;
                /*  ETAT B  */
                voyant.set_voyant_prise(VERT);
                charge.set_pwm(AC_1K);
                trappe.Close();
                /*  FIN ETAT B  */
                while((charge.get_tension()!= 9) && !(bouton.get_bouton(STP)));
                if(bouton.get_bouton(STP)){
                    std::cout<<"bouton stop est appuie"<<std::endl;
                    retirer_vehicule(&voyant,&charge);
                }
                else if((charge.get_tension() == 9) && (charge.get_pwm() == AC_1K) ){
                    /*  ETAT C  */
                    charge.close_AC();
                    charge.set_pwm(AC_CL);
                    charge.set_pwm(AC_1K);
                    charge.close_AC();
                    /*  FIN ETAT C  */
                    while((charge.get_tension()!=6) && !(bouton.get_bouton(STP)));
                    if(bouton.get_bouton(STP)){
                        charge.set_pwm(DC);
                        std::cout<<"bouton stop est appuie"<<std::endl;
                        retirer_vehicule(&voyant,&charge);
                    }
                    else if((charge.get_tension() == 6) && (charge.get_pwm() == AC_1K) ){
                        /*  ETAT D  */
                        charge.set_pwm(AC_CL);
                        while((charge.get_tension()!=9) && !(bouton.get_bouton(STP)));
                        retirer_vehicule(&voyant,&charge);
                    }

                }
            }else{
                std::cout<<"refait la procedure"<<std::endl;
            }

        }
        else{
            std::cout<<"le client n'existe pas"<<std::endl;
            voyant.blink_defaut(ROUGE);
        }

}
}

void retirer_vehicule(Voyants *voyant, Charge *charge){
    int num; /*!< le numero de la carte du client inserée pour retirer le véhicule */
    charge->set_pwm(DC);
    charge->open_AC();
    if(carte_existe){
        attente_insertion_carte();
        if(carte_inseree()){
                num = lecture_numero_carte();
                std::cout<< "numero lu : " << num<< std::endl;
                attente_retrait_carte();
        }
    }else{
        std::cout<<"entrez le carte pour retirer le vehicule"<<std::endl;
        std::cin>>num;
    }
    while(num != numero_current){
        std::cout<<"fausse carte !! entrez à nouveau votre carte pour retirer le vehicule"<<std::endl;
        std::cin>>num;
        if(carte_existe){
        attente_insertion_carte();
        if(carte_inseree()){
            num = lecture_numero_carte();
            std::cout<< "numero lu : " << num<< std::endl;
            attente_retrait_carte();
        }
        }else{
            std::cout<<"entrez le carte pour retirer le vehicule"<<std::endl;
            std::cin>>num;
        }
    }
    std::cout<<"meme carte :)"<<std::endl;
    std::cout<<"retirez la prise :)"<<std::endl;
    while(charge->get_tension()!=12);
    std::cout<<"prise retiree :)"<<std::endl;
    voyant->set_voyant_prise(OFF);
    std::cout<<"bon voyage"<<std::endl;
    voyant->set_voyant_charge(OFF);
    voyant->set_voyant_trappe(OFF);
}
