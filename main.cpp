#pragma once

#include "pch.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

//to make Unreal Friendly Syntax we used
using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetValidGuess();
void PlayGame();
void GameSummary();
bool PlayAgain();

FBullCowGame BCGame;

int main()
{
	PrintIntro();
	PlayGame();
    
	return 0;
}


void PrintIntro()
{
	std::cout << R"(
                               _                 _     _ _       
                              (_)               (_)   | (_)      
               _ __   ___ _ __ _ _ __   ___ _ __ _  __| |_ _ __  
              | '_ \ / _ \ '__| | '_ \ / _ \ '__| |/ _` | | '_ \ 
              | |_) |  __/ |  | | |_) |  __/ |  | | (_| | | |_) |
              | .__/ \___|_|  |_| .__/ \___|_|  |_|\__,_|_| .__/ 
              | |               | |                       | |    
              |_|               |_|                       |_|    
  
 )";
std::cout << "\n";

std::cout << R"(
                                                     __             
                                                    /\ \__          
            _____   _ __    __    ____     __    ___\ \ ,_\   ____  
           /\ '__`\/\`'__\/'__`\ /',__\  /'__`\/' _ `\ \ \/  /',__\ 
           \ \ \L\ \ \ \//\  __//\__, `\/\  __//\ \/\ \ \ \_/\__, `\
            \ \ ,__/\ \_\\ \____\/\____/\ \____\ \_\ \_\ \__\/\____/
             \ \ \/  \/_/ \/____/\/___/  \/____/\/_/\/_/\/__/\/___/ 
              \ \_\                                                 
               \/_/                                                 

              )";

std::cout << "\n";
  
std::cout << "\n\nBulls And Cows,A fun word Game\n";
std::cout << "You get " << BCGame.GetMaxTries() << " tries to guess a "<<BCGame.HiddenWordLength()<<" letter isogram\n";
std::cout << "LETS GO!";
std::cout << "\n\n";
}

FText GetValidGuess()
{
	EWordStatus st = EWordStatus::Invalid_Guess;
	FText guess = " ";
	
	do{
	      std::cout << "\n\nTry " << BCGame.GetCurrentTry() << " Enter your guess:" << std::endl;
		  std::getline(std::cin, guess);          
	  
		  st= BCGame.CheckGuessValidity(guess);
	
			switch (st)
			{
			case Not_Isogram: std::cout << "This is not an isogram \n\n";
				break;
			case Invalid_Length: std::cout << "Invalid Length of Guess \n\n";
				break;
			case Not_lowercase:  std::cout << "Not in lowercase \n\n";
				break;
			default: 
				break;
			}

	} while (st!= EWordStatus::OK);
	return guess;
}

void PlayGame()
{
	bool a = true;
	while(a)
	{
		while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= BCGame.GetMaxTries())
		{
			FText Guess = GetValidGuess();
			FBullCowCount BCC = BCGame.SubmitGuess(Guess);
			std::cout << "\nBulls: " << BCC.Bulls;
			std::cout << "  Cows: " << BCC.Cows << "\n" << std::endl;
		}

		GameSummary();
		a = PlayAgain();
		BCGame.Reset();
		PrintIntro();
	}
}

void GameSummary()
{
	if (BCGame.IsGameWon())
		std::cout << "YOU WON!!!!!! CONGRATULATIONS! :) \n\n";
	else
		std::cout << "Better Luck next time mate :/ \n\n";
}

bool PlayAgain()
{	FText response = "";
	std::cout << "You wanna try again? (yes/no) \n";
	std::getline(std::cin, response);

	if (response[0] == 'y' || response[0] == 'Y')
	{
		std::cout << "\n\n";
		return true;
	}
    std::cout << "\n\n";
	return false;
}
                    
                                                  //FINISH BY 31 MARCH !!