// queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <mutex>

enum ItemType {
    kItemTypeNONE,
    kItemTypeNumber,
    kItemTypePointer,
    kItemTypeQUIT
};

struct QueueItem {
    int itemType;
    QueueItem* next;
    union {
        void* asPtr;
        double asNumber;
    };
};

struct Queue {
    QueueItem* first;
    QueueItem* last;
    std::mutex queueLock;
    long int id;
    volatile long int length;
    void push(QueueItem* qitem);
    QueueItem* pull();
    Queue() : first(nullptr), last(nullptr), id(0), length(0) {}
};

QueueItem* nuItem(int itemType, void* item);
void destroyItem(QueueItem* qitem);
Queue* nuQueue(long int id);
void initQueues();

#endif // QUEUE_H