#include <vector>
#include <stdexcept>
#include <iostream>

template <class T>
class Deque {
    std::vector<T> front;
    std::vector<T> back;

public:
    Deque() = default;

    bool Empty(void) const {
        return front.empty() && back.empty();
    }

    size_t Size(void) const {
        return front.size() + back.size();
    }

    T& operator[](size_t index) {
        if (index < front.size()) {
            return front[front.size() - 1 - index];
        }
        return back[index - front.size()];
    }

    const T& operator[](size_t index) const {
        if (index < front.size()) {
            return front[front.size() - 1 - index];
        }
        return back[index - front.size()];
        // return this->operator[](index);
    }

    T &At(size_t index) {
        if (index >= Size())
            throw std::out_of_range("index is more than size of deque");
        return this->operator[](index);
    }

    const T &At(size_t index) const {
        if (index >= front.size() + back.size())
            throw std::out_of_range("index is more than size of deque");
        return this->operator[](index);
    }

    const T &Front(void) const {
        if (front.empty()) {
            return back.front();
        }
        return front.back();
    }

    T &Front(void) {
        if (front.empty()) {
            return back.front();
        }
        return front.back();
    }

    const T &Back(void) const {
        if (back.empty()) {
            return front.front();
        }
        return back.back();
    }

    T &Back(void) {
        if (back.empty()) {
            return front.front();
        }
        return back.back();
    }

    void PushFront(const T &value) {
        front.push_back(value);
    }
    
    void PushBack(const T &value) {
        back.push_back(value);
    }
};

int main(void) {
    {
        Deque<int> deque;

        for (int i = 0; i < 10; ++i) {
            deque.PushBack(i);
        }
        for (int i = 10; i < 20; ++i) {
            deque.PushFront(i);
        }
        for (int i = 0; i < 20; ++i) {
            std::cout << deque[i] << ' ';
        }

        std::cout << std::endl;
        try {
            deque.At(100);
        } catch (const std::exception &exc) {
            std::cout << exc.what() << std::endl;
        }
    }

#define PASS_LINE std::cout << "==================" << std::endl
    PASS_LINE;
    {
        Deque<int> deque;

        std::cout << "Check PushBack():" << std::endl;
        std::cout << "Front()\tBack()" << std::endl;
        for (int i = 0; i < 5; ++i) {
            deque.PushBack(i);
            std::cout << deque.Front() << '\t' << deque.Back() << std::endl;
        }
    }

    PASS_LINE;
    {
        Deque<int> deque;

        std::cout << "Check PushFront():" << std::endl;
        std::cout << "Front()\tBack()" << std::endl;
        for (int i = 0; i < 5; ++i) {
            deque.PushFront(i);
            std::cout << deque.Front() << '\t' << deque.Back() << std::endl;
        }
    }
    return 0;
}
