#pragma once

#include <queue>
#include <deque>
#include <mutex>
#include <condition_variable>
#include <string>

struct ClosedQueue : public std::runtime_error {
    ClosedQueue() : std::runtime_error("The queue is closed") {}
};

template<typename T, class C = std::deque<T> >
class ProtectedQueue {
private:
    std::queue<T, C> q;
    const unsigned int max_size;
    bool closed;
    std::mutex mtx;
    std::condition_variable is_not_full;
    std::condition_variable is_not_empty;

public:
    explicit ProtectedQueue(const unsigned int max_size) : max_size(max_size), closed(false) {}

    bool try_push(T const& val) {
        std::unique_lock<std::mutex> lck(mtx);

        if (closed) {
            throw ClosedQueue();
        }

        if (q.size() == this->max_size) {
            return false;
        }

        if (q.empty()) {
            is_not_empty.notify_all();
        }

        q.push(val);
        return true;
    }

    bool try_pop(T& val) {
        std::unique_lock<std::mutex> lck(mtx);

        if (q.empty()) {
            if (closed) {
                throw ClosedQueue();
            }
            return false;
        }

        if (q.size() == this->max_size) {
            is_not_full.notify_all();
        }

        val = q.front();
        q.pop();
        return true;
    }

    bool try_pop(std::vector<T>& val, size_t n) {
        std::unique_lock<std::mutex> lck(mtx);

        if (q.empty()) {
            if (closed) {
                throw ClosedQueue();
            }
            return false;
        }

        if (q.size() == this->max_size) {
            is_not_full.notify_all();
        }

        if (q.size() < n) {
            n = q.size();
        }
        for (size_t i = 0; i < n; i++) {
            val.push_back(q.front());
            q.pop();
        }
        return true;
    }

    void push(T const& val) {
        std::unique_lock<std::mutex> lck(mtx);

        if (closed) {
            throw ClosedQueue();
        }

        while (q.size() == this->max_size) {
            is_not_full.wait(lck);
        }

        if (q.empty()) {
            is_not_empty.notify_all();
        }

        q.push(val);
    }


    T pop() {
        std::unique_lock<std::mutex> lck(mtx);

        while (q.empty()) {
            if (closed) {
                throw ClosedQueue();
            }
            is_not_empty.wait(lck);
        }

        if (q.size() == this->max_size) {
            is_not_full.notify_all();
        }

        T const val = q.front();
        q.pop();

        return val;
    }

    void close() {
        std::unique_lock<std::mutex> lck(mtx);

        if (closed) {
            throw std::runtime_error("The queue is already closed.");
        }

        closed = true;
        is_not_empty.notify_all();
    }

    bool isClosed() const {
        return closed;
    }

    ProtectedQueue& operator=(const ProtectedQueue&) = delete;
    ProtectedQueue& operator=(ProtectedQueue&&) = delete;
    ProtectedQueue(const ProtectedQueue&) = delete;
    ~ProtectedQueue() = default;
};
