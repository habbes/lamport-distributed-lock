#include "lock.h"

DistributedLock::DistributedLock(const int & num_procs, const int & my_id):
    _num_procs(num_procs), _my_id(my_id) {
}

void DistributedLock::acquire() {}

void DistributedLock::release() {}

DistributedLock::~DistributedLock() {}
