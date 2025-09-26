// worker_threads.hpp
#ifndef WORKER_THREADS_H
#define WORKER_THREADS_H

#include <thread>
#include <mutex>
#include <condition_variable>
#include <string>
#include "queue.h"
#include "dummy.h"

enum JobType {
    kJobTypeEval,
    kJobTypeEvent,
    kJobTypeEventSerialized
};

struct Job {
    int jobType;
    struct {
        std::string* eventName;
        std::string** arguments;
        int length;
    } typeEvent;
    struct {
        std::string* eventName;
        char* buffer;
        size_t bufferSize;
        int length;
    } typeEventSerialized;
    struct {
        int error;
        int hasCallback;
        int useStringObject;
        std::string* result;
        std::string* scriptLocation;
        std::string* scriptText;
    } typeEval;
};

struct Thread {
    long int id;
    std::thread thread;
    volatile int sigkill;
    Queue inQueue;
    Queue outQueue;
    volatile bool idle;
    std::condition_variable idleCondition;
    std::mutex idleMutex;
    unsigned long threadMagicCookie = 0x99c0ffee;
    void pushToInQueue(QueueItem* qitem);
};

QueueItem* nuJobQueueItem();
Thread* isAThread(const Local_Object&);
void eval(Local_Value* info);
void load(Local_Value* info);
void processEmit(Local_Value* info);
void destroy(Local_Value* info);
void create(Local_Value* info);
void init(Local_Object target);

#endif // WORKER_THREADS_H