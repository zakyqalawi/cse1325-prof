#include "direction.h"
#include <iostream>
#include <sstream>
#include <vector>

/*
 Test Coordinate class

 @author      George F. Rice
 @copyright   Copyright 2017-2019
 @version     2.0

 This file is part of Roving Robots.

 Roving Robots is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 Roving Robots is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with Foobar.  If not, see <https://www.gnu.org/licenses/>.
*/ 
 
int main() {
  int result = 0;      // Set to non-zero code if failed
  int test_vector = 1; // Bitmask for calculating codes

  {
  ///////////////////////////////////
  // Coordinate static initialization
  std::string expected = "(0,0)  (0,3)  (0,6)  (2,0)  (2,3)  (2,6)  (4,0)  (4,3)  (4,6)  ";
  std::ostringstream actual;

  for(int x = 0; x < 3; ++x) {
    for(int y = 0; y < 3; ++y) {
      Coordinate c(x*2, y*3);
      actual << c << "  ";
    }
  }

  if (expected != actual.str()) {
    std::cerr << "FAIL: Coordinate static initialization" << std::endl;
    std::cerr << "  Expected: \"" << expected << '"' << std::endl;
    std::cerr << "  Actual:   \"" << actual.str() << '"' << std::endl << std::endl;
    result |= test_vector;  // Fail this test vector
  }
  test_vector <<= 1;
  }{
  // ////////////////////////////////
  // Coordinate random initialization
  std::string expected = "(13,16)  (27,25)  (23,25)  (16,12)  (9,1)  (2,7)  (20,19)  (23,16)  (0,6)  ";
  std::ostringstream actual;
  for(int i = 0; i < 9; ++i) {
    Coordinate c;
      actual << c << "  ";
  }

  if (expected != actual.str()) {
    std::cerr << "FAIL: Coordinate random initialization" << std::endl;
    std::cerr << "  Expected: \"" << expected << "\"" << std::endl;
    std::cerr << "  Actual:   \"" << actual.str() << "\"" << std::endl << std::endl;
    result |= test_vector;  // Fail this test vector
  }
  test_vector <<= 1;
  }{
  // ////////////////////////////////
  // Coordinate moving in a Direction
  std::string expected = "(10,9)  (9,9)  (10,10)  ";
  Direction up{0,-1};
  Direction left{-1,0};
  Direction diag{1,1};
  std::vector<Direction> path{up, left, diag};

  std::ostringstream actual;
  Coordinate c{10,10};
  for(Direction& d : path) {
      c = c + d;
      actual << c << "  ";
  }

  if (expected != actual.str()) {
    std::cerr << "FAIL: Coordinate moving in a direction" << std::endl;
    std::cerr << "  Expected: \"" << expected << "\"" << std::endl;
    std::cerr << "  Actual:   \"" << actual.str() << "\"" << std::endl << std::endl;
    result |= test_vector;  // Fail this test vector
  }
  test_vector <<= 1;
  }

  if (result) std::cerr << "FAIL: Code " << result << std::endl;
  return result;


}
