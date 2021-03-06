// RockPaperScissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Input.h"
#include "Messager.h"
#include "AI.h"
#include <stdio.h>

int main()
{
	const char NEWLINE = '\n';
	char input;

	PrintHeader();
	PrintInstructions();
	
	do
	{		
		input = getchar();

		if (input == NEWLINE)
		{
			continue;
		}

		if (!Validate(input))
		{
			PrintInvalidInput();
			PrintInstructions();
			continue;
		}

		Shoot shoot = ProcessInput(input);
		Shoot aiShoot = GenerateShoot();

		PrintAIChose(aiShoot.Type);

		if (shoot == aiShoot)
		{
			PrintDraw();
		}

		if (shoot > aiShoot)
		{
			PrintWin();
		}

		if (shoot < aiShoot)
		{
			PrintLose();
		}

		PrintGoAgain();

	} while (true);
}