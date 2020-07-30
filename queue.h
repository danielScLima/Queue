#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <vector>

/**
 * @brief struct NodeOfQueue
 * 
 */
struct NodeOfQueue
{
    /**
     * @brief Construct a new NodeOfQueue object
     * 
     */
    NodeOfQueue()
    {
        next = nullptr;
        this->data = "";
    }
    /**
     * @brief Construct a new NodeOfQueue object
     * 
     * @param data 
     */
    NodeOfQueue(const std::string& data)
    {
        this->data = data;
        next = nullptr;
    }

    std::string data = "";
    struct NodeOfQueue* next = nullptr;
};


/**
 * @brief 
 * 
 */
class QueueDataStructure
{
public:
    /**
     * @brief Construct a new QueueDataStructure object
     * 
     */
    QueueDataStructure();

    ~QueueDataStructure();

    /**
     * @brief Inserts a string
     * 
     * @param data 
     * @return NodeOfQueue*
     */
    NodeOfQueue* insert(const std::string& data);

    /**
     * @brief Returns the head element
     * 
     * @return NodeOfQueue*
     */
    NodeOfQueue* top();

    /**
     * @brief Removes the head element
     * 
     * @return NodeOfQueue*
     */
    NodeOfQueue* remove();

    /**
     * @brief Get the Elements As Vector object
     * 
     * @return std::vector<std::string> 
     */
    std::vector<std::string> getElementsAsVector();

private:
    struct NodeOfQueue* head = nullptr;
    struct NodeOfQueue* tail = nullptr;
};

#endif // QUEUE_H
