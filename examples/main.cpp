#include "text_processing.h"
#include "top_words.h"
#include "word_counter.h"

#include <fstream>
#include <iostream>
#include <iterator>

int main(int argc, char* argv[]) {
    if (argc < 3)
    {
        std::cout << "Usage: " << argv[0] << " <text-file> <top-n>\n";
        return 1;
    }

    const std::string filename = argv[1];
    size_t top_n = 0;

    try
    {
        top_n = std::stoul(argv[2]);
    }
    catch (const std::exception&)
    {
        std::cerr << "Invalid number for top-n: " << argv[2] << "\n";
        return 1;
    }

    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Failed to open file: " << filename << "\n";
        return 1;
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    if (content.empty())
    {
        std::cerr << "File is empty: " << filename << "\n";
        return 1;
    }

    const auto normalized = text::normalize(content);
    const auto words = text::tokenize(normalized);

    const auto wordCounts = word_count::count_unordered(words);

    std::vector<top_words::WordCountPair> wordPairs;
    wordPairs.reserve(wordCounts.size());

    for (const auto& [word, count] : wordCounts)
    {
        wordPairs.emplace_back(word, count);
    }

    const auto topWords = top_words::extract_top_n(wordPairs, top_n);

    for (const auto& [word, count] : topWords)
    {
        std::cout << word << " : " << count << '\n';
    }
    
    return 0;
}
