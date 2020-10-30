# clhelper
clhelper is a helper library for OpenCL which aims to help you write less code

# example project
`src/main.cpp`:
```cpp
#include <CL/cl.hpp>
#include <iostream>
#include "clhelper.cpp"

int main() {
  //getFirstDevice is a function from clhelper
  cl::Device device = getFirstDevice();

  //getDeviceInfo is another function from clhelper
  std::cout << "device name: " << getDeviceInfo<std::string>(device, CL_DEVICE_NAME) << std::endl;
}
```

`CMakeLists.txt`:
```
cmake_minimum_required(VERSION "3.7")

project("easyopencl")

# include OpenCL
find_package(OpenCL REQUIRED)
include_directories(${OpenCL_INCLUDE_DIRS})

# include clhelper
add_subdirectory(clhelper)
include_directories(clhelper/src)

add_executable(${PROJECT_NAME} src/main.cpp)

# link clhelper
target_link_libraries(${PROJECT_NAME} clhelper)

# link OpenCL
target_link_libraries(${PROJECT_NAME} ${OpenCL_LIBRARY})
```

clone clhelper into your project directory
```
git clone https://github.com/urlordjames/clhelper.git
```
build and run project
```
cmake .
make
./easyopencl
```
