#pragma once

class Exception
{
public:
    Exception() noexcept;
    Exception(const Exception&) noexcept;
    //Exception& operator=(const Exception&) noexcept;
    virtual ~Exception(); 
    virtual const char* what() const noexcept; // возвращает сообщение об исключении
};
