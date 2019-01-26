// SDL2_Komponents_TestApp.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#include "pch.h"
#include <iostream>
#include <Runtime.h>
#include "GameFactory.h"
#include "PathHelper.h"
#include "Player.h"
#include "Camera.h"
int main(int, char **)
{
	
	Runtime run;
	run.init(480, 320, "TEST");

	Camera* cam = new Camera();
	cam->setSpeed(20, 0);
	run.addCamera(cam);

	GameFactory fac;
	TMXMap* map = fac.loadTmxMap((PathHelper::getBasePath() + "\\..\\..\\testmap.tmx").c_str(), run.getRenderer());
	run.addIRenderObject(map);
	
	Player* player = fac.loadPlayer(map, run.getRenderer());
	if (player)
	{
		run.addIRenderObject(player);
		player->startAnim("idle");
		
	}
	
	
	run.start();
	run.close();

	return 0;
}
