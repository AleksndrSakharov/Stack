#pragma once
#include "Stack.h"

template <typename T2, typename T1>
class Table
{
private:
    size_t _count;
    size_t _size;
    T1* _col1;
    T2* _col2;
    string _title1;
    string _title2;
public:
    Table(string title1, string title2, size_t size = 10){
        _size = size;
        _count = 0;
        _col1 = new T1[size];
        _col2 = new T2[size];
        _title1 = title1;
        _title2 = title2;
    }
    /// @brief эта функция для добавления элементов в строку 
    /// @param elem1 элемент первого столбца
    /// @param elem2 элемент второго столбца
    void AppendRow(T1 elem1, T2 elem2, string title1, string title2){
        _col1[_count] = elem1;
        _col2[_count] = elem2;
        _title1 = title1;
        _title2 = title2;
        if (_count + 1 > _size) throw;
        _count++;
    }
    void Print(){
        size_t flag = 5;
        cout << "+";
        for (size_t i = 0; i < flag * 2; i++){ if(i == flag)cout <<"+"; cout << "-";}
        cout << "+\n";
        cout << "|" << setw(flag) << _title1 << "|" << setw(flag) << _title2;
        for (size_t i = 0; i < _count; i++){
            cout << "|" << setw(flag) << _col1[i] << "|" << setw(flag) << _col2[i];
        }
        cout << "\n";
        cout << "+";
        for (size_t i = 0; i < flag * 2; i++){ if(i == flag)cout <<"+"; cout << "-";}
        cout << "+\n";
    }
    ~Table(){
        delete [] _col1;
        delete [] _col2;
        _col1 = nullptr;
        _col2 = nullptr;
    }
};
