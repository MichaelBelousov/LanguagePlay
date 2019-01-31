
class NoneType;

const NoneType& none = *static_cast<NoneType*>(nullptr);

class NoneType {
    NoneType() = delete;
    template<typename T>
    bool operator==(const T& other) {
        return &T == &none;
    }
};

#define MC_PREF ___raw_
#define mclass(name) \
    using name = std::shared_ptr<MC_PREF##name>;\
    class MC_PREF##name { \
        public: \
           name(const NoneType& in_none) { \
           } \ 
        private:

