
#include <string>			// Needed to process error messages
//#include <SDL.h>		// Always needs to be included for an SDL app
//#include <SDL_ttf.h>	// Used for loading fonts and rendering text
//#include <SDL_image.h>	// Used for loading and drawing sprites
//#include <SDL_mixer.h>	// Used for loading and playing audio files

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <XML\rapidxml_utils.hpp>
#include <XML\rapidxml_iterators.hpp>
#include <XML\rapidxml_print.hpp>
#include <XML\rapidxml_utils.hpp>

#define RESOURCE_PATH "../../res/"
#define RESOURCE_FILE(filename) (RESOURCE_PATH + (filename)).c_str()

void testXml(const std::string &filename) {
	rapidxml::file<> xmlFile(RESOURCE_FILE(filename));//carrega el fitxer xml amb la ruta especifcada
	rapidxml::xml_document<>doc;// crea un document que contindrà el DOM tree per l'XML
	doc.parse<0>(xmlFile.data());//parseja tot el contingut del fitxer carregat
	//la funcio data() retorna una cadena de caracters amb tot el que te larxiu
	rapidxml::xml_node<> *root_node = doc.first_node("difficultMode");

	std::cout << "Nmbre de la raiz: " << doc.first_node()->name() << "\n";//aqui tindria que imprimir:difficultMode
	//rapidxml::xml_node<> *pRoot = doc.first_node();//el rootelement es el prmier element del arxiu xml que sera el primer node: difficultMode

}
int main(void) {
	
	testXml("statsSnake");
	return 0;
}


/*rapidxml::xml_document<>doc;//declaro el xml document
std::ifstream file("statsSnake");//operacio d'entrada del xml
std::stringstream buffer;//permet entradas/sortides dels caracters a traves de intput/output
buffer << file.rdbuf();//movemos al buffer los datos del file
file.close();//
std::string content(buffer.str());
doc.parse<0>(&content[0]);*/

/*for (rapidxml::xml_node<> *node = root_node->first_node(""); node; node = node->next_sibling()) {
std::cout << ("Node: ",
node->first_attribute("numCol")->value()),
" - ",
node->first_attribute("numRow")->value();
}*/


/*std::cout << "Nmbre de la raiz: " << doc.first_node()->name() << "\n";//aqui tindria que imprimir:difficultMode
rapidxml::xml_node<> *pRoot = doc.first_node();//el rootelement es el prmier element del arxiu xml que sera el primer node: difficultMode

for (rapidxml::xml_node<> *pNode = pRoot->first_node("MODE"); pNode; pNode = pNode->next_sibling()) {
//bucle en el que recorres el primer node des de pRoot(difficultMOde) i tot els seus germans(sibilings
rapidxml::xml_attribute<> *pAttr = pNode->first_attribute();//declares els atributs: easy, medium, hard
std::cout << pAttr->name() << '-' << pAttr->value() << "\n";// imprmimeixes tots els valors dels elements de cada node amb atributs(numCol, num Rows...
}*/