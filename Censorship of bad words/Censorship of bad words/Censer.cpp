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

			// Censering text
			int pos = text.find(tmp_bad);

			if (pos != std::string::npos)
			{
				for (int i = pos; i < pos + tmp_bad.length(); ++i)
					text[i] = '*';
			}
		}

		this->text = text;
	}

	std::string TextPart::GetText(void)
	{
		return text;
	}

	Text::Text(std::string out_name, std::string in_name)
	{
		out.open(out_name, std::ios::trunc);
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