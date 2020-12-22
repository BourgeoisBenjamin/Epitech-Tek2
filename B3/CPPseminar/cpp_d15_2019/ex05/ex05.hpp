/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** TODO: add description
*/

#ifndef CPP_D15_2019_EX05_HPP
#define CPP_D15_2019_EX05_HPP

template<typename T>
class array
{
    private:
        T *_array;
        unsigned int _size;
    public:
        array(unsigned int n = 0)
        {
            _size = n;
            _array = new T[n];
        }
        array(const T *old)
        {
            _size = old.size();
            _array = new T[_size];
            for (int i = 0; i < old.size(); i++)
                _array[i] = old._array[i];
        }
        ~array()
        {
            if (_array)
                delete [] _array;
        }
        unsigned int size()
        {
            return _size;
        }
        array<T> & operator=(const array<T> &old)
        {
            if (_array)
                delete[] _array;
            _size = old.size();
            _array = new T[_size];
            for (int i = 0; i < old.size(); i++)
                _array[i] = old._array[i];
            return *this;
        }
        T & operator[](unsigned int index)
        {
            if (index >= _size)
                throw std::exception;
            return _array[index];
        }
        T & operator[](unsigned int index)
        {
            T* temp = nullptr;
            try
            {
                if (index >= _size)
                {
                    temp = new T[index + 1];
                    for (int i = 0; i < _size; i++)
                        temp[i] = _array[i];
                    delete _array[];
                    _array = temp;
                    _size = index + 1;
                }
                return array[index];
            }
            throw std::exception;
        }

};

#endif //CPP_D15_2019_EX05_HPP
