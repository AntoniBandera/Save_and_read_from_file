#include "Student.hpp"
#include <fstream>
#include <iostream>
#include <vector>

int main() {
  //it was added
  //3
  std::vector<Student> v;
  v.push_back(Student(1, "Kowalska1", "Anna1"));
  v.push_back(Student(2, "Kow2", "Anna2"));
  v.push_back(Student(3, "Kowalska3", "Anna3"));
  v.push_back(Student(4, "Kowalska4", "Anna4"));

  // save to file
  std::ofstream out_file("./data.txt");
  for (auto z : v) {
    out_file << z.getIndex() << std::endl << z.getName() << std::endl << z.getSurname() << std::endl;
  }
  out_file.close();
  // read from file
  std::vector<Student> v2;
  std::ifstream input_file("./data.txt");
  if (input_file.is_open()) {
    int a;
    std::string b, c;
    while (input_file >> a >> b >> c) {
      v2.push_back(Student(a, b, c));
    }
    input_file.close();
  } else {
    std::cout << "Unable to open file";
  }
  // print data read from file and added to vector
  for (auto z : v2) {
    std::cout << z.getIndex() << " " << z.getSurname() << " " << z.getName() << std::endl;
  }
  return 0;
}
