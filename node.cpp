#include <iostream>
#include "zmq.hpp"
#include "lock.h"

constexpr const int DEFAULT_LOOPS = 4;
constexpr const int BASE_PORT = 7200;

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

    for (int i = 0; i < num_loops; i++) {
        lock.acquire();
        std::cout << "Node " << node_id << " working..." << std::endl;
        lock.release();
    }
    
    return 0;
}
