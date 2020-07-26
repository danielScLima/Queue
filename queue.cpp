#include "queue.h"

Queue::Queue()
{

}

Queue::~Queue()
{
    NodeOfQueue* initialHead = head;
    if (initialHead != nullptr)
    {
        NodeOfQueue* tmp = initialHead->next;
        delete initialHead;
        while (tmp != nullptr)
        {
            head = tmp->next;
            delete tmp;
            tmp = head;
        }
    }
}

NodeOfQueue * Queue::insert(const std::string& data)
{
    struct NodeOfQueue* tmp = new NodeOfQueue(data);

    if (head == nullptr)
    {
        head = tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tmp;
    }

    return tmp;
}

NodeOfQueue* Queue::top()
{
    return head;
}

NodeOfQueue *Queue::remove()
{
    if (head == nullptr)
        return nullptr;
    else
    {
        if (head == tail)
        {
            NodeOfQueue * tmp = head;
            head = tail = nullptr;
            return tmp;
        }
        else
        {
            NodeOfQueue * tmp = head;
            head = head->next;
            return tmp;
        }
    }
}

std::vector<std::string> Queue::getElementsAsVector()
{
    std::vector<std::string> vec;
    NodeOfQueue* tmp = head;
    while (tmp != nullptr)
    {
        vec.push_back(tmp->data);
        tmp = tmp->next;
    }

    return vec;
}
