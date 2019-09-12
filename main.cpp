#include <iostream>
#include <fstream>

using namespace std;

void usage(const std::string& prog)
{
    std::cout << "Usage:\t " << prog << " <path to log>  <path to key>" << std::endl;
}

int main(int argc, char** argv)
{
    if (argc != 3) {
        usage(argv[0]);
    } else {
        const std::string logPath = argv[1];
        const std::string keyPath = argv[2];

        std::ifstream keyFile(keyPath);
        std::ifstream log(logPath);

        std::string key;
        keyFile >> key;

        std::string out;
        char c;
        while (log.get(c)) {
            out.push_back(c);
        }

        size_t ind = 0;
        for (size_t i = 0; i < out.size(); ++i) {
            char cc = char(out[i] ^ key[ind % (key.size() - 1)]);
            ++ind;
            cout << cc;
            if (cc == '\n') {
                ++i;
                ind = 0;
            }
        }
    }
    return 0;
}
