#include <iostream>
#include <cstdint>
#include <cstring>

class Queue {
    public:
        Queue(uint64_t size) {
            this->size = size;
            this->ids = new uint64_t[size];
            this->end = 0;
        }

        ~Queue() {
            delete[] ids;
        }

        bool add(uint64_t elem) {
            if (end < size) {
                ids[end] = elem;
                end++;
                return true;
            } else {
                return false;
            }
        }

        uint64_t remove() {
            if (end > 0 && end <= size) {
                auto result = ids[0];
                l_shift();
                end--;
                return result;
            } else {
                return -1;
            }
        }

        void print() {
            std::cout << "queue capacity: " << size << '\n';
            std::cout << "queue current size: " << end << '\n';
            for (int i = 0; i < end; i++) {
                std::cout << ids[i] << (i == end -1 ? "" : (i % 10 == 9 ? "\n" : " | "));
            }
            std::cout << '\n';
        }

    private:

        void l_shift() {
            for (int i = 0; i < end; i++) {
                ids[i] = ids[i + 1];
            }
        }
        uint64_t* ids;
        uint64_t end;
        uint64_t size;
};

int main() {
    uint64_t size = 30;
    Queue queue = Queue(size);

    for (int i = 0; i < size; i++) {
        queue.add(i * 13 % 7);
    }

    queue.print();

    std::cout << queue.remove() << " : " << queue.remove() << '\n';

    queue.print();

    queue.add(800);

    queue.print();

    return 0;
}