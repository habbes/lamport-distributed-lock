#include <iostream>
#include <cstdio>
#include <algorithm>
#include "zmq.hpp"
#include "lock.hpp"
#include "helpers.hpp"

constexpr const int DEFAULT_LOOPS = 4;
constexpr const int BASE_PORT = 7200;
constexpr const char *FILENAME = "result.csv";

int main(int argc, char *argv[])
{
    if (argc < 3) {
        std::cout << "Usage: ./node <num_nodes> <node_id> <num_loops?>" << std::endl;
        return 1;
    }
    const int num_nodes = atoi(argv[1]);
    const int node_id = atoi(argv[2]);
    const int num_loops = argc >= 4 ? atoi(argv[3]) : DEFAULT_LOOPS;
    const int node_port = node_id + BASE_PORT;

    DistributedLock lock(num_nodes, node_id);
    FILE *file = fopen(FILENAME, "a+");

    for (int i = 0; i < num_loops; i++) {
        lock.acquire();
        int last_value = get_last_result_value(file);
        write_result_line(file, last_value + 1, node_id);
        fflush(file);
        lock.release();
    }

    fclose(file);
    return 0;
}
