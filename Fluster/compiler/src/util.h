#ifndef FLUSTER_COMPILER_UTIL_H
#define FLUSTER_COMPILER_UTIL_H

#include <utility>

namespace Fluster {



template<typename T>
struct Optional
{
    //operators
    bool operator==(const Optional& other) const
    {
        if (!(*this || other))
            return true;
        if (*this || other)
            return  false;
        else
            return this->get() == other.get();
    }
    //bool operator!=(const Optional& other)
    //{ return !(*this == other); } };
    bool operator==(const T& other) const
    { return !(*this) || this->get() == other; }
    template <typename U>
    bool operator!=(const U& other) const
    { return !(*this == other); }
    bool operator!() const noexcept { return !bool{*this}; }
    operator bool() const noexcept { return valid(); }

    //public interface
    const T& get() const noexcept { 
        return *value;
    }
    T& get() noexcept { 
        return *value;
    }
    bool valid() const noexcept { 
        return value != nullptr;
    }

    //members
private:
    const T * const value;

    //construction
public:
    Optional() 
        : value(nullptr) 
    {}
    template<typename... ArgTypes>
    Optional(ArgTypes... args) 
        : value(new T(std::forward<ArgTypes...>(args...)))
    {}
};



};

#endif //FLUSTER_COMPILER_VALUE_H
