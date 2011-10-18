#include <stdexcept>
#include <string>

class No_such_object_exception :public runtime_error {
public:
  No_such_object_exception (const std::string& message ="")
    :std::runtime_error(message) {};
};

