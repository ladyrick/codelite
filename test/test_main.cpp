#include <random>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#define MY_UINT_MAX 4294967296ULL

const char strDes[] = "ladyrick";
#define STRLENGTH 8

template<class RandomEngine>
void findladyrick(const string &filename) {
    ofstream fout(string("random_engines_") + filename + ".txt");
    for (unsigned long long seed = 0; seed < MY_UINT_MAX; ++seed) {
        RandomEngine re(seed);
        int i = 0;
        for (; i < STRLENGTH; ++i) {
            if ((re() % 26) != (strDes[i] - 'a')) {
                break;
            }
        }
        if (i == STRLENGTH || seed % 100000000 == 0) {
            RandomEngine t(seed);
            char str[STRLENGTH + 1] = {0};
            for (int j = 0; j < STRLENGTH; ++j) {
                str[j] = t() % 26 + 'a';
            }
            cout << seed << " : " << str << endl;
            if (i == STRLENGTH) {
                fout << seed << " : " << str << endl;
            }
        }
    }
    fout.close();
}

#define CHECK_LADYRICK(re) findladyrick<re>(#re)

int main() {
    CHECK_LADYRICK(default_random_engine);
    CHECK_LADYRICK(minstd_rand);
    CHECK_LADYRICK(minstd_rand0);
    CHECK_LADYRICK(mt19937);
    CHECK_LADYRICK(mt19937_64);
    CHECK_LADYRICK(ranlux24_base);
    CHECK_LADYRICK(ranlux48_base);
    CHECK_LADYRICK(ranlux24);
    CHECK_LADYRICK(ranlux48);
    CHECK_LADYRICK(knuth_b);
    return 0;
}

/*
default_random_engine
minstd_rand
minstd_rand0
mt19937
mt19937_64
ranlux24_base
ranlux48_base
ranlux24
ranlux48
knuth_b
 */