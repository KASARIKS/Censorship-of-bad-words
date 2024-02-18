#pragma once
#include <iostream>
#include <vector>
#include <fstream>

namespace Censer
{
	enum Status { Normal, Bad };
	const std::string bad_words_file = "bad_words.txt";
	
	// Count of words differnt statuses
	class CountStatus
	{
	private:
		int count_normal, count_bad;
	public:
		CountStatus();
		void PlusNormal(void);
		void PlusBad(void);
		int GetNormal(void);
		int GetBad(void);
	};

	// Keep word and status
	class Word
	{
	private:
		std::string word;
		Status status;
	public:
		Word(std::string word, Status status);
		std::string GetWord(void);
		Status GetStatus(void);
	};

	// Keep a part of text, words of this part.
	class TextPart
	{
	private:
		std::string text;
		std::vector<Word> words;
	public:
		TextPart(std::string text);
		std::string GetText(void);
		std::vector<Word> GetWords(void);
	};

	// Keep file and number of differnt statuses
	class Text
	{
	private:
		std::ofstream out;
		std::ifstream in;
		CountStatus count_status;
	public:
		Text(std::string out_name, std::string in_name);
		~Text();
		bool WritePath(void); // Return false if eof
	};
}