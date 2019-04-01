#pragma once
#include<string>

using FString = std::string;
using int32 = int;

enum EWordStatus 
{  
	Invalid_Guess,
	OK,
	Not_Isogram,
	Invalid_Length,
	Not_lowercase

};

struct FBullCowCount 
{ 
	int32 Bulls = 0, Cows = 0;
};

class FBullCowGame {

public: 
	FBullCowGame();
     	
		int32  GetMaxTries() const;
		int32  GetCurrentTry() const;
		int32  HiddenWordLength() const;
		bool   IsGameWon() const;
		
		void Reset();
	    
		enum EWordStatus CheckGuessValidity(FString);
		
		FBullCowCount SubmitGuess(FString);
		

private:
		int32 MyCurrentTry;
		FString MyHiddenWord;
		bool GameWon;

		bool   IsIsogram(FString Word) const;
		bool   IsLower(FString Guess) const;


};  