#include "text_processing.h"

#include <algorithm>
#include <cctype>
#include <sstream>

namespace text
{
    std::string text::normalize(std::string_view input)
    {
        std::string result;
        result.reserve(input.size());

        for (char c : input)
        {
            if (std::isalnum(static_cast<unsigned char>(c)))
            {
                result.push_back(static_cast<char>(std::tolower(c)));
            }
            else
            {
                result.push_back(' ');
            }
        }

        return result;
    }

    std::vector<std::string> text::tokenize(std::string_view normalized_text)
    {
        std::vector<std::string> words;
        std::string text(normalized_text);
        std::istringstream stream(text);

        std::string word;
        while (stream >> word)
        {
            words.push_back(word);
        }

        return words;
    }
}
