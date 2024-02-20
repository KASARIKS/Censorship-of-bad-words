#pragma once
#include <iostream>
#include <vector>
#include <fstream>

namespace Censer
{
	enum Status { Normal, Bad };
	const std::string bad_words_file("filter_banned_russian.txt");
	
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

	// Keep a part of text.
	class TextPart
	{
	private:
		std::string text;
	public:
		TextPart(std::string text);
		std::string GetText(void);
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