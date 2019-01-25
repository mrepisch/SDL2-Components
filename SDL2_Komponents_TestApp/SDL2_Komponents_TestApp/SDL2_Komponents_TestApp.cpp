// SDL2_Komponents_TestApp.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#include "pch.h"
#include <iostream>
#include <Runtime.h>


int main(int, char **)
{
	Runtime run;
	run.init(480, 320, "TEST");
	run.start();
	run.close();

	return 0;
}
