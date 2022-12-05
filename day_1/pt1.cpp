#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  string line;
  ifstream content("input.txt");
  int cals = 0;
  int i = 1;
  int max = 0;
  int max_elf = 0;
  while (getline(content, line)) {
  // Output the text from the file
    if (line == "") {
      if (cals > max) {
        max = cals;
        max_elf = i;
      }
      cals = 0;
      i++;
    } else {
      cals = cals + std::stoi(line);
    }
  }
  if (cals > max) {
    max = cals;
    max_elf = i;
  }
  cout << "Elf " << max_elf << " has the most calories at " << max << "\n";
  return 0;
}