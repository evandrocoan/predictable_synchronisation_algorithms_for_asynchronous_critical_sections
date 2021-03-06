// EPOS Debug Utility Declarations

#include <utility/debug.h>
#include <semaphore.h>

#ifndef __debug_sync_h
#define __debug_sync_h

// You can define it anywhere before including this file
// #define DEBUG_SYNC

#ifdef DEBUG_SYNC

__BEGIN_UTIL
    Semaphore _debug_syncronized_semaphore_lock;
__END_UTIL

    // A debug function cannot call this recursively, otherwise a deadlock happens.
    // Unless you replace the `_debug_syncronized_semaphore_lock` by a recursive
    // semaphore or mutex. See:
    // https://stackoverflow.com/questions/36619715/a-shared-recursive-mutex-in-standard-c
    #define DB(name,level,...) do { \
        _debug_syncronized_semaphore_lock.lock(); \
            db<name>(level) << __VA_ARGS__; \
        _debug_syncronized_semaphore_lock.unlock(); } while(0);

#else
    #define DB(name,level,...) db<name>(level) << __VA_ARGS__;

#endif

#define LOG(...) DB(Debug, WRN, __VA_ARGS__)

#endif

