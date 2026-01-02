#pragma once

#include <cstddef>
#include <string>
#include <utility>
#include <vector>

namespace top_words
{
    using WordCountPair = std::pair<std::string, std::size_t>;

    // Extract the top N most frequent words
    std::vector<WordCountPair> extract_top_n(const std::vector<WordCountPair>& vec, std::size_t n);
}