#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
	auto word_begin = begin(s);
	auto word_end = find(begin(s), end(s), ' ');
	vector<string> ans;

	while (word_end != end(s)) {
		ans.push_back(string(word_begin, word_end));
		word_begin = ++word_end;
		word_end = find(word_begin, end(s), ' ');
	}
	ans.push_back(string(word_begin, word_end));
	return (ans);
}

// int main() {
//   string s = "C Cpp Java Python";

//   vector<string> words = SplitIntoWords(s);
//   cout << words.size() << " ";
//   for (auto it = begin(words); it != end(words); ++it) {
//     if (it != begin(words)) {
//       cout << "/";
//     }
//     cout << *it;
//   }
//   cout << endl;
//   
//   return 0;
// }
