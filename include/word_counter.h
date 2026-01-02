#pragma once

#include <cstddef>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

namespace word_count
{
    using Word = std::string;
    using Count = std::size_t;

    using OrderedResult = std::map<Word, Count>;
    using UnorderedResult = std::unordered_map<Word, Count>;

    // Count words using std::map (ordered)
    OrderedResult count_ordered(const std::vector<Word>& words);

    UnorderedResult count_unordered(const std::vector<Word>& words);
}