#ifndef HEADER_ASSERT_FC81EE1B_9E8E_41B2_9F3E_B3F87F1DA4ED
#define HEADER_ASSERT_FC81EE1B_9E8E_41B2_9F3E_B3F87F1DA4ED


#include <stdexcept>


namespace utility {


template<typename T>
T assertExists(T const &&t, std::string const &error) {
    if (t)
        return t; // ----->
    else
        throw std::runtime_error(error);
}


template<typename T>
T assertOne(T const &&t, std::string const &error) {
    if (t.size() == 1)
        return t; // ----->
    else
        throw std::runtime_error(error);
}


template<typename T>
T assertComplete(T const &&t, std::string const &error) {
    if (t.size() >= 1)
        return t; // ----->
    else
        throw std::runtime_error(error);
}


} // utility


#endif // HEADER_ASSERT_FC81EE1B_9E8E_41B2_9F3E_B3F87F1DA4ED
