#include "Exception.h"

Exception::Exception() noexcept = default;

Exception::Exception(const Exception&) noexcept = default;

Exception::~Exception() = default;

const char* Exception::what() const noexcept {
    return 0;
}
