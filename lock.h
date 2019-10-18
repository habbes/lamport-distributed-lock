#ifndef __lock_h__
#define __lock_h__

class DistributedLock
{
    int _num_procs;
    int _my_id;
public:
    DistributedLock(const int & num_procs, const int & my_id);
    void acquire();
    void release();
    ~DistributedLock();
};

#endif
