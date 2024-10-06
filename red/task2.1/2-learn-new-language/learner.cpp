#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

class Learner {
 private:
    std::set<string> dict;

 public:
  int Learn(const vector<string>& words) {
    const size_t old_size = dict.size();
    for (const auto& word : words) {
      dict.insert(word);
    }
    return dict.size() - old_size;
  }

  vector<string> KnownWords() {
    return std::vector<string>(dict.begin(), dict.end());
  }
};

int main() {
  Learner learner;
  string line;
  while (getline(cin, line)) {
    vector<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word) {
      words.push_back(word);
    }
    cout << learner.Learn(words) << "\n";
  }
  cout << "=== known words ===\n";
  for (auto word : learner.KnownWords()) {
    cout << word << "\n";
  }
}
