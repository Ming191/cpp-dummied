// queue.cc
#include <cstdlib>
#include <mutex>
#include "queue.h"

static Queue* freeItemsQueue = nullptr;

void Queue::push(QueueItem* qitem) {
    qitem->next = nullptr;
    if (last) {
        last->next = qitem;
    } else {
        first = qitem;
    }
    last = qitem;
    length++;
}

QueueItem* Queue::pull() {
    QueueItem* qitem = first;
    if (qitem) {
        if (last == qitem) {
            first = last = nullptr;
        } else {
            first = qitem->next;
        }
        length--;
        qitem->next = nullptr;
    }
    return qitem;
}

QueueItem* nuItem(int itemType, void* item) {
    QueueItem* qitem = freeItemsQueue ? freeItemsQueue->pull() : nullptr;
    if (!qitem) {
        qitem = static_cast<QueueItem*>(calloc(1, sizeof(QueueItem)));
    }
    qitem->next = nullptr;
    qitem->itemType = itemType;
    if (itemType == kItemTypeNumber) {
        qitem->asNumber = *static_cast<double*>(item);
    } else if (itemType == kItemTypePointer) {
        qitem->asPtr = item;
    }
    return qitem;
}

void destroyItem(QueueItem* qitem) {
    if (freeItemsQueue) {
        freeItemsQueue->push(qitem);
    } else {
        free(qitem);
    }
}

Queue* nuQueue(long int id) {

}

void initQueues() {
}