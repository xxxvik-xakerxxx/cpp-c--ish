#include <iostream>
#include <exception>

template <typename T>
class Array
{
    template <typename U>
    friend void swap(Array<U>&, Array<U>&);

public:
    typedef std::size_t         size_type;
    typedef T                   value_type;
    typedef value_type&         reference;
    typedef const value_type&   const_reference;

    //c-like iterator
    typedef T* iterator;

    Array() :
        _data(nullptr),
        _size(0),
        _capacity(0)
    {
    }

    Array(const Array& other)
    {
        _alloc(other.capacity());

        std::copy(_data, other._data, other.size());
        std::copy(_size, other.size());
        std::copy(_capacity, other.capacity());
    }

    Array& operator=(Array other)
    {
        other.swap(*this);
        return *this;
    }

    ~Array()
    {
        _dealloc();
    }

    void swap(Array& other)
    {
        std::swap(_data, other._data);

        std::swap(_size, other._size);
        std::swap(_capacity, other._capacity);
    }

    size_type size() const
    {
        return _size;
    }

    size_type capacity() const
    {
        return _capacity;
    }

    void push_back(const value_type& value)
    {
        if (_size == 0)
        {
            _alloc(1);
            _capacity = 1;
        }
        else if (_size == _capacity)
        {
            _alloc(_capacity * 2);
            _capacity *= 2;
        }

        _data[_size++] = value;
    }

    reference at(size_type i)
    {
        if (i >= _size)
            throw std::out_of_range();

        return _data[i];
    }

    const_reference at(size_type i) const
    {
        if (i >= _size)
            throw std::out_of_range();

        return _data[i];
    }

    reference operator[](size_type i)
    {
        return _data[i];
    }

    const_reference operator[](size_type i) const
    {
        return _data[i];
    }

    iterator begin()
    {
        if (_size == 0)
            return end();

        return &_data[0];
    }

    iterator end()
    {
        if (_capacity == 0)
            return nullptr;

        return &_data[_size];
    }

private:
    value_type *_data;

    size_type _size;
    size_type _capacity;

    void _alloc(size_type count)
    {
        if (!(_data = (value_type*)realloc(_data, count * sizeof(value_type))))
        {
            throw std::bad_alloc();
        }
    }

    void _dealloc()
    {
        free(_data);
    }
};

int main()
{
    int count = 10;
    Array<int> array;

    for (int i = 0; i < count; ++i)
    {
        array.push_back(i);
    }

    for (Array<int>::iterator it = array.begin(); it != array.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    std::getchar();

    return 0;
}
