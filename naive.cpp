#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

void do_cnt(int len)
{
	std::string word;
	std::unordered_map<std::string, int> stat;
	while (std::getline(std::cin, word)) {
		if ((int) word.size() >= len)
			++stat[word.substr(word.size() - len)];
	}
	std::vector<std::pair<int, std::string>> vec;
	for (auto& p : stat)
		vec.emplace_back(p.second, p.first);
	std::sort(vec.begin(), vec.end(), std::greater<decltype(vec)::value_type>());
	// for (int i = 0; i < std::min<int>(10, vec.size())) {
	//     auto& p = vec[i];
	for (auto& p : vec)
		std::cout << p.first << '\t'
			<< p.second << std::endl;
	// }
}

void do_suffix(std::string suf)
{
	std::string word;
	std::vector<std::string> vec;
	while (std::getline(std::cin, word)) {
		if (word.size() >= suf.size() &&
				std::equal(word.begin() + (word.size() - suf.size()),
					word.end(),
					suf.begin()))
			vec.push_back(word);
	}
	std::sort(vec.begin(), vec.end(), std::greater<decltype(vec)::value_type>());
	for (auto& word : vec)
		std::cout << word << std::endl;
}


int main(int argc, char **argv)
{
	if (argc < 2) {
		return -1;
	} else {
		if (std::isdigit(argv[1][0])) {
			do_cnt(std::atoi(argv[1]));
		} else {
			do_suffix(argv[1]);
		}
	}
	return 0;
}
