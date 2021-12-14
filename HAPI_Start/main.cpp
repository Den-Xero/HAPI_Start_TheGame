/*
	HAPI Start
	----------
	This solution contains an already set up HAPI project and this main file
	
	The directory structure and main files are:

	HAPI_Start - contains the Visual Studio solution file (.sln)
		HAPI_Start - contains the Visual Studio HAPI_APP project file (.vcxproj) and source code
			HAPI - the directory with all the HAPI library files
			Data - a place to put your data files with a few sample ones provided

	Additionally in the top directory there is a batch file for creating a redistributable Demo folder

	For help using HAPI please see the Reference folder in the HAPI sub-directory
*/

// Include the HAPI header to get access to all of HAPIs interfaces
#include <HAPI_lib.h>
#include "World.h"


// HAPI itself is wrapped in the HAPISPACE namespace
using namespace HAPISPACE;

// Every HAPI program has a HAPI_Main as an entry point
// When this function exits the program will close down




//struct Positions
//{
//	float X, Y;
//};

void HAPI_Main()
{
	World World;

	World.Run();

	//Render Rend;
	//calls for initalise and setup
	/*if (!Rend.Initialise())
		return;*/

	/*Controls Con;*/
	

	////gets and checks the sprite
	//if (!Rend.GetSprite("BackGround", "Data\\background.tga"))
	//{
	//	HAPI.UserMessage("Missing Background tex", "Error");
	//	return;
	//}
	////gets and checks the sprite
	//if (!Rend.GetSprite("PlayerSprite", "Data\\alphathing.tga"))
	//{
	//	HAPI.UserMessage("Missing PlayerSprite", "Error");
	//	return;
	//}

	//getter
	/*Con.GetValues();*/
	//sets the playersprites position.
	/*Positions Pos{ 100, 200 };*/
	//while (HAPI.Update())
	//{
		//controller, rumble and keybord controls calls.
		//Con.KeyboardControls(Pos.X, Pos.Y);
		/*Con.XboxControls(Pos.X, Pos.Y);
		Con.Rumble(Pos.X, Pos.Y);*/
		//Calls the function to set the screen background colour.
		/*Rend.Setbackgroundcolour();*/
		//draws the sprites to the window.
		/*Rend.BackgroundRender("BackGround", 0, 0);*/
		/*Rend.PlayerSpriteRender("PlayerSprite", Pos.X, Pos.Y);*/

		/*Rend.PlayerSpriteRender("PlayerSprite", -25, 250);
		Rend.PlayerSpriteRender("PlayerSprite", -25, -25);
		Rend.PlayerSpriteRender("PlayerSprite", 1000, 500);
		Rend.PlayerSpriteRender("PlayerSprite", 500, 730);*/

	//}

}

