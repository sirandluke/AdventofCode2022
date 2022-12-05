#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <typeinfo>

using namespace std;

std::map<char, char>initialize_mapping() {
  std::map<char, char> win_mapping;
  win_mapping['B'] = 'C';
  win_mapping['C'] = 'A';
  win_mapping['A'] = 'B';
  return win_mapping;
}

std::map<char, int> initialize_point_mapping() {
  std::map<char, int> point_mapping;
    point_mapping.insert(pair<char, int>('A', 1));
    point_mapping.insert(pair<char, int>('B', 2));
    point_mapping.insert(pair<char, int>('C', 3));
    return point_mapping;
}

int main () {
  std::map<char, char> win_map = initialize_mapping();
  std::map<char, int> point_map = initialize_point_mapping();
  string line;
  int score = 0;
  ifstream content("input.txt");
  while (getline(content, line)) {
    std::istringstream iss(line);
    char opponent_move,strategy;
    char my_move;
    iss >> opponent_move >> strategy;
    cout << opponent_move << " " << strategy;
    switch (strategy)
    {
    case 'Z':  // Win.
      my_move = win_map[opponent_move];
      cout << " win " << my_move;
      score += 6 + point_map[my_move];
      break;
    case 'X':  // Lose.
      my_move = win_map[win_map[opponent_move]];
      score += point_map[my_move];
      cout << " lose " << my_move;
      break;
    default:  //  Draw.
      score += 3 + point_map[opponent_move];
      cout << " draw " << opponent_move;
    }
    cout << " " << score << std::endl;
  }
  cout << "I got a score of " << score << " points!" << std::endl;
  return 0;
}