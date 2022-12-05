#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <typeinfo>

using namespace std;

pair<std::map<char, char>, std::map<char, char> > initialize_mappings() {
  std::map<char, char> win_mapping;
  std::map<char, char> opponent_mapping;
  win_mapping['X'] = 'C';
  win_mapping['Z'] = 'B';
  win_mapping['Y'] = 'A';
  opponent_mapping['X'] = 'A';
  opponent_mapping['Y'] ='B';
  opponent_mapping['Z'] = 'C';
  return std::make_pair(win_mapping, opponent_mapping);
}

std::map<char, int> initialize_point_mapping() {
  std::map<char, int> point_mapping;
    point_mapping.insert(pair<char, int>('X', 1));
    point_mapping.insert(pair<char, int>('Y', 2));
    point_mapping.insert(pair<char, int>('Z', 3));
    return point_mapping;
}

int main () {
  pair<std::map<char, char>, std::map<char, char> > maps = initialize_mappings();
  std::map<char, char> win_map = maps.first;
  std::map<char, char> opponent_map = maps.second;
  std::map<char, int> point_map = initialize_point_mapping();
  string line;
  int score = 0;
  ifstream content("input.txt");
  while (getline(content, line)) {
    std::istringstream iss(line);
    char a,b;
    iss >> a >> b;
    cout << a << " " << b;
    if (win_map.at(b) == a ) {  // I won.
      score += 6 + point_map[b];
      cout << " win" << std::endl;
    } else if (opponent_map.at(b) == a) {  // Draw.
      score += 3 + point_map[b];
      cout << " draw" << std::endl;
    } else {  // I lost.
      score += point_map[b];
      cout << " lose" << std::endl;
    }
  }
  cout << "I got a score of " << score << " points!" << std::endl;
  return 0;
}