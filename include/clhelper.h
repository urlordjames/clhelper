#include <CL/cl.hpp>
#include <vector>
#include <fstream>

cl::Platform getFirstPlatform();

cl::Device getFirstDevice(cl::Platform platform);

cl::Device getFirstDevice();

void addFileToSources(cl::Program::Sources *sources, std::string fileName);

cl::Program::Sources getSourcesFromFile(std::string fileName);

template <typename T> std::vector<T> initNVector(int n, T val);

template <typename T> T getDeviceInfo(cl::Device device, cl_device_info info);
