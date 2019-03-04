#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>
#include <exception>

template <typename T>
class DequeItem
{
public:
    DequeItem(const T& data) :
        data_(data), prev(0), next(0) {}
    T data_;
    DequeItem* prev;
    DequeItem* next;
};

template <typename T>
class Deque
{
public:
    Deque() :
        count(0), head(0), tail(0) {}

    bool empty() const
    {
        return (count == 0);
    }

    size_t size() const
    {
        return count;
    }

    T& operator[](size_t index)
    {
        return at_(index);
    }

    const T& operator[](size_t index) const
    {
        return at(index);
    }

    const T& at(size_t index) const
    {
        return at_(index);
    }

    T& at(size_t index)
    {
        return at_(index);
    }

    const T& front() const
    {
        return head->data_;
    }

    T& front()
    {
        return head->data_;
    }

    const T& back() const
    {
        return tail->data_;
    }

    T& back()
    {
        return tail->data_;
    }

    void pushFront(T const& value)
    {
        DequeItem<T>* temp = new DequeItem<T>(value);

        temp->prev = 0;
        temp->data_ = value;
        temp->next = head;

        if (head != 0) {
            head->prev = temp;
        }

        if (count == 0) {
            head = tail = temp;
        } else {
            head = temp;
        }

        count++;
    }

    void pushBack(T const& value)
    {
        DequeItem<T>* temp = new DequeItem<T>(value);

        temp->next = 0;
        temp->data_ = value;
        temp->prev = tail;

        if (tail != 0) {
            tail->next = temp;
        }

        if (count == 0) {
            head = tail = temp;
        } else {
            tail = temp;
        }

        count++;
    }

private:
    size_t count;
    DequeItem<T>* head;
    DequeItem<T>* tail;
    T& at_(size_t index) {
        if (index < 0 || index >= count)
            throw std::out_of_range("Error! Invalid index");
        DequeItem<T>* item = head;
        for (size_t i = 0; i < index; i++) {
            item = item->next;
        }
        return item->data_;
    }

};

#endif // DEQUE_H
