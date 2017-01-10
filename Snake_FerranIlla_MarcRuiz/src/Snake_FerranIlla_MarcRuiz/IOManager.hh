#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <XML\rapidxml_utils.hpp>
#include <XML\rapidxml_iterators.hpp>
#include <XML\rapidxml_print.hpp>
#include <XML\rapidxml_utils.hpp>

int timeXML, speedXML, foodXML, incrementXML, wallXML;

void readDifficultyXml(int diff) {
	rapidxml::file<> xmlFile("../../res/test.xml"); //carrega el fitxer xml amb la ruta especifcada
	rapidxml::xml_document<>doc; // crea un document que contindrà el DOM tree per l'XML
	doc.parse<0>(xmlFile.data()); //parseja tot el contingut del fitxer carregat
								 //la funcio data() retorna una cadena de caracters amb tot el que te larxiu
	rapidxml::xml_node<> *pRoot = doc.first_node("difficultMode");

	std::string tmp, vI, aI, iI, wall; //temps, velocitat, aliments, increment, midaParets


	for (rapidxml::xml_node<> *pNode = pRoot->first_node("MODE"); pNode; pNode = pNode->next_sibling()) {
		rapidxml::xml_attribute<> *pAttr = pNode->first_attribute("difficult");
		std::string atr;
		atr = pAttr->value();
		if (atr == "facil" && diff == 0) { //easy difficulty
			rapidxml::xml_node<> *pWall = pNode->first_node("wallSize"); //agafo lstring de columnes i el guardo com un int
			wall = pWall->value();
			wallXML = atoi(wall.c_str());
			
			rapidxml::xml_node<> *pTemps = pNode->first_node("time");
			tmp = pTemps->value();
			timeXML = atoi(tmp.c_str());

			rapidxml::xml_node<> *pVel = pNode->first_node("vInicial");
			vI = pVel->value();
			speedXML = atoi(vI.c_str());

			rapidxml::xml_node<> *pAl = pNode->first_node("alimentsInicials");
			aI = pAl->value();
			foodXML = atoi(aI.c_str());

			rapidxml::xml_node<> *pInc = pNode->first_node("incrementAliments");
			iI = pInc->value();
			incrementXML = atoi(iI.c_str());
			break;
		}
		else if (atr == "medio" && diff == 1) { //normal difficulty
			rapidxml::xml_node<> *pWall = pNode->first_node("wallSize"); //agafo lstring de columnes i el guardo com un int
			wall = pWall->value();
			wallXML = atoi(wall.c_str());

			rapidxml::xml_node<> *pTemps1 = pNode->first_node("time");
			tmp = pTemps1->value();
			timeXML = atoi(tmp.c_str());
	
			rapidxml::xml_node<> *pVel1 = pNode->first_node("vInicial");
			vI = pVel1->value();
			speedXML = atoi(vI.c_str());

			rapidxml::xml_node<> *pAl1 = pNode->first_node("alimentsInicials");
			aI = pAl1->value();
			foodXML = atoi(aI.c_str());

			rapidxml::xml_node<> *pInc1 = pNode->first_node("incrementAliments");
			iI = pInc1->value();
			incrementXML = atoi(iI.c_str());
			break;

		}

		if (atr == "dificil" && diff == 2) { //hard difficulty
			rapidxml::xml_node<> *pWall = pNode->first_node("wallSize"); //agafo lstring de columnes i el guardo com un int
			wall = pWall->value();
			wallXML = atoi(wall.c_str());

			rapidxml::xml_node<> *pTemps = pNode->first_node("time");
			tmp = pTemps->value();
			timeXML = atoi(tmp.c_str());

			rapidxml::xml_node<> *pVel = pNode->first_node("vInicial");
			vI = pVel->value();
			speedXML = atoi(vI.c_str());

			rapidxml::xml_node<> *pAl = pNode->first_node("alimentsInicials");
			aI = pAl->value();
			foodXML = atoi(aI.c_str());

			rapidxml::xml_node<> *pInc = pNode->first_node("incrementAliments");
			iI = pInc->value();
			incrementXML = atoi(iI.c_str());
			break;
		}
	}

}

