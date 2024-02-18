#include "Censer.h"
#include <algorithm>

namespace Censer
{
	// CountStatus methods
	CountStatus::CountStatus()
	{
		count_bad = count_normal = 0;
	}
	void CountStatus::PlusNormal(void)
	{
		++count_normal;
	}
	void CountStatus::PlusBad(void)
	{
		++count_bad;
	}
	int CountStatus::GetNormal(void)
	{
		return count_normal;
	}
	int CountStatus::GetBad(void)
	{
		return count_bad;
	}

	// TextPart methods
	TextPart::TextPart(std::string text)
	{
		// Check in word file
		std::ifstream bad_file(bad_words_file);
		std::string tmp_bad;

		while (!bad_file.eof())
		{
			bad_file >> tmp_bad;
			if (tmp_bad == text)
				std::reverse(text.begin(), text.end());
		}

		this->text = text;
	}

	std::string TextPart::GetText(void)
	{
		return text;
	}

	std::vector<Word> TextPart::GetWords(void)
	{
		return words;
	}

	// Word methods
	Word::Word(std::string word, Status status)
	{
		this->word = word;
		this->status = status;
	}

	std::string Word::GetWord(void)
	{
		return word;
	}

	Status Word::GetStatus(void)
	{
		return status;
	}

	Text::Text(std::string out_name, std::string in_name)
	{
		out.open(out_name);
		in.open(in_name);
	}

	Text::~Text()
	{
		out.clear();
		out.close();
		in.clear();
		in.close();
	}

	bool Text::WritePath(void)
	{
		if (!in.eof())
		{
			std::string text;
			in >> text;
			TextPart text_part(text);
			out << text_part.GetText() << " ";

			return true;
		}

		return false;
	}

}