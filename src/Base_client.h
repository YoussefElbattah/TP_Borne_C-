#ifndef BASE_CLIENT_H
#define BASE_CLIENT_H
#include <vector>

/*! \class Base_client
* \brief classe representant la Base client de la borne
*
* la classe Base_client qui gére la Base client de la borne de charge
*/

class Base_client{
	int buff_client;
	std::vector<int> Numero_carte;

	public:
	Base_client();
	int authentifier(int numero_carte);
	void get_client();

};


#endif
