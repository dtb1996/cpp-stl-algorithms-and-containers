#pragma once

#include <string>
#include <string_view>
#include <vector>

namespace text
{
    // Normalize text by converting to lowercase and replacing non-alphanumeric characters with spaces
    std::string normalize(std::string_view input);

    // Split normalized text into individual words
    std::vector<std::string> tokenize(std::string_view normalized_text);
}