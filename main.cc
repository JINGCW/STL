#include <iostream>
#include <boost/program_options.hpp>

using namespace std;
namespace po = boost::program_options;

void show_help(const po::options_description &desc, const string &topic = "")
{
    cout << desc << endl;
    if (!topic.empty())
        cout << "You asked help on: " << topic << endl;
    exit(EXIT_SUCCESS);
}

void process_program_options(const int argc, const char *const argv[])
{
//    int opt;

    po::options_description desc("Allowed options");

    desc.add_options()
//            (
////                    "help,h",
////                    po::value<string>()
////                            ->implicit_value("")
////                            ->notifier([&desc](const string &topic) { show_help(desc, topic); }),
////                    "Show help. If given, show help on the specified topic."
//            )
            ("help","produce help message")
            ("compression", po::value<int>(), "set compression level");
    if (argc == 1)
        show_help(desc);

    po::variables_map vm;
    try
    {
        po::store(po::parse_command_line(argc, argv, desc), vm);
    } catch (po::error const &e)
    {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    po::notify(vm);

    if(vm.count("help"))
        cout << desc << endl;
    if (vm.count("compression"))
        cout << "compression level was set to " << vm["compression"].as<int>() << ".\n";
    else
        cout << "compression level was not set." << endl;
}

//template<typename T>
//T max(T a, T b)
//{
//    std::cout << "max<T>() \n";
//    return b < a ? a : b;
//}
//
//template<typename T>
//T max(T a, T b, T c)
//{
//    return max(max(a, b), c);
//}
//
//int max(int a, int b)
//{
//    std::cout << "max(int,int)\n";
//    return b < a ? a : b;
//}

int main(int argc, char *argv[])
{
//    ::max(47, 11, 33);
    process_program_options(argc, argv);
    return 0;
}
