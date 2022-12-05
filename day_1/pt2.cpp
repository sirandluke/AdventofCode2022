#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main () {
  string line;
  vector<int> elves;
  ifstream content("input.txt");
  int cals = 0;
  int total = 0;
  while (getline(content, line)) {
  // Output the text from the file
    if (line == "") {
      elves.push_back(cals);
      cals = 0;
    } else {
      cals = cals + std::stoi(line);
    }
  }
  elves.push_back(cals);
  for (int i = 0; i < 3; i++) {
    std::make_heap(elves.begin(), elves.end());
    std::pop_heap(elves.begin(), elves.end());
    total += elves.back();
    elves.pop_back();
  }
  
  cout << total << '\n';
  return 0;
}