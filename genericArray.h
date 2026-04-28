#ifndef GENERICARRAY_H
#define GENERICARRAY_H

#include <cstddef>
#include <stdexcept>

template <typename T>
class GenericArray {
private:
    T* data_;
    std::size_t size_;

public:
    GenericArray() : data_(nullptr), size_(0) {}

    GenericArray(const GenericArray& other) : data_(nullptr), size_(other.size_) {
        if (size_ > 0) {
            data_ = new T[size_];
            for (std::size_t i = 0; i < size_; ++i) {
                data_[i] = other.data_[i];
            }
        }
    }

    GenericArray& operator=(const GenericArray& other) {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            data_ = nullptr;

            if (size_ > 0) {
                data_ = new T[size_];
                for (std::size_t i = 0; i < size_; ++i) {
                    data_[i] = other.data_[i];
                }
            }
        }
        return *this;
    }

    ~GenericArray() {
        delete[] data_;
    }

    void addElement(const T& value) {
        T* newData = new T[size_ + 1];

        for (std::size_t i = 0; i < size_; ++i) {
            newData[i] = data_[i];
        }

        newData[size_] = value;

        delete[] data_;
        data_ = newData;
        ++size_;
    }

    T at(int param) const {
        if (param < 0 || static_cast<std::size_t>(param) >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[param];
    }

    std::size_t size() const {
        return size_;
    }

    T sum() const {
        if (size_ == 0) {
            throw std::runtime_error("Cannot compute sum of empty array");
        }

        T total{};
        for (std::size_t i = 0; i < size_; ++i) {
            total += data_[i];
        }
        return total;
    }

    T max() const {
        if (size_ == 0) {
            throw std::runtime_error("Cannot compute max of empty array");
        }

        T maximum = data_[0];
        for (std::size_t i = 1; i < size_; ++i) {
            if (data_[i] > maximum) {
                maximum = data_[i];
            }
        }
        return maximum;
    }

    T min() const {
        if (size_ == 0) {
            throw std::runtime_error("Cannot compute min of empty array");
        }

        T minimum = data_[0];
        for (std::size_t i = 1; i < size_; ++i) {
            if (data_[i] < minimum) {
                minimum = data_[i];
            }
        }
        return minimum;
    }

    T* slice(int begin, int end) const {
        if (begin < 0 || end < 0 || begin > end || static_cast<std::size_t>(end) >= size_) {
            throw std::out_of_range("Invalid slice bounds");
        }

        std::size_t newSize = static_cast<std::size_t>(end - begin + 1);
        T* sliced = new T[newSize];

        for (std::size_t i = 0; i < newSize; ++i) {
            sliced[i] = data_[begin + static_cast<int>(i)];
        }

        return sliced;
    }
};

#endif
