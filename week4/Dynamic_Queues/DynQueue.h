#ifndef DYNQUEUE_H_
#define DYNQUEUE_H_
struct QueueNode{
    int value;
    QueueNode *next;
    QueueNode(int num, QueueNode *ptr = nullptr):value(num),next(ptr){};
};
class DynQueue{
    private:
        QueueNode *front;
        QueueNode *rear;
    public:
    DynQueue(); //! Constructor
    //! Member Functions
    void enqueue(int);
    void dequeue(int &);
    bool isEmpty() const;
    void clear();
    void print();
};
#endif