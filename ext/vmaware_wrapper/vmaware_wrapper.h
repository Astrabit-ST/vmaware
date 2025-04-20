#include <cstddef>
#include <cstdint>

extern "C" {
bool vm_detect();
uint8_t vm_percentage();
size_t vm_brand(char *buf, size_t buf_len);
size_t vm_type(char *buf, size_t buf_len);
size_t vm_conclusion(char *buf, size_t buf_len);
uint8_t vm_detected_count();
}