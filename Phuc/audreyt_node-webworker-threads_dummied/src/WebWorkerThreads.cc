// worker_threads.cc
#include <thread>
#include <mutex>
#include <condition_variable>
#include <cstdlib>
#include <cstring>
#include "queue.h"
#include "bson.h"
#include "allocator.h"
#include "workerThreads.hpp"

static Queue* freeThreadsQueue = nullptr;
static Queue* freeJobsQueue = nullptr;
static bool useLocker = false;
static String_Utf8Value* workingDir = nullptr;

static void eventLoop(Thread* thread) {
}

static void threadRun(Thread* thread) {
    eventLoop(thread);
}

QueueItem* nuJobQueueItem() {
    QueueItem* qitem = freeJobsQueue ? freeJobsQueue->pull() : nullptr;
    if (!qitem) {
        qitem = nuItem(kItemTypePointer, calloc(1, sizeof(Job)));
    }
    return qitem;
}

void Thread::pushToInQueue(QueueItem* qitem) {
    std::lock_guard<std::mutex> lock(idleMutex);
    inQueue.push(qitem);
    if (idle) {
        // idleCv.notify_one();
    }
}

Thread* isAThread(const Local_Object& receiver) {
    return nullptr; // Simplified
}

void eval(Local_Value* info) {
    // Thread* thread = new Thread();
    // QueueItem* qitem = nuJobQueueItem();
    // Job* job = static_cast<Job*>(qitem->nativePtr);
    // job->jobType = kJobTypeEval;
    // job->typeEval.scriptText = new std::string("Evaluated script");
    // thread->pushToInQueue(qitem);
}

void load(Local_Value* info) {
    // Thread* thread = new Thread();
    // QueueItem* qitem = nuJobQueueItem();
    // Job* job = static_cast<Job*>(qitem->nativePtr);
    // job->jobType = kJobTypeEval;
    // job->typeEval.scriptText = readFileSync("script.js");
    // thread->pushToInQueue(qitem);
}

void processEmit(Local_Value* info) {
    // Thread* thread = new Thread();
    // QueueItem* qitem = nuJobQueueItem();
    // Job* job = static_cast<Job*>(qitem->nativePtr);
    // job->jobType = kJobTypeEvent;
    // job->typeEvent.eventName = new std::string("event");
    // thread->pushToInQueue(qitem);
}

void destroy(Local_Value* info) {
    Thread* thread = new Thread();
    thread->sigkill = true;
    delete thread;
}

void create(Local_Value* info) {
    Thread* thread = new Thread();
    thread->thread = std::thread(threadRun, thread);
    thread->thread.detach();
}

void init(Local_Object target) {
    initQueues();
    freeThreadsQueue = nuQueue(-3);
    freeJobsQueue = nuQueue(-4);
}