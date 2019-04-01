#pragma once

#include "pch.h"
#include "FBullCowGame.h"
#include <map>

#define TMap std::map

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }    //no point of defining separately as its basically thr Reset function

void FBullCowGame::Reset()                   //does the work of a ctor by resetting(initializing) the values of our constants
{
	MyCurrentTry = 1;
	MyHiddenWord = "ace";
	GameWon = false;
}

int32 FBullCowGame::GetMaxTries() const 
{ 
   	TMap <int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,15}, {7,20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

int32 FBullCowGame::GetCurrentTry() const  { return MyCurrentTry; }
bool  FBullCowGame::IsGameWon()     const  { return GameWon;      }


bool FBullCowGame::IsLower(FString Guess) const
{
	for (auto Letter : Guess)
	{
		if (!islower(Letter)) { return false; }
	}
	return true;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString Guess)
{
	if (!IsIsogram(Guess))
		return EWordStatus::Not_Isogram;
	
	else if ( Guess.length()!=HiddenWordLength() )
		return EWordStatus::Invalid_Length;

	else if (!IsLower(Guess))
        return EWordStatus::Not_lowercase;
    else 
		return EWordStatus::OK;
}

int32 FBullCowGame::HiddenWordLength() const
{    
	return MyHiddenWord.length();
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;
    
	FBullCowCount BullCowCount;
	
	int32 MyHiddenWordLength = MyHiddenWord.length();
	
	for (int32 i = 0; i < MyHiddenWordLength; i++)
	{
		for (int32 j = 0; j < MyHiddenWordLength; j++)
		{
			if (Guess[j] == MyHiddenWord[i] && (i == j))
			     {BullCowCount.Bulls++;}

			else if(Guess[j]==MyHiddenWord[i]&&(i!=j))
			     {BullCowCount.Cows++;}
		}

		}
	
	if (BullCowCount.Bulls == MyHiddenWordLength)
		GameWon = true;
	else
		GameWon = false;
		
	return BullCowCount;

}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; }
	
	TMap <char, bool> LetterSeen;
	
	for (auto Letter : Word)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter])
			return false;
		else
			LetterSeen[Letter] = true;
	}
	
	return true;
}

