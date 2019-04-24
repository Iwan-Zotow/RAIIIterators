// -*- C++ -*-

#pragma once

#include <cassert>
#include <cstddef>

template <typename I> struct Incrementer
{
    private: I* _pi;

    public: Incrementer() = delete;

    public: Incrementer(I* pi):
        _pi{pi}
    {
    }

    public: Incrementer(const Incrementer& pi) = delete;
    public: Incrementer& operator=(const Incrementer& pi) = delete;

    public: ~Incrementer()
    {
        _pi->increment();
    }
};

template <typename I> struct Decrementer
{
    private: I* _pi;

    public: Decrementer() = delete;

    public: Decrementer(I* pi):
        _pi{pi}
    {
    }

    public: Decrementer(const Decrementer& pi) = delete;
    public: Decrementer& operator=(const Decrementer& pi) = delete;

    public: ~Decrementer()
    {
        _pi->decrement();
    }
};

class Iterator
{
#pragma region typedefs
    public: using data_t    = int;
    public: using pointer_t = data_t*;
#pragma endregion

#pragma region Data
    private: pointer_t _p;
#pragma endregion

#pragma region Ctor/Dtor/ops
    public: Iterator(pointer_t p):
        _p{p}
    {
    }

    public: Iterator(const Iterator& s) = default;

    public: Iterator(Iterator&& s) = default;

    public: Iterator& operator=(const Iterator& s) = default;

    public: Iterator& operator=(Iterator&& s) = default;

    public: ~Iterator() = default;
#pragma endregion

#pragma region Observers
    public: const data_t& operator*() const
    {
        return *_p;
    }
#pragma endregion

#pragma region Mutators
    public: data_t& operator*()
    {
        return *_p;
    }
#pragma endregion

#pragma region Increments
    public: void increment()
    {
        ++_p;
    }

    public: Iterator operator++()
    {
        increment();
        return *this;
    }

    public: Iterator operator++(int)
    {
        Incrementer<Iterator> inc(this);
        return *this;
    }

    public: void decrement()
    {
        --_p;
    }

    public: Iterator operator--()
    {
        decrement();
        return *this;
    }

    public: Iterator operator--(int)
    {
        Decrementer<Iterator> dec(this);
        return *this;
    }
#pragma endregion
};
