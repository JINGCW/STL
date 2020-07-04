#include "utils.h"
//#include "_7_class.h"
#include "_6_function.h"
#include "_8_IO.h"
#include "_9_sequential_container.h"
#include "_12_dy_mem.h"
#include "_17_stdlib.h"

//
EXPORT_API void mini_text_query()
{
    ifstream file("test.txt");
    TextQuery tq(file);
    string input;
    cout <<
    "___________              __    ________                               __________                                           .__                \n"
    "\\__    ___/___ ___  ____/  |_  \\_____  \\  __ __   ___________ ___.__. \\______   \\_______  ____   ________________    _____ |__| ____    ____  \n"
    "  |    |_/ __ \\\\  \\/  /\\   __\\  /  / \\  \\|  |  \\_/ __ \\_  __ <   |  |  |     ___/\\_  __ \\/  _ \\ / ___\\_  __ \\__  \\  /     \\|  |/    \\  / ___\\ \n"
    "  |    |\\  ___/ >    <  |  |   /   \\_/.  \\  |  /\\  ___/|  | \\/\\___  |  |    |     |  | \\(  <_> ) /_/  >  | \\// __ \\|  Y Y  \\  |   |  \\/ /_/  >\n"
    "  |____| \\___  >__/\\_ \\ |__|   \\_____\\ \\_/____/  \\___  >__|   / ____|  |____|     |__|   \\____/\\___  /|__|  (____  /__|_|  /__|___|  /\\___  / \n"
    "             \\/      \\/               \\__>           \\/       \\/                              /_____/            \\/      \\/        \\//_____/  "
    << endl;
    cout << "Welcome to Mini TextQuery Program!\n"
         << "-------------------------------\n"
         << "You can enter the word you want to search...."
         << endl;
    while (cin >> input)
    {
        if (input == "exit")
            break;
        print(cout, tq.query(input));
    }
}


double Math::add(double a, double b)
{
    return a + b;
}

double Math::mul(double a, double b)
{
    return a * b;
}
//void stores_sales_search()
//{
//    string file_path = "stores_sales_search.txt";
//    vector<vector<Sales_data>> *_files = _read_files_from_txt(file_path);
//
//    cout << "input the store book you want to search...\n"
//            "-------------------------------" << endl;
//    if (_files->empty())
//        cout << "_files is empty" << endl;
//    else
//        cout << "_files is not empty" << endl;
//
//    cout << "---------------------------" << endl;
//    print_search_out(cin, cout, *_files);
//}
//
//void mini_text_query()
//{
//    ifstream file("test.txt");
//    TextQuery tq(file);
//    string input;
//    cout << "Welcome to Mini TextQuery Program!\n"
//         << "-------------------------------\n"
//         << "You can enter the word you want to search...."
//         << endl;
//    while (cin >> input)
//    {
//        if (input == "exit")
//            break;
//        print(cout, tq.query(input));
//    }
//}

