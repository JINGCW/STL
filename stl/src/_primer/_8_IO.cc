#include <iostream>
#include <sstream>
#include <fstream>
#include <ostream>
#include <string>
#include "_8_IO.h"

using namespace std;

void manage_io_state(istream &is) {
    is.setstate(is.rdstate() & ~is.failbit & ~is.badbit);
//    cin.tie(nullptr);
}

void save_person_info() {
//    ifstream in;
    string line, word;
    vector<person_info> people;

//    in.open(file_path);
    while (getline(cin, line)) {
        if (line == "no") {
            break;
        }
        person_info info;
        istringstream record(line);
        record >> info.name;
        while (record >> word) {
            info.phones.push_back(word);
        }
        people.push_back(info);
//        for (const auto& i:people) {
//            cout << i.name << endl;
//        }
    }
    for (const auto& entry:people) {
//        ostringstream formatted, bad_nums;
//        for (const auto &nums:entry.phones) {
//            if () {
//
//            }
//        }
        cout << entry.name << endl;
    }
//    in.close();
}
