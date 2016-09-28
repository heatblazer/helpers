#ifndef UTILS_H
#define UTILS_H

namespace izutils {


template <typename A, typename B> struct is_same
{
    static const bool isSame = false;
};

template <typename T> struct is_same<T, T>
{
    static const bool isSame = true;
};

template <class A, class B> bool isSameClass()
{
    return is_same<A, B>::isSame;
}

/// as functor
/// \brief The EndianSwap class
///
template <class T> class EndianSwap
{
private:
    // aux bifield
    struct byte_t {
        uint8_t ba : 1;
        uint8_t bb : 1;
        uint8_t bc : 1;
        uint8_t bd : 1;
        uint8_t be : 1;
        uint8_t bf : 1;
        uint8_t bg : 1;
        uint8_t bh : 1;
    };

    struct byte_t _reverse(struct byte_t b)
    {
        struct byte_t rev;
        rev.ba = b.bh;
        rev.bb = b.bg;
        rev.bc = b.bf;
        rev.bd = b.be;
        rev.be = b.bd;
        rev.bf = b.bc;
        rev.bg = b.bb;
        rev.bh = b.ba;
        return rev;
    }

public:
      T operator()(T thing) {
        union {
            T t;
            byte_t b[sizeof(T)];
        } u1, u2;

        u1.t = thing;
        for(int i=0; i < sizeof(T); i++) {
            u1.b[i] = _reverse(u1.b[i]);
        }
        int i =0;
        for(int j=(sizeof(T)-1); j >=0; j--) {
            u2.b[j] = u1.b[i++];
        }

        return u2.t;
    }
};


} // namespace izutils


#endif // UTILS_H
