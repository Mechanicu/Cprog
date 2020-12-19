#include <iostream>
#include <cinttypes>
#include <chrono>

using namespace std;
using namespace chrono;

#include "../list-based/seq.h"
#include "../tree-based/bstree.h"
#include "../hash/hash.h"

template <typename table_type, typename search_algo>
void test_search(KeyType key, search_algo algo, const char *algo_name)
{
    table_type l;

    CreateFromFile(&l);

    auto start = steady_clock::now();
    auto i = algo(l, key);    
    auto end = steady_clock::now();

    printf("%s Search:\n", algo_name);
    Found(i, key);
    auto duration = duration_cast<nanoseconds>(end - start).count();
    printf("--- Time consumed: %lu ns\n\n", duration);

    Destroy(&l);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: benchmark <key>" << std::endl;
        return 1;
    }
    
    KeyType key = atoi(argv[1]);

    test_search<RecordList>(key, SeqSearch, "Sequencial");
    test_search<BSTree>(key, BSTSearch, "Binary Sorted Tree");
    test_search<HashTable>(key, HashSearch, "Hash");
   
    return 0;
}