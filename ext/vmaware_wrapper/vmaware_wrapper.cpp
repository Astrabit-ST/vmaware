#include "vmaware_wrapper.h"
#include "vmaware.hpp"
#include <cstddef>
#include <cstdint>

bool vm_detect() { return VM::detect(); }
uint8_t vm_percentage() { return VM::percentage(); }
size_t vm_brand(char *buf, size_t buf_len) {
  std::string brand = VM::brand();
  if (buf)
    memcpy(buf, brand.data(), buf_len);
  return brand.length();
}
size_t vm_type(char *buf, size_t buf_len) {
  std::string type = VM::type();
  if (buf)
    memcpy(buf, type.data(), buf_len);
  return type.length();
}
size_t vm_conclusion(char *buf, size_t buf_len) {
  std::string conclusion = VM::conclusion();
  if (buf)
    memcpy(buf, conclusion.data(), buf_len);
  return conclusion.length();
}
uint8_t vm_detected_count() { return VM::detected_count(); }
